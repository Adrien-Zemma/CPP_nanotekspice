/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** 
*/

#include "Driver.hpp"

Driver::Driver()
{
	this->_tab_function["loop"] = &Driver::loop;
	this->_tab_function["exit"] = &Driver::_exit;
	this->_tab_function["display"] = &Driver::display;
	this->_tab_function["simulate"] = &Driver::simulate;
	this->_tab_function["dump"] = &Driver::dump;
	fil_available_chipsettab();
	fil_tab_factory();
}

Driver::~Driver(){}

void	Driver::fil_tab_factory()
{
	this->_tab_factory["4001"] = &Driver::creat4001;
	this->_tab_factory["4008"] = &Driver::creat4008;
	this->_tab_factory["4011"] = &Driver::creat4011;
	this->_tab_factory["4013"] = &Driver::creat4013;
	this->_tab_factory["4017"] = &Driver::creat4017;
	this->_tab_factory["4030"] = &Driver::creat4030;
	this->_tab_factory["4040"] = &Driver::creat4040;
	this->_tab_factory["4069"] = &Driver::creat4069;
	this->_tab_factory["4071"] = &Driver::creat4071;
	this->_tab_factory["4081"] = &Driver::creat4081;
	this->_tab_factory["4094"] = &Driver::creat4094;
	this->_tab_factory["4514"] = &Driver::creat4514;
	this->_tab_factory["2716"] = &Driver::creat2716;
}

void Driver::fil_available_chipsettab()
{
	this->_available_chipset["4001"] = new C_nor();
	this->_available_chipset["4008"] = new C_four_added();
	this->_available_chipset["4011"] = new C_nand();
	this->_available_chipset["4013"] = new C_flip_flop();
	this->_available_chipset["4017"] = new C_johnson();
	this->_available_chipset["4030"] = new C_xor();
	this->_available_chipset["4040"] = new C_conter();
	this->_available_chipset["4069"] = new C_invert();
	this->_available_chipset["4071"] = new C_or();
	this->_available_chipset["4081"] = new C_and();
	this->_available_chipset["4094"] = new C_register();
	this->_available_chipset["4514"] = new C_ram();
	this->_available_chipset["2716"] = new C_rom();
}

bool	Driver::is_a_chipset(std::string name)
{
	for (auto el : this->_available_chipset)
	{
		if (el.first == name)
			return true;
	}
	return false;
}

void Driver::init()
{
	std::vector<std::pair<std::string, std::string>> *chipset = parse.getChipset();

	for (auto &el: *chipset)
	{
		std::cout << el.first << "\t" << el.second << std::endl;
		if (el.first == "input")
			this->_tab_input.push_back(std::unique_ptr<nts::IComponent>(new Pin(el.second)));
		else if (el.first == "output")
			this->_tab_output.push_back(std::unique_ptr<nts::IComponent>(new Pin(el.second)));
		else if (is_a_chipset(el.first))
			this->_tab_chipset.push_back(chipset_factory(el.first, el.second));
	}
}

std::unique_ptr<nts::IComponent>	Driver::chipset_factory(std::string type,
	std::string name)
{
	for (auto &el : this->_tab_factory)
		if (el.first == type)
		{
			std::unique_ptr<nts::IComponent> tmp = (this->*el.second)("");
			tmp.get()->setName(name);
			return tmp;
		}
	return nullptr;
}

void	Driver::init()
{

}

void Driver::shell()
{
	this->init();
	this->new_line();
	for (auto el = _tab_function.begin(); el != _tab_function.end(); ++el)
		if (el->first == _command) {
			(this->*el->second)();
			return ;
		}
}

void Driver::new_line()
{
	std::cout << "> ";
	std::cin >> this->_command;
}

void Driver::loop()
{
	while(1)
		this->simulate();
}

void Driver::_exit()
{
	std::cout << "exit" << std::endl;
}

