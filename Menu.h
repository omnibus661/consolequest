#pragma once

#include <string>
#include <vector>
#include <optional>
#include <any>
namespace ConsoleQuest
{
	enum class MenuTag
	{
		None = 0,
		Exit = 1 << 0,
		NewGame = 1 << 1,
		SelectedGame = 1 << 2,
		DeleteGame = 1 << 3,
		Invalid = 1 << 4,
		Continue = 1 << 5,
		Blank = 1 << 6
	};

	struct MenuItem 
	{
		std::string data;
		std::optional<MenuTag> tag;

	public:
		MenuItem(const std::string& _data, const std::optional<MenuTag> _tag) : data(_data), tag(_tag) {}
		MenuItem(const std::string& _data) : data(_data){}
	};

	class Menu
	{
	private:
		std::vector<MenuItem> items;
		std::string title;
		bool anyOtherIsCancel;

		MenuItem GetItem(const int value);
	public:
		Menu(const std::string& title) : title(title), anyOtherIsCancel(false){}
		Menu(const std::string& title, const std::vector<MenuItem>& items) : items(items), title(title), anyOtherIsCancel(false) {}
		
		void Add(const std::string& _data, MenuTag tag);
		void Add(const std::string& _data);
		void AllowCancel();
		void AddBlank();
		MenuItem Show();

		static void ClearConsole();
	};

}


