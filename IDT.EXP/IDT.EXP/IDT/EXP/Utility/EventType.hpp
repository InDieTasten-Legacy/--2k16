#pragma once

#include "BaseLogger.hpp"
#include "IEventRegister.hpp"
#include <functional>
#include <list>

using namespace std;

namespace IDT
{
	namespace EXP
	{
		namespace Utility
		{
			template <typename EventParameter>
			class EventType : public IEventRegister<EventParameter>
			{
			private:
				BaseLogger& logger;
				list<function<void(EventParameter)> > listeners;
			public:
				EventType(BaseLogger& logger) : logger(logger)
				{
					logger.Info("EventType has been constructed: " + Conversion::ToString(this));
				}
				~EventType()
				{
					logger.Info("EventType has been destructed:  " + Conversion::ToString(this));
				}

				//Subscribe to event
				virtual typename list< function<void(EventParameter)> >::iterator operator+=(function<void(EventParameter)> listener)
				{
					listeners.push_back(listener);
					return --listeners.end();
				}
				//Unsubscribe to event
				virtual void operator-=(typename list< function<void(EventParameter)> >::iterator position)
				{
					listeners.erase(position);
				}
				void Raise(EventParameter event)
				{
					logger.Info("Event has been raised: " + Conversion::ToString(this));
					for (auto it : listeners)
					{
						it(event);
					}
				}
			};
		}
	}
}