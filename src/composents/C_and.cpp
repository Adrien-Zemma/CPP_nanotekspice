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
	this->_pinMax = 14;
}

void	C_and::_and(size_t index, size_t index2, size_t out)
{
	if (*this->_pin_status[index].get() == nts::TRUE && 
		*this->_pin_status[index2].get() == nts::TRUE)
		*this->_pin_status[out] = nts::TRUE;
	else if (*this->_pin_status[index].get() == nts::FALSE ||
		*this->_pin_status[index2].get() == nts::FALSE)
		*this->_pin_status[out].get() = nts::FALSE;
}

nts::Tristate C_and::calculate(const std::size_t &index) noexcept
{
	switch (index)
	{
		case 3:
			_and(1, 2, 3);
		break;
		case 4:
			_and(6, 5, 4);
		break;
		case 10:
			_and(9, 8, 10);
		break;
		case 11:
			_and(13, 12, 11);
		break;
	}
	return *this->_pin_status[index];
}
