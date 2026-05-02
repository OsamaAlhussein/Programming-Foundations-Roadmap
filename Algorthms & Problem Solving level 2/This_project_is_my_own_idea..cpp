#include<iostream>
#include<string>
using namespace std ;

/*This program is from a thinker.

Input: The user enters the desired number of students and their information.
Output: Information on the student with the highest score, information on the student with the lowest score, and the average of the students' scores.
This is the solution to the program I wrote. */

struct stInfoStudent{
    string FullName = "";
    string Id = "" ;
    float Gread = 0;
};

struct stAllStudents{
    stInfoStudent StudentList[100] ;
    int StudentOfNumber =0 ;
    float HighestMark =0 ;
    float AvreageStudentGreads = 0;
    float LowestMark = 0 ;
};

int HowManyStudents(){
    int Num = 1;
    do{
    cout << "How Many want Student Number 1 to 10 ? ";
    cin >> Num ;

    }while(Num < 1 || Num > 10);
    
return Num ;
}

string ReadFullName(){
    string FullName ="";
    cout << "Please Enter Student Full Name ? ";
    cin >> FullName ;
    return FullName ;
}

string StudentId(){
    string Id ;
    cout << "Please Enter Student Id ? ";
    cin >> Id ;
    return Id ;
}

float ReadGerad(){
    float Gerad ;
    do{

    cout << "Please Enter Student Gerad from 100 ? ";
    cin >> Gerad ;
    }while(Gerad < 1 || Gerad > 100 );
    return Gerad ;
}

stInfoStudent GetInfoStudent(){
    stInfoStudent InfoStudent ;

    InfoStudent.FullName = ReadFullName();
    InfoStudent.Id = StudentId();
    InfoStudent.Gread = ReadGerad();

    return InfoStudent ;
}

void GenaretInfoStudent(stAllStudents & Student){

    for(int Num=1 ; Num <= Student.StudentOfNumber ; Num++){
        cout << "\n\nInformation Student [" << Num <<"/" << Student.StudentOfNumber << "]";
        cout << "\n___________________________\n"; 
        Student.StudentList[Num] = GetInfoStudent();
        cout << "___________________________\n";
    }
}

float Highest_Mark(stAllStudents  Student){

    float MaxMark = 0 ;
    for (int i=1 ; i<=Student.StudentOfNumber ; i++){

        if(MaxMark < Student.StudentList[i].Gread)
        {
            MaxMark = Student.StudentList[i].Gread ;
        }
    }
    return MaxMark ;
}

float Lowest_Mark(stAllStudents  Student){
    float MinMArk = Student.StudentList[1].Gread ;

    for(int i=1 ; i<=Student.StudentOfNumber ; i++){

        if(MinMArk >= Student.StudentList[i].Gread){

            MinMArk = Student.StudentList[i].Gread ;
        }
    }
    return MinMArk ;
}

float SumOfGreads(stAllStudents  Student){

    int Sum = 0;
    for(int i=1 ; i<=Student.StudentOfNumber ;i++){

        Sum+=Student.StudentList[i].Gread ;
    }

    return Sum ;
}

float AvreageStudentGreads(stAllStudents  Student){
    return SumOfGreads(Student) / Student.StudentOfNumber ;
}

void PrintInfoStudentHighwst(stAllStudents  Student){

    for(int i=1 ; i<=Student.StudentOfNumber ; i++){

        if(Student.StudentList[i].Gread==Highest_Mark(Student)){
            cout << "\n_______________[The Student]_________________________\n";
            cout << "The Student with the Highest mark is : " << Student.HighestMark 
            << " | Student Full Name : " << Student.StudentList[i].FullName 
            << " | Id for him (" << Student.StudentList[i].Id << ") . "; 
            cout << "\n_____________________________________________________\n";
            break; 
        }

    }


    
    
}

void PrintInfoStudentLowest(stAllStudents  Student){

     for(int i=1 ; i<=Student.StudentOfNumber ; i++){

        if(Student.StudentList[i].Gread==Lowest_Mark(Student)){
            cout << "\n_______________[The Student]_________________________\n";
            cout << "The Student with the Lowest mark is : " << Student.HighestMark 
            << " | Student Full Name : " << Student.StudentList[i].FullName 
            << " | Id for him (" << Student.StudentList[i].Id << ") . ";
            cout << "\n_____________________________________________________\n";
            break;  
        }

    }

}


void PrintGeneralInformation(stAllStudents  Student){
    cout << "\n___________________________________________________\n";
    cout << "The Student with the Highest  mark is : " << Student.HighestMark << endl ;
    cout << "The average grades of students are   : " << Student.AvreageStudentGreads << endl ;
    cout << "The Student with the Lowest  mark is : " << Student.LowestMark << endl ; 
    cout << "\n___________________________________________________\n";
}

void PrintAllInformation(stAllStudents  Student){

    PrintInfoStudentHighwst(Student);
    PrintInfoStudentLowest(Student);
    PrintGeneralInformation(Student);

}

void SimpleCalculation(stAllStudents & Student){
    Student.HighestMark = Highest_Mark(Student);
    Student.LowestMark = Lowest_Mark(Student);
    Student.AvreageStudentGreads = AvreageStudentGreads(Student);
    
}

void OrganizingStudents(){

     stAllStudents Students ;

    Students.StudentOfNumber = HowManyStudents() ;

 
    GenaretInfoStudent(Students);
    SimpleCalculation(Students);
    PrintAllInformation(Students);


}


int main(){

    OrganizingStudents();
   
    return 0;
}
