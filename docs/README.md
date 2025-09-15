# libpololui2c

A lightweight C/C++17 library for talking to Pololu USB-to-I²C adapters over a serial port on POSIX systems.

Status: early-stage, usable for basic operations (connect, set frequency, write/read, scan). Some auxiliary APIs are placeholders.

- OS: Linux, macOS (POSIX termios serial)
- Language: C/C++17 compatible
- Transport: Serial (e.g., /dev/ttyACM0)

See:
- Getting started: ./Getting-Started.md
- API reference: ./API.md
- Error codes: ./Errors.md
- Examples: ./Examples.md

## Known Issues

- Some helper functions are currently stubs (timeout, STM32 timing, digital read, VCC out).
- There may be naming inconsistencies between declarations and definitions for certain auxiliary functions. Before relying on them, verify the exact exported symbol names and adjust as needed.
- Only POSIX serial is supported at this time.

If you run into issues or want to contribute, see ./Contributing.md.