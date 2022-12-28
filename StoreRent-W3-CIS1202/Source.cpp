/*
Kurt Kangas
01/28/2022
Week 3
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void enterRents(float[], int* pnt);
void displayRents(float[], int* pt);
void displayMemoryLocations(float[], int* point);
void selectionSort(float[], int* point);

int getMenuItem(int&);

int main()
{
	int selection = 0;
	const int SIZE = 25;
	float rent[SIZE];
	int numRents = 0;


	getMenuItem(selection);

	while (selection != 5)
	{
		switch (selection)
		{
		case 1:
			// Enter rent amounts
			enterRents(rent, &numRents);
			getMenuItem(selection);
			break;
		case 2:
			// Display rent amounts
			displayRents(rent, &numRents);
			getMenuItem(selection);
			break;
		case 3:
			// Sort
			selectionSort(rent, &numRents);
			getMenuItem(selection);
			break;
		case 4:
			// Display memory locations
			displayMemoryLocations(rent, &numRents);
			getMenuItem(selection);
			break;
		case 5:
			// Exit;
			exit(0);
			break;
		default:
			cout << "Invalid selection. Please enter a number 1-5: ";
			cin >> selection;
		}
	}
	system("pause");
	return 0;
}
int getMenuItem(int& selection)
{
	// Display Menu
	cout << "1. Enter rent amounts";
	cout << "\n2. Display rent amounts";
	cout << "\n3. Sort rent amounts from low to high";
	cout << "\n4. Display memory locations";
	cout << "\n5. Exit";

	cout << "\nEnter selection: ";
	cin >> selection;
		if (selection > 0 && selection < 6)
		{
			return selection;
		}

}

void enterRents(float arr[], int* count)
{
	int counter = 0;
	int position = 0;
	int size = 1;
	char answer = 'y';
	do {
		for (int i = 0; i < 1; ++i)
		{
			i = position;
			cout << "POS: " << position;
			cout << "Enter rent amount " << i + 1 << ": ";
			cin >> arr[i];
			counter++;
			position++;
		}
		cout << "Add another? Y or N... ";
		cin >> answer;
	}
	while (answer != 'N' && answer != 'n');
	*count = counter;
}

void displayRents(float arr[], int* count)
{

	cout << fixed << setprecision(2);
	cout << "Rents:" << endl;

	int len = *(&arr + 1) - arr;
	int leng = 0;

	for (int i = 0; i < len; ++i) {

		if (arr[i] > 0 && arr[i] > 1 && arr[i] != -1)
		{
			leng++;
		}
	}
	for (int i = 0; i < leng; i++)
	{
			cout << setw(10) << right << *(arr + i) << endl;
	}
}

void selectionSort(float rent[], int* count)
{
	cout << *count << endl;
	cout << setprecision(2) << fixed;

	const int SIZE = 5;

	float tempRent;

	int len = *count;
	if (*count >= 2) {
		for (int i = 0; i < len - 1; i++)
		{
			for (int j = i + 1; j < len; j++)
			{
				if (rent[j] < rent[i])
				{
					tempRent = rent[i];
					rent[i] = rent[j];
					rent[j] = tempRent;

				}
			}
		}
	}
}

void displayMemoryLocations(float arr[], int* count)
{
	int len = *count;
	for (int i = 0; i < len; ++i) {
		cout << setw(19) << right << (arr + i) << endl;
	}
}
