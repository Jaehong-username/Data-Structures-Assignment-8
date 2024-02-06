#include "BST.h"

BST::~BST()
{
	destroyTree(mpRoot);
}

BST::BST()
{
	mpRoot = nullptr;
}

Node*& BST::getpRoot()
{
	return mpRoot;
}

void BST::setpRoot(Node* newpRoot)
{
	mpRoot = newpRoot;
}

void BST::insert(const string& newData, const int newUnits) //insert the new tree node based on mUnits
{
	insert(this->mpRoot, newData, newUnits);
}


void BST::inOrderTraversal()
{
	inOrderTraversal(this->mpRoot);
}

TransactionNode& BST::findSmallest(Node* pRoot)
{
	//just explicitly casting is not safe.
	Node* searchPtr = mpRoot; //we need to down cast it via using keyword dynamic_cast (more safe checks at a run time works in polymorphism) than static_cast 
	//Node* searchPtr = dynamic_cast<TransactionNode*>(pRoot);

	//searchPtr = (dynamic_cast <TransactionNode*> (searchPtr)); //this code will not change searchPTr to TransactionNode foreover.
	
	while (searchPtr->getmpLeft()!= nullptr)
	{
		//searchPtr = mpRoot->getmpLeft(); //causes the infinite loop search pointer only gets updated once and never gets updated further!!
		searchPtr = searchPtr->getmpLeft();
	}
	//once out of the loop searchPtr currently pointng to the leftmost subtree!

	return *(dynamic_cast<TransactionNode*> (searchPtr));
}

TransactionNode& BST::findLargest(Node* pRoot) //finding the rightmost subtree
{
	Node* searchPtr = mpRoot;
	while (searchPtr->getmpRight() != nullptr)
	{
		//searchPtr = mpRoot->getmpRight();
		searchPtr = searchPtr->getmpRight();
	}
	//once out of the loop searchPtr currently pointng to the leftmost subtree!

	return *(dynamic_cast<TransactionNode*> (searchPtr)); //downcasting

	//if (pRoot->getmpRight() == nullptr) // now this is the rightmost subtree
	//{
	//	return *(dynamic_cast<TransactionNode*> (pRoot)); //I need that * since & automatically dereference for you it is an ailias another name 
	//	                                             // for the same object with automatically derefereces
	//}
	//else
	//{
	//	findLargest(mpRoot->getmpRight());
	//}
}

void BST::destroyTree(Node* newpRoot) //this is private this should visit each node in post order!
{
	if (newpRoot != nullptr) //Visit each in post order!
	{
		if (newpRoot->getmpLeft() != nullptr)
		{
			destroyTree(newpRoot->getmpLeft());
		}
	
		if (newpRoot->getmpRight() != nullptr)
		{
			destroyTree(newpRoot->getmpRight());
		}

		cout << "Destroy the tree Node that contains data: " << newpRoot->getmData() << endl;
		delete newpRoot;

	}

	else // mpRoot nullptr
	{
		cout << "Tree empty, There is nothing to delete the tree nodes Please double check!" << endl;
	}
}


  //reference to a pointer
void BST::insert(Node*& pRoot, const string& newData, const int newUnits)
{
	if (pRoot == nullptr)  //Tree root ptr is empty
	{
		TransactionNode* pMem = new TransactionNode(newData, newUnits); //dynamically allocates an memory!!
		//so that in tree node can be deleted from the heap using the delete keyword from destroyTree function
		pRoot = pMem; //pRoot is ptr to Node pMem is ptr to TransactionNode??????????????????????
	}

	else //Tree root ptr is not empty
	{                                           //because pRoot is a reference to a ptr automatically gives you a ptr which is a derferenced value
		if (newUnits > (dynamic_cast <TransactionNode*> (pRoot))->getmUnits()) //then traverse down the right tree
		{
			if (pRoot->getmpRight() == nullptr) //insert in the right subtree here!
			{
				TransactionNode* pMem = new TransactionNode(newData, newUnits);
				pRoot->setmpRight(pMem);
			}

			else //if mpRight ptr already filled with a tree Node
			{
				insert(pRoot->getmpRight(), newData, newUnits);
			}

		}

		else if (newUnits < (dynamic_cast <TransactionNode*> (pRoot))->getmUnits()) //then traverse down the left tree.
		{
			if (pRoot->getmpLeft() == nullptr) //insert in the left subtree here!
			{
				TransactionNode* pMem = new TransactionNode(newData, newUnits);
				pRoot->setmpLeft(pMem);
			}

			else //if mpLeft ptr already filled with a tree Node
			{
				insert(pRoot->getmpLeft(), newData, newUnits);
			}

		}

		else // if newData == pRoot->getmData() in Binary search tree doesn't deal with duplicates!!
		{
			cout << "Duplicate data!\nBinary search tree does not deal with duplicates!\nPlease doublecheck the data!" << endl << endl;
		}

	}

}



void BST::inOrderTraversal(Node* pRoot) //prints data in order
{
	if (pRoot != nullptr)
	{
		inOrderTraversal(pRoot->getmpLeft());
		pRoot->printData(); //printData for TransactionNode class
		inOrderTraversal(pRoot->getmpRight());

	}

}
