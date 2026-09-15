
#include<iostream>
#include"clsInputValidate.h"
#include"clsUtility.h"
#include"clsMainScreen.h"
#include"clsLoginScreen.h"
//======



int main(){     


    while(true){

        if(!clsLoginScreen::ShowLoginScreen())
        {
            break;
        }
            

    }
    system("pause>0");
    return 0;
}