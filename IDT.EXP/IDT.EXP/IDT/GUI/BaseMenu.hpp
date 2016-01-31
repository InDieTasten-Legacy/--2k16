#pragma once

#include <SFML\Graphics.hpp>
#include "Canvas.hpp"
#include "../EXP/Utility/BaseLogger.hpp"

using namespace IDT::EXP::Utility;


using namespace sf;

namespace IDT
{
	namespace GUI
	{
		class BaseMenu : public Drawable
		{
		private:
			int top;
			int left;
			int height;
			int width;
			BaseLogger& logger;
			char* x;
			bool focused;

		protected:
			Canvas controls;
		public:
			BaseMenu(BaseLogger& logger);
			~BaseMenu();
			virtual void Show(bool focused = true);
			virtual void Hide();

			virtual void draw(RenderTarget& target, RenderStates states) const;
		};
	}
}
