/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/hexify-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/

#include "utest.h"
#include <hexify/hexify.h>

UTEST(Hexify, short1)
{
    char target[8];
    uint8_t data[] = { 0x10, 0x33, 0xff };

    char* dest = hexifyFormat(target, 8, data, sizeof(data));
    ASSERT_STREQ(dest, "0000  1");
}

UTEST(Hexify, short2)
{
    char target[16];
    uint8_t data[] = { 0x10, 0x33, 0xff, 0x88 };

    char* dest = hexifyFormat(target, 16, data, sizeof(data));
    ASSERT_STREQ(dest, "0000  10 33 FF ");
}

UTEST(Hexify, normal)
{
    char target[16];
    uint8_t data[] = { 0x2F, 0x9A };

    char* dest = hexifyFormat(target, 16, data, sizeof(data));
    ASSERT_STREQ(dest, "0000  2F 9A \n");
}

UTEST(Hexify, zero)
{
    char target[1];
    uint8_t data[] = { 0x2F, 0x9A };

    char* dest = hexifyFormat(target, 0, data, sizeof(data));
    ASSERT_STREQ(dest, "");
}