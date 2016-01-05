#pragma once

#include "../Utility/BaseLogger.hpp"
#include "SFML\System.hpp"

using namespace IDT::EXP::Utility;
using namespace sf;

namespace IDT
{
	namespace EXP
	{
		namespace Processing
		{
			class Renderer
			{
			private:
				BaseLogger& logger;
				Thread renderThread;
				bool running = false;

				Mutex threadManagement;
			public:
				Renderer(BaseLogger& logger);
				~Renderer();

				void Launch();
				void Terminate();

			private:
				void render();

			};
		}
	}
}