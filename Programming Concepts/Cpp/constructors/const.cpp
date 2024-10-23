// default constructor

#include<iostream>
using namespace std;

class number{
    int a,b;
    public:
        number(){
            a=10;
            b=10;
            cout<<"in constructor"<<endl;
        }
        void display(){
            cout<<a<<" "<<b;
        }
};
int main(){
    number n1;
    n1.display();
    return 0;
}