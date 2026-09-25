
#include <iostream>
#include "clsDblLinkedList.h"

using namespace std;


int main()
{

    clsDblLinkedList <int> MydblLinkedList;

    if(MydblLinkedList.IsEmpty())
        cout << "\nYes List Is empty \n";
        else 
        cout << "\nNO List Is Not empty \n";

    MydblLinkedList.InsertAtBeginning(5);
    MydblLinkedList.InsertAtBeginning(4);
    MydblLinkedList.InsertAtBeginning(3);
    MydblLinkedList.InsertAtBeginning(2);
    MydblLinkedList.InsertAtBeginning(1);
   
    cout << "\nLinked List Contenet:\n";
     MydblLinkedList.PrintList();
     
     cout << "\nNumber of items in the linked list = "<< MydblLinkedList.Size() << endl  ;

     cout << "\nItem(2) value : " << MydblLinkedList.GetItem(2) ;

     cout << "\n\n";
     MydblLinkedList.InsertAfter(2,500);
     MydblLinkedList.PrintList();

 



    system("pause>0");

}