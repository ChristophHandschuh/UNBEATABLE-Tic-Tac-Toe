#include <iostream>
#include "display.h"
#include <vector>
#include <conio.h>

using namespace std;

void vergleichen();
bool MovesLeft();
int minimax(bool isMax);
void draw();
void player();
int collumsleft();

vector<char>zahlen{' ', ' ', ' ',
                   ' ', ' ', ' ',
                   ' ', ' ', ' '};

bool player1win = false, player2win = false;
int allthebest = -1000, position, b, l=0, zahl;

int main()
{
    console_init();

    vergleichen();

    draw();

    while(l<9 && player1win == false && player2win == false)
    {
        player();
        vergleichen();
        draw();


        if(l<9){
        allthebest = -1000;
        for(int i = 0; i<9; i++)        //Loops throw every possible Position *O* can set
        {
        if(zahlen.at(i) == ' ')
        {
            zahlen.at(i) = 'O';

            b = minimax(false);
            //cout<<i<<" : "<<b<<endl;

            zahlen.at(i) = ' ';

            if(allthebest < b)
            {
                allthebest = b;
                position = i;
            }
        }
        }
        zahlen.at(position) = 'O';
    }
        vergleichen();
        draw();


        if(player2win == true)
        {
            cout<<"Spieler 2 hat gewonnen";
        }

        if(player1win == true)
        {
            cout<<"Spieler 1 hat gewonnen";
        }
        l+=2;
    }
    return 0;
}

void vergleichen()      //Function is used to determine if one player won
{
    player1win = false;
    player2win = false;

    for(int b = 0; b<=2; b++)
    {
        if(zahlen.at(b) == 'X' && zahlen.at(b + 3)== 'X' && zahlen.at(b + 6) == 'X')
        {
            player1win = true;
        }
    }

    for(int b = 0; b<=6; b+=3)
    {
        if(zahlen.at(b) == 'X' && zahlen.at(b + 1)== 'X' && zahlen.at(b + 2) == 'X')
        {
            player1win = true;
        }
    }

    if(zahlen.at(0) == 'X' && zahlen.at(4)== 'X' && zahlen.at(8) == 'X')
    {
        player1win = true;
    }

    if(zahlen.at(2) == 'X' && zahlen.at(4)== 'X' && zahlen.at(6) == 'X')
    {
        player1win = true;
    }

    for(int b = 0; b<=2; b++)
    {
        if(zahlen.at(b) == 'O' && zahlen.at(b + 3)== 'O' && zahlen.at(b + 6) == 'O')
        {
            player2win = true;
        }
    }

    for(int b = 0; b<=6; b+=3)
    {
        if(zahlen.at(b) == 'O' && zahlen.at(b + 1)== 'O' && zahlen.at(b + 2) == 'O')
        {
            player2win = true;
        }
    }

    if(zahlen.at(0) == 'O' && zahlen.at(4)== 'O' && zahlen.at(8) == 'O')
    {
        player2win = true;
    }

    if(zahlen.at(2) == 'O' && zahlen.at(4)== 'O' && zahlen.at(6) == 'O')
    {
        player2win = true;
    }
}

void player()       //Asks Player for Position and Places X there
{
        do{
        cout<<"Spieler eins is dran Zoi: ";
        zahl = _getch() - 48;

        switch(zahl)
        {
        case 1:
            zahl = 7;
            break;
        case 2:
            zahl = 8;
            break;
        case 3:
            zahl = 9;
            break;
        case 4:
            zahl = 4;
            break;
        case 5:
            zahl = 5;
            break;
        case 6:
            zahl = 6;
            break;
        case 7:
            zahl = 1;
            break;
        case 8:
            zahl = 2;
            break;
        case 9:
            zahl = 3;
            break;
        }

        }while((char) zahlen.at(zahl - 1) != ' ');

        zahlen.at(zahl - 1) = 'X';
}

void draw()         //Cleans Screen and draws TicTacToe field
{
    system("cls");
    cout<<" "<<(char)zahlen.at(0)<<" | "<<(char)zahlen.at(1)<<" | "<<(char)zahlen.at(2)<<endl;
    cout<<"___|___|___"<<endl;
    cout<<" "<<(char)zahlen.at(3)<<" | "<<(char)zahlen.at(4)<<" | "<<(char)zahlen.at(5)<<endl;
    cout<<"___|___|___"<<endl;
    cout<<" "<<(char)zahlen.at(6)<<" | "<<(char)zahlen.at(7)<<" | "<<(char)zahlen.at(8)<<endl;
}

bool MovesLeft()      //Checks if there are free fields
{
    for(int i = 0; i<9; i++)
    {
        if(zahlen.at(i) == ' ')
        {
            return true;
        }
    }
    return false;
}

int collumsleft(){          //Checks how many fields are left
    int anz = 0;
    for(int i = 0;i<9;i++){
        if(zahlen.at(i) == ' '){
            anz++;
        }
    }
    return anz;
}

int minimax(bool isMax)     //MiniMax Algo is used to calculate the best move/s
{
    vergleichen();

    if(player1win)
    {
        return -10 - collumsleft();
    }

    if(player2win)
    {
        return 10 + collumsleft();
    }

    if(MovesLeft() == false && player1win == false && player2win == false)
    {
        return 0;
    }

    if(isMax)
    {
        int best = -1000;

        for(int i = 0; i<9; i++)
        {
            if(zahlen.at(i) == ' ')
            {
                zahlen.at(i) = 'O';

                best = max(best, minimax(!isMax));
                zahlen.at(i) = ' ';
            }
        }
        return best;
    }
    else
    {
        int best = 1000;

        for(int i = 0; i<9; i++)
        {
            if(zahlen.at(i) == ' ')
            {
                zahlen.at(i) = 'X';

                best = min(best, minimax(!isMax));
                zahlen.at(i) = ' ';
            }
        }
        return best;
    }
}
