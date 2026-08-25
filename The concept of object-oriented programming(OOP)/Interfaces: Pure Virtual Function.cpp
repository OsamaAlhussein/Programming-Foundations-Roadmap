#include<iostream>
using namespace std ;


// Abstract class / Interface / Contract. 
class clsMobile{
    
    virtual void Dial(string PhonNumber) =0 ;
    virtual void SendSMS(string PhonNubmer , string Text) = 0;
    virtual void TakePicture() = 0;
};


class clsiPhon : public clsMobile{

    void Dial(string PhonNumber){


    }
    void SendSMS(string PhonNubmer , string Text){


    }
    void TakePicture(){


    }

};


class clsSamsung : public clsMobile{

    
    void Dial(string PhonNumber){


    }
    void SendSMS(string PhonNubmer , string Text){


    }
    void TakePicture(){


    }

};



int main(){

    clsiPhon Iphon1 ;
    clsSamsung Samsung ;

    return 0;
}
