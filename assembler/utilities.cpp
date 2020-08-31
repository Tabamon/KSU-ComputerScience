#include "utilities.hpp"

unsigned tmpc = 1;

String InfixToPostfix(String input){
    std::vector<String> splitString;
    splitString = input.split(' ');
    int i = 0;
    String right;
    String left;
    String oper;

    stack<String> stringStack;
    while(splitString[i] != ';'){

        if (splitString[i] == ')'){
            right = stringStack.pop();
            oper = stringStack.pop();
            left = stringStack.pop();
            right += ' ';
            left += ' ';

            stringStack.push(left + right + oper);

        }else{
            if (splitString[i]!='(') stringStack.push(splitString[i]);

        }
        i++;
    }

    return stringStack.top();
}

//===========================================================================

String PostfixToAssembly(String postfix, std::ostream &out){

    tmpc = 1;
    std::vector<String> splitPost = postfix.split(' ');
    stack<String> assemblyStack;
    String assembly, left, right;

    for (unsigned long int i=0; i < splitPost.size(); i++){

        if (splitPost[i]!='+' and splitPost[i]!='-' and splitPost[i]!='/' and splitPost[i]!='*'){
            assemblyStack.push(splitPost[i]);
        } else{
            right = assemblyStack.pop();
            left = assemblyStack.pop();
            String tmp = evaluate(left, splitPost[i], right, out);
            assemblyStack.push(tmp);
        }
    }

    return assemblyStack.pop();
}

//===========================================================================

String InfixToPrefix(String input){
    std::vector<String> splitString;
    splitString = input.split(' ');

    int i = 0;
    String right;
    String left;
    String oper;

    stack<String> stringStack;
    while(splitString[i] != ';'){

        if (splitString[i] == ')'){
            right = stringStack.pop();
            oper = stringStack.pop();
            left = stringStack.pop();
            oper += ' ';
            left += ' ';

            stringStack.push(oper + left + right);

        }else{
            if (splitString[i]!='(') stringStack.push(splitString[i]);

        }
        i++;
    }

    return stringStack.top();
}

//===========================================================================

String evaluate(String left, String t, String right, std::ostream &out){

    const String LD("LD\t");
    const String MU("MU\t");
    const String SB("SB\t");
    const String AD("AD\t");
    const String DV("DV\t");
    const String ST("ST\t");
    const String space("  ");
    String result;

    if (t == '*'){
        result = space + LD + "     " + left;
        result += '\n';
        result += space + MU + "     " + right;
        result += '\n';
        result += space + ST + "     " + makeTemp(tmpc++);
    }else if(t == '-'){
        result = space + LD + "     " + left;
        result += '\n';
        result += space + SB + "     " + right;
        result += '\n';
        result += space + ST + "     " + makeTemp(tmpc++);
    }else if(t == '/'){
        result = space + LD + "     " + left;
        result += '\n';
        result += space + DV + "     " + right;
        result += '\n';
        result += space + ST + "     " + makeTemp(tmpc++);
    }else if(t == '+'){
        result = space + LD + "     " + left;
        result += '\n';
        result += space + AD + "     " + right;
        result += '\n';
        result += space + ST + "     " + makeTemp(tmpc++);
    }
    result += '\n';
    out << result;
    return makeTemp(tmpc-1);
}

//===========================================================================


String PrefixToAssembly(String prefix, std::ostream &out){

    std::vector<String> splitPre = prefix.split(' ');
    stack<String> assemblyStack;
    String assembly, left, right;
    
    for (int i = splitPre.size()-1; i >= 0; i--){
        
        if (splitPre[i]!='+' and splitPre[i]!='-' and splitPre[i]!='/' and splitPre[i]!='*'){
            assemblyStack.push(splitPre[i]);
        } else{
            left = assemblyStack.pop();
            right = assemblyStack.pop();
            String tmp = evaluate(left, splitPre[i], right, out);
            assemblyStack.push(tmp);
        }
    }

    return assemblyStack.top();
}

String makeTemp(int n){

    const String temp("temp");
    String result = temp + intToString(n);
    return result;
}

String intToString(int n){

    char tmp[1000];
    sprintf(tmp, "%d", n);
    String output(tmp);
    return output;
}