#include "../sleep/tsleep.h"
#include <CoreFoundation/CoreFoundation.h>
#include <CoreGraphics/CoreGraphics.h>

#pragma once

// Axises qty (1 = vertical)
void scrollVertical(int delta);

// Vertical scroll (0 = dont moving)
void scrollHorizontal(int delta);

// Combined scroll (vertical and horizontal)
void scroll(int verticalDelta, int horizontalDelta);

// Scroll in px (more sensitive)
void scrollPixels(int verticalPixels, int horizontalPixels = 0);

// Animated scroll
void smoothScroll(int totalDelta, int steps = 20, int delayMs = 10);

// Scroll to bottom of page
void scrollToBottom(int scrollAmount = 10, int steps = 50);

// Scroll to start of page
void scrollToTop(int scrollAmount = 10, int steps = 50);
