#ifndef __ENGINE__INPUT_INTERFACE_
#define __ENGINE__INPUT_INTERFACE_

	class InputFunction {
		public:
			virtual void excecute();
	};

	class Input {
	
	public:
		Input();
		~Input();

		virtual void init();
		virtual void addFunction(int, InputFunction*);
		virtual void checkInput();
	};

#endif