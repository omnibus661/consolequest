#include <iostream>
#include <filesystem>
#include <vector>
#include "GameManager.h"
#include "Menu.h"
#include "MenuBuilder.h"

using namespace ConsoleQuest;

namespace fs = std::filesystem;
using Path = fs::path;

int main()
{
	GameManager manager;
	NActiveGame game;

	while (!game)
	{
		MenuItem selection = MenuBuilder::MakeMainMenu().Show();

		if (selection.tag == MenuTag::Exit)
		{
			break;
		}

		//delete
		if (selection.tag == MenuTag::DeleteGame)
		{
			MenuItem toDelete = MenuBuilder::MakeDeleteMenu().Show();

			if (toDelete.tag == MenuTag::SelectedGame &&
				MenuBuilder::Continue("Really delete '" + toDelete.data + "' ?")) {
				manager.Delete(toDelete.data);
			}
		}

		//new game
		if (selection.tag == MenuTag::NewGame)
		{
			Menu::ClearConsole();
			std::cout << "Enter Name for new Savegame: ";
			String newFileName;

			std::cin >> newFileName;
			manager.New(newFileName);
		}

		if(selection.tag == MenuTag::SelectedGame)
		{

		}

	}

	if (game == std::nullopt)
	{
		std::cout << "Goodbye";
		return 0;
	}
}

