// Implement a class Complex which represents the Complex Number data type. Implement the following 1. Constructor (including a default constructor which creates the complex number 0+0i). 2. Overload operator+ to add two complex numbers. 3. Overload operator* to multiply two complex numbers. 4. Overload operators << and >> to print and read Complex Numbers.

#include <iostream>

using namespace std;

class Complex
{
  private :
    double real , img ;
    
  public:
  Complex(double r = 0.0 , double i = 0.0 ){
    real = r;
    img = i;
  }
 
  Complex operator+ (const Complex& c){
    Complex temp ;
    temp.real = c.real + real;
    temp.img = c.img + img ; 
    return temp;
  }
  
  Complex operator* (const Complex& c){
    Complex temp;
    temp.real = c.real*real - c.img*img ;
    temp.img = c.img*real + img*c.real ;
    return temp;
  }

  friend ostream& operator<<(ostream&out , const Complex& c);
  friend istream& operator>>(istream&in , Complex& c); 
};

istream& operator>>(istream& in , Complex& c){
  cout<<"Enter the real part: \n";
  in>>c.real;
  cout<<"Enter the img part: ";
  in>>c.img;
  return in;
}

ostream& operator<<(ostream& out , const Complex& c){
  out<<"Number is:"<<c.real<<"+ ("<<c.img<<"i)\n";
  return out;
}

int main ()
{
  Complex c1 , c2 , c3 , c4;
  cin >> c1 ;
  cin >> c2 ; 
  
  c3 = c1 + c2 ;
  c4 = c1*c2 ;
  
  cout << "Sum: " << c3;
  cout << "Product: " << c4;

}
