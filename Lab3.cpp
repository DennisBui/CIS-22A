// Currency Conversion Program
// Dennis Bui
// November 10, 2015
// OSX XCode
// This program converts any amount of USD into another desired currency

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

void idFunction (int hwNum);

const double CANADIANRATIO = 1.31;       //Number of Canadian dollars in one USD
const double MEXICANRATIO = 16.44;       //Number of Mexican pesos in one USD
const double EUROPEANRATIO = 0.90;       //Number of Euros in one USD
const double CHINESERATIO = 6.36;        //Number of Chinese Yuan in one USD
const double JAPANESERATIO = 120.53;     //Number of Japanese Yen in one USD

int main()
{
    idFunction(4);
    
    //VARIABLES
    
    int choice;                        //Choice from the menu of conversions
    double usDollar;                   //Amount of money in USD
    double conversionResult;           //Result after conversion
    char yesOrNo;                      //Make another conversion?
    string currencyType;               //Type of currency
    
    do
    {
        
        //INPUT
        
        cout << "Currency Options (Output)" << endl;
        cout << "1 - Canadian Dollar" << endl;
        cout << "2 - Chinese Yuan" << endl;
        cout << "3 - Euro" << endl;
        cout << "4 - Japanese Yen" << endl;
        cout << "5 - Mexican Peso" << endl;
        
        cout << "Enter the number of the currency to convert US Dollars to: ";
        cin >> choice;
        
        while ((choice > 5) || (choice < 1))
        {
            cout << endl;
            cout << "Invalid choice, must be 1 to 5." << endl;
            
            cout << "Currency Options (Output)" << endl;
            cout << "1 - Canadian Dollar" << endl;
            cout << "2 - Chinese Yuan" << endl;
            cout << "3 - Euro" << endl;
            cout << "4 - Japanese Yen" << endl;
            cout << "5 - Mexican Peso" << endl;
            
            cout << "Enter the number of the currency to convert US Dollars to: ";
            cin >> choice;
        }
        
        cout << "Enter the value (in US Dollars) to convert: ";
        cin >> usDollar;
        
        while (usDollar <= 0)
        {
            cout << "Invalid value: must be > 0, enter again: ";
            cin >> usDollar;
        }
        
        //CALCULATIONS
        
        switch (choice)
        {
            case 1: conversionResult = usDollar * CANADIANRATIO;
                currencyType = "Canadian Dollars";
                break;
            case 2: conversionResult = usDollar * CHINESERATIO;
                currencyType = "Chinese Yuan";
                break;
            case 3: conversionResult = usDollar * EUROPEANRATIO;
                currencyType = "Euros";
                break;
            case 4: conversionResult = usDollar * JAPANESERATIO;
                currencyType = "Japanese Yuan";
                break;
            case 5: conversionResult = usDollar * MEXICANRATIO;
                currencyType = "Mexican Pesos";
                break;
        }
        
        //OUTPUT
        
        cout.precision(2);
        cout << endl;
        cout << "The converted value in " << currencyType << " = " << fixed << conversionResult <<endl << endl;
        cout << "Would you like to make another conversion? (Enter y for yes): ";
        cin >> yesOrNo;
        cout << endl;
        
    } while ((yesOrNo == 'y') || (yesOrNo == 'Y'));
    
}

void idFunction(int hwNum)
{
    cout << "CIS 22A Programming Homework #" << hwNum << endl;
    cout << "Bui,Dennis" << endl <<endl;
}

/*
 CIS 22A Programming Homework #4
 Bui,Dennis
 
 Currency Options (Output)
 1 - Canadian Dollar
 2 - Chinese Yuan
 3 - Euro
 4 - Japanese Yen
 5 - Mexican Peso
 Enter the number of the currency to convert US Dollars to: 4
 Enter the value (in US Dollars) to convert: 125
 
 The converted value in Japanese Yuan = 15066.25
 
 Would you like to make another conversion? (Enter y for yes): n
 
 Program ended with exit code: 0
*/
