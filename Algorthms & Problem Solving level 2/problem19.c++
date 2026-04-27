#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std ;

// Random 3 Numbers from 1 to 10
int RandomNumber(int from , int To )
{
    int Random = rand() % (To - from +1 ) + from ;
    return Random ;
}

int main()
{
srand((unsigned)time(NULL));

cout << RandomNumber(1,10) << endl ;
cout << RandomNumber(1,10) << endl ;
cout << RandomNumber(1,10) << endl ;
cout << RandomNumber(1,10) << endl ;
    return 0 ;
}
