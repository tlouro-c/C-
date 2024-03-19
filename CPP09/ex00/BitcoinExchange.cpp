#include "BitcoinExchange.hpp"

void	ErrorMessage(const char* errorMessage, int errorCode)
{
	std::cerr << errorMessage << std::endl;
	std::exit(errorCode);
}

void	ReadDataFile(std::map<int, float>& BitcoinPriceHistory)
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
		BitcoinPriceHistory.insert(std::pair<int, float>
			(dateToValue(dateToken), std::atof(priceToken.c_str())));
	}
	CSVfile.close();
}

void	ReadClosedPositionsFile
	(std::map<int, float> BitcoinPriceHistory, std::ifstream& infile)
{
	std::string						line = "";

	std::getline(infile, line);
	if (line != "date | value")
		throw "bad header";
	line.clear();
	while (getline(infile, line))
	{
		if (line.empty() || line.find_first_not_of("\f\n\r\t\v ") == line.npos)
			continue ;
		s_TransactionValues	TransactionValues = {0, 0, 0, false, false, ""};
		line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
		std::stringstream	sline(line);
		std::string			dateToken = "";
		std::string			volumeToken= "";

		std::getline(sline, dateToken, '|');
		parseDate(dateToken, TransactionValues.badDate);
		std::getline(sline, volumeToken);
		TransactionValues.volume = parseVolume(volumeToken, TransactionValues.badVolume);
		BTCpriceHistoryIt it = BitcoinPriceHistory.lower_bound(dateToValue(dateToken));
		if (!TransactionValues.badDate && !TransactionValues.badVolume
			&& it != BitcoinPriceHistory.end()) {
			if (it->first != dateToValue(dateToken) && it != BitcoinPriceHistory.begin())
				it--;
			TransactionValues.priceReferenceDate = valueToDate(it->first);
			TransactionValues.exchangeRate = it->second;
			TransactionValues.total = TransactionValues.volume
									* TransactionValues.exchangeRate;
		}
		std::cout << closedPositionsPair(dateToken, TransactionValues) << std::endl;
		line.clear();
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
	std::istringstream	sdate(date);
	int year = 0, month = 0, day = 0;
	char sep1, sep2, tmp;

	if (!(sdate >> year >> sep1 >> month >> sep2 >> day) || sdate >> tmp
		|| sep1 != '-' || sep2 != '-' || year > 2024 || year < 2009
		||  month < 1 || month > 12 || bad_day(year, month, day)) {
			badDate = true;
	}
}

inline float	parseVolume(std::string volume, bool& badVolume)
{
	char* rest;

	float f_volume = std::strtof(volume.c_str(), &rest);
	if (*rest != '\0' || f_volume <= 0 || f_volume > 1000)
		badVolume = true;
	return (f_volume);
}

bool	bad_day(int year, int month, int day)
{
	int	months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (year % 4 == 0)
		months[1] = 29;
	if (day > months[month - 1] || day < 1)
		return (true);
	return (false);
}

int	dateToValue(const std::string& date)
{
	std::istringstream	sdate(date);
	int year = 0, month = 0, day = 0;
	char sep1, sep2;

	sdate >> year >> sep1 >> month >> sep2 >> day;
	return (year * 10000 + month * 100 + day);
}

std::string valueToDate(const int& dateValue)
{
	std::ostringstream osdate;

	int year = dateValue / 10000;
	osdate << year << '-';

	int month = (dateValue % 10000) / 100;
	if (month < 10)
		osdate << '0';
	osdate << month << '-';

	int day = dateValue % 100;
	if (day < 10)
		osdate << '0';
	osdate << day;

	return osdate.str();
}

