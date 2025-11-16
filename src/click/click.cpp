#include "click.h"

#define TAP			kCGHIDEventTap
#define UP			kCGEventLeftMouseUp
#define DOWN		kCGEventLeftMouseDown
#define LEFT_BUTTON kCGMouseButtonLeft

CGPoint getPosition()
{
    CGEventRef event = CGEventCreate(NULL);
    CGPoint cursor = CGEventGetLocation(event);
    CFRelease(event);
    return cursor;
}

void leftClick()
{
    CGPoint point = getPosition();

    CGEventRef mouseDown = CGEventCreateMouseEvent(NULL, DOWN, point, LEFT_BUTTON);
    CGEventPost(TAP, mouseDown);
    CFRelease(mouseDown);

    CGEventRef mouseUp = CGEventCreateMouseEvent(NULL, UP, point, LEFT_BUTTON);
    CGEventPost(TAP, mouseUp);
    CFRelease(mouseUp);
}
