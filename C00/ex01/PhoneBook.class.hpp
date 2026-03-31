#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include "Contact.class.hpp"
# include <iostream>
# include <iomanip>
class PhoneBook
{
	private:
		Contact _contacts[8];
		int _contactCount;
	public:
		PhoneBook();
		~PhoneBook();
		void add();
		void search();

};

#endif
