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
char winner(const vector<char>& board);
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
//Return the piece winner a tie or noBody
char winner(const vector<char>& board)
{
    //This are the posibilities to win
    const int WINNING_POS[8][3] = { {0, 1, 2}, //Horizontal
                                    {3, 4, 5}, //Horizontal
                                    {6, 7, 8}, //Horizontal
                                    {0, 3, 6}, //Vertical
                                    {1, 4, 7}, //Vertical
                                    {2, 5, 8}, //Vertical
                                    {2, 4, 6}, //Horizontal
                                    {0, 4, 8} }; //Horizontal
    const int TOTAL_ROWS = 8;

    //Return the winner
    for (int row = 0; row < TOTAL_ROWS; row++)
    {
        if ((board[WINNING_POS[row][0]] != EMPTY) &&
            (board[WINNING_POS[row][0]] == board[WINNING_POS[row][1]]) &&
            (board[WINNING_POS[row][1]] == board[WINNING_POS[row][2]]))
        {
            return board[WINNING_POS[row][0]];
        }
    }

    //Return a Tie
    if (count(board.begin(), board.end(), EMPTY) == 0) {
        return TIE;
    }

    //Return that no one is the winner yet
    return NO_ONE;
}