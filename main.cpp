// Taxable Income Program
// Dennis Bui
// October 26, 2015
// OSX Xcode
// This program will display tax owed and tax refunded based on tax liability
// and tax withheld

#include <iostream>
#include <iomanip>
using namespace std;
void idFunction(int hwNum);

const double taxPercent1 = .15;
const double taxPercent2 = .28;
const double taxPercent3 = .35;
const double income1 = 36900;
const double income2 = 186350;
int main()
{
    
    double taxableIncome;       // The amount of income
    double taxWithHeld;         // The amount of tax paid
    double taxLiability;        // The amount of tax you must pay
    double taxOwed;             // The amount of tax you owe
    double taxRefund;           // The amount of tax you get refunded
    
    idFunction(3);
    
    
    cout << "Input your taxable income  ";
    cin >> taxableIncome;
    
    cout << "Input your tax with held  ";
    cin >> taxWithHeld;
    
    cout << endl;

    //Calculations
    
    if((taxableIncome > 0) && (taxableIncome <= income1))
      taxLiability = (taxableIncome * taxPercent1);
    else if ((taxableIncome > income1) && (taxableIncome <= income2))
        taxLiability = ((taxableIncome - income1)*(taxPercent2)) + ((income1)*(taxPercent1));
    else if (taxableIncome > income2)
        taxLiability = (income1 * taxPercent1) + (149450 * taxPercent2) + ((taxableIncome - income2)*(taxPercent3));
    else
        taxLiability = 0;
    
    if(taxLiability > taxWithHeld)
        taxOwed = taxLiability - taxWithHeld;
    else
        taxRefund = taxWithHeld - taxLiability;
    
   
    //Output
    
    cout.precision(2);
    cout << "Taxable Income:    " << fixed << taxableIncome <<endl;
    cout << "Tax Withheld:      " << fixed << taxWithHeld <<endl;
    cout << "Tax Liability:     " << fixed << taxLiability <<endl;
    if (taxLiability >= taxWithHeld)
        cout << "Tax Owed:          " << fixed << taxOwed <<endl;
    else
        cout << "Tax Refund:        " << fixed << taxRefund <<endl;
   
    return 0;
    
}

void idFunction(int hwNum)
{
    cout << "CIS 22A Programming Homework # 3"<<endl;
    cout << "Bui, Dennis"<<endl<<endl;
}

/*
 CIS 22A Programming Homework #3
 Bui, Dennis
 
 Input your taxable income  1234567.00
 Input your tax with held  234567.00
 
 Taxable Income:    1234567.00
 Tax Withheld:      234567.00
 Tax Liability:     414256.95
 Tax Owed:          179689.95
 Program ended with exit code: 0
 */
