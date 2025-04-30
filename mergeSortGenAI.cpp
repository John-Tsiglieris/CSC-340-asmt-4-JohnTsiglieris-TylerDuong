#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to merge two sorted lists
ListNode* mergeHalves(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->val < l2->val) {
        l1->next = mergeHalves(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeHalves(l1, l2->next);
        return l2;
    }
}

// Function to find the middle of the list
ListNode* getMiddle(ListNode* head) {
    if (!head) return head;
    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Merge sort function
ListNode* mergeSort(ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    // Find the middle
    ListNode* middle = getMiddle(head);
    ListNode* nextOfMiddle = middle->next;
    middle->next = nullptr;

    // Recursively sort the two halves
    ListNode* left = mergeSort(head);
    ListNode* right = mergeSort(nextOfMiddle);

    // Merge the sorted halves
    return mergeHalves(left, right);
}

// Helper function to print the list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    std::cout << "Original list: ";
    printList(head);

    head = mergeSort(head);

    std::cout << "Sorted list: ";
    printList(head);

    // Clean up memory
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
