#pragma once

#include "BaseLogger.hpp"
#include <iostream>
#include <SFML\System.hpp>

using namespace sf;

namespace IDT
{
	namespace EXP
	{
		namespace Utility
		{
			class StandardLogger : public BaseLogger
			{
			private:
				Mutex mtxLog;
				ThreadLocalPtr<short> thisThread;
			public:
				StandardLogger();
				~StandardLogger();
			protected:
				virtual void log(string message);
			};
		}
	}
}
