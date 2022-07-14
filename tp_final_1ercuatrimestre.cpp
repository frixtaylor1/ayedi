#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX_SIZE = 50;

struct Guest
{
    string DNI;
    string name;
    string surname;
    char confirmation;
};
typedef Guest Guests[MAX_SIZE];
typedef struct 
{
    int counter;
    Guests guests; 
} GuestList;

void fileStatus(ifstream& file, string ERROR);
//Chek if the file is open and good
ifstream openFile(string fileNameDir);
void writeFileStatus(ofstream& file, string ERROR);
ofstream writeFile(string fileNameDir);
void saveList(GuestList& guestList);
void closeFile(ifstream& file);
GuestList getFileData(ifstream& file);
void removeGuest(GuestList& guestList);
void addGuest(GuestList& guestList, ostream& stream);
void changeConfirmation(GuestList& guestList);
void changeName(GuestList& guestList);
void changeSurname(GuestList& guestList);
void changeDNI(GuestList& guestList);
bool selectConfirmedGuest(char confirmation);
bool evaluationList(int count, int max);
void showList(GuestList guestList);
void showConfirmedGuest(GuestList& guestList);
int selectAOption();
void menu(GuestList& list);

int main()
{
    ifstream file = openFile("FESTIVAL.txt");
    GuestList list;
    list = getFileData(file);
    closeFile(file);
    menu(list);
    
    return EXIT_SUCCESS;
}
int selectAOption()
{
    int option;
    cout << "\tWellcome to the G.L.H"                   << endl;
    cout << "***************************************"   << endl;
    cout << "\t(1) Enter a new guest"                   << endl;
    cout << "\t(2) Remove a Guest"                      << endl;
    cout << "\t(3) Change confirmation"                 << endl;
    cout << "\t(4) Change name"                         << endl;
    cout << "\t(5) Change surname"                      << endl;
    cout << "\t(6) Change DNI"                          << endl;
    cout << "\t(7) Show list of guest"                  << endl;
    cout << "\t(8) Show confirmed guest"                << endl;
    cout << "\t(0) E X I T"                             << endl;
    cout << "***************************************"   << endl;
    cout << "Enter a option: ";
    cin >> option;
    return option;
}
void menu(GuestList& list)
{
    int option;
    do
    {
        option = selectAOption();
        switch (option)
        {
        case 1:
            addGuest(list, cout);
            break;
        case 2:
            removeGuest(list);
            break;
        case 3:
            changeConfirmation(list);
            break;
        case 4:
            changeName(list);
            break;
        case 5:
            changeSurname(list);
            break;
        case 6:
            changeDNI(list);
            break;
        case 7:
            showList(list);
            break;
        case 8:
            showConfirmedGuest(list);
            break;
        default:
            cerr << "UNKNOWN OPTION, try again!!";
            break;
        }
        saveList(list);
        
    } while (option != 0);
    
}
void fileStatus(ifstream& file, string ERROR)
{
    bool condition = (!(file.is_open()) ||!(file.good()));
    if (condition)
    {
        cerr << ERROR << std::endl;
        exit(EXIT_FAILURE);
    }
}
ifstream openFile(string fileNameDir)
{
    ifstream file;
    file.open(fileNameDir);
    fileStatus(file, "ERROR OPENIN FILE!!");
    return file;    
}
void writeFileStatus(ofstream& file, string ERROR)
{
    bool condition = (!(file.is_open())||!(file.good()));
    if (condition)
    {
        cerr << ERROR << endl;
        exit(EXIT_FAILURE);
    }
}
ofstream writeFile(string fileNameDir)
{
    ofstream file(fileNameDir);
    writeFileStatus(file, "ERROR OPENING WRITER FILE");
    return file;
}
void saveList(GuestList& guestList)
{
    ofstream file = writeFile("FESTIVAL.txt");
    int i = 0;
    while(i != guestList.counter)
    {
        file << guestList.guests[i].name << " "
             << guestList.guests[i].surname << " "
             << guestList.guests[i].DNI << " " 
             << guestList.guests[i].confirmation << endl;
        i++;
    }
    file.close();
}
void closeFile(ifstream& file)
{
    if(file.is_open()) file.close();
}
GuestList getFileData(ifstream& file)
{
    GuestList guestList;
    guestList.counter = 0;
    if(file.is_open())
    {
        while(!file.eof())
        {
            file >> guestList.guests[guestList.counter].name 
                 >> guestList.guests[guestList.counter].surname
                 >> guestList.guests[guestList.counter].DNI
                 >> guestList.guests[guestList.counter].confirmation;
            guestList.counter++;
        }
        guestList.counter--;
    }
    return guestList;
}
void showList(GuestList guestList)
{
    for (int idx = 0; idx < guestList.counter; idx++)
    {
        cout << setw(16) << "TICKET";
        cout << setw(16) << "NAME";
        cout << setw(16) << "SURNAME";
        cout << setw(16) << "DNI ";
        cout << setw(16) << "CONFIRMATION" << endl; 
        cout << setw(16) << idx;
        cout << setw(16) << guestList.guests[idx].name;    
        cout << setw(16) << guestList.guests[idx].surname; 
        cout << setw(16) << guestList.guests[idx].DNI; 
        cout << setw(16) << guestList.guests[idx].confirmation;
        cout << "\n\t---------------------------------------------------------------------------------\n";
    }
}
void removeGuest(GuestList& guestList)
{
    int pos;
    cout << "Enter the ticket to romove guest: ";
    cin >> pos;
    for (int idx = pos; idx < guestList.counter-1; idx++)
    {
        guestList.guests[idx] = guestList.guests[idx+1];
    }
}
bool evaluationList(int count, int max)
{
    return (count < max);
}
void addGuest(GuestList& guestList, ostream& stream)
{
    if(evaluationList(guestList.counter, MAX_SIZE))
    {
        stream << "Enter a name:.............. ";
        cin >> guestList.guests[guestList.counter].name;
        stream << "Enter a surname:........... ";
        cin >> guestList.guests[guestList.counter].surname;
        stream << "Enter the DNI:............. ";
        cin >> guestList.guests[guestList.counter].DNI;
        stream << "Enter the confirmaton[Y/n]: ";
        cin >> guestList.guests[guestList.counter].confirmation;
        guestList.counter++;
    }
    else
    {
        cout << "List reached maximum capacity!!" << endl;
    }
}
bool selectConfirmedGuest(char confirmation)
{
    return (confirmation == 'Y' || confirmation == 'y');
}
void showConfirmedGuest(GuestList& guestList)
{
    cout << "\n\tConfirmed Guest...\n" << endl;

    for (int idx = 0; idx < guestList.counter; idx++)
    {
        if(selectConfirmedGuest(guestList.guests[idx].confirmation))
        {  
            cout << setw(16) << "TICKET";
            cout << setw(16) << "NAME";
            cout << setw(16) << "SURNAME";
            cout << setw(16) << "DNI ";
            cout << setw(16) << "CONFIRMATION" << endl; 
            cout << setw(16) << idx;
            cout << setw(16) << guestList.guests[idx].name;    
            cout << setw(16) << guestList.guests[idx].surname; 
            cout << setw(16) << guestList.guests[idx].DNI; 
            cout << setw(16) << guestList.guests[idx].confirmation;
            cout << "\n\t---------------------------------------------------------------------------------\n";
        }
    }
    
}
void changeConfirmation(GuestList& guestList)
{
    int nbTicket;
    cout << "Enter the number of ticket to change the data: ";
    cin >> nbTicket;
    cout << "Change confirmation[Y/N]: ";
    cin >> guestList.guests[nbTicket].confirmation;
}
void changeName(GuestList& guestList)
{
    int nbTicket;
    cout << "Enter the ticket to change the name: ";
    cin >> nbTicket;
    cout << "Write a new name: ";
    cin >> guestList.guests[nbTicket].name;
}
void changeSurname(GuestList& guestList)
{
    int nbTicket;
    cout << "Enter the numer of ticket to change the surname: ";
    cin >> nbTicket;
    cout << "Write a new surname: ";
    cin >> guestList.guests[nbTicket].surname;
}
void changeDNI(GuestList& guestList)
{
    int nbTicket;
    cout << "Enter the number of ticket to change the DNI: ";
    cin >> nbTicket;
    cout << "Write a new DNI: ";
    cin >> guestList.guests[nbTicket].DNI;

}
