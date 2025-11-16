#include <stdlib.h>
#include <iostream>
#include <ostream>
#include <unistd.h>

#include "src/click/click.h"
#include "src/move/move.h"
#include "src/scroll/scroll.h"
#include "src/sleep/tsleep.h"

using namespace std;

void process(int sleep, int steps)
{
	for (int i = 0; i < steps ; i++)
	{
		scrollToTop();
		leftClick();
		tSleepSec(sleep);

		moveRand(2);
		tSleepSec(sleep);

		leftClick();
		tSleepSec(sleep);

		scrollToBottom();
        leftClick();
        tSleepSec(sleep);

		cout << "Step\t" << i+1 << endl;
	}
}

int main()
{
	const int sleep = 2;
	const int steps = 10;

	// Main process
	cout << "START" << endl;
	process(sleep, steps);
	cout << "STOP" << endl;

	return 0;
}
