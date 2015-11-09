/****************************************************************
 * BigInt.cpp -- big integer package for C++
 ****************************************************************/
#include <iostream>
#include "BigInt.h"

using namespace std;

/*****************************************************************
 * member functions for BigInt class
 *
 * Presently dummied up:
 * - does not implement integer values larger than the 'long' data
 *   type
 * - only operations related to '+' and '==' operator are defined
 * 
 *****************************************************************/

// copy constructor
BigInt::BigInt(BigInt const& orig) {
//  cout<<"copy constructor start"<<endl<<endl;
  
 // cout<<"copy constructor start"<<endl<<endl;
  this->sign = orig.sign;
  this->size = orig.size;
  this->data = new short[this->size];
  int i = 0;
  while(i<orig.size)
  {
	this->data[i] = orig.data[i];
	i++;
  }
 // cout<<"debug Copy"<<endl;
}

// constructor
BigInt::BigInt()
{
	this->size =1;
	this->data = new short[1];
	this->data[0] = 0;
	this->sign = true;
}

// constructor where operand is a long
BigInt::BigInt(long num) {
	if(num>=0)
	{
		this->sign = true;
	}
	else
	{
		this->sign = false;
		num = -num;
	}
  
  this->size = this->getLength(num);
  this->data = new short[getLength(num)];
  long i = this->getLength(num)-1;
  while(i>=0)
  {
	this->data[i] = num%10;
	//cout<<this->data[i]<<"DEBUG Constructor"<<endl;
	num = num/10;
	i--;
  }
}
  
long BigInt::getLength(long num)
{
	int i =0;
	if(num == 0)return 0;
	while(num !=0)
	{
			num = num/10;
			i++;
	}
	return i;
}
  
// destructor
BigInt::~BigInt() {
	delete[] this->data;
	
}


BigInt BigInt::operator-(BigInt const& other) const {
	BigInt test = other;
	cout<<this->size<<" "<<other.size;
	BigInt test2 = *this;
	cout<<test<<"rhs"<<"______________SUBTRACT"<<test2<<"lhs";
	cout<<(test2<test)<<endl;
	if(*this < other)
	{
		cout<<"lessthan"<<endl;
		BigInt retVal = other - *this;
		retVal.sign = false;
		return retVal;
	}
	
	if(this->sign && other.sign==false)
	{
		return (*this+ (-other));
	}
	if(this->sign == false && other.sign==false)
	{
		return (*this + -other);
	}
	
	
	BigInt result;
	
	if(this->size > other.size)
	{
		result.setLength(this->size);
		//result.changeBigSize(this->size);
	}
	else
	{
		result.setLength(other.size);
		//result.changeBigSize(other.size);
	}
	
	
	int rightLen = other.size;
	int leftLen = this->size;
	int resultLen = result.size;
	
	int i =leftLen-1;
	int j = rightLen-1;
	int k = resultLen-1;
	
	int subI = 0;
	int subK = 0;
	
	while(i>=0)
	{
		subI = i;
		if(j<0)
		{
			result.data[k] = this->data[i];
		}
		else
		{
			if(this->data[i]< other.data[j] )
			{
				//borrow from up further in the number
				while(subI-1>=0)
				{
					if(this->data[subI-1] >0)
					{
						this->data[subI-1]-=1;
						break;
					}
					subI--;
				}
				while(subI<i)
				{
					this->data[subI]+=9;
					subI++;
				}
				this->data[i]+=10;
				result.data[k]+= this->data[i] - other.data[j];
				
			}
			else
			{
				result.data[k]  += this->data[i] - other.data[j];
			}		
		
		}
		i--;
		j--;
		k--;
	}
	
	
	
	
	i = 0;
	int c = 0;
	
	while(result.data[i] == 0)
	{
		//cout<<result.data[i]<<"----------------------------------------------------"<<endl;
		c++;
		i++;
	}
	k = result.size -c;
	j = result.size-1;
	
	short *temp = new short[k];
	k--;
	while(k>=0)
	{
		temp[k] = result.data[j];
		k--;
		j--;
	}
	
	result.size-= c;
	result.data = temp;
	
return result;
}
	
	
	



