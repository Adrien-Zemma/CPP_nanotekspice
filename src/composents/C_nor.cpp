/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "C_nor.hpp"

C_nor::C_nor(){}

void C_nor::calculate()
{
	_nor(1, 2, 3);
	_nor(5, 6, 4);
	_nor(8, 9, 10);
	_nor(12, 13, 11);
}

nts::Tristate C_nor::compute(std::size_t pin)
{
	calculate();
	return this->_pin_status[pin];
}

void C_nor::setLink (std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
}

void C_nor::dump() const 
{
	std::cout << "dump" << std::endl;
}

void C_nor::_nor(int index1, int index2, int index3)
{
	if (this->_pin_status[index1] == nts::TRUE && this->_pin_status[index2] == nts::TRUE)
		this->_pin_status[index3] = nts::TRUE;
	else 
		this->_pin_status[index3] = nts::FALSE;
}