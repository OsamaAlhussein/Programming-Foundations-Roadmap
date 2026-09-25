
#pragma once 
#include<iostream>
using namespace std ;


template <class T>
class clsDblLinkedList {
    
    protected:
    int _Size = 0;

    public:

    class Node{
        public :

        T value ;
        Node * next ;
        Node * prev ;

    };



    Node * head = NULL ;


    void InsertAtBeginning(T value)
    {
        
        Node * NewNode = new Node ;

        NewNode->value = value ;
        NewNode->next = head ;
        NewNode->prev = NULL ;
        if(head != NULL)
        {
            head->prev = NewNode ;
        }
        head = NewNode ;  
        
        _Size++ ;
    }

    Node * Find(T value){

        Node * Current = head  ;

        while(Current != NULL)
        {
            if(Current->value == value)
            {
                return Current ;
            }
            Current = Current->next ;
        }

        return NULL ;
    }

    void InsertAfter(Node * Current , T value)
    {
        Node * NewNode = new Node ;

        NewNode->value = value ;
        NewNode->next = Current->next ;
        NewNode->prev = Current ;

        if(Current != NULL)
        {
            Current->next->prev = NewNode ;
        }

        Current->next = NewNode;
        _Size++ ;

    }

    void InsertAtEnd(T value)
    {
        Node * NewNode = new Node ;

        NewNode->value = value ;
        NewNode->next = NULL ;

        if(head == NULL)
        {
            NewNode->prev = NULL ;
            head = NewNode ;
        }
        else{
            Node * Current = head ; 
            while(Current->next != NULL)
            {
                Current = Current->next ;
            }
            Current->next = NewNode ;
            NewNode->prev = Current ;
        }
        _Size++ ;

    }

    void DeleteNode( Node * &NodeToDelete)
    {
        if(head == NULL || NodeToDelete == NULL)
        {
            return ;
        }
        if(head == NodeToDelete)
        {
            head = NodeToDelete->next ;
        }
        if(NodeToDelete->next != NULL)
        {
            NodeToDelete->next->prev = NodeToDelete->prev ;
        }
        if(NodeToDelete->prev != NULL)
        {
            NodeToDelete->prev->next = NodeToDelete->next ;
        }

        delete NodeToDelete ;
        _Size-- ;
    }

    void DeleteFirstNode()
    {
        if(head == NULL)
        {
            return ;
        }

        Node * Temp = head ;

        head = head->next ;

        if(head != NULL)
        {
            head->prev = NULL ;
        }

        delete Temp ;
        _Size-- ;

    }

    void DeleteLastNode()
    {
        if(head == NULL)
        {
            return ;
        }

        
        if(head->next == NULL)
        {
            delete head ;
            head = NULL ;
            return ;
        }
        
        Node * Current = head;

        while(Current->next->next != NULL)
        {
           Current = Current->next  ;
        }

        Node * Temp = Current->next ;
        Current->next =NULL ;
        delete Temp ;
        _Size-- ;


    }

    void PrintList()
    {
        
        Node * Current = head ;

        while(Current != NULL)
        {
            cout << Current->value << "   ";
            Current = Current->next ;
        }
        cout << "\n";
        delete Current ;
    }


    int Size()
    {
        return _Size ;
    }

    bool IsEmpty(){
        return (_Size==0 ? true : false) ;
    }

    void Clear()
    {
        while(_Size > 0)
        {
            DeleteFirstNode();
        }
    }

    void Reverse()
    {
        Node * Current = head ;
        Node * temp = nullptr ;

        while(Current != nullptr)
        {
            temp = Current->prev ;
            Current->prev = Current->next ;
            Current->next = temp ;
            Current = Current->prev ; 
        }

        if(temp != nullptr)
        {
            head = temp->prev;
        }
        
    }

    Node * GetNode(int Index)
    {
        int  count =0 ;
        
        if(Index > _Size-1 || Index < 0)
        return NULL; 
        
        
        Node * Current = head ;

        while(Current != NULL && (Current->next != NULL))
        {
            if(count == Index)
            break;

            Current = Current->next ;
            count++;


        }

        return Current ;
    }


    T GetItem(int Index){
        Node * ItemNode  = GetNode(Index);

        if(ItemNode == NULL)
            return NULL ;
        else 
            return ItemNode->value ;
    }

    bool UpdateItem(int Index, T NewValue)
    {
        Node* ItemNode = GetNode(Index);

        if (ItemNode != NULL)
        {
            ItemNode->value = NewValue;
            return true;
        }
        else
            return false;

    }

    bool InsertAfter(int Index , T value)
    {
        Node * ItemNode = GetNode(Index);

        if(ItemNode != NULL)
        {
            InsertAfter(ItemNode,value) ;
            return true ;
        }
        else    
        {
            return false ;
        }
    }





};
