/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "C_invert.hpp"

C_invert::C_invert()
{
	this->_type = nts::CHIPSETS;
}
void	C_invert::_invert(size_t index, int out)
{
	if (*this->_pin_status[index + out].get() == nts::TRUE)
		*this->_pin_status[index].get() = nts::FALSE;
	else if (*this->_pin_status[index + out].get() == nts::FALSE)
		*this->_pin_status[index].get() = nts::TRUE;
}

nts::Tristate C_invert::calculate(size_t idx)
{
	if (idx == 2 || idx == 4 || idx == 6)
		_invert(idx, -1);
	else if (idx == 12 || idx == 10 || idx == 8)
		_invert(idx, 1);
	return *this->_pin_status[idx].get();
}