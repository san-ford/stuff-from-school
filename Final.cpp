// This program allows a user to choose a few options from a menu.
// It uses text files and 2D arrays to create custom or random data tables,
// or display, sort, and search data tables.
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Constants for row and column size
// (except for the random function)
const int MIN_SIZE = 1, MAX_SIZE = 10;

int displayMenu();
void customData();
void randData();
void displayData();
void sortData();
void searchData();

int main()
{
	int option;
	
	do
	{
		option = displayMenu();
		
		switch (option)
		{
			case 1: customData();
				break;
			case 2: randData();
				break;
			case 3: displayData();
				break;
			case 4: sortData();
				break;
			case 5: searchData();
				break;
			case 6: cout << "Goodbye";
				break;
			default:
			{
				cout << "Error. Terminating Program.";
				return 0;
			}	
		}
	} while (option != 6);
	
	return 0;
}

// This function displays the menu and returns the number of the menu option.
int displayMenu()
{
	int menuOption;
	double inputValue;
	int validOption = 0;
	
	do
	{
		cout << "Main Menu\n\n";
		cout << "1. New Custom Data Table\n";
		cout << "2. New Random Data Table\n";
		cout << "3. Display a Data Table\n";
		cout << "4. Sort a Data Table by Column\n";
		cout << "5. Search a Data Table by Column\n";
		cout << "6. Exit\n\n";
		cout << "Please enter the number of your menu option: ";
		cin >> inputValue;
		menuOption = static_cast<int>(inputValue);
		
		if (menuOption >= 1 && menuOption <= 6)
			validOption = 1;
		else
		{
			cout << "\nThat is not a valid option. Please enter a number 1 through 6.\n\n";
			cin.clear();
			cin.ignore();
		}		
	} while (validOption == 0);
	
	return menuOption;	
}

// This function prompts user to specify dimensions for a data table up to a 10 x 10 grid,
// prompts user to populate the grid, then saves the data to a text file named by the user.
void customData()
{
	ofstream outputFile;
	string filename;
	int row, col;
	int validOption = 0;
	long double inputValue = 0;
	long double array[MAX_SIZE][MAX_SIZE];
	
	cout << "\nEnter a file name to save the data to: ";
	cin >> filename;
	
	// Validates input for number of rows
	do
	{
		cout << "Enter the number of rows in your data table (up to 10): ";
		cin >> inputValue;
		row = static_cast<int>(inputValue);
		
		if (row >= MIN_SIZE && row <= MAX_SIZE)
			validOption = 1;
		else
		{
			cout << "\nThat is not a valid option. Please enter a number 1 through 10.\n\n";
			cin.clear();
			cin.ignore();
		}	
	} while (validOption == 0);
	cout << "Number of rows: " << row << endl;
	
	// Validates input for number of columns
	validOption = 0;
	inputValue = 0;
	do
	{
		cout << "Enter the number of columns in your data table (up to 10): ";
		cin >> inputValue;
		col = static_cast<int>(inputValue);
		
		if (col >= MIN_SIZE && col <= MAX_SIZE)
			validOption = 1;
		else
		{
			cout << "\nThat is not a valid option. Please enter a number 1 through 10.\n\n";
			cin.clear();
			cin.ignore();
		}
	} while (validOption == 0);
	cout << "Number of columns: " << col << endl;
	
	// Prompts user to populate data table and verifies input.
	inputValue = 0;
	for (int index1 = 0; index1 < row; index1++)
	{
		for (int index2 = 0; index2 < col; index2++)
		{
			cout << "Enter a value for row " << (index1 + 1) << " column " << (index2 + 1) << ": ";
			cin >> inputValue;
			if (!cin)
			{
				cout << "\nThat is not a valid input. Please enter only numbers\n\n";
				cin.clear();
				cin.ignore();
				index2--;
			}
			else
				array[index1][index2] = inputValue;
		}
	}

	// Writes data table to a text file
	outputFile.open( filename.c_str() );
	outputFile << "UNSORTED ";
	outputFile << row << " " << col << endl;
	for (int index1 = 0; index1 < row; index1++)
	{
		for (int index2 = 0; index2 < col; index2++)
		{
			outputFile << array[index1][index2];
			outputFile << " ";
		}
		outputFile << endl;
	}
	
	outputFile.close();
	cout << "\nFile saved as: " << filename << endl << endl;
	
	return;
}

