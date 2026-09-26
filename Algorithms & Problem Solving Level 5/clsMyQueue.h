#pragma once 
#include<iostream>
#include"clsDblLinkedList.h"
using namespace std ;


template <class T>
class clsMyQueue{

    protected:
    clsDblLinkedList <T> _MyList ;

    public:
    void push(T Item)
    {
       _MyList.InsertAtEnd(Item);
    }


    void pop()
    {
        _MyList.DeleteFirstNode();
    }

    void print()
    {
        _MyList.PrintList();
    }

    int size()
    {
        return _MyList.Size() ;
    }

    bool IsEmpty()
    {
       return  _MyList.IsEmpty();
    }

    T front()
    {
       return _MyList.GetItem(0);
    }

    T back()
    {
       return _MyList.GetItem(size()-1);
    }

    T GetItem(int Index)
    {
       return _MyList.GetItem(Index);
    }

    void Reverse()
    {
        _MyList.Reverse();
    }

    bool UpdateItem(int Index , T value)
    {
       return _MyList.UpdateItem(Index,value);
    }

    bool InsertAfter(int Index , T value)
    {
       return _MyList.InsertAfter(Index,value);
    }

    void InsertAtFront(T value)
    {
        _MyList.InsertAtBeginning(value);
    }

    void InsertAtBack(T value)
    {
        _MyList.InsertAtEnd(value);
    }

    void Clear()
    {
        _MyList.Clear();
    }

};