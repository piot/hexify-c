# Hexify C99 Library

`hexify` is a simple, lightweight C99 library for formatting binary data into a human-readable hexadecimal representation (hex dump). It provides functionality to output data in a format similar to common hex dump tools, making it useful for debugging and inspecting binary data.

## Features

* Hexadecimal Formatting: Converts binary data into a formatted hex string.
* Offset Indicators: Includes byte offsets at the beginning of each line.
* Grouped Output: Groups hex values into customizable byte groups (default is 8 bytes).
* Line Wrapping: Wraps output after a specified number of bytes per line (default is 16 bytes).
* Buffer Safety: Ensures output does not exceed provided buffer size.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
