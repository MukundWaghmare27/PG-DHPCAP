// destructor(it is automatically called)

#include<iostream>
using namespace std;

class number{
    int a,b;
    public:
        number(){
            a=10,b=20;
        }
        number(int x,int y){
            a=x;
            b=y;
            cout<<"in constructor"<<endl;
        }
        number(number &no){
            a=no.a; b =no.b;
            cout<<"in constructor "<<endl;
        }
        ~number(){
            cout<<"is destructor "<<endl;
        }
        void display(){
            cout<<a<<" "<<b<<endl;
        }
};
int main(){
    number n1;
    number n2(22,33);
    number n3(n1);
    n1.display();
    n2.display();
    n3.display();
    return 0;
}