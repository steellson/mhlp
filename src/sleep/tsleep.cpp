#include "../sleep//tsleep.h"
#include <chrono>
#include <thread>

using namespace std;

void tSleepNanosec(int ns)
{
	auto time = chrono::nanoseconds(ns);
	this_thread::sleep_for(time);
}

void tSleepSec(int s) 
{
	auto time = chrono::seconds(s);
	this_thread::sleep_for(time);
}
