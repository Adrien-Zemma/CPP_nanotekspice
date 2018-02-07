/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef C_RAM_HPP_
	#define C_RAM_HPP_

#include "Chipset.hpp"

class C_ram: public Chipset
{
public:
	C_ram();
private:
	nts::Tristate calculate(int index);
};

#endif /* !C_RAM_HPP_ */
