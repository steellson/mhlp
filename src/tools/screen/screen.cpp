#include "../screen/screen.h"

ScreenSize getScreenSize()
{
	CGDirectDisplayID displayID = CGMainDisplayID();
	CGRect rect = CGDisplayBounds(displayID);
	ScreenSize size = ScreenSize {rect.size.width, rect.size.height};
	return size;
}
