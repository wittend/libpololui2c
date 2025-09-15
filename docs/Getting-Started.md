# Getting Started

## Prerequisites
- POSIX-like system (Linux, macOS)
- C/C++17 compiler (gcc/clang)
- Access to the serial device for your Pololu USB-to-I²C adapter (e.g., `/dev/ttyACM0`)

Tip (Linux): you might need to add your user to the `dialout` group or adjust udev rules to access `/dev/ttyACM*`.

## Build

Example using a simple compile and link (adjust paths to your project layout):

For C:
```aiignore
bash cc -std=c11 -O2 -Wall -Wextra -c pololu_i2c.c cc -o demo demo.c pololu_i2c.o
```
For C++:

```aiignore
bash c++ -std=gnu++17 -O2 -Wall -Wextra -c pololu_i2c.c c++ -std=gnu++17 -o demo demo.cpp pololu_i2c.o
```
## Basic Usage

- Initialize a handle
- Connect to the serial port
- Optionally set I²C frequency
- Use read/write helpers
- Disconnect

```aiignore
#include <stdio.h> 
#include <stdint.h> 
#include "pololu_i2c.h"

int main() { pololu_i2c_adapter adp; pololu_i2c_init(&adp);

if (pololu_i2c_connect(&adp, "/dev/ttyACM0") != 0) {
    fprintf(stderr, "Failed to connect\n");
    return 1;
}

// Optional: set I²C speed (kHz)
if (pololu_i2c_set_frequency(&adp, 400) != 0) {
    fprintf(stderr, "Failed to set I2C frequency\n");
}

// Example: scan bus
uint8_t addrs[16];
int found = pololu_i2c_scan(&adp, addrs, 16);
if (found >= 0) {
    printf("Found %d device(s):", found);
    for (int i = 0; i < found; ++i) printf(" 0x%02X", addrs[i]);
    printf("\n");
} else {
    fprintf(stderr, "Scan failed\n");
}

pololu_i2c_disconnect(&adp);
return 0;
```