// This program generates a table of random numbers between 0 and 1 for a
// random number (between 2 and 10) of rows and columns.
// Then it saves the data to a text file named by the user.
void randData()
{
	ofstream outputFile;
	string filename;
	int row, col, rand1, rand2;
	long double rand3;
	const int MIN_SIZE = 2; // Locally redefines min size for random row/col values
	const int MIN_VALUE = 0, MAX_VALUE = 999;
	long double array[MAX_SIZE][MAX_SIZE];
	unsigned seed = time(0);
	
	cout << "\nEnter a file name to save the data to: ";
	cin >> filename;
	
	// Generates a random number of rows and columns between 2 and 10
	srand(seed);
	row = (rand() % (MAX_SIZE - MIN_SIZE + 1)) + MIN_SIZE;
	col = (rand() % (MAX_SIZE - MIN_SIZE + 1)) + MIN_SIZE;
	
	// Generates random long double values for each array element between 0 and 1
	for (int index1 = 0; index1 < row; index1++)
	{
		for (int index2 = 0; index2 < col; index2++)
		{
			rand1 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
			rand2 = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;
			rand3 = static_cast<long double>(rand2);
			
			if (rand1 < rand3)
				array[index1][index2] = rand1 / rand3;
			else if (rand1 == 0 && rand3 ==0)
				array[index1][index2] = rand1 / rand3;
			else
				array[index1][index2] = rand3 / rand1;
		}
	}
	
	// Writes data table to a text file
	outputFile.open( filename.c_str() );
	outputFile << "UNSORTED ";
	outputFile << row << " " << col << endl;
	for (int index1 = 0; index1 < row; index1++)
	{
		for (int index2 = 0; index2 < col; index2++)
		{
			outputFile << array[index1][index2];
			outputFile << " ";
		}
		outputFile << endl;
	}
	
	outputFile.close();
	cout << "\nFile saved as: " << filename << endl << endl;
	
	return;
}

// This function reads a text file of a specific format
// and displays the contents of a data table.
void displayData()
{
	ifstream inputFile;
	string filename, sortedOrNot;
	int row, col, dummyInt, success = 0;
	char dummyChar;
	long double array[MAX_SIZE][MAX_SIZE];
	
	// Prompts user to enter file name to open or return to Main Menu
	do
	{
		cout << "\nEnter the file name of a data table to display, ";
		cout << "or enter / to return to Main Menu: ";
		cin >> filename;
		
		// Returns to Main Menu if user chooses
		if (filename == "/")
		{
			cout << endl;
			return;
		}
		else
			inputFile.open( filename.c_str() );
		
		// Verifies opening of file and copies contents into array
		if (inputFile)
		{
			inputFile >> sortedOrNot;
			inputFile >> row >> col;
			
			// Determines whether data is sorted or unsorted
			if (sortedOrNot == "SORTED")
			{
				inputFile >> dummyInt;
				inputFile >> dummyChar;
				if (!dummyInt || !dummyChar)
				{
					cout << "File cannot be read. Please try a different file.\n\n";
					inputFile.close();
				}
			}
			else if (sortedOrNot != "UNSORTED")
			{
				cout << "File cannot be read. Please try a different file.\n\n";
				inputFile.close();
				inputFile.close();
			}
			
			if (inputFile)
			{
				// Verifies file input
				if (!row || !col)
				{
					cout << "File cannot be read. Please try a different file.\n\n";
					inputFile.close();
				}
				if (row < MIN_SIZE || row > MAX_SIZE || col < MIN_SIZE || col > MAX_SIZE)
				{
					cout << "File cannot be read. Please try a different file.\n\n";
					inputFile.close();
				}
				
				// Assigns file data to local array, then displays it
				for (int index1 = 0; index1 < row; index1++)
				{
					for (int index2 = 0; index2 < col; index2++)
					{
						// If there are less values in the file than indicated
						// by row and column numbers, the loop stops and the function ends.
						if (inputFile)
						{
							inputFile >> array[index1][index2];
							cout << setprecision(6) << setw(12) << fixed << right;
							cout << array[index1][index2] << " ";
						}
						else
						{
							cout << "\nNo more values to display\n";
							system("pause");
							inputFile.close();
							return;
						}
					}
					cout << endl;
				}
				
				inputFile.close();
				system("pause");
				success = 1;
			}
		}
		else
			cout << "Error opening file. Please try again.";
	} while (success == 0);
	
		
	return;
}

