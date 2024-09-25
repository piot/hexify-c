/*----------------------------------------------------------------------------------------------------------
 *  Copyright (c) Peter Bjorklund. All rights reserved. https://github.com/piot/hexify-c
 *  Licensed under the MIT License. See LICENSE in the project root for license information.
 *--------------------------------------------------------------------------------------------------------*/
#include <hexify/hexify.h>
#include <stdio.h> // For snprintf

/// Writes the hex data to the specified target buffer.
/// @param target Output character buffer.
/// @param max_count Maximum size of the target buffer.
/// @param data Payload to log as hex.
/// @param length Size of data in octets.
char* hexifyFormat(char* target, size_t max_count, const uint8_t* data, size_t length)
{
    if (max_count == 0) {
        return "";
    }

    size_t pos = 0;

    if (length == 0) {
        if (max_count > 0)
            target[0] = '\0';
        return target;
    }

    for (size_t i = 0; i < length; ++i) {
        // At the beginning of each line (every 16 bytes)
        if (i % 16 == 0) {
            if (i != 0) {
                // Add a newline after every line except the first
                int ret = snprintf(target + pos, max_count - pos, "\n");
                if (ret < 0 || (size_t)ret >= max_count - pos) {
                    target[max_count - 1] = '\0';
                    return target;
                }
                pos += (size_t)ret;
            }
            // Add the hex offset at the beginning of each line
            int ret = snprintf(target + pos, max_count - pos, "%04X ", (unsigned int)i);
            if (ret < 0 || (size_t)ret >= max_count - pos) {
                target[max_count - 1] = '\0';
                return target;
            }
            pos += (size_t)ret;
        }

        // Add an extra space before each group
        if (i % 8 == 0) {
            int ret = snprintf(target + pos, max_count - pos, " ");
            if (ret < 0 || (size_t)ret >= max_count - pos) {
                target[max_count - 1] = '\0';
                return target;
            }
            pos += (size_t)ret;
        }

        // Write the hex representation of the byte
        int ret = snprintf(target + pos, max_count - pos, "%02X ", data[i]);
        if (ret < 0 || (size_t)ret >= max_count - pos) {
            if (max_count > 0)
                target[max_count - 1] = '\0';
            return target;
        }
        pos += (size_t)ret;
    }

    // Add a final newline if there's space
    if (pos < max_count - 1) {
        target[pos++] = '\n';
        target[pos] = '\0';
    } else {
        // Ensure the buffer is null-terminated
        target[max_count - 1] = '\0';
    }

    return target;
}
