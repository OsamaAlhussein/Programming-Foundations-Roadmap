#include<iostream>
using namespace std ;

// Grad A , B , C , D , E , F 

int ReadGrade(int From , int To){
    int Grade;
    do{
         cout << "Please enter a Grade between 0 and 100 ?\n";
    cin >> Grade ;


    }while(Grade < From || To < Grade);
   

    return Grade ;
}

char GetGradeLetter(int Grade){

    if( 90 <= Grade)
    return 'A' ;
    else if ( Grade >= 80 )
    return 'B' ;
    else if(Grade >= 70 )
    return 'C' ;
    else if(Grade >= 60 )
    return 'D' ;
    else if (Grade >= 50)
    return 'E' ;
    else 
    return 'F';
    
}

int main(){
    int N = ReadGrade(0,100);
    cout << endl  << "Result = " << GetGradeLetter(N) << endl ;

    return 0;
}