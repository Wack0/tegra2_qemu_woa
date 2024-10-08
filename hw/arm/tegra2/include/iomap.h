/*
 * arch/arm/mach-tegra/include/mach/iomap.h
 *
 * Copyright (C) 2010 Google, Inc.
 * Copyright (C) 2011-2012, NVIDIA Corporation.
 *
 * Author:
 *	Colin Cross <ccross@google.com>
 *	Erik Gilling <konkers@google.com>
 *
 * Copyright (C) 2010-2011 NVIDIA Corporation
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef __MACH_TEGRA_IOMAP_H
#define __MACH_TEGRA_IOMAP_H

#include "sizes.h"

/* TEGRA2 PLATFORM */
#define CONFIG_ARCH_TEGRA_2x_SOC
/****/

#if defined(CONFIG_ARCH_TEGRA_2x_SOC)
#define TEGRA_NOR_FLASH_BASE		0xD0000000
#define TEGRA_NOR_FLASH_SIZE		SZ_256M
#else
#define TEGRA_NOR_FLASH_BASE		0x48000000
#define TEGRA_NOR_FLASH_SIZE		SZ_128M
#endif

#if defined(CONFIG_ARCH_TEGRA_2x_SOC)
#define TEGRA_DRAM_BASE			0x00000000
#define TEGRA_DRAM_SIZE			SZ_1G		/* Maximum size */
#else
#define TEGRA_DRAM_BASE			0x80000000
#define TEGRA_DRAM_SIZE			(SZ_2G - SZ_1M)	/* Maximum size */
#endif

#define TEGRA_IRAM_BASE			0x40000000
#define TEGRA_IRAM_SIZE			SZ_256K

/* First 1K of IRAM is reserved for cpu reset handler. */
#define TEGRA_RESET_HANDLER_BASE	TEGRA_IRAM_BASE
#define TEGRA_RESET_HANDLER_SIZE	SZ_1K

#define TEGRA_GRHOST_BASE		0x50000000
#define TEGRA_GRHOST_SIZE		0x24000

#define TEGRA_ARM_PERIF_BASE		0x50040000
#define TEGRA_ARM_PERIF_SIZE		SZ_8K

#define TEGRA_MSELECT_BASE		0x50042000
#define TEGRA_MSELECT_SIZE		80

#if defined(CONFIG_ARCH_TEGRA_2x_SOC) || defined(CONFIG_ARCH_TEGRA_3x_SOC)

#define TEGRA_ARM_PL310_BASE		0x50043000
#define TEGRA_ARM_PL310_SIZE		SZ_4K

#endif

#define TEGRA_ARM_INT_DIST_BASE		0x50041000
#define TEGRA_ARM_INT_DIST_SIZE		SZ_4K

#define TEGRA_HOST1X_BASE		0x54000000
#define TEGRA_HOST1X_SIZE		SZ_256K

#define TEGRA_MPE_BASE			0x54040000
#define TEGRA_MPE_SIZE			SZ_256K

#define TEGRA_VI_BASE			0x54080000
#define TEGRA_VI_SIZE			SZ_256K

#define TEGRA_ISP_BASE			0x54100000
#define TEGRA_ISP_SIZE			SZ_256K

#define TEGRA_GR2D_BASE			0x54140000
#define TEGRA_GR2D_SIZE			SZ_256K

#define TEGRA_GR3D_BASE			0x54180000
#define TEGRA_GR3D_SIZE			SZ_256K

#define TEGRA_DISPLAY_BASE		0x54200000
#define TEGRA_DISPLAY_SIZE		SZ_256K

#define TEGRA_DISPLAY2_BASE		0x54240000
#define TEGRA_DISPLAY2_SIZE		SZ_256K

#define TEGRA_HDMI_BASE			0x54280000
#define TEGRA_HDMI_SIZE			SZ_256K

#define TEGRA_DSI_BASE			0x54300000
#define TEGRA_DSI_SIZE			SZ_256K

#define TEGRA_DSIB_BASE			0x54400000
#define TEGRA_DSIB_SIZE			SZ_256K

#define TEGRA_MSENC_BASE		0x544c0000
#define TEGRA_MSENC_SIZE		SZ_256K

