/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "C_invert.hpp"

C_invert::C_invert()
{
	this->_type = CHIPSETS;
}
void	C_invert::_invert(size_t index, size_t out)
{
	if (index % 2 == 0)
		index++;
	if (index % 2 == 1)
		index--;
	if (*_pin_status[index].get() == nts::TRUE)
		*_pin_status[out].get() = nts::FALSE;
	else if (*_pin_status[index].get() == nts::FALSE)
		*_pin_status[out].get() = nts::TRUE;
	else if (*_pin_status[index].get() == nts::UNDEFINED)
		*_pin_status[out].get() = nts::UNDEFINED;
}

nts::Tristate C_invert::calculate(size_t index)
{
	for (size_t i = 1; i <= _pinMax; i++)
		if (index == i)
			_invert(i, index);
	return *this->_pin_status[index];
}