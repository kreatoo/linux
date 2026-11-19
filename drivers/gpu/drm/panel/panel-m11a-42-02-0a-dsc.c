// SPDX-License-Identifier: GPL-2.0-only
// Copyright (c) 2026 FIXME
// Generated with linux-mdss-dsi-panel-driver-generator from vendor device tree:
//   Copyright (c) 2013, The Linux Foundation. All rights reserved. (FIXME)

#include <linux/backlight.h>
#include <linux/delay.h>
#include <linux/gpio/consumer.h>
#include <linux/mod_devicetable.h>
#include <linux/module.h>
#include <linux/regulator/consumer.h>

#include <video/mipi_display.h>

#include <drm/display/drm_dsc.h>
#include <drm/display/drm_dsc_helper.h>
#include <drm/drm_mipi_dsi.h>
#include <drm/drm_modes.h>
#include <drm/drm_panel.h>
#include <drm/drm_probe_helper.h>

struct m11a_42_02_0a_dsc {
	struct drm_panel panel;
	struct mipi_dsi_device *dsi;
	struct drm_dsc_config dsc;
	struct gpio_desc *reset_gpio;
	struct regulator_bulk_data supplies[3];
};

static inline
struct m11a_42_02_0a_dsc *to_m11a_42_02_0a_dsc(struct drm_panel *panel)
{
	return container_of_const(panel, struct m11a_42_02_0a_dsc, panel);
}

static void m11a_42_02_0a_dsc_reset(struct m11a_42_02_0a_dsc *ctx)
{
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(11000, 12000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	usleep_range(1000, 2000);
	gpiod_set_value_cansleep(ctx->reset_gpio, 0);
	usleep_range(11000, 12000);
}

static int m11a_42_02_0a_dsc_on(struct m11a_42_02_0a_dsc *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0,
				     0x55, 0xaa, 0x52, 0x08, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x1a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc2, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0,
				     0x55, 0xaa, 0x52, 0x08, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x0e);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb4, 0x1f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xff, 0xaa, 0x55, 0xa5, 0x80);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf5, 0x10);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0,
				     0x55, 0xaa, 0x52, 0x08, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb1, 0x06, 0x06);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0,
				     0x55, 0xaa, 0x52, 0x08, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc4, 0xe3);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xff, 0xaa, 0x55, 0xa5, 0x80);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x18);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf8, 0x19);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0,
				     0x55, 0xaa, 0x52, 0x08, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc5, 0x0b, 0x0b, 0x0b);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0,
				     0x55, 0xaa, 0x52, 0x08, 0x04);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc0, 0x20);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0,
				     0x55, 0xaa, 0x52, 0x08, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x20);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc6,
				     0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
				     0x55);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xff, 0xaa, 0x55, 0xa5, 0x80);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x1b);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf4, 0x55);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x19);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf2, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xff, 0xaa, 0x55, 0xa5, 0x81);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x18);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfb, 0x04);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xff, 0xaa, 0x55, 0xa5, 0x81);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x07);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xfc, 0x08);
	mipi_dsi_dcs_set_column_address_multi(&dsi_ctx, 0x0000, 0x059f);
	mipi_dsi_dcs_set_page_address_multi(&dsi_ctx, 0x0000, 0x0c7f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x90, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x91,
				     0xab, 0xa8, 0x00, 0x20, 0xd2, 0x00, 0x02,
				     0x86, 0x03, 0x5e, 0x00, 0x0a, 0x03, 0x5b,
				     0x02, 0x63, 0x10, 0xf0);
	mipi_dsi_dcs_set_tear_on_multi(&dsi_ctx, MIPI_DSI_DCS_TEAR_MODE_VBLANK);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x5a, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0,
				     0x55, 0xaa, 0x52, 0x08, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd2,
				     0x00, 0x00, 0x00, 0x00, 0x15);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x05);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd2, 0x01, 0x00, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x0e);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd2,
				     0x00, 0x00, 0x10, 0x13, 0x32);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe4,
				     0x80, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00,
				     0x00, 0x00, 0x33);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x0a);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xe4,
				     0x80, 0x03, 0x00, 0x10, 0x00, 0x53);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x3b, 0x00, 0x18, 0x00, 0x10);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_WRITE_CONTROL_DISPLAY,
				     0x20);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x51,
				     0x00, 0x00, 0x0f, 0xff, 0x0f, 0xff);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x9c, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_WRITE_MEMORY_START,
				     0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x2f, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x5f, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, MIPI_DCS_SET_GAMMA_CURVE, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x8b, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0,
				     0x55, 0xaa, 0x52, 0x08, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x03);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc0, 0x10);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x31);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xdf, 0x21);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0,
				     0x55, 0xaa, 0x52, 0x08, 0x02);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xcc, 0x30);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xce, 0x01);
	mipi_dsi_msleep(&dsi_ctx, 20);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xcc, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0,
				     0x55, 0xaa, 0x52, 0x08, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc3,
				     0x90, 0x04, 0x20, 0x13, 0xff, 0x00, 0x04,
				     0x20, 0x0e, 0xff, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x0b);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc3,
				     0x06, 0x30, 0x1d, 0x06, 0x67, 0x14);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x11);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc3,
				     0x06, 0x30, 0x1d, 0x06, 0x67, 0x14);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x17);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc3,
				     0x06, 0x30, 0x1d, 0x06, 0x67, 0x14);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x1d);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc3,
				     0x06, 0x30, 0x1d, 0x06, 0x67, 0x14);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x23);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc3,
				     0x06, 0x30, 0x1d, 0x06, 0x67, 0x14);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0,
				     0x55, 0xaa, 0x52, 0x08, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x01);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbe, 0x45);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x05);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xbe, 0x88);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0,
				     0x55, 0xaa, 0x52, 0x08, 0x00);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x07);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb5, 0x2a, 0x1e, 0x00, 0x32);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb7,
				     0x40, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45,
				     0x46, 0x47, 0x48, 0x49, 0x4a, 0x4b, 0x4c,
				     0x4d, 0x4e, 0x4f, 0x50, 0x51, 0x51, 0x51,
			     0x51, 0x51, 0x51, 0x51);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x19);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb7,
				     0x17, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd,
				     0xee, 0xff, 0xff, 0xff, 0xff);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x25);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xb7,
				     0xba, 0xff, 0x77, 0xef, 0x67, 0xdf, 0x57,
				     0xcf, 0x47, 0xbf, 0x37, 0xaf, 0x27, 0x9f,
				     0x17, 0x8f, 0x07, 0x7f, 0xff, 0xff, 0xff,
				     0xff, 0xff, 0xff);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0,
				     0x55, 0xaa, 0x52, 0x08, 0x07);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xc0, 0xb1);
	mipi_dsi_dcs_exit_sleep_mode_multi(&dsi_ctx);
	mipi_dsi_msleep(&dsi_ctx, 120);
	mipi_dsi_dcs_set_display_on_multi(&dsi_ctx);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xf0,
				     0x55, 0xaa, 0x52, 0x08, 0x04);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x16);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd2, 0x19);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x16);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd4, 0x18);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x2f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd2, 0x28);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x2f);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd4, 0x27);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x48);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd2, 0x18);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x6f, 0x48);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0xd4, 0x17);

	return dsi_ctx.accum_err;
}

