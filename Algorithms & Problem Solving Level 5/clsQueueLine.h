#pragma once
#include<iostream>
#include<string>
#include"clsDate1.h"
#include<queue>
#include<stack>
using namespace std;


class clsQueueLine
{

private:
    short _TotalTickets = 0;
    short _AverageServedTime = 0;
    string _Prefix ="";

    class clsTicket{

        private:
            short _Number = 0;
            string _Prefix ;
            string _TicketTime ;
            short _WaitingClient = 0;
            short _AverageServedTime = 0;
            short _ExpectedServed =0;


        public:

            clsTicket(string Prefix , short Number , short WaitingClient , short AverageTime){

                _Prefix = Prefix;
                _TicketTime = clsDate::GetSystemDateTimeString();
                _Number = Number ;
                _WaitingClient = WaitingClient ;
                _AverageServedTime = AverageTime ; 
            }

            string Perfix()
            {
                return _Prefix ;
            }

            short Number()
            {
                return _Number ;
            }

            string FullNumber()
            {
                return _Prefix + to_string(_Number);
            }


            string TicketTime()
            {
                return _TicketTime ; 
            }

            short WaitingClient()
            {
                return _WaitingClient;
            }

            short ExpectedServedTime()
            {
                return _AverageServedTime * _WaitingClient ;
            }

            
            void Print()
            {
                cout << "\n\t\t\t ---------------------------\n";
                cout << "\n\t\t\t\t   " << FullNumber() ;
                cout << "\n\n\t\t\t  " << _TicketTime ;
                cout << "\n\t\t\t   Waiting Clients : " << _WaitingClient ;
                cout <<"\n\t\t\t      Served Time In ";
                cout << "\n\t\t\t       " << ExpectedServedTime() << "Minutes.";
                cout << "\n\t\t\t ---------------------------\n";        
            }
        

    };


    public:


    queue <clsTicket> QueueLine ;

    clsQueueLine(string Prefix , short AverageServedTime)
    {
        _Prefix = Prefix ;
        _TotalTickets = 0 ;
        _AverageServedTime = AverageServedTime ;
    }

    void IssusTicket()
    {
        _TotalTickets++ ;
        clsTicket Ticket(_Prefix , _TotalTickets , WaitingClients() , _AverageServedTime);
        QueueLine.push(Ticket) ;
    }

    int WaitingClients()
    {
        return QueueLine.size();
    }

    string WhoIsNext()
    {
        if(QueueLine.empty())
            return "\nNo Client Left\n";
        else
            return QueueLine.front().FullNumber();
    }

    bool ServedNextClient()
    {
        if(QueueLine.empty())
        return false ;

        QueueLine.pop();
        return true ;
    }

    short ServedClients()
    {
        return _TotalTickets - WaitingClients();
    }

    void PrintInfo()
    {
        cout << "\n\t\t\t _________________________\n";
        cout << "\n\t\t\t\tQueue Info";
        cout << "\n\t\t\t _________________________\n";
        cout << "\n\t\t\t    Prefix   = " << _Prefix;
        cout << "\n\t\t\t    Total Tickets   = " << _TotalTickets ;
        cout << "\n\t\t\t    Served Clients  = " << ServedClients();
        cout << "\n\t\t\t    Wating Clients  = " << WaitingClients(); ;
        cout << "\n\t\t\t _________________________\n";
        cout << "\n";
    }


    void PrintTicketsLineRTL()
    {
        if(QueueLine.empty())
            cout << "\n\t\tTickets : NO Tickets.";
        else 
            cout << "\n\t\tTickets : ";

        queue <clsTicket> TempQueueLine = QueueLine ;
        
        while(!TempQueueLine.empty())
        {
            clsTicket Ticket  = TempQueueLine.front();

            cout << "   " << Ticket.FullNumber() << " <-- ";

            TempQueueLine.pop();
        }
        cout <<"\n";
    }


    void PrintTicketsLineLTR()
    {
        if (QueueLine.empty())
            cout << "\n\t\tTickets: No Tickets.";
        else
            cout << "\n\t\tTickets: ";

        //we copy the queue in order not to lose the original
        queue <clsTicket> TempQueueLine = QueueLine;
        stack <clsTicket> TempStackLine;

        while (!TempQueueLine.empty())
        {
            TempStackLine.push(TempQueueLine.front());
            TempQueueLine.pop();
        }

        while (!TempStackLine.empty())
        {
            clsTicket Ticket = TempStackLine.top();

            cout << " " << Ticket.FullNumber() << " --> ";

            TempStackLine.pop();
        }
        cout << "\n";
    }


    void PrintAllTickets()
    {
       
        cout << "\n\n\t\t\t       ---Tickets---";

        if (QueueLine.empty())
        cout << "\n\n\t\t\t     ---No Tickets---\n";

        //we copy the queue in order not to lose the original
        queue <clsTicket> TempQueueLine= QueueLine;

       
        while (!TempQueueLine.empty())
        {
            TempQueueLine.front().Print();
            TempQueueLine.pop();
        }

    }



};