#include <stdlib.h>
#include <iostream>
#include "../move/move.h"
#include "../random/random.h"

#define TAP			kCGHIDEventTap
#define MOVE		kCGEventMouseMoved
#define LEFT_BUTTON kCGMouseButtonLeft

using namespace std;

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
    int moveX = getRandomInt((int)(size.width / divider));
    int moveY = getRandomInt((int)(size.height / divider));

	cout << "Moved to x: " << moveX << " y: " << moveY << endl;
	moveTo(moveX, moveY);
}
