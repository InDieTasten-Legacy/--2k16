#pragma once

#include "../Utility/BaseLogger.hpp"

using namespace IDT::EXP::Utility;

namespace IDT
{
	namespace EXP
	{
		namespace Level
		{
			class Universe
			{
			private:
				BaseLogger& logger;
			public:
				Universe(BaseLogger& logger);
				~Universe();
			};
		}
	}
}