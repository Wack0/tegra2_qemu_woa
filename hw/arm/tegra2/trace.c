/*
 * ARM NVIDIA Tegra2 emulation.
 *
 * Copyright (c) 2014-2015 Dmitry Osipenko <digetx@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *  FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 *  for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#define LOCAL_SOCKET

#include <sysemu/sysemu.h>
#include "qemu/sockets.h"
#include "qemu/thread.h"

#include "ahb/host1x/include/host1x_cdma.h"
#include "tegra_trace.h"

#define SOCKET_FILE     "/tmp/trace.sock"

/* FIXME */
static uint64_t reset_time;

#define HOST1X_CDMA	0x1010

#define PACKET_TRACE_RW 0x11111111
struct __attribute__((packed, aligned(1))) trace_pkt_rw {
    uint32_t magic;
    uint32_t hwaddr;
    uint32_t offset;
    uint32_t value;
    uint32_t new_value;
    uint32_t is_write;
    uint32_t time;
    uint32_t cpu_pc;
    uint32_t cpu_id;
};

#define PACKET_TRACE_IRQ 0x22222222
struct __attribute__((packed, aligned(1))) trace_pkt_irq {
    uint32_t magic;
    uint32_t hwaddr;
    uint32_t hwirq;
    uint32_t status;
    uint32_t time;
    uint32_t cpu_pc;
    uint32_t cpu_id;
};

#define PACKET_TRACE_TXT 0x33333333
struct __attribute__((packed, aligned(1))) trace_pkt_txt {
    uint32_t magic;
    uint32_t text_sz;
//     uint32_t time;
    char text[1]; // \0
};

#define PACKET_TRACE_CDMA 0x44444444
struct __attribute__((packed, aligned(1))) trace_pkt_cdma {
    uint32_t magic;
    uint32_t time;
    uint32_t data;
    uint32_t is_gather;
    uint32_t ch_id;
};

static int msgsock = -1;

void tegra_trace_text_message(const char* format, ...)
{
#ifdef _GNU_SOURCE
    struct trace_pkt_txt *W;
    va_list args;
    char *txt;
    size_t sz;
    int ret;

    va_start(args, format);
    ret = vasprintf(&txt, format, args);
    va_end(args);

    if (ret < 1)
        return;

    sz = sizeof(*W) + strlen(txt);
    W = malloc(sz);
    W->magic = htonl(PACKET_TRACE_TXT);
//     W->time = qemu_clock_get_us(QEMU_CLOCK_VIRTUAL);
    W->text_sz = htonl(strlen(txt) + 1);
    memcpy(W->text, txt, strlen(txt) + 1);
    free(txt);

    if (send_all(msgsock, W, sz) != 0)
        printf("%s", W->text);

    free(W);
#endif
}

void tegra_trace_irq(uint32_t hwaddr, uint32_t hwirq, uint32_t status)
{
    uint32_t time = qemu_clock_get_us(QEMU_CLOCK_VIRTUAL);
    struct trace_pkt_irq W = {
        htonl(PACKET_TRACE_IRQ),
        htonl(hwaddr),
        htonl(hwirq),
        htonl(status),
        htonl(time - reset_time),
        htonl(0),
        htonl(0)
    };

    send_all(msgsock, &W, sizeof(W));
}

void tegra_trace_write(uint32_t hwaddr, uint32_t offset,
                       uint32_t value, uint32_t new_value, uint32_t is_write)
{
    CPUState *cs = CPU(current_cpu);
    ARMCPU *cpu = ARM_CPU(cs);
    uint32_t cpu_pc = cpu ? cpu->env.regs[15] : 0;
    uint32_t time = qemu_clock_get_us(QEMU_CLOCK_VIRTUAL);
    uint32_t cpu_id = host1x_cdma_ptr ? HOST1X_CDMA : (cs ? cs->cpu_index : 0xFF);
    struct trace_pkt_rw W = {
        htonl(PACKET_TRACE_RW),
        htonl(hwaddr),
        htonl(offset),
        htonl(value),
        htonl(new_value),
        htonl(is_write),
        htonl(time - reset_time),
        htonl(cpu_pc),
        htonl(cpu_id)
    };

    send_all(msgsock, &W, sizeof(W));
}

void tegra_trace_cdma(uint32_t data, uint32_t is_gather, uint32_t ch_id)
{
    uint32_t time = qemu_clock_get_us(QEMU_CLOCK_VIRTUAL);
    struct trace_pkt_cdma W = {
        htonl(PACKET_TRACE_CDMA),
        htonl(time),
        htonl(data),
        htonl(is_gather),
        htonl(ch_id)
    };

    send_all(msgsock, &W, sizeof(W));
}

void tegra_trace_init(void)
{
#ifdef TEGRA_TRACE
    static int sock = -1;

    if (msgsock != -1) {
        close(msgsock);
    }

    if (sock != -1) {
        goto WAIT;
    }

#ifdef LOCAL_SOCKET
    sock = unix_listen(SOCKET_FILE, NULL, 0, &error_abort);
#else
    sock = inet_listen("0.0.0.0:19191", NULL, 0, SOCK_STREAM, 0, &error_abort);
#endif // LOCAL_SOCKET

    socket_set_fast_reuse(sock);

    if (listen(sock, 1) < 0) {
        error_setg_errno(&error_abort, errno, "Failed to listen on socket");
    }

WAIT:
    printf("Waiting for trace viewer connection...\n");
    msgsock = qemu_accept(sock, NULL, NULL);
    g_assert(msgsock != -1);

    reset_time = qemu_clock_get_us(QEMU_CLOCK_VIRTUAL);
#endif // TEGRA_TRACE
}
