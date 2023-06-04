#include "iostream"

int main(int argc, char **argv) {
	if (argc > 1)
		for (int i = 1; i < argc; i++) {
			int j = -1;
			while (argv[i][++j])
				std::cout << (char) toupper(argv[i][j]);
		}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}