// Name: Gerard Lawrence
 // Program: C++
 // Summary: Write a Theater Seating program that can be used by a small theater to sell tickets for performances. The theater’s auditorium has 15 rows of seats, with 30 seats in each row (Two-dimensional array). The program should display a screen that shows which seats are available and which are taken. For example, the following screen shows a char depicting each seat in the theater. Seats that are taken are represented by an * symbol, and seats that are available are represented by a # symbol.
 // Due Date: 12/14/2018
 // 12/07/2018 Rev A. Wrote code to display menu and user input
 // 12/08/2018 Rev B. Wrote code for switch for menu and seat display
 // 12/09/2018 Rev C. Wrote code to display seat prices and updating prices
 // 12/12/2018 Rev D. Worked on output structure; making the sentences look neat and adding proper spacing.
 // 12/12/2018 Rev E. Wrote code for output file but Struggled for days with code for input of prices.
 // 12/13/2018 Rev F. Unable to find a way to show input of new seat prices without running into some kind of error.
 // 12/14/2018 Rev F. Finalized code; wrote comments.
 
 #include <iostream>
 #include <iomanip>
 #include <fstream>
 #include <string>
 #include <cstdlib>

using namespace std;

// Constants for rows and columns
const int ROWS = 15;
const int COLS = 30;

// Function prototypes
void displayMenu();
int getChoice();
void displaySeats(const char [][COLS]);
void displayPrices(const double[]);
void updatePrices(double[]);
void displaySales(double);
void purchaseTicket(char [][COLS], const double[], double&);

int main()
{
	char theater[ROWS][COLS];
	double ticketPrice[ROWS] = { 0.0 };
	double totalSales = 0.0;
	int row;
	int seat;
	int choice;
	
	// Initialize theater with #'s -- all seats available
	for(row = 0; row < ROWS; row++)
		for (seat = 0; seat < COLS; seat++)
			theater[row][seat] = '#';
	
	do
	{
		displayMenu();
		choice = getChoice();
		
		switch(choice)
		{
			case 1: displaySeats(theater);
				break;
				
			case 2: displayPrices(ticketPrice);
				break;
				
			case 3: updatePrices(ticketPrice);
				break;
				
			case 4: purchaseTicket(theater, ticketPrice, totalSales);
				break;
				
			case 5: displaySales(totalSales);
				break;
		}
		
	} while (choice != 6);
	
	return 0;
}

// Displays the Main Menu
void displayMenu()
{
	cout << endl << endl;
	cout << "\t\tC++ Theatre" << endl << endl;
	cout << " 1. View Available Seats" << endl;
	cout << " 2. View Seating Prices" << endl;
	cout << " 3. Update Seating Prices" << endl;
	cout << " 4. Purchase a Ticket" << endl;
	cout << " 5. View Ticket Sales" << endl;
	cout << " 6. Quit" << endl << endl;
	cout << "Enter your choice(1-5):  ";
}

// if user makes a choice outside of 1-6
int getChoice()
{
	int choice;
	
	// Validate user's choice
	cin  >> choice;
	while (choice < 1 || choice > 5)
	{
		cout << "Choice must be between 1 and 5. Please re-enter: ";
		cin  >> choice;
	}
	
	//Return the choice
	return choice;
}

// 1. Displays a chart showing sold and available seats
void displaySeats(const char theater[][COLS])
{
	cout << "\t\t\tSeats" << endl;
	cout << "\t\t 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0" << endl;
	
	for(int row = 0; row < ROWS; row++)
	{
		cout << endl << "Row " << setw(2) << row+1 << "\t";
		
		for (int seat = 0; seat < COLS; seat++)
		{
			cout << " " << theater[row][seat];
		}
	}
	
	cout << endl << endl << endl << "\tLegend:\t*  =  Sold";
	cout << endl << "\t\t\t#  =  Available";
	
	cout << endl << endl << endl << "Press the Enter key to continue.";
	cin.ignore();
	cin.get();
}

