/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef C_ROM_HPP_
	#define C_ROM_HPP_

#include "Chipset.hpp"

class C_rom: public Chipset
{
public:
	C_rom();
private:
	nts::Tristate calculate(size_t index);
};

#endif /* !C_ROM_HPP_ */
