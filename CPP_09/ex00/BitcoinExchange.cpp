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
		return (0);
	}
	splited[0] = str.substr(0, sepidx1);
	splited[1] = str.substr(sepidx1 + sep.length(), sepidx2);
	splited[2] = str.substr(sepidx2 + sep.length(), str.length());
	return (splited);
}

bool    checkLeap(int year) {
	if  (year % 4 == 0 && year % 100 != 0)
		return (true); 
	if (year % 4 == 0 && year % 100 == 0 && year % 400 == 0)
		return (true);
	return (false);
	
}

time_t  extractDate(std::string inputdate) {
	std::string *splitedDate = new std::string[3];

	splitedDate = splitdate(inputdate, "-");
	if (splitedDate->empty()) {
		return (-1);
	}

	int year = std::atoi( splitedDate[0].c_str() );
	if ( splitedDate[0].empty() || year < 0 || year > 2024 ) {
		return (-1);
	}

	int month = std::atoi( splitedDate[1].c_str() );
	if ( splitedDate[1].empty() || month <= 0 || month > 12 ) {
		return (-1);
	}

	int day = std::atoi( splitedDate[2].c_str() );
	if ( splitedDate[2].empty() || day <= 0 || day > 31 ) {
		return (-1);
	}
	if (month == 2 && day > 29  ) {
		return (-1);
	}

	if (month == 2 && day == 29) {
		if (!checkLeap(year))
			return (-1);
	}
	
	struct tm  timeinfo;
	bzero(&timeinfo, sizeof(timeinfo));
	timeinfo.tm_year = year - 1900;
	timeinfo.tm_mon = month - 1;
	timeinfo.tm_mday = day;

	time_t date = mktime( &timeinfo );
	return (date);
}

const std::string WHITESPACE = " \n\r\t\f\v";
 
std::string leftTrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}
 
std::string rightTrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim_sp(std::string str) {

	std::string trimed = rightTrim(leftTrim(str));

	std::string whitespaces (" \t\f\v\n\r");
	return (trimed);
	
}

bool allDigits(std::string str) {
    for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
		if (it == str.begin() && *it == '-')
			continue;
		else if (!std::isdigit(*it) && *it != '.') {
			return (false);
		}
	}
	return (true); 
}


static bool checkValue(std::string const & str) {
	if (str.empty() || str.length() == 0)
		return (false);
	std::string trimed = trim_sp(str);
	int dotcount = std::count(str.begin(), str.end(), '.');
	if ((dotcount > 1) || !allDigits(trimed))
		return (false);
	return (true);
}



double  extractValue(std::string inputval) {
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

std::string *splitstr(std::string str, std::string sep) {
	std::string *splited = new std::string[2];

	std::string newstr = trim_sp(str);

	size_t sepidx = newstr.find(sep, 0);
	if (sepidx == std::string::npos)
	{
		delete [] splited;
		// return ("");
		return new std::string("");
	}
	splited[0] = newstr.substr(0, sepidx);
	splited[1] = newstr.substr(sepidx + 1,  newstr.length());
	return (splited);
}


void BitcoinExchange::parseInput() {
	std::fstream myfile;
	myfile.open("./data.csv", std::fstream::in);
	if (myfile.fail())
		throw ( std::runtime_error( "Couldn't open data file" ) );
	std::string line;
	std::string *splited;
	std::getline(myfile, line);
	splited = splitstr(line, ",");
	if (splited[0] != "date" || splited[1] != "exchange_rate") {
		delete [] splited;
		throw (std::runtime_error( "Invalid data.csv header."));
	}
	delete [] splited;
	while (std::getline(myfile, line)) {
		splited = splitstr(line, ",");
		if(splited[0].empty() || splited[1].empty()) {
			 throw ( std::runtime_error( "Invalid data" ) );
			exit(1);
		}
		time_t date = extractDate(splited[0]);
		if (date == -1) {
			std::string err = "Error: bad input in the .csv file => " + splited[0];
			delete [] splited;
			throw std::runtime_error(err);
		}
		double value = extractValue(splited[1]);
		if (value < 0) {
			std::cout << "val : " << value << std::endl;
			std::string err = "Error: bad input in the .csv file => " + splited[1];
			delete [] splited;
			throw std::runtime_error(err);
		}
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

void    BitcoinExchange::computeExhange() {
	std::fstream inputfile;
	inputfile.open(_infile.c_str(), std::fstream::in);
	if (inputfile.fail())
		throw ( std::runtime_error( "Couldn't open input.txt file" ) );
	
	std::string line;
	std::string *splited;
	std::getline(inputfile, line);
	while (std::getline(inputfile, line)) {
		splited = splitstr(line, "|");
		if(splited->empty()) {
			std::cout << "Error: bad input => " << line << std::endl;
		}
		else {

			time_t date = extractDate(splited[0]);
			double value = extractValue(splited[1]);
			if (date != -1 && value >= 0) {
				time_t key = findNearestDate(date);
				struct tm* timeinfo = localtime(&date);
			
				char buffer[80];
				strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
						
				std::cout << buffer << " -> ";
				std::cout << std::fixed;
				std::cout.precision( 2 );
				std::cout << _data[key] * value <<  std::endl;
			}
			else if (date == -1 || value == -2) {
				std::cout << "Error: bad input => " << splited[0] << std::endl;
			}
			else if (value == -1) {
				std::cout << "Error: not a positive number. => " << splited[1] << std::endl;
			}
			else if (value == -3) {
				std::cout << "Error: too large a number. => " << splited[1] << std::endl;
			}
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







