#include "EventManager.hpp"

IDT::EXP::Processing::EventManager::EventManager(RenderWindow& renderWindow, BaseLogger & logger)
	:
	logger(logger),
	renderWindow(renderWindow),
	Events(logger)
{
	logger.Info("EventManager has been constructed: " + Conversion::ToString(this));
}

IDT::EXP::Processing::EventManager::~EventManager()
{
	if (running)
	{
		logger.Warning("Destruction of EventManager initializes Stop of Event Handling");
		Stop();
		sleep(seconds(2));
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
	
	Event event;
	
	while (running)
	{
		while (renderWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				Events.Closed.Raise(0);
				break;
			case sf::Event::KeyPressed:
				Events.KeyPressed.Raise(event.key);
				break;
			}
		}
	}
	logger.Info("EventManager will be stopped");
}
