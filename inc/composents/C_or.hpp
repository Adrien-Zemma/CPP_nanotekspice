/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef C_OR_HPP_
	#define C_OR_HPP_

#include "Chipset.hpp"

class C_or: public Chipset
{
public:
	C_or();
	nts::Tristate calculate(size_t index);
private:
};


#endif /* !C_OR_HPP_ */
