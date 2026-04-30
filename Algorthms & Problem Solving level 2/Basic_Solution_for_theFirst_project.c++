#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std ;

enum enGameChoise{Ston =1 , Paper =2 , Scissor=3};

enum enWinner{Plyer1=1 , Computer =2 , Draw=3};

struct stRoundInfo{

    short RoundNumber =0 ;
    enGameChoise Plyer1Choise ;
    enGameChoise Computer2Choise ;
    enWinner Winner ;
    string NameWiner ="";
};


struct stGameResult{

    short RoundNumber =0 ;
    short  Plyer1WinTimes = 0 ;
    short Computer2WinTimes =0 ;
    short DrawTimes = 0 ;
    enWinner Winner ;
    string NameWinner="" ;

};


short ReadHowMany(){

    short Num = 1 ;
    do{

        cout << "How many rounds the game will be 1 to 10 ?\n";
        cin >> Num ;

    }while(Num < 1 || Num > 11);

    return Num ; 
}

short RandomNumber (short From , short To){

    short Random = rand() % (To - From + 1) + From ;
    return Random ;

}


enGameChoise ReadPlyer1Chiose(){

short Num =1 ;
do{
    cout << "Your Choice: [1]:Stone, [2]:Paper, [3]:Scissors?  ";
    cin >> Num ;

}while(Num < 1 || Num > 3);

return (enGameChoise)Num ;

}

enGameChoise GetComputer2Choise(){

    return (enGameChoise)RandomNumber(1,3);
}

enWinner WhoWonRound(stRoundInfo RoundInfo){

    if(RoundInfo.Plyer1Choise==RoundInfo.Computer2Choise)
    return enWinner::Draw;

    switch(RoundInfo.Plyer1Choise)
    {
        case enGameChoise::Ston:
        if (RoundInfo.Computer2Choise==enGameChoise::Paper)
        return enWinner::Computer;
        break;

        case enGameChoise::Paper:
        if(RoundInfo.Computer2Choise==enGameChoise::Scissor)
        return enWinner::Computer ;
        break; 

        case enGameChoise::Scissor:
        if(RoundInfo.Computer2Choise==enGameChoise::Ston)
        return enWinner::Computer;

    }

   
    return enWinner::Plyer1 ;

}


string  WinnerName(enWinner Winner )
{

    string arrWinner[3] = {"Plyer1" , "Computer" , "Draw"};
    return arrWinner[Winner - 1 ] ;

}

string Choise(enGameChoise Choise )
{
    string arrChois[3] = {"Ston" , "Paper" , "Scissor"};
    return arrChois[Choise  - 1];
}

void SetWinColor(enWinner Winner){
    
    switch(Winner)
    {
        case enWinner::Plyer1 :
        system("color 2f");
        break; 

        case enWinner::Computer:
        system("color 4f");
        cout << "\a";
        break; 

       default:
        system("color 6f");
        break; 
    }
}

void PrintGame(stRoundInfo RoundInfo)
{
    cout << "\n_____________["<<RoundInfo.RoundNumber<<"]____________\n";
    cout << "Plyer1 Choisse : "<<Choise(RoundInfo.Plyer1Choise)  << endl ;
    cout << "Computer Choise : "<<Choise(RoundInfo.Computer2Choise)<<endl ;
    cout << "Round Winner : [" << RoundInfo.NameWiner <<"]"<< endl  ;
    cout << "______________________________\n";
    SetWinColor(RoundInfo.Winner);
}


enWinner WhoWinTheGame(short Plyer , short Computer)
{
    if(Plyer>Computer)
    return enWinner::Plyer1;
   else if (Plyer<Computer)
    return enWinner::Computer;
   else  if(Plyer==Computer)
    return enWinner::Draw;
}


stGameResult FullGameResult(int  GameRound , short Plyer1WinTimes , short ComputerWinTimes , short DrawTimes)
{
    stGameResult GameResult ;
    GameResult.RoundNumber = GameRound ;
    GameResult.Plyer1WinTimes = Plyer1WinTimes ;
    GameResult.Computer2WinTimes = ComputerWinTimes ;
    GameResult.DrawTimes = DrawTimes ;
    GameResult.Winner = WhoWinTheGame(Plyer1WinTimes,ComputerWinTimes);
    GameResult.NameWinner = WinnerName(GameResult.Winner);

    return GameResult ;
}

stGameResult PlayGame(short HowManyRound)
{
    short Player1WinTimes = 0 , Computer2WinTimes=0 , DrawWinTimes =0 ;
    stRoundInfo RoundInfo ;

    for (short  GameRound=1 ; GameRound<=HowManyRound ; GameRound++)
    {
        RoundInfo.RoundNumber = GameRound ;
        RoundInfo.Plyer1Choise = ReadPlyer1Chiose();
        RoundInfo.Computer2Choise = GetComputer2Choise();
        RoundInfo.Winner = WhoWonRound(RoundInfo);
        RoundInfo.NameWiner = WinnerName(RoundInfo.Winner);


        if(RoundInfo.Computer2Choise>RoundInfo.Plyer1Choise)
        Computer2WinTimes++;
        else if (RoundInfo.Computer2Choise<RoundInfo.Plyer1Choise)
        Player1WinTimes++;
        else if(RoundInfo.Computer2Choise==RoundInfo.Plyer1Choise)
        DrawWinTimes++;

        PrintGame(RoundInfo);

    }

    return FullGameResult(HowManyRound , Player1WinTimes , Computer2WinTimes , DrawWinTimes);
     
}


string Tabs(short howmany){

    string t = "";
    for (int i =0 ; i<=howmany ; i++)
    {
        t = t +"\t";
        cout << t ;
    }
    return t ;
}

void ShowGameOverScreen(){

cout << Tabs(0) << "-------------------------------------------------\n\n";
cout << Tabs(0) << "               +++ G a m e O v e r +++\n";
cout << Tabs(0) << "-------------------------------------------------\n\n";

}

void   ShowFinalGameOverScreen(stGameResult GameResult){
    
cout <<Tabs(0) << " Game Rounds : "<<GameResult.RoundNumber << endl ;
cout <<Tabs(0) <<" Plyer1 won times : "<< GameResult.Plyer1WinTimes << endl ;
cout <<Tabs(0) << " Computer won times : "<<GameResult.Computer2WinTimes << endl ;
cout <<Tabs(0) << " Draw times : "<< GameResult.DrawTimes<<endl ;
cout <<Tabs(0) << " Final Winner : "<< GameResult.NameWinner <<endl;
cout <<Tabs(0) << "-------------------------------------------------";


}

void SecreenColor(){
system("cls");
system("color 0f");
}

void StartGame()
{
    char PlayAgain = 'Y';
    do{
        SecreenColor();
        
        stGameResult GameResult = PlayGame(ReadHowMany());
         ShowGameOverScreen();
         ShowFinalGameOverScreen(GameResult);
              

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> PlayAgain ;

    }while(PlayAgain=='Y' || PlayAgain=='y');
     
}

int main(){

srand((unsigned)time(NULL));
StartGame();


    return 0 ; 
}