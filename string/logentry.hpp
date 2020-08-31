#ifndef CS_LOGENTRY_H_
#define CS_LOGENTRY_H_

////////////////////////////////////////////////////////////
//
// File:        logentry.hpp 
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class definition for a log entry.
//
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>

#include "string.hpp" 

////////////////////////////////////////////////////////////
class Date { 
public:
    Date() {
        day = "";
        month = "";
        year = 0;

    }
    Date(String dateTime){

        std::vector<String> strArr;
        strArr = dateTime.split('/');
        day = strArr[0].substr(1,2);
        month = strArr[1];
        year=(strArr[2][0]-'0')*1000+(strArr[2][1]-'0')*100+(strArr[2][2]-'0')*10+(strArr[2][3]-'0');
        
    }
    String getDay() const{
        return day;
    };
    String getMonth() const{
        return month;
    };
    int getYear() const{
        return year;
    };

private:
    String day, month;
    int year;
};

////////////////////////////////////////////////////////////
class Time {
  public:
    Time() {};
    Time(String dateTime){

        std::vector<String> strArr= dateTime.split('/');
        String timeStr = strArr[2];
        hour=(timeStr[5]-'0')*10+(timeStr[6]-'0');
        minute=(timeStr[8]-'0')*10+(timeStr[9]-'0');
        second=(timeStr[11]-'0')*10+(timeStr[12]-'0');

    }
    int getHour()const{
        return hour;
    }
    int getMinute()const{
        return minute;
    }
    int getSecond()const{
        return second;
    }
  private:
    int hour, minute, second;
};


////////////////////////////////////////////////////////////
class LogEntry {
public:
    LogEntry() {};
    LogEntry(String);
    friend  std::ostream& operator<<(std::ostream&, const LogEntry&);
    String getHost() const{
        return host;
    }
    int getBytes()const{
        return number_of_bytes;
    }
private:
    String host;
    Date date;
    Time time;
    String request;
    String status;
    int number_of_bytes;
};


////////////////////////////////////////////////////////////
//
// Free functions
//

std::vector<LogEntry> parse(std::istream&);
void output_all (std::ostream&, const std::vector<LogEntry> &);
void by_host (std::ostream&, const std::vector<LogEntry> &);
int byte_count (const std::vector<LogEntry>&);
int countBytesFromString(String strByte);

#endif

