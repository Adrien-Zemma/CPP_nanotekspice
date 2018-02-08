/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef C_JOHNSON_HPP_
	#define C_JOHNSON_HPP_

#include "Chipset.hpp"

class C_johnson: public Chipset
{
public:
	C_johnson();
private:
	nts::Tristate calculate(int index);
};

#endif /* !C_JOHNSON_HPP_ */