static int m11a_42_02_0a_dsc_off(struct m11a_42_02_0a_dsc *ctx)
{
	struct mipi_dsi_multi_context dsi_ctx = { .dsi = ctx->dsi };

	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x28, 0x00);
	mipi_dsi_msleep(&dsi_ctx, 20);
	mipi_dsi_dcs_write_seq_multi(&dsi_ctx, 0x10, 0x00);
	mipi_dsi_msleep(&dsi_ctx, 100);

	return dsi_ctx.accum_err;
}

static int m11a_42_02_0a_dsc_enable_supplies(struct m11a_42_02_0a_dsc *ctx)
{
	/* Stock M11A power-on order: VDDIO, VDDD, then VCI. */
	static const unsigned int post_enable_us[] = { 20000, 20000, 15000 };
	unsigned int i;
	int ret;

	for (i = 0; i < ARRAY_SIZE(post_enable_us); i++) {
		if (i == 2)
			fsleep(10000); /* VCI pre-enable delay */

		ret = regulator_enable(ctx->supplies[i].consumer);
		if (ret) {
			dev_err(&ctx->dsi->dev, "Failed to enable %s: %d\n",
				ctx->supplies[i].supply, ret);
			regulator_bulk_disable(i, ctx->supplies);
			return ret;
		}

		fsleep(post_enable_us[i]);
	}

	return 0;
}

