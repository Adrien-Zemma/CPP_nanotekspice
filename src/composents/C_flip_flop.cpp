/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "C_flip_flop.hpp"

C_flip_flop::C_flip_flop(nts::Tristate cloc)
{
	this->_type = CHIPSETS;
	this->_clock = cloc;
}

nts::Tristate C_flip_flop::calculate(size_t index)
{
	/*
	faire un tableau de pointer sur fonction pour choisire quelle fonctin en fonction de quelle output
	*/
	index = index;
	return nts::UNDEFINED;
}