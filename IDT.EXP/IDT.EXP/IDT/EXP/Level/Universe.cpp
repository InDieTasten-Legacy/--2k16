#include "Universe.hpp"

IDT::EXP::Level::Universe::Universe(BaseLogger & logger)
	:
	logger(logger)
{
	logger.Info("Universe has been constructed: " + Conversion::ToString(this));
}

IDT::EXP::Level::Universe::~Universe()
{
	logger.Info("Universe has been destructed:  " + Conversion::ToString(this));
}
