/* Copyright (C) Alif Semiconductor - All Rights Reserved.
 * Use, distribution and modification of this code is permitted under the
 * terms stated in the Alif Semiconductor Software License Agreement
 *
 * You should have received a copy of the Alif Semiconductor Software
 * License Agreement with this file. If not, please write to:
 * contact@alifsemi.com, or visit: https://alifsemi.com/license
 */

#define LOG_LEVEL CONFIG_LOG_DEFAULT_LEVEL

#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(app);

int main(void)
{
	LOG_INF("Hello World!");
	return 0;
}

