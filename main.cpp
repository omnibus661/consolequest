#include <iostream>
#include "GameManager.h"
#include <filesystem>
#include <vector>

namespace fs = std::filesystem;
using Path = fs::path;

int main()
{
	MainGame::GameManager manager;

	std::cout << " --=== ConsoleQuest ===-- " << '\n' << '\n';

	//alle .save dateien laden
	std::vector<Path> files;
	for (const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(fs::current_path()))
	{
		if (entry.is_regular_file() && entry.path().extension() == ".save")
		{
			files.push_back(entry.path());
		}
	}

	std::cout << "New Game: 0" << std::endl << std::endl;

	if (!files.empty())
	{
		for (int i = 0; i < files.size(); i++)
		{
			std::filesystem::path name = files[i].stem();
			std::cout << "Load Game '" + name.string() + "': " + std::to_string(i + 1) << std::endl;
		}
	}
	std::cout << std::endl;

	int maxSel = files.size() + 1;
	std::cout << "Delete Game: " << maxSel << std::endl;
	std::cout << "Exit: " << maxSel + 1 << std::endl << std::endl;

	int selection;

	while (true)
	{
		std::cout << "Selection: (0-" << maxSel + 1 << "): ";

		if (std::cin >> selection)
		{
			if (selection >= 0 && selection < (maxSel + 1))
			{
				break;
			}
			std::cout << "Invalid Selection. Try Again" << std::endl << std::endl;
		}

		//hier falsch
		else
		{
			std::cout << "Invalid Selection. Try Again" << std::endl << std::endl;
			selection = -1;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

	//new game
	if (selection == 0)
	{
		std::cout << "Enter Name for new Savegame: ";
		String newFileName;

		std::cin >> newFileName;
		//hier neustarten??
	}

	NActiveGame game = manager.Load("game");

	if (!game)
	{
		MainGame::ActiveGame newGame = manager.New("game");
	}
}