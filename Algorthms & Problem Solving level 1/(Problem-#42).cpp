#include<iostream>
using namespace std ;

// Task Duration In Secinde 

struct strTaskDuration{
    int Day , Hour , Min , Sec ;
};

float ReadPositiveNumber(string Message){

    float Num =0 ;
    do
    {
        cout << Message << endl ;
        cin >> Num ;
    }while(Num <=0 );

    return Num ;
}

strTaskDuration ReadTaskDuration(){

    strTaskDuration TaskDuration ;
     TaskDuration.Day = ReadPositiveNumber("Please enter Number of Days ?");
     TaskDuration.Hour = ReadPositiveNumber("Please enter Number of Hour ?");
     TaskDuration.Min = ReadPositiveNumber("Please enter Number of Min ?");
     TaskDuration.Sec = ReadPositiveNumber("Please enter Number of Second ?") ;

    return TaskDuration ;

}

int TaskDurationInSeconds(strTaskDuration TaskDuration)
{
    int TotalSecond ;
    TotalSecond = TaskDuration.Day * 24 * 60 *60 ;
    TotalSecond+= (TaskDuration.Hour * 60 * 60) ;
    TotalSecond+= (TaskDuration.Min * 60);
    TotalSecond+= TaskDuration.Sec ;
    
    return TotalSecond ;
}

int main(){
    int TotalSecond =  TaskDurationInSeconds(ReadTaskDuration()) ;

    cout << "Task Duration In Seconde : " <<TotalSecond ;

    return 0;
}