#include "bigint.hpp"
#include <iostream>

void bigint::zero() //turn entire index[] to 0
{
  for (unsigned i = 0; i < CAPACITY; ++i) index[i] = 0;
}

bigint::bigint() //default
{
  zero();
}

bigint::bigint(int value) : bigint(){
  for (unsigned i = 0; value != 0; ++i){
    index[i]= value % 10;
    value /= 10;
    }
}

bigint::bigint(const char *valueChar) : bigint(){ //char

  unsigned charLen = 0;
  while(valueChar[charLen]!='\0') ++charLen;

  int i=charLen-1;

  for(unsigned j=0; j<charLen; j++){
    index[j]=(int(valueChar[i])-int('0'));
    i--;
    //debugPrint(std::cout); //for debug
    //std::cout << "at:" << j << " " << index[i] << int(valueChar[charLen]) << "\n"; //for debug
    }
}

bool bigint::operator==(bigint &big2) const{
  bool flag = true;
  for (unsigned i = 0; i< CAPACITY; ++i){
      if (big2.getIndex(i)!=getIndex(i)) flag = false;
  }

  return flag;
}

int bigint::getIndex(int i) const{
  return index[i];
}

bool bigint::operator==(int num) const{
  bool flag = true;
  int numIndex[CAPACITY];
  for (int i = 0; i<CAPACITY; ++i){
     numIndex[i]= 0;
  }
  for (unsigned i = 0; num != 0; ++i){
    numIndex[i]= num % 10;
    num /= 10;
  }
  for(unsigned i = 0; i<CAPACITY; ++i){
    if(numIndex[i]!=getIndex(i)){ flag = false;
      //std::cout<<"error at " << i << " " << numIndex[i] << getIndex(i)<<"\n"; //For debugging purposes
    }
  }
  return flag;
}

std::ostream& operator<<(std::ostream &output, const bigint big){

  int size=CAPACITY;
  do{
    size--;
  }while(big.getIndex(size)==0 && size > 0);
  
  do{
    output<<big.getIndex(size);
    --size;
  }while(size>=0);

  return output;
}

void bigint::debugPrint(std::ostream &out) const{
  for (unsigned i = 0; i<CAPACITY; ++i) out << index[i] << '|';
  std::cout<<"\n";
}

bool bigint::operator==(const char charBigInt[]) const{
  bool flag = true;
  int i = 0;
  do{
    ++i;
  }while(charBigInt[i]!='\0');
  --i;
  for(unsigned j=0; charBigInt[j]!='\0'; ++j, --i){
    if (index[i]!=(int(charBigInt[j])-int('0'))){ flag = false;
    //std::cout<<"error at " << i << " " << charBigInt[j] << index[i]<<"== \n"; //For debugging purposes
    }
  }
  return flag;

}

bigint bigint::operator+(bigint big2) const{
  int carryover[CAPACITY+1];
  for (unsigned i = 0; i<CAPACITY; i++) carryover[i]=0;
  bigint result;
  int tmp;
  for(unsigned i = 0; i<CAPACITY; i++){
    tmp=index[i]+big2.getIndex(i)+carryover[i];
    if (tmp > 9){
      carryover[i+1]=1;
      result.setIndex(i, tmp%10);
    }else result.setIndex(i, tmp);
  }
  return result;
}

void bigint::setIndex(int i, int value){
  index[i]=value;
}

int bigint::operator[](int position) const{
  return index[position];
}

std::istream& operator>>(std::istream &input, bigint &big){
	
  char charBigInt[CAPACITY];
  char tmp='\0';
  unsigned i = 0;

  do{
    input >> tmp;
    charBigInt[i++]=tmp;
  }while (!input.eof() && tmp!=';');

  charBigInt[--i]='\0'; //get rid of ';'
  
  big = bigint(charBigInt);
  
  return input;
}

bigint bigint::times_digit(int num) const{
  bigint temp;
  int rem = 0, result = 0;
  for (int i = 0; i<CAPACITY; i++){
    result = index[i] * num + rem;
    if (result >= 9){ //if rem is needed
      rem = result / 10;
      result = result % 10;
      }else rem = 0; //if not set to 0
    temp.setIndex(i,result);
  }
  return temp;
}

bigint bigint::times_10(int exp) const{
  bigint temp;
  for (int i = CAPACITY - 1 - exp; i >= 0; i--){ //shift to right
    temp.setIndex(i + exp, index[i]);
  }
  for (unsigned i = 0; i<exp; i++){ //set zeros on left
    temp.setIndex(i, 0);
  }
  return temp;
}

bigint bigint::operator*(bigint big) const{
  bigint product;
  bigint tmp1;
  bigint tmp2;
  for (int i = 0; i<CAPACITY; i++){
    tmp1=times_digit(big[i]);
    tmp2=tmp1.times_10(i);
    product = product + tmp2;
  }
  return product;
}