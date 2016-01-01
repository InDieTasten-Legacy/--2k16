#pragma once

#include "../Level/Universe.hpp"
#include "SFML\Graphics.hpp"

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
				Universe& currentUniverse;
				RenderWindow& renderWindow;
			private:
			public:
				GameEngine();
				~GameEngine();
			};
		}
	}
}
