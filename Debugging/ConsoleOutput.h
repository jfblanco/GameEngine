#ifndef __ENGINE__DEBUGGING_CONSOLEOUTPUT_
#define __ENGINE__DEBUGGING_CONSOLEOUTPUT_

	class ShortString;
	class String;
	class LongString;

	class ConsoleOutput {
		private:
			static ConsoleOutput* instance;

			ConsoleOutput();
		public:
			static ConsoleOutput* getInstance();

			~ConsoleOutput();

			void success(const char*);
			void success(ShortString*);
			void success(String*);
			void success(LongString*);
			
			void info(const char*);
			void info(ShortString*);
			void info(String*);
			void info(LongString*);

			void warning(const char*);
			void warning(ShortString*);
			void warning(String*);
			void warning(LongString*);

			void error(const char*);
			void error(ShortString*);
			void error(String*);
			void error(LongString*);
			
			void fatal(const char*);
			void fatal(ShortString*);
			void fatal(String*);
			void fatal(LongString*);
		};

#endif