#pragma once

#include "../Utility/BaseLogger.hpp"
#include "../Utility/EventType.hpp"
#include "../Utility/EventRegister.hpp"
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <functional>
#include <list>

#include <iostream>

using namespace std;
using namespace IDT::EXP::Utility;
using namespace sf;

namespace IDT
{
	namespace EXP
	{
		namespace Processing
		{
			class EventManager
			{
			private:
				RenderWindow& renderWindow;
				BaseLogger& logger;
				bool running = false;

				struct events
				{
					events(BaseLogger& logger)
						:
						JoyStickButtonPressed(logger),
						JoyStickButtonReleased(logger),
						JoyStickConnected(logger),
						JoystickDisconnected(logger),
						JoystickMoved(logger),
						KeyPressed(logger),
						KeyReleased(logger),
						MouseButtonPressed(logger),
						MouseButtonReleased(logger),
						MouseMoved(logger),
						MouseWheelMoved(logger),
						MouseWheelScrolled(logger),
						SensorChanged(logger),
						Resized(logger),
						TextEntered(logger),
						TouchBegan(logger),
						TouchMoved(logger),
						TouchEnded(logger),
						Closed(logger)
					{}
					EventType<Event::JoystickButtonEvent&> JoyStickButtonPressed;
					EventType<Event::JoystickButtonEvent&> JoyStickButtonReleased;
					EventType<Event::JoystickConnectEvent&> JoyStickConnected;
					EventType<Event::JoystickConnectEvent&> JoystickDisconnected;
					EventType<Event::JoystickMoveEvent&> JoystickMoved;
					EventType<Event::KeyEvent&> KeyPressed;
					EventType<Event::KeyEvent&> KeyReleased;
					EventType<Event::MouseButtonEvent&> MouseButtonPressed;
					EventType<Event::MouseButtonEvent&> MouseButtonReleased;
					EventType<Event::MouseMoveEvent&> MouseMoved;
					EventType<Event::MouseWheelEvent&> MouseWheelMoved;
					EventType<Event::MouseWheelScrollEvent&> MouseWheelScrolled;
					EventType<Event::SensorEvent&> SensorChanged;
					EventType<Event::SizeEvent&> Resized;
					EventType<Event::TextEvent&> TextEntered;
					EventType<Event::TouchEvent&> TouchBegan;
					EventType<Event::TouchEvent&> TouchMoved;
					EventType<Event::TouchEvent&> TouchEnded;
					EventType<int> Closed;
				} internalEvents;

			public:
				EventManager(RenderWindow& renderWindow, BaseLogger& logger);
				~EventManager();

				struct Events
				{
					Events(BaseLogger& logger, events& evs)
						:
						JoyStickButtonPressed(logger, evs.JoyStickButtonPressed),
						JoyStickButtonReleased(logger, evs.JoyStickButtonReleased),
						JoyStickConnected(logger, evs.JoyStickConnected),
						JoystickDisconnected(logger, evs.JoystickDisconnected),
						JoystickMoved(logger, evs.JoystickMoved),
						KeyPressed(logger, evs.KeyPressed),
						KeyReleased(logger, evs.KeyReleased),
						MouseButtonPressed(logger, evs.MouseButtonPressed),
						MouseButtonReleased(logger, evs.MouseButtonReleased),
						MouseMoved(logger, evs.MouseMoved),
						MouseWheelMoved(logger, evs.MouseWheelMoved),
						MouseWheelScrolled(logger, evs.MouseWheelScrolled),
						SensorChanged(logger, evs.SensorChanged),
						Resized(logger, evs.Resized),
						TextEntered(logger, evs.TextEntered),
						TouchBegan(logger, evs.TouchBegan),
						TouchMoved(logger, evs.TouchMoved),
						TouchEnded(logger, evs.TouchEnded),
						Closed(logger, evs.Closed)
					{}
					EventRegister<Event::JoystickButtonEvent&> JoyStickButtonPressed;
					EventRegister<Event::JoystickButtonEvent&> JoyStickButtonReleased;
					EventRegister<Event::JoystickConnectEvent&> JoyStickConnected;
					EventRegister<Event::JoystickConnectEvent&> JoystickDisconnected;
					EventRegister<Event::JoystickMoveEvent&> JoystickMoved;
					EventRegister<Event::KeyEvent&> KeyPressed;
					EventRegister<Event::KeyEvent&> KeyReleased;
					EventRegister<Event::MouseButtonEvent&> MouseButtonPressed;
					EventRegister<Event::MouseButtonEvent&> MouseButtonReleased;
					EventRegister<Event::MouseMoveEvent&> MouseMoved;
					EventRegister<Event::MouseWheelEvent&> MouseWheelMoved;
					EventRegister<Event::MouseWheelScrollEvent&> MouseWheelScrolled;
					EventRegister<Event::SensorEvent&> SensorChanged;
					EventRegister<Event::SizeEvent&> Resized;
					EventRegister<Event::TextEvent&> TextEntered;
					EventRegister<Event::TouchEvent&> TouchBegan;
					EventRegister<Event::TouchEvent&> TouchMoved;
					EventRegister<Event::TouchEvent&> TouchEnded;
					EventRegister<int> Closed;
				} Events;

				void Run();
				void Stop();

				bool IsRunning();

			private:
				void handle();
			};
		}

	}

}