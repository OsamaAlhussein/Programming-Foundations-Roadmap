#include<iostream>
using namespace std ;


// commission percentage

int ReadNumber(){

    int N;
    cout << "Please enter Total Sales ?\n";
    cin >> N;
    return N ;
}

float GetCommissionPercentage(float  TotalSale)
{
     if(TotalSale >= 1000000)
    return  0.01 ;
    else if (TotalSale >= 500000)
    return   0.02 ;
    else if(TotalSale >= 100000)
    return  0.03 ;
    else if(TotalSale >= 50000)
    return  0.05 ;
    else 
    return  0.00 ;
}
float CalculatTotalCommission(float TotalSale){

    return GetCommissionPercentage(TotalSale) * TotalSale ;
}


int main(){


    int TotalCommission = ReadNumber();
    cout << "commission percentage " << GetCommissionPercentage(TotalCommission)<< endl ;
    cout << "Total commission = " << CalculatTotalCommission(TotalCommission);


    return 0;
}