#define TEGRA_TSEC_BASE			0x54500000
#define TEGRA_TSEC_SIZE			SZ_256K

#if defined(CONFIG_ARCH_TEGRA_2x_SOC)

#define TEGRA_GART_BASE			0x58000000
#define TEGRA_GART_SIZE			SZ_32M
#define TEGRA_IOMMU_BASE		TEGRA_GART_BASE
#define TEGRA_IOMMU_SIZE		TEGRA_GART_SIZE

#else

#define TEGRA_SMMU_BASE_TEGRA3_A01	0xe0000000
#define TEGRA_SMMU_SIZE_TEGRA3_A01	SZ_256M

#if defined(CONFIG_ARCH_TEGRA_3x_SOC)
#define TEGRA_SMMU_BASE			0x00001000
#define TEGRA_SMMU_SIZE			(SZ_1G - SZ_4K * 2)
#else
#define TEGRA_SMMU_BASE			0x01000000
#define TEGRA_SMMU_SIZE			(SZ_1G - SZ_16M - SZ_4K)
#endif

#define TEGRA_IOMMU_BASE		TEGRA_SMMU_BASE
#define TEGRA_IOMMU_SIZE		TEGRA_SMMU_SIZE
#endif

#define TEGRA_RES_SEMA_SIZE		SZ_4K
#define TEGRA_RES_SEMA_BASE		0x60001000

#define TEGRA_ARB_SEMA_BASE		0x60002000
#define TEGRA_ARB_SEMA_SIZE		SZ_4K

#define TEGRA_PRIMARY_ICTLR_BASE	0x60004000
#define TEGRA_PRIMARY_ICTLR_SIZE	64

#define TEGRA_ARBGNT_ICTLR_BASE		0x60004040
#define TEGRA_ARBGNT_ICTLR_SIZE		192

#define TEGRA_SECONDARY_ICTLR_BASE	0x60004100
#define TEGRA_SECONDARY_ICTLR_SIZE	64

#define TEGRA_TERTIARY_ICTLR_BASE	0x60004200
#define TEGRA_TERTIARY_ICTLR_SIZE	64

#define TEGRA_QUATERNARY_ICTLR_BASE	0x60004300
#define TEGRA_QUATERNARY_ICTLR_SIZE	64

#ifndef CONFIG_ARCH_TEGRA_2x_SOC

#define TEGRA_QUINARY_ICTLR_BASE	0x60004400
#define TEGRA_QUINARY_ICTLR_SIZE	SZ_64

#endif

#define TEGRA_TMR1_BASE			0x60005000
#define TEGRA_TMR1_SIZE			SZ_8

#define TEGRA_TMR2_BASE			0x60005008
#define TEGRA_TMR2_SIZE			SZ_8

#define TEGRA_TMRUS_BASE		0x60005010
#define TEGRA_TMRUS_SIZE		64

#define TEGRA_TMR3_BASE			0x60005050
#define TEGRA_TMR3_SIZE			SZ_8

#define TEGRA_TMR4_BASE			0x60005058
#define TEGRA_TMR4_SIZE			SZ_8

#ifndef CONFIG_ARCH_TEGRA_2x_SOC

#define TEGRA_TMR5_BASE			0x60005060
#define TEGRA_TMR5_SIZE			8

#define TEGRA_TMR6_BASE			0x60005068
#define TEGRA_TMR6_SIZE			8

#define TEGRA_TMR7_BASE			0x60005070
#define TEGRA_TMR7_SIZE			8

#define TEGRA_TMR8_BASE			0x60005078
#define TEGRA_TMR8_SIZE			8

#define TEGRA_TMR9_BASE			0x60005080
#define TEGRA_TMR9_SIZE			8

#define TEGRA_TMR10_BASE		0x60005088
#define TEGRA_TMR10_SIZE		8

#define TEGRA_WDT0_BASE			0x60005100
#define TEGRA_WDT0_SIZE			32

#define TEGRA_WDT1_BASE			0x60005120
#define TEGRA_WDT1_SIZE			32

#define TEGRA_WDT2_BASE			0x60005140
#define TEGRA_WDT2_SIZE			32

