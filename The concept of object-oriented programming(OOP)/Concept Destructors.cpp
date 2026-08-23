#include<iostream>
using namespace std ;


class clsPerson{

    public:
    clsPerson(){
        cout << "\nHi I am Constructors "; 
    }

    ~clsPerson(){
        cout << "\nHi I am Destructors ";
    }
};

int main(){

    clsPerson Person ;

  
    clsPerson * Person2 = new clsPerson ;
    delete Person2 ;


    return 0;
}
