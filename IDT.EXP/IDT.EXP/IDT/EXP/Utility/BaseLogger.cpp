#include "BaseLogger.hpp"

IDT::EXP::Utility::BaseLogger::BaseLogger()
{
}

IDT::EXP::Utility::BaseLogger::~BaseLogger()
{
}

void IDT::EXP::Utility::BaseLogger::Info(string message)
{
	this->log("[Information]" + message);
}

void IDT::EXP::Utility::BaseLogger::Debug(string message)
{
	this->log("[DEBUG]" + message);
}

void IDT::EXP::Utility::BaseLogger::Warning(string message)
{
	this->log("[Warning]" + message);
}

void IDT::EXP::Utility::BaseLogger::Error(string message)
{
	this->log("[Error]" + message);
}

void IDT::EXP::Utility::BaseLogger::Fatal(string message)
{
	this->log("[FATAL]" + message);
}
