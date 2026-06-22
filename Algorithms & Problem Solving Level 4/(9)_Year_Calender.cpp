#include<iostream>
#include<iomanip>
using namespace std ;

// Function to check if a year is a leap year
bool IsLeapYear(short Year){
    return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

// Function to calculate the day of the week for a specific date (Zeller's Congruence / Gregorian)
short DayOfWeekOrder(short Year , short Month , short Day){
    short a = ((14 - Month) / 12) ;
    short y = (Year - a) ;
    short m = Month + (12 * a) - 2 ;
    return (Day + y + (y/4) - (y/100) + (y/400) + (31 * m/12)) % 7 ;
}

// Function to get the short name of the day
string DayShortname(short DayOfWeekOrder){
    string arrNameDay[] = {"Sun" , "Mon" , "Tue" , "Wed" , "Thu" , "Fri" , "Sat"};
    return arrNameDay[DayOfWeekOrder];
}

// Function to get the total number of days in a specific month
short NumberOfDaysInMonth(short Year , short Month){
    int NumberOfDay[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; // Array size is 12 (Jan to Dec)

    if(Month < 1 || Month > 12)
        return 0 ;

    return (Month == 2) ? ((IsLeapYear(Year)) ? 29 : 28) : NumberOfDay[Month-1] ;
}

// Function to get the short name of the month
string MonthShortName(short MonthName){
    string Month[12] = {"Jan" , "Feb" , "March" , "Apr" , "May" , "June" ,
                        "July" , "Aug" , "Sep" , "Oct" , "Nov" , "Dec"};
    return (Month[MonthName-1]);
}

// Function to print the monthly calendar layout
void PrintMonthCalender(short Year , short Month){
    short current = DayOfWeekOrder(Year, Month, 1); // Get starting day index (0 for Sun, 1 for Mon, etc.)
    short NumberOfDays = NumberOfDaysInMonth(Year, Month);

    // Print the month header
    printf("\n_______________ %s _______________\n\n", MonthShortName(Month).c_str());

    // Print weekdays column headers
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    // Print appropriate leading spaces before the first day of the month
    int i;
    for(i = 0; i < current; i++) {
        printf("     ");
    }

    // Loop to print all the days of the month
    for(int j = 1; j <= NumberOfDays; j++) {
        printf("%5d", j);

        // If we reach the end of the week (Saturday), print a new line and reset counter
        if (++i == 7) {
            i = 0;
            printf("\n");
        }
    }
    printf("\n_____________________________________\n");
}

// Function to read the year from user input
short ReadYear(){
    short Year ;
    cout << "Please enter a year? ";
    cin >> Year ;
    return Year ;
}

// Function to read the month from user input
short ReadMonth(){
    short Month ;
    cout << "Please enter a month? ";
    cin >> Month ;
    return Month ;
}

void PrintYearCalender(short Year){

    printf("\n _________________________________\n\n");
    printf("               Calendar - %d\n", Year );
    printf("\n_________________________________");


    for(int i=1 ; i<=12 ; i++){
        PrintMonthCalender(Year, i);
        cout << "\n\n";
    }

    return  ;
}

int main(){
    short Year = ReadYear();
    
    PrintYearCalender(Year);
   


    

    
    system("pause"); 

    return 0;
}