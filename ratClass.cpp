// This c++ program creates a class for rational numbers: 3 constructors to create a rational number, calculating 2 rational 
// numbers, and operator for inputing and outputing a rational number.
// @Noushin Iqra

#include <iostream>
using namespace std;

class Rat{ 
	
private:
int n; //numerator
int d; //denominator

public:
// default constructor 
Rat(){
    n=0;
    d=1; 
}
// 2 parameter constructor 
Rat(int i, int j){
    n=i;
    d=j; 
}
// conversion constructor
Rat(int i){ 
    n=i;
    d=1; 
}
//accessor functions
int getN(){ 
    return n;
}
int getD(){ 
    return d;
}
void setN(int i){ 
    n=i;
}
void setD(int i){ 
    d=i;
}
	
//arithmetic operators
Rat operator+(Rat r){ 
    Rat t;
    t.n=(n*r.d)+(d*r.n); 
    t.d=d*r.d;
    lowestTerms(t);
    improperFraction(t);
return t;
}//adding 2 rational numbers
	
Rat operator-(Rat r) {
    Rat t;
    t.n=(n*r.d)-(d*r.n);
    t.d=d*r.d;
    lowestTerms(t);
    improperFraction(t);
    return t;
}//subtracting 2 rational numbers
	
Rat operator*(Rat r) {
    Rat t;
    t.n=n*r.n;
    t.d=d*r.d;
    lowestTerms(t);
    improperFraction(t);
    return t;
}//multiplying 2 rational numbers
	
Rat operator/(Rat r) {
    Rat t;
    t.n=n*r.d;
    t.d=d*r.n;
    lowestTerms(t);
    improperFraction(t);
    return t;
}//dividing 2 ratinal numbers
	
int gcd(int a, int b) {
        if(b == 0) {
	        return a;
        }
        else {
            return gcd(b, a % b);
        }
}//greatest common denominator
	
void lowestTerms(Rat &t) {
        if(t.getN()<0&&t.getD()>0) {
        return;
        }
        int x = t.gcd(t.getN(), t.getD());
        t.n=t.n/x;
        t.d=t.d/x;
}//simplify a rational number to the lowest term
	
void improperFraction(Rat &t) {
        if (t.n > t.d) {
            cout << t.n/t.d << " ";
            t.n=t.n%t.d;
        }
}//simplify if numerator is bigger than denominator

// 2 overloaded i/o operators
friend ostream& operator<<(ostream& os, Rat r);
friend istream& operator>>(istream& is, Rat& r);

}; //end Rat class

ostream& operator<<(ostream& os, Rat r){ 
    if(r.d==1) {
        os<<r.n<<endl;
        return os;
    }
    os<<r.n<<" / "<<r.d<<endl;
return os;
}//outputing a rational number

istream& operator>>(istream& is, Rat& r){
    is>>r.n>>r.d;
return is; 
}//inputing a rational number

int main(){
Rat x(1,2), y(2,3), z; 
z=x+y;
cout<<z;
z=x-y;
cout<<z;
z=x*y;
cout<<z;
z=x/y;
cout<<z;
x.setN(0); 
y.setD(2); 
z=x+y;
cout<<z;
cin>>x;
cout<<x+5;
return 0;
}





