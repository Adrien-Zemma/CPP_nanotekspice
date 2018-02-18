/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "C_nor.hpp"

C_nor::C_nor()
{
	this->_type = CHIPSETS;
	this->_pinMax = 13;
}

void C_nor::_nor(size_t index, size_t index2, size_t out)
{
	if (*_pin_status[index].get() == nts::FALSE && *_pin_status[index2].get() == nts::FALSE)
		*_pin_status[out].get() = nts::TRUE;
	else if (*_pin_status[index].get() == nts::TRUE && 
		*_pin_status[index2].get() == nts::FALSE ||
		*_pin_status[index].get() == nts::FALSE && 
		*_pin_status[index2].get() == nts::TRUE ||
		*_pin_status[index].get() == nts::TRUE && 
		*_pin_status[index2].get() == nts::TRUE)
		*_pin_status[out].get() = nts::FALSE;
	else 
		*_pin_status[out].get() = nts::UNDEFINED;
}

nts::Tristate	C_nor::calculate(size_t index)
{
	switch (index)
	{
		case 3:
			_nor(1, 2, 3);
		break;
		case 4:
			_nor(5, 6, 4);
		break;
		case 10:
			_nor(8, 9, 10);
		break;
		case 11:
			_nor(12, 13, 11);
		break;
	}
	return *this->_pin_status[index];
}