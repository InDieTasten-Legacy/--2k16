#pragma once

#include "../Utility/EventRegister.hpp"
#include "../Utility/EventType.hpp"
#include "../Utility/BaseLogger.hpp"
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"

using namespace IDT::EXP::Utility;
using namespace sf;

namespace IDT
{
	namespace EXP
	{
		namespace Processing
		{
			class Renderer
			{
			private:
				BaseLogger& logger;
				Thread renderThread;
				bool running = false;
				RenderWindow& target;


				Mutex threadManagement;
			public:
				struct DrawEvent
				{
					DrawEvent(RenderTarget& target)
						:
						target(target)
					{}
					RenderTarget& target;
					RenderStates states;
				};
			private:
				struct events
				{
					events(BaseLogger& logger)
						:
						OnRenderFrame(logger)
					{}
					EventType<DrawEvent&> OnRenderFrame;
				} internalEvents;
			public:
				struct Events
				{
					Events(BaseLogger& logger, events& evs)
						:
						OnRenderFrame(logger, evs.OnRenderFrame)
					{}
					EventRegister<DrawEvent&> OnRenderFrame;
				} Events;
				Renderer(BaseLogger& logger, RenderWindow& target);
				~Renderer();

				void Launch();
				void Terminate();

			private:
				void render();

			};
		}
	}
}