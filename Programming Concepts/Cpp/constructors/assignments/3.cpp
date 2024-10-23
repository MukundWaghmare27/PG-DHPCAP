// using copy constructor ,copy values of one object to other

#include<iostream>
using namespace std;

class Chamber{
   public:

    int rollno;
    string name;

    Chamber(){
        rollno = 44;
        name = "lebron";
    }

    Chamber(Chamber &ch){
        rollno = ch.rollno;
        name = ch.name;
    }

    
    void display(){
        cout<<"name : "<<name<<" roll no: "<<rollno<<endl;
    }

};

int main(){
    Chamber c1;
    Chamber c2(c1);
    // c2.name = "james";
    c2.display();

    return 0;
}