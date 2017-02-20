#include <iostream>
using namespace std;
class Rat{ 
private:
int n;
int d; 

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
//accessor functions (usually called get() and set(...) )
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
}
Rat operator-(Rat r) {
    Rat t;
    t.n=(n*r.d)-(d*r.n);
    t.d=d*r.d;
    lowestTerms(t);
    improperFraction(t);
    return t;
}
Rat operator*(Rat r) {
    Rat t;
    t.n=n*r.n;
    t.d=d*r.d;
    lowestTerms(t);
    improperFraction(t);
    return t;
}
Rat operator/(Rat r) {
    Rat t;
    t.n=n*r.d;
    t.d=d*r.n;
    lowestTerms(t);
    improperFraction(t);
    return t;
}
int gcd(int a, int b) {
        if(b == 0) {
	        return a;
        }
        else {
            return gcd(b, a % b);
        }
}
void lowestTerms(Rat &t) {
        if(t.getN()<0&&t.getD()>0) {
        return;
        }
        int x = t.gcd(t.getN(), t.getD());
        t.n=t.n/x;
        t.d=t.d/x;
}
void improperFraction(Rat &t) {
        if (t.n > t.d) {
            cout << t.n/t.d << " ";
            t.n=t.n%t.d;
        }
}

// 2 overloaded i/o operators
friend ostream& operator<<(ostream& os, Rat r);
friend istream& operator>>(istream& is, Rat& r);

}; //end Rat

// operator<<() is NOT a member function but since it was declared a friend of Rat 
// it has access to its private parts.
ostream& operator<<(ostream& os, Rat r){ 
    if(r.d==1) {
        os<<r.n<<endl;
        return os;
    }
    os<<r.n<<" / "<<r.d<<endl;
return os;
}

//operator>>() is NOT a member function but since it was declared a friend of Rat 
// it has access to its provate parts.
istream& operator>>(istream& is, Rat& r){
    is>>r.n>>r.d;
return is; 
}

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





