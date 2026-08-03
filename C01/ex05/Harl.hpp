#ifndef HARL_HPP
#define HARL_HPP
#include <string>
#include <iostream>

	class Harl
	{
		public:
			Harl();
			void complain(std::string level);
			~Harl();
			
		private:
			void debug(void);
			void info(void);
			void warning (void);
			void error(void);
			void (Harl::*methods[4])(void);
   			int filter_level;
		
	};


#endif