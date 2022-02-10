#pragma once

#ifndef RENDER_THREAD
#define RENDER_THREAD

#include "../utilities/SafeQueue.h"
#include <functional>
#ifdef WIN32
#include <windows.h>
#elif _WIN64
#include <windows.h>
#else
#include <unistd.h>
#endif // win32

class RenderThread
{
private:

	uint8_t m_core;
	bool m_running;
	std::thread m_renderThread;
	std::function<void()> m_task;
	uint8_t m_runningTasks;

public:

	RenderThread();
	RenderThread(uint8_t core);
	~RenderThread();

	void StartWorkerThread();
	void StartWorkerThread(uint8_t core);
	void StopWorkerThread();
	void Enqueue(std::function<void()> task);
	bool IsRunning();
	int GetNumberRunningTasks();
};

#endif //RENDER_THREAD
