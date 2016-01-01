#pragma once

#include <string>
#include <sstream>

using namespace std;

namespace IDT
{
	namespace EXP
	{
		namespace Utility
		{
			class Conversion
			{
			public:
				template<typename T>
				static string ToString(T thingy)
				{
					ostringstream mystream;
					mystream << thingy;
					return mystream.str();
				}
			};
		}
	}
}
