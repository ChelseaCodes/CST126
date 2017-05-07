/*************************************************************
* Author:		Chelsea Christison
* Filename:		node.cpp
* Date Created:	3.13.2017
* Modifications:
*
**************************************************************/
#include "node.h"

//default c'tor
Node::Node(): m_data(nullptr), m_next(nullptr) {}

//c'tor
Node::Node(Music* m):m_data(m), m_next(nullptr) {}

//copy c'tor
Node::Node(const Node& copy):m_data(copy.m_data), m_next(copy.m_next)
{}

//op=
Node& Node::operator=(const Node& copy)
{
	if(this != &copy)
	{
		m_data = copy.m_data;
		m_next = copy.m_next;		
	}
	return *this; 
}

//getter for  node data
Music* Node::getData() const
{
	if(this != nullptr)
		return m_data;
}

//getter for next node
Node* Node::getNext() const
{
	if (this != nullptr)
		return m_next;
}

//setter for node data
void Node::setData(Music* m) { m_data = m; }

//setter for node next
void Node::setNext(Node* next) { m_next = next; }

/*************************************************************
*	Purpose:
*		Overloaded operator>=, used for node to node
*		comparisons, but calls String class overloaded op>=
*
**************************************************************/
bool Node::operator>=(const Node & rhs)
{
	return m_data->getSong() <= rhs.m_data->getSong(); 
}

/*************************************************************
*	Purpose:
*		Overloaded operator<=, used for node to node
*		comparisons. Calls String class overloaded op<=
*
**************************************************************/
bool Node::operator<=(const Node & rhs)
{
	return m_data->getSong() >= rhs.m_data->getSong(); 
}

/*************************************************************
*	Purpose:
*		Overloaded operator>, used for node to node
*		comparisons. Calls String class overloaded op>
*
**************************************************************/
bool Node::operator>(const Node & rhs)
{
	return m_data->getSong() > rhs.m_data->getSong(); 
}

/*************************************************************
*	Purpose:
*		Overloaded operator<, used for node to node
*		comparisons. Calls String class overloaded op<
*
**************************************************************/
bool Node::operator<(const Node & rhs)
{
	return m_data->getSong() < rhs.m_data->getSong(); 
}

/*************************************************************
*	Purpose:
*		Overloaded operator==, used for node to node
*		comparisons. Calls Music class overloaded op==
*
**************************************************************/
bool Node::operator==(const Node & rhs)
{
	return m_data == rhs.m_data; 
}

//d'tor, free mem used for data
Node::~Node()
{
	delete m_data; 
	m_next = nullptr;
}