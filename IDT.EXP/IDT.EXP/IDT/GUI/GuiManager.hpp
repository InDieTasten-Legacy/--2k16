#pragma once

#include "../EXP/Utility/BaseLogger.hpp"
#include <SFML\Graphics.hpp>
#include "BaseMenu.hpp"
#include <list>

using namespace IDT::EXP::Utility;
using namespace sf;

namespace IDT
{
	namespace GUI
	{
		class GuiManager : public Drawable
		{
		private:
			BaseLogger& logger;
			list<BaseMenu> menus;
		public:
			GuiManager(BaseLogger& logger);
			~GuiManager();

			virtual void draw(RenderTarget& target, RenderStates states) const;
		};
	}
}