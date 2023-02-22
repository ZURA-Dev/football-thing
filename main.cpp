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
                getline(inFile >> ws, footballTeam[i].lastName, ',') >> footballTeam[i].name >> footballTeam[i].pos >> footballTeam[i].touchDowns >> footballTeam[i].catches >> footballTeam[i].passingYards >> footballTeam[i].recievingYards >> footballTeam[i].rushingYards;
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
            outFile << footballTeam[i].lastName << ", " << footballTeam[i].name << " " << footballTeam[i].pos << " " << footballTeam[i].touchDowns << " " << footballTeam[i].catches << " " << footballTeam[i].passingYards << " " << footballTeam[i].recievingYards << " " << footballTeam[i].rushingYards << endl;
        }
    }
    else
    {
        cout << "invalid file";
    }

    outFile.close();
};

int lookUpPlayer(playerType footballTeam[], const int SIZE)
{
    bool found;
    int pos = 0;
    do {
    string temp_name;
    string temp_lastName;
    pos = 0;
    found = false;
    int choice = 0;
    cout << "\033c";
    cout << "Enter first/last name of player to look up" << endl;
    cout << "first: ";
    getline(cin, temp_name);
    cout << "last: ";
    getline(cin, temp_lastName);
    
    for (int i = 0; i < SIZE; i++)
    {
        if (footballTeam[i].name == temp_name && footballTeam[i].lastName == temp_lastName)
        {
            pos = i;
            cout << "found! " << endl;
            found = true;
        }
    }
    cout << "not found" << endl;
    cin >> choice;
    if (choice == 0) {
        return 0;
    }
    system("pause");
    }while(found == false);
    if (found == false) {
        cout << "not found // returning" << endl;
    }

    if (found == true) {
        return pos;
    } else {
        return -1;
    }
}
void editPlayer(ofstream &outFile, playerType footballTeam[], const int SIZE)
{
 
    int pos = 0;
    int choice = 0;
    
        pos = lookUpPlayer(footballTeam, SIZE);
        cout << pos << endl;
        do
        {
            cout << "1. Edit Name" << setw(60) << footballTeam[pos].lastName << "," <<footballTeam[pos].name << endl;
            cout << "2. Edit Position" << endl;
            cout << "3. Edit Number of Touch Downs" << endl;
            cout << "4. Edit Number of Catches" << endl;
            cout << "5. Edit Number of Passing Yards" << endl;
            cout << "6. Edit Number of Recieving Yards" << endl;
            cout << "7. Edit Number of Rushing Yards" << endl;
            cin >> choice;
            cin.clear();
        cin.ignore();

            switch (choice)
            {
            case 0:
                break;
            case 1:
                cout << "Edit First Name: " << endl;
                getline(cin, footballTeam[pos].name);
                cout << "Edit last Name" << endl;
                getline(cin, footballTeam[pos].lastName);
                break;
            case 2:
                cout << "Edit position: " << endl;
                getline(cin, footballTeam[pos].pos);
                break;
            case 3:
                cout << "Edit Number of Touch Downs: " << endl;

                getline(cin, footballTeam[pos].touchDowns);
                break;
            case 4:
                cout << "Edit Catches: " << endl;

                getline(cin, footballTeam[pos].catches);
                break;
            case 5:
                cout << "Edit Passing Yards: " << endl;

                getline(cin, footballTeam[pos].passingYards);
                break;
            case 6:
                cout << "Edit Receiving Yards: " << endl;

                getline(cin, footballTeam[pos].recievingYards);
                break;
            case 7:
                cout << "Edit Rushing Yards: " << endl;

                getline(cin, footballTeam[pos].rushingYards);
                break;
            default:
                cout << "\t\tInvalid Input. Press enter to continue..." << endl;
                cin.ignore();
                break;
            }
        } while (choice != 8);
    }
void printTeamRoster(playerType footballTeam[])
{
    cout << "\033c";
};
void menu(playerType footballTeam[], const int SIZE, ofstream &outFile, bool &ifRunned)
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
            lookUpPlayer(footballTeam, SIZE);
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
    // menu(footballTeam, SIZE, outFile);
    lookUpPlayer(footballTeam, SIZE);
    //editPlayer(outFile, footballTeam, SIZE);

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