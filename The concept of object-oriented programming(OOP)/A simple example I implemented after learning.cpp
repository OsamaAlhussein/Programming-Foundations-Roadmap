/*After grasping the fundamentals of object-oriented programming, 
I applied what I learned to this simple example.
The best is yet to come—I am a curious person.
*/

#include<iostream>
using namespace std ;


class clsCalculater{
    private:
    float _LastNumber=0 ;
    float _PreviousResult =0 ;
    string _LastOpreation ="Clear";
    float _Result =0 ;

    bool IsZero(float Number){
        return (Number ==0 );

    }


    public:

    void Add(float Number){
        _LastNumber = Number;
        _PreviousResult = _Result;
        _LastOpreation = "Add";
        _Result += Number ;
    }

    void Subtract(float Number){
        _LastNumber = Number ;
        _PreviousResult = _Result ;
        _LastOpreation = "Subract" ;
        _Result -= Number ;
    }

    void Divide(float Number){
        _LastNumber = Number ;
        if(IsZero(Number)){
            Number = 1 ;
            _LastNumber = 1 ;
        }
        _PreviousResult = _Result ;
        _LastOpreation = "Divide";
        _Result /= Number ;
    }

    void Multiply(float Number){
        _LastNumber = Number ;
        _PreviousResult = _Result ;
        _LastOpreation = "Multiply";
        _Result *= Number ;
    }

    void CanclLastOperation(){
        _LastNumber = 0 ;
        _LastOpreation = "Canclling Last Operation ";
        _Result = _PreviousResult ;
    }


    void Clear(){
        _LastNumber =0 ;
        _PreviousResult = 0;
        _LastOpreation = "Clear";
        _Result = 0;
    }

    float GetFinalResult(){
        return _Result ;
    }

    void PrintResult(){
        cout << "Result ";
        cout << "After " << _LastOpreation << " " << _LastNumber << " is : "
        << _Result << endl ; 
    }

};

int main(){

    clsCalculater Calculater1 ;
    Calculater1.Add(10);
    Calculater1.PrintResult();

    Calculater1.Add(100);
    Calculater1.PrintResult();

    Calculater1.Divide(0);
    Calculater1.PrintResult();

    Calculater1.Divide(2);
    Calculater1.PrintResult();

    Calculater1.Multiply(3);
    Calculater1.PrintResult();

    Calculater1.CanclLastOperation();
    Calculater1.PrintResult();

    return 0;
}
