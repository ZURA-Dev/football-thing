
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
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
            outFile << footballTeam[i].lastName << ", " << endl;
            outFile << footballTeam[i].name << " " << endl;
            outFile << footballTeam[i].pos << " " << endl;
            outFile << footballTeam[i].touchDowns << " " << endl;
            outFile << footballTeam[i].catches << " " << endl;
            outFile << footballTeam[i].passingYards << " " << endl;
            outFile << footballTeam[i].recievingYards << " " << endl;
            outFile << footballTeam[i].rushingYards << endl;
        }
    }
    else
    {
        cout << "invalid file";
    }

    outFile.close();
};
string toLowerString(string &word)
{
    for (size_t i = 0; i < word.length(); i++)
    {
        word[i] = tolower(word[i]);
    }
    return word;
}
int lookUpPlayer(playerType footballTeam[], const int SIZE, bool &ifExit)
{
    bool found;
    int choice;
    int pos;
    playerType tempFootball[SIZE];
    do
    {
        string temp_name;
        string temp_lastName;
        found = false;
        cout << "\033c";
        cout << "Enter first/last name of player to look up" << endl;
        cout << "first: ";
        getline(cin, temp_name);
        cin.clear();
        cout << "last: ";
        getline(cin, temp_lastName);
        cin.clear();
        

        for (int i = 0; i < SIZE; i++)
        {
            temp_name = toLowerString(temp_name);
            temp_lastName = toLowerString(temp_lastName);
            tempFootball[i].name = footballTeam[i].name;
            tempFootball[i].lastName = footballTeam[i].lastName;
            tempFootball[i].name = toLowerString(footballTeam[i].name);
            tempFootball[i].lastName = toLowerString(footballTeam[i].lastName);
        }

        for (int i = 0; i < SIZE; i++)
        {
            if (tempFootball[i].name == temp_name && tempFootball[i].lastName == temp_lastName)
            {
                pos = i;
                found = true;
            }
        }
        if (found == false)
        {
            cout << "\033c";
            cout << "not found" << endl;
            cout << "1. Retry" << endl;
            cout << "2. Quit to menu: " << endl;
            cout << "Enter:" << endl;
            cin >> choice;
            cin.clear();
            cin.ignore(25, '\n');
            switch (choice)
            {
            case 0:
                cout << "error" << endl;
            case 1:
                break;
            case 2:
                if (choice == 2)
                {
                    ifExit = true;
                    return 0;
                }
                break;
            default:
                cout << "error";
            }
        }

    } while (found == false);

    if (found == true)
    {
        
        cout << "found! " << endl;
        system("pause");
        cout << "\033c";
        return pos;
    }
    else
    {
        return -1;
    }
}
void editPlayer(ofstream &outFile, playerType footballTeam[], const int SIZE, bool ifExit)
{
    cout << "\033c";
    int pos = 0;
    int choice = 0;
    ifExit = false;
    pos = lookUpPlayer(footballTeam, SIZE, ifExit);
    if (ifExit == true)
    {
        return;
    }
    cout << pos << endl;
    do
    {
       const int WIDTH = 80;
	
	cout << fixed << showpoint << setprecision(2);
	cout << setfill('*') << setw(WIDTH) << "*" << endl;
	cout << setfill(' ');
	cout << "*";
	cout << right << setw((WIDTH - 2) / 2) << "A6 STRUCT ";
	cout << left << setw((WIDTH - 2) / 2) << " EDIT PLAYER";
	cout << "*" << endl;
	cout << "*";
	cout << right << setw((WIDTH - 2) / 2) << "";
	cout << left << setw((WIDTH - 2) / 2) << "";
	cout << left << "*" << endl;
	cout << left << setw(WIDTH / 2) << "*";
	cout << right << setw(WIDTH / 2) << "*" << endl;
	cout << left << setw(WIDTH - 50) << "*";
	cout << right << setw(WIDTH - 66) << "";
	cout << right << setw(WIDTH - 76);
	cout << right << setw(WIDTH - 60);
	cout << right << setw(WIDTH - 76);
	cout << right << setw(WIDTH - 72) << "*" << endl;
	cout << left << setw(WIDTH / 2) << "*";
	cout << right << setw(WIDTH / 2) << "*" << endl;
	cout << left << setw(WIDTH - 30) << "*";
	cout << left << setw(WIDTH - 40) << "--PENDING VALUES";
	cout << "*" << endl;
	cout << left << setw(WIDTH - 42) << "* <1>  Edit Name";
	cout << ">  --";
	cout << left << setw(WIDTH - 40) << setw(5) << footballTeam[pos].lastName << ", " << footballTeam[pos].name;
	cout << "" << endl;
	cout << left << setw(WIDTH - 42) << "* <2>  Edit Position";
	cout << ">  --";
	cout << left << setw(WIDTH - 40) << footballTeam[pos].pos;
	cout << "*" << endl;
	cout << left << setw(WIDTH - 42) << "* <3>  Edit Number of Touch Downs";
	cout << ">  --";
	cout << left << setw(WIDTH - 40) << footballTeam[pos].touchDowns;
	cout << "*" << endl;
	cout << left << setw(WIDTH - 42) << "* <4>  Edit Number of Catches";
	cout << ">  --";
	cout << left << setw(WIDTH - 40) << footballTeam[pos].catches;
	cout << "*" << endl;
	cout << left << setw(WIDTH - 42) << "* <5>  Edit Number of Passing Yards";
	cout << ">  --";
	cout << left << setw(WIDTH - 40) << footballTeam[pos].passingYards;
	cout << "*" << endl;
	cout << left << setw(WIDTH - 42) << "* <6>  Edit Number of Receiving Yards";
	cout << ">  --";
	cout << left << setw(WIDTH - 40) << footballTeam[pos].recievingYards;
	cout << "*" << endl;
	cout << left << setw(WIDTH - 42) << "* <7>  Edit Number of Rushing Yards";
	cout << ">  --";
	cout << left << setw(WIDTH - 40) << footballTeam[pos].rushingYards;
	cout << "*" << endl;
	cout << left << setw(WIDTH - 42) << "* <8>  Return to Main Menu";
	cout << "";
	cout << left << setw(WIDTH - 40);
	cout << "*" << endl;
	cout << left << setw(WIDTH - 42) << "";
	cout << right << setw(WIDTH - 36) << "*" << endl;
	cout << left << setw(WIDTH - 44) << "";
	cout << right << setw(WIDTH - 36) << "*" << endl;
	cout << setfill('*') << setw(WIDTH) << "*" << endl;
	cout << "\t\tChoice<0-8>: ";
        cin >> choice;
        cin.clear();
        cin.ignore();

        switch (choice)
        {
        case 0:
            break;
        case 1:
            cout << "\033c";
            cout << "Edit First Name: " << endl;
            getline(cin, footballTeam[pos].name);
            cout << "Edit last Name" << endl;
            getline(cin, footballTeam[pos].lastName);
            break;
        case 2:
            cout << "\033c";
            cout << "Edit position: " << endl;
            getline(cin, footballTeam[pos].pos);
            break;
        case 3:
            cout << "\033c";
            cout << "Edit Number of Touch Downs: " << endl;

            getline(cin, footballTeam[pos].touchDowns);
            break;
        case 4:
            cout << "\033c";
            cout << "Edit Catches: " << endl;

            getline(cin, footballTeam[pos].catches);
            break;
        case 5:
            cout << "\033c";
            cout << "Edit Passing Yards: " << endl;

            getline(cin, footballTeam[pos].passingYards);
            break;
        case 6:
            cout << "\033c";
            cout << "Edit Receiving Yards: " << endl;

            getline(cin, footballTeam[pos].recievingYards);
            break;
        case 7:
            cout << "\033c";
            cout << "Edit Rushing Yards: " << endl;

            getline(cin, footballTeam[pos].rushingYards);
            break;
        case 8:
            return;
            break;
        default:
            cout << "\033c";
            cout << "\t\tInvalid Input. Press enter to continue..." << endl;
            break;
        }
    } while (choice != 8);
}
void printTeamRoster(playerType footballTeam[], const int SIZE)
{
    cout << "\033c";
    int W = 20;
    cout << setfill(' ');
    cout << left << "Name" << setw(W + 7) << "Pos" << setw(W) << "TDs" << setw(W) << "Catches" << setw(W) << "Pass Yds" << setw(W) << "Recv Yds" << setw(W) << "Rush YDS" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << "---------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << left << setw(10) << footballTeam[i].lastName << ", " << left << setw(W) << footballTeam[i].name << left << setw(W) << footballTeam[i].pos << left << setw(W) << footballTeam[i].catches << left << setw(W) << footballTeam[i].passingYards << left << setw(W) << footballTeam[i].recievingYards << left << setw(W) << footballTeam[i].rushingYards << endl;
    }
    cout << endl;
    system("pause");
};
void menu(playerType footballTeam[], const int SIZE, ofstream &outFile, bool ifExit)
{
    cout << "\033c";
    int choice = 0;
    do
    {
        cout << "\033c";
        cout << "\033c";
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
            lookUpPlayer(footballTeam, SIZE, ifExit);
            break;
        case 2:
            cout << "\033c";
            editPlayer(outFile, footballTeam, SIZE, ifExit);
            break;
        case 3:
            cout << "\033c";
            printTeamRoster(footballTeam, SIZE);
            break;
        case 4:
            int save;
            do
            {
                cout << "\033c";
                cout << "Do you wish to save before exiting?" << endl;
                cout << "1. Return back to menu" << endl;
                cout << "2. Save to file" << endl;
                cout << "3. Exit" << endl;
                cout << "Enter: ";
                int save;
                cin >> save;
                cin.clear();
                cin.ignore();
                switch (save)
                {
                case 1:
                    cout << "\033c";
                    menu(footballTeam, SIZE, outFile, ifExit);
                case 2:
                     cout << "\033c";
                    writeFile(outFile, footballTeam, SIZE);
                    return;
                case 3:
                    return;
                default:
                    cout << "invalid" << endl;
                };
            } while (save != 3);
            break;
        default:
            cout << "invalid" << endl;
        };
        cout << "\033c";
    } while (choice != 4);
};

int main()
{
    ofstream outFile;
    ifstream inFile;
    const int SIZE = 10;
    bool ifExit = false;
    playerType footballTeam[SIZE];
    readFile(footballTeam, inFile, SIZE);
    menu(footballTeam,SIZE, outFile, ifExit);
    return 0;
}
