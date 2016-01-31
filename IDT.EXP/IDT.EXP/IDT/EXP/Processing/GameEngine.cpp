#include "GameEngine.hpp"

IDT::EXP::Processing::GameEngine::GameEngine(BaseLogger & logger)
	:
	logger(logger),
	currentUniverse(logger),
	eventManager(renderWindow, logger),
	renderWindow(sf::VideoMode(1280, 720), "SFML works!"),
	renderer(logger, renderWindow),
	guiManager(logger)
{
	renderWindow.setActive(false);
	logger.Info("GameEngine has been constructed: " + Conversion::ToString(this));
}

IDT::EXP::Processing::GameEngine::~GameEngine()
{
	logger.Info("GameEngine has been destructed:  " + Conversion::ToString(this));
}

void IDT::EXP::Processing::GameEngine::Init()
{
	logger.Info("GameEngine initiates");

	logger.Info("Hooking quit event");

	eventManager.Events.Closed += [this](int) -> void { eventManager.Stop(); };

	renderer.Events.OnRenderFrame += [this](Renderer::DrawEvent& drawEvent) -> void { drawEvent.target.draw(this->guiManager, drawEvent.states); };

	renderer.Launch();
	
	eventManager.Run();

	renderer.Terminate();

}
