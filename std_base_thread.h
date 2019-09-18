#ifndef __STD_BASE_THREAD_H
#define __STD_BASE_THREAD_H

#include <thread>
#include <mutex>


class std_base_thread
{
	typedef void (*thread_start_rtn)(std_base_thread*);

public:
	explicit std_base_thread(void) {};
	virtual ~std_base_thread(void) {};

protected:
	inline static void start(thread_start_rtn _start_rtn,
		std_base_thread* _kid_this) {
		if (true == _kid_this->m_run_mutex.try_lock())
		{
			_kid_this->m_start_rtn = _start_rtn;
			std::thread t(start_rtn, _kid_this);
			_kid_this->m_id = t.get_id();
			t.detach();
		}
	};

private:
	inline static void start_rtn(std_base_thread* _kid_this) {
		_kid_this->m_start_rtn(_kid_this);
		_kid_this->m_run_mutex.unlock();
	};

private:
	std::thread::id m_id;
	std::mutex m_run_mutex;
	thread_start_rtn m_start_rtn;
};

#endif // __STD_BASE_THREAD_H
