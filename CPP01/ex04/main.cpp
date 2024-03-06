#include <iostream>
#include <string>
#include <fstream>
#include <sstream>  

int	main(int argc, char *argv[])
{
	std::string	line;
	std::string	needle;
	std::string	replaceString;
	std::string	output_filename;

	if (argc != 4)
		return (std::cerr << "Invalid number of arguments" << std::endl, 1);
	std::ifstream inputFile(argv[1]);
	if (!inputFile)
		return (std::cerr << argv[1] << ": Unable to open file" << std::endl, 1);
	needle = argv[2];
	if (needle.empty())
	{
		std::cerr << "Don't try to break me :c" << std::endl;
		inputFile.close();
		return (1);
	}
	replaceString = argv[3];
	output_filename = static_cast<std::string>(argv[1]) + ".replace";
	std::ofstream replaceFile(output_filename.c_str());
	while (!inputFile.eof())
	{
		std::getline(inputFile, line);
		for (int i = line.find(needle, 0); i != static_cast<int>(line.npos);
			i = line.find(needle, i + replaceString.length()))
		{
			line.erase(i, needle.size());
			line.insert(i, replaceString);
		}
		replaceFile << line << std::endl;
	}
	replaceFile.close();
	inputFile.close();
	return (0);
}
