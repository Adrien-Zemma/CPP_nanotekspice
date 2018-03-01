/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "C_flip_flop.hpp"

C_flip_flop::C_flip_flop(nts::Tristate cloc)
{
	this->_type = nts::CHIPSETS;
	this->_clock = cloc;
}

void	C_flip_flop::_flip_flop(std::vector<int> set)
{
}

nts::Tristate C_flip_flop::calculate(size_t index)
{
	return nts::UNDEFINED;
}