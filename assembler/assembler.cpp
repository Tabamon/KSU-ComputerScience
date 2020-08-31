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
    bool postfix = true;

    if (argc == 2){

        in.open(argv[1]);
        if (in.is_open()==false){
            std::cerr<<"Could not open file"<<std::endl;
            return -1;
        }
        screenFlag = true;
    }else if (argc == 3){

        in.open(argv[1]);
        String arg(argv[2]);
        if (arg=="prefix"){
            postfix=false;
            screenFlag = true;
        }else{
            out.open(argv[2]);
        }
    }else if (argc == 4){
        String arg(argv[3]);
        if (arg=="prefix"){
            postfix=false;
        }
        in.open(argv[1]);
        out.open(argv[2]);
    }else{
        std::cerr<<"wrong arguments"<<std::endl;
        return -1;
    }

    String infixExpression;
    String postfixExpression;
    String prefixExpression;
    String AssemblyExpression;

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
        if (postfix){
            postfixExpression = InfixToPostfix(infixExpression);
            if (screenFlag == true){
                AssemblyExpression = PostfixToAssembly(postfixExpression, std::cout);
                std::cout<<"========================"<<std::endl;
            }else{
                AssemblyExpression = PostfixToAssembly(postfixExpression, out);
                out<<"========================"<<std::endl;
            }
        }else{
            prefixExpression = InfixToPrefix(infixExpression);
            std::cout<<prefixExpression<<std::endl;
            if (screenFlag == true){
                AssemblyExpression = PrefixToAssembly(prefixExpression, std::cout);
                std::cout<<"========================"<<std::endl;
            }else{
                AssemblyExpression = PrefixToAssembly(prefixExpression, out);
                out<<"========================"<<std::endl;
            }
        }
    }

    in.close();
    if (screenFlag == false){
        out.close();
    }

    return 0;
}