/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "C_and.hpp"

C_and::C_and(){}

void C_and::_and(int index, int index2, int output)
{
	if (this->_pin_status[index] == nts::TRUE &&
		 this->_pin_status[index2] == nts::TRUE)
		this->_pin_status[output] = nts::TRUE;
	else 
		this->_pin_status[output] = nts::FALSE;
}

void C_and::calculate()
{
	this->_and(2, 3, 1);
	this->_and(5, 6, 4);
	this->_and(9, 8, 10);
	this->_and(13, 12, 11);
}