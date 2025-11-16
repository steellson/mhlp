#include "../move/move.h"

#define TAP			kCGHIDEventTap
#define MOVE		kCGEventMouseMoved
#define LEFT_BUTTON kCGMouseButtonLeft

void moveTo(int x, int y)
{
    CGPoint point = CGPointMake(x, y);
    CGEventRef moveEvent = CGEventCreateMouseEvent(NULL, MOVE, point, LEFT_BUTTON);
    CGEventPost(TAP, moveEvent);
    CFRelease(moveEvent);
}

void moveRand(int divider)
{
    ScreenSize size = getScreenSize();
    int moveX = rand() % (int)(size.width / divider);
    int moveY = rand() % (int)(size.height / divider);
    moveTo(moveX, moveY);
}
