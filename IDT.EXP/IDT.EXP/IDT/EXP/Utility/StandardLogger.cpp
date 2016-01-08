#include "StandardLogger.hpp"

IDT::EXP::Utility::StandardLogger::StandardLogger() : BaseLogger()
{
	this->Info("StandardLogger has been constructed: " + Conversion::ToString(this));
}

IDT::EXP::Utility::StandardLogger::~StandardLogger()
{
	this->Info("StandardLogger has been destructed: " + Conversion::ToString(this));
}

void IDT::EXP::Utility::StandardLogger::log(string message)
{
	Lock lock(mtxLog);

	static short threadCount = 0;

	if (!thisThread)
	{
		thisThread = new short(threadCount++);
	}

	std::cout << "<" << *thisThread << ">" << message << std::endl;
}
