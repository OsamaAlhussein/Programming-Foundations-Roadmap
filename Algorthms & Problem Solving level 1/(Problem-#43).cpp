#include<iostream>
#include<cmath>
using namespace std ;

// Seconde to days hours Minutes seconts 

struct strTaskDuration{
    int Day , Hour , Min , Sec , Reminder;
};

int ReadPositiveNumber(string Message){

    int Num =0 ;
    do
    {
        cout << Message << endl ;
        cin >> Num ;
    }while(Num <=0 );

    return Num ;
}

strTaskDuration SecondsToTaskDuration(int TotalSeconds){
    strTaskDuration TaskDuration ;
    const int SecondsPerDay = (24*60*60) ;
    const int SecondsPerHour = (60*60) ;
    const int SecondsPerMinute = (60) ; 
    TaskDuration.Day = floor(TotalSeconds / SecondsPerDay ) ;
    TaskDuration.Reminder = TotalSeconds % SecondsPerDay ;
    TaskDuration.Hour = floor(TaskDuration.Reminder / SecondsPerHour );
    TaskDuration.Reminder = TaskDuration.Reminder % SecondsPerHour ;
    TaskDuration.Min = floor(TaskDuration.Reminder / SecondsPerMinute);
    TaskDuration.Reminder = TaskDuration.Reminder % SecondsPerMinute ;
    TaskDuration.Sec = TaskDuration.Reminder ; 

    return TaskDuration ;

}

void PrintTaskDuration(strTaskDuration TaskDuration){

    cout << endl << TaskDuration.Day <<" : " << TaskDuration.Hour << " : " << TaskDuration.Min << " : " << TaskDuration.Sec ;
}


int main(){

    int TotalSecond = ReadPositiveNumber("Please enter total second ?");
    PrintTaskDuration(SecondsToTaskDuration(TotalSecond));

    return 0;
}