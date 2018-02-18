/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef PIN_HPP_
	#define PIN_HPP_

#include "Chipset.hpp"

class Pin : public Chipset
{
public:
	Pin(std::string);
	std::shared_ptr<nts::Tristate> getPinPtr(size_t pin);
	nts::Tristate	calculate(size_t pin);
	//void	dump() const;
	
private:
	std::vector<std::shared_ptr<nts::Tristate>>	_pin_status;
};

#endif /* !PIN_HPP_ */
