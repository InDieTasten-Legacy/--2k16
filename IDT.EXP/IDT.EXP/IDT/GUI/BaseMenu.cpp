#include "BaseMenu.hpp"

IDT::GUI::BaseMenu::BaseMenu(BaseLogger & logger)
	:
	logger(logger)
{
	logger.Info("BaseMenu has been constructed: " + Conversion::ToString(this));
}

IDT::GUI::BaseMenu::~BaseMenu()
{
	logger.Info("BaseMenu has been destructed:  " + Conversion::ToString(this));
}

void IDT::GUI::BaseMenu::Show(bool focused)
{
	this->focused = focused;
}

void IDT::GUI::BaseMenu::Hide()
{

	this->focused = false;
}

void IDT::GUI::BaseMenu::draw(RenderTarget & target, RenderStates states) const
{
	//draw body

	//draw controls
	target.draw(controls, states);

	//draw titlebar

	//draw closebutton

}
