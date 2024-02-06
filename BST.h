/****************************************************************************************************************************
* Programmer: Jaehong Lee
* Class: CPTs 122, Fall 2023; Lab Section 3 (Tuesday 1:30PM - 4:20PM)
* Programming Assignment: PA8
* Date: December 15, 2023
* Description: This PA assignment analysizes the most/least purchased and sold products in the market within 48hours
*              from data.csv file using BST search algorithm. Each line of data from the csv file will be inserted into one
*              of two BST (Purchased, Sold). BST is an effective search algorithm with less time complexity compared to
*              sequential search. Node is an abstract class, and TransactionNode class which is publicly inherited from
*              Node class will override some of the member functions defined in Node class through virtual keyword.
****************************************************************************************************************************/

#pragma once

#include "TransactionNode.h"


/********************************************************************************************************************
* Class name: BST
* Description: This class contains basic functions that manage the binary search tree such as insertion or destroy
*              the tree function.
*********************************************************************************************************************/
class BST
{
public:

	~BST(); //call destroyTree, a private function

	BST();

	Node*& getpRoot();

	void setpRoot(Node* newpRoot);

	void insert(const string& newData, const int newUnits);

	void inOrderTraversal();

	TransactionNode& findSmallest(Node* pRoot);

	TransactionNode& findLargest(Node* pRoot);



	//+default constructor
	//	+ setter
	//	+ getter
	//	+ insert() // public used to hide pointer information, i.e. won¡¯t pass in the
	//	root of the tree into this function, only the private insert() function
	//	- insert() // yes, it¡¯s private, and it dynamically allocates a
	//	TransactionNode and inserts recursively in the correct subtree based on
	//	mUnits; should pass in a reference to a pointer(i.e.Node*& pT)
	//	+ inOrderTraversal() // yes, once again it¡¯s private to hide pointer information
	//	- inOrderTraversal(), which recursively visits and prints the contents(mData
	//		and mUnits) of each node in the tree in order; each node¡¯s printData() should
	//	be called
	//	contents should be printed on a separate line; must call the printData()
	//	function associated with the TransactionNode
	




private:
	Node* mpRoot; //a pointer to Node not a transaction class

	void destroyTree(Node* newpRoot);

	void insert(Node*& pRoot,const string& newData, const int newUnits);

	void inOrderTraversal(Node* pRoot);

};