#pragma once
#include<iostream>
#include"clsDaynamicArray.h"
using namespace std ;


template <class T>
class clsMyQueueArr{

    protected:
    clsDaynamicArray <T> _MyDaynamicArray ;

    public:

    void push(T value)
    {
        _MyDaynamicArray.InsertAtEnd(value);
    }

    void pop()
    {
        _MyDaynamicArray.DeleteFirstItem();
    }

    int Size()
    {
        return _MyDaynamicArray.Size();
    }

    bool IsEmpty()
    {
        return _MyDaynamicArray.IsEmpty();
    }

    T front()
    {
        return _MyDaynamicArray.GetItem(0);
    }

    T back()
    {
        return _MyDaynamicArray.GetItem(Size()-1);
    }

    T GetItem(int Index)
    {
        return _MyDaynamicArray.GetItem(Index);
    }

    void UpdateItem(int Index , T value)
    {
         _MyDaynamicArray.SetItem(Index,value) ;
    }

    void InsertAfter(int Index , T value)
    {
        _MyDaynamicArray.InsertAfter(Index,value);
    }

    void InsertAtFront(T value)
    {
         _MyDaynamicArray.InsertAtBeginning(value);
    }

    void InsertAtBack(T value)
    {
        _MyDaynamicArray.InsertAtEnd(value);
    }

    void Clear()
    {
        _MyDaynamicArray.Clear();
    }

    void Reverse()
    {
        _MyDaynamicArray.Revrese();
    }


    void print()
    {
        _MyDaynamicArray.PrintList();
    }


};
