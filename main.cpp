#include <algorithm>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>

using namespace std;

struct playerType {
    string lastName;
    string name;
    string pos;
    string touchDowns;
    string catches;
    string passingYards;
    string recievingYards;
    string rushingYards;
};

void readFile(playerType footballTeam[], ifstream& inFile){
    string line;
    bool check = false;
    string lastName;
    int i = 0;
    inFile.open ("output.txt");
    if (inFile.is_open()) {
    while (!inFile.eof()) {
        while(getline( inFile >> ws, footballTeam[i].name, ',' ) >> footballTeam[i].lastName >> footballTeam[i].pos >> footballTeam[i].touchDowns >> footballTeam[i].passingYards >> footballTeam[i].recievingYards >> footballTeam[i].rushingYards) {
            cout << "hello";
            //lastName = footballTeam[i].name + footballTeam[i].lastName;
           // footballTeam[i].name = lastName;
            i++;
        }
        inFile.close();
        }
    }
    //getline
    cout << "test";
};
void writeFile(ofstream& outFile){
    outFile.open ("output.txt");


    outFile.close();
};

void lookUpPlayer(playerType footballTeam[]) {
    cout << "\033c";



};
void editPlayer(playerType footballTeam[]){
    cout << "\033c";

};
void printTeamRoster(playerType footballTeam[]){
    cout << "\033c";
};
void menu(playerType footballTeam[], const int SIZE){
    int choice = 0;
    do {
    cout << "\033c";
   //  system("CLS");
    cout << "1. look up player" << endl;
    cout << "2. edit a player" << endl;
    cout << "3. print team roster" << endl;
    cout << "4. Quit" << endl;
    cin >> choice;
    cin.clear();
    cin.ignore();

    switch (choice) {
        case 0:
        cout << "invalid" << endl;
        break;
        case 1: 
        lookUpPlayer(footballTeam);
        break;
        case 2:
        editPlayer(footballTeam);
        break;
        case 3:
        printTeamRoster(footballTeam);
        break;
        case 4:
        cout << "exited program" << endl;
        break;
        default:
        cout << "invalid" << endl;
    };
    } while(choice != 4);
};



int main() {
    ofstream outFile;
    ifstream inFile;


    
    const int SIZE = 10;
    playerType footballTeam[SIZE];
    readFile(footballTeam, inFile);
    cout << "hello";
    for (int i = 0; i < 10; i++) {
    cout << footballTeam[i].name << endl;
    cout << footballTeam[i].lastName << endl;
    }
    


return 0;
}