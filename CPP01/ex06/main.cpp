#include "Harl.h"

int main(int argc, char **argv) {

	(void)argc;
	if (argc != 2)
		return (1);
	Harl harl(argv[1]);

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	return 0;
}