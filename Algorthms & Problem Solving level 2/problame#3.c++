#include<iostream>

using namespace std ;

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