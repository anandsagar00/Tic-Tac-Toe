#include<iostream>
#include<ctype.h>

using namespace std;

class ticTacToe{
    char arr[3][3],previousMove;
    int count,status;
    int rowIndex,columnIndex;

    public:
        ticTacToe();
        int play();
        void display();
        
};

//Default constructor used to initialise the data members.
ticTacToe::ticTacToe(){
    for(columnIndex=0; columnIndex < 3; ++columnIndex){
        for(rowIndex=0; rowIndex < 3; ++rowIndex)
            arr[columnIndex][rowIndex] = '_';
    }
    count = 1;
    status = -1;
    previousMove = '-';
}

/*
    The following member function "void display()" is used to display the following outputs:
        1) The array after each loop to help the players decide their next move.
        2) Has the match been won by any player and if so which player has won the match!
        3) If match is a tie!
*/
void ticTacToe::display(){
    if(status == 1){
        if(arr[columnIndex][rowIndex] == 'X')
            cout << "Player X has won the game\n";
        else
            cout << "Player O has won the game\n";
    }

    for(columnIndex=0; columnIndex < 3; ++columnIndex){
        for(rowIndex=0; rowIndex < 3; ++rowIndex)
            cout << arr[columnIndex][rowIndex] << " ";
        cout << "\n";
    }

    if(count == 10 && status != 1)
        cout << "This match is a tie\n";
}

/*
    The following member function "int play()" is used for:
        1) To handle all the logic of the game.
        2) Each part of the function has been explained in the function itself.
*/
int ticTacToe::play(){
    label :{

        cout << "Enter the row index and column index respectively and press enter\n";
        cin >> columnIndex >> rowIndex;

        if( columnIndex > 3 || rowIndex > 3){
            cout << "You have entered invalid index\n";
            goto label;
        }
            
        /*
            Here we decrement the value of both the indexes because players follow 1-based indexing but C/C++
            follows 0-based indexing. Doing so helps to eliminate the confusion in the players regarding indexing.
        */
        --rowIndex;
        --columnIndex;

        //The below if condition checks if the entered position is vacant or already occupied
        if(arr[columnIndex][rowIndex] == 'O' || arr[columnIndex][rowIndex] == 'X'){
            cout << "The position is already occupied\n";
            goto label;
        }
            
        cout << "Enter your move(X or O) and press enter\n";
        cin >> arr[columnIndex][rowIndex]; 
        arr[columnIndex][rowIndex] = toupper(arr[columnIndex][rowIndex]); 

        //This condition handles invalid inputs
        if(previousMove == arr[columnIndex][rowIndex] || (arr[columnIndex][rowIndex] != 'X' && arr[columnIndex][rowIndex] != 'O')){
            cout << "It is an invalid input\n";
            arr[columnIndex][rowIndex] = '_';
            goto label;
        }
        previousMove = arr[columnIndex][rowIndex];
        ++count;
    }   //Label ends here

    //This condition checks for 3 similar consecutive moves
    if(count > 4){
        if(arr[columnIndex][0] == arr[columnIndex][1] && arr[columnIndex][1] == arr[columnIndex][2])
            status = 1;
        else if(arr[0][rowIndex] == arr[1][rowIndex] && arr[1][rowIndex] == arr[2][rowIndex])
            status = 1;
        else if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2])
            status = 1;
        else if(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0])
            status = 1;
    }
    
    return status;
}

int main(){
    ticTacToe game;
    int numberOfMoves = 9,result = 0;
    
    cout << "Rules of the game:\n";
    cout << "1)This is a multiplayer game\n";
    cout << "2) Game shall follow 1 based indexing.\n";
    cout << "3) The first player to have 3 consecutive X or O will be the winner respectively\n";
    cout << " ----> Row\n";
    cout << " | \n";
    cout << " | \n";
    cout << "\\/\n";
    cout << "Column\n";
    cout << "Let's begin!\n";

    while(numberOfMoves--){
        result = game.play();
        game.display();
        if(result == 1)
            break;
    }

    return 0;
}
