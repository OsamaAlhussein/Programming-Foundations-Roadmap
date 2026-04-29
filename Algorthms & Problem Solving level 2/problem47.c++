#include<iostream>
#include<cmath>
#include<string>

using namespace std ;

// My Round Function 


float GetFractionPart(float number){
   
return number - (int)number ;  
}

int Myraound(float number)
{

    int Ispart ;
    Ispart = (int)number;

    float Fraction = GetFractionPart(number);



    if(abs(Fraction)>=0.5)
    {

        if(number>0)
        return Ispart+1;
        else
        return Ispart-1;

    }
    else 
    {
      return   Ispart ;
    }
    

}


float  ReadNubmer(){


    float  number;
    cout << "pleas enter the Number" <<endl ;
    cin >> number ;
    return  (float)number ;

}
int main(){

    float  number = ReadNubmer();
    cout << "My round Result : "<< Myraound(number) << endl ;
    cout << "C++ round Result : "<<round(10.7) ; 

   

    return 0 ;
}