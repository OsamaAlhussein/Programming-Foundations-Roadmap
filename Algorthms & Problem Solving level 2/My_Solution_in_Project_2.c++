#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
using namespace std ;

/*This project is a sports game. For example, the user chooses the difficulty and type of question. 
This is my solution for this project.*/

enum enLevel{Easy=1 , Med=2 , Hard=3 , Mix=4};

struct stGame{

  short HowMany = 0 ;
    short QusetionLevel = 0 ;
    short QusetionType = 0 ;



};

int  RandomNumber(short From ,  short To){
    
    short Random = rand() % ( To - From  + 1) + From ;
    return Random ;
}

short HowMany(){
    short num ;
    do{
        cout << "How Many Qusetions do you want answer ?"; // عدد الأسئلة
        cin >> num ;

    }while(num < 0);
    return num ;
}


enLevel QusetionLevel(){  // صعوبة, مستوى السؤال

    short  num = 0;
    do{
        cout << "Enter Qusetions 1:[Easy] , 2:[Med] , 3:[Hard] , 4:[Mix] ? ";
        cin >> num ;
    }while(num < 1 || num > 4);

    return (enLevel)num ;
}

short  QusetionType(){      // نوع السؤال 
    short num = 0 ;

    do{
        cout << "Enter Opretion Type 1:[Add] , 2:[Sub] , 3[Mul] , 4:[Div] , 5:[Mix] ? ";
        cin >> num ;
    }while(num < 1 || num > 5);

    return num ;
}

string  LeveLName(short level){   

    string arrLevel[4]={"Easy" , "Med" ,  "Hard" , "Mix"};
    return arrLevel[level - 1];
}

string TypeName(short  Type){
    string arrTyp[5]= {"Add" , "Sub" , "Mul" , "Div" , "Mix"};
    return arrTyp[Type -1] ;
}


void COLOR(short NUM , short VALUE)
{
if(NUM==VALUE)
{
    
    system("color 2f");
    cout << "Right Answer :-)\n\n";
}
else {
    system("color 4f");
cout << "Right Answer :-(\n";
cout << "The right answer " << VALUE  << "\n\n";

}
}



void  Add(short num1 , short num2){
short NUM  , SUM ;
  cout << num1 << "\n";
        cout << "+\n";
        cout << num2 <<endl ;
        SUM = num1 + num2 ;
        cout << "_____________\n";
        cin >> NUM ;
     COLOR(NUM,SUM);
}

void Sud(short num1 , short num2){
   short NUM  , SUD ;
  cout << num1 << "\n";
        cout << "-\n";
        cout << num2 <<endl ;
        SUD = num1 - num2 ;
        cout << "_____________\n";
        cin >> NUM ;
     COLOR(NUM,SUD);
    
}

void MUL(short num1 , short num2)
{
       short NUM  , MUD ;
  cout << num1 << "\n";
        cout << "/\n";
        cout << num2 <<endl ;
        MUD = num1 / num2 ;
        cout << "_____________\n";
        cin >> NUM ;
     COLOR(NUM,MUD);
}

void DIV(short num1 , short num2){
        short NUM  , DIV ;
  cout << num1 << "\n";
        cout << "x\n";
        cout << num2 <<endl ;
        DIV = num1 * num2 ;
        cout << "_____________\n";
        cin >> NUM ;
     COLOR(NUM,DIV);
}

void MIXType(short num1 , short num2 ){   //الأسئلة متنوعة من (جمع و طرح ....)

    
    short N = RandomNumber(1,4);
    switch(N)
    {
        case 1 :
        {
            Add(num1 , num2);
            break;
        }
        case 2 :
        {
            Sud(num1 , num2);
            break;
        }
        case 3 :
        {
             MUL(num1,num2);
             break; 
        }
        case 4 :
        {
          DIV(num1,num2);
          break;  
        }

    }

}

void TypeAnswer(short  Type ,short num1 , short num2)
{
 
    switch(Type)
    {
        case 1 :
        {
            Add(num1 , num2);
            break;
        }
        case 2 :
        {
            Sud(num1 , num2);
            break;
        }
        case 3 :
        {
            MUL(num1,num2);
            break;
        }
        case 4 :
        {
            DIV(num1,num2);
            break;
        }
        case 5 :
        {
            
             MIXType(num1,num2);
             break; 
        }

    }
}

void EasyLevel(short  Type){
    short num1 = RandomNumber(1,10);
    short num2 = RandomNumber(1,10);

    TypeAnswer(Type,num1,num2);
}

void MedLevel(short  Type){

    short num1 = RandomNumber(10,50);
    short num2 = RandomNumber(10,50);

     TypeAnswer(Type,num1,num2);

}

void HardLevel(short  Type){

    short num1 = RandomNumber(50,100);
    short num2 = RandomNumber(502,100);

    TypeAnswer(Type,num1,num2);

}

void MIXQusetions(short Type ){   //صعوبة السؤال (متنوعة) 

short N = RandomNumber(1,3);

    switch(N)
    {
        case 1 :
        {
        EasyLevel(Type);
        break;
        }
       

        case 2 :
        {
        MedLevel(Type);
        break;
        }
      

        case 3 :
        {
        HardLevel(Type);
         break;
        }
        

    }
  

}


void AthleticTeaining(short  Type , int  Level){ //تمرين الرياضي 


    switch (Level)
    {
        case 1 :
        {
             EasyLevel(Type);  //مستوى السهل 
             break;
        }
        case 2 :
        {
            MedLevel(Type); // مستوى المتوسط
            break; 
        }
        case 3 :
        {
            HardLevel(Type); // مستوى الصعب
            break;
        }
        default :
        {
              
        MIXQusetions(Type); //مشكل مستوى
        break;

        }


    }

    

}

void RoundsNumber(short i , short rounde)
{
    cout << "Qusetion["<< i << "/" << rounde << "]\n\n"; 
}

void MathGame(){
stGame Game ;
Game.HowMany = HowMany();
Game.QusetionLevel = QusetionLevel() ;
Game.QusetionType = QusetionType();

for(int i = 1 ; i <= Game.HowMany ; i++)
{
    RoundsNumber(i,Game.HowMany);
    AthleticTeaining(Game.QusetionType , Game.QusetionLevel) ;
}

}
void SecreenColor(){
system("cls");
system("color 0f");
}

void StartGame(){

    char Y='y';
    do{
        SecreenColor();
        MathGame();

        cout << "Do you want play math game again (Y/N) ? ";
        cin >> Y ;

    }while(Y=='y' || Y=='Y');
}


int main(){
srand((unsigned)time(NULL));

StartGame();





    return 0 ;
}
