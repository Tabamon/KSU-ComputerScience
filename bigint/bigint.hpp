#ifndef BIGINT
#define BIGINT 10
#include <iostream>

const int CAPACITY = 1000; //max number of digits in bigint

class bigint{
private:
  void zero();
  int index[CAPACITY];
public:
//milestone 1
  bigint();
  bigint(int value);
  bigint(const char *valueChar);
  int getIndex(int i) const;
  void setIndex(int i, int value);
  void debugPrint(std::ostream &out) const;
  bool operator==(bigint &big2) const;
  bool operator==(int num) const;
  bool operator==(const char charBigInt[]) const;
  friend std::ostream &operator<<(std::ostream& output, const bigint big);
  friend std::istream &operator>>(std::istream &input, bigint &big);
//milestone 2
  bigint operator+(bigint) const;
  int operator[](int position) const;
//milestone 3
  bigint times_digit(int x) const;
  bigint times_10(int x) const;
  bigint operator*(bigint) const;
//Challenge
  bigint operator!();

};

 

#endif
