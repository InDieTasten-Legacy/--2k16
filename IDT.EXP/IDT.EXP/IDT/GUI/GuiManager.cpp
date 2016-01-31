#include "GuiManager.hpp"

IDT::GUI::GuiManager::GuiManager(BaseLogger & logger)
	:
	logger(logger)
{
	logger.Info("GuiManager has been constructed: " + Conversion::ToString(this));
}

IDT::GUI::GuiManager::~GuiManager()
{
	logger.Info("GuiManager has been destructed:  " + Conversion::ToString(this));
}

void IDT::GUI::GuiManager::draw(RenderTarget & target, RenderStates states) const
{
	logger.Debug("BANANA WORKS");
	for (auto it : menus)
	{
		target.draw(it, states);
	}
}