#define TEGRA_WDT3_BASE			0x60005160
#define TEGRA_WDT3_SIZE			32

#define TEGRA_WDT4_BASE			0x60005180
#define TEGRA_WDT4_SIZE			32

#endif

#define TEGRA_CLK_RESET_BASE		0x60006000
#define TEGRA_CLK_RESET_SIZE		SZ_4K

#define TEGRA_FLOW_CTRL_BASE		0x60007000
#define TEGRA_FLOW_CTRL_SIZE		SZ_32

#define TEGRA_AHB_DMA_BASE		0x60008000
#define TEGRA_AHB_DMA_SIZE		(SZ_4K + SZ_128)

#define TEGRA_AHB_DMA_CH0_BASE		0x60009000
#define TEGRA_AHB_DMA_CH0_SIZE		32

#define TEGRA_APB_DMA_BASE		0x6000A000
#define TEGRA_APB_DMA_SIZE		SZ_4K

#define TEGRA_APB_DMA_CH0_BASE		0x6000B000
#define TEGRA_APB_DMA_CH0_SIZE		32

#ifndef CONFIG_ARCH_TEGRA_2x_SOC

#define TEGRA_AHB_ARB_BASE		0x6000C000
#define TEGRA_AHB_ARB_SIZE		768	/* Overlaps with GISMO */

#endif

#define TEGRA_AHB_GIZMO_BASE		0x6000C004
#define TEGRA_AHB_GIZMO_SIZE		0x10C

#define TEGRA_SB_BASE			0x6000C200
#define TEGRA_SB_SIZE			256

#define TEGRA_STATMON_BASE		0x6000C400
#define TEGRA_STATMON_SIZE		SZ_1K

#if !defined(CONFIG_ARCH_TEGRA_2x_SOC)

#define TEGRA_ACTMON_BASE		0x6000C800
#define TEGRA_ACTMON_SIZE		SZ_1K

#endif

#define TEGRA_GPIO_BASE			0x6000D000
#define TEGRA_GPIO_SIZE			SZ_4K

#define TEGRA_EXCEPTION_VECTORS_BASE    0x6000F000
#define TEGRA_EXCEPTION_VECTORS_SIZE    SZ_4K

#define TEGRA_BSEA_BASE			0x60010000
#define TEGRA_BSEA_SIZE			SZ_4K

#define TEGRA_VDE_BASE			0x6001A000
#define TEGRA_VDE_SIZE			0x3c00

#define IO_APB_PHYS	0x70000000
#define IO_APB_SIZE	SZ_64M

#define TEGRA_APB_MISC_BASE		0x70000000
#define TEGRA_APB_MISC_SIZE		SZ_4K

#define TEGRA_APB_MISC_DAS_BASE		0x70000c00
#define TEGRA_APB_MISC_DAS_SIZE		SZ_128

#if defined(CONFIG_ARCH_TEGRA_2x_SOC)

#define TEGRA_AC97_BASE			0x70002000
#define TEGRA_AC97_SIZE			SZ_512

#define TEGRA_SPDIF_BASE		0x70002400
#define TEGRA_SPDIF_SIZE		SZ_512

#define TEGRA_I2S1_BASE			0x70002800
#define TEGRA_I2S1_SIZE			SZ_256

#define TEGRA_I2S2_BASE			0x70002A00
#define TEGRA_I2S2_SIZE			SZ_256

#define TEGRA_PCIE_BASE			0x80000000
#define TEGRA_PCIE_SIZE			SZ_1G

#else

#if defined(CONFIG_ARCH_TEGRA_3x_SOC)

#define TEGRA_PCIE_BASE			0x00000000
#define TEGRA_PCIE_SIZE			SZ_1G

#define TEGRA_TSENSOR_BASE		0x70014000
#define TEGRA_TSENSOR_SIZE		SZ_4K
#endif

#define TEGRA_CEC_BASE			0x70015000
#define TEGRA_CEC_SIZE			SZ_4K

#define TEGRA_HDA_BASE			0x70030000
#define TEGRA_HDA_SIZE			SZ_64K

