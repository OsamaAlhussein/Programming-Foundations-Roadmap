#include <iostream>   
#include <cstdlib>    
#include <ctime>      
using namespace std;  

enum enQusetionLevel {EasyLevel = 1 , MedLevel = 2 , HardLevel = 3 , Mix = 4};

enum enOpertionType{Add = 1 , Sub = 2 , Mult = 3 , Div = 4 , MixOp = 5};

struct stQusetion{

    short Number1 = 0 ;
    short Number2 = 0 ;
    enOpertionType OpertionType ;
    enQusetionLevel QusetionLevel ;
    int CorrectAnswer = 0  ;
    int PlyerAnswer = 0 ;
    bool AnswerResult = false ;

};

struct stQuizz {

    stQusetion QusetionList[100] ;
    short NumberOfQusetion  ;
    enQusetionLevel QusetionsLevel ;
    enOpertionType OpType ;
    short NumberOfWrongAnswer ;
    short NumberOfRighAnswer ;
    bool isPASS = false ;
};

int RandomNumber(short From , short To)
{
    short Random = rand() % (To - From + 1) + From ;
    return Random ;
}

int ReadHowManyQusetion(){
      short num=0 ;
    do{
        cout << "How Many Qusetions do you want answer ? "; // عدد الأسئلة
        cin >> num ;

    }while(num < 1 || num > 10);

    return num ;
}

string  GetQUstionLevelText(enQusetionLevel QusetionLevel)
{
    string Text[4] ={"Easy" , "Med" , "Hard" , "Mix"};
    return Text[QusetionLevel-1] ;

}



int SimplCalculater(int Number1 , int Number2 , enOpertionType OpType){

    switch(OpType)
    {
        case enOpertionType::Add :
        return Number1 + Number2 ;
        case enOpertionType::Sub:
        return Number1 - Number2 ;
        case enOpertionType::Mult:
        return Number1 / Number2 ;
        case enOpertionType::Div :
        return Number1 * Number2 ;

        default:
        return Number1 + Number2 ;
    }

}

enQusetionLevel ReadQusetionLevel(){
  short  num = 0;
    do{
        cout << "Enter Qusetions 1:[Easy] , 2:[Med] , 3:[Hard] , 4:[Mix] ? ";
        cin >> num ;
    }while(num < 1 || num > 4);
    return (enQusetionLevel) num ;
   
}

enOpertionType ReadOpType(){
    short num = 0 ;

    do{
        cout << "Enter Opretion Type 1:[Add] , 2:[Sub] , 3[Mul] , 4:[Div] , 5:[Mix] ? ";
        cin >> num ;
    }while(num < 1 || num > 5);

    return (enOpertionType) num ;
}

enOpertionType GetRandomOpertionType(){
    short Op = RandomNumber(1,4);
    return (enOpertionType) Op ;
}

stQusetion GeneratQusetion(enQusetionLevel QusetionLevel , enOpertionType OpType){
    stQusetion Qusetion ;

    if(QusetionLevel==enQusetionLevel::Mix)
    {
        QusetionLevel = (enQusetionLevel) RandomNumber(1,3);
    }

    if(OpType==enOpertionType::MixOp)
    {
        OpType = GetRandomOpertionType() ;
    }
    Qusetion.OpertionType = OpType ;


    switch(QusetionLevel)
    {
        case enQusetionLevel::EasyLevel:
        Qusetion.Number1 = RandomNumber(1,10) ;
        Qusetion.Number2 = RandomNumber(1,10) ;

        Qusetion.CorrectAnswer = SimplCalculater(Qusetion.Number1 , Qusetion.Number2 , Qusetion.OpertionType);
        Qusetion.QusetionLevel = QusetionLevel ;
        return Qusetion ;

        case enQusetionLevel::MedLevel:
        Qusetion.Number1 = RandomNumber(10,50);
        Qusetion.Number2 = RandomNumber(10,50);

        Qusetion.CorrectAnswer = SimplCalculater(Qusetion.Number1 , Qusetion.Number2 , Qusetion.OpertionType);
        Qusetion.QusetionLevel = QusetionLevel ;
        return Qusetion ;
        
        case enQusetionLevel::HardLevel:
        Qusetion.Number1 = RandomNumber(50,100);
        Qusetion.Number2 = RandomNumber(50,100);

        Qusetion.CorrectAnswer = SimplCalculater(Qusetion.Number1 , Qusetion.Number2 , Qusetion.OpertionType);
        Qusetion.QusetionLevel = QusetionLevel ;
        return Qusetion ;

    }


}

