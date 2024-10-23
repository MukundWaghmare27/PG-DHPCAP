// paramaterized constructor

#include<iostream>
using namespace std;

class number{
    int a,b;
    public:
        number(int x,int y){
            a=x;
            b=y;
            cout<<"in constructor"<<endl;
        }
        void display(){
            cout<<a<<" "<<b<<endl;
        }
};
int main(){
    number n1(22,33);
    n1.display();
    return 0;
}