#include "string.hpp"
#include <iostream>
#include <cassert>

String::String(){
    str[0]=END;
}

String::String(char ch){
    str[0]=ch;
    str[1]=END;
}

String::String(const char c_str[]){
    int i = 0;
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
    return STRING_SIZE-1;
}

int String::length() const{
    int i = 0;
    while (str[i]!=END) i++;
    return i;
}

String String::operator+(const String & str2) const{
    String result(getArr());
    if (length()+str2.length() > STRING_SIZE){
        std::cerr << "strings are too long\n";
        return *this;
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
    bool flag = true;
    if (length()!=str2.length()){
        flag = false;
    }else{
    for (int i = 0; i < length(); i++){
        if (str2[i]!=str[i]) flag = false;
        //std::cerr<< flag << '\n';
    }
    }
    return flag;
}

bool String::operator<(const String &str2) const{

    int i = 0;

    //if (min>str2.length()) min = str2.length();
    if (str2 == *this) return false;
    if (str2[i]==END&&i==0) return false;
    while (i <= length()){
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
    char tmpChar;
	in >> tmpChar;
    while(in && tmpChar != ' ' && tmpChar != '\n' && tmpChar != '\t' && tmpChar != '\r'){
        //std::cout<<tmpChar<<std::endl;
        str2 += tmpChar;
        in.get(tmpChar);
    }
    std::cout<<str2<<'\n';
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
    String sub(int(end-start));
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
    else{
        for (int i = pos; i<=length(); i++){
            if (ch==str[i]){ 
                res = i;
                return res;
            }
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
        if (tmp == str2){ 
            res = i;
            return res;
        }
    }
    return res;
}

String& String::operator+=(const String &str2){
    *this = *this + str2;
    return *this;
}
