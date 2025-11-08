#pragma once

#include <string>
#include "SavedGame.h"

using String = std::string;

namespace System
{
	struct SystemResponse
	{
		SystemResponse(bool s, String m) : message(std::move(m)), success(s) {}

	private:
		String message;
		bool success;

	public:

		[[nodiscard]]
		const String& Message() const noexcept
		{
			return message;
		}

		[[nodiscard]]
		bool Success() const noexcept
		{
			return success;
		}
	};

	class DataSystem
	{
		SystemResponse Save(Game::SavedGame& game);
		Game::SavedGame Load();
	};
}
