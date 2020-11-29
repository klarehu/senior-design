# Space Jam!

### Firmware

This firmware is designed to run on an Arduino board connected with a Serial (USB) cable. To change the pins for the step and direction, modify `Definitions.h`. All the firmware lives in the `firmware/` directory.

#### Functionality

- [x] Serial reading
- [x] Command finished "OK"
- [x] Axis representation and state tracking
- [ ] Add support for second Y axis
- [ ] Command Parsing
    - [x] G0 (move, supports X, Y, Z, E, F)
    - [ ] "Home"
    - [ ] "Laser"
    - [ ] "Substrate Depositing"
