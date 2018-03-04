/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "C_nand.hpp"

C_nand::C_nand()
{
	this->_pinMax = 14;
	this->_type = nts::CHIPSETS;
}

void C_nand::_nand(size_t index, size_t index2, size_t out)
{
	if (*this->_pin_status[index].get() == nts::TRUE && 
		*this->_pin_status[index2].get() == nts::TRUE)
		*this->_pin_status[out] = nts::FALSE;
	else if (*this->_pin_status[index].get() == nts::FALSE && 
		*this->_pin_status[index2].get() == nts::TRUE ||
		*this->_pin_status[index].get() == nts::TRUE && 
		*this->_pin_status[index2].get() == nts::FALSE ||
		*this->_pin_status[index].get() == nts::FALSE && 
		*this->_pin_status[index2].get() == nts::FALSE)
		*this->_pin_status[out].get() = nts::TRUE;
}

nts::Tristate C_nand::calculate(const size_t &index) noexcept
{
	switch (index)
	{
		case 3:
			_nand(1, 2, 3);
		break;
		case 4:
			_nand(6, 5, 4);
		break;
		case 10:
			_nand(9, 8, 10);
		break;
		case 11:
			_nand(13, 12, 11);
		break;
	}
	return *this->_pin_status[index];
}