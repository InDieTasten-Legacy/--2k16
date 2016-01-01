#include "StandardLogger.hpp"
//#include <chrono>
//#include <ctime>

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
	/*using std::chrono::system_clock;
	system_clock::time_point today = system_clock::now();
	std::time_t tt;
	tt = system_clock::to_time_t(today);*/

	std::cout << /*ctime(&tt) << " " +*/ message << std::endl;
}
