/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:

** 
*/

#include "C_or.hpp"

C_or::C_or()
{
	this->_pinMax = 14;
	this->_type = nts::CHIPSETS;
}

nts::Tristate C_or::calculate(const size_t &index) noexcept
{
	switch (index)
	{
		case 3:
			_or(1, 2, 3);
		break;
		case 4:
			_or(5, 6, 4);
		break;
		case 10:
			_or(9, 8, 10);
		break;
		case 11:
			_or(12, 13, 11);
		break;
	}
	return *this->_pin_status[index];
}

void C_or::_or(size_t index, size_t index2, size_t out)
{
	if (*_pin_status[index].get() == nts::TRUE || *_pin_status[index2].get() == nts::TRUE)
		*_pin_status[out].get() = nts::TRUE;
	else if (*_pin_status[index].get() == nts::FALSE && *_pin_status[index2].get() == nts::FALSE)
		*_pin_status[out].get() = nts::FALSE;
}