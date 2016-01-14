#pragma once

#include <list>
#include <functional>

namespace IDT
{
	namespace EXP
	{
		namespace Utility
		{
			template <typename EventParameter>
			class IEventRegister
			{
			public:
				//Subscribe to event
				virtual typename list< function<void(EventParameter)> >::iterator operator+=(function<void(EventParameter)> listener) = 0;
				//Unsubscribe to event
				virtual void operator-=(typename list< function<void(EventParameter)> >::iterator position) = 0;
			};
		}
	}
}