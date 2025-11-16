#include "../random/random.h"

using namespace std;

int getRandomInt(int range)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, range - 1);

	return dis(gen);
}
