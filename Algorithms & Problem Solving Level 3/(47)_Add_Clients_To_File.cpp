#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std ;



struct stClient{
    string AcountNumber;
    string PinCode ;
    string Name;
    string Phon;
    double AcountBalance ;

};

vector <string> SliptString(string Line , string Delime){
    int pos =0;
    string sWord ;
    vector <string> vClient ;

    while((pos=Line.find(Delime)) != std::string::npos){
        sWord = Line.substr(0,pos);

        if(sWord != ""){
            vClient.push_back(sWord);
        }
        Line.erase(0,pos+Delime.length());

    }

    if(Line!=""){
        vClient.push_back(Line);
    }

    return vClient ;
}

stClient ConvertLineToRecord(string Line , string Seperator="#//#"){
    stClient Client ;
    vector <string> vClient = SliptString(Line,Seperator);

    Client.AcountNumber = vClient[0];
    Client.PinCode = vClient[1];
    Client.Name = vClient[2];
    Client.Phon = vClient[3];
    Client.AcountBalance = stod(vClient[4]);

    return Client ;

}

vector <stClient> LoadClientDataFromFile(){

    vector <stClient> vClient ;
    fstream MyFile ;

    MyFile.open("CleintRecord.txt" , ios::in);

    if(MyFile.is_open()){

        string Line ;
        stClient Clinet ;

        while(getline(MyFile,Line)){

            Clinet = ConvertLineToRecord(Line);
            vClient.push_back(Clinet);
        }
    }
    return vClient ;
}

void PrintClientRecord(stClient Client){
    cout << "|" << left << setw(15) << Client.AcountNumber;
    cout << "|" << left << setw(10) << Client.PinCode;
    cout << "|" << left << setw(40) << Client.Name ;
    cout << "|" << left << setw(12) << Client.Phon;
    cout << "|" << left << setw(12) << Client.AcountBalance;
}

void PrintAllClientsData(vector <stClient> vCleints){

    cout << "\n\t\t\t\t\t Client List ("<< vCleints.size()<<") Client(s).";
    cout << "\n______________________________________________________";
    cout << "_________________________________________\n" << endl ;

    cout << "|" << left << setw(15) << "Acount Number";
    cout << "|" << left << setw(10) << "Pin Code";
    cout << "|" << left << setw(40) << "Client Name" ;
    cout << "|" << left << setw(12) << "Phon";
    cout << "|" << left << setw(12) << "Acount Balance";
    cout << "\n______________________________________________________";
    cout << "_________________________________________\n" << endl ;

    for(stClient Cleint : vCleints){
        PrintClientRecord(Cleint);
        cout << endl ;

    }

}



int main(){
    vector <stClient> vClients = LoadClientDataFromFile();
    PrintAllClientsData(vClients);


    return 0;
}