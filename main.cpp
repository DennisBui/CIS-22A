// Lottery Program
// Dennis Bui
// December 2, 2015
// OSX Xcode
// This program will prompt the user for a certain amount of lottery numbers, the program
// will test if the lottery entries match the winning numbers. The program will display the
// amount of matches too.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <string>
#include <cctype>

using namespace std;

const int ELEMENTS = 9;     // Maximum amount of loterry numbers that could be read

void idFunction(int hwNum);

bool readArrayFromFile( int numbers[], int &numElems, int &maxNumRead, int maxElems);

bool openInputFile(ifstream &ifs);

void readFromUser( int entryNums[], int numElems, int maxNumRead);

int searchList(int list[], int numElems, int value);

int matchFunction( int entryNums[], int numbers[], int numElems);

void lottoSort( int entryNums[], int numbers[], int numElems);

void selectionSort(int array[], int size);

void displayFunction(int entryNums[], int numbers[], int match, int numElems);

int main()
{
    int entryNums[ELEMENTS];        // Entry numbers from the user
    int prizeNums[ELEMENTS];        // Winning prize numbers;
    int numElems;                   // The number of elements in the particular lottery
    int maxNum;                     // Maximum value for each individual lottery
    int match;                      // The amount of matches in a lottery
    
    idFunction(6);
    
    if(readArrayFromFile(prizeNums, numElems, maxNum, ELEMENTS) == false)
    {
        return 1;
    }
    
    readFromUser(entryNums, numElems, maxNum);
    
    match = matchFunction(entryNums, prizeNums, numElems);
    
    lottoSort(entryNums, prizeNums, numElems);
    
    displayFunction(entryNums, prizeNums, match, numElems);
}

//*************************************************************************************
//Definition of function readArrayFromFile. This function accepts values from an      *
//input file, and declares them to be the winning numbers. The function returns true  *
//if the file can be opened or false if the file cannot be opened. The return value is*
//a bool.                                                                             *
//*************************************************************************************

bool readArrayFromFile( int numbers[], int &numElems, int &maxNumRead, int maxElems)
{
    ifstream inputFile;     // Name of the input file
    
    if( !openInputFile(inputFile) )
    {
        cout << "Can't open input file" <<endl;
        return false;
    }
    
    
    inputFile >> maxNumRead;
    inputFile >> numElems;
    
    if(numElems > maxElems)
    {
        numElems = maxElems;
    }
    
    for(int i = 0; i < numElems; i++)
    {
        inputFile >> numbers[i];
    }
    return true;
}

//**************************************************************************************
//Definition of function openInputFile. This function accepts strings from the user. If*
//an input file exists with the string name, the file will open. The function returns  *
//open if the name exists, and pops back if the file fails.                            *
//**************************************************************************************

bool openInputFile(ifstream &ifs)
{
    string filename;        //The name of the file you want to open
    
    cout << "Enter the input filename: ";
    getline(cin, filename);
    
    if( isspace(filename[filename.length()-1]) )
        filename.pop_back();

    
    ifs.open(filename.c_str());
    return ifs.is_open();
}

//*************************************************************************************
//Definition of function readFromUser. This function accepts values from the user.    *
//the input is then used and put into an array named entryNums                        *
//*************************************************************************************
void readFromUser( int entryNums[], int numElems, int maxNumRead)
{
    
    
    cout << "Enter " << numElems << " numbers between 1 and " << maxNumRead <<endl;
    
    for( int i = 0; i < numElems; i++)
    {
        cout << "Enter number #" << i + 1<< ": ";
        cin >> entryNums[i];
       
        
        if(entryNums[i] < 1 || entryNums[i] > maxNumRead)
        {
            cout << "Number out of range, must be >= 1 and <= " << maxNumRead << "!" <<endl;
            --i;
        }
        
        else if(searchList(entryNums, i, entryNums[i]) != -1)
        {
            cout << "You already chose that number!"<<endl;
            --i;
        }
    }
    
    
}

//*************************************************************************************
//Definition of function searchList. This function takes values from an array and     *
//tests to see if a certain input value is inside the array. If the input value is    *
//already in the array then the function returns the position, if not then it returns *
//the number -1                                                                       *
//*************************************************************************************

int searchList(int list[], int numElems, int value)
{
    int index = 0;      // Used as a subscript to search array
    int position = -1;  // To record position of search value
    bool found = false; // Flag to indicate if value was found
    while (index < numElems && !found)
    {
        if (list[index] == value) // If the value is found
        {
            found = true; // Set the flag
            position = index; // Record the value's subscript
        }
        index++; // Go to the next element
    }
    return position; // Return the position, or -1
}

