#include<iostream>
#include<string>
using namespace std ;


struct stClient{
    string AcountNumber ="";
    string PinCode ="";
    string Name="";
    string Phon="";
    double AcountBalance ;

};

stClient ReadNewClient(){
    stClient Clinet ;

    cout << "Enter Acount Number ? ";
    getline(cin,Clinet.AcountNumber);

    cout << "Enter PinCode ? ";
    getline(cin,Clinet.PinCode);

    cout << "Enter Name ? ";
    getline(cin,Clinet.Name);

    cout << "Enter Phon ? ";
    getline(cin,Clinet.Phon);

    cout << "Enter Acount Balance ? ";
    cin >> Clinet.AcountBalance ;

    return Clinet ;
}


string ConvertRecordToLine(stClient Client , string Seperator="#//#"){
    string stClientRecord ="";

    stClientRecord += Client.AcountNumber + Seperator;
    stClientRecord += Client.PinCode + Seperator;
    stClientRecord += Client.Name + Seperator;
    stClientRecord +=to_string(Client.AcountBalance) ;

    return stClientRecord ;
}



int main(){

    cout << "\nPlease Enter Client Data: \n\n";
    stClient Client;
    Client = ReadNewClient();
    cout << "\n\nClient Record for Saving is: \n";
    cout << ConvertRecordToLine(Client);
   
    system("pause>0");
    return 0;
}