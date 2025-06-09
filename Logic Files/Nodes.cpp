#include "Nodes.h"
template<typename NODETYPE>
Node<NODETYPE>::Node(const NODETYPE& Room_Number, const NODETYPE& Rate, const NODETYPE& Status)
:nextPtr(nullptr)
{
        setRoomNumber(Room_Number);
	setRate(Rate);
	setStatus(Status);
}

///////////////////////////////////////////////////////////////

template<typename NODETYPE>
void Node<NODETYPE>::setRoomNumber(const NODETYPE& Room_Number)
{
        this->Room_Number = (Room_Number < 0) ? 0 : Room_Number;
        if(Room_Number < 0)
        {
                cout << "Value entered is invalid" << endl;
                this->Room_Number = 0;
        }
        else
        {
                this->Room_Number = Room_Number;
        }
}

/////////////////////////////////////////////////////////////////

template<typename NODETYPE>
NODETYPE Node<NODETYPE>::getRoomNumber() const
{
        return this->Room_Number;
}

//////////////////////////////////////////////////////////////

template<typename NODETYPE>
void Node<NODETYPE>::setRate(const NODETYPE& Rate)
{
        this->Rate = (Rate < 0) ? 0 : Rate;
        if(Rate < 0)
        {
                cout << "Value entered is invalid" << endl;
                this->Rate = 0;
        }
        else
        {
                this->Rate = Rate;
        }
}

/////////////////////////////////////////////////////////////////

template<typename NODETYPE>
NODETYPE Node<NODETYPE>::getRate() const
{
        return this->Rate;
}

/////////////////////////////////////////////////////////////////

template<typename NODETYPE>
void Node<NODETYPE>::setStatus(const char& Status)
{
//        this->Status = (Status < 0) ? 0 : Status;
        if(Status == 'Y' || Status == 'O')
        {
	  this->Status = Status; // Only accepts Y or O
        }
        else
        {
	  cout << "Invalid entry. Must be Y or O" << endl;
	  cout << "Setting O as default" << endl;
	  this->Status = 'O';
        }
}

/////////////////////////////////////////////////////////////////

template<typename NODETYPE>
char Node<NODETYPE>::getStatus() const
{
        return this->Status;
}
