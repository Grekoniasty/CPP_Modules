
#include <iostream>

int main(int ac, char **argv)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	for(int i = 1; i < ac; i++)
	{
		for (int j = 0; argv[i][j]; j++)
		{
			if (argv[i][j] > 96 && argv[i][j] < 123)
				std::cout << (char)(argv[i][j] - 32);
			else
				std::cout << argv[i][j];
		}
	}
	std::cout << std::endl;
	return 0;
}
