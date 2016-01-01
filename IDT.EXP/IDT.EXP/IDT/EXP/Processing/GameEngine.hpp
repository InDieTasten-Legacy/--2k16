#pragma once

namespace IDT
{
	namespace EXP
	{
		namespace Processing
		{
			class GameEngine
			{
				Universe& currentUniverse;
				RenderWindow& renderWindow;
			private:
			public:
				GameEngine();
				~GameEngine();
			};
		}
	}
}
