// Name: Gerard Lawrence
// Program: C++
// Summary: The purpose of this code is to create a "Lottery Simulator". This program will contain 5 arrays, each array will contain a randomly generated number between 0-9. The program will then display the user's numbers and the computers numbers and let the user know if they have won or not.
// Due Date: 11/16/2018
// 11/07/2018 Rev A. Wrote variables for arrays and
// 11/08/2018 Rev B. Wrote code for user to enter their numbers.
// 11/13/2018 Rev C. Worked on output structure; making the sentences look neat and adding proper spacing.
// 11/15/2018 Rev D. Finalized code; wrote comments.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()

{
	//Variables
	int lottery[5];
	int user[5];
	bool allmatch = true;
	bool nomatch = true;
	int matchcount = 0;
	
	//random number generator
	srand (time(NULL));
	
	//random number for each lottery number
	lottery[0] = rand() % 10;
	lottery[1] = rand() % 10;
	lottery[2] = rand() % 10;
	lottery[3] = rand() % 10;
	lottery[4] = rand() % 10;
	
	//Opening message
	cout << "Welcome to the Lottery Number Generator." << endl;
	cout << "Please enter 5 numbers ranging from 0 to 9!" << endl << endl;
	
	//Input for each lotter number
	for(int i = 0; i < 5; i++)
	{
		cout << "Enter a number: ";
		cin>>user[i];
		while (user[i]<0 || user[i]>9)
		{
			cout << "Error! Entry must be between 0 and 9!" << endl;
			cout << "Enter a number: ";
			cin >> user[i];
		}
	}
	
	//Output for the random generated lottery numbers
	cout << endl << "Comp Lottery Numbers: ";
	
	for(int i = 0; i < 5; i++)
		{
		cout << lottery[i];
			cout << "|";
	}
	
	//Output for User's lottery numbers
	cout << endl << endl << "Your Lottery Numbers: ";
	
	for(int i = 0; i < 5; i++)
	{
		cout<<user[i];
		cout<<"|";
	}
	
	//To check if the user's individual numbers matches the computer's numbers
	for(int i = 0; i < 5; i++)
	{
			if(user[i] == lottery[i])
		{
			matchcount++;
			nomatch = false;
		}
	
	//To check if the all of the user's individual numbers match the computer's numbers
	if(user[i] != lottery[i])
		{
			allmatch = false;
		}
	}
	
	//Message print out if no numbers
	if(nomatch == true)
	{
		cout<<endl<<endl<<"Sorry, You did not win."<<endl;
	}
	
	//Message print out if all numbers match
	if(allmatch == true)
	{
		cout<<endl<<endl<<"Congratulation! you are the grand prize winner!"<<endl;
	}
	
	//Message print out to tell how many indivdual numbers match
	if(matchcount != 0)
		cout<<endl<<endl<<matchcount<<" Match"<<endl;
	
	return 0;
}
