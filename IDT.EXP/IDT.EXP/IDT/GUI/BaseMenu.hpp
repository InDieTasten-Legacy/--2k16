#pragma once

#include <SFML\Graphics.hpp>
#include "Canvas.hpp"


using namespace sf;

namespace IDT
{
	namespace GUI
	{
		class BaseMenu : public Drawable
		{
		protected:
			Canvas controls;
		public:
			virtual void Show();
			virtual void Hide();
		};
	}
}
