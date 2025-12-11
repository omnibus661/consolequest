#pragma once
#include "Menu.h"

namespace ConsoleQuest 
{
	class MenuBuilder
	{

	private:
		MenuBuilder() = delete;
		~MenuBuilder() = delete;

	public:

		static Menu MakeMainMenu();
		static Menu MakeDeleteMenu();
		static bool Continue(const std::string& message);
	};
}