// This function prompts the user to open a file,
// then to decide a column to sort in ascending or descending order.
// It then prompts the user to name a file to save the new data to.
void sortData()
{
	ifstream inputFile;
	ofstream outputFile;
	string inFilename, outFilename, sortedOrNot;
	int row, col, sortCol, dummyInt, success = 0;
	long double inputValue;
	char sortOrder, dummyChar;
	long double array[MAX_SIZE][MAX_SIZE];
	
	do
	{
		cout << "\nEnter the file name of a data table to sort, ";
		cout << "or enter / to return to Main Menu: ";
		cin >> inFilename;
		
		// Returns to Main Menu if user chooses
		if (inFilename == "/")
		{
			cout << endl;
			return;
		}
		else
			inputFile.open( inFilename.c_str() );
		
		// Verifies opening of file and copies contents into array
		if (inputFile)
		{
			inputFile >> sortedOrNot;
			inputFile >> row >> col;
			
			// Determines whether data is sorted or unsorted
			if (sortedOrNot == "SORTED")
			{
				inputFile >> dummyInt;
				inputFile >> dummyChar;
				
				if (!dummyInt || !dummyChar)
				{
					cout << "\nError reading file. Returning to Main Menu.\n";
					inputFile.close();
					return;
				}
			}
			else if (sortedOrNot != "UNSORTED")
			{
				cout << "File cannot be read. Please try a different file.\n\n";
				inputFile.close();
				inputFile.close();
			}
			
			if (inputFile)
			{
				// Verifies file input
				if (!row || !col)
				{
					cout << "\nError reading file. Returning to Main Menu.\n";
					inputFile.close();
					return;
				}
				if (row < MIN_SIZE || row > MAX_SIZE || col < MIN_SIZE || col > MAX_SIZE)
				{
					cout << "\nError reading file. Returning to Main Menu.\n";
					inputFile.close();
					return;
				}
				
				// Assigns file data to local array
				for (int index1 = 0; index1 < row; index1++)
				{
					for (int index2 = 0; index2 < col; index2++)
					{
						// If there are less values in the file than indicated
						// by row and column numbers, the loop stops and the function ends.
						if (inputFile)
							inputFile >> array[index1][index2];
						else
						{
							cout << "\nError reading file. Returning to Main Menu.\n";
							inputFile.close();
							return;
						}
					}
				}
				
				inputFile.close();
				success = 1;
			}
		}
		else
			cout << "Error opening file. Please try again.";
	} while (success == 0);
	
	// Prompts user for column to sort and verifies it
	do
	{
		cout << endl << "Enter column number to sort: ";
		cin >> inputValue;
		sortCol = static_cast<int>(inputValue);
		
		if (!sortCol || sortCol < MIN_SIZE || sortCol > col)
		{
			cout << "That is not a valid input. Please try again.\n";
			cin.clear();
			cin.ignore();
			sortCol = -1;
		}
	} while (sortCol == -1);
	
	// Prompts user to specify sort order and verifies it
	do
	{
		cout << "Choose a sort order. Enter 'A' for ascending or 'D' for descending: ";
		cin >> sortOrder;
		
		if (sortOrder != 'a' && sortOrder != 'A' && sortOrder != 'd' && sortOrder != 'D')
		{
			cout << "That is not a valid input. Please try again.\n";
			cin.clear();
			cin.ignore();
			sortOrder = 'E';
		}
	} while (sortOrder == 'E');
	
	// Sorts a chosen column in ascending order
	inputValue = 0;
	if (sortOrder == 'a' || sortOrder == 'A')
	{
		sortOrder = 'A';
		for (int maxElement = row - 1; maxElement > 0; maxElement--)
		{
			for (int index = 0; index < maxElement; index++)
			{
				if (array[index][sortCol - 1] > array[index + 1][sortCol - 1])
				{
					// Swaps elements using inputValue as an intermediate
					inputValue = array[index][sortCol - 1];
					array[index][sortCol - 1] = array[index + 1][sortCol - 1];
					array[index + 1][sortCol - 1] = inputValue;
					inputValue = 0;
				}
			}
		}
	}
	
	// Sorts a chosen column in descending order
	if (sortOrder == 'd' || sortOrder == 'D')
	{
		sortOrder = 'D';
		for (int maxElement = row - 1; maxElement > 0; maxElement--)
		{
			for (int index = 0; index < maxElement; index++)
			{
				if (array[index][sortCol - 1] < array[index + 1][sortCol - 1])
				{
					// Swaps elements using inputValue as an intermediate
					inputValue = array[index][sortCol - 1];
					array[index][sortCol - 1] = array[index + 1][sortCol - 1];
					array[index + 1][sortCol - 1] = inputValue;
					inputValue = 0;
				}
			}
		}
	}
	
	// Writes sorted data to text file named by user
	cout << "Enter a file name to save the data to: ";
	cin >> outFilename;
	outputFile.open( outFilename.c_str() );
	outputFile << "SORTED ";
	outputFile << row << " " << col << " ";
	outputFile << sortCol << " " << sortOrder << endl;
	for (int index1 = 0; index1 < row; index1++)
	{
		for (int index2 = 0; index2 < col; index2++)
		{
			outputFile << array[index1][index2];
			outputFile << " ";
		}
		outputFile << endl;
	}
	
	outputFile.close();
	cout << "\nFile saved as: " << outFilename << endl << endl;
	
	return;
}

