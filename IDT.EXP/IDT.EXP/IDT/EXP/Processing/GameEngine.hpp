#pragma once

#include "../Level/Universe.hpp"
#include "Renderer.hpp"
#include "EventManager.hpp"
#include "SFML\Graphics.hpp"
#include "../Utility/BaseLogger.hpp"
#include "../../GUI/GuiManager.hpp"

using namespace IDT::EXP::Utility;
using namespace IDT::EXP::Level;
using namespace IDT::GUI;
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
				Renderer renderer;
				EventManager eventManager;
				GuiManager guiManager;
			public:
				GameEngine(BaseLogger& logger);
				~GameEngine();

				void Init();
			};
		}
	}
}
