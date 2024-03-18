#include "BitcoinExchange.hpp"

void	ErrorMessage(const char* errorMessage, int errorCode)
{
	std::cerr << errorMessage << std::endl;
	std::exit(errorCode);
}

void	ReadDataFile(std::map<std::string, float>& BitcoinPriceHistory)
{
	std::ifstream					CSVfile("data.csv");
	std::string						line;

	std::getline(CSVfile, line);
	while (std::getline(CSVfile, line))
	{
		std::stringstream	sline(line);
		std::string			dateToken;
		std::string			priceToken;

		std::getline(sline, dateToken, ',');
		std::getline(sline, priceToken);
		BitcoinPriceHistory.insert(std::pair<std::string, float>
			(dateToken, std::atof(priceToken.c_str())));
	}
	CSVfile.close();
}

void	ReadClosedPositionsFile
	(std::map<std::string, float> BitcoinPriceHistory, std::ifstream& infile)
{
	std::string						line;

	std::getline(infile, line);
	while (getline(infile, line))
	{
		s_TransactionValues	TransactionValues = {0, 0, 0, false, false, ""};
		line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
		std::stringstream	sline(line);
		std::string			dateToken = "";
		std::string			volumeToken= "";

		std::getline(sline, dateToken, '|');
		parseDate(dateToken, TransactionValues.badDate);
		std::getline(sline, volumeToken);
		TransactionValues.volume = parseVolume(volumeToken, TransactionValues.badVolume);
		BTCpriceHistoryIt it = BitcoinPriceHistory.lower_bound(dateToken);
		if (!TransactionValues.badDate && !TransactionValues.badVolume) {
			if (it->first != dateToken && it != BitcoinPriceHistory.begin())
				it--;
			TransactionValues.priceReferenceDate = it->first;
			TransactionValues.exchangeRate = it->second;
			TransactionValues.total = TransactionValues.volume
									* TransactionValues.exchangeRate;
		}
		std::cout << closedPositionsPair(dateToken, TransactionValues) << std::endl;
	}
	infile.close();
}


std::ostream& operator<<(std::ostream& os,
	const std::pair<std::string, s_TransactionValues>& closedPositions)
{
	if (closedPositions.second.badDate)
		os << "Bad date -> \e[0;31m" << closedPositions.first << std::endl;
	else if (closedPositions.second.badVolume)
		os << "Bad volume -> \e[0;31m" << closedPositions.second.volume << std::endl;
	else {
	os	<< "Close time: " << closedPositions.first
		<< "\t |\tVolume: " << closedPositions.second.volume
		<< "\tExchange Rate: " << closedPositions.second.exchangeRate << "€"
		<< "\tTotal: " << closedPositions.second.total << "€"
		<< "\t Date of exchange rate reference: " << closedPositions.second.priceReferenceDate << std::endl;
	}
	os << "\033[0m";
	return (os); 
}

void	parseDate(std::string& date, bool& badDate)
{
	std::stringstream	sdate(date);
	std::string			tmp;
	char				*restYear;
	char				*restMonth;
	char				*restDay;

	std::getline(sdate, tmp, '-');
	int year = std::strtol(tmp.c_str(), &restYear, 10);
	std::getline(sdate, tmp, '-');
	int month = std::strtol(tmp.c_str(), &restMonth, 10);
	std::getline(sdate, tmp);
	int day = std::strtol(tmp.c_str(), &restDay, 10);
	if (year > 2024 || year < 2009 
	|| month < 1 || month > 12 
	|| day < 1 || day > 31
	|| *restDay || *restMonth || *restYear || bad_day(year, month, day))
		badDate = true;
}

inline float	parseVolume(std::string volume, bool& badVolume)
{
	char* rest;

	float f_volume = std::strtof(volume.c_str(), &rest);
	if (*rest != '\0' || f_volume < 0 || f_volume > 1000)
		badVolume = true;
	return (f_volume);
}

bool	bad_day(int year, int month, int day)
{
	int	months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (year % 4 == 0)
		months[1] = 29;
	if (day > months[month - 1])
		return (true);
	return (false);
}
