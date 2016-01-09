#pragma once

#include "BaseLogger.hpp"
#include <functional>
#include <list>

using namespace std;

namespace IDT
{
	namespace EXP
	{
		namespace Utility
		{
			template <typename EventType>
			class EventHandler
			{
			private:
				BaseLogger& logger;
				list<function<void(EventType)> > listeners;
			public:
				EventHandler(BaseLogger& logger) : logger(logger)
				{
					logger.Info("EventHandler has been constructed: " + Conversion::ToString(this));
				}
				~EventHandler()
				{
					logger.Info("EventHandler has been desctructed:  " + Conversion::ToString(this));
				}

				//Subscribe to event
				typename list< function<void(EventType)> >::iterator operator+=(function<void(EventType)> listener)
				{
					listeners.push_back(listener);
					return --listeners.end();
				}
				//Unsubscribe to event
				void operator-=(typename list< function<void(EventType)> >::iterator position)
				{
					listeners.erase(position);
				}
				void Raise(EventType event)
				{
					for (auto it : listeners)
					{
						it(event);
					}
				}
			};
		}
	}
}