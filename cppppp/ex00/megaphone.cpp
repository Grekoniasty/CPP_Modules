
#include <iostream>

int main(int ac, char **argv)
{
	char c;
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for(int i = 1; i < ac; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			c = std::toupper(argv[i][j]);
			std::cout << c;
		}
		std::cout << " ";
	}
	std::cout << std::endl;
	return 0;
}
