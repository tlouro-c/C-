#include "BitcoinExchange.hpp"

int	main(int argc, char* argv[]) {
	
	std::ifstream infile;
	if (argc != 2)
		ErrorMessage("usage: ./btc [closed positions file]", 1);
	infile.open(argv[1]);
	if (!infile.good())
		ErrorMessage("error: couldn't open file", 2);

	std::map<std::string, float> BitcoinPriceHistory;
	ReadDataFile(BitcoinPriceHistory);

	std::cout << "\n\e[1;96mYour closed positions\n\033[0m" << std::endl;
	try {
		ReadClosedPositionsFile(BitcoinPriceHistory, infile); }
	catch (...)
	{
		std::cerr << "bad input" << std::endl;
		infile.close();
		return (4);
	}
	return (0);
}
