/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "C_xor.hpp"

C_xor::C_xor()
{
	this->_type = nts::CHIPSETS;
}

void	C_xor::_xor(size_t index, size_t index2, size_t out)
{
	if (*_pin_status[index].get() == nts::TRUE && *_pin_status[index2].get() == nts::FALSE ||
		*_pin_status[index].get() == nts::FALSE && *_pin_status[index2].get() == nts::TRUE)
		*_pin_status[out].get() = nts::TRUE;
	else if (*_pin_status[index].get() == nts::UNDEFINED || *_pin_status[index2].get() == nts::UNDEFINED)
		*_pin_status[out].get() == nts::UNDEFINED;
	else 
		*_pin_status[out].get() = nts::FALSE;
}

nts::Tristate C_xor::calculate(size_t index)
{
	switch (index)
	{
		case 11:
			_xor(13, 12, 11);
		break;
		case 10:
			_xor(9, 8, 10);
		break;
		case 3:
			_xor(1, 2, 3);
		break;
		case 4:
			_xor(5, 6, 4);
		break;
	}
	return *this->_pin_status[index];
}