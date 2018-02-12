/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "Chipset.hpp"

// Chipset::Chipset(){}

// Chipset::~Chipset()
// {
	
// }

nts::Tristate	Chipset::compute(std::size_t pin)
{
	return this->calculate(pin);
}

void Chipset::setName(std::string name)
{
	this->_name = name;
}

std::shared_ptr<nts::Tristate> Chipset::getPinPtr(int index)
{
	return _pin_status[index];
}

void	Chipset::setPinPtr(int index, std::shared_ptr<nts::Tristate> status)
{
	this->_pin_status[index] = status;
}

nts::Tristate	Chipset::getPinValue(int index)
{
	return *_pin_status[index].get();
}

void	Chipset::setPinValue(int index, nts::Tristate value)
{
	*_pin_status[index] = value;
}

void Chipset::dump() const
{
	int i = 0;	
	std::cout << "Composent :\t" << this->_name << std::endl;
	for (auto el : this->_pin_status)
		std::cout << "pin " << ++i << "value = \t" << el << std::endl;
	std::cout << std::endl;
}

void	Chipset::setLink (std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	this->_pin_status[pin] = other.getPinPtr(otherPin);
}

std::string 	Chipset::getName()
{
	return this->_name;
}