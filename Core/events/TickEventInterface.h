#ifndef __ENGINE__SDL_CORE_TICK_TIME_EVENT__
#define __ENGINE__SDL_CORE_TICK_TIME_EVENT__

	class Actor;

	class TickTimeEventInterface {
	
	public:
		TickTimeEventInterface();
		~TickTimeEventInterface();

		virtual void excecute(Actor*, unsigned int);
	};

#endif