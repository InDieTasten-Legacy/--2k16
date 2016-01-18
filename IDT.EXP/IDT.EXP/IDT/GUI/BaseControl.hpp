#pragma once

#include <SFML\Graphics.hpp>

using namespace sf;

namespace IDT
{
	namespace GUI
	{
		class BaseControl : Drawable
		{
		public:
			virtual void Hide();
			virtual void Show();
			virtual void Enable();
			virtual void Disable();
		};
	}
}
