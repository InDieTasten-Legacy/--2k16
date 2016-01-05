#include "GameEngine.hpp"

IDT::EXP::Processing::GameEngine::GameEngine(BaseLogger & logger)
	:
	logger(logger),
	currentUniverse(logger),
	renderer(logger),
	renderWindow(sf::VideoMode(1280, 720), "SFML works!")
{
	logger.Info("GameEngine has been constructed: " + Conversion::ToString(this));
}

IDT::EXP::Processing::GameEngine::~GameEngine()
{
	logger.Info("GameEngine has been destructed:  " + Conversion::ToString(this));
}

void IDT::EXP::Processing::GameEngine::Init()
{
	logger.Info("GameEngine initiates");
	renderer.Launch();
	sleep(seconds(10));
	renderer.Terminate();

}
