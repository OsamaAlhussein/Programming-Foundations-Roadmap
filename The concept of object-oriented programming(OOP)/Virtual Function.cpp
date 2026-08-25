#include<iostream>
using namespace std ;

class clsPerson{
    public:
    
    virtual void Print(){
        cout << "\nHi I am a Person\n";
    }
};

class clsEmployee : public clsPerson {

    public:
    void Print(){
        cout << "\nHi I am an Employee\n";
    }

};


class clsStudent : public clsPerson{
    public:
    void Print(){
        cout << "\nHi I am a Student\n";
    }
};

int main(){

    clsEmployee Employee1 ;
    clsStudent Student1 ;

    Employee1.Print();
    Student1.Print();


    clsPerson * Person1 = &Employee1 ;
    clsPerson * Person2 = &Student1 ;

    Person1->Print();
    Person2->Print();

    return 0;
}
