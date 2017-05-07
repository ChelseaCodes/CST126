/************************************************************************
* Class: Node
*
* Purpose:
*	This class encapsulates Music class, to be added into 
*	linked list class
*
* Manager functions:
*	Node()
*	Node(Music * m)
*	Node(const Node& copy)
*	Node& operator=(const Node& copy)
*
* Methods:
*	setters and getters for data, next ptr
*	operator overloads
*
*************************************************************************/
#ifndef Node_H
#define Node_H

#include <iostream>
using std::cout;
using std::endl; 
#include <iomanip>
using std::setw;
using std::left;

#include <ostream>
using std::ostream;
#include "music.h"

class Node
{
public:
	Node();
	Node(Music * m); 
	Node(const Node& copy);
	Node& operator=(const Node& copy);

	Music * getData() const; 
	Node * getNext() const; 
	void setData(Music * m);
	void setNext(Node * next);

	bool operator>=(const Node & rhs); 
	bool operator<=(const Node & rhs);
	bool operator>(const Node & rhs);
	bool operator<(const Node & rhs);
	bool operator==(const Node & rhs); 

	~Node(); 
private:
	Music * m_data; 
	Node * m_next;
};
#endif