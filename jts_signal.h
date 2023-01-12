#include <signal.h>

volatile sig_atomic_t run = 1;

void handler(int n)
{
	run = 0;
}

signal(SIGINT, handler);
