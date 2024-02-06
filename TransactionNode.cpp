#include "TransactionNode.h"

/********************************************************************************************************************
* Function: ~TransactionNode()
* Description: A destructor for an object when it goes out of scope.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
TransactionNode::~TransactionNode()
{
	cout << "Destructor for TransactionNode class" << endl;
}


/********************************************************************************************************************
* Function: TransactionNode()
* Description: A constructor for TransactionNode class initialzing data members delcared in both Node class and its class.
* Input parameters: newData, newUnits
* Returns: Nothing
*********************************************************************************************************************/
TransactionNode::TransactionNode(string newData, int newNumUnits) : Node(newData, newNumUnits) //expected an expression instead of a type for Node
{
	//Node(newData) constructor inherited with : Node(newData);
	mUnits = newNumUnits;
}


/********************************************************************************************************************
* Function: getmUnits()
* Description: A getter for mUnits, accessing mUnits from outside of the class
* Input parameters: Nothing
* Returns: mUnits
*********************************************************************************************************************/
int TransactionNode::getmUnits()
{
	return mUnits;
}


/********************************************************************************************************************
* Function: setmUnits()
* Description: A setter for mUnits, updating mUnits with new values from outside of the class
* Input parameters: newUnits
* Returns: Nothing
*********************************************************************************************************************/
void TransactionNode::setmUnits(int newUnits)
{
	mUnits = newUnits;
}


/********************************************************************************************************************
* Function: printData()
* Description: this fucntion wil override the pure virtual function from Node abstract class and print the content
*              of the node.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void TransactionNode::printData() //through inheritance I can use getmData
{ 
	cout << "String Data from TransactionNode class: " << getmData() << endl;
	cout << "Units Data from TransactionNode class: " << getmUnits() << endl << endl;
}
