/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef C_XOR_HPP_
	#define C_XOR_HPP_

#include "Chipset.hpp"

class C_xor: public Chipset
{
public:
	C_xor();
private:
	nts::Tristate calculate(size_t index);
};

#endif /* !C_XOR_HPP_ */
