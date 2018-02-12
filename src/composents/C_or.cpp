/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "C_or.hpp"

C_or::C_or(){}

nts::Tristate C_or::calculate(size_t index)
{
	/*
	faire un tableau de pointer sur fonction pour choisire quelle fonctin en fonction de quelle output
	*/
	index = index;
	return nts::UNDEFINED;
}

//nts::Tristate C_nor::calculate(int index)
//{
//	_or(1, 2, 3);
//	_or(5, 6, 4);
//	_or(8, 9, 10);
//	_or(12, 13, 11);
//}

//void C_or::_or(int index1, int index2, int index3)
//{
//	if (this->_pin_status[index1] == nts::FALSE && this->_pin_status[index2] == nts::FALSE)
//		this->_pin_status[index3] = nts::FALSE;
//	else 
//		this->_pin_status[index3] = nts::TRUE;
//}