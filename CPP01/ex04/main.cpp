#include <iostream>
#include <string>
#include <fstream>

int	main(int argc, char *argv[])
{
	std::string	line;
	std::string	needle;
	std::string	replaceString;

	if (argc != 4)
		return (std::cerr << "Invalid number of arguments" << std::endl, 1);
	std::ifstream inputFile(argv[1]);
	if (!inputFile)
		return (std::cerr << argv[1] << ": Unable to open file" << std::endl, 1);
	needle = argv[2];
	replaceString = argv[3];
	std::ofstream replaceFile(static_cast<std::string>(argv[1]) + ".replace");
	while (!inputFile.eof())
	{
		std::getline(inputFile, line);
		for (int i = line.find(needle); i != static_cast<int>(std::string::npos); i = line.find(needle))
		{
			line.erase(i, needle.size());
			line.insert(i, replaceString);
		}
		replaceFile << line << std::endl;
	}
	replaceFile.close();
	inputFile.close();
	return 0;
}
