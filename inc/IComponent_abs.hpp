/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#ifndef ICOMPONENT_ABS_HPP_
	#define ICOMPONENT_ABS_HPP_

#include "IComponent.hpp"
#include <vector>
#include <memory>
class IComponent_abs : public nts::IComponent
{
public:
	void calculate();
	std::unique_ptr < IComponent> creat4001 (const std::string &value) const noexcept;
	std::unique_ptr < IComponent> creat4008 (const std::string &value) const noexcept;
	std::unique_ptr < IComponent> creat4011 (const std::string &value) const noexcept;
	std::unique_ptr < IComponent> creat4013 (const std::string &value) const noexcept;
	std::unique_ptr < IComponent> creat4017 (const std::string &value) const noexcept;
	std::unique_ptr < IComponent> creat4030 (const std::string &value) const noexcept;
	std::unique_ptr < IComponent> creat4040 (const std::string &value) const noexcept;
	std::unique_ptr < IComponent> creat4069 (const std::string &value) const noexcept;
	std::unique_ptr < IComponent> creat4071 (const std::string &value) const noexcept;
	std::unique_ptr < IComponent> creat4081 (const std::string &value) const noexcept;
	std::unique_ptr < IComponent> creat4094 (const std::string &value) const noexcept;
	std::unique_ptr < IComponent> creat4514 (const std::string &value) const noexcept;
	std::unique_ptr < IComponent> creat2716 (const std::string &value) const noexcept;
protected:
	std::vector <nts::Tristate> _pin_status;
	std::string _name;
	nts::Tristate clock;
};

#endif /* !ICOMPONENT_ABS_HPP_ */