#define TEGRA_AUDIO_CLUSTER_BASE	0x70080000
#define TEGRA_AUDIO_CLUSTER_SIZE	SZ_4K

#define TEGRA_APBIF0_BASE		TEGRA_AUDIO_CLUSTER_BASE
#define TEGRA_APBIF0_SIZE		32

#define TEGRA_APBIF1_BASE		0x70080020
#define TEGRA_APBIF1_SIZE		32

#define TEGRA_APBIF2_BASE		0x70080040
#define TEGRA_APBIF2_SIZE		32

#define TEGRA_APBIF3_BASE		0x70080060
#define TEGRA_APBIF3_SIZE		32

#define TEGRA_AHUB_BASE			0x70080200
#define TEGRA_AHUB_SIZE			SZ_256

#define TEGRA_I2S0_BASE			0x70080300
#define TEGRA_I2S0_SIZE			SZ_256

#define TEGRA_I2S1_BASE			0x70080400
#define TEGRA_I2S1_SIZE			SZ_256

#define TEGRA_I2S2_BASE			0x70080500
#define TEGRA_I2S2_SIZE			SZ_256

#define TEGRA_I2S3_BASE			0x70080600
#define TEGRA_I2S3_SIZE			SZ_256

#define TEGRA_I2S4_BASE			0x70080700
#define TEGRA_I2S4_SIZE			SZ_256

#define TEGRA_DAM0_BASE			0x70080800
#define TEGRA_DAM0_SIZE			SZ_256

#define TEGRA_DAM1_BASE			0x70080900
#define TEGRA_DAM1_SIZE			SZ_256

#define TEGRA_DAM2_BASE			0x70080A00
#define TEGRA_DAM2_SIZE			SZ_256

#define TEGRA_SPDIF_BASE		0x70080B00
#define TEGRA_SPDIF_SIZE		SZ_256

#ifndef CONFIG_ARCH_TEGRA_3x_SOC

#define TEGRA_AMX0_BASE			0x70080C00
#define TEGRA_AMX0_SIZE			SZ_256

#define TEGRA_ADX0_BASE			0x70080E00
#define TEGRA_ADX0_SIZE			SZ_256

#define TEGRA_APBIF4_BASE		0x70081000
#define TEGRA_APBIF4_SIZE		32

#define TEGRA_APBIF5_BASE		0x70081020
#define TEGRA_APBIF5_SIZE		32

#define TEGRA_APBIF6_BASE		0x70081040
#define TEGRA_APBIF6_SIZE		32

#define TEGRA_APBIF7_BASE		0x70081060
#define TEGRA_APBIF7_SIZE		32

#define TEGRA_APBIF8_BASE		0x70081080
#define TEGRA_APBIF8_SIZE		32

#define TEGRA_APBIF9_BASE		0x700810A0
#define TEGRA_APBIF9_SIZE		32

#endif

#endif

#define TEGRA_UARTA_BASE		0x70006000
#define TEGRA_UARTA_SIZE		64

#define TEGRA_UARTB_BASE		0x70006040
#define TEGRA_UARTB_SIZE		64

#define TEGRA_UARTC_BASE		0x70006200
#define TEGRA_UARTC_SIZE		SZ_256

#define TEGRA_UARTD_BASE		0x70006300
#define TEGRA_UARTD_SIZE		SZ_256

#define TEGRA_UARTE_BASE		0x70006400
#define TEGRA_UARTE_SIZE		SZ_256

#define TEGRA_NAND_BASE			0x70008000
#define TEGRA_NAND_SIZE			SZ_256

#define TEGRA_HSMMC_BASE		0x70008500
#define TEGRA_HSMMC_SIZE		SZ_256

#define TEGRA_SNOR_BASE			0x70009000
#define TEGRA_SNOR_SIZE			SZ_4K

#define TEGRA_PWFM_BASE			0x7000A000
#define TEGRA_PWFM_SIZE			SZ_256

#define TEGRA_PWFM0_BASE		0x7000A000
#define TEGRA_PWFM0_SIZE		4

#define TEGRA_PWFM1_BASE		0x7000A010
#define TEGRA_PWFM1_SIZE		4

#define TEGRA_PWFM2_BASE		0x7000A020
#define TEGRA_PWFM2_SIZE		4

