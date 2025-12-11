#include <vector>
#include <chrono>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std::chrono;
using Path = fs::path;

namespace ConsoleQuest {

	static bool IsNumeric(const std::string& input, int& output)
	{
		auto result = std::from_chars(input.data(), input.data() + input.size(), output);
		return result.ec == std::errc{};

	}

	static std::vector<Path> GetSaveGames()
	{
		//alle .save dateien laden
		std::vector<Path> files = std::vector<Path>();
		for (const std::filesystem::directory_entry& entry : std::filesystem::directory_iterator(fs::current_path()))
		{
			if (entry.is_regular_file() && entry.path().extension() == ".save")
			{
				files.push_back(entry.path());
			}
		}

		return files;
	}
}