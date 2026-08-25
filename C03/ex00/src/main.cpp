#include "../include/ClapTrap.hpp"
#include <cstdlib>
#include <unistd.h>

static void nap(void) { usleep(1000000); }

int main(int argc, char **argv)
{
	std::cout << "====== WELCOME TO THE CLAPTRAP ARENA ======" << std::endl;
	std::cout << std::endl;
	std::cout << "Pick your scenario:" << std::endl;
	std::cout << "  1) The Classic Beatdown" << std::endl;
	std::cout << "  2) The Twins" << std::endl;
	std::cout << "  3) The Marathon" << std::endl;
	std::cout << "  4) The Comeback" << std::endl;
	std::cout << std::endl;
	std::cout << "> ";

	std::string input;
	if (argc > 1)
		input = argv[1];
	else if (!std::getline(std::cin, input))
		return 1;

	int choice = std::atoi(input.c_str());

	std::cout << std::endl;

	switch (choice)
	{
		case 1:
		{
			std::cout << "--- The Classic Beatdown ---" << std::endl;
			std::cout << std::endl;
			ClapTrap jesus("Jesus");
			ClapTrap putin("Putin");
			nap();
			jesus.attack("Putin");
			putin.takeDamage(4);
			nap();
			jesus.attack("Putin");
			putin.takeDamage(4);
			nap();
			jesus.attack("Putin");
			putin.takeDamage(4);
			nap();
			putin.takeDamage(1);
			nap();
			putin.beRepaired(5);
			std::cout << std::endl;
			break;
		}
		case 2:
		{
			std::cout << "--- The Twins ---" << std::endl;
			std::cout << std::endl;
			ClapTrap original("Twin");
			ClapTrap clone(original);
			nap();
			original.attack("Twin");
			clone.takeDamage(3);
			nap();
			clone.attack("Twin");
			original.takeDamage(3);
			nap();
			original.attack("Twin");
			clone.takeDamage(7);
			nap();
			clone.attack("Twin");
			std::cout << std::endl;
			break;
		}
		case 3:
		{
			std::cout << "--- The Marathon ---" << std::endl;
			std::cout << std::endl;
			ClapTrap runner("Angry Stinky Nerd");
			for (int i = 0; i < 10; i++)
			{
				nap();
				runner.attack("The Undestroyable PC");
			}
			std::cout << std::endl;
			std::cout << "--- Energy depleted, one more try... ---" << std::endl;
			nap();
			runner.attack("The Undestroyable PC");
			std::cout << std::endl;
			break;
		}
		case 4:
		{
			std::cout << "--- The Comeback ---" << std::endl;
			std::cout << std::endl;
			std::cout << "Desoriented Eagle sees a lonely squirrel walking down the street" << std::endl;
			ClapTrap angry_cat("Deformed Squirrel");
			nap();
			angry_cat.takeDamage(4);
			nap();
			angry_cat.takeDamage(4);
			nap();
			angry_cat.takeDamage(1);
			std::cout << std::endl;
			std::cout << "--- Eagle flew 10m away and can't find its way back. Deformed Squirrel is almost done... time to patch up ---" << std::endl;
			nap();
			angry_cat.beRepaired(5);
			nap();
			angry_cat.beRepaired(3);
			std::cout << std::endl;
			std::cout << "--- Oh shit Eagle is coming back! Can the squirrel survive another hit? ---" << std::endl;
			nap();
			angry_cat.takeDamage(3);
			nap();
			angry_cat.takeDamage(9);
			angry_cat.beRepaired(1);
			std::cout << std::endl;
			break;
		}
		default:
		{
			std::cout << "Invalid choice. Pick 1-4 next time." << std::endl;
			return 1;
		}
	}
	return 0;
}
