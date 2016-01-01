#pragma once

#include <string>
#include "Conversion.hpp"

using namespace std;

namespace IDT
{
	namespace EXP
	{
		namespace Utility
		{
			class BaseLogger
			{
			public:
				BaseLogger();
				virtual ~BaseLogger();

				void Info(string message);
				void Debug(string message);
				void Warning(string message);
				void Error(string message);
				void Fatal(string message);

			protected:
				virtual void log(string message) = 0;
			};
		}
	}

}