/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "C_and.hpp"

C_and::C_and(){}

nts::Tristate C_and::calculate(std::size_t index)
{
	switch (index)
	{
		case 3:
			if (*this->_pin_status[1] == nts::TRUE && *this->_pin_status[2] == nts::TRUE)
				*this->_pin_status[index] = nts::TRUE;
		break;
		case 6:
			if (*this->_pin_status[1] == nts::TRUE && *this->_pin_status[2] == nts::TRUE)
				*this->_pin_status[index] = nts::TRUE;
		break;
		case 10:
			if (*this->_pin_status[1] == nts::TRUE && *this->_pin_status[2] == nts::TRUE)
				*this->_pin_status[index] = nts::TRUE;
		break;
		case 13:
			if (*this->_pin_status[1] == nts::TRUE && *this->_pin_status[2] == nts::TRUE)
				*this->_pin_status[index] = nts::TRUE;
		break;
	}
	return *this->_pin_status[index];
}
