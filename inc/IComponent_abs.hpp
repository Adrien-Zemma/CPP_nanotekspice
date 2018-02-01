/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef ICOMPONENT_ABS_HPP_
	#define ICOMPONENT_ABS_HPP_

#include "IComponent.hpp"
#include <vector>

class IComponent_abs : public nts::IComponent
{
public:
	void calculate();
protected:
	std::vector <nts::Tristate> _pin_status;
	std::string _name;
	nts::Tristate clock;
};

#endif /* !ICOMPONENT_ABS_HPP_ */
