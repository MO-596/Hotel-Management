#ifndef LINKLIST_H
#define LINKLIST_H
#include "Nodes.cpp"
template <typename NODETYPE>
class List
{
  public:
        List();
        List(const List &);
        ~List();

        void insertNode(const NODETYPE&, const NODETYPE&, const NODETYPE&);
	bool searchNode_by_Room_Number(const NODETYPE&);
        bool searchNode_by_Status(const NODETYPE&);
        bool display() const;

	bool save(const string&) const;
	bool load(const string&);

	bool isEmpty() const;
	bool isFull(const NODETYPE&) const;
  private:
        Node<NODETYPE> *headPtr;
        Node<NODETYPE> *getNewNode(const NODETYPE&, const NODETYPE&, const NODETYPE&);
};
#endif

