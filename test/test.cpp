/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** nanotekspice
*/

#include "Driver.hpp"

int main(int ac, char **av)
{
	if (ac <= 1)
		return 84;
	Driver pilote(av);
	pilote.parse.dumpChipsets();
	pilote.parse.dumpLinks();
	pilote.shell();
}