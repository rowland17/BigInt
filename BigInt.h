/****************************************************************
 * BigInt.h -- include-file for big integer package
 ****************************************************************/
#ifndef BIGINT_H
#define BIGINT_H

#include <iostream>

/*****************************************************************
 * BigInt class
 *
 * Presently dummied up:
 * - does not implement integer values larger than the 'long' data
 *   type
 * - only operations related to '+' and '==' operator are defined
 * 
 *****************************************************************/
class BigInt {
 private:
  short *data; // our numeric data, for now
  bool sign; //true is positive
  int size;
  
  int setLength(long num);
 public:
 short* getData(){return data;};
 long getLength(long num);
  // copy constructor
  BigInt(BigInt const& orig);
  
  BigInt& operator=(const BigInt& rhs);

  // constructor where data value is passed as a long
  BigInt(long num);
  BigInt();
  
  // destructor
  ~BigInt();

  // binary operators
  BigInt operator+(BigInt const& other) const;
  BigInt operator-(BigInt const& rhs) const;
  BigInt operator*(BigInt const& rhs) const;
 
  
  // unary '+' operator
  BigInt operator+() const;
  BigInt operator-() const;

  // prefix '++' operator
  BigInt operator++();

  // postfix '++' operator
  BigInt operator++(int dummy);

  // compound addition-assignment operator
  BigInt operator+=(BigInt const& other);

  // equality operation
	bool operator==(BigInt const& other) const;
	bool operator!=(BigInt const& other)const;
	bool operator>(BigInt const& other)const;
	bool operator<(BigInt const& other) const;
	bool operator<=(BigInt const& other) const;
	bool operator>=(BigInt const& other) const;
  // output-stream operator for BigInt (non-member function)
  friend std::ostream & operator<<(std::ostream& os, BigInt& num);
};

// addition operator where left operand is a long
inline BigInt operator+(long num, BigInt const& val) {
  return val+num;
}

inline BigInt operator-(long num, BigInt const& val) {
  return (-val) + num;
}

// equality operator where left operand is a long
inline bool operator==(long num, BigInt const& val) {
  return val==num;
}

#endif