// This function prompts a user to open a file,
// prompt for a column to search and a value to search for.
// It will then display the location of the value if found.
void searchData()
{
	ifstream inputFile;
	string filename, sortedOrNot;
	int row, col, sortCol, searchCol, success = 0;
	long double inputValue, searchValue;
	char sortOrder;
	long double array[MAX_SIZE][MAX_SIZE];
	bool found;
	int position, first, last, middle;
	
	do
	{
		cout << "\nEnter the file name of a data table to search, ";
		cout << "or enter / to return to Main Menu: ";
		cin >> filename;
		
		// Returns to Main Menu if user chooses
		if (filename == "/")
		{
			cout << endl;
			return;
		}
		else
			inputFile.open( filename.c_str() );
		
		// Verifies opening of file and copies contents into array
		if (inputFile)
		{
			inputFile >> sortedOrNot;
			inputFile >> row >> col;

			// Determines whether data is sorted or unsorted
			if (sortedOrNot == "SORTED")
			{
				inputFile >> sortCol;
				inputFile >> sortOrder;
				
				if (!sortCol || !sortOrder)
				{
					cout << "\nError reading file. Returning to Main Menu.\n";
					inputFile.close();
					return;
				}
			}
			else if (sortedOrNot != "UNSORTED")
			{
				cout << "File cannot be read. Please try a different file.\n\n";
				inputFile.close();
				inputFile.close();
			}
			
			if (inputFile)
			{
				// Verifies file input
				if (!row || !col)
				{
					cout << "\nError reading file. Returning to Main Menu.\n";
					inputFile.close();
					return;
				}
				if (row < MIN_SIZE || row > MAX_SIZE || col < MIN_SIZE || col > MAX_SIZE)
				{
					cout << "\nError reading file. Returning to Main Menu.\n";
					inputFile.close();
					return;
				}
				
				// Assigns file data to local array
				for (int index1 = 0; index1 < row; index1++)
				{
					for (int index2 = 0; index2 < col; index2++)
					{
						// If there are less values in the file than indicated
						// by row and column numbers, the loop stops and the function ends.
						if (inputFile)
						{
							inputFile >> array[index1][index2];
						}
						else
						{
							cout << "\nError reading file. Returning to Main Menu.\n";
							inputFile.close();
							return;
						}
					}
				}
				inputFile.close();
				success = 1;
			}
		}
		else
			cout << "Error opening file. Please try again.";
	} while (success == 0);

	// Prompts user to enter column to search and validates it
	do
	{
		cout << "Enter the column to search: ";
		cin >> inputValue;
		searchCol = static_cast<int>(inputValue);
		
		if (!searchCol || searchCol < MIN_SIZE || searchCol > col)
		{
			cout << "That is not a valid input. Please try again.\n";
			cin.clear();
			cin.ignore();
			searchCol = -1;
		}
	} while (searchCol == -1);
	
	// Prompts user to enter a value to search for and validates it
	inputValue = 0;
	success = 1;
	do
	{
		cout << "Enter a value to search for: ";
		cin >> inputValue;
		if (!cin)
		{
			cout << "That is not a valid input. Please enter only numbers\n";
			cin.clear();
			cin.ignore();
			success = 0;
		}
		else
			searchValue = inputValue;
	} while (success == 0);
	
	// Determines whether to perform a binary or linear search, then executes
	if (sortedOrNot == "SORTED")
	{
		if(sortCol == searchCol)
		{
			if (sortOrder == 'A')
			{
				// Ascending binary search
				first = 0;
				last = col - 1;
				found = false;
				position = -1;
				while (!found && first <= last)
				{
					middle = (first + last) / 2;
					if (array[middle][searchCol - 1] == searchValue)
					{
						found = true;
						position = middle;
					}
					else if (array[middle][searchCol - 1] > searchValue)
						last = middle - 1;
					else
						first = middle + 1;
				}
			}
			else if (sortOrder == 'D')
			{
				// Descending binary search
				first = 0;
				last = col - 1;
				found = false;
				position = -1;
				while (!found && first <= last)
				{
					middle = (first + last) / 2;
					if (array[middle][searchCol - 1] == searchValue)
					{
						found = true;
						position = middle;
					}
					else if (array[middle][searchCol - 1] < searchValue)
						last = middle - 1;
					else
						first = middle + 1;
				}
			}
			else
			{
				// Linear search
				found = false;
				position = -1;
				for (int index = 0; (index < row) && !found; index++)
				{
					if (array[index][searchCol - 1] == searchValue)
					{
					found = true;
					position = index;
					}
				}
			}
		}
		else
		{
			// Linear search
			found = false;
			position = -1;
			for (int index = 0; (index < row) && !found; index++)
			{
				if (array[index][searchCol - 1] == searchValue)
				{
				found = true;
				position = index;
				}
			}
		}
	}
	else
	{
		// Linear search
		found = false;
		position = -1;
		for (int index = 0; (index < row) && !found; index++)
		{
			if (array[index][searchCol - 1] == searchValue)
			{
				found = true;
				position = index;
			}
		}
	}

	if (found)
		cout << "That value was found in row " << position + 1 << ".\n\n";
	else
		cout << "That value was not found.\n\n";
	
	return;
}
