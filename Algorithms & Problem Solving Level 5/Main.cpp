#include<iostream>
#include"clsQueueLine.h"
using namespace std ;



int main(){

   
    clsQueueLine PayBillsQueue("A0", 10);

    PayBillsQueue.IssusTicket();
    PayBillsQueue.IssusTicket();
    PayBillsQueue.IssusTicket();
    PayBillsQueue.IssusTicket();


        cout << "\nPay Bills Queue Info:\n";
        PayBillsQueue.PrintInfo();


        PayBillsQueue.PrintTicketsLineRTL();
        PayBillsQueue.PrintTicketsLineLTR();


        PayBillsQueue.PrintAllTickets();




    return 0;
}