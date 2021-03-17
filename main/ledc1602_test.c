
#include <stdio.h>
#include "driver/i2c.h"
#include "lcd_i2c.h"

void app_main()
{
    uint8_t zero[8] = {
        0b11111,
        0b11111,
        0b11000,
        0b11001,
        0b11001,
        0b11000,
        0b11111,
        0b11111,
    };

    uint8_t one[8] = {
        0b00000,
        0b00000,
        0b00000,
        0b00000,
        0b11111,
        0b11111,
        0b00000,
        0b00000,
    };

    uint8_t two[8] = {
        0b00000,
        0b00000,
        0b11111,
        0b11111,
        0b00000,
        0b00000,
        0b00000,
        0b00000,
    };
    uint8_t three[8] = {
        0b00000,
        0b11110,
        0b10011,
        0b10000,
        0b10000,
        0b10000,
        0b00000,
        0b00000,
    };
    uint8_t four[8] = {
        0b00000,
        0b00000,
        0b00000,
        0b11110,
        0b00110,
        0b00011,
        0b00011,
        0b00011,
    };
    uint8_t five[8] = {
        0b00000,
        0b00000,
        0b10000,
        0b10000,
        0b10000,
        0b10011,
        0b11110,
        0b00000,
    };

    uint8_t six[8] = {
        0b00011,
        0b00011,
        0b00011,
        0b00011,
        0b00110,
        0b11100,
        0b00000,
        0b00000,
    };

    uint8_t seven[8] = {
        0b11111,
        0b11111,
        0b00011,
        0b10011,
        0b10011,
        0b00011,
        0b11111,
        0b11111,
    };

    lcd1602_i2c_init(18, 19, 0);

    lcd1602_t lcdtmp = {0};
    lcdtmp.i2caddr = 0x27;
    lcdtmp.backlight = 1;
    
    lcd1602_dcb_set(&lcdtmp, 1, 0, 0);

    lcd1602_init(&lcdtmp);

    lcd1602_create_char(&lcdtmp, 0, zero);
    lcd1602_create_char(&lcdtmp, 1, one);
    lcd1602_create_char(&lcdtmp, 2, two);
    lcd1602_create_char(&lcdtmp, 3, three);
    lcd1602_create_char(&lcdtmp, 4, four);
    lcd1602_create_char(&lcdtmp, 5, five);
    lcd1602_create_char(&lcdtmp, 6, six);
    lcd1602_create_char(&lcdtmp, 7, seven);

    lcd1602_set_pos(&lcdtmp, 0, 0);

    lcd1602_send_data(&lcdtmp, 0);
    lcd1602_send_data(&lcdtmp, 7);
    for (int x = 0; x < 6; x++)
        lcd1602_send_data(&lcdtmp, 1);

    lcd1602_send_data(&lcdtmp, 3);
    lcd1602_send_data(&lcdtmp, 4);
    lcd1602_set_pos(&lcdtmp, 1, 0);

    lcd1602_send_data(&lcdtmp, 0);
    lcd1602_send_data(&lcdtmp, 7);

    for (int x = 0; x < 6; x++)
        lcd1602_send_data(&lcdtmp, 2);
    lcd1602_send_data(&lcdtmp, 5);
    lcd1602_send_data(&lcdtmp, 6);

    while (1)
    {
        lcd1602_rl_shift(&lcdtmp, LCD1602_DISPLAYMOVE, LCD1602_MOVERIGHT);
        vTaskDelay(150 / portTICK_PERIOD_MS);
    }
}
