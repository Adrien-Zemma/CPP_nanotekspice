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
	nts::Tristate calculate(const size_t &index) noexcept;
	void _invert(size_t index, int out);
};

#endif /* !C_INVERT_HPP_ */
