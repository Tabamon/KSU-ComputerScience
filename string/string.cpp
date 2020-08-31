#include "string.hpp"
#include <iostream>
#include <cassert>
#include <vector>

String::String(){
    str = new char [1];
    stringSize=1;
    str[0]=END;
}

String::String(int size){
    str = new char [size+1];
    stringSize = size+1;
    str[0]=END;
}

String::~String(){
    //std::cout << "B" << std::endl;
    delete[] str;
    //std::cout << "A" << std::endl;
}

String::String(int size, const char cStr[]){
    int i = 0;
    str = new char [size+1];
    stringSize = size+1;
    while (cStr[i] != 0){
        str[i]=cStr[i];
        i++;
    }
    str[i]=END;
}

String::String(String const& str2) {//:String(str2.getArr()){
    stringSize = str2.stringSize;
    str = new char[stringSize];
    for(int i = 0; i < stringSize; ++i) {
        str[i] = str2.str[i];
    }
    str[stringSize-1] = 0;
}

String& String::operator=(String str2){
  if(str==str2.str)return*this;
  delete[] str;
  stringSize=str2.stringSize;
  str= new char[stringSize];
  for(int i=0; i<stringSize; ++i)
    str[i]=str2[i];
  return *this;
}

String::String(char ch):String(1){
    str[0]=ch;
    str[1]=END;
}



String::String(const char c_str[]){
    int i = 0;
    
    while (c_str[i]!=END){
        i++;
    }
    ++i;
    str = new char [i];
    stringSize = i;
    //std::cerr<<capacity()<<'\n';
    i=0;
    while (c_str[i]!=END){
        str[i]=c_str[i];
        i++;
    }
    str[i]=END;
}

char & String::operator[](int i){
    return str[i];
}

char String::operator[](int i) const{
    return str[i];
}

int String::capacity() const{
    return stringSize-1;
}

int String::length() const{
    int i = 0;
    while (str[i]!=END) i++;
    return i;
}

String String::operator+(const String & str2) const{
    String result(int(length()+str2.length()));
    
    for(int i = 0; i<length(); i++){
        result[i]=str[i];
    }
    int i = 0;
    int j = length();
    for (i = 0; str2[i]!=END; i++, j++){
        result[j]=str2[i];
    }
    result[j]=END;
    return result;
}

bool String::operator==(const String &str2) const{
    if (length()!=str2.length()){
        //std::cerr<<"len!="<<'\n';
        return false;
    }else{
    for (int i = 0; i < length(); i++){
        if (str2[i]!=str[i]) return false;
        //std::cerr<< flag << '\n';
    }
    }
    return true;
}

bool String::operator<(const String &str2) const{

    int i = 0;
    int min = length();

    if (min>str2.length()) min = str2.length();

    while (i <= min){
        if(str[i]<str2[i])return true;
        else if (str[i]==str2[i])++i;
        else return false;
    }
    if (str2[i]==END) return false;
    return true;
}

std::ostream &operator<<(std::ostream & out, const String &str2){

    int i=0;
    while(str2[i]!=0){
        out<<str2[i];
        ++i;
    }
    return out;
}

std::istream& operator>>(std::istream& in, String& str2)
{
    String tmp;
    char tmpChar;
	in >> tmpChar;
    while(in && tmpChar != ' ' && tmpChar != '\n' && tmpChar != '\t' && tmpChar != '\r'){
        //std::cout<<tmpChar<<std::endl;
        tmp += tmpChar;
        in.get(tmpChar);
    }
    str2.swap(tmp);
    //std::cout<<str2<<'\n';
    return in;
}

String operator+(const char arr[], const String &str2){
    String result(str2.getArr());
    String tmp(arr);
    result += tmp;
    return result;
}

const char* String::getArr() const{
    return str;
}

String operator+(char ch, const String &str2){
    String tmp(ch);
    String result(str2.getArr());
    result = result+tmp;
    return result;
}

bool operator==(const char c_str[], const String &str2)
{
    String str3(c_str);
    return (str2 == str3);
}

bool operator==(char ch, const String &str2){
    String str3(ch);
    return (str3 == str2);
}

bool operator<(const char cStr[], const String &str2){
    String str3(cStr);
    return (str3<str2);
}

bool operator<(char ch, const String &str2){
    String str3(ch);
    return (str3<str2);
}

bool operator<=(const String &str2, const String &str3){
    return ((str2<str3)||(str2==str3));
}

bool operator!=(const String &str2, const String &str3){
    return (!(str2==str3));
}

bool operator>=(const String &str2, const String &str3){
    return (!(str2<str3));
}

bool operator>(const String &str2, const String &str3){
    return (!(str2<=str3));
}

String String::substr(int start, int end) const{
    String empty;
    if (start>end) return empty;
    String sub(int(end-start+1));
    int j=0;
    for (int i = start; i<=end; i++, j++){
        sub[j]=str[i];
    }
    sub[j]=END;
    return sub;
}

int String::findch(int pos, char ch) const{
    int res = -1;
    if (pos>length()) return res;
    for (int i = pos; i<=length(); i++){
        if (ch==str[i]){ res = i;
            return res;
        }
    }
    return res;
}

int String::findstr(int pos, const String& str2) const{
    int res = -1;
    if (pos>length()) return res;
    for (int i = pos; i<length(); i++){
        String tmp;
        tmp = substr(i, i+str2.length()-1);
        //std::cout<<tmp << "    " <<str2<<std::endl;
        if (str2 == tmp){
            res = i;
            return res;
        }
    }
    return res;
}

String& String::operator+=(const String &str2){
    
    return *this = *this + str2;
}

void String::swap(String& str2){
    char * ptrTmp = str2.str;
    str2.str = str;
    str = ptrTmp;

    int sizeTmp = str2.stringSize;
    str2.stringSize = stringSize;
    stringSize = sizeTmp;
}

void String::resetCapacity (int newCap){

    char * tmp = nullptr;
    tmp = new char[newCap];
    int i = 0;
    for (i = 0; i<length()&&i<newCap; i++){
        tmp[i]=str[i];
    }
    tmp[i]=END;
    delete[] str;
    str = new char[newCap];
    for (i = 0; i<length()&&i<newCap; i++){
        str[i]=tmp[i];
    }
    str[i]=END;
    return;
}

std::vector<String> String::split(char splitChar) const{

    std::vector<String> result;
    String empty;
    int lastSplit=0;
    for (int i = 0; i<=length(); i++){
        if (str[i]==splitChar || i == length()){
            if (lastSplit-i == 0){
                result.push_back(empty);
            }else{
                String tmp = substr(lastSplit,i-1);
                //std::cout<<tmp<<'\n';
                result.push_back(tmp);
            }
            lastSplit = i+1;
        }
    }

    return result;
}