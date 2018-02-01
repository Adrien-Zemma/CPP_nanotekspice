#include "parse.hpp"

int main(int ac, char **av)
{
	if (ac <= 1)
		return 1;
	Parse file(av[1]);

	file.read();
}