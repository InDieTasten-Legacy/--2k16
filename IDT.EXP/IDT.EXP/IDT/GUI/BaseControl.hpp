#pragma once

#include <SFML\Graphics.hpp>

using namespace sf;

namespace IDT
{
	namespace GUI
	{
		class BaseControl : public Drawable
		{
		private:
			int top;
			int left;
			int height;
			int width;
			bool isVisible;
		public:
			virtual void draw(RenderTarget& target, RenderStates states) const;
		};
	}
}
