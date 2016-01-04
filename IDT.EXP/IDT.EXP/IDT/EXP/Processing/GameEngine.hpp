#pragma once

#include "../Level/Universe.hpp"
#include "SFML\Graphics.hpp"
#include "../Utility/BaseLogger.hpp"

using namespace IDT::EXP::Utility;
using namespace IDT::EXP::Level;
using namespace sf;

namespace IDT
{
	namespace EXP
	{
		namespace Processing
		{
			class GameEngine
			{
			private:
				BaseLogger& logger;
				Universe currentUniverse;
				RenderWindow renderWindow;
			public:
				GameEngine(BaseLogger& logger);
				~GameEngine();
			};
		}
	}
}
