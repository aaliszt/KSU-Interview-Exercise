// Aaron Liszt
// Interview coding exercise
// A Program to take a user input list of numbers and a delimiter that will then multiply those numbers based on the given delemiter.

#include <iostream>
#include <vector>
#include <string>

// NOTE: Code supports lists of numbers with:
// More than one digit					X  Ex: (100,10,5,10)
// Multiple digits						X  Ex: (2,4,6)
// Custom single digit delimeters		X  Ex: (10\9\8\7)
// But does not currently support long delimeters Ex: (4+++2+++3++)

// INPUT: A list of numbers seperated by a delimiter, and a user specified delemiter
// OUTPUT: The product of the given numbers
int Multiply(std::string numbers, std::string delimiter) {
	int product = 1;				// Stores the product to return
	int size = numbers.size();		
	int real_size = size - 1;		// The size of the string numbers for index checking
	int currentNum = 1;				// Holds the current number parsed out of the sequence
	std::string numSubstring;		// Holds a substring with a number from numbers
	char startDelim = delimiter[0];  // Holds the start character of the delimiter
	int delimLen = delimiter.size(); // The length of the delimeter string

	// Check for empty string
	if (numbers.size() == 0) {
		return 0;
	}
	// Check for single number
	else if (numbers.size() == 1) {
		return std::stoi(numbers);
	}
	// Parse numbers from string by breaking numbers into substrings
	else {
		int lastDelim = 0; // Marks the location of the last ',' character in numbers

		//product = product * (int)(numbers[0] - '0'); // Convert first char to int and multiply

		for (int i = 0; i < numbers.size(); ++i) {

			// Initialize start delimeter for the first delimeter we find and mutiply by first number
			// Seems tedious but is needed for numbers greater than a single digit
			if (numbers[i] == startDelim && lastDelim == 0) { 
				lastDelim = i;
				numSubstring = numbers.substr(0, i); // Construct a new string with just the number
				currentNum = std::stoi(numSubstring);
				product = product * currentNum;
			}

			// Gets numbers from the middle of the list
			if (numbers[i] == startDelim && lastDelim != i) {
				std::string sub(numbers.begin() + (lastDelim + 1), numbers.begin() + i); // Construct a new string with just the number
				std::cout << "lastDelim: " << lastDelim << "\t currentIndex: " << i << std::endl;
				std::cout << "substring: " << sub << "\n";
				currentNum = std::stoi(sub); 
				product = product * currentNum;
				lastDelim = i;
			}

			// Get the last number in the list
			if (i == real_size) {
				numSubstring = numbers.substr(lastDelim + 1, real_size);
				currentNum = std::stoi(numSubstring);
				product = product * currentNum;
			}
		}
		return product;
	}

	return -1; // An error occured if we reach this point
}

int main() {
	std::string userNumbers;			// User entered list of numbers
	std::string userDelimeter(",");		// Delimeter to be applied to the numbers, is ',' by default

	int continueLoop = 0;
	int userSelection = 0;
	int numListProduct;

	while (continueLoop != 4) {
		std::cout << "\n Please select an option from the list... \n";
		std::cout << "1. Enter a list of numbers \n";
		std::cout << "2. Enter a delimeter \n";
		std::cout << "3. Multiply numbers \n";
		std::cout << "4. Exit \n";
		std::cout << "Enter your selection number here as '1', '2', ... (without ''): ";
		std::cin >> userSelection;
		std::cout << "\n";

		switch (userSelection) {
			// User enters a list of numbers
		case 1:
			std::cout << "Enter your list of numbers: ";
			std::cin >> userNumbers;
			break;

			// User enters thier own delimeter
		case 2:
			std::cout << "Enter your delimeter such as '.' or '/': ";
			std::cin >> userDelimeter;
			std::cout << "\n";

			break;
			// Multiply users numbers
		case 3:
			numListProduct = Multiply(userNumbers, userDelimeter);

			if (numListProduct == -1) {
				std::cout << "An error occured while multiplying your number list";
				break;
			}

			std::cout << "The product of your integers is: " << numListProduct << std::endl;
			break;

			// Exit the program
		case 4:
			continueLoop = 4;
			std::cout << "Thank you for your time! Exiting... \n";
			break;

			// User gave invalid input
		default:
			std::cout << "Please enter a valid integer! \n";
			break;
		}
	}
}