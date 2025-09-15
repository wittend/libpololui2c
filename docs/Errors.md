# Error Codes

Errors are returned as negative integers by most functions. Use `pololu_i2c_error_string()` to convert to messages.

Common codes:
- 0: No error
- 1: Protocol error (invalid command/data)
- 2: Previous command timed out
- 3: Timeout (operation exceeded adapter’s I²C timeout)
- 4: Timeout sending address
- 5: Timeout while transmitting data
- 6: Timeout while receiving data
- 7: NACK (generic)
- 8: Address NACK (target didn’t respond)
- 9: TX data NACK
- 10: Bus error (unexpected START/STOP)
- 11: Arbitration lost
- 12: Other
- 13: Not supported

Troubleshooting:
- Address NACK: check target power, wiring, pull-ups, and correct 7-bit address.
- Timeouts: increase I²C timeout (once supported), verify bus health, reduce speed.
- Bus error/arbitration lost: multiple controllers on bus or noise; try lowering speed and ensuring proper pull-ups.