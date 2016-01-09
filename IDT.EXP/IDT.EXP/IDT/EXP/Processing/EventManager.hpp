#pragma once

#include "../Utility/BaseLogger.hpp"
#include "../Utility/EventHandler.hpp"
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>
#include <functional>
#include <list>

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

			public:
				EventManager(RenderWindow& renderWindow, BaseLogger& logger);
				~EventManager();

				struct events {
					events(BaseLogger& logger)
						:
						KeyPressed(logger),
						KeyReleased(logger),
						Closed(logger) {}
					EventHandler<Event::KeyEvent&> KeyPressed;
					EventHandler<Event::KeyEvent&> KeyReleased;
					EventHandler<int> Closed;
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