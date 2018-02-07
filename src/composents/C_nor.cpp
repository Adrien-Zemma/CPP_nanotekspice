/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "C_nor.hpp"

C_nor::C_nor(){}

//void C_nor::calculate()
//{
//	_nor(1, 2, 3);
//	_nor(5, 6, 4);
//	_nor(8, 9, 10);
//	_nor(12, 13, 11);
//}

nts::Tristate C_nor::calculate(int index)
{
	/*
	faire un tableau de pointer sur fonction pour choisire quelle fonctin en fonction de quelle output
	*/
	index = index;
	return nts::UNDEFINED;
}


//nts::Tristate C_nor::_nor(int index1, int index2, int index3)
//{
//	if (*this->_pin_status[index1].get() == nts::TRUE && *this->_pin_status[index2].get() == nts::TRUE)
//	{
//		*this->_pin_status[index3] = nts::TRUE;
//		return nts::TRUE;
//	}
//	else 
//	{
//		*this->_pin_status[index3] = nts::FALSE;
//		return nts::FALSE;
//	}
//}