// binary addition
BigInt BigInt::operator+(BigInt const& other) const {
//cout<<this->data[0]<<"lhs"<<other.data[0]<<"rhs"<<endl;
if(this->sign && (other.sign == false) )
{
	return *this - (-other);
}
if( (this->sign ==false)&& other.sign)
{
	return other - (-*this);
}
if((other.sign==false) &&(this->sign ==false))
{
	BigInt retVal = -other + -(*this);
	retVal.sign = false;
	return retVal;
}


 short *lhs,*rhs;
  lhs = this->data;
  rhs = other.data;
  BigInt result;
  int k;
  if(this->size > other.size){
	
	 k= this->size;
	 result.setLength(this->size+1);	//in case there is a carry
	
  }
  else
  {
	result.setLength(other.size+1);
	k = other.size;
	
  }
  int i = this->size-1;
  int j = other.size-1;
  
  while(i>=0 || j>=0)
  {
	if(i<0)
	{
		result.data[k] += rhs[j];
	}
	else if(j<0)
	{
		result.data[k] += lhs[i];
	}
	else if(i>=0 && j>=0)
	{
		result.data[k] += lhs[i] +rhs[j];
	}
	int subk = k;
	while(subk-1 >=0)
	{
		if(result.data[subk]>=10)
		{
			result.data[subk] -=10;
			result.data[subk-1] += 1;
		}
		subk--;
	}
	i--;
	j--;
	k--;
  }
 // cout<<endl<<result<<endl<<"result"<<endl;
  //set the actual length of the number in case there was no carry
  if(result.data[0] == 0)
  {
	k = result.size;
	i = this->size;
    j = other.size;
	if(j<i)
	{
		short * temp = new short[i];
		i--;
		k--;
		while(i>=0)
		{
			temp[i] = result.data[k];
			i--;
			k--;
		}
		result.setLength(this->size);
		  result.data = temp;
	}
	else
	{
		short * temp = new short[j];
		j--;
		k--;
		while(j>=0)
		{
			temp[j] = result.data[k];
			j--;
			k--;
		}
		result.setLength(other.size);
		  result.data = temp;
	}
  }

  return result;
}



int BigInt::setLength(long num)
{
	this->data = new short[num];
	this->size = num;
	int i = 0;
	while(i<num)
	{
		this->data[i] = 0;
		i++;
	}
	return 1;
}



// compound addition-assignment operator
BigInt BigInt::operator+=(BigInt const& other) {
	//cout<<*this<<"plusequals"<<endl;
	*this = (*this +other);
	//cout<<*this<<"plusequals"<<endl;
	return *this;
}

// prefix '++' operator
BigInt BigInt::operator++() {
	return *this+1;
}

// postfix '++' operator
BigInt BigInt::operator++(int dummy) {
  BigInt temp = *this;
 // *this = *this+ 1;
  BigInt add(1);
  *this += add;
  return temp;
}

 BigInt& BigInt::operator=(const BigInt& rhs)
 {
	this->sign = rhs.sign;
	if(this->size != rhs.size)
	{
		this->size = rhs.size;
		delete [] this->data;
		this-> data = new short[rhs.size];
		
	}
	int i = 0;
	for (i = 0; i<rhs.size; i++)
	{
		this->data[i] = rhs.data[i];
	}
	return *this;
 }

