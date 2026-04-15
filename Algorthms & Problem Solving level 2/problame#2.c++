#include<iostream>
#include<cmath>
using namespace std ;

/*Writing a program where the user input a number , and the output is 
a series of prime numbers Example :
Input : 5
Output : 1 , 2 , 3 , 5 */


enum enprimNotprime{prim=1 , Notprime=2};

int Readnumber(string massge)
{
int number;
cout << massge << endl ;
cin >> number ;
return number ;
}


enprimNotprime CheckPrimeNumber(short num)
{

    int M = round(num/2);

    for(int i=2 ; i<=M ; i++)
    {
        if(num%i==0)
        return enprimNotprime::Notprime;
     
        
    }
    return enprimNotprime::prim;
}

void printprimnumber(short Num)
{

    cout << "Prime of Number : \n";
    for (int i=1 ; i<=Num ; i++)
    {
        if(CheckPrimeNumber(i)==enprimNotprime::prim)
        {
            cout << i << endl ;
        }

    }
}



int main() {

int Num = Readnumber("pleas enter a Number ?");

printprimnumber(Num);



    return 0 ;
}