#include <CoreGraphics/CGDirectDisplay.h>
#include <CoreGraphics/CoreGraphics.h>

#pragma once

struct ScreenSize { double width, height; };

// Current screen rect size
ScreenSize getScreenSize();