// unary '+' operator
BigInt BigInt::operator+() const {

  BigInt retVal= *this;
  //cout<<retVal<<"UNARYPLUS<"<<endl;
  return retVal;
}
//unary - operator
BigInt BigInt::operator-() const{
	BigInt retVal = *this;
	retVal.sign = !retVal.sign;
	return retVal;
}
// equality operator
bool BigInt::operator==(BigInt const& other) const {
	if(this->sign != other.sign)return false;
	if( this->size != other.size) return false;
	int i = 0;
	
	while(i < this->size)
	{
		if( this->data[i] != other.data[i])
		{
			return false;
		}
		i++;
	}
	return true;
}
//not equal
bool BigInt::operator!=(BigInt const& other) const {
	return !(*this==other);
}
//greater than
bool BigInt::operator>(BigInt const& rhs) const {
	if(this->sign && rhs.sign)
	{
		if(this->size > rhs.size){return true;}//
		else if(this->size<rhs.size){return false;}//
		else{
			int i = 0;
			for( i = 0; i<rhs.size; i++)
			{
				if(this->data[i] < rhs.data[i])
				{
						return false;//
				}
				
			}
			
		}
	return true;//
	}
	else if(this->sign == false && rhs.sign == false)
	{
		if(this->size > rhs.size){return false;}//
		else if(this->size<rhs.size){return true;}//
		else{
			int i = 0;
			for( i = 0; i<rhs.size; i++)
			{
				if(this->data[i] > rhs.data[i])
				{
						return false;//
				}
				
			
			}
		}
	return true;//
	}
	else
	{
		if(this->sign ==false)
		{
			return false;//
		}
		return true;//
	}
}

//less than
bool BigInt::operator<(BigInt const& other) const {
	return !((*this)==other) && !((*this > other));
}
//greater than equal to
bool BigInt::operator>=(BigInt const& other) const{
	return (*this)==other || (*this)>other;
}
//less than equal to
bool BigInt::operator<=(BigInt const& other) const{
	return (*this)<other || (*this)==other;
}

// output-stream operator for BigInt (non-member function)
ostream & operator<<(ostream& os, BigInt& num) {
	if(!(num.sign))
	{
		os<<'-';
	}
	int i = 0;
	while(i<num.size)
	{
		os<<num.data[i];
		i++;
	}
	os<<endl;
  return os;
}



 BigInt BigInt::operator*(BigInt const& rhs) const{
	BigInt result;
	int rightLen = rhs.size;
	int leftLen = this->size;
	
	
	int count = 1;
	
	int i =leftLen-1;
	int j = rightLen-1;
	
	//big number on top
	if(rhs>*this)
	{
		result.size = 2*rhs.size;
		result.setLength(result.size);
		int resultLen = result.size;
		int k = resultLen-(1*count);
		while(i>=0)
		{
			while(j>=0 && k>=0)
			{
				
				result.data[k] += (rhs.data[j]*this->data[i])%10;
				if(k-1 >=0)
				{
					//put in tens digit in current answer
					result.data[k-1] += (rhs.data[j]*this->data[i])/10;
				}
				if(result.data[k]>=10 && k-1 >=0)
				{
					//carry over
					result.data[k]-=10;
					result.data[k-1] +=1;
				}
				j--;
				k--;
			}
			i--;
			count++;
			j = rightLen-1;
			k = resultLen-(1*count);
			
			
		}
		
	}
	else//big number on bottom
	{
		result.size = 2*this->size;
		result.setLength(result.size);
		int resultLen = result.size;
		int k = resultLen-(1*count);
		while(j>=0)
		{
			while(i>=0 && k>=0)
			{
				
				result.data[k] += (rhs.data[j]*this->data[i])%10;
				if(k-1 >=0)
				{
					result.data[k-1] += (rhs.data[j]*this->data[i])/10;
				}
				if(result.data[k]>=10 && k-1 >=0)
				{
					result.data[k]-=10;
					result.data[k-1] +=1;
				}
				
				i--;
				k--;
			}
			j--;
			count++;
			i = leftLen-1;
			k = resultLen-(1*count);
			
			
		}
	}
	
	
	
	
	i = 0;
	int c = 0;
	
	while(result.data[i] == 0)
	{
		//cout<<result.data[i]<<"----------------------------------------------------"<<endl;
		c++;
		i++;
	}
	int k = result.size -c;
	j = result.size-1;
	
	short *temp = new short[k];
	k--;
	while(k>=0)
	{
		temp[k] = result.data[j];
		k--;
		j--;
	}
	
	result.size-= c;
	result.data = temp;
	
	return result;
 }