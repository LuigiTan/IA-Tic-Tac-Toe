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
char RandomPlayerSymbol();
char OponentSymbol(char Symbol);
char winner(const vector<char>& board);
char AskYesNo(string question);
char AskParImpar(string question);
void displayboard(const vector<char>& board);
int askNumber(string question, int high, int low = 1);
bool IsLegal(const vector<char>& board, int LastMove);


int main()
{
    int move = 0;
    vector<char> board(NUM_SQUARES, EMPTY);
    instructions();
    //char Player = playerSymbol();
    char Player = RandomPlayerSymbol();
    char Computer = Player == X ? O : X;
    //char Computer = Player == X ? O : X;
    char Turn = X;


    while (winner(board) == NO_ONE)
    {
        if (Turn == Player)
        {
            cout << "Testing: el jugador va a introducir el valor de los dos casos" << endl;
            cout << "Este es el turno del jugador" << endl;
            do {
            move = askNumber("\nElige un numero ", 8);
            } while (IsLegal(board, move) == false);
            board[move] = Player;
            Turn = Computer;
           
        }
        else
        {
            cout << "Testing: el jugador va a introducir el valor de los dos casos" << endl;
            cout << "Este es el turno de la maquina" << endl;
            do {
            move = askNumber("\nElige un numero ", 8);
            } while (IsLegal(board, move) == false);
            board[move] = Computer;
            Turn = Player;
                
        }
        
        displayboard(board);
    }


    
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

char RandomPlayerSymbol()
{
    //bool CheckingRandom = true;
    //do
    //{
        srand(time(NULL));
       
        int DiceRoll = rand() % (6 - 1 + 1) + 1;
        char GoFirst = AskParImpar("Se seleccionara un numero al azar, si adivinas que es empezaras tu. Sera Par o Impar?");
        cout << "\nEl numero del dado fue: " << DiceRoll << endl;
        if (GoFirst == 'p')
        {
            if (DiceRoll % 2 == 0)
            {
                cout << "Le atinaste!! Empiezas tu. Player = X" << endl;
                
                return X;
            }
            else
            {
                cout << "No le atinaste... La maquina empieza. Player = O" << endl;
                return O;
            }
        }
        else
        {
            if (DiceRoll % 2 != 0)
            {
                cout << "Le atinaste!! Empiezas tu. Player = X" << endl;
                return X;
            }
            else
            {
                cout << "No le atinaste... La maquina empieza. Player = O" << endl;
                return O;
            }

        }
    //} while (CheckingRandom);
    //return X;
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

char AskParImpar(string question)
{
    char answer;

    do {
        cout << "\n" << question << "(p/i)";
        cin >> answer;
    } while (answer != 'p' && answer != 'i');

    return answer;

}

char AskYesNo(string question)
{
    char answer;

    do {
        cout << "\n" << question << "(y/n)";
        cin >> answer;
    }while(answer != 'y' && answer != 'n');
       
    return answer;  

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
void displayboard(const vector<char>& board)
{
    cout << "| " << board[0] << " | " << board[1] << " | " << board[2] << " |" << endl;
    cout << "| " << board[3] << " | " << board[4] << " | " << board[5] << " |" << endl;
    cout << "| " << board[6] << " | " << board[7] << " | " << board[8] << " |" << endl;
}

int askNumber(string question, int high, int low)
{
    string input;
    bool isValid = false;
    //int number = 0;

    //do {
        cout << question << "entre " << low << " y " << high << endl;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//La segunda vez que se habla a esta funcion, esta linea hace que el proceso se detenga para leer un input del usuario que no va ninguna parte 
      do {
          cout << "The Do is doing its job correcly" << endl;//Una vez se le da enter a la linea de arriba el proceso sigue a esa linea y todo funciona como deberia 
        getline(cin, input);
        //cin>> input;
    
        for (char c : input)
        {
            if (isdigit(c))
            {
                isValid = true;
                cout << "Test, The input is valid\n";
                break;
            }
            cout << "Test, outside the if\n";
        }
        if (!isValid)///Lo mismo que if(isvalid == false)
        {
            cout << "\nEntrada invalida, porfavor elige solo numeros.\n";
        }
        else if (isValid)
        {
            if (stoi(input) < low || stoi(input) > high)
            {
                cout << "Numero muy bajo o muy alto, introduce otro numero" << endl;
                isValid = false;
            }
        }

    } while (!isValid || input.empty());
    //number > high || number < low);

    return stoi(input);
}

bool IsLegal(const vector<char>& board, int LastMove)
{
    if (board[LastMove] != ' ')
    {
        cout << "El espacio seleccionado ya fue tomado, elige otro" << endl;
        return false;
    }
    else
    {
        return true;
    }

}

