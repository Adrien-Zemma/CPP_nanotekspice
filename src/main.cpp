/*
** EPITECH PROJECT, 2018
** nanotekspice
** File description:
** 
*/

#include "Driver.hpp"

int main(int ac, char **av)
{
	if (ac <= 1)
		return 84;
	Driver pilote(av);
	pilote.shell();
}