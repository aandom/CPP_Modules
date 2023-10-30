/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aandom <aandom@student.abudhabi42.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:44:08 by aandom            #+#    #+#             */
/*   Updated: 2023/10/20 16:44:08 by aandom           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

const std::string WHITESPACE = " \n\r\t\f\v";

BitcoinExchange::BitcoinExchange(std::string infile) : _infile(infile) {
	parseInput();
	// std::cout << this->_data << std::endl;
	computeExhange();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) : _infile(src._infile), _data(src._data) {    
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & src) {
	if (this != &src) {
		this->_infile = src._infile;
		this->_data = src._data;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {
}

std::string *splitdate(std::string str, std::string sep) {
	std::string *splited = new std::string[3];

	size_t sepidx1 = str.find(sep, 0);
	size_t sepidx2 = str.find(sep, sepidx1 + 1);
	if (sepidx1 == std::string::npos || sepidx2 == std::string::npos)
	{
		delete [] splited;
		return ( new std::string(""));
		// return (0);
	}
	splited[0] = str.substr(0, sepidx1);
	splited[1] = str.substr(sepidx1 + sep.length(), sepidx2 - sepidx1 - 1);
	splited[2] = str.substr(sepidx2 + sep.length(), str.length() - sepidx2);
	return (splited);
}

bool    checkLeap(int year) {
	if  (year % 4 == 0 && year % 100 != 0)
		return (true); 
	if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0)
		return (true);
	return (false);
}

bool	isValidDate(int day, int month, int year) {
		int groups[4] = {4, 6, 9, 11};
	if (month == 2 && day > 29  )
		return (false);
	if ((month == 2 && day == 29) && !checkLeap(year))
		return (false);
	if (day == 31){
		for (int i = 0; i < 4; i++) {
			if (month == groups[i])
				return (false);
		}
	}
	return (true);
}

static std::string leftTrim(const std::string &s) {
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
static std::string rightTrim(const std::string &s) {
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

static std::string trimSpace(std::string str) {
	return (rightTrim(leftTrim(str)));	
}

static bool allDigits(std::string str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
		if (it == str.begin() && *it == '-')
			continue;
		else if (!std::isdigit(*it) && *it != '.') {
			return (false);
		}
	}
	return (true); 
}

int checkDatetwo(std::string inputdate) {
	std::string *splitedDate = splitdate(inputdate, "-");

	// if (!allDigits(trimSpace(splitedDate[0]))) {
	// 	return (delete [] splitedDate, 0);
	// }

	if (!allDigits(leftTrim(splitedDate[0]))) {
		return (delete [] splitedDate, 0);
	}

	// if ((!allDigits(trimSpace(splitedDate[1])))) {
	// 	return (delete [] splitedDate, 0);
	// }

	if ((!allDigits(splitedDate[1]))) {
		return (delete [] splitedDate, 0);
	}

	// if (!allDigits(trimSpace(splitedDate[2])))  {
	// 	return (delete [] splitedDate, 0);
	// }

	if (!allDigits(rightTrim(splitedDate[2])))  {
		return (delete [] splitedDate, 0);
	}
	
	return (delete [] splitedDate, 1);
}

time_t  extractDate(std::string inputdate) {
	if (!checkDatetwo(inputdate))
		return (-1);
	std::string *splitedDate = splitdate(inputdate, "-");
	if (splitedDate->empty()) {
		return (delete splitedDate, -1);
		return (-1);
	}

	int year = std::atoi( splitedDate[0].c_str() );
	if ( splitedDate[0].empty() || year <= 0 || year > 2024 ) {
		return (delete [] splitedDate, -1);
	}

	int month = std::atoi( splitedDate[1].c_str() );
	if ( splitedDate[1].empty() || month <= 0 || month > 12 ) {
		return (delete [] splitedDate, -1);
	}

	int day = std::atoi( splitedDate[2].c_str() );
	if ( splitedDate[2].empty() || day <= 0 || day > 31 ) {
		return (delete [] splitedDate, -1);
	}
	if (!isValidDate(day, month, year))
		return (delete [] splitedDate, -1);

	struct tm  timeinfo;
	bzero(&timeinfo, sizeof(timeinfo));
	timeinfo.tm_year = year - 1900;
	timeinfo.tm_mon = month - 1;
	timeinfo.tm_mday = day;

	return (delete [] splitedDate, mktime( &timeinfo ));
}

static bool checkValue(std::string const & str) {
	if (str.empty() || str.length() == 0)
		return (false);
	std::string trimed = trimSpace(str);
	int dotcount = std::count(str.begin(), str.end(), '.');
	if ((dotcount > 1) || !allDigits(trimed))
		return (false);
	return (true);
}



static double  extractValue(std::string inputval) {
	if (!checkValue(inputval))
		return (-2);
	double val = std::strtod(inputval.c_str(), NULL);
	if (val < 0 ) {
	   return (-1);
	}
	if (val > std::numeric_limits<int>::max()) {
	   return (-3);
	}
	return (val);
}

static std::string *splitstr(std::string str, std::string sep) {
	std::string *splited = new std::string[2];

	std::string newstr = trimSpace(str);
	size_t sepidx = newstr.find(sep, 0);
	if (sepidx == std::string::npos) {
		delete [] splited;
		return (0);
	}
	splited[0] = newstr.substr(0, sepidx);
	splited[1] = newstr.substr(sepidx + 1,  newstr.length() - sepidx - 1);
	return (splited);
}

static void	checkHeaderAndSkip(std::string line, std::string sep, std::string filename, int code) {
	std::string *splited = splitstr(line, sep);
	std::string errmsg;
	if (!splited) {
		errmsg = "Error: Empty " + filename +  " file or Empty " + filename + " header";
		throw (std::runtime_error(errmsg));
	}
	if (code == 1 &&  (trimSpace(splited[0]) != "date" || trimSpace(splited[1]) != "exchange_rate")) {
		delete [] splited;
		errmsg = "Error: Invalid " + filename +  " header.";
		throw (std::runtime_error(errmsg));
	}
	if (code == 2 &&  (trimSpace(splited[0]) != "date" || trimSpace(splited[1]) != "value")) {
		delete [] splited;
		errmsg = "Error: Invalid " + filename +  " header.";
		throw (std::runtime_error(errmsg));
	}
	delete [] splited;
}

void BitcoinExchange::parseInput() {
	std::fstream	myfile;
	std::string		line;
	time_t			date;
	double			value;
	std::string		*splited;

	myfile.open("./data.csv", std::fstream::in);
	if (myfile.fail())
		throw ( std::runtime_error( "Couldn't open data.csv file" ) );
	std::getline(myfile, line);
	checkHeaderAndSkip(line, ",", "data.csv", 1);
	while (std::getline(myfile, line)) {
		splited = splitstr(line, ",");
		if(!splited) {
			throw ( std::runtime_error( "Invalid data" ) );
		}
		date = extractDate(splited[0]);
		if (date == -1) {
			std::string err = "Error: bad input in the .csv file => " + splited[0];
			delete [] splited;
			throw std::runtime_error(err);
		}
		value = extractValue(splited[1]);
		if (value < 0) {
			std::string err = "Error: bad input in the .csv file => " + splited[1];
			delete [] splited;
			throw std::runtime_error(err);
		}
		delete [] splited;
		this->insertToMap(date, value);
	}
}

void   BitcoinExchange::insertToMap(time_t date, double value) {
	std::map<time_t, double>::iterator it = this->_data.find(date);
	if (it != this->_data.end()) {
		it->second = value;
	}
	else
		this->_data.insert(std::pair<time_t, double>(date, value));
}

time_t  BitcoinExchange::findNearestDate(time_t date) {
	std::map<time_t, double>::iterator it = _data.find( date );
	if ( date < _data.begin()->first ) {
		return ( _data.begin()->first );
	}

	for ( int i = 0; it == _data.end(); i++ ) {
		time_t newDate = date - i * 24 * 60 * 60;
		it = _data.find( newDate );
	}
	return ( it->first );
}

void	BitcoinExchange::displayeCalculatedRate(time_t date, double value) {
	time_t key = findNearestDate(date);
	struct tm* timeinfo = localtime(&date);

	char buffer[80];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
	// std::streamsize ss = std::cout.precision();
			
	std::cout << buffer << "   =>  ";
	std::cout << value << " \t= ";
	// std::cout << std::fixed;
	// std::cout.precision( 2 );
	std::cout << _data[key] * value <<  std::endl;
	// std::cout << std::setprecision(ss);


}

void    BitcoinExchange::computeExhange() {
	std::fstream	inputfile;
	std::string		line;
	std::string		*splited;

	inputfile.open(_infile.c_str(), std::fstream::in);
	if (inputfile.fail())
		throw ( std::runtime_error( "Couldn't open input.txt file" ) );
	std::getline(inputfile, line);
	checkHeaderAndSkip(line, "|", _infile, 2);
	while (std::getline(inputfile, line)) {
		splited = splitstr(line, "|");
		if(!splited) {
			std::cout << YELLOW << "Error: bad input => " << line <<  RESET << std::endl;
		}
		else {
			time_t date = extractDate(splited[0]);
			double value = extractValue(splited[1]);
			if (!checkDatetwo(splited[0]))
				std::cout << YELLOW << "Error: bad input => " << splited[0] << RESET << std::endl;
			else if (date != -1 && value >= 0)
				displayeCalculatedRate(date, value);
			else if (date == -1 || value == -2)
				std::cout << YELLOW << "Error: bad input => " << splited[0] << RESET << std::endl;
			else if (value == -1)
				std::cout << YELLOW << "Error: not a positive number. => " << splited[1] << RESET << std::endl;
			else if (value == -3)
				std::cout << YELLOW << "Error: too large a number. => " << splited[1] << RESET << std::endl;
			delete [] splited;
		}
	}
}

std::ostream& operator<<(std::ostream& os, std::map<long, double>& obj) {
	os << "[ ";
	for (std::map<long, double>::const_iterator it = obj.begin(); it != obj.end(); ++it) {
		struct tm* timeinfo = localtime(&it->first);
		
		char buffer[80];
		strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);

		os << buffer << " " << it->second << std::endl;
	}
	os << "]";
	return os;
}