#define TEGRA_PWFM3_BASE		0x7000A030
#define TEGRA_PWFM3_SIZE		4

#define TEGRA_MIPI_BASE			0x7000B000
#define TEGRA_MIPI_SIZE			SZ_256

#define TEGRA_I2C_BASE			0x7000C000
#define TEGRA_I2C_SIZE			SZ_256

#define TEGRA_TWC_BASE			0x7000C100
#define TEGRA_TWC_SIZE			SZ_256

#if defined(CONFIG_ARCH_TEGRA_2x_SOC)

#define TEGRA_SPI_BASE			0x7000C380
#define TEGRA_SPI_SIZE			48

#else

#define TEGRA_DTV_BASE			0x7000C300
#define TEGRA_DTV_SIZE			SZ_256

#endif

#define TEGRA_I2C2_BASE			0x7000C400
#define TEGRA_I2C2_SIZE			SZ_256

#define TEGRA_I2C3_BASE			0x7000C500
#define TEGRA_I2C3_SIZE			SZ_256

#define TEGRA_OWR_BASE			0x7000C600
#define TEGRA_OWR_SIZE			80

#if defined(CONFIG_ARCH_TEGRA_2x_SOC)

#define TEGRA_DVC_BASE			0x7000D000
#define TEGRA_DVC_SIZE			SZ_512

#else

#define TEGRA_I2C4_BASE			0x7000C700
#define TEGRA_I2C4_SIZE			SZ_512

#define TEGRA_I2C5_BASE			0x7000D000
#define TEGRA_I2C5_SIZE			SZ_512

#endif

#define TEGRA_SPI1_BASE			0x7000D400
#define TEGRA_SPI1_SIZE			SZ_512

#define TEGRA_SPI2_BASE			0x7000D600
#define TEGRA_SPI2_SIZE			SZ_512

#define TEGRA_SPI3_BASE			0x7000D800
#define TEGRA_SPI3_SIZE			SZ_512

#define TEGRA_SPI4_BASE			0x7000DA00
#define TEGRA_SPI4_SIZE			SZ_512

#ifndef CONFIG_ARCH_TEGRA_2x_SOC

#define TEGRA_SPI5_BASE			0x7000DC00
#define TEGRA_SPI5_SIZE			SZ_512

#define TEGRA_SPI6_BASE			0x7000DE00
#define TEGRA_SPI6_SIZE			SZ_512

#endif

#define TEGRA_RTC_BASE			0x7000E000
#define TEGRA_RTC_SIZE			SZ_256

#define TEGRA_KBC_BASE			0x7000E200
#define TEGRA_KBC_SIZE			SZ_256

#define TEGRA_PMC_BASE			0x7000E400
#define TEGRA_PMC_SIZE			SZ_512

#if defined(CONFIG_ARCH_TEGRA_2x_SOC) || defined(CONFIG_ARCH_TEGRA_3x_SOC)

#define TEGRA_MC_BASE			0x7000F000
#define TEGRA_MC_SIZE			SZ_1K

#define TEGRA_EMC_BASE			0x7000F400
#define TEGRA_EMC_SIZE			SZ_1K

#else

#define TEGRA_MC0_BASE			0x70018000
#define TEGRA_MC0_SIZE			SZ_2K

#define TEGRA_MC1_BASE			0x7001C000
#define TEGRA_MC1_SIZE			SZ_2K

#define TEGRA_MC_BASE			0x70019000
#define TEGRA_MC_SIZE			SZ_2K

#define TEGRA_EMC0_BASE			0x7001A000
#define TEGRA_EMC0_SIZE			SZ_2K

#define TEGRA_EMC1_BASE			0x7001A800
#define TEGRA_EMC1_SIZE			SZ_2K

#define TEGRA_EMC_BASE			0x7001B000
#define TEGRA_EMC_SIZE			SZ_2K

#define TEGRA_XUSB_HOST_BASE		0x70090000
#define TEGRA_XUSB_HOST_SIZE		SZ_32K
#define TEGRA_XUSB_FPCI_BASE		0x70098000
#define TEGRA_XUSB_FPCI_SIZE		SZ_4K
#define TEGRA_XUSB_IPFS_BASE		0x70099000
#define TEGRA_XUSB_IPFS_SIZE		SZ_4K


