#include <vector>
#include <iostream>
#include <string>
using namespace std;
const int NUM_SQUARES = 9;
const char EMPTY = ' ';
const int ROWS = 3;
const int COLUMNS = 3;
const char NO_ONE = 'N';
const char TIE = 'T';
const char X = 'x';
const char O = 'o';
void instructions();
char playerSymbol();
char OponentSymbol(char Symbol);
char Winner();
bool AskYesNo(string question);

int main()
{
    char Player = playerSymbol()? X : O;
    char Computer = Player == X? O : X;
    char Turn = X;
    vector<char> board(NUM_SQUARES, EMPTY);    
    instructions();
}


void instructions()
{
    char boardoptions[ROWS][COLUMNS] = { {'0', '1', '2'},
                                         {'3', '4', '5'},
                                         {'6', '7', '8'} };

    cout << "Bienvenido a un nuevo TicTacToe" << endl;
    cout << "En este juego te enfrentaras a una IA basica" << endl;
    cout << "El tablero siguiente representa tus controles, recuerdalos bien" << endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            cout << boardoptions[i][j];
        }
        cout << endl;
    }
}

char playerSymbol()
{
    char GoFirst = AskYesNo("Quisieras empezar el juego?");
    if (GoFirst == 'y')
    {
        return X;
    }
    else
    {
        return O;
    }
}
char OponentSymbol(char Symbol)
{
    if (Symbol == X)
    {
        return O;
    }
    else if (Symbol == O)
    {
        return X;
    }
}

bool AskYesNo(string question)
{
    char answer;

    do {
        cout << "\n" << question << "(y/n)";
        cin >> answer;
    } while (answer != 'y' && answer != 'n');

   if(answer=='y'){
       return true;
   }
   else {
       return false;
   }

}


