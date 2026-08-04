#include "PhoneBook.class.hpp"
#include <iomanip>
#include <cstdlib>
PhoneBook::PhoneBook()
{
	_contactCount = 0;
}

PhoneBook::~PhoneBook()
{
}
static size_t	utf8Length(std::string const &str)
{
	size_t	count = 0;

	for (size_t i = 0; i < str.length(); i++)
	{
		if ((static_cast<unsigned char>(str[i]) & 0xC0) != 0x80)
			count++;
	}
	return (count);
}

static std::string	utf8Substr(std::string const &str, size_t chars)
{
	size_t	count = 0;
	size_t	i = 0;

	while (i < str.length())
	{
		if ((static_cast<unsigned char>(str[i]) & 0xC0) != 0x80)
		{
			if (count == chars)
				break ;
			count++;
		}
		i++;
	}
	return (str.substr(0, i));
}

static std::string	padRight(std::string const &str, size_t width)
{
	size_t	len = utf8Length(str);

	if (len >= width)
		return (str);
	return (std::string(width - len, ' ') + str);
}

std::string truncate(std::string str)
{
	if (utf8Length(str) > 10)
		return (utf8Substr(str, 9) + ".");
	return (str);
}

static bool	promptField(std::string const &label, std::string &out)
{
	while (true)
	{
		std::cout << "Input the " << label << ": ";
		if (!std::getline(std::cin, out))
			return (false);
		if (!out.empty())
			return (true);
		std::cout << "Field cannot be empty." << std::endl;
	}
}

void	PhoneBook::add()
{
	static char const	*labels[5] = {
		"First Name",
		"Last Name",
		"Nickname",
		"Phone Number",
		"Darkest Secret"
	};
	std::string		fields[5];
	Contact			&contact = _contacts[_contactCount % 8];

	for (int i = 0; i < 5; i++)
	{
		if (!promptField(labels[i], fields[i]))
		{
			std::cout << std::endl
				<< "Oi! That's the EOF, focking diabolical." << std::endl;
			return ;
		}
	}
	contact.SetFirstName(fields[0]);
	contact.SetLastName(fields[1]);
	contact.SetNickname(fields[2]);
	contact.SetPhoneNumber(fields[3]);
	contact.SetDarkestSecret(fields[4]);
	_contactCount++;
}

void	PhoneBook::search()
{
	std::string	input;
	int		index;

	std::cout << std::setw(10) << "index" << "|"
		<< std::setw(10) << "first name" << "|"
		<< std::setw(10) << "last name" << "|"
		<< std::setw(10) << "nickname" << std::endl;
	for (int i = 0; i < _contactCount && i < 8; i++)
	{
		std::cout << std::setw(10) << i << "|"
			<< padRight(truncate(_contacts[i].getFirstName()), 10) << "|"
			<< padRight(truncate(_contacts[i].getLastName()), 10) << "|"
			<< padRight(truncate(_contacts[i].getNickname()), 10) << std::endl;
	}
	std::cout << "Enter index: ";
	std::getline(std::cin, input);
	if (input.length() == 1 && std::isdigit(input[0]))
		index = std::atoi(input.c_str());
	else
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	if (index < 0 || index >= _contactCount || index >= 8)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " <<_contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " <<_contacts[index].getDarkestSecret() << std::endl;

}
