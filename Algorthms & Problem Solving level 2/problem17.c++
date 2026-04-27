#include<iostream>
using namespace std ;

string ReadPassword()
{
    string pas ;
    cout << "Please enter a 3-Letter Password (all capital)?\n";
    cin >> pas ;
    return pas ;
}

bool GuessPassword(string OriginalPassword){

   int  counter =0 ;
   string  word="" ;
    for (int i = 65 ; i<=90 ; i++)
    {

        for(int j=65 ; j<=90; j++)
        {

            for(int k=65 ; k<=90 ; k++)
            {
                
               word +=  char(i) ;
               word+= char(j) ;
               word+= char(k) ;

                counter++ ;

                 cout << "Trial [" << counter << "] : " << word  << endl;


                 if (word==OriginalPassword){

                      cout << "\nPassword is " << word << "\n";
                    cout << "Found after " << counter << " Trial(s)\n";

                    return true ;
                    
                 }

                 word="";
            }

        }

    }
    return false;
}





int main(){


    GuessPassword(ReadPassword());


    return 0 ;
}
