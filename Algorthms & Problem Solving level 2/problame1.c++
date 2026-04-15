#include<iostream>
using namespace std ;

void meniu()
{
    cout << "-------------------------------------------\n";
    cout << "                meniu                      \n";
    cout << "-------------------------------------------\n     ";
    for (int i=1 ; i<=10 ; i++){
        cout << i << "    ";
    }
    cout << "\n___|________________________________________________________\n";
}


string Check(short N)
{
    if(N<10)
    return "  | ";
    else 
    return " | ";
}

string Check2(short N)
{
    if(N<10)
    return "    ";
    else 
    return "   ";
}

void print()
{
    for(int i =1 ; i<=10 ; i++)
    {
        cout << i << Check(i) ;

        for (int j=1 ; j<=10 ; j++)
        {
            cout << j*i << Check2(j*i);
        }
        cout << "\n";
    }

    
}

int main(){

meniu();
print();



    return 0 ;
}














