#include <Arduino.h>
#include "Axis.h"

Axis findStateByIdentifier(Axis axes[], char c);

void parseGCode(Axis axes[], String line);
