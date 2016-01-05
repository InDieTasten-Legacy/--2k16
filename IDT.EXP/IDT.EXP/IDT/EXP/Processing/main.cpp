#include <SFML/Graphics.hpp>
#include <iostream>

#include "../Utility/Conversion.hpp"
#include "../Utility/StandardLogger.hpp"
#include "GameEngine.hpp"

using namespace IDT::EXP::Utility;
using namespace IDT::EXP::Processing;

int main()
{
	BaseLogger* logger = new StandardLogger();
	{
		GameEngine engine(*logger);
		engine.Init();
	}
	delete logger;
	logger = nullptr;


	getchar();
	return EXIT_SUCCESS;
}