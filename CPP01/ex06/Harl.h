#ifndef HARL_H
#define HARL_H

#include <iostream>

class Harl {

	enum Level {
		DEFAULT = 0,
		DEBUG = 1,
		INFO = 2,
		WARNING = 3,
		ERROR = 4
	};

private:
	Level minLevel;

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:
	Harl(std::string level);
	void complain(std::string level);
};

#endif
