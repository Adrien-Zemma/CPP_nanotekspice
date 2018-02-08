/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef PIN_HPP_
	#define PIN_HPP_

#include "IComponent.hpp"

class Pin
{
public:
	Pin();
	~Pin();
	enum Pin_Type
	{
		OUTPUT,
		INPUT
	};
	std::shared_ptr<nts::Tristate> getPin_ptr();
	void	setPin_valu();
private:
	std::shared_ptr<nts::Tristate>	_value;
	std::string	_name;
	Pin_Type _type;

};

#endif /* !PIN_HPP_ */
