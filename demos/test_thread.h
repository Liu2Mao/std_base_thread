#ifndef __TEST_THREAD_H
#define __TEST_THREAD_H

#include <iostream>
#include "std_base_thread.h"


class test_thread :
	public std_base_thread
{
public:
	test_thread(void);
	virtual ~test_thread(void);
	void run(void);

	void print(void);
	static void start_rtn(std_base_thread* arg);

	int a = 10;
};


#endif // __TEST_THREAD_H

