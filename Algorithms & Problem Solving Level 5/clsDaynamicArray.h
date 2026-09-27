#pragma once
#include<iostream>
using namespace std ;

template <class T> 
class clsDaynamicArray{

    protected:
    int _Size ;
    T * _TempArray ;

    public:
    T * OriginalArray ;

    clsDaynamicArray(int Size=0){
        if(Size<0)
        Size =0;


        _Size = Size ;
        OriginalArray = new T[_Size] ;
    }

    ~clsDaynamicArray()
    {
        delete[] OriginalArray ;
    }

    bool SetItem(int Index , T value)
    {
        if(Index >= _Size || _Size < 0)
        {
            return false;
        }

        OriginalArray[Index] = value;
        return true ;

    }

    int Size()
    {
        return _Size ;
    }

    bool IsEmpty()
    {
        return (_Size == 0 ? true : false) ;
    }

    void PrintList()
    {
        for(int i=0 ; i < _Size ; i++)
        {
            cout << OriginalArray[i] << "  ";
        }
        cout << "\n";
    }

    void Resize(int NewSize)
    {
        if(NewSize < 0)
        {
            NewSize = 0 ;
        }

        _TempArray = new T[NewSize];

        if(NewSize < _Size)
        {
            _Size = NewSize;
        }

        for(int i=0 ; i<_Size ;i++)
        {
            _TempArray[i] = OriginalArray[i];
        }

        _Size = NewSize ;
        delete[] OriginalArray;
        OriginalArray = _TempArray ;
    }
    

    T GetItem(int Index)
    {
        return OriginalArray[Index];
    }

    void Revrese()
    {
        _TempArray = new T[_Size] ;
        int counter = 0 ;
        for(int i=_Size-1 ; i>=0 ;i--)
        {
            _TempArray[counter] = OriginalArray[i] ;
            counter++ ;
        }

        delete[] OriginalArray;
        OriginalArray = _TempArray ;
    }

    void Clear()
    {
        _Size =0 ;
        _TempArray = new T[0];
        delete[] OriginalArray ;
        OriginalArray = _TempArray ;
    }

    bool DeleteItemAt(int Index)
    {
        if(Index < 0 || Index > _Size)
        {
            return false;
        }

        _TempArray = new T[_Size] ;
        _Size-- ;

        // Copy all befor index 
        for(int i=0 ; i<Index ; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }
        
        // Copy all after index 
        for(int i= Index+1 ; i<_Size+1 ; i++)
        {
            _TempArray[i-1] = OriginalArray[i] ;
        }
        delete[] OriginalArray;
        OriginalArray = _TempArray ;
        return true ;
    }


    void DeleteFirstItem()
    {
        DeleteItemAt(0);
    }

    void DeleteLastItem()
    {
        DeleteItemAt(_Size-1);
    }


    int Find(T value)
    {
        for(int i=0 ; i<_Size ;i++)
        {
            if(OriginalArray[i]==value)
            {
                return i ;
                
            }
        }
        return -1 ; 
    }


    bool DeleteItem(T value)
    {
        int Index = Find(value);
        if(Index==-1)
        {
            return false;
        }
        DeleteItemAt(Index);
        return true ;
    }

    bool InsertAt(T Index , T value)
    {

        if(Index > _Size || Index < 0)
        {
            return false;
        }

        _Size++ ;
        _TempArray = new T[_Size] ;

        for(int i=0 ; i<Index ; i++)
        {
            _TempArray[i] = OriginalArray[i];
        }
        _TempArray[Index] = value ;

        for(int i=Index+1 ; i<_Size ; i++)
        {
            _TempArray[i] = OriginalArray[i-1] ;
        }

        delete[] OriginalArray ;
        OriginalArray = _TempArray;
        return true ;

    }

    void InsertAtBeginning(T value)
    {
        InsertAt(0,value);
    }

    bool InsertBefor(T Index , T value)
    {
        if(Index < 1)
            return InsertAt(0,value);
        else
            return InsertAt((Index-1) , value);
    }

    bool InsertAfter(T Index , T value)
    {
        if(Index >= _Size)
                return InsertAt(_Size-1 ,value);
            else
                return InsertAt(Index +1 , value);
    }

    void InsertAtEnd(T value)
    {
        InsertAt(_Size , value); 
    }
    
};