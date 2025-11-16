#include "../scroll/scroll.h"

#define TAP		kCGHIDEventTap
#define PIXELS	kCGScrollEventUnitPixel
#define LINES	kCGScrollEventUnitLine

/*
 * Vertical scroll
 * delta > 0 - scroll to top
 * delta < 0 - scroll to bottom
 *
 * Horizontal scroll
 * delta > 0 - scroll to right
 * delta < 0 - scroll to left
 */

void scrollVertical(int delta)
{
    CGEventRef scrollEvent = CGEventCreateScrollWheelEvent(NULL, LINES, 1, delta);
    CGEventPost(TAP, scrollEvent);
    CFRelease(scrollEvent);
}

void scrollHorizontal(int delta)
{
    CGEventRef scrollEvent = CGEventCreateScrollWheelEvent(NULL, LINES, 2, 0, delta);
    CGEventPost(TAP, scrollEvent);
    CFRelease(scrollEvent);
}

void scroll(int verticalDelta, int horizontalDelta)
{
    CGEventRef scrollEvent = CGEventCreateScrollWheelEvent(NULL, LINES, 2, verticalDelta, horizontalDelta);
    CGEventPost(TAP, scrollEvent);
    CFRelease(scrollEvent);
}

void scrollPixels(int verticalPixels, int horizontalPixels)
{
    CGEventRef scrollEvent = CGEventCreateScrollWheelEvent(NULL, PIXELS, 2, verticalPixels, horizontalPixels);
    CGEventPost(TAP, scrollEvent);
    CFRelease(scrollEvent);
}

void smoothScroll(int totalDelta, int steps, int delayMs)
{
    int deltaPerStep = totalDelta / steps;
    for (int i = 0; i < steps; i++)
    {
        scrollVertical(deltaPerStep);
		tSleepNanosec(delayMs);
    }
}

void scrollToBottom(int scrollAmount, int steps)
{
    for (int i = 0; i < steps; i++)
    {
        scrollVertical(-scrollAmount);
        tSleepNanosec(20);
    }
}

void scrollToTop(int scrollAmount, int steps)
{
    for (int i = 0; i < steps; i++)
    {
        scrollVertical(scrollAmount);
        tSleepNanosec(20);
    }
}
