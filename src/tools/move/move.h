#include "../screen/screen.h"
#include <CoreFoundation/CoreFoundation.h>
#include <CoreGraphics/CoreGraphics.h>

#pragma once

// Move coursor to coordinates
void moveTo(int x, int y);

// Move randomly 
// Could be limited with divider
void moveRand(int divider = 1);
