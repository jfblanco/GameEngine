#ifndef __ENGINE__GUI_EVENT_
#define __ENGINE__GUI_EVENT_

	struct GUIMouseEvent {
		unsigned int button;
		unsigned int clicks;
		unsigned int x, y;
	};

	struct GUIEvent {
		unsigned int type;
		unsigned int keyCode;
		unsigned int mouseButtonClick;
		GUIMouseEvent button;
	};

#endif