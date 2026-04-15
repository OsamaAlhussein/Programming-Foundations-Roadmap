#include<iostream>
using namespace std ;

/*writing a prgram  to detremine if the input number is perfect or 
not perfect ,
Example : 
Input : 6 
Output : is Number Perfact 
because : 1+2+3 = 6 
remainder when 6 is divided by 1 is 0 , the remainder when 6 is divided by 2 is 0 , and the remainder when 6 is divided by 3 is 0. */

enum enperfactenumber{perfact = 1 , Notperfact=2};

int Readnumber(string massge)
{
int number;
cout << massge << endl ;
cin >> number ;
return number ;
}

enperfactenumber  perfactNumber(int number)
{
    short Num=0 ;

    for(int i=1 ; i<number ; i++)
    {
        if (number%i==0)
        {
            Num = Num + i ;
        }
    }

    if(number==Num)
    return enperfactenumber::perfact;
    else 
    return enperfactenumber::Notperfact;
}


void PrintPerfactNubmer(int Number)
{
if (perfactNumber(Number)==enperfactenumber::perfact)
cout << Number <<" is Number Perfact \n";
else 
cout << Number << " is not Number Perfact\n";

}

int main(){
int N =  Readnumber("pleas enter number ?") ;
PrintPerfactNubmer(N);


    return 0;
}
