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
	nts::Tristate calculate(const size_t &index) noexcept;
private:
	void _xor(size_t index, size_t index2, size_t out);
};

#endif /* !C_XOR_HPP_ */
