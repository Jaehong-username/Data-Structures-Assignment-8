#include "DataAnalysis.h"

/********************************************************************************************************************
* Function: runAnalysis()
* Description: runs the analysis program.
* Input parameters: Nothing
* Returns: Nothing
*********************************************************************************************************************/
void DataAnalysis::runAnalysis()
{
	makeDataBST(mTreeSold, mTreePurchased);
	displayTrends(mTreeSold, mTreePurchased);
}

/********************************************************************************************************************
* Function: parseLine()
* Description: This will parse the line extracted from data.csv file and separate it in to units, type, and
*              transaction.
* Input parameters: line, units, type, transaction
* Returns: Nothing
*********************************************************************************************************************/
void DataAnalysis::parseLine(char line[100], string& units, string& type, string& transaction)
{
	//Units, Type, Transaction
	//mCsvStream.getline(line, 100);
		
	units = string(strtok(line, ",\n"));
	type = string(strtok(NULL, ",\n"));
	transaction = string(strtok(NULL, ",\n"));
}

/********************************************************************************************************************
* Function: makeDataBST
* Description: Insert data from data.csv and determine to insert it into one of two BST (mTreeSold, mTreePurchased).
* Input parameters: mTreeSold: BST passed by reference, mTreePurchased: BST passed by reference.
* Returns: Nothing
*********************************************************************************************************************/
void DataAnalysis::makeDataBST(BST& mTreeSold, BST& mTreePurchased)
{
	/*int dummyNum = 0;
	int* units = &dummyNum;
	string typeStr = "";
	char transaction[20] = "";
	string transactionStr = "";*/
	string units = "";
	string type = "";
	string transaction = "";

	char line[100];

	openDataCsv(mCsvStream);

	mCsvStream.getline(line, 100); //skip the first line
	cout << "" << line << endl;
	//Units, Type, Transaction

	while (mCsvStream.is_open() && !mCsvStream.eof())
	{
		mCsvStream.getline(line, 100);
		parseLine(line, units, type, transaction);
		compareTransactionField(units, type, transaction);
	}


	cout << "\nTreeSold: " << endl << endl;
	mTreeSold.inOrderTraversal();

	cout << "\nTreePurchased: " << endl << endl;
	mTreePurchased.inOrderTraversal();

	mCsvStream.close();
}


/********************************************************************************************************************
* Function: compareTransactionField()
* Description: based on transaction type: Purchased and Sold from the data.csv file, insertion function will be operated
*              into the corresponding name of the BST.
* Input parameters: units, type, transaction
* Returns: Nothing
*********************************************************************************************************************/
void DataAnalysis::compareTransactionField(string& units, string& type, string& transaction)
{
	if (transaction == "Sold")
	{
		mTreeSold.insert(type, stoi(units));
	}

	else if (transaction == "Purchased")
	{
		mTreePurchased.insert(type, stoi(units));
	}

}


/********************************************************************************************************************
* Function: displayTrends()
* Description: This will find the product with the largest and the smallest units in both mTreeSold BST and
*              mTreePurchased BST.
* Input parameters: mTreeSold: BST passed by reference, mTreePurchased: BST passed by reference.
* Returns: Nothing
*********************************************************************************************************************/
void DataAnalysis::displayTrends(BST& mTreeSold, BST& mTreePurchased)
{                 //auto dereference so using .operator
	int mostPurchased;
	int leastPurchased;
	
	int mostSold;
	int leastSold;
	
	cout << "This is the recent trend in the market within 48 hours based on the data analysis of the csv file!\n\n\n" << endl;



	mostSold = (mTreeSold.findLargest(mTreeSold.getpRoot())).getmUnits();  //return reference to transaction so I can use the dot operator
	leastSold = (mTreeSold.findSmallest(mTreeSold.getpRoot())).getmUnits();
	cout << "Most Recently Sold Products: " << mostSold << endl;
	cout << "Least Recently Sold Products: " << leastSold << endl << endl;

	mostPurchased = (mTreePurchased.findLargest(mTreePurchased.getpRoot())).getmUnits(); //return reference to transaction so I can use the dot operator
	leastPurchased = (mTreePurchased.findSmallest(mTreePurchased.getpRoot())).getmUnits();
	cout << "Most Recently Purchased Products: " << mostPurchased << endl;
	cout << "Least Recently Purchased Products: " << leastPurchased << endl << endl;

}


/********************************************************************************************************************
* Function: openDataCsv()
* Description: checks the input file if it's closed, it will open the file.
* Input parameters: mCsvStream: input file strea passed by reference.
* Returns: input fike stream reference.
*********************************************************************************************************************/
ifstream& DataAnalysis::openDataCsv(ifstream& mCsvStream)
{
	//first need to include the library <fstream>

	if (!mCsvStream.is_open())
	{
		mCsvStream.open("data.csv", std::ios::in);
	}

	else //file is already opened
	{
		cout << "data.csv file is already opened! No need for this function use\n" << endl;
	}

	return mCsvStream;
}
