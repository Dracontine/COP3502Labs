// Lab 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <unordered_map>
using namespace std;
int main()
{
    string title;
    string col1name;
    string col2name;
    string str;
    vector<string> names;
    vector<string> numbers;




    cout << "Enter a title for the data:" << endl;
    getline(cin, title);
    cout << "You entered: " << title << endl;


    cout << "Enter the column 1 header:" << endl;// column one
    cout << endl;
    getline(cin, col1name);
    cout << "You entered: " << col1name << endl;
    cout << endl;

    cout << "Enter the column 2 header:" << endl; // column two
    cout << endl;
    getline(cin, col2name);
    cout << "You entered: " << col2name << endl;

    while (1) {

        cout << "\nEnter a data point (-1 to stop input): " << endl;
        getline(cin, str);
        if (str == "-1")
            break;
        unordered_map<char, int> mp;
        for (int i = 0; i < str.size(); i++) {
            mp[str[i]]++; //string.find find.last_of
        }

        try {

            if (mp[','] == 0)
            {
                string excep = "Error: No comma in string.\n";
                throw excep;
            }
            if (mp[','] > 1)
            {
                string excep = "Error: Too many commas in input.\n";
                throw excep;
            }
        }
        catch (string excep) {
            cout << excep;
            continue;
        }



        string tmp1, tmp2;
        int i = 0;
        for (; i < str.size(); i++) {

            if (str[i] == ',')
                break;
            tmp1 += str[i];
        }

        i += 2;
        while (i < str.size()) {
            tmp2 += str[i];
            i++;
        }
        try {
            int x = stoi(tmp2);
        }
        catch (std::invalid_argument& e) {
            cout << "Error: Comma not followed by an integer.\n";
            continue;
        }
        cout << "\nData string: " << tmp1;
        cout << "\nData integer: " << tmp2 << endl;

        /*try {
            int x = stoi(tmp2);
        }
        catch (std::invalid_argument& e) {
            cout << "Error: Comma not followed by an integer.\n";
            continue;
        }*/


        names.push_back(tmp1);
        numbers.push_back(tmp2);

    }
    // table of values
    cout << setw(33) << right << title << endl;
    cout << setw(20) << left << col1name << "|" << setw(23) << right << col2name << endl;
    cout << "--------------------------------------------" << endl;
    for (int i = 0; i < names.size(); i++) {
        cout << setw(20) << left << names[i] << "|" << setw(23) << right << numbers[i] << endl; // setw statement 
    }
    cout << "\n";

    //histogram
    for (int i = 0; i < names.size(); i++) {
        cout << setw(20) << right << names[i] << " ";
        for (int j = 0; j < stoi(numbers[i]); j++) {
            cout << "*";
        }
        cout << endl;
    }


    //cout << setw(20) << right << names[i] << " " << numbers[i] << endl
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
