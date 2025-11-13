#include "Menu.h"
#include <iostream>
#include <algorithm>
#include <cstdlib>

#if defined(_WIN32)
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

namespace ConsoleQuest 
{
	void Clear() {
		std::system(CLEAR);
	}

	void Menu::Add(const std::string& _data, const int _value)
	{
		items.push_back(MenuItem(_data, _value));
	}
	void Menu::AddBlank()
	{
		Menu::Add(std::string{}, -1);
	}
	int Menu::Show()
	{
		std::vector<MenuItem> valid;
		valid.reserve(items.size());

		std::copy_if(items.begin(), items.end(), std::back_inserter(valid), 
			[](const MenuItem& item) 
			{
				return item.value != -1;
			});

		auto lowest = std::min_element(valid.begin(), valid.end(),
			[](const MenuItem& a, const MenuItem& b) 
			{
				return a.value < b.value;
			});

		auto highest = std::max_element(valid.begin(), valid.end(),
			[](const MenuItem& a, const MenuItem& b) 
			{
				return a.value < b.value;
			});

		int min = lowest->value;
		int max = highest->value;

		while (true) {
			Clear();

			std::cout << title;
			int selection;
			for (auto& item : items)
			{
				if (item.value != -1)
				{
					std::cout << item.value << " " << item.data << std::endl;
				}
				else {
					std::cout << "" << std::endl;
				}
				
			}
			std::cout << "Selection (" << min << "-" << max << "): ";
			
			if (std::cin >> selection)
			{
				if (selection >= min && selection <= max)
				{
					return selection;

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

