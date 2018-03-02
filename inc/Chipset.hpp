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
	Chipset() noexcept;
	Chipset(const std::string &type) noexcept;
	virtual ~Chipset();
	virtual nts::Tristate	calculate(const std::size_t &pin) noexcept = 0;
	virtual std::shared_ptr<nts::Tristate>	getPinPtr(const int &index) const noexcept;
	nts::Tristate	compute(const std::size_t &pin) noexcept;
	void	setPinPtr(const int &index, std::shared_ptr<nts::Tristate> ptr) noexcept;
	nts::Tristate	getPinValue(const int &index) const noexcept;
	void	setPinValue(const int &index, const nts::Tristate &value) noexcept;
	void	setPinValue(const int &index, const std::string &value) noexcept;
	void	setLink (const std::size_t &pin, 
		nts::IComponent &other, const std::size_t &otherPin) noexcept;
	std::string	getName() const noexcept;
	size_t	getPinMax() const noexcept;
	void	setName(const std::string &) noexcept;
	void	dump() const noexcept;
	void	dumpPin() const noexcept;
	nts::Tristate	getValue() const noexcept;
	nts::Type	getType() const noexcept;
protected:
	std::vector<std::shared_ptr<nts::Tristate>>	_pin_status;
	std::vector<std::shared_ptr<nts::Tristate>>	_output;
	nts::Tristate					_clock;
	std::string					_name;
	nts::Type					_type;
	nts::Tristate 					_value = nts::UNDEFINED;
	size_t						_pinMax = 14;
};

#endif /* !CHIPSET_HPP_ */
