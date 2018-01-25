/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef C_AND_HPP_
	#define C_AND_HPP_

#include "IComponent_abs.hpp"

class C_and: public IComponent_abs
{
	void _and(int index, int index2, int output);
};

#endif /* !C_AND_HPP_ */
