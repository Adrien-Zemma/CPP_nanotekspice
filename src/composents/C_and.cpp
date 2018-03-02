/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "C_and.hpp"

C_and::C_and()
{
	this->_type = nts::CHIPSETS;
	this->_pinMax = 13;
}

void	C_and::_and(size_t index, size_t index2, size_t out)
{
	
	if (*this->_pin_status[index].get() == nts::TRUE && 
		*this->_pin_status[index2].get() == nts::TRUE)
		*this->_pin_status[out] = nts::TRUE;
	else if (*this->_pin_status[index].get() == nts::FALSE && 
		*this->_pin_status[index2].get() == nts::TRUE ||
		*this->_pin_status[index].get() == nts::TRUE && 
		*this->_pin_status[index2].get() == nts::FALSE ||
		*this->_pin_status[index].get() == nts::FALSE && 
		*this->_pin_status[index2].get() == nts::FALSE)
		*this->_pin_status[out].get() = nts::FALSE;
	else 
		*this->_pin_status[out].get() = nts::UNDEFINED;
}

nts::Tristate C_and::calculate(const std::size_t &index) noexcept
{
	switch (index)
	{
		case 3:
			_and(1, 2, 3);
		break;
		case 6:
			_and(4, 5, 6);
		break;
		case 10:
			_and(9, 8, 10);
		break;
		case 13:
			_and(11, 12, 13);
		break;
	}
	return *this->_pin_status[index];
}
