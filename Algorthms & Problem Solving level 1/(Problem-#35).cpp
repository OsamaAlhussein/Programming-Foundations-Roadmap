#include<iostream>
using namespace std ;

// Piggy Bank Calculator 

// enum { ,  ,  , , };

struct stPiggyBankCalculator{

    int Pennies =1  ,  Nickels=1 ,Dimes=1 ,Quarters=1 ,Dollars=1 ;


};

stPiggyBankCalculator ReadPiggyyBankContenet(){

    stPiggyBankCalculator PiggyBankCalculator ;

    cout << "Please enter Prnnies ?\n";
    cin  >> PiggyBankCalculator.Pennies ;

    cout << "Please enter Nickels ?\n";
    cin  >> PiggyBankCalculator.Nickels ;

    cout << "Please enter a Dimes ?\n";
    cin  >> PiggyBankCalculator.Dimes ;

    cout << "Please enter a Quarters ?\n";
    cin  >> PiggyBankCalculator.Quarters ;

    cout << "Please enter a Dollars ?\n";
    cin  >> PiggyBankCalculator.Dollars ; 


    return PiggyBankCalculator ;
    

}

int CalculateTotalPennies(stPiggyBankCalculator PiggyBankCalculator)
{
    int TotalPennise = (PiggyBankCalculator.Pennies*1) 
    + (PiggyBankCalculator.Nickels*5) 
    + (PiggyBankCalculator.Dimes*10 )
    + (PiggyBankCalculator.Quarters*25) 
    + (PiggyBankCalculator.Dollars*100 );

    return TotalPennise ;

}


int main(){

    int TotalPennies = CalculateTotalPennies(ReadPiggyyBankContenet());

    cout << "Total Pennies = " << TotalPennies << endl ;
    cout << "Total Dollars = " << (float) TotalPennies / 100;


    return 0;
}