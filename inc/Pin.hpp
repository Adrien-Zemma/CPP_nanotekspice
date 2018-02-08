/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef PIN_HPP_
	#define PIN_HPP_

#include "IComponent.hpp"

class Pin
{
public:
	Pin();
	~Pin();
	std::shared_ptr<nts::Tristate> getPin_ptr();
private:
	std::shared_ptr<nts::Tristate> value;
};

#endif /* !PIN_HPP_ */
