#include "MenuBuilder.h"
#include "Menu.h"
#include "Globals.cpp"

namespace ConsoleQuest 
{

    Menu MenuBuilder::MakeMainMenu()
    {
		Menu menu("ConsoleQuest");
		menu.Add("New Game", MenuTag::NewGame);

		auto files = GetSaveGames();
		if (!files.empty())
		{
			for (int i = 0; i < files.size(); i++)
			{
				std::filesystem::path name = files[i].stem();
				menu.Add("Load Game " + name.string(), MenuTag::SelectedGame);
			}
		}

		menu.AddBlank();
		menu.Add("Delete Game", MenuTag::DeleteGame);
		menu.Add("Exit", MenuTag::Exit);

        return menu;
    }

	Menu MenuBuilder::MakeDeleteMenu()
	{
		Menu menu = Menu("Delete Savegame");

		auto files = GetSaveGames();
		for (auto& file : files)
		{
			std::filesystem::path name = file.stem();
			menu.Add(name.string(), MenuTag::SelectedGame);
		}
		menu.AddBlank();
		menu.Add("Return", MenuTag::Exit);
		return menu;
	}

	bool MenuBuilder::Continue(const std::string& message)
	{
		Menu menu(message);
		menu.Add("Continue", MenuTag::Continue);
		menu.AllowCancel();

		MenuItem item = menu.Show();
		if (item.tag == MenuTag::Continue)
		{
			return true;
		}

		return false;
	}



}

