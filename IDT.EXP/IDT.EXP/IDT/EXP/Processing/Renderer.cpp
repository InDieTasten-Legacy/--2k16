#include "Renderer.hpp"

IDT::EXP::Processing::Renderer::Renderer(BaseLogger & logger, RenderWindow& target)
	:
	logger(logger),
	renderThread(&IDT::EXP::Processing::Renderer::render, this),
	target(target),
	internalEvents(logger),
	Events(logger, internalEvents)
{
	target.setActive(true);
	logger.Info("Renderer has been constructed: " + Conversion::ToString(this));
}

IDT::EXP::Processing::Renderer::~Renderer()
{
	logger.Info("Renderer has been destructed:  " + Conversion::ToString(this));
}

void IDT::EXP::Processing::Renderer::Launch()
{
	Lock lock(threadManagement);
	if (running)
	{
		logger.Warning("Tried launching already running Renderer");
		return;
	}
	logger.Info("Renderer will be launched");
	running = true;
	renderThread.launch();
}

void IDT::EXP::Processing::Renderer::Terminate()
{
	Lock lock(threadManagement);
	if (!running)
	{
		logger.Warning("Tried terminating already stopped Renderer");
		return;
	}
	running = false;
	renderThread.wait();
	logger.Info("Renderer has been terminated");
}

void IDT::EXP::Processing::Renderer::render()
{
	logger.Info("Rendering thread has been launched");

	DrawEvent drawEvent(target);
	

	while (running)
	{
		drawEvent.states = RenderStates();
		internalEvents.OnRenderFrame.Raise(drawEvent);
		target.clear(Color::Black);
	}

	logger.Info("Rendering thread will be terminated");
}
