#include "../process/process.h"

using namespace std;

void process()
{
	const int sleepSecondsRange = 60;

	for (;;)
	{
		int sleep = rand() % sleepSecondsRange;
		cout << "Delay " << sleep << " sec" << endl;

        tSleepSec(sleep);
		scrollToTop();
		leftClick();
		
		moveRand(2);

        tSleepSec(sleep);
		scrollToBottom();
        leftClick();
	}
}
