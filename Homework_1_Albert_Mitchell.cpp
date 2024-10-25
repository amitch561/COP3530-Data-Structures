/*
* Albert Mitchell
* COP 3530: Data Structure and Algorithm Analysis
* Homework 1
*/

#include<iostream>
#include<vector>
#include<stdexcept>



//QUESTION 1(C)Function for Time complexity tightly bound by O(log n)
int DoubleCounter(int n)
{    //Notes: To achieve logarithmic loop always use a value of 1 or non-zero positive integer
	int i = 1;
	for (i; i <= n; i *= 2)
	{
		std::cout << "\nThe counter value is: " << i;
	}
	std::cout << std::endl;
	return i;
}

//QUESTION 2 Test
class ArraySequence
{
public:
	std::vector<int> A = { 1,2,3 };
	std::vector<int> X = { 7,8,9,10 };
	

	
	void InsertAt(int index, int value)
	{
		if (index < 0 || index > A.size())
		{
			throw std::out_of_range("Index selected is out of range");
		}
		A.insert(A.begin() + index, value);

	}


	void InsertAllAtA(int index, const std::vector<int>& Xinsert)
	{
		if (index < 0 || index > A.size())
		{
			throw std::out_of_range("Index selected is out of range");
		}

		for (int i = 0; i < Xinsert.size(); i++)
		{
			InsertAt(index+i, Xinsert[i]);
		}
	}

	void InsertAllAtB(int index, const std::vector<int>& Xinsert)
	{
			if (index < 0 || index > A.size())
			{
				throw std::out_of_range("Index selected is out of range");
			}
			A.insert(A.begin() + index, Xinsert.begin(), Xinsert.end());
	}

		void print()
		{
			for (int i:A)
			{
				std::cout << i << " ";
			}
			std::cout << std::endl;
		}
	

private:
	

};


//Question 3- Write a function to determine whether a LinkedList is sorted in the increasing order
struct Node
{
	int value;
	Node* next;
};
bool isSorted(Node* head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return true;
	}

	Node* current = head;

	while (current->next != nullptr)
	{
		if (current->value > current->next->value)
		{
			return false;
		}
		current = current->next;
	}
	return true;
}

//Question 4 - Implement the DeleteAt(i) function for LinkedList.

Node* DeleteAt(Node* head, int index)
{
	if (head == nullptr || index < 0)
	{
		return head;
	}

	if (index == 0)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
		return head;
	}

	Node* current = head;
	int count = 0;
	//Traverse
	while (current && count < index-1)
	{ 
		current = current->next;
		count++;
	}
	if (current == nullptr || current->next == nullptr)
	{
		return head;
	}

	Node* temp = current->next;
	current->next = current->next->next;
	delete temp;
	return head;
}
void Printlist(Node* head)
{
	Node* current = head;
	while (current != nullptr)
	{
		std::cout << current->value << "->";
		current = current->next;
	}
}

/*Question 6 
Given an array of integers numbers and an integer target
• Return true if there are two numbers with different indices such that they add up to
target.
Return false otherwise*/

bool twoSum(std::vector<int>& nums, int target)
{
	for (size_t i = 0; i < nums.size(); i++)
	{
		for (size_t j = i + 1; j < nums.size(); j++)
		{
			if (nums[i] + nums[j] == target)
			{
				return true;
			}
		}
	}
	return false;
}





int main()
{
	//Initialization
	int n = 10;
	
	std::vector<int> nums = { 8,5,6,7,9 };
	//Linked List Intialization
	Node* head = new Node{ 4,nullptr };
	head->next = new Node{ 8,nullptr };
	head->next->next = new Node{ 5, nullptr };
	head->next->next->next = new Node{ 7, nullptr };


	//Question 1
	std::cout << "QUESTION 1:";
	DoubleCounter(n);

	//Question 2
	std::cout << "\n" << "QUESTION 2:" <<"\n";
	ArraySequence Array_one;
	Array_one.InsertAllAtA(1,Array_one.X);
	Array_one.print();
	Array_one.A.assign({ 1,2,3 });
	Array_one.InsertAllAtB(1, Array_one.X);
	Array_one.print();

	//Question 3
	std::cout << "\n" << "QUESTION 3:";
	
	std::cout << "The Linked List is:";
	Printlist(head);
	int sort= isSorted(head);
	std::cout <<"\n\n\n" <<"0 represents false & 1 represents true"<<std::endl
			  <<"Is the linked list sorted?:"  << sort<<std::endl;

	//Question 4
	std::cout << "\n" << "QUESTION 4:";
	Printlist(head);
	DeleteAt(head, 3);
	std::cout << "\n";
	Printlist(head);
	std::cout << "\n\n\n";
	return 0;
}


