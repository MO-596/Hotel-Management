#include "LinkList.h"
template<typename NODETYPE>
List<NODETYPE>::List() : headPtr(nullptr)
{
 // empty constructor
}

//////////////////////////////
template<typename NODETYPE>
List<NODETYPE>::List(const List& copyList) : headPtr(nullptr)
{
  // Pointer to traverse the list
  Node<NODETYPE>* currPtr = copyList.headPtr;
  // Check if the original list is empty
  if(copyList.headPtr == nullptr)
  {
    headPtr = nullptr; // The new list is empty
  }
  else
  {
    // Copies the data of the first node
    insertNode(currPtr->getRoomNumber(), currPtr->getRate(), currPtr->getStatus());

    // Travesres the list and then copies it
    while(currPtr->nextPtr != nullptr)
    {
      currPtr = currPtr->nextPtr;
      insertNode(currPtr->getRoomNumber(), currPtr->getRate(), currPtr->getStatus());
    }
  }
}

////////////////////////////////
template<typename NODETYPE>
List<NODETYPE>::~List()
{
  cout << "Destorying All Nodes ...\n" << endl;
  Node<NODETYPE>* newPtr = headPtr, *temPtr;
  while(newPtr != nullptr)
  {
    temPtr = newPtr;
    newPtr = newPtr -> nextPtr;
    delete temPtr;
  }
}

////////////////////////////////////
template<typename NODETYPE>
void List<NODETYPE>::insertNode(const NODETYPE& Room_Number, const NODETYPE& Rate, const NODETYPE& Status)
{
  // Create a new node with user inputs
  Node<NODETYPE>* newPtr = getNewNode(Room_Number, Rate, Status);

  // Checks if the list is empty
  if(isEmpty())
  {
    headPtr = newPtr; // New node becomes the new header pointer
  }
  else
  {
    //inserts the new node at the back
    Node<NODETYPE>* currPtr = headPtr;
    while(currPtr->nextPtr != nullptr)
    {
        currPtr = currPtr->nextPtr; // Now it traverses to the end of the list
    }
    // Insert the new node at the end
    currPtr->nextPtr = newPtr;
  }
 cout << "Room has been added in the list" << endl;
}

//////////////////////////////////

template<typename NODETYPE>
bool List<NODETYPE>::searchNode_by_Room_Number(const NODETYPE& Room_Number)
{
  // Checks if the list is empty
  if(isEmpty())
  {
    cout << "List is empty. Can not start search." << endl;
    return false;
  }
  else
  {
    // If the list is not empty, create a new pointer then start traversing list
    Node<NODETYPE>* currPtr = headPtr;
    while(currPtr && currPtr->getRoomNumber() != Room_Number)
    {
        currPtr = currPtr->nextPtr;
    }

    // Loops to check if matching room number is found
    if(currPtr && currPtr->getRoomNumber() == Room_Number)
    {
        cout << "Room Found: " << endl;
	cout << "Number:" << Room_Number <<endl;
	cout << "Rate: $" << currPtr->getRate() << endl;
        cout << "Status: " << currPtr->getStatus() << endl;
        return true;
    }
    else
    {
        cout << "Room Number could not be found" << endl;
        return false;
    }
  }

}

//////////////////////////////////

template<typename NODETYPE>
bool List<NODETYPE>::searchNode_by_Status(const NODETYPE& Status)
{
  // Checks if the list is empty
  if(isEmpty())
  {
    cout << "List is empty. Can not start search." << endl;
    return false;
  }
  else
  {
    // If the list is not empty, create a new pointer then start traversing list
    Node<NODETYPE>* currPtr = headPtr;
    while(currPtr && currPtr->getStatus() != Status)
    {
        currPtr = currPtr->nextPtr;
    }

    // Loops to check if matching status is found
    if(currPtr && currPtr->getStatus() == Status)
    {
        cout << "Room Found: " << endl;
        cout << "Number:" << currPtr->getRoomNumber() <<endl;
        cout << "Rate: $" << currPtr->getRate() << endl;
        cout << "Status: " << currPtr->getStatus() << endl;
        return true;
    }
    else
    {
        cout << "Room Number could not be found" << endl;
        return false;
    }
  }

}
/////////////////////////////////////////////////////////////////////

