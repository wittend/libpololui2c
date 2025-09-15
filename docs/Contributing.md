# Contributing

Thanks for your interest!

## Development Notes
- Keep the API C-friendly and usable from C++.
- Prefer small, well-documented functions; propagate adapter errors as negative values.
- Ensure serial port configuration and I²C command layout remain consistent.

## Areas To Improve
- Align function names between headers and sources (e.g., STM32 timing/digital read/VCC out).
- Implement timeout configuration and digital I/O helpers.
- Add Windows support via appropriate serial APIs.
- Expand tests and add CI.

## Style
- Compile with `-Wall -Wextra` (or equivalent) and aim for zero warnings.
- Keep documentation in `/docs` up to date when changing public APIs.

## Filing Issues
When reporting a bug, please include:
- OS and compiler versions
- Serial device path and adapter model
- Minimal sample code and steps to reproduce
- Expected vs. actual behavior and any logs