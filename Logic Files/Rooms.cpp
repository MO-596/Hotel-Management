#include "Rooms.h"
template<typename NODETYPE>
Rooms<NODETYPE>::Rooms()
{
	//empty for now
}

//////////////////////////////

template<typename NODETYPE>
Rooms<NODETYPE>::Rooms(const Rooms& copyList)
{
        //empty for now
}

//////////////////////////////

template<typename NODETYPE>
void Rooms<NODETYPE>::addRoom(const NODETYPE& Room_Number, const NODETYPE& Rate, const NODETYPE& Status)
{
      this->insertNode(Room_Number, Rate, Status);
}

//////////////////////////////

template<typename NODETYPE>
bool Rooms<NODETYPE>::searchRoom_by_Number(const NODETYPE& Room_Number)
{
       return this->searchNode_by_Room_Number(Room_Number);
}

//////////////////////////////

template<typename NODETYPE>
bool Rooms<NODETYPE>::searchRoom_by_Status(const NODETYPE& Status)
{
       return this->searchNode_by_Status(Status);
}

//////////////////////////////

template<typename NODETYPE>
void Rooms<NODETYPE>::displayRooms() const
{
	this->display();
}

//////////////////////////////

template<typename NODETYPE>
bool Rooms<NODETYPE>::SaveToFile() const
{
	return this->save("RoomsHistory.txt");
}

//////////////////////////////

template<typename NODETYPE>
bool Rooms<NODETYPE>::LoadFromFile()
{
	return this->load("RoomsHistory.txt");
}

//////////////////////////////

template<typename NODETYPE>
bool Rooms<NODETYPE>::isFull(const NODETYPE& input)
{
	return this->List<NODETYPE>::isFull(input);
}

//////////////////////////////

template<typename NODETYPE>
bool Rooms<NODETYPE>::isEmpty() const
{
	return this->List<NODETYPE>::isEmpty();
}

/////////////////////////////////////////////////////////////////////

template<typename NODETYPE>
int Rooms<NODETYPE>::roomInput(int& input)
{
  do
  {	// Validates the input
        while((input < 1) || (input > 300) || cin.fail())
        {
          cin.clear();//clears the last input to avoid it repeating
          cin.ignore(numeric_limits <streamsize> ::max(), '\n');//ignores anything that isnt a number
          cout << "Input needs to be an integer, Try again" << endl;
          cin >> input;
	}
	//Checks if the room number is already in the list
	if(isFull(input))
	{
	  cout << "Room Number is already occupied. Please enter a different number" << endl;
          cin >> input;
	}
  }while(isFull(input)); // Repeats until false
  return input;
}

/////////////////////////////////////////////////////////////////////

template<typename NODETYPE>
char Rooms<NODETYPE>::charInput(char& input)
{
	// Validates the input
        while((input != 'V') && (input != 'O'))
        {
                cin.clear();//clears the last input to avoid it repeating
                cin.ignore(numeric_limits <streamsize> ::max(), '\n');//ignores anything that isnt a number
                cout << "Input needs to be a character (V or N), Try again" << endl;
                cin >> input;
        }
 return input;
}

/////////////////////////////////////////////////////////////////////

template<typename NODETYPE>
int Rooms<NODETYPE>::rateInput(int& rate)
{
	// Validates the input
        while((rate < 1) || (rate > 300) || cin.fail())
        {
                cin.clear();//clears the last input to avoid it repeating
                cin.ignore(numeric_limits <streamsize> ::max(), '\n');//ignores anything that isnt a number
                cout << "Input needs to be in the form of 0, Try again" << endl;
                cin >> rate;
        }
  return rate;
}

/////////////////////////////////////////////////////////////////////

template<typename NODETYPE>
ostream &operator<< (ostream &output,const Rooms<NODETYPE> &Hotel_List_Output)
{
  if(Hotel_List_Output.isEmpty())
  {
    output << "List is currently empty" << endl;
  }
  else
  {
    Hotel_List_Output.displayRooms();
  }
 return output;
}

/////////////////////////////////////////////////////////////////////

template<typename NODETYPE>
istream &operator>> (istream &input, Rooms<NODETYPE> &Hotel_List_Input)
{
        NODETYPE Room_num, rate;
        char status;

        cout << "Please enter room number: " << endl;
        input >> Room_num;
        Room_num = Hotel_List_Input.roomInput(Room_num);

        cout << "Please enter room rate: " << endl;
        input >> rate;
        rate = Hotel_List_Input.rateInput(rate);

        cout << "Is the room vacant? (V/O): " << endl;
        input >> status;
        status = Hotel_List_Input.charInput(status);

    Hotel_List_Input.addRoom(Room_num, rate, status);
  return input;
}

/////////////////////////////////////////////////////////////////////

