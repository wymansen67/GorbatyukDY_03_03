#include <iostream>
#include <string>
#include <fstream>
#include "GorbatyukDY_03_03.h"
using namespace std;

class Shop {
    private:

       
        
    public:

        string Name = "";
        int Number = 0;
        //Площадь зала
        double HallS = 0;
        //Площадь склада
        double StorageS = 0;

        //Constructor
        Shop() {  }

        //Extended constructor
        Shop(string name, int number, double hallS, double storageS) {
            Name = name;
            Number = number;
            HallS = hallS;
            StorageS = storageS;
        }

        //Debugging method
        void GetData() {
            cout << "Shop name: " << Name << endl << "Shop number: " << Number << endl << "Shop hall storage: " << HallS << endl << "Shop storage storage: " << StorageS << endl;
        }
        //Emptiness check
        bool isEmpty() {
            if (Name == "" || Number == 0 || HallS == 0 || StorageS == 0) return true;
            else return false;
        }
};

int main()
{
    //Global variables
    Shop shops[256];
    int counter = 0;

    string name = "";
    int num = 0;
    double hallS = 0;
    double storageS = 0;
    //input var
    string input;
    //input method
    bool end = false;
    do {
        //Input shop number
        cout << "Input shop name " << counter + 1 << " ( input 0 to exit ): ";
        cin >> input;
        if (input == "0") {
            end = true;
            break;
        }
        else {
            name = input;
            input == "";
        }
        //Input shop number
        cout << "Input shop number " << counter + 1 <<  " (input 0 to exit) : ";
        cin >> input;
        if (input == "0") {
            end = true;
            break;
        }
        else {
            num = stoi(input);
            input == "";
        }
        //input sho hall space
        cout << "Input shop hall space " << counter + 1 << " ( input 0 to exit ): ";
        cin >> input;
        if (input == "0") {
            end = true;
            break;
        }
        else {
            hallS = stod(input);
            input == "";
        }
        //input shop storage space
        cout << "Input shop storage space " << counter + 1 << " ( input 0 to exit ): ";
        cin >> input;
        if (input == "0") {
            end = true;
            break;
        }
        else {
            storageS = stod(input);
            input == "";
        }
        if (!name.empty() && num > 0 && hallS > 0 && storageS > 0) {
            //Create shop and list it
            Shop shop = Shop(name, num, hallS, storageS);
            shops[counter] = shop;
            if (counter+1 > 255) {
                cout << "Limit reached";
                break;
            }
            else {
                counter++;
            }
        }

    } while (!end);

    //File stream write
    ofstream file = ofstream("Shops.txt");
    do {
        cout << "Input sort type. 0 for ascending or 1 for descending:  ";
        cin >> input;
    } while (input != "0" && input != "1");

    //Save data to file in ascending
    if (input == "0") {
        int j = 0;
        for (int i = 255; i > -1, i--;) { 
            if (j + 1 > 255) break;
            if (!shops[j].isEmpty()) { file << "Shop name: " << shops[j].Name << endl << "Shop number: " << shops[j].Number << endl << "Shop hall storage: " << shops[j].HallS << endl << "Shop storage storage: " << shops[j].StorageS << endl; 
            j++; }
            else break;
        }
    }
    //Save data to file in descending
    if (input == "1") {
        for (int i = 255; i > -1, i--;) {
            if (!shops[i].isEmpty()) file << "Shop name: " << shops[i].Name << endl << "Shop number: " << shops[i].Number << endl << "Shop hall storage: " << shops[i].HallS << endl << "Shop storage storage: " << shops[i].StorageS << endl;
        }
    }
    file.close();
    
    return 0;
}
