#include "Theme.h"
#include<iostream>
#include<windows.h>




using namespace std;
Theme::Theme()
{
    //ctor
}

void Theme::ClearScreen()
{
    system("cls");
}


void Theme::showLoadingAnimation()
{
    ClearScreen();
    cout<<"\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t loading.....!";
//    cout << "\t\t\t\t\t\t";
        for(int i=0; i<=25; i++)
        {
            Sleep(30);
            cout<<loadingCharacter;
        }
}

Theme::~Theme()
{
    //dtor
}
