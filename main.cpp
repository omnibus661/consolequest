#include <iostream>
#include <filesystem>
#include <vector>
#include "GameManager.h"
#include "Menu.h"
using namespace ConsoleQuest;

namespace fs = std::filesystem;
using Path = fs::path;

int main()
{
	GameManager manager;
	Menu menu("ConsoleQuest");
	menu.Add("New Game", 0);

	//alle .save dateien laden
	std::vector<Path> files;
	for (const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(fs::current_path()))
	{
		if (entry.is_regular_file() && entry.path().extension() == ".save")
		{
			files.push_back(entry.path());
		}
	}

	if (!files.empty())
	{
		for (int i = 0; i < files.size(); i++)
		{
			std::filesystem::path name = files[i].stem();
			menu.Add("Load Game " + name.string(), i + 1);
		}
	}

	menu.AddBlank();

	int maxSel = files.size() + 1;
	menu.Add("Delete Game", maxSel);
	menu.Add("Exit", maxSel + 1);

	int selection = menu.Show();

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
		ActiveGame newGame = manager.New("game");
	}
}