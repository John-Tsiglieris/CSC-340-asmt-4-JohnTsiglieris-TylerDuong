//  Created by Frank M. Carrano and Timothy M. Henry.
//  Copyright (c) 2017 Pearson Education, Hoboken, New Jersey.

/** ADT bag: Link-based implementation.
	 @file LinkedBag.h 
	 Listing 4-3 */
#ifndef LINKED_BAG_
#define LINKED_BAG_

#include "BagInterface.h"
#include "Node.h"

template<class ItemType>
class LinkedBag : public BagInterface<ItemType>{
	private:
		Node<ItemType>* headPtr; // Pointer to first node
		int itemCount;			 // Current count of bag items
		
		// Returns either a pointer to the node containing a given entry
		// or the null pointer if the entry is not in the bag.
		Node<ItemType>* getPointerTo(const ItemType& target) const;
		
	public:
		LinkedBag();
		LinkedBag(const LinkedBag<ItemType>& aBag); // Copy constructor
		virtual ~LinkedBag(); // Destructor should be virtual
		
		//   SORTING ----------------------------------------------------
		void sort(int method); // 0 for merge sort, 1 for quick sort
		// TO DO: update prototype of merge sort based on your implementation
		//void mergeSort();
		//void mergeSort(ListNode* head);
		//Node<ItemType>* findMiddle(const Node<ItemType>* node); // mergesort helper function
		//Node<ItemType>* merge(Node<ItemType>* left, Node<ItemType>* right); // mergesort helper function
		//Node<ItemType>* mergeSort(Node<ItemType>* head);

		// Defining MergeSort functions here because it was giving us problems in the cpp file
		Node<ItemType>* split(Node<ItemType>* node){
			if (node == nullptr || node->getNext() == nullptr) {
				std::cout << "nullptr" << std::endl;
				return nullptr;
			}
			Node<ItemType>* slow = node;
			Node<ItemType>* fast = node->getNext();

			while (fast != nullptr && fast->getNext() != nullptr) {
				fast = fast->getNext()->getNext();
				slow = slow->getNext();
			}

			Node<ItemType>* result = slow->getNext();
			slow->setNext(nullptr); // separate the end of first half from second half
			return result; // returns first node of second half
		}

		Node<ItemType>* merge(Node<ItemType>* left, Node<ItemType>* right){
			if (left == nullptr) return right;
			if (right = nullptr) return left;

			// left and right should be the beginning of their respective parts of linkedBag
			if (left->getItem() <= right->getItem()) {
				left->setNext(merge(left->getNext(), right));
				return left;
			} else {
				right->setNext(merge(left,right->getNext()));
				return right;
			}
		}

		// Our own implementation of merge sort in the LinkedBag data structure
		Node<ItemType>* mergeSort(Node<ItemType>* head){
			if (head == nullptr || head->getNext() == nullptr) {
				return head;
			}

			// Find the start of second half
			Node<ItemType>* second = split(head); // split and return beginning of latter halg

			// Recursively sort the two halves
			Node<ItemType>* left = mergeSort(head);
			Node<ItemType>* right = mergeSort(second);

			// Merge the sorted halves
			return merge(left, right);

		}
		// EXTRA CREDIT 
		// TO DO: update prototype of quick sort based on your implementation
		void quickSort();
		// --------------------------------------------------------------

		int getCurrentSize() const;
		bool isEmpty() const;
		bool add(const ItemType& newEntry);
		bool remove(const ItemType& anEntry);
		void clear();
		bool contains(const ItemType& anEntry) const;
		int getFrequencyOf(const ItemType& anEntry) const;
		std::vector<ItemType> toVector() const;
		bool removeAlt(const ItemType& anEntry);
}; // end LinkedBag

#include "LinkedBag.cpp"
#endif