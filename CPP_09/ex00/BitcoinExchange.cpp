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


time_t  extractDate(std::string inputdate) {
    std::string *splitedDate = new std::string[3];

    splitedDate = splitdate(inputdate, "-");
    if (splitedDate->empty()) {
        std::cout << "invalid date_2" << std::endl;
        exit(1);
    }

    int year = std::atoi( splitedDate[0].c_str() );
	if ( splitedDate[0].empty() || year < 0 || year > 2050 ) {
		throw std::out_of_range( inputdate + ": invalid date" );
	}

    int month = std::atoi( splitedDate[1].c_str() );
	if ( splitedDate[1].empty() || month < 0 || month > 12 ) {
		throw std::out_of_range( inputdate + ": invalid date" );
	}

    int day = std::atoi( splitedDate[2].c_str() );
	if ( splitedDate[2].empty() || day < 0 || day > 31 ) {
		throw std::out_of_range( inputdate + ": invalid date" );
	}
	
    struct tm  timeinfo;
    bzero(&timeinfo, sizeof(timeinfo));
    timeinfo.tm_year = year - 1900;
    timeinfo.tm_mon = month - 1;
    timeinfo.tm_mday = day;

    time_t date = mktime( &timeinfo );
    return (date);
}

double  extractValue(std::string inputval) {
    double val = std::strtod(inputval.c_str(), NULL);
    if (val < 0 ) {
        std::cout << "Error: not a positive number" << std::endl;
        exit (1);
    }
    if (val > std::numeric_limits<int>::max()) {
        std::cout << "Error: too large a number." << std::endl;
        exit (1);
    }
    return (val);
}

std::string *splitstr(std::string str, std::string sep) {
    std::string *splited = new std::string[2];

    size_t sepidx = str.find(sep, 0);
    if (sepidx == std::string::npos)
    {
        delete [] splited;
        // return ("");
        return new std::string("");
    }
    splited[0] = str.substr(0, sepidx);
    splited[1] = str.substr(sepidx + sep.length(), str.length());
    return (splited);
}

// void    validateStr(std::string * splited) {
//     if (splited->empty())
//         throw ( std::runtime_error( "Invalid data" ))
//     for (size_t i = 0; i < 2; i++)
//     {
        
//     }
    
    
// }


static bool    checkInput(std::string const & str) {

    if (str.empty() || str.length() == 0)
        return (false);
    for (std::string::const_iterator it = str.begin(); it != str.end() ; it++) {
        if (!std::isdigit(*it))
            return (false);
    }
    return (true);
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
        double value = extractValue(splited[1]);
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
            std::cout << "invalid date_1" << std::endl;
        }
        else {
            time_t date = extractDate(splited[0]);
            double value = extractValue(splited[1]);
            time_t key = findNearestDate(date);

            struct tm* timeinfo = localtime(&key);
        
            char buffer[80];
            strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);
            	    
            std::cout << buffer << " -> ";
            std::cout << std::fixed;
            std::cout.precision( 2 );
            std::cout << _data[key] * value << std::endl;
        }
        // this->insertToMap(date, value);
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







