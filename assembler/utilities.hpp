#ifndef UTILS
#define UTILS 10
#include "stack.hpp"
#include "../string/string.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>


String InfixToPostfix(String input);
String PostfixToAssembly(String postfix, std::ostream &out);
String evaluate(String left, String t, String right, std::ostream &out);
String InfixToPrefix(String input);
String PrefixToAssembly(String prefix, std::ostream &out);
String makeTemp(int n);
String intToString(int n);

#endif