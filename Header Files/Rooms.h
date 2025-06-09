#ifndef ROOMS_H
#define ROOMS_H
#include "LinkList.h"

template<typename NODETYPE>
class Rooms: private List<NODETYPE>
{
  public:
        template <typename T>
        friend ostream &operator<< (ostream &,const Rooms<T> &);

        template <typename T>
        friend istream &operator>> (istream &, Rooms<T> &);

        Rooms();
        Rooms(const Rooms&);

	void addRoom(const NODETYPE&, const NODETYPE&, const NODETYPE&);
	bool searchRoom_by_Number(const NODETYPE&);
	bool searchRoom_by_Status(const NODETYPE&);
	void displayRooms() const;
	bool SaveToFile() const;
	bool LoadFromFile();
	// Add date and delete function in a future date

	bool isFull(const NODETYPE&);
	bool isEmpty() const;

	int roomInput(int&);
	char charInput(char&);
	int rateInput(int&);

  private:
	int Room_Number;
	int Rate;
	char Status;
};
#endif
