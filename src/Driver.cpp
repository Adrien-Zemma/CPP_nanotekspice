/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
**
*/

#include "Driver.hpp"

namespace loop
{
	bool	gSignalStatus;
	void	loopStatus(int sig);
}

Driver::Driver()
{
	this->_tab_function["loop"] = &Driver::loop;
	this->_tab_function["exit"] = &Driver::_exit;
	this->_tab_function["display"] = &Driver::display;
	this->_tab_function["simulate"] = &Driver::simulate;
	this->_tab_function["dump"] = &Driver::dump;
	filAvailableChipsetTab();
	filTabFactory();
	std::signal(SIGINT, loop::loopStatus);
	_clock = nts::TRUE;
	_exit_status = false;
}

Driver::~Driver()
{
	for (auto el : _available_chipset)
		delete el.second;
}

void	Driver::filTabFactory()
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

void	Driver::filAvailableChipsetTab()
{
	this->_available_chipset["4001"] = new C_nor();
	this->_available_chipset["4008"] = new C_four_added();
	this->_available_chipset["4011"] = new C_nand();
	this->_available_chipset["4013"] = new C_flip_flop(_clock);
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

bool	Driver::isAChipset(std::string name)
{
	for (auto el : this->_available_chipset)
		if (el.first == name)
			return true;
	return false;
}

void	Driver::readAv(char **av)
{
	std::vector<std::string> tmp;
	for (size_t i = 0; av[i] != NULL; i++)
		tmp.push_back(av[i]);
	if (tmp.size() < 2)
		return ;
	for (size_t i = 2; i < tmp.size(); i++)
	{
		_commande = tmp[i];
		setValue();
	}
	_commande = "";
}

void	Driver::_init(char *file, char **av)
{
	if (parse.read(file) == 84)
		_exit_status = true;
	std::vector<std::pair<std::string, std::string>> *chipset;
	chipset = parse.getChipset();
	for (auto &el: *chipset) {
		if (el.first == "input")
			this->_tab_input.push_back(std::unique_ptr
				<nts::IComponent>(new Pin(el.second)));
		else if (el.first == "output")
			this->_tab_output.push_back(std::unique_ptr
				<nts::IComponent>(new Pin(el.second)));
		else if (isAChipset(el.first))
			this->_tab_chipset.push_back(chipsetFactory(el.first,
				 el.second));
	}
	this->makeLink();
	this->readAv(av);
	this->simulate();
	this->display();
}

std::unique_ptr<nts::IComponent>	Driver::chipsetFactory(std::string type,
	std::string name)
{
	for (auto &el : this->_tab_factory)
		if (el.first == type) {
			std::unique_ptr<nts::IComponent> tmp;
			tmp = (this->*el.second)("");
			tmp.get()->setName(name);
			return tmp;
		}
	return nullptr;
}

void	Driver::setValue()
{
	auto args = Parse::split(_commande, '=');
	for (auto &it : args)
		Parse::removeSpaces(it);
	if (args.size() == 2) {
		if (getComponentFromName(args[0]).getType() == nts::PIN)
			getComponentFromName(args[0]).setPinValue(1, args[1]);
	}
}

void	Driver::shell()
{
	if (_exit_status == true)
		return ;
	do {
		std::cout << "> ";
    		getline(std::cin, _commande);
		setValue();
		for(auto &el : _tab_function)
			if (el.first == this->_commande)
				(this->*el.second)();
		if (_exit_status == true)
			return ;
	} while (!std::cin.eof());
}

void	loop::loopStatus(int sig)
{
	if (sig == 2)
		loop::gSignalStatus = false;
	else
		loop::gSignalStatus = true;
}

void	Driver::loop()
{
	loop::loopStatus(0);
	while(loop::gSignalStatus)
		this->simulate();
	loop::loopStatus(0);
}

void	Driver::_exit()
{
	this->display();
	_exit_status = true;
}

void	Driver::display()
{
	for (auto &el: this->_tab_output)
		el->dump();
}

void	Driver::reverseClock()
{
	if (_clock == nts::TRUE)
		_clock = nts::FALSE;
	else if (_clock == nts::FALSE)
		_clock = nts::TRUE;
}

void	Driver::simulate()
{
	for (auto &el : this->_tab_chipset)
		for(size_t i = el->getPinMax(); i >= 1; i--)
			el->compute(i);
	reverseClock();
}

void	Driver::dump()
{
	for (auto &el: this->_tab_input)
		el->dump();
	for(auto &el: this->_tab_chipset)
		el->dump();
}

nts::Tristate	Driver::stringToTristate(const std::string &value) const
{
	if (value == "TRUE" || value == "true")
		return nts::TRUE;
	if (value == "FALSE" || value == "false")
		return nts::FALSE;
	return nts::UNDEFINED;
}

void	Driver::checkLinks()
{
	for (auto &el : this->_tab_output) {
		if (el->getPinPtr(1).use_count() < 3) {
			std::cerr << "Output ‘"<< el->getName();
			std::cerr << "’ is not linked to anything." << std::endl;
			_exit_status = true;
		}
	}
}

void	Driver::makeLink()
{
	std::vector<std::pair 
		<std::pair<std::string, size_t>, 
		std::pair<std::string, size_t>>>	*tmp = this->parse.getLink();
	for (auto &el: *tmp)
		if (getComponentFromNameBool(el.first.first) 
		&& getComponentFromNameBool(el.second.first))
		getComponentFromName(el.first.first).setLink(el.first.second,
		getComponentFromName(el.second.first), el.second.second);
	checkLinks();
}

nts::IComponent	&Driver::getComponentFromName(std::string name)
{
	for(auto &el: this->_tab_input)
		if (el->getName() == name)
			return *el;
	for(auto &el: this->_tab_output)
		if (el->getName() == name)
			return *el;
	for(auto &el: this->_tab_chipset)
		if (el->getName() == name)
			return *el;
	return *this->_tab_chipset[0];
}

bool	Driver::getComponentFromNameBool(std::string name)
{
	for(auto &el: this->_tab_input)
		if (el->getName() == name)
			return true;
	for(auto &el: this->_tab_output)
		if (el->getName() == name)
			return true;
	for(auto &el: this->_tab_chipset)
		if (el->getName() == name)
			return true;
	return false;
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
	 return std::unique_ptr<nts::IComponent> (new C_flip_flop(stringToTristate(value)));
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