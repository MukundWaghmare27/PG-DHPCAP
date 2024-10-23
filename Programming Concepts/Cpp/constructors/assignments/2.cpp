// Define constructor overloading for initializing the above example

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

    A(string n,int r){
        name = n;
        rollno = r;
    }
    
    void display(){
        cout<<"name : "<<name<<" roll no: "<<rollno<<endl;
    }

};

int main(){

    A a1(22,"jordan");
    A a1("johnson",27);
    a1.display();

    return 0;
}