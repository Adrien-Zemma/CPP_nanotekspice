/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef C_NAND_HPP_
	#define C_NAND_HPP_

#include "Chipset.hpp"

class C_nand: public Chipset
{
public:
	C_nand();
private:
	void C_nand::_nand(size_t idx1, size_t idx2, size_t out);
	nts::Tristate calculate(size_t index);
};

#endif /* !C_NAND_HPP_ */
