/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "Pin.hpp"

Pin::Pin(){}
Pin::~Pin(){}

std::shared_ptr<nts::Tristate> Pin::getPin_ptr()
{
	return this->_value;
}