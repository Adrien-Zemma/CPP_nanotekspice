/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef C_INVERT_HPP_
	#define C_INVERT_HPP_

#include "Chipset.hpp"

class C_invert: public Chipset
{
public:
	C_invert();
private:
	nts::Tristate calculate(size_t index);
	void _invert(size_t index, size_t out);
};

#endif /* !C_INVERT_HPP_ */
