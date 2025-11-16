#include "../process/process.h"
#include "../tools/random/random.h"
#include <iostream>

#define DELAY_RANGE  60
#define SCROLL_RANGE 50

using namespace std;

int getRandomDelay()
{
	int del = getRandomInt(DELAY_RANGE);
	cout << "Delay " << del << " sec" << endl;

	return del;
}

int getRandomScrollDirection()
{
	int val = getRandomInt(SCROLL_RANGE);
	int arr[2] = {-val, val};
	int randIndex = getRandomInt(2);

	int direction = arr[randIndex];
	cout << "Scroll direction " << direction << endl;

	return direction;
}

void process()
{
	for (;;)
	{
		int del1 = getRandomDelay();
		int scroll1 = getRandomScrollDirection();
        tSleepSec(del1);
		smoothScroll(scroll1);
		leftClick();
		
		moveRand(2);

		int del2 = getRandomDelay();
		int scroll2 = getRandomScrollDirection();
        tSleepSec(del2);
		smoothScroll(scroll2);
        leftClick();
	}
}
