#include<iostream>
using namespace std ;

// simple calculator 

enum enOperationTyp{Add='+' , Subtract='-' , Multiply='*' , Divide='/'};


float ReadNumber(string Message){

    float Num ;
    cout << Message << endl ;
    cin  >> Num ;

    return Num ;
}

enOperationTyp ReadOpType(){
    char Type='+' ;

    cout << "Please enter Operation Type (+) , (-) , (*) , (/) \n";
    cin  >> Type ;

    return (enOperationTyp) Type ;
}

float Calculate(float Num1 , float Num2 , enOperationTyp OperationType){

   switch(OperationType){
    case enOperationTyp::Add :
    return Num1+Num2 ;
    case enOperationTyp::Subtract:
    return Num1-Num2;
    case enOperationTyp::Multiply:
    return Num1*Num2 ;
    case enOperationTyp::Divide :
    return Num1/Num2 ;
    default:
    return Num1+Num2 ;
   }
}



int main(){

    float Num1 = ReadNumber("Please enter a Number 1 ?");
    float Num2 = ReadNumber("Please enter a Number 2 ?");
    enOperationTyp OperationType = ReadOpType() ;

    cout << "Result = " << Calculate(Num1 , Num2 , OperationType);


    return 0;
}