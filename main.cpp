#include <algorithm>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>

using namespace std;

struct playerType
{
    string lastName;
    string name;
    string pos;
    string touchDowns;
    string catches;
    string passingYards;
    string recievingYards;
    string rushingYards;
};

void readFile(playerType footballTeam[], ifstream &inFile, const int SIZE)
{
    string line;
    bool check = false;
    string lastName;
    inFile.open("output.txt");
    if (inFile.is_open())
    {
        while (!inFile.eof())
        {
            for (int i = 0; i < SIZE; i++)
            {
                getline(inFile >> ws, footballTeam[i].name, ',') >> footballTeam[i].lastName >> footballTeam[i].pos >> footballTeam[i].touchDowns >> footballTeam[i].catches >> footballTeam[i].passingYards >> footballTeam[i].recievingYards >> footballTeam[i].rushingYards;
            }
        }
    }
    else
    {
        cout << "invalid file";
    }
    // getline
    inFile.close();
};
void writeFile(ofstream &outFile, playerType footballTeam[], const int SIZE)
{
    outFile.open("output.txt");
    if (outFile.is_open())
    {
        for (int i = 0; i < SIZE; i++)
        {
            outFile << footballTeam[i].name << ", " << footballTeam[i].lastName << " " << footballTeam[i].pos << " " << footballTeam[i].touchDowns << " " << footballTeam[i].catches << " " << footballTeam[i].passingYards << " " << footballTeam[i].recievingYards << " " << footballTeam[i].rushingYards << endl;
        }
    }
    else
    {
        cout << "invalid file";
    }

    outFile.close();
};

void lookUpPlayer(playerType footballTeam[])
{
    int choice = 0;
    do
    {
    
    cout << "\033c";
    cout << "<0> exit";
    cin >> choice;
    cin.clear();
    cin.ignore();
    switch (choice) {
        case 0:
        cout << "exit";
        default:
            cout << "invalid" << endl;
    };
    } while (choice != 0);
};
void editPlayer(ofstream& outFile, playerType footballTeam[], const int SIZE)
{
    cout << "\033c";
};
void printTeamRoster(playerType footballTeam[])
{
    cout << "\033c";
};
void menu(playerType footballTeam[], const int SIZE, ofstream& outFile)
{
    int choice = 0;
    do
    {
        cout << "\033c";
        //  system("CLS");
	const int WIDTH = 80;
    cout << fixed << showpoint << setprecision(2);
	cout << setfill('*') << setw(WIDTH) << "*" << endl;
	cout << setfill(' ');
	cout << "*";
	cout << right << setw((WIDTH - 2) / 2) << "A6 ";
	cout << left << setw((WIDTH - 2) / 2) << " STRUCTS";
	cout << "*" << endl;
	cout << "*";
	cout << right << setw((WIDTH - 2) / 2) << " ";
	cout << left << setw((WIDTH - 2) / 2) << "";
	cout << left << "*" << endl;
	cout << left << setw(WIDTH / 2) << "*";
	cout << right << setw(WIDTH / 2) << "*" << endl;
	cout << left << setw(WIDTH - 50) << "*";
	cout << right << setw(WIDTH - 66) << "";
	cout << right << setw(WIDTH - 76);
	cout << right << setw(WIDTH - 60) << "";
	cout << right << setw(WIDTH - 76);
	cout << right << setw(WIDTH - 72) << "*" << endl;
	cout << left << setw(WIDTH / 2) << "*";
	cout << right << setw(WIDTH / 2) << "*" << endl;
	cout << left << setw(WIDTH - 30) << "*";
	cout << left << setw(WIDTH - 51) << "";
	cout << "*" << endl;
	cout << left << setw(WIDTH - 44) << "* <1>  Look Up a Player";
	cout << "";
	cout << left << setw(WIDTH - 42);
	cout << "*" << endl;
	cout << left << setw(WIDTH - 44) << "* <2>  Edit a Player";
	cout << "";
	cout << left << setw(WIDTH - 42);
	cout << "*" << endl;
	cout << left << setw(WIDTH - 44) << "* <3>  Print Team Roster";
	cout << "";
	cout << left << setw(WIDTH - 42);
	cout << "*" << endl;
	cout << left << setw(WIDTH - 44) << "* <4>  To Quit";
	cout << "";
	cout << left << setw(WIDTH - 42);
	cout << "*" << endl;
	cout << left << setw(WIDTH - 44) << "*  ";
	cout << "";
	cout << left << setw(WIDTH - 42);
	cout << "" << endl;
	cout << left << setw(WIDTH - 44) << "*  ";
	cout << "";
	cout << left << setw(WIDTH - 42);
	cout << "" << endl;
	cout << left << setw(WIDTH - 44) << "*  ";
	cout << "";
	cout << left << setw(WIDTH - 42);
	cout << "" << endl;
	cout << left << setw(WIDTH - 44) << "*  ";
	cout << "";
	cout << left << setw(WIDTH - 42);
	cout << "" << endl;
	cout << left << setw(WIDTH - 44) << "*  ";
	cout << right << setw(WIDTH - 36) << "*" << endl;
	cout << left << setw(WIDTH - 44) << "*  ";
	cout << right << setw(WIDTH - 36) << "*" << endl;
	cout << setfill('*') << setw(WIDTH) << "*" << endl;
	cout << "\t\tChoice<1-4>: ";
        cin >> choice;
        cin.clear();
        cin.ignore();

        switch (choice)
        {
        case 0:
            cout << "invalid" << endl;
            break;
        case 1:
            lookUpPlayer(footballTeam);
            break;
        case 2:
            editPlayer(outFile, footballTeam, SIZE);
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
    } while (choice != 4);
};

int main()
{
    ofstream outFile;
    ifstream inFile;

    const int SIZE = 10;
    playerType footballTeam[SIZE];
    readFile(footballTeam, inFile, SIZE);
    menu(footballTeam, SIZE, outFile);

    return 0;
}
    /*for (int i = 0; i < SIZE; i++)
    {
        cout << footballTeam[i].name << endl;
        cout << footballTeam[i].lastName << endl;
        cout << footballTeam[i].pos << endl;
        cout << footballTeam[i].touchDowns << endl;
        cout << footballTeam[i].catches << endl;
        cout << footballTeam[i].passingYards << endl;
        cout << footballTeam[i].recievingYards << endl;
        cout << footballTeam[i].rushingYards << endl;
    };*/

   // writeFile(outFile, footballTeam, SIZE);