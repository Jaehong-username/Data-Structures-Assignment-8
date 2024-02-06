#include "Node.h"


/********************************************************************************************************************
* Function: ~Node()
* Description: A destructor for an object when it goes out of scope.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
Node::~Node()
{
	cout << "Destructor for Node class" << endl;
}

/********************************************************************************************************************
* Function: Node()
* Description: A constructor for Node class initialzing data members with newData and newUnits.
* Input parameters: newData, newUnits
* Returns: Nothing
*********************************************************************************************************************/
Node::Node(string newData, int newUnits)
{
	mData = newData;
	mpLeft = nullptr;
	mpRight = nullptr;
}


/********************************************************************************************************************
* Function: setmData()
* Description: A setter for mData, updating mData with new values from outside of the class
* Input parameters: newData
* Returns: Nothing
*********************************************************************************************************************/
void Node::setmData(string newData)
{
	mData = newData;
}

/********************************************************************************************************************
* Function: setmpLeft()
* Description: A setter for mpLeft, updating mpLeft with new values from outside of the class
* Input parameters: newpLeft
* Returns: Nothing
*********************************************************************************************************************/
void Node::setmpLeft(Node* newpLeft)
{
	mpLeft = newpLeft;
}

/********************************************************************************************************************
* Function: setmpRight()
* Description: A setter for mpRight, updating mpRight with new values from outside of the class
* Input parameters: newpRight
* Returns: Nothing
*********************************************************************************************************************/
void Node::setmpRight(Node* newpRight)
{
	mpRight = newpRight;
}

/********************************************************************************************************************
* Function: getmData()
* Description: A getter for mData, accessing mData from outside of the class
* Input parameters: Nothing
* Returns: mData
*********************************************************************************************************************/
string Node::getmData()
{
	return mData;
}

/********************************************************************************************************************
* Function: getmpLeft()
* Description: A getter for mpLeft, accessing mpLeft from outside of the class
* Input parameters: Nothing
* Returns: mpLeft reference
*********************************************************************************************************************/
Node*& Node::getmpLeft() //getting a reference to a pointer
{
	return mpLeft;
}

/********************************************************************************************************************
* Function: getmpRight()
* Description: A getter for mpRight, accessing mpRight from outside of the class
* Input parameters: Nothing
* Returns: mpRight reference
*********************************************************************************************************************/
Node*& Node::getmpRight()
{
	return mpRight;
}

/********************************************************************************************************************
* Function: printData() (a pure virtual function)
* Description: a pure virtual function that must be overidden by a derived class
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void Node::printData() // virtual keyword declared only in header not in the func implementation.
{
	//pure virtual function. //doesn't require any function implementation.
}
