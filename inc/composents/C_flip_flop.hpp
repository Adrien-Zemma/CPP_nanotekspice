/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef C_FLIP_FLOP_HPP_
	#define C_FLIP_FLOP_HPP_


#include "Chipset.hpp"

class C_flip_flop: public Chipset
{
public:
	C_flip_flop(nts::Tristate);
private:
	nts::Tristate calculate(size_t index);
	void	_flip_flop(std::vector<int>);
};

#endif /* !C_FLIP_FLOP_HPP_ */
