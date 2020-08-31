//
//
// File:        logentry.cpp  
//       
// Version:     1.0
// Date:        
// Author:      
//
// Description: Class implementation for a log entry.
//
//

////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <cmath>

#include "string.hpp" 
#include "logentry.hpp"

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
LogEntry::LogEntry(String s) {
    // ...
    //std::cout<<"constructor 1"<<'\n';
    std::vector<String> logs = s.split(' ');
    host = logs[0];
    date = Date(logs[3]);
    time = Time(logs[3]);
    status = logs[8];
    number_of_bytes = countBytesFromString(logs[9]);
    logs = s.split('"');
    request = logs[1];
    //std::cout<<*this<<std::endl;
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
int countBytesFromString(String strByte){
    int result = 0;
    int j=0;
    if (strByte=='-') return result;
    
    for (int i=strByte.length()-1; i>=0; i--, j++){
        result = result + ((strByte[i]-'0')*pow(10,j));

    }
    
    return result;
}

std::vector<LogEntry> parse(std::istream& in) {
    std::vector<LogEntry> result;
    int i = 0;
    char buffer[1000];
    std::cout<<"parsing"<<'\n';
    while(!in.eof()){
        in.getline(buffer, 999, '\n');
        //if(in.eof()) {break;}
        String tmp(buffer);
        //std::cout<<buffer<<'\n';
        std::vector<String> tmpSplit = tmp.split(' ');
        //std::cout<<"after split"<<'\n';
        if (tmpSplit.size() == 10){
            //std::cout<<"inside if statement parse"<<'\n';
            LogEntry logTmp(tmp);
            result.push_back(logTmp);
            //std::cout<<logTmp;
            i++;
        }
    }
    return result;
}

std::ostream& operator<<(std::ostream& out, const LogEntry& log){
    out <<"host: "<<log.host<< " date: "<<log.date.getDay()
        << "/" << log.date.getMonth()<< "/" << log.date.getYear()
        << " Time: " << log.time.getHour()<<":"<<log.time.getMinute()
        << ":" << log.time.getSecond() << " request: " << log.request
        << " status: " << log.status << " bytes: " << log.number_of_bytes 
        << std::endl;
    return out;
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void output_all(std::ostream& out, const std::vector<LogEntry> &logs) {
    for (unsigned i = 0; i<logs.size(); i++) out << logs[i];
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
void by_host(std::ostream& out, const std::vector<LogEntry>& logs) {
    for (unsigned i = 0; i<logs.size(); i++) out << logs[i].getHost() <<'\n';
    return;
}

////////////////////////////////////////////////////////// 
// REQUIRES:  
// ENSURES: 
//
int byte_count(const std::vector<LogEntry> &logs) {
    int sum = 0;
    for (unsigned i = 0; i<logs.size(); i++){
        sum+=logs[i].getBytes();
    }
    return sum;
}