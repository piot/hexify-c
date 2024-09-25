/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/hexify-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/

#ifndef HEXIFY_H
#define HEXIFY_H

#include <stddef.h> // For size_t
#include <stdint.h> // For uint8_t

char* hexifyFormat(char* target, size_t max_count, const uint8_t* data, size_t length);

#endif
