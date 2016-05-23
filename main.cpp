// Wind Chill Program
// Dennis Bui
// November 23, 2015
// OSX Xcode
// This program will calculate wind chill of a certiain farenheit range and create a table

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

const double LOWBORDER1 = -50;      //This is as low as the temperature can get
const double LOWBORDER2 = 45;       //This is as high as the temperature can get for the low bound
const double HIGHBORDER1 = 5;       //The highest temperature has to be at least 5 degrees higher than
                                    //the low temperature
const double HIGHBORDER2 = 50;      //The highest temperature can be up to 50 degrees higher than
                                    //the low temperature
const int INCREMENT = 5;            //Use this as an increment for wind speed

void idFunction (int hwNum);

void readf(double &a,
           double &b);

void tablef(double &a,
            double &b,
            int lowWindSpeed,
            int highWindSpeed);

double windCalc(double windSpeed,
                double airTemp);

int main()
{
    
    idFunction(5);
    
    int lowWindSpeed = 5;       //Lowest boundary for wind speed mph
    int highWindSpeed = 40;     //Highest boundary for wind speed mph
    
    double lowTemp;
    double highTemp;
    double airtemp;
    double windSpeed;
    double airTemp;
    ofstream windTab;
    
    readf(lowTemp, highTemp);
    
    windCalc( windSpeed, airTemp);
    
    tablef(lowTemp, highTemp, lowWindSpeed, highWindSpeed);
    
    
}

void readf(double &a,
           double &b)
{
    
        cout << "Please enter the lowest temperature on the table ";
        cin >> a;
    
    while( a < LOWBORDER1 || a > LOWBORDER2)
    {
        cout << "Please enter a value between -50 and 45 ";
        cin >> a;
    }
    
        cout << "Please enter the highest temperature on the table ";
        cin >> b;
    
    while( b < a + HIGHBORDER1 || b > a + HIGHBORDER2)
    {
        cout << "Please enter a value 5 greater than the lowest temperature ";
        cin >> b;
    }

}       //End of readf

void tablef(double &a,
            double &b,
            int lowWindSpeed,
            int highWindSpeed)
{
    
    ofstream windTab;
    double windChill;
    int windSpeed;
    int airTemp;
    
    windTab.open("WindChillTable.txt");
    if(windTab.fail())
    {
        cout << " Unable to open file" <<endl;
        return;
    }
    
    windTab << "Wind Chill Temperatures (Degrees F)" <<endl;
    windTab << "                    Wind Speed (MPH)" <<endl;
    windTab << "Air temp";
    for(double windSpeed = lowWindSpeed; windSpeed <= highWindSpeed; windSpeed += INCREMENT)
    {
        windTab << setw(7) << windSpeed;
    }
        
    
    for (double airTemp = a ; airTemp <= b; airTemp++)
    {
        windTab << endl;
        windTab.precision(0);
        windTab << setw(6) << fixed << airTemp << "    ";
        
        for (windSpeed = lowWindSpeed; windSpeed <= highWindSpeed; windSpeed += INCREMENT)
        {
            windChill = windCalc(airTemp, windSpeed);
            windTab.precision(1);
            windTab << fixed << setw(5) <<windChill << "  ";
        }
    }
        
    
    
}       //End of tablef

double windCalc(double airTemp, double windSpeed)
{
    double solution;
    
    solution = (35.74) + ((0.6215)*(airTemp) - ((35.75)*pow(windSpeed,0.16)) + ((0.4275 * airTemp)*pow(windSpeed,0.16)));
    
    return solution;
    
}

void idFunction(int hwNum)
{
    cout << "CIS 22A Programming Homework #" << hwNum << endl;
    cout << "Bui,Dennis" << endl <<endl;
}       //End of windCalc

/*
 CIS 22A Programming Homework #5
 Bui,Dennis
 
 Please enter the lowest temperature on the table -15
 Please enter the highest temperature on the table 35
 Program ended with exit code: 0
 */

 
