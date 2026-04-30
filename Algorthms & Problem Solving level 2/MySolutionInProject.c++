#include<iostream>
#include<ctime>
using namespace std ;

/*ًWriting Program , A game simpl (Ston , Peper , Scissor) ,
A game between the user and the computer . Here is the code and this is my solution */


enum enGameChoice {Stone = 1, Paper = 2, Scissor = 3} ;

enum enTheWinner{Plyer=1 , Computer=2 , Draw=3};

struct stRoundGame{

    int RoundNumber =0 ;
    enGameChoice PlyerChoice  ;
    enGameChoice Computerchoice ;
    enTheWinner Winner ;
    string NameWinner = "";

};


int RandomNumber(int From , int To){
    int Random = rand() % (To - From +1) +From ;
    return Random ; 
}

int HowManyRounds(){
    int Num=0 ;
    do{

    cout << "How Many Rounds the game will be 1 to 10\n";
    cin >> Num ;
    }while(Num > 10 || Num < 1);

    return Num ;   
}

enGameChoice PlyerChoice(){
    int Num =1 ;
    do{
        cout << "\nYour Choice : [1]:Ston , [2]:Peper , [3]:Scissor ? ";
        cin >> Num ;

    }while(Num < 1 || Num > 3);
    return (enGameChoice) Num ;
     
}

enGameChoice ComputerChoice(){
    return (enGameChoice) RandomNumber(1,3) ;
}


enTheWinner WhoWomTheRound(stRoundGame Round){

    if(Round.PlyerChoice == Round.Computerchoice){
        return enTheWinner::Draw ;
    }

    
    switch(Round.PlyerChoice){

        case enGameChoice::Stone :
        if(Round.Computerchoice == enGameChoice::Scissor)
        return enTheWinner::Plyer ;
        break;

        case enGameChoice::Scissor:
        if(Round.Computerchoice == enGameChoice::Paper)
        return enTheWinner::Plyer ;
        break;

        case enGameChoice::Paper:
        if(Round.Computerchoice == enGameChoice::Stone)
        return enTheWinner::Plyer ;
        break;

    } 

     return enTheWinner::Computer ;
}

string ChoiceName(enGameChoice Choice){

    string arrChoice[3] = {"Ston" , "Peper" , "Scissor"};

    return arrChoice[Choice - 1] ;
}

string WinnerName(enTheWinner Winner){
    
    switch(Winner)
    {
        case enTheWinner::Plyer:
        system("color 2f");
        return "[Plyer]";
        break;

        case enTheWinner::Computer:
        system("color 4f");
        return "[Computer]";
        break;

        case enTheWinner::Draw :
        system("color 6f");
        return "[Not Winner]";
        break;
    }
};


void PrintRound(stRoundGame RoundGame){

    cout << "__________Round [" << RoundGame.RoundNumber << "]__________\n";
    cout << "\nPlyer Choice    : " << ChoiceName(RoundGame.PlyerChoice);
    cout << "\nComputer Choice : " << ChoiceName(RoundGame.Computerchoice);
    cout << "\nRound Winner    : " << RoundGame.NameWinner ;
    cout << "\n______________________\n";
    
}


void RoundGame(short HowManyRound){

    stRoundGame Round ;

    for(int Roundnumber=1 ; Roundnumber <= HowManyRound ; Roundnumber++){


    Round.RoundNumber = Roundnumber ;
    Round.PlyerChoice = PlyerChoice() ;
    Round.Computerchoice = ComputerChoice();
    Round.Winner = WhoWomTheRound(Round) ;
    Round.NameWinner = WinnerName(Round.Winner) ;

 

    PrintRound(Round) ;
    }

}

void SecreenColor(){
system("cls");
system("color 0f");
}

void StartGame(){

    char playagain = 'y';
    do{
        SecreenColor();
        int RoundNumber = HowManyRounds() ;
        RoundGame(RoundNumber) ;


        cout << "Do you want to play again ? (Y/N) : ";
        cin >> playagain ;

    }while(playagain=='y' || playagain=='Y');
}


int main(){

    srand((unsigned)time(NULL));
StartGame();

    return 0;
}
