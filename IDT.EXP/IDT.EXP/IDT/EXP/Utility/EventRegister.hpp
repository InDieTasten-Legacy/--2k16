#pragma once

#include "BaseLogger.hpp"
#include "EventType.hpp"

namespace IDT
{
	namespace EXP
	{
		namespace Utility
		{
			template <typename EventParameter>
			class EventRegister : public IEventRegister<EventParameter>
			{
			private:
				BaseLogger& logger;
				EventType<EventParameter>& eventType;
			public:
				EventRegister(BaseLogger& logger, EventType<EventParameter>& eventType)
					:
					logger(logger),
					eventType(eventType)
				{
					logger.Info("EventRegister has been constructed: " + Conversion::ToString(this));
				}
				~EventRegister()
				{
					logger.Info("EventRegister has been destructed:  " + Conversion::ToString(this));
				}

				//Subscribe to event
				virtual typename list< function<void(EventParameter)> >::iterator operator+=(function<void(EventParameter)> listener)
				{
					logger.Info("Routing event subscription: " + Conversion::ToString(this) + " : " + Conversion::ToString(&listener) + " ---> " + Conversion::ToString(&eventType));
					return eventType += listener;
				}
				//Unsubscribe to event
				virtual void operator-=(typename list< function<void(EventParameter)> >::iterator position)
				{
					logger.Info("Routing event unsubscription: " + Conversion::ToString(this) + " : X " + Conversion::ToString(&eventType));
					return eventType -= position;
				}
			};
		}
	}
}