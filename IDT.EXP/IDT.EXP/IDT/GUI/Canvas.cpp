#include "Canvas.hpp"

void IDT::GUI::Canvas::draw(RenderTarget & target, RenderStates states) const
{
	states.transform.translate(sf::Vector2f((float)x, (float)y));
	for (auto it : controls)
	{
		target.draw(it, states);
	}
}
