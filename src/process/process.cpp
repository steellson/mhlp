#include "../process/process.h"
#include "../tools/random/random.h"
#include <iostream>

#define DELAY_RANGE  60
#define SCROLL_RANGE 50

using namespace std;

int del, scrll;

void randomizeDelay()
{
	del = getRandomInt(DELAY_RANGE);
	cout << "Delay " << del << " sec" << endl;
}

void randomizeScrollDirection()
{
	int val = getRandomInt(SCROLL_RANGE);
	int arr[2] = {-val, val};
	int randIndex = getRandomInt(2);

	int direction = arr[randIndex];
	scrll = direction;
	cout << "Scroll direction " << direction << endl;
}

void process()
{
	for (;;)
	{
		randomizeDelay();
		randomizeScrollDirection();
        tSleepSec(del);
		smoothScroll(scrll);
		leftClick();

		moveRand(2);

		randomizeDelay();
		randomizeScrollDirection();
        tSleepSec(del);
		smoothScroll(scrll);
        leftClick();
	}
}
