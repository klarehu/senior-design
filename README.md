# Space Jam!

### Firmware

This firmware is designed to run on an Arduino board connected with a Serial (USB) cable. To change the pins for the step and direction, modify `Definitions.h`. All the firmware lives in the `firmware/` directory.

### Features

- [x] Serial reading
- [x] Command finished "OK"
- [x] Axis representation and state tracking
- [x] Add support for second Y axis
- [x] Axis homing on bootup
- [x] Command Parsing
    - [x] G0 (move, supports X, Y, Z, E, F)
    - [x] "Home"
    - [x] "Laser"
- [ ] Command Implementations
	- [x] G0
	- [x] H0
	- [ ] T0
	- [ ] T1

### G-Code Reference

`G0 X[...] Y[...] U[...] Z[...] E[...] F[...]`: G0 is the standard `move` command for the printer. All axis begin at 0, and do not have a defined upper bound (i.e., it is up to the user to not over-extend the limits of the motion). `U` represents the second Y axis motor (and should always be commanded to the same position). `E` and `F` represent the roller collector motor and unroller motor respectively.

`H0`: Homes all motion axes (`X`, `Y`, `U`, `Z`) until they make contact with the limit switches.

`T0`: Turns the laser diode OFF

`T1`: Turns the laser diode ON

`L0 [axis]`: Tests a limit switch of the given `axis` (`0`: x, `1`: y, `2`: u, `3`: z)
