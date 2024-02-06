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

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

#include <string>

#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

using std::ifstream;


/********************************************************************************************************************
* Class name: Node
* Description: Node is an abstract class with printDatan being a pure virtual function, which must be overridden by
*              the one from TransactionNode class which is publicly inherited from Node class.
*********************************************************************************************************************/
class Node //the node class is now an abstrac class
{
public:

	virtual ~Node(); //virtual destructor

	Node(string newData, int newUnits);

	void setmData(string newData);
	void setmpLeft(Node* newpLeft);
	void setmpRight(Node* newpRight);

	string getmData();
	Node*& getmpLeft();
	Node*& getmpRight();

	virtual void printData() = 0;//declaring it as a pure virtual function.

private:
	std:: string mData;
	Node* mpLeft;
	Node* mpRight;
};