static int m11a_42_02_0a_dsc_prepare(struct drm_panel *panel)
{
	struct m11a_42_02_0a_dsc *ctx = to_m11a_42_02_0a_dsc(panel);
	struct device *dev = &ctx->dsi->dev;
	struct drm_dsc_picture_parameter_set pps;
	int ret;

	ret = m11a_42_02_0a_dsc_enable_supplies(ctx);
	if (ret)
		return ret;

	m11a_42_02_0a_dsc_reset(ctx);

	m11a_42_02_0a_dsc_off(ctx);

	ret = m11a_42_02_0a_dsc_on(ctx);
	if (ret < 0) {
		dev_err(dev, "Failed to initialize panel: %d\n", ret);
		gpiod_set_value_cansleep(ctx->reset_gpio, 1);
		regulator_bulk_disable(ARRAY_SIZE(ctx->supplies), ctx->supplies);
		return ret;
	}
	drm_dsc_pps_payload_pack(&pps, &ctx->dsc);

	ret = mipi_dsi_picture_parameter_set(ctx->dsi, &pps);
	if (ret < 0) {
		dev_err(panel->dev, "failed to transmit PPS: %d\n", ret);
		regulator_bulk_disable(ARRAY_SIZE(ctx->supplies), ctx->supplies);
		return ret;
	}

	ret = mipi_dsi_compression_mode(ctx->dsi, true);
	if (ret < 0) {
		dev_err(dev, "failed to enable compression mode: %d\n", ret);
		regulator_bulk_disable(ARRAY_SIZE(ctx->supplies), ctx->supplies);
		return ret;
	}
	msleep(28); /* TODO: Is this panel-dependent? */

	return 0;
}

static int m11a_42_02_0a_dsc_unprepare(struct drm_panel *panel)
{
	struct m11a_42_02_0a_dsc *ctx = to_m11a_42_02_0a_dsc(panel);
	struct device *dev = &ctx->dsi->dev;
	int ret;

	ret = m11a_42_02_0a_dsc_off(ctx);
	if (ret < 0)
		dev_err(dev, "Failed to un-initialize panel: %d\n", ret);

	gpiod_set_value_cansleep(ctx->reset_gpio, 1);
	regulator_bulk_disable(ARRAY_SIZE(ctx->supplies), ctx->supplies);

	return 0;
}

/*
 * Command mode uses horizontal blanking as the DSI transfer-time budget. The
 * vendor programs a 7.3 ms transfer window at 1.2 Gb/s per lane.
 */
#define M11A_CMD_TRANSFER_HTOTAL 1990

static const struct drm_display_mode m11a_42_02_0a_dsc_mode = {
	.clock = M11A_CMD_TRANSFER_HTOTAL * (3200 + 16 + 14 + 6) * 60 / 1000,
	.hdisplay = 1440,
	.hsync_start = 1440 + 8,
	.hsync_end = 1440 + 8 + 12,
	.htotal = M11A_CMD_TRANSFER_HTOTAL,
	.vdisplay = 3200,
	.vsync_start = 3200 + 16,
	.vsync_end = 3200 + 16 + 14,
	.vtotal = 3200 + 16 + 14 + 6,
	.width_mm = 695,
	.height_mm = 1545,
	.type = DRM_MODE_TYPE_DRIVER,
};

static int m11a_42_02_0a_dsc_get_modes(struct drm_panel *panel,
				       struct drm_connector *connector)
{
	return drm_connector_helper_get_modes_fixed(connector, &m11a_42_02_0a_dsc_mode);
}

static const struct drm_panel_funcs m11a_42_02_0a_dsc_panel_funcs = {
	.prepare = m11a_42_02_0a_dsc_prepare,
	.unprepare = m11a_42_02_0a_dsc_unprepare,
	.get_modes = m11a_42_02_0a_dsc_get_modes,
};

