/*
 * Core functions for libfprint
 * Copyright (C) 2007 Daniel Drake <dsd@gentoo.org>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include <config.h>

#include <glib.h>

#include "fp_internal.h"

static GList *registered_drivers = NULL;

static void register_driver(const struct fp_driver *drv)
{
	registered_drivers = g_list_prepend(registered_drivers, (gpointer) drv);
}

static const struct fp_driver * const drivers[] = {
	&upekts_driver,
};

static void register_drivers(void)
{
	int i;

	for (i = 0; i < ARRAY_SIZE(drivers); i++)
		register_driver(drivers[i]);
}

API_EXPORTED int fp_init(void)
{
	register_drivers();
	return 0;
}
