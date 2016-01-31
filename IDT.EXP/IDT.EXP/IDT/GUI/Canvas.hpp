#pragma once

#include <SFML\Graphics.hpp>
#include "BaseControl.hpp"
#include <list>

using namespace sf;
using namespace std;

namespace IDT
{
	namespace GUI
	{
		class Canvas : public Drawable
		{
			list<BaseControl> controls;
			int x = 0;
			int y = 0;
			int width = 0;
			int height = 0;
		protected:
			virtual void draw(RenderTarget& target, RenderStates states) const;
		};
	}
}
