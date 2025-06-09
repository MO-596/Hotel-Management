#ifndef NODES_H
#define NODES_H
#include "MainHeader.h"

template<typename NODETYPE>
class List;

template<typename NODETYPE>
class Node
{
        friend class List<NODETYPE>;
  public:
        Node(const NODETYPE&, const NODETYPE&, const NODETYPE&);

        void setRoomNumber(const NODETYPE&);
        NODETYPE getRoomNumber() const;

        void setRate(const NODETYPE&);
        NODETYPE getRate() const;

        void setStatus(const char&);
        char getStatus() const;

  private:
        NODETYPE Room_Number;
	NODETYPE Rate;
	char Status;

        Node<NODETYPE> *nextPtr;
};
#endif
