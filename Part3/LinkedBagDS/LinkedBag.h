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
		Node<ItemType>* findMiddle(const Node<ItemType>* node){
			//if (node == std::nullptr) {
				//std::cout << 'nullptr' << std::endl;
			//}
			std::cout << "DEGUG: findMiddle called"	<< std::endl;

			int size = this->itemCount;
			int middle = size / 2;

			Node<ItemType>* current = headPtr; // start at the head
			int i = 1; // NOT zero indexing

			while (i < middle && current != nullptr) {
				current = current->getNext();
				i++;
			}
			std::cout << "DEGUG: current.item == " << current->getItem() << std::endl;
			return current;
		}

		Node<ItemType>* merge(Node<ItemType>* left, Node<ItemType>* right){
			std::cout << "DEGUG: merge() called"	<< std::endl;
			std::cout << "DEGUG: left.item == " << left->getItem() << std::endl;
			std::cout << "DEGUG: right.item == " << right->getItem() << std::endl;
			if (!left) return right;
			if (!right) return left;

			Node<ItemType>* result = nullptr;

			// left and right should be the beginning of their respective parts of linkedBag
			
			if (left->getItem() <= right->getItem()) {
				result = left;
				result->setNext(merge(left->getNext(), right));
			} else {
				result = right;
				result->setNext(merge(left, right->getNext()));
			}

			return result;
		}

		// Our own implementation of merge sort in the LinkedBag data structure
		Node<ItemType>* mergeSort(Node<ItemType>* head){
			std::cout << "DEGUG: mergeSort() called" << std::endl;
			if (!head->getNext()) {
				return head;
			}
			std::cout << "DEGUG: finding Middle"	<< std::endl;
			// Find the middle
			Node<ItemType>* middle = findMiddle(head);
			Node<ItemType>* nextOfMiddle = middle->getNext();
			middle->setNext(nullptr);
			std::cout << "DEGUG: middle.item == " << middle->getItem() << std::endl;
			std::cout << "DEGUG: nextOfMiddle.item == " << nextOfMiddle->getItem() << std::endl;

			// create a left and right linkedBag

			// Recursively sort the two halves
			std::cout << "DEGUG: calling mergeSort on left (head): " << head->getItem() << std::endl;
			Node<ItemType>* left = mergeSort(head);
			std::cout << "DEGUG: left.item == " << left->getItem() << std::endl;
			std::cout << "DEGUG: calling mergeSort on right (nextofmiddle): " << nextOfMiddle->getItem() << std::endl;
			Node<ItemType>* right = mergeSort(nextOfMiddle);
			std::cout << "DEGUG: right.item == " << right->getItem() << std::endl;

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