/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef C_REGISTER_HPP_
	#define C_REGISTER_HPP_

#include "Chipset.hpp"

class C_register: public Chipset
{
public:
	C_register();
private:
	nts::Tristate calculate(int index);
};

#endif /* !C_REGISTER_HPP_ */
