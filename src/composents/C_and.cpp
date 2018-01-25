/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "C_and.hpp"

void C_and::_and(int index, int index2, int output)
{
	if (this->_status_pin[index] == nts::TRUE &&
		 this->_status_pin[index2] == nts::TRUE)
		this->_status_pin[output] = nts::TRUE;
}

void C_and::calculation()
{
	_and(2,3, 1);
}