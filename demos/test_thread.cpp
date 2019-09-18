#include "test_thread.h"


test_thread::test_thread(void)
{
	run();
}

test_thread::~test_thread(void)
{
}

void test_thread::run(void)
{
	start(start_rtn, this);
}

void test_thread::print()
{
	std::cout << "hello,world\n";
	std::cout << "a = " << a << std::endl;
	a = 100000;
	std::cout << "a = " << a << std::endl;
}

void test_thread::start_rtn(std_base_thread* arg)
{
	test_thread* p = (test_thread*)arg;
	p->print();
	p->a = 1000;
	std::cout << "a = " << p->a << std::endl;
}
