#pragma once

#include "../Utility/BaseLogger.hpp"
#include <SFML\System.hpp>

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
				BaseLogger& logger;
				bool running = false;
				Mutex mtxRunning;
			public:
				EventManager(BaseLogger& logger);
				~EventManager();

				void Run();
				void Stop();

				bool IsRunning();

			private:
				void handle();
			};
		}

	}

}