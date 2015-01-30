/*
 * Copyright (c) 2013, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#define pr_fmt(fmt) "%s: " fmt, __func__

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/errno.h>
#include <linux/io.h>
#include <linux/clk.h>
#include <linux/platform_device.h>
#include <linux/regulator/consumer.h>
#include <linux/regulator/cpr-regulator.h>

#include <mach/clk-provider.h>
#include <mach/msm_bus.h>
#include <mach/msm_bus_board.h>
#include <mach/rpm-regulator-smd.h>
#include <mach/socinfo.h>

#include "acpuclock-cortex.h"

static int __init acpuclk_a7_probe(struct platform_device *pdev)
{
		return -EINVAL;
}

static struct of_device_id acpuclk_a7_match_table[] = {
	{.compatible = "qcom,acpuclk-a7-8226"},
	{}
};

static struct platform_driver acpuclk_a7_driver = {
	.driver = {
		.name = "acpuclk-a7-8226",
		.of_match_table = acpuclk_a7_match_table,
		.owner = THIS_MODULE,
	},
};

static int __init acpuclk_a7_init(void)
{
	return platform_driver_probe(&acpuclk_a7_driver, acpuclk_a7_probe);
}
device_initcall(acpuclk_a7_init);
