#include "bigint.hpp"
#include <iostream>


bigint bigint::operator!(){
    bigint i(1);
    bigint fact(1);
    while(!(*this+1==i)){
        fact = fact * i;
        i = i + 1;
    }

    return fact;
}

int main(void){
    bigint big(100);
    bigint fact = !big;
    int zeros = 0;
    int trailZeros = 0;
    int lastChar=0;
    for (unsigned i = 0; i<CAPACITY; i++){
        if(fact[i]!=0) lastChar = i;
    }
    for (int i = lastChar; i>=0; i--){
        if(fact[i]==0) zeros++;
    }
    int i = 0;
    while (fact[i++]==0) trailZeros++;

    std::cout << big << "! = " << fact << "\twith:" << zeros << " zeros in it, "<< trailZeros << " of them are trailing zeros\n\n" << std::endl;
    std::cout << "The easyest way to calculate it was through making a factorial operator, by multiplying the bigint from 1 all the way up to its value by increments of "
              << "1 and then calculating the zeros by counting how many were in the index once the numbers started."
              << "\nAnother way we could mathematically calculate the zeros would be counting how many 2 and 5 digits there are between 1 and the bigint value, in the case of 100"
              << " the values with five are 24 given by 100/5 and 100/(5^2) the same process is done for the two and they yeld 97 and 24, so the trailing zeros are 24.\n";
}