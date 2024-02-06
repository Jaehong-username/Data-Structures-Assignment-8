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

#include "BST.h"


/********************************************************************************************************************
* Class name: DataAnalysis
* Description: This DataAnalysis class contains functions needed for basically running the data anaylsis program.
*********************************************************************************************************************/
class DataAnalysis
{
public:


	void runAnalysis();

	void parseLine(char line[100], string& units, string& type, string& transaction);

	void makeDataBST(BST& mTreeSold, BST& mTreePurchased);

	void compareTransactionField(string& units, string& type, string& transaction);

	void displayTrends(BST& mTreeSold, BST& mTreePurchased);
	
private:

	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream; //if put & get an error saying attempting to reference a function that has been already deleted
	ifstream& openDataCsv(ifstream& mCsvStream);

};

//
//Member functions :
//-A function that opens
//https ://eecs.wsu.edu/~aofallon/cpts122/progassignments/data.csv // yes, it¡¯s
//private, and must use mCsvStream to open the file
//- A function that reads one line from the file and splits the line into units, type,
//and transaction fields
//- A function that loops until all lines are read from the file; calls the function
//below, and then displays the current contents of both BSTs; use inOrderTraversal() to
//display the trees
//- A function that compares the transaction field and inserts the units and type
//into the appropriate tree(mTreeSold or mTreePurchased) // note with the way the
//data.csv file is organized the trees will be fairly balanced
//- A function that writes to the screen the trends we see in our tree; the
//function must display the type and number of units that are least purchased and sold,
//and the most purchased and sold
//+ runAnalysis(), which is the only public function in the class, aside from
//possibly a constructor and /or destructor; this function calls the other private
//functions