// 2. Displays ticket prices for each row
void displayPrices(const double price[])
{
	int row = 0;
	int row2;
	ifstream inputFile;
	
	
	inputFile.open("MovieTickets.txt");
		inputFile >> row2;

	cout << endl << "Ticket Prices By Row " << endl << endl;
	cout << "\tRow Price" << endl;
	cout << "\t--- -----" << endl;
	
	if (inputFile)
	{
	while (row <= ROWS)
	{
		while (inputFile >> row2)
		{
		cout << setw(6) << row+1 << setw(6) << row2 << endl;
			row++;
		}
	}
	
	inputFile.close();
	}
	else
	{
		// Display an error message.
		cout << "Error opening the file.\n";
	}
	
	cout << "\n\n\nPress the Enter key to continue.";
	cin.ignore();
	cin.get();
}

// 3. Asks user to update seating prices
void updatePrices(double price[])
{
	
	double ticketPrice[ROWS] = { 0.0 };
	//int row2;
	int row;
	ofstream outputFile;
	
	outputFile.open("MovieTickets.txt");
	
	// Get seat prices for each of row and update it to .txt file
	for (row = 0; row < ROWS; row++)
	{
		cout << "Please enter ticket price for Row " << setw(2) << row+1
		<< ": ";
		cin  >> ticketPrice[row];
	}
	
	// Set print formats
	//cout << fixed << showpoint << setprecision(2);
	
	outputFile.close();
	cout << endl << "Ticket prices have been updated" << endl;
	
	cout << endl << "Press the Enter key to continue.";
	cin.ignore();
	cin.get();
	
}

// 4. Navigates ticket purchasing
void purchaseTicket(char theater[][COLS], const double price[],
					double &totSales)
{
	int row;
	int seat;
	int numTickets = 0;
	double totPrice = 0;
	char response;
	
	cout << endl << "\t\t        C++ Theatre" << endl;
	cout << "\t\tTicket Purchase Opportunity" << endl << endl;
	
	cout << "Do you wish to view the chart of available seats " << endl
	<< "before making your selections (y/n)? ";
	cin  >> response;
	
	if (toupper(response) == 'Y')
		displaySeats(theater);
	
	// User chooses what seat they want
	do
	{
		cout << "\nPlease enter desired row number (1-"
		<< ROWS << "): ";
		cin >> row;
		
		while (row < 1 || row > ROWS)
		{
			cout << "Row must be between 1 and "
			<< ROWS << ". Please re-enter: ";
			cin  >> row;
		}
		
		cout << endl << "Please enter desired seat number (1-"
		<< COLS << "): ";
		cin >> seat;
		
		while (seat < 1 || seat > COLS)
		{
			cout << "Seat must be between 1 and "
			<< COLS << ". Please re-enter: ";
			cin  >> seat;
		}
		
		if (theater[row-1][seat-1] == '#')   // mark the seat is available
		{
			theater[row-1][seat-1] = '*';    // mark the seat is taken
			numTickets++;                    // add to user's ticket total
			totPrice += price[row-1];        // add to user's $ total
			cout << endl << "Purchase confirmed" << endl;
		}
		else  // seat has been sold
		{
			cout << endl << "Sorry. That seat has been sold." << endl;
		}
		
		cout << endl << "Would you like to purchase another seat (y/n)? ";
		cin >> response;
		
		if(numTickets == 450){
			cout << "Sorry, we're sold out!" << endl;
			break;
		}
		else
			continue;
		
	} while (toupper(response) == 'Y');
	
	
	// Displays user's purchases
	cout << endl << endl << "You have purchased a total of " << numTickets
	<< " ticket(s) " << "for a total price of $" << totPrice;
	
	// Add users's purchases total puchases
	totSales += totPrice;
	
	cout << endl << endl << endl << "Press the Enter key to continue.";
	cin.ignore();
	cin.get();
}

// 5. Displays total sales information
void displaySales(double totalSales)
{
	cout << endl << endl << "Total Sales: $" << totalSales << endl << endl;
}
