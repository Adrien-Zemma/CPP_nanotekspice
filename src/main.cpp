#include "Driver.hpp"

int main(int ac, char **av)
{
	if (ac <= 1)
		return 1;
	Driver pilote;
	pilote.parse.read(av[1]);
	pilote.shell();
}