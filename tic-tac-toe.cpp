#include <iostream>
using namespace std;
void display(char tictactoe[3][3]){                                 // Displays the Tic-Tac-Toe Grid (empty) 
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<'|'<<tictactoe[i][j]<<'|'<<'\t';
        } 
        cout << "\n---------------------\n";
    }
}
bool win(char x[3][3], char player){                                // Checks win by analysing each step  
    if(x[2][0]==player && x[1][1]==player && x[0][2]==player){
        return true;
    }
    else if(x[0][0]==player && x[1][1]==player && x[2][2]==player){  // If there is a match return true
        return true;
    }
    for(int i=0;i<3;i++){
        if(x[i][0]==player && x[i][1]==player && x[i][2]==player){
            return true;
        }
        else if(x[0][i]==player && x[1][i]==player && x[2][i]==player){
            return true;
        }
        }
    return false;                                                    // else false is the output if no match
    }
void game(char tictactoe[3][3], char player){                        // Inputs row and column values 
    int turn=0;
    int row,column;
    char q='y';
    while(q=='y'){                                                   // For playing the game again
        while (turn<=9){
        cout<<"Player: "<<player<<" choose an index: (row: 0 to 2) (column: 0 to 2): "<<endl;
        cin>>row>>column;
        if(tictactoe[row][column]==' '){                            // Inputs value only if there is an empty space
            tictactoe[row][column]=player;
            for(int i=0;i<3;i++){                           
                for(int j=0;j<3;j++){
                    cout<<'|'<<tictactoe[i][j]<<'|'<<'\t';
                }
                cout << "\n---------------------\n";
            }
        }
        else{                                      
            cout<<"Error! try again"<<endl;       
            continue;
        }
        turn+=1;
        // Output on the basis of win or a draw:- 
        if(win(tictactoe,player)){                           
            cout<<"winner is: "<<player<<endl;
            break;
        };
        if(turn==9 && !win(tictactoe,'X') && !win(tictactoe,'O')){   
            cout<<"DRAW!"<<endl;
            break;
        }  
        player=(player=='X') ? 'O': 'X';   // Swtich between the 2 players
    }
        cout<<"do you want to play again? (y/n): "<<endl;
        cin>>q; 
        if(q=='y')   // condition to play again
        {
            for (int i=0;i<3; i++)
            {
                    for (int j=0; j<3; j++)
                    {
                            tictactoe[i][j]=' ';
                    }
            }
            turn=0;
        }
        else{
            // exit the game
            exit(0);
        }    

    }
}

   
int main(){          // Initialising the player and the grid
    char tictactoe[3][3]={
        {' ',' ',' '},
        {' ',' ',' '},
        {' ',' ',' '}
    };
    cout<<"Welcome to TIC - TAC - TOE GAME! "<<endl;
    char player='X';
    display(tictactoe);
    game(tictactoe, player);

    return 0;
}