#include "Driver.hpp"

int main(int ac, char **av)
{
	if (ac <= 1)
		return 1;
	Driver pilote;
	pilote._init(av[1]);
	pilote.shell();
}