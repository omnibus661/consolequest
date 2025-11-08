#include "DataSystem.h"
#include <nlohmann/json.hpp>

namespace System
{
	SystemResponse DataSystem::Save(Game::SavedGame& game)
	{
		SystemResponse response(true, "");

		return response;
	}

	Game::SavedGame DataSystem::Load()
	{
		Game::SavedGame game();
		return game();
	}
}