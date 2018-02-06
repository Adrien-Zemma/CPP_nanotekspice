/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "IComponent.hpp"

#ifndef C_NOR_HPP_
	#define C_NOR_HPP_

class C_nor: public nts::IComponent
{
public:
	C_nor();
	void	calculate();
	nts::Tristate	compute(std::size_t pin);
	void	setLink (std::size_t pin, nts::IComponent &other, std::size_t otherPin);
	void	dump() const;
	void	_nor(int index1, int index2, int output);
private:
	std::vector <std::shared_ptr<nts::Tristate>> _pin_status;
	std::string			_name;
	nts::Tristate 			_clock;
};

#endif /* !C_NOR_HPP_ */
