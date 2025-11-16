#include <stdlib.h>
#include <chrono>
#include <thread>

#pragma once

// Sleep for current thread
// Metrics - nanoseconds
void tSleepNanosec(int);

// Metrics - seconds
void tSleepSec(int);
