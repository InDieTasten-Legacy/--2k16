#include "EventManager.hpp"

IDT::EXP::Processing::EventManager::EventManager(BaseLogger & logger)
	:
	logger(logger)
{
	logger.Info("EventManager has been constructed: " + Conversion::ToString(this));
}

IDT::EXP::Processing::EventManager::~EventManager()
{
	if (running)
	{
		logger.Warning("Destruction of EventManager initializes Stop of Event Handling");
		running = false;
		Lock lock(mtxRunning);
	}
	logger.Info("EventManager has been destructed:  " + Conversion::ToString(this));
}

void IDT::EXP::Processing::EventManager::Run()
{
	if (!running)
	{
		logger.Info("EventManager will be started");
		running = true;
		handle();
	}
	else
	{
		logger.Warning("Tried launching already running EventManager");
	}
}

void IDT::EXP::Processing::EventManager::Stop()
{
	if (running)
	{
		logger.Info("Initializing stop of EventManager");
		running = false;
		Lock lock(mtxRunning);
		logger.Info("EventManager has been stopped");
	}
	else
	{
		logger.Warning("Tried stopping already stopped EventManager");
	}
}

bool IDT::EXP::Processing::EventManager::IsRunning()
{
	return running;
}

void IDT::EXP::Processing::EventManager::handle()
{
	logger.Info("EventManager has been started");
	Lock lock(mtxRunning);

	while (running)
	{
		sleep(seconds(5));
		
		logger.Info("EventManager will be stopped");
		lock.~Lock();
		Stop();
	}

}
