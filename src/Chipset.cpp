/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "Chipset.hpp"

std::shared_ptr<nts::Tristate> Chipset::getPin_ptr(int index)
{
	return _pin_status[index];
}

nts::Tristate	Chipset::compute(std::size_t pin)
{
		if (this->_output[pin] != nullptr)
			return calculate();
		else 
			return *this->_pin_status[pin].get();
}

void	Chipset::setPin_ptr(int index, std::shared_ptr<nts::Tristate> status)
{
	this->_pin_status[index] = status;
}

nts::Tristate	Chipset::getPin_value(int index)
{
	return *_pin_status[index].get();
}

void	Chipset::setPin_value(int index, nts::Tristate value)
{
	*_pin_status[index] = value;
}

void Chipset::dump() const
{
	int i = 0;
	for (auto el : this->_pin_status)
		std::cout << "pin " << ++i << "value = \t" << el << std::endl;
}

void	Chipset::setLink (std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	//TODO chercher dans le tableau de chipset;
	//static_cast<Chipset>(other);
	//this->_pin_status[pin] = other.getPin_ptr(otherPin);
}

