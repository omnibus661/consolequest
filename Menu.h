#pragma once
#include <string>
#include <vector>
namespace ConsoleQuest
{
	struct MenuItem 
	{
		std::string data;
		int value{};

	public:
		MenuItem(const std::string& _data, const int _value) : data(_data), value(_value) {}
	};

	class Menu
	{
	private:
		std::vector<MenuItem> items;
		std::string title;

	public:
		Menu(const std::string& title){}
		Menu(const std::string& title, const std::vector<MenuItem>& items) : items(items), title(title) {}
		
		void Add(const std::string& _data, const int _value);
		void AddBlank();
		int Show();
	};
}


