/* 
 * Copyright 2025 Ryan Jacoby
 * SPDX-License-Identifier: Apache-2.0
 *
 * fw_alpha/src/main.c
 *
 * Alpha hardware bringup and validation firmware entry
 *
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

#define LED0_NODE DT_ALIAS(led0)
#define LED1_NODE DT_ALIAS(led1)

static const struct gpio_dt_spec led0 = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static const struct gpio_dt_spec led1 = GPIO_DT_SPEC_GET(LED1_NODE, gpios);

int main(void)
{
        int i;

        /* Ensure device tree was properly formed */
        if (!gpio_is_ready_dt(&led0) || !gpio_is_ready_dt(&led1)) {
                goto L_EXIT;
        }

        /* Config pins as output */
        if (gpio_pin_configure_dt(&led0, GPIO_OUTPUT_ACTIVE) < 0 || 
            gpio_pin_configure_dt(&led1, GPIO_OUTPUT_ACTIVE) < 0) {
                goto L_EXIT;
        }

        while (1) {
                for (i = 0; i < 4; i++) {
                        /* Count 0->3 in binary */
                        gpio_pin_set_dt(&led0, i & 0x01);
                        gpio_pin_set_dt(&led1, i & 0x02);

                        printf("LED state %d\n", i);

                        k_sleep(K_SECONDS(1));
                }
        }

L_EXIT:
        goto L_EXIT;
}
