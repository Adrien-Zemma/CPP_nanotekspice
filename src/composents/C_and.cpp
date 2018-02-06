/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "C_and.hpp"

C_and::C_and(){}

nts::Tristate C_and::compute(std::size_t pin)
{
	return nts::UNDEFINED;
}

void C_and::_and(int index, int index2, int output)
{
	if (this->getPin_value(index) == nts::TRUE &&
		this->getPin_value(index2) == nts::TRUE)
		this->setPin_value(output, nts::TRUE);
	else 
		this->setPin_value(output, nts::FALSE);
}

void C_and::calculate()
{
	this->_and(2, 3, 1);
	this->_and(5, 6, 4);
	this->_and(9, 8, 10);
	this->_and(13, 12, 11);
}