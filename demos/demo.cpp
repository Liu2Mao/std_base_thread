#include "test_thread.h"

#define  WIN32

#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32


void common_sleep(unsigned int seconds)
{
#ifdef WIN32
	Sleep(seconds * 1000);
#else
	sleep(seconds);;
#endif
}


void common_pause(void)
{
#ifdef WIN32
	system("pause");
#endif // WIN32
}

int main(void)
{
	test_thread test;
	common_pause();
	return 0;
}



