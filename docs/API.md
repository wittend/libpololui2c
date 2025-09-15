# API Reference
```aiignore
int pololu_i2c_init(pololu_i2c_adapter* adapter, const char* device_path);
int pololu_i2c_close(pololu_i2c_adapter* adapter);
```
Headers: `pololu_i2c.h`

All functions return `0` on success unless otherwise noted. Negative values indicate errors; pass the absolute value to `pololu_i2c_error_string` for a readable description.

## Types
 
```aiignore
typedef struct 
{ 
    int fd; // serial file descriptor 
} pololu_i2c_adapter;

typedef struct 
{ 
    uint16_t vendor_id; 
    uint16_t product_id; 
    char firmware_version[16]; 
    uint16_t firmware_version_bcd; 
    char firmware_modification[9]; 
    char serial_number[25]; 
} pololu_i2c_device_info;

```
```aiignore
int pololu_i2c_write_to(pololu_i2c_adapter* adapter, uint8_t address, const uint8_t* data, uint8_t size); // returns bytes written or negative error
int pololu_i2c_read_from(pololu_i2c_adapter* adapter, uint8_t address, uint8_t* data, uint8_t size); // returns bytes read or negative error
```
- `write_to`: Sends a payload to a 7-bit I²C address.
- `read_from`: Reads `size` bytes from a 7-bit I²C address.

Convenience register read/write helpers may be available; when using register-based devices, a common pattern is write the register, then read the data.
## Bus Control
```aiignore
int pololu_i2c_set_frequency(pololu_i2c_adapter* adapter, unsigned int frequency_khz); 
int pololu_i2c_clear_bus(pololu_i2c_adapter* adapter);
```

- `set_frequency`: Accepts common speeds in kHz; internally maps to supported modes:
    - 10 kHz mode (<= 100)
    - Standard-mode (100 kHz)
    - Fast-mode (400 kHz)
    - Fast-mode Plus (1000 kHz)

- `clear_bus`: Attempts an I²C bus recovery.

## Device Info

```aiignore
int pololu_i2c_get_device_info(pololu_i2c_adapter* adapter, pololu_i2c_device_info* info);
```
- Probes 0x00–0x7F; stores addresses that ACK.
## Error Handling
```
const char* pololu_i2c_error_string(int error_code);
```
- Convert error codes to human-readable strings. If a function returns `-x`, pass `x` or the negative value directly.
## Placeholders / Experimental

These functions are declared/mentioned but currently serve as stubs or may differ by name in code vs header. They are reserved for future functionality:

- Convert error codes to human-readable strings. If a function returns `-x`, pass `x` or the negative value directly.

These functions are declared/mentioned but currently serve as stubs or may differ by name in code vs header. They are reserved for future functionality:
```
int pololu_i2c_set_timeout(); // I²C operation timeout config int pololu_i2c_set_STM32_timing(); // Low-level timing tuning int pololu_i2c_digital_read(); // General purpose digital input int pololu_i2c_enable_VCC_out(); // Enable adapter’s VCC out
```
