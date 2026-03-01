// 25. Reverse Nodes in k-Group
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

// Example 1:


// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]
// Example 2:


// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]
 

// Constraints:

// The number of nodes in the list is n.
// 1 <= k <= n <= 5000
// 0 <= Node.val <= 1000
 

// Follow-up: Can you solve the problem in O(1) extra memory space?

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
#include<iostream>
using namespace std;
class Solution {
public:
    ListNode* reverseLL(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* fut = curr->next;
        prev->next = NULL;
        while (curr) {
            curr->next = prev;
            prev = curr;
            curr = fut;
            if (fut)
                fut = fut->next;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* back = NULL;
        ListNode* modified_head = NULL;
        int count = 0;
        while (temp) {
            count++;
            temp = temp->next;
        }
        temp = head;
        while (count >= k) {
            int rem = k;
            while (rem > 1) {
                temp = temp->next;
                rem--;
            }
            if (back == NULL) {
                back = head;
                modified_head = temp;
                temp = temp->next;
                modified_head->next = NULL;
                modified_head = reverseLL(head);
                back->next = temp;
            } else {
                ListNode* curr_head = back->next;
                back->next = NULL;
                ListNode* nextnode = temp;
                temp=temp->next;
                nextnode->next=NULL;
                back->next = reverseLL(curr_head);
                curr_head->next=temp;
                back = curr_head;
                back->next = temp;
            }
            
            count -= k;
        }
        return modified_head;
    }
};