#define TEGRA_XUSB_PADCTL_BASE		0x7009F000
#define TEGRA_XUSB_PADCTL_SIZE		SZ_4K

#define TEGRA_XUSB_DEV_BASE		0x700D0000
#define TEGRA_XUSB_DEV_SIZE		(SZ_32K + SZ_4K)

#ifdef CONFIG_ARM_ARCH_TIMER
#define TEGRA_TSC_BASE			0x700F0000
#define TEGRA_TSC_SIZE			(SZ_64K)
#endif

#define TEGRA_CL_DVFS_BASE		0x70110000
#define TEGRA_CL_DVFS_SIZE		SZ_1K

#endif

#define TEGRA_FUSE_BASE			0x7000F800
#define TEGRA_FUSE_SIZE			SZ_1K

#define TEGRA_KFUSE_BASE		0x7000FC00
#define TEGRA_KFUSE_SIZE		SZ_1K

#define TEGRA_CSITE_BASE		0x70040000
#define TEGRA_CSITE_SIZE		SZ_256K

#if defined(CONFIG_ARCH_TEGRA_11x_SOC)
#define TEGRA_SOCTHERM_BASE		0x700E2000
#define TEGRA_SOCTHERM_SIZE		SZ_4K

#define TEGRA_MIPI_CAL_BASE		0x700E3000
#define TEGRA_MIPI_CAL_SIZE		SZ_256
#endif

#if defined(CONFIG_ARCH_TEGRA_2x_SOC)

#define TEGRA_USB_BASE			0xC5000000
#define TEGRA_USB_SIZE			SZ_16K

#define TEGRA_USB2_BASE			0xC5004000
#define TEGRA_USB2_SIZE			SZ_16K

#define TEGRA_USB3_BASE			0xC5008000
#define TEGRA_USB3_SIZE			SZ_16K

#define TEGRA_SDMMC1_BASE		0xC8000000
#define TEGRA_SDMMC1_SIZE		SZ_512

#define TEGRA_SDMMC2_BASE		0xC8000200
#define TEGRA_SDMMC2_SIZE		SZ_512

#define TEGRA_SDMMC3_BASE		0xC8000400
#define TEGRA_SDMMC3_SIZE		SZ_512

#define TEGRA_SDMMC4_BASE		0xC8000600
#define TEGRA_SDMMC4_SIZE		SZ_512

#else

#define TEGRA_SATA_BASE			0x70020000
#define TEGRA_SATA_SIZE			SZ_64K

#define TEGRA_SATA_CONFIG_BASE		0x70021000
#define TEGRA_SATA_CONFIG_SIZE		SZ_4K

#define TEGRA_SATA_BAR5_BASE		0x70027000
#define TEGRA_SATA_BAR5_SIZE		SZ_8K

#ifdef CONFIG_TEGRA_SIMULATION_PLATFORM
#define TEGRA_SIM_ETH_BASE              0x77000000
#define TEGRA_SIM_ETH_SIZE              SZ_64K
#endif

#define TEGRA_SDMMC1_BASE		0x78000000
#define TEGRA_SDMMC1_SIZE		SZ_512

#define TEGRA_SDMMC2_BASE		0x78000200
#define TEGRA_SDMMC2_SIZE		SZ_512

#define TEGRA_SDMMC3_BASE		0x78000400
#define TEGRA_SDMMC3_SIZE		SZ_512

#define TEGRA_SDMMC4_BASE		0x78000600
#define TEGRA_SDMMC4_SIZE		SZ_512

#define TEGRA_USB_BASE			0x7D000000
#define TEGRA_USB_SIZE			SZ_16K

#define TEGRA_USB2_BASE			0x7D004000
#define TEGRA_USB2_SIZE			SZ_16K

#define TEGRA_USB3_BASE			0x7D008000
#define TEGRA_USB3_SIZE			SZ_16K

#define TEGRA_SE_BASE			0x70012000
#define TEGRA_SE_SIZE			SZ_8K

#endif

#endif
