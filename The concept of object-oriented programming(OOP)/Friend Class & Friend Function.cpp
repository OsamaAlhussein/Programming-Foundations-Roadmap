#include<iostream>
using namespace std ;



class clsA{
    private:
    int _Var1 ;

    protected:

    int __Var2 ;

    public:

    int Var3 ;

    clsA(){
        _Var1 = 10 ;
        __Var2 =20 ;
        Var3=30 ;
    }

    friend class clsB ;

    friend int MySum(clsA A) ;

};



int MySum(clsA A){   // Friend Function
    return A.Var3 + A.__Var2 + A._Var1  ;
}

class clsB{   // Friend class 

    public:
    void Display(clsA A){
        cout << "\nThe Value of Var3 = " << A.Var3 << endl ;
        cout << "\nThe Value of Var2 = " << A.__Var2 << endl ;
        cout << "\nThe Value of Var1 = " << A._Var1 << endl ;
    }
};


int main(){

    clsA A ;
    clsB B ;
    B.Display(A)  ;

    cout<< endl << "Sum Var1 , Var2 , and Var3 = " << MySum(A)  ;
    return 0;
}