//***************************************************************************************
//Definition of function matchFunction. This function takes in values from array 1 and  *
//tests to see if any of the values from array 1 are in array 2. Everytime the function *
//finds a match, the variable match increments. The functions returns the number of     *
//matches.                                                                              *
//***************************************************************************************
int matchFunction(int entryNums[], int numbers[], int numElems)
{
    int match = 0;      // The number of matches from the two arrays.
    
    
        for (int i = 0; i < numElems; i++)
        {
            if(searchList(entryNums, numElems, numbers[i]) != -1)
            {
                match++;
            }
        }
    
    return match;
}

//*************************************************************************************
//Definition of function selectionSort. This function takes values from an array and  *
//puts the values from the array into numerical order from least to greatest          *
//*************************************************************************************
void selectionSort(int array[], int size)
{
    int startScan, minIndex, minValue;
       for (startScan = 0; startScan < (size - 1); startScan++)
        {
        minIndex = startScan;
        minValue = array[startScan];
        for(int index = startScan + 1; index < size; index++)
            {
            if (array[index] < minValue)
                {
                minValue = array[index];
                minIndex = index;
                }
            }
            array[minIndex] = array[startScan];
            array[startScan] = minValue;
        }
}

//**************************************************************************************
//Definition of function lottoSort. This function takes values from from array 1       *
//and puts the values in numerical order from least to greatest. Then the function     *
//takes values from array 2 and puts the values in numerical order from least to       *
//greatest. The function has no return value.                                          *
//**************************************************************************************

void lottoSort (int entryNums[], int numbers[], int numElems)
{
    selectionSort(entryNums, numElems);
    selectionSort(numbers, numElems);
}
//**************************************************************************************
//Definition of function displayFunction. This function takes values from the lotteries*
//and prints out the values from the numbers of winning numbers, the numbers the       *
//user entered, and how many number matched                                            *
//**************************************************************************************
void displayFunction (int entryNums[], int numbers[], int match, int numElems)
{
    cout << "Lotto Game Numbers: ";
    for(int i = 0; i < numElems; i++)
    {
        cout << setw(4) << numbers[i];
    }
    cout << endl;
    
    cout << "Your Numbers: ";
    for(int j = 0; j < numElems; j++)
    {
        cout << setw(4) << entryNums[j];
    }
    cout << endl;
    
    cout << "You matched " << match << " number(s)" << endl;
    
}

//**************************************************************************************
//Definition of function idfunction. This function uses the homework number and uses   *
//it to print out a label at the top of the program saying the homework number and the *
//name of the person who wrote the program.                                            *
//**************************************************************************************

void idFunction( int hwNum)
{
    cout << "CIS 22A Homework #" << hwNum<<endl;
    cout << "Bui, Dennis"<<endl;
}
    
/*
 CIS 22A Homework #6
 Bui, Dennis
 Enter the input filename: HW6TestInput1.txt
 Enter 6 numbers between 1 and 49
 Enter number #1: 45
 Enter number #2: 25
 Enter number #3: 35
 Enter number #4: 15
 Enter number #5: 5
 Enter number #6: 40
 Lotto Game Numbers:    2   7  19  20  35  43
 Your Numbers:    5  15  25  35  40  45
 You matched 1 number(s)
 Program ended with exit code: 0
 */

/*
 CIS 22A Homework #6
 Bui, Dennis
 Enter the input filename: HW6BadInputFileName
 Can't open input file
 Program ended with exit code: 1
 */

/*
 CIS 22A Homework #6
 Bui, Dennis
 Enter the input filename: HW6TestInput2.txt
 Enter 5 numbers between 1 and 41
 Enter number #1: 41
 Enter number #2: 42
 Number out of range, must be >= 1 and <= 41!
 Enter number #2: 41
 You already chose that number!
 Enter number #2: 0
 Number out of range, must be >= 1 and <= 41!
 Enter number #2: 43
 Number out of range, must be >= 1 and <= 41!
 Enter number #2: 41
 You already chose that number!
 Enter number #2: 1
 Enter number #3: 0
 Number out of range, must be >= 1 and <= 41!
 Enter number #3: 41
 You already chose that number!
 Enter number #3: 1
 You already chose that number!
 Enter number #3: 0
 Number out of range, must be >= 1 and <= 41!
 Enter number #3: -1
 Number out of range, must be >= 1 and <= 41!
 Enter number #3: -2
 Number out of range, must be >= 1 and <= 41!
 Enter number #3: -3
 Number out of range, must be >= 1 and <= 41!
 Enter number #3: 1
 You already chose that number!
 Enter number #3: 2
 Enter number #4: 40
 Enter number #5: 3
 Lotto Game Numbers:    1  12  23  34  41
 Your Numbers:    1   2   3  40  41
 You matched 2 number(s)
 Program ended with exit code: 0
 */






