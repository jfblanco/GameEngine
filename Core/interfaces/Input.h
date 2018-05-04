#ifndef __ENGINE__INPUT_INTERFACE_
#define __ENGINE__INPUT_INTERFACE_

	class ShutDownInputCommand {
		public:
			virtual void shutDownEvent()=0;
	};

	class KeyBoardInputCommand {
		public:
			virtual void keyDown(unsigned int)=0;
			virtual void keyUp(unsigned int)=0;
	};

	class MouseInputCommand {
		public:
			virtual void leftClick()=0;
			virtual void leftUp()=0;
			virtual void rightUp()=0;
			virtual void rightClick()=0;
			virtual void middleClick()=0;
			virtual void mouseMove(unsigned int, unsigned int)=0;
			virtual void wheelMove(unsigned int)=0;
	};

	class JoyStickInputCommand {
		public:
			virtual void shutDownEvent()=0;
	};

	class ControllerInputCommand {
		public:
			virtual void shutDownEvent()=0;
	};

	class ShutDownInputNullCommand : public ShutDownInputCommand {
		public:
			virtual void shutDownEvent();
	};

	class KeyBoardInputNullCommand : public KeyBoardInputCommand {
		public:
			virtual void keyDown(unsigned int);
			virtual void keyUp(unsigned int);
	};

	class MouseInputNullCommand : public MouseInputCommand {
		public:
			virtual void leftClick();
			virtual void rightClick();
			virtual void leftUp();
			virtual void rightUp();
			virtual void middleClick();
			virtual void mouseMove(unsigned int, unsigned int);
			virtual void wheelMove(unsigned int);
	};

	class Input {
	
	public:
		Input();
		~Input();

		virtual void init();
		virtual void addShutDownFunction(int, ShutDownInputCommand*);
		virtual void addKeyBoardFunction(int, KeyBoardInputCommand*);
		virtual void addMouseFunction(int, MouseInputCommand*);
		virtual void addJoyStickFunction(int, JoyStickInputCommand*);
		virtual void addControllerFunction(int, ControllerInputCommand*);
		virtual void checkInput();
	};

#endif