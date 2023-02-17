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

void readFile(playerType footballTeam[], ifstream& inFile, const int SIZE){
    string line;
    bool check = false;
    string lastName;
    inFile.open ("output.txt");
    if (inFile.is_open()) {
    while (!inFile.eof()) {
        for(int i = 0; i < SIZE; i++) {
            getline( inFile >> ws, footballTeam[i].name, ',' ) >> footballTeam[i].lastName >> footballTeam[i].pos >> footballTeam[i].touchDowns >> footballTeam[i].catches >> footballTeam[i].passingYards >> footballTeam[i].recievingYards >> footballTeam[i].rushingYards;
        }

        }
    }
    //getline
    inFile.close();
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
    readFile(footballTeam, inFile, SIZE);
    cout << "hello";
    for (int i = 0; i < SIZE; i++) {
    cout << footballTeam[i].name << endl;
    cout << footballTeam[i].lastName << endl;
    cout << footballTeam[i].pos << endl;
    cout << footballTeam[i].touchDowns << endl;
    cout << footballTeam[i].catches << endl;
    cout << footballTeam[i].passingYards << endl;
    cout << footballTeam[i].recievingYards << endl;
    cout << footballTeam[i].rushingYards << endl;
    };
    


return 0;
}