/*****************************************************************
 * Defines main function containing some BigInt tests
 *****************************************************************/
#include <iostream>
#include <stddef.h>
#include <stdlib.h>
#include "BigInt.h"

using namespace std;

int main(void) {
	

  // object with explicit constructor from long
  BigInt num1(-4);
  BigInt num2(60);
//  cout<<(num2<num1)<<"DDDDDDDDDD"<<endl;
  num1 = num1-num2;
  cout<<(num1);
  
  
  
  
  //cout<<"hello"<<num1<<endl;
  num1 = -num1;
  //cout<<"hello"<<num1<<"negative"<<endl;
  //cout<<(num1)<<endl;//<<(-4%10)<<endl<<"MAIN"<<endl;
   num1 = 1+num1+2;
  //cout<<"hello"<<num1<<"negative"<<endl;
   //cout<<num1<<"ssssssssssssssssssssssssssssss"<<endl;
   
   num1 = num1 + (-4);
  // cout<<"hello"<<num1<<"negative"<<endl;
   num1 = num1 - (-2);
   //cout<<"hello"<<num1<<"negative"<<endl;
    //cout<<num1<<"ssssssssssssssssssssssssssssss"<<endl;
	
	num1 = num1 *4;
   
    cout<<num1<<"ssssssssssssssssssssssssssssss"<<endl;
//  cout<<"hello"<<num1<<endl;

  BigInt num11 = num1;
  cout<<num11<<endl<<endl<<endl;
  
  // object with implicit constructor from long
  //BigInt num2 = 60;

  // binary addition BigInt+BigInt
  BigInt num3 = num1 + num2;
  // binary addition BigInt+long
  BigInt num4 = num3 + 2;


  // unary +
  BigInt num5 = +num2;
  
  // prefix increment
  BigInt num6 = ++num1;

  // postfix increment
  BigInt num7 = num3++;
    //cout<<num3<<"NUM#############";
  // direct initialization
  BigInt num8 = num3;
//cout<<"DEBUGGGGGGGMAIN---------------------------------------------"<<num5<<endl;

  // increment
  num3++;
  cout<<num3<<"num3"<<endl;
//out<<num1<<" "<<num2<<endl<<endl<<"asssssssssshhhh"<<endl;

  // print the values
  
  cout << num1<< num2<<endl<< " " << num3<<endl << " " <<
  num4 << " " << " " << num6 << " " <<
  num7 << " " << num8 << endl;

  // compound assignment addition with BigInt
 // num4 += num5;

// compund assignment addition with long
  //num5 += 34;

  
  
  // assignment with long
  num8 = 23;

  // binary addition: long + BigInt
  num3 = 28 + num8;

  // perform some equality tests
  bool bool1 = num7 == num8; // BigInt == BigInt
  bool bool2 = num6 == num1; // BigInt == BigInt
  bool bool3 = num1 == 4; // BigInt == long
  bool bool4 = num2 == 60; // BigInt == long
  bool bool5 = 4 == num1; // long == BigInt
  bool bool6 = 60 == num2; // long == BigInt

  // print the values
  cout << bool1 << " " << bool2 << " " << bool3 << " " <<
    bool4 << " " << bool5 << " " << bool6 << " " << endl;
  cout <<num1 << " " << num2 << " " << num3 << " " <<
    num4 << " "  << " " << num6 << " " <<
    num7 << " " << num8 << endl;
//cout<<"debug MAin"<<endl;
  // loop that computes a very large value
  //
  // with the dummied-up varsion, it overflows; in the completed
  // implementation, it should actually compute the correct value
  BigInt bigVal = 1234;
  BigInt bigVal2 = 1234;
  cout << bigVal << endl;
  cout<<"debug MAin"<<endl;
  for (BigInt i = 0; !(i == 35); i++) {
    bigVal += bigVal;
    bigVal += bigVal;
    bigVal += 1;
    cout << bigVal << endl;
  }
  
  bigVal = 1234;
  BigInt bigVal3 = bigVal2*bigVal;
  
cout<<bigVal<<" "<<bigVal2<<" "<<bigVal3;
  
  
  cout<<bigVal2<<"bigVal2"<<endl;
  return EXIT_SUCCESS;
}
