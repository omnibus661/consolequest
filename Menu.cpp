#include "Menu.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include "Globals.cpp"

#if defined(_WIN32)
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

namespace ConsoleQuest 
{
	static void Clear() {
		std::system(CLEAR);
	}

	void Menu::Add(const std::string& _data, MenuTag _tag)
	{
		items.push_back(MenuItem(_data, _tag));
	}

	void Menu::Add(const std::string& _data)
	{
		Add(_data, MenuTag::None);
	}


	void Menu::AllowCancel()
	{
		anyOtherIsCancel = true;
	}

	void Menu::AddBlank()
	{
		Add(std::string{}, MenuTag::Blank);
	}


	MenuItem Menu::Show()
	{
		std::vector<MenuItem> valid;
		valid.reserve(items.size());

		std::copy_if(items.begin(), items.end(), std::back_inserter(valid), [](const MenuItem& item) 
			{
				return item.tag != MenuTag::Blank && item.tag != MenuTag::Invalid;
			});

		int min = 0;
		size_t max = valid.size() -1;

		while (true) {
			Clear();

			int selectedIndex = 0;
			std::cout << title << std::endl << std::endl;
			for (auto& item : items)
			{
				if (item.tag != MenuTag::Blank)
				{
					std::cout << selectedIndex << " " << item.data << std::endl;
					selectedIndex++;
				}
				else {
					std::cout << "" << std::endl;
				}
				
			}
			
			//implicit cancel
			if (anyOtherIsCancel)
			{
				std::cout << "Selection (" << min << "-" << max << ")";

				std::cout << std::endl << "(press any other key to return): ";
				std::string input;

				std::cin >> input;

				int inputNum = 0;
				if (IsNumeric(input, inputNum))
				{
					if (inputNum >= min && inputNum <= max)
					{
						MenuItem item = GetItem(inputNum);
						return item;
					}

					return MenuItem("Cancel", MenuTag::Exit);
				}
				else {
					return MenuItem("Cancel", MenuTag::Exit);
				}	
			}

			//regular, no implicit cancel
			else {

				std::cout << "Selection (" << min << "-" << max << "): ";

				int selection;
				if (std::cin >> selection)
				{
					if (selection >= min && selection <= max)
					{
						MenuItem item = GetItem(selection);
						return item;
					}
					else {
						std::cout << "Invalid Selection." << std::endl << std::endl;
					}
				}
				else
				{
					std::cout << "Invalid Selection." << std::endl << std::endl;
					selection = -1;
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			}
		}
	}

	MenuItem Menu::GetItem(const int value)

	{
		std::vector<MenuItem> valid;
		std::copy_if(items.begin(), items.end(), std::back_inserter(valid), [](const MenuItem& item)
			{
				return item.tag != MenuTag::Blank && item.tag != MenuTag::Invalid;
			});


		if (value > valid.size())
		{
			return MenuItem("Not Found", MenuTag::Invalid);
		}

		return valid[value];
	}

	void Menu::ClearConsole()
	{
		std::system(CLEAR);
	}
}