/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef CHIPSET_HPP_
	#define CHIPSET_HPP_
	
#define NB_PIN 20;
#include "IComponent.hpp"

class Chipset :public nts::IComponent
{
public:
	enum Type
	{
		PIN,
		CHIPSETS
	};
	Chipset();
	Chipset(std::string type);
	virtual ~Chipset();
	virtual nts::Tristate	calculate(std::size_t pin) = 0;
	virtual std::shared_ptr<nts::Tristate>	getPinPtr(int index);
	nts::Tristate	compute(std::size_t pin);
	void	setPinPtr(int index, std::shared_ptr<nts::Tristate> ptr);
	nts::Tristate	getPinValue(int index);
	void	setPinValue(int index, nts::Tristate value);
	void	setPinValue(int index, std::string value);
	void	setLink (std::size_t pin, 
		nts::IComponent &other, std::size_t otherPin);
	std::string	getName();
	size_t	getPinMax();
	void	setName(std::string);
	void	dump() const;
	void	dumpPin() const;
protected:
	std::vector<std::shared_ptr<nts::Tristate>>	_pin_status;
	std::vector<std::shared_ptr<nts::Tristate>>	_output;
	nts::Tristate					_clock;
	std::string					_name;
	Type						_type;
	size_t						_pinMax = 14;
};

#endif /* !CHIPSET_HPP_ */
