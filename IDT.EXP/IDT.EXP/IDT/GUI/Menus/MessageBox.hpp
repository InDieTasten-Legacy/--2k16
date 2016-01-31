#pragma once

#include "../BaseMenu.hpp"
#include "../../EXP/Utility/BaseLogger.hpp"

using namespace IDT::EXP::Utility;

namespace IDT
{
	namespace GUI
	{
		namespace Menus
		{
			class MessageBox : public BaseMenu
			{
			private:
				BaseLogger& logger;

				Button yes;
				Button no;

				initializeComponents();
			public:
				MessageBox(BaseLogger& logger);
				~MessageBox();

			protected:
				virtual void draw(RenderTarget& target, RenderStates states) const;
			};
		}
	}
}
