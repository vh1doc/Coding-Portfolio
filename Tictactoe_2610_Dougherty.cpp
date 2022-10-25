//This is written by Amber Dougherty for 2610 Programming problem solving

#include <iostream>
using namespace std;


class Everything
{

private:

char board [3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};

char current_marker;
int current_player;

public:

void print_board()
{
    cout << " " << board [0][0] << " | " << board[0][1] << " |  " << board [0][2] << endl;
    cout << "____________\n";
    cout << " " << board [1][0] << " | " << board[1][1] << " |  " << board [1][2] << endl;
    cout << "____________\n";
    cout << " " << board [2][0] << " | " << board[2][1] << " |  " << board [2][2] << endl;
    cout << "\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n ";

}

void place_marker (int slot)
{
    int row= (slot/3);
    int column;

    if (slot % 3==0)
    {
        row = row -1;
        column = 2;
    }
  else column = (slot % 3) -1 ;



    board[row][column] = current_marker;

}

char game_won()
{

    for (int i = 0; i < 3; i++)
    {
        //rows
        if (board [i][0] == board [i][1] && board[i][1] == board [i][2])
        {
            return current_player;
        }
        //columns
         if (board [0][i] == board [1][i] && board[1][i] == board [2][i])
        {
            return current_player;
        }
    }
    if (board[0][0] == board [1][1] && board[1][1] == board [2][2])
    {
        return current_player;
    }
    if (board[0][2] == board [1][1] && board[1][1] == board [2][0])
    {
        return current_player;
    }


}

void swap_players()
{
    if (current_marker == 'X')
    {
        current_marker = 'O';
    }
    else
    {
        current_marker = 'X';
    }

    if (current_player == 1)
    {
        current_player = 2;
    }
    else
    {
        current_player = 1;
    }
}

void gameplay()
{
    cout<< "Player 1, choose your marker: \n";
    char marker_p1;
    cin >> marker_p1;

    current_player = 1;
    current_marker = marker_p1;

    print_board();

    int player_won;

    for (int i =0; i < 9; i++)
    {
        cout << "It is player " << current_player << "'s turn. Enter your slot: ";
        int slot;
        cin>> slot;

        place_marker(slot);

        player_won = game_won();


        if (player_won == 1)
        {
           print_board();
            cout<< "Player one won!"; break;
        }
        if (player_won == 2)
        {
            print_board();
            cout<< "Player two won!"; break;
        }

        swap_players();
        print_board();

        game_won();

         if (player_won == 0)
    {
        cout << "The game was a tie and no one won \n";
    }

    }
}

};
int main()
{
    cout<< "This program was written for 2610 Programming Problem Solving by Dougherty \n";
    cout<< "It is a game of Tic Tac Toe \n";

Everything game;
game.gameplay();

    return 0;
}
