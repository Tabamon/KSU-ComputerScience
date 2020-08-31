#include<iostream>
#include<fstream>
#include "../string/string.hpp"
#include "stack.hpp"
#include "utilities.hpp"
//FILE: postfix.cpp
//Lorenzo Toscano
//CS2 Lab Project Assembler
//=====================================================

int main(int argc, char **argv){
    std::ifstream in;
    std::ofstream out;
    bool screenFlag = false;
    if (argc == 2){

        in.open(argv[1]);
        if (in.is_open()==false){
            std::cerr<<"Could not open file"<<std::endl;
            return -1;
        }
        screenFlag = true;
    }else if (argc == 3){

        in.open(argv[1]);
        out.open(argv[2]);
    }else{
        std::cerr<<"wrong arguments"<<std::endl;
        return -1;
    }

    String infixExpression;
    String postfixExpression;

    while(!in.eof()){
        infixExpression = String();
        String tmpStr;
        in >> tmpStr;
        if(in.eof()) break;
        while(tmpStr != ';' && !in.eof()){
            infixExpression += tmpStr;
            infixExpression += ' ';
            in>>tmpStr;
        }

        infixExpression += tmpStr;
        postfixExpression = InfixToPostfix(infixExpression);
        if (screenFlag == true){
            std::cout<<postfixExpression<<std::endl;
        }else{
            out<<postfixExpression<<'\n';
        }
    }

    in.close();
    if (screenFlag == false){
        out.close();
    }

    return 0;
}