#include "parse.hpp"
#include "Driver.hpp"
#include "IComponent.hpp"

int main(int ac, char **av)
{
	if (ac <= 1)
		return 1;
	Driver pilote;
	Parse file(av[1]);

	if (file.read() == 84)
		return (84);
	return (0);
}