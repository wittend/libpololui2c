# Examples

## 1) Scan and print devices
```aiignore
#include <stdio.h> 
#include <stdint.h> 
#include "pololu_i2c.h"

int main() 
{ 
    pololu_i2c_adapter adp; 
    pololu_i2c_init(&adp);
    
    if (pololu_i2c_connect(&adp, "/dev/ttyACM0") != 0) 
    {
        fprintf(stderr, "Connect failed\n");
        return 1;
    }

    // Optionally set I²C frequency, e.g., 100, 400, 1000 kHz
    if (pololu_i2c_set_frequency(&adp, 400) != 0) 
    {
        fprintf(stderr, "Set frequency failed\n");
    }

    uint8_t addrs[32];
    int n = pololu_i2c_scan(&adp, addrs, 32);
    if (n < 0) 
    {
        fprintf(stderr, "Scan failed: %s\n", pololu_i2c_error_string(-n));
    } 
    else 
    {
        printf("Found %d device(s):", n);
        for (int i = 0; i < n; ++i) 
        {
            printf(" 0x%02X", addrs[i]);
            printf("\n");
        }
}

pololu_i2c_disconnect(&adp);
return 0;
``` 

## 2) Write then read
Many I²C sensors use a “write register address, then read data” pattern.
```
#include <stdio.h> 
#include <stdint.h> 
#include "pololu_i2c.h"

int main() 
{ 
    pololu_i2c_adapter adp; 
    pololu_i2c_init(&adp);
    if (pololu_i2c_connect(&adp, "/dev/ttyACM0") != 0) 
    {
        fprintf(stderr, "Connect failed\n");
        return 1;
    }

    uint8_t addr = 0x68; // example device
    uint8_t reg  = 0x00; // example register
    int rv;

    // Write register index
    rv = pololu_i2c_write_to(&adp, addr, &reg, 1);
    if (rv < 0) 
    {
        fprintf(stderr, "Write failed: %s\n", pololu_i2c_error_string(-rv));
        goto done;
    }
    // Read back 2 bytes
    uint8_t buf[2] = {0};
    rv = pololu_i2c_read_from(&adp, addr, buf, 2);
    if (rv < 0) 
    {
        fprintf(stderr, "Read failed: %s\n", pololu_i2c_error_string(-rv));{
        fprintf(stderr, "Write failed: %s\n", pololu_i2c_error_string(-rv));
        goto done;
    }

    // Read back 2 bytes
    uint8_t buf[2] = {0};
    rv = pololu_i2c_read_from(&adp, addr, buf, 2);
    if (rv < 0) 
    {
        fprintf(stderr, "Read failed: %s\n", pololu_i2c_error_string(-rv));
        goto done;
    }
    printf("Data: %02X %02X\n", buf[0], buf[1]);
done: 
    pololu_i2c_disconnect(&adp); 
    return 0; 
}

````