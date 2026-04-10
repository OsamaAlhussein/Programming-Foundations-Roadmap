#include<iostream>
using namespace std ;

struct stInfo{

    int Age ;
    bool HasDriveingLicense ;
    bool Haswasta ;
    
};


stInfo ReadInfo(){
    stInfo Info ;

    cout << "\nPleas enter your age ? \n";
    cin >> Info.Age ;
    cout << "\nDo you have driver License\n";
    cin >> Info.HasDriveingLicense ;
    cout << "\nDo you have wasta ? ";
    cin >>Info.Haswasta ;

    return Info ;

}


bool IsAccepted(stInfo Info){

    if(Info.Age > 21 && Info.HasDriveingLicense || Info.Haswasta)
    return true ;
    else 
    return false ;
}


void PrintResult(stInfo Info){

    if(IsAccepted(Info)){
        cout << "Hired";
    }
    else 
    {
        cout << "Rejected";
    }

}


int main(){

    PrintResult(ReadInfo());

    return 0;
}
