// Name: Gerard Lawrence
//Program: C++
// Summary: The purpose of this code is to create a "Rock, Paper, Sissor" game for one player against the computer. The computer will randomly generate it's choice after the player make's their choice. In case of a tie, the program will ask the player to play again.
// This code took a few weeks to work on because of schedule
// Due Date: 11/16/2018
// 11/02/2018 Rev A. Wrote variables and UI for choices.
// 11/02/2018 Rev B. Wrote code for random number creator and if/else statements
// 11/03/2018 Rev C. Worked on output structure; making the sentences look neat.
// 11/15/2018 Rev D. Had issues with loop for a tied game. Not sure how to rectify.
// 11/16/2018 Rev E. Finalized code; wrote comments.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    
    int choice;
    int comp;
    int lose = 0;
    int win = 0;
    int tie = 0;
    //char ch;
    
    unsigned seed = time(0);
    
    cout << "Lets play a game of Rock, Paper, Scissors!" << endl;
    
    //User's choices
    cout << "Press 1: Rock" << endl;
    cout << "Press 2: Paper" << endl;
    cout << "Press 3: Scissors" << endl;
    cout << "Press 4: Quit" << endl;
    cout << "Enter: ";
    cin >> choice;
    
    // Computer generated numbers
    srand(seed);
    
    comp = rand() % 3 + 1;
    
    //If/Else statements for computer's choice
    //do{
    if(choice == 1 && comp == 1)
    {
        cout << "You chose: Rock" << endl;
        cout << "The computer chose: Rock"  << endl;
        cout << "It's a tie! Let's play again?" << endl;
        /* cout << "Y or N: ";
        cin >> ch; */
        tie++;
    }
    else if(choice ==1 && comp== 2)
    {
        cout << "You chose: Rock" << endl;
        cout << "The computer chose: Paper!" << endl;
        cout << "Paper beats Rock. THE COMPUTER WINS!." << endl;
        lose++;
    }
    else if(choice == 1 && comp == 3)
    {
        cout << "You chose: Rock!" << endl;
        cout << "The computer chose: Scissors" << endl;
        cout << "Rock beats Scissors. YOU WIN!" << endl;
        win++;
    }
    else if(choice == 2 && comp == 1)
    {
        cout << "You chose: Paper!" << endl;
        cout << "The computer chose: Rock" << endl;
        cout << "Paper beats Rock. YOU WIN!" << endl;
        win++;
    }
    else if(choice == 2 && comp == 2)
    {
        cout << "You chose: Paper" << endl;
        cout << "The computer chose: Paper" << endl;
        cout << "It's a tie! Let's play again?" << endl;
        /* cout << "Y or N: ";
        cin >> ch; */
        tie++;
    }
    else if(choice == 2 && comp == 3)
    {
        cout << "You chose: Paper" << endl;
        cout << "The computer chose: Scissors!" << endl;
        cout << "Paper beats Scissors. THE COMPUETER WINS!" << endl;
        lose++;
    }
    else if( choice == 3 && comp == 1)
    {
        cout << "You chose: Scissors" << endl;
        cout << "The computer chose: Rock!" << endl;
        cout << "Rock beats scissors. THE COMPUTER WINS!" << endl;
        lose++;
    }
    else if( choice == 3 && comp == 2)
    {
        cout << "You chose: Scissors!" << endl;
        cout << "The computer chose: Paper" << endl;
        cout << "Scissors beats Paper. YOU WIN!" << endl;
        win++;
    }
    else if(choice == 3 && comp == 3)
    {
        cout << "You chose: Scissors" << endl;
        cout << "The computer chose: Scissors" << endl;
        cout << "It's a tie! Let's play again?" << endl;
       /*  cout << "Y or N: ";
        cin >> ch; */
        tie++;
        //while (ch == 'Y' || ch == 'y');
    }
    
        return 0;
    
}
