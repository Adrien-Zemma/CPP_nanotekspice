/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef C_AND_HPP_
	#define C_AND_HPP_

#include "IComponent_abs.hpp"

#define NB_PIN 14;

class C_and: public IComponent_abs
{
public:
	C_and();
	void calculate();
private:
	void _and(int index, int index2, int output);
};

#endif /* !C_AND_HPP_ */
