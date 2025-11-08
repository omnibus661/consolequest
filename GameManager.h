#pragma once

#include <optional>
#include <string>

namespace MainGame
{
	class ActiveGame;
}

using NActiveGame = std::optional<MainGame::ActiveGame>;
using String = std::string;

namespace MainGame
{
	class ActiveGame
	{
	};

	class GameManager
	{
	public:
		NActiveGame Load(const String& gameName);
		ActiveGame New(const String& gameName);
	private:
		static bool CreateSaveFile(const String& fileName);
	};

	struct SystemResponse
	{
		bool success;
		String message;

		SystemResponse(bool s, String m)
			: success(s), message(std::move(m)) {
		}

		[[nodiscard]] bool Success() const noexcept { return success; }
		[[nodiscard]] const String& Message() const noexcept { return message; }
	};
}