template<typename NODETYPE>
bool List<NODETYPE>::display() const
{
 // Checks if the list is empty
 if(isEmpty())
  {
    cout << "List is currently empty" << endl;
    return false;
  }
  else
  {
    // If the list is not empty, traverse through the list then displays content
    Node<NODETYPE>* currPtr = headPtr;
    cout << "Room List:" << endl;
    cout << "Number" << setw(10) << "Rate" << setw(10) << "Status" << endl;

    // Traverses the list and displays room details
    while(currPtr != nullptr)
    {
      cout << "<---------------------------------->" << endl;
      cout << currPtr->getRoomNumber() << setw(12) << currPtr->getRate()
		<< setw(12) << currPtr->getStatus() << endl;
      currPtr = currPtr->nextPtr;
    }
    return true;
  }
}

//////////////////////////////////////////////////////////////////////

template<typename NODETYPE>
bool List<NODETYPE>::save(const string& filename) const
{
        fstream inputFile(filename,ios::out | ios::binary);
        if(inputFile.is_open())
        {
	  unordered_set<NODETYPE> uniqueRoomNumbers;  // To track room numbers and prevent duplicates,
						      // found it on cpp website
          Node<NODETYPE>* currPtr = headPtr;
          while(currPtr != nullptr)
          {

            // Stores get Function values here
            NODETYPE roomNumber = currPtr->getRoomNumber();
            NODETYPE rate = currPtr->getRate();
            NODETYPE status = currPtr->getStatus();

	    // This checking is to check if the info is in the file
	    if(uniqueRoomNumbers.find(roomNumber) == uniqueRoomNumbers.end())
	    {
                // Adds the room number to the set to prevent duplicates from being saved
                uniqueRoomNumbers.insert(roomNumber);

		// Writes the rooms number to the file
		inputFile.write(reinterpret_cast<const char*>(&roomNumber), sizeof(roomNumber));

		// Writes the rooms rate to the file
		inputFile.write(reinterpret_cast<const char*>(&rate), sizeof(rate));

 		// Writes the rooms status to the file
		inputFile.write(reinterpret_cast<const char*>(&status), sizeof(status));
	    }
	    else
	    {
		cout << "Duplicate room found, skipping insertion" << endl;
	    }

           currPtr = currPtr->nextPtr;
          }
          inputFile.close();
          cout << "Rooms saved to file" << endl;
          return true;
        }
        else
        {
          cerr << "File could not be opened" << endl;
	  return false;
        }
}

//////////////////////////////////////////////////////////////////////

template<typename NODETYPE>
bool List<NODETYPE>::load(const string& filename)
{
        fstream inputFile(filename,ios::in | ios::binary);
        if(inputFile.is_open())
        {
	  // Variables to store the room details read from the file
	  NODETYPE roomNumber, rate, status;
        // Reads the data in a loop until the end of the file is reached
        while (inputFile.read(reinterpret_cast<char*>(&roomNumber), sizeof(roomNumber)))
        {
            // Reads the rate after the room number
            inputFile.read(reinterpret_cast<char*>(&rate), sizeof(rate));

            // Reads the status after the room number
            inputFile.read(reinterpret_cast<char*>(&status), sizeof(status));

            // Checks if a room with this roomNumber already exists in the list
            if (!searchNode_by_Room_Number(roomNumber))
            {
                // Insert the loaded room data into the linked list only if it's unique
                insertNode(roomNumber, rate, status);
            }
            else
            {
                cout << "Duplicate room found with Room Number: " << roomNumber << ", skipping insertion." << endl;
            }
        }

        // Close the file after reading
          inputFile.close();

          cout << "Rooms loaded from file" << endl;
          return true;
        }
        else
        {
          cerr << "File could not be opened" << endl;
	  return false;
        }
}

//////////////////////////////////////////////////////////////////////

template<typename NODETYPE>
bool List<NODETYPE>::isEmpty() const
{
        return headPtr == nullptr;
}

/////////////////////////////////////////////////////////////////////

template<typename NODETYPE>
bool List<NODETYPE>::isFull(const NODETYPE& roomNumber) const
{
        Node<NODETYPE>* currPtr = headPtr;
        while(currPtr != nullptr)
        {
	  // If current node's room number is the same then return true
	  if(currPtr->getRoomNumber() == roomNumber)
	  {
	    return true; // Room Number already is in the list
	  }
	 currPtr = currPtr->nextPtr;
	}
  return false; // If no room matches then return false
}

/////////////////////////////////////////////////////////////////////

template<typename NODETYPE>
Node<NODETYPE> *List<NODETYPE>::getNewNode(const NODETYPE& Room_Number, const NODETYPE& Rate, const NODETYPE& Status)
{
        return new Node<NODETYPE>(Room_Number, Rate, Status);
}

/////////////////////////////////////////////////////////////////////
