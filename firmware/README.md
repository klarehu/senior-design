# 3D Printer Main Firmware

This contains the main body of code from Gcode to complete 3D printer motion. 

### Axis

Axis.h contains relevant delarations. Axis.cpp defines the axes and implements the movements for the laser head and the ink deposition nozzle.

### Definitions

Currently supports 1 X axis motor, 2 y-axis motor, 1 z-axis motor. There is one laser pin.

Collector: collector roller motor for spooling in substrate. 

Unroller: roller motor for unspooling. 

###### Needs work

Adding motor pins for the extruder motor as well as the two axis (raster motion) supporting it. 


### Parser.cpp

Implements overall axis motion for the 3D printer. 