void Driver::display()
{
	std::cout << "display" << std::endl;
}

void Driver::simulate()
{
	std::cout << "simulate" << std::endl;
}

void Driver::dump()
{
	for(auto &el: this->_tab_output)
		el->dump();
}

std::unique_ptr<nts::IComponent>	Driver::creat4001(const std::string
	&value) const noexcept
{
	(void) value;
	return std::unique_ptr<nts::IComponent>(new C_nor());
}
std::unique_ptr<nts::IComponent>	Driver::creat4008(const std::string
	&value) const noexcept
{
	(void) value;
	return std::unique_ptr<nts::IComponent>(new C_four_added());
}
std::unique_ptr<nts::IComponent>	Driver::creat4011(const std::string
	&value) const noexcept
{
	(void) value;
	 return std::unique_ptr<nts::IComponent>(new C_nand());
}
std::unique_ptr<nts::IComponent>	Driver::creat4013(const std::string
	&value) const noexcept
{
	(void) value;
	 return std::unique_ptr<nts::IComponent>(new C_flip_flop());
}
std::unique_ptr<nts::IComponent>	Driver::creat4017(const std::string
	&value) const noexcept
{
	(void) value;
	 return std::unique_ptr<nts::IComponent>(new C_johnson());
}
std::unique_ptr<nts::IComponent>	Driver::creat4030(const std::string
	&value) const noexcept
{
	(void) value;
	return std::unique_ptr<nts::IComponent>(new C_xor());
}
std::unique_ptr<nts::IComponent>	Driver::creat4040(const std::string
	&value) const noexcept
{
	(void) value;
	return std::unique_ptr<nts::IComponent>(new C_conter());
}
std::unique_ptr<nts::IComponent>	Driver::creat4069(const std::string
	&value) const noexcept
{
	(void) value;
	return std::unique_ptr<nts::IComponent>(new C_invert());
}
std::unique_ptr<nts::IComponent>	Driver::creat4071(const std::string 
	&value) const noexcept
{
	(void) value;
	return std::unique_ptr<nts::IComponent>(new C_or());
}
std::unique_ptr<nts::IComponent>	Driver::creat4081(const std::string
	&value) const noexcept
{
	(void) value;
	return std::unique_ptr<nts::IComponent>(new C_and());
}
std::unique_ptr<nts::IComponent>	Driver::creat4094(const std::string
	&value) const noexcept
{
	(void) value;
	return std::unique_ptr<nts::IComponent>(new C_register());
}
std::unique_ptr<nts::IComponent>	Driver::creat4514(const std::string
	&value) const noexcept
{
	(void)value;
	return std::unique_ptr<nts::IComponent>(new C_ram());
}
std::unique_ptr<nts::IComponent>	Driver::creat2716(const std::string
	&value) const noexcept
{
	(void)value;
	return std::unique_ptr<nts::IComponent>(new C_rom());
}

void Driver::make_link()
{
	std::vector<std::pair 
		<std::pair<std::string, size_t>, 
		std::pair<std::string, size_t>>>	*tmp = this->parse.getLink();
	for (auto &el : *tmp)
	{
		for(auto &it : _tab_chipset)
			make_link2(el, it);
		for (auto &it : this->_tab_input)
			make_link2(el, it);
		for (auto &it : this->_tab_output)
			make_link2(el, it);
	}
}

nts::IComponent &Driver::get_component_from_name(std::string name)
{
	for(auto &el: this->_tab_chipset)
		if (el->getName() == name)
			return *el.get();
	return *this->_tab_chipset[0];
}

void	Driver::make_link2(std::pair <std::pair<std::string, size_t>, 
	std::pair<std::string, size_t>> link, 
	std::unique_ptr<nts::IComponent> &chipset)
{
	if (link.first.first == chipset->getName())
	{
		chipset->setLink(link.second.second,
			get_component_from_name(link.first.first), link.first.second);
	}
}