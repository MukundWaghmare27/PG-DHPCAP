// Define constructor to initialize class members rollno,name and print them

#include<iostream>
using namespace std;

class A{
   public:

    int rollno;
    string name;

    A(int r,string n){
        rollno = r;
        name = n;
    }

    void display(){
        cout<<"name : "<<name<<" roll no: "<<rollno<<endl;
    }

};

int main(){

    // A a1 = A(21,"jordan");
    A a1(22,"jordan");
    a1.display();

    return 0;
}