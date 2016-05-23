//Coordinate Distance Program
//Dennis Bui
//October 6,2015
//OSX Xcode
//This program will determine distance by inputting coordinates

#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

void idFunction();

const double radius = 3959;             // The radius of the earth
const double degRad = 57.2957795;       // Convert to radians
const double vertKilo = 8./5.;          // Convert to kilometers


int main()
{
    idFunction();
    
    string lottoStore;          //Name of the lottery store
    double latitude2;           //Latitude of the lottery store
    double longitude2;          //Longitude of the lottery store
    double latitude1;           //Latitude of home address
    double longitude1;          //Longitude of home address
    double deltalatitude;       //The difference between the latitudes
    double deltalongitude;      //The difference between the longitudes
    double part1;
    double part2;
    double distanceMiles;       //The distance in miles
    double distanceKilo;        //The distance in kilometers
    
    
    cout << "Input the address of the store ";
    getline(cin,lottoStore);
    
    cout << "Input the latitude of the store ";
    cin >> latitude2;
    
    cout << "Input the longitude of the store ";
    cin >> longitude2;
    
    cout << "Input the latitude of your home ";
    cin >> latitude1;
    
    cout << "Input the longitude of your home ";
    cin >> longitude1;
    
    //Calculations
    latitude1 = latitude1/degRad;       //latitude 1 converted into radians
    latitude2 = latitude2/degRad;       //latitude 2 converted into radians
    longitude1 = longitude1/degRad;     //longitude 1 converted into radians
    longitude2 = longitude2/degRad;     //longitude 2 converted into radians
    
    deltalatitude = (latitude2 - latitude1);
    deltalongitude = (longitude2 - longitude1);
    part1 = pow(sin(deltalatitude/2),2) + cos(latitude1) * cos(latitude2) * pow(sin(deltalongitude/2),2);
    part2 = 2 * atan2(sqrt(part1),sqrt(1 - part1));
    distanceMiles = radius * part2;
    distanceKilo = distanceMiles * vertKilo;
    
    //Output
    
    cout.precision(4);
    cout << "Store address:" <<endl;
    cout << "    " <<lottoStore<<endl;
    cout << "Earth's Radius (in miles):     " <<radius<<endl;
    cout << "Latitude difference:          " << setw(7) << fixed <<deltalatitude<<endl;
    cout << "Longitude difference:         " << setw(7) << fixed <<deltalongitude<<endl;
    cout << "Part 1 of calculation:        " << setw(7) << fixed <<part1<<endl;
    cout << "Part 2 of calculation:        " << setw(7) << fixed <<part2<<endl;
    cout << "Distance to the store (mi):   " << setw(7) << fixed <<distanceMiles<<endl;
    cout << "Distance in kilometers:       " << setw(7) << fixed <<distanceKilo<<endl;
    
    return 0;
    
}

void idFunction()
{
    cout << "Bui, Dennis" <<endl;
    cout << "CIS 22a Homework #2" <<endl;
}

/*
 Bui, Dennis
 CIS 22a Homework #2
 Input the address of the store 14000 Fruitvale Av, Saratoga
 Input the latitude of the store 37.2634
 Input the longitude of the store 122.0100
 Input the latitude of your home 37.3911
 Input the longitude of your home 121.9821
 Store address:
 14000 Fruitvale Av, Saratoga
 Earth's Radius (in miles):     3959
 Latitude difference:          -0.0022
 Longitude difference:          0.0005
 Part 1 of calculation:         0.0000
 Part 2 of calculation:         0.0023
 Distance to the store (mi):    8.9559
 Distance in kilometers:       14.3295
 Program ended with exit code: 0
 */


