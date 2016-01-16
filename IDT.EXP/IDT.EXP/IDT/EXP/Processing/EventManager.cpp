#include "EventManager.hpp"

IDT::EXP::Processing::EventManager::EventManager(RenderWindow& renderWindow, BaseLogger & logger)
	:
	logger(logger),
	renderWindow(renderWindow),
	internalEvents(logger),
	Events(logger, internalEvents)
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
			case sf::Event::JoystickButtonPressed:
				internalEvents.JoystickButtonPressed.Raise(event.joystickButton);
				break;
			case sf::Event::JoystickButtonReleased:
				internalEvents.JoystickButtonReleased.Raise(event.joystickButton);
				break;
			case sf::Event::JoystickConnected:
				internalEvents.JoystickConnected.Raise(event.joystickConnect);
				break;
			case sf::Event::JoystickDisconnected:
				internalEvents.JoystickDisconnected.Raise(event.joystickConnect);
				break;
			case sf::Event::JoystickMoved:
				internalEvents.JoystickMoved.Raise(event.joystickMove);
				break;
			case sf::Event::KeyPressed:
				internalEvents.KeyPressed.Raise(event.key);
				break;
			case sf::Event::KeyReleased:
				internalEvents.KeyReleased.Raise(event.key);
				break;
			case sf::Event::MouseButtonPressed:
				internalEvents.MouseButtonPressed.Raise(event.mouseButton);
				break;
			case sf::Event::MouseButtonReleased:
				internalEvents.MouseButtonReleased.Raise(event.mouseButton);
				break;
			case sf::Event::MouseMoved:
				internalEvents.MouseMoved.Raise(event.mouseMove);
				break;
			case sf::Event::MouseWheelMoved:
				internalEvents.MouseWheelMoved.Raise(event.mouseWheel);
				break;
			case sf::Event::MouseWheelScrolled:
				internalEvents.MouseWheelScrolled.Raise(event.mouseWheelScroll);
				break;
			case sf::Event::SensorChanged:
				internalEvents.SensorChanged.Raise(event.sensor);
				break;
			case sf::Event::Resized:
				internalEvents.Resized.Raise(event.size);
				break;
			case sf::Event::TextEntered:
				internalEvents.TextEntered.Raise(event.text);
				break;
			case sf::Event::TouchBegan:
				internalEvents.TouchBegan.Raise(event.touch);
				break;
			case sf::Event::TouchMoved:
				internalEvents.TouchMoved.Raise(event.touch);
				break;
			case sf::Event::TouchEnded:
				internalEvents.TouchEnded.Raise(event.touch);
				break;
			case sf::Event::Closed:
				internalEvents.Closed.Raise(0);
				break;
			}
		}
	}
	logger.Info("EventManager will be stopped");
}
