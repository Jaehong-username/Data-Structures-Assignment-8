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


#include "DataAnalysis.h"

int main(void)
{
	DataAnalysis obj;
	obj.runAnalysis();

	return 0;
}