void GeneratQuizzQusetions(stQuizz & Quizz){

    for(short Qusetion=0 ; Qusetion<Quizz.NumberOfQusetion ; Qusetion++)
    {
        Quizz.QusetionList[Qusetion] = GeneratQusetion(Quizz.QusetionsLevel , Quizz.OpType);
    }
}

string GetOpTypeSymbol(enOpertionType OpType)
{
    switch (OpType)
    {
    case enOpertionType::Add:
        return "+";
    case enOpertionType::Sub:
        return "-";
    case enOpertionType::Mult:
        return "/";
    case enOpertionType::Div:
        return "*";
    default:
        return "Mix";
    }
}

void CorrectTheQusetionAnswer(stQuizz & Quizz , short QusetionNumber)
{
    if(Quizz.QusetionList[QusetionNumber].PlyerAnswer!=Quizz.QusetionList[QusetionNumber].CorrectAnswer)
    {
        Quizz.QusetionList[QusetionNumber].AnswerResult = false ;
        Quizz.NumberOfWrongAnswer++ ;
        system("color 4f");
        cout << "Wrong Answer : -(\n";
        cout << "The right answer is : ";
        cout << Quizz.QusetionList[QusetionNumber].CorrectAnswer ;
        cout << "\n";

    }
    else 
    {
        Quizz.QusetionList[QusetionNumber].AnswerResult = true ;
        Quizz.NumberOfRighAnswer++ ;
        system("color 2f");
        cout << "Right Answer : -)\n";
    }
}

void PrintTheQusetion(stQuizz & Quizz , short QusetionOfNumber){

    cout << "\n";
    cout << "Qusetion[" << QusetionOfNumber + 1 <<"/" << Quizz.NumberOfQusetion << "]\n\n";
    cout << Quizz.QusetionList[QusetionOfNumber].Number1 << endl ;
    cout << Quizz.QusetionList[QusetionOfNumber].Number2 << " " ;
    cout << GetOpTypeSymbol(Quizz.QusetionList[QusetionOfNumber].OpertionType);
    cout << "\n__________________" << endl ;
}

short ReadQusetionAnswer(){
    short Answer =0  ;
    cin >> Answer ;
    return Answer ;
}

void AskAndCorrectQuestionListAnswers(stQuizz & Quizz ){

    for (short Qusetion = 0 ; Qusetion< Quizz.NumberOfQusetion ; Qusetion++)
    {
        PrintTheQusetion(Quizz , Qusetion);

        Quizz.QusetionList[Qusetion].PlyerAnswer = ReadQusetionAnswer();

        CorrectTheQusetionAnswer(Quizz , Qusetion);
    }

    Quizz.isPASS = (Quizz.NumberOfRighAnswer>=Quizz.NumberOfWrongAnswer);
}

string GetFainlResult(bool PASS){

    if(PASS)
    return "PASS : -)";
    else 
    return "Fail : -(";
}



void PrintQuizzResult(stQuizz Quizz)
{
    cout << "\n";
    cout << "---------------------------\n";
    cout << "        Final Result is " << GetFainlResult(Quizz.isPASS);
    cout << "\n\n---------------------------\n";
    
    cout << "Number of Qusetion : " << Quizz.NumberOfQusetion << endl ;
    cout << "Qusetion Level : "<< GetQUstionLevelText(Quizz.QusetionsLevel)  << endl ;
    cout << "Op Tyoe : " << GetOpTypeSymbol(Quizz.OpType) << endl ;
    cout << "Number of Right : " << Quizz.NumberOfRighAnswer << endl; 
    cout << "Number of Wrong : " << Quizz.NumberOfWrongAnswer ;
    cout << "\n--------------------------------";
}

void PlayMath()
{
    stQuizz Quizz ;
    Quizz.NumberOfQusetion = ReadHowManyQusetion();
    Quizz.QusetionsLevel = ReadQusetionLevel();
    Quizz.OpType = ReadOpType();

    GeneratQuizzQusetions(Quizz);
    AskAndCorrectQuestionListAnswers(Quizz);
    PrintQuizzResult(Quizz); 
}

void RestSecreen(){

    system("cls");
    system("color 0f");
}

void StartGame(){

    char Y = 'y' ;
    do {
        RestSecreen();
        PlayMath();

        cout << endl << "Do you Want to play again? Y/y ";
        cin >> Y ; 
    }while(Y=='y' || Y=='Y');


}

int main()
{
    srand((unsigned)time(NULL));

    StartGame();
    
    return 0 ; 
    
}