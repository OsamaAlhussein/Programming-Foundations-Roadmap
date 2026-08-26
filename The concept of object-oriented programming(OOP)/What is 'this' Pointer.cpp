#include<iostream>
using namespace std ;


class clsEmployee{
    public:
    int Id ;
    string Name ;
    string Salary ;

    clsEmployee(int Id , string Name , string Salary){
        this->Id = Id ;
        this->Name = Name ;
        this->Salary = Salary ;
    }

    static void Function1(clsEmployee Employee){
        Employee.Print();
    }

    void Function2(){
        Function1(*this);
    }


    void Print(){
        cout << Id << "  " << Name << "  " << Salary << "\n" ;
    }
};



int main(){

    clsEmployee Employee(10,"Osama" , "5000$") ;

    Employee.Print();

    Employee.Function2();


    return 0;
}
