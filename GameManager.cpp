#include "GameManager.h"
#include <filesystem>
#include <fstream>
#include <chrono>
#include <format>

namespace fs = std::filesystem;
using namespace std::chrono;
using Path = fs::path;

namespace ConsoleQuest
{
	NActiveGame GameManager::Load(const String& gameName)
	{
		if (gameName.empty())
		{
			return std::nullopt;
		}
		return std::nullopt;
	}

	ActiveGame GameManager::New(const String& gameName)
	{
		if (CreateSaveFile(gameName))
		{
		}
		else
		{
			ActiveGame game;
			return game;
		}
	}

	bool GameManager::CreateSaveFile(const String& fileName)
	{
		const Path newFilePath = fileName + ".save";
		if (fs::exists(newFilePath))
		{
			return false;
		}

		std::ofstream fileStream(newFilePath);
		if (!fileStream)
		{
			return false;
		}

		time_point<system_clock> now = system_clock::now();
		const String creationTime = std::format("{:%Y-%m-%d_%H-%M-%S}", floor<seconds>(now));

		fileStream << "dt_Start:" + creationTime << std::endl;
		fileStream << "int64_Score:0" << std::endl;
		fileStream.close();

		return true;
	}
}