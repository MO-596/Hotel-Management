#include "Rooms.cpp"
#include "LinkList.cpp"
//displays
void WelcomeFunction();
void MenuDisplay();
void searchDisplay();
void searchSection(Rooms<int>*);

//user input validation
int validInput(int&);
int searchInput(int&);
int valueInput(int&);
char charInput(char&);

// user processes
bool process(int, Rooms<int>*);
bool searchProcess(int, Rooms<int>*);
///////////////////////////////////////////////////////////////

int main()
{
        bool Repeat = true;
        int choice = 0;
        Rooms<int> *Hotel_List = new Rooms<int>();

        WelcomeFunction();
        do
        {
                MenuDisplay();
                cout << "Enter your choice: " << endl;
                cin >> choice;
                choice = validInput(choice);
                Repeat = process(choice, Hotel_List);
        }while(Repeat);
}

///////////////////////////////////////////////////////////////

void WelcomeFunction()
{
        cout << "Welcome to the BatKnights Hotel Management App" << endl;
}

///////////////////////////////////////////////////////////////

void MenuDisplay()
{
        cout << "Here's the Main Menu, please choose one of the following: " << endl;
        cout << "1. Add a new room" << endl;
        cout << "2. Search for a room" << endl;
        cout << "3. Display all rooms" << endl;
        cout << "4. Save room info to a file" << endl;
        cout << "5. Load room info from a file" << endl;
        cout << "6. Exit" << endl;
}

///////////////////////////////////////////////////////////////

void searchDisplay()
{
        cout << "Search room by one of the following options: " << endl;
        cout << "1. Search by room number" << endl;
        cout << "2. Search by room status" << endl;
	cout << "3. Back to main menu" << endl;
}

///////////////////////////////////////////////////////////////

int validInput(int& choice)
{
        while((choice < 1) || (choice > 6) || cin.fail())
        {
                cin.clear();//clears the last input to avoid it repeating
                cin.ignore(numeric_limits <streamsize> ::max(), '\n');//ignores anything that isnt a number
                cout << "Invalid Input, Try again" << endl;
                cin >> choice;
        }
  return choice;
}

///////////////////////////////////////////////////////////////

bool process(int choice, Rooms<int> *Hotel_List)
{
    bool Repeat = true;

    enum Choices
    {
      ADD = 1, SEARCH, DISPLAY, SAVE, LOAD, EXIT
    };

    switch(choice)
    {
       case ADD:
         cout << "You have chosen to add a room ..." << endl;
	 cin >> *Hotel_List;
         cout <<"\n";
	 break;

       case SEARCH:
         cout << "You have chosen to search for a room ..." << endl;
	 searchSection(Hotel_List);
	 cout <<"\n";
	 break;

       case DISPLAY:
         cout << "You have chosen to display all rooms ..." << endl;
	 cout << *Hotel_List;
         cout <<"\n";
         break;

       case SAVE:
         cout << "You have chosen to save room info to a file ..." << endl;
	 Hotel_List->SaveToFile();
         cout <<"\n";
         break;

       case LOAD:
         cout << "You have chosen to load room info from a file ..." << endl;
	 Hotel_List->LoadFromFile();
         cout <<"\n";
         break;

        case EXIT:
          cout << "Exiting, Thank you for you for using the app!" << endl;
          cout << "\n------------------------\n";
          Repeat = false;

    }
  return Repeat;
}

/////////////////////////////////////////////////////////////////////////

void searchSection(Rooms<int> *Hotel_List)
{
        bool Repeat = true;
        int choice = 0;

        do
        {
                searchDisplay();
                cout << "Enter your choice: " << endl;
                cin >> choice;
                choice = searchInput(choice);
                Repeat = searchProcess(choice, Hotel_List);
        }while(Repeat);
}

/////////////////////////////////////////////////////////////////////////

bool searchProcess(int choice, Rooms<int> *Hotel_List)
{
    int Room_Num;
    char Stat;
    bool Repeat = true;
    enum Choices
    {
      BY_ROOM = 1, BY_STATUS, EXIT
    };

    switch(choice)
    {
       case BY_ROOM:
         cout << "Searching by room number ..." << endl;
	 cout << "Please enter room number: ";
	 cin >> Room_Num;

	 Room_Num = valueInput(Room_Num);

	 Hotel_List->searchRoom_by_Number(Room_Num);
         cout <<"\n";
         break;

       case BY_STATUS:
         cout << "Searching by room status ..." << endl;
         cout << "Please enter room status (V/O): ";
	 cin >> Stat;

	 Stat = charInput(Stat);

	 Hotel_List->searchRoom_by_Status(Stat);
         cout <<"\n";
	 break;

       case EXIT:
         cout << "Exiting, Thank you for you for using the app!" << endl;
         cout << "\n------------------------\n";
         Repeat = false;

    }
  return Repeat;
}

/////////////////////////////////////////////////////////////////////////

int valueInput(int& choice)
{
        while((choice < 1) || (choice > 300) || cin.fail())
        {
                cin.clear();//clears the last input to avoid it repeating
                cin.ignore(numeric_limits <streamsize> ::max(), '\n');//ignores anything that isnt a number
                cout << "Invalid Input, Try again" << endl;
                cin >> choice;
        }
  return choice;
}

/////////////////////////////////////////////////////////////////////////

int searchInput(int& choice){
	while((choice < 1) || (choice > 4) || cin.fail())
        {
                cin.clear();//clears the last input to avoid it repeating
                cin.ignore(numeric_limits <streamsize> ::max(), '\n');//ignores anything that isnt a number
                cout << "Invalid Input, Try again" << endl;
                cin >> choice;
        }
  return choice;
}

/////////////////////////////////////////////////////////////////////////
char charInput(char& input)
{
        while((input != 'V') && (input != 'O'))
        {
                cin.clear();//clears the last input to avoid it repeating
                cin.ignore(numeric_limits <streamsize> ::max(), '\n');//ignores anything that isnt a number
                cout << "Input needs to be a character (V or N), Try again" << endl;
                cin >> input;
        }
 return input;
}
