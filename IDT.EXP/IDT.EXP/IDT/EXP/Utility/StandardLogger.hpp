#pragma once

#include "BaseLogger.hpp"
#include <iostream>

namespace IDT
{
	namespace EXP
	{
		namespace Utility
		{
			class StandardLogger : public BaseLogger
			{
			public:
				StandardLogger();
				~StandardLogger();
			protected:
				virtual void log(string message);
			};
		}
	}
}