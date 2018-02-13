/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef PIN_HPP_
	#define PIN_HPP_

// #include "IComponent.hpp"
#include "Chipset.hpp"

class Pin : public Chipset
{
public:
	Pin(std::string);
	virtual ~Pin(){};
	enum Pin_Type
	{
		OUTPUT,
		INPUT
	};
	std::shared_ptr<nts::Tristate> getPinPtr(size_t pin);
	nts::Tristate	calculate(size_t pin);
	void	dump() const;
	
private:
	std::vector<std::shared_ptr<nts::Tristate>>	_pin_status;
	std::string	_name;
	Pin_Type _type;

};

#endif /* !PIN_HPP_ */
