#ifndef __RENDER_EXAMPLE_TICK_EVENT_
#define __RENDER_EXAMPLE_TICK_EVENT_

	#include "../../../Core/events/TickEventInterface.h"
	#include "../../../Core/utils/Matrix4x4.h"

	class TickEvent : public TickTimeEventInterface {

	private:
		float pitch, roll, yaw;
		Matrix4x4 rotation;	
		Matrix4x4 position;	
	
	public:
		TickEvent();
		~TickEvent();
		void excecute(Mesh*, unsigned int);
	};

#endif