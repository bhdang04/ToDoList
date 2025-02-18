#include <stdio.h>
#include <string.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <termios.h>

using namespace std;

void view(int entry, string toDoArr[]);
void manage(int entry, string toDoArr[]);
int add(int entry, string toDoArr[]);
int remove(int entry, string toDoArr[]);
void exit();

int main() {
    int choices = 0;
    int entries = 0;
    string toDoArr[100];

    do { 
        cout << "<-------- Choose Options (1-5) -------->" << endl;
        cout << "1. Add to List\n" 
            << "2. Remove to List\n"
            << "3. Manage List\n"
            << "4. View List\n"
            << "5. Quit Application\n";
        cout << "Pick a number to select that option: ";
        cin >> choices;

        system("clear");
        switch (choices) {
            case 1:
                entries = add(entries, toDoArr);
                cout << "Added Successfully" << endl;
                exit();
                break;
            case 2:
                entries = remove(entries, toDoArr);
                cout << "Deleted Successfully" << endl;
                exit();
                break;
            case 3:
                manage(entries, toDoArr);
                cout << "Swapped Successfully" << endl;
                exit();
                break;
            case 4:
                view(entries, toDoArr);
                exit();
                break;
            case 5:
                cout << "Successfully Closed\n";
                break;
            default: 
                cerr << "\nInvalid Option";
                break;               
        }
        system("clear");
    } while (choices != 5);

    return 0;
}

void view(int entry, string toDoArr[]) {
    cout << "---------- TO DO LIST -------------\n";
    for (int i = 0; i < entry; i++) {
        cout << i + 1 << ". " << toDoArr[i] << endl;
    }
}

void exit() {
    cout << "Press Any Key To Exit..." << endl;
    
    // Disable buffering and echo
    termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt); // Get current terminal settings
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new settings

    // Read a single character
    char ch;
    read(STDIN_FILENO, &ch, 1);

    // Restore original terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

int remove(int entry, string toDoArr[]) {
    int delEntry = 0;

    view(entry, toDoArr);
    
    cout << "Select the number to remove from your To-Do List (0 = clear all): ";
    cin.ignore();
    cin >> delEntry;
    delEntry = delEntry - 1;

    if (delEntry >= entry) {
        cout << "\nInvalid Entry\n";
        exit();
    } else {
        toDoArr[delEntry] = "";

        for (int i = delEntry; i < entry - 1; i++) {
            delEntry++;
            toDoArr[i] = toDoArr[delEntry];
        }
        entry--;
    }

    return entry;
}

int add(int entry, string toDoArr[]) {
    string input = "";

    cout << "Add an item onto your To-Do List: ";
    cin.ignore();
    getline(cin, input);
    
    toDoArr[entry] = input;
    entry++;

    return entry;
}

void manage(int entry, string toDoArr[]) {
    int selected = 0;
    int switched = 0;
    string holder = "";

    view(entry, toDoArr);

    cout << "Select 1st number to switch with the 2nd number inputted\n";
    cout << "Selecting: ";
    cin.ignore();
    cin >> selected;
    cout << "Swap with: ";
    cin.ignore();
    cin >> switched;

    selected--;
    switched--;

    if (switched >= entry || selected >= entry) {
        cout << "Invalid Entry\n";
        exit();
    } else {
        holder = toDoArr[selected];
        toDoArr[selected] = toDoArr[switched];
        toDoArr[switched] = holder;
    }
}