static int m11a_42_02_0a_dsc_bl_update_status(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness = backlight_get_brightness(bl);
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_set_display_brightness_large(dsi, brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return 0;
}

// TODO: Check if /sys/class/backlight/.../actual_brightness actually returns
// correct values. If not, remove this function.
static int m11a_42_02_0a_dsc_bl_get_brightness(struct backlight_device *bl)
{
	struct mipi_dsi_device *dsi = bl_get_data(bl);
	u16 brightness;
	int ret;

	dsi->mode_flags &= ~MIPI_DSI_MODE_LPM;

	ret = mipi_dsi_dcs_get_display_brightness_large(dsi, &brightness);
	if (ret < 0)
		return ret;

	dsi->mode_flags |= MIPI_DSI_MODE_LPM;

	return brightness;
}

static const struct backlight_ops m11a_42_02_0a_dsc_bl_ops = {
	.update_status = m11a_42_02_0a_dsc_bl_update_status,
	.get_brightness = m11a_42_02_0a_dsc_bl_get_brightness,
};

static struct backlight_device *
m11a_42_02_0a_dsc_create_backlight(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	const struct backlight_properties props = {
		.type = BACKLIGHT_RAW,
		.brightness = 4095,
		.max_brightness = 4095,
	};

	return devm_backlight_device_register(dev, dev_name(dev), dev, dsi,
					      &m11a_42_02_0a_dsc_bl_ops, &props);
}

static int m11a_42_02_0a_dsc_probe(struct mipi_dsi_device *dsi)
{
	struct device *dev = &dsi->dev;
	struct m11a_42_02_0a_dsc *ctx;
	int ret;

	ctx = devm_drm_panel_alloc(dev, struct m11a_42_02_0a_dsc, panel,
				   &m11a_42_02_0a_dsc_panel_funcs,
				   DRM_MODE_CONNECTOR_DSI);
	if (IS_ERR(ctx))
		return PTR_ERR(ctx);

	ctx->supplies[0].supply = "vddio";
	ctx->supplies[1].supply = "vddd";
	ctx->supplies[2].supply = "vci";
	ret = devm_regulator_bulk_get(dev, ARRAY_SIZE(ctx->supplies),
				      ctx->supplies);
	if (ret < 0)
		return dev_err_probe(dev, ret, "Failed to get regulators\n");

	ctx->reset_gpio = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
	if (IS_ERR(ctx->reset_gpio))
		return dev_err_probe(dev, PTR_ERR(ctx->reset_gpio),
				     "Failed to get reset-gpios\n");

	ctx->dsi = dsi;
	mipi_dsi_set_drvdata(dsi, ctx);

	dsi->lanes = 4;
	dsi->format = MIPI_DSI_FMT_RGB888;
	dsi->mode_flags = MIPI_DSI_CLOCK_NON_CONTINUOUS | MIPI_DSI_MODE_LPM;

	ctx->panel.prepare_prev_first = true;

	ctx->panel.backlight = m11a_42_02_0a_dsc_create_backlight(dsi);
	if (IS_ERR(ctx->panel.backlight))
		return dev_err_probe(dev, PTR_ERR(ctx->panel.backlight),
				     "Failed to create backlight\n");

	drm_panel_add(&ctx->panel);

	/* This panel only supports DSC; unconditionally enable it */
	dsi->dsc = &ctx->dsc;

	ctx->dsc.dsc_version_major = 1;
	ctx->dsc.dsc_version_minor = 2;

	ctx->dsc.slice_height = 32;
	ctx->dsc.slice_width = 720;
	/*
	 * TODO: hdisplay should be read from the selected mode once
	 * it is passed back to drm_panel (in prepare?)
	 */
	WARN_ON(1440 % ctx->dsc.slice_width);
	ctx->dsc.slice_count = 1440 / ctx->dsc.slice_width;
	ctx->dsc.bits_per_component = 10;
	ctx->dsc.bits_per_pixel = 8 << 4; /* 4 fractional bits */
	ctx->dsc.block_pred_enable = true;

	ret = mipi_dsi_attach(dsi);
	if (ret < 0) {
		drm_panel_remove(&ctx->panel);
		return dev_err_probe(dev, ret, "Failed to attach to DSI host\n");
	}

	return 0;
}

static void m11a_42_02_0a_dsc_remove(struct mipi_dsi_device *dsi)
{
	struct m11a_42_02_0a_dsc *ctx = mipi_dsi_get_drvdata(dsi);
	int ret;

	ret = mipi_dsi_detach(dsi);
	if (ret < 0)
		dev_err(&dsi->dev, "Failed to detach from DSI host: %d\n", ret);

	drm_panel_remove(&ctx->panel);
}

static const struct of_device_id m11a_42_02_0a_dsc_of_match[] = {
	{ .compatible = "mdss,m11a-42-02-0a-dsc" }, // FIXME
	{ /* sentinel */ }
};
MODULE_DEVICE_TABLE(of, m11a_42_02_0a_dsc_of_match);

static struct mipi_dsi_driver m11a_42_02_0a_dsc_driver = {
	.probe = m11a_42_02_0a_dsc_probe,
	.remove = m11a_42_02_0a_dsc_remove,
	.driver = {
		.name = "panel-m11a-42-02-0a-dsc",
		.of_match_table = m11a_42_02_0a_dsc_of_match,
	},
};
module_mipi_dsi_driver(m11a_42_02_0a_dsc_driver);

MODULE_AUTHOR("linux-mdss-dsi-panel-driver-generator <fix@me>"); // FIXME
MODULE_DESCRIPTION("DRM driver for xiaomi 42 02 0a cmd mode dsc dsi panel");
MODULE_LICENSE("GPL");
