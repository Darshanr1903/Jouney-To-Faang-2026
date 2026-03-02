// 61. Rotate List
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given the head of a linked list, rotate the list to the right by k places.

 

// Example 1:


// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Example 2:


// Input: head = [0,1,2], k = 4
// Output: [2,0,1]
 

// Constraints:

// The number of nodes in the list is in the range [0, 500].
// -100 <= Node.val <= 100
// 0 <= k <= 2 * 109
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0||head==NULL) return head;
        int count=0;
        ListNode* temp=head;
        ListNode* tail;
        while(temp){
            count++;
            if(temp->next==NULL) tail=temp;
            temp=temp->next;
        }
        k=k%count;
        count=count-k;
        while(count){
            tail->next=head;
            ListNode* curr_head=head;
            head=head->next;
            curr_head->next=NULL;
            tail=curr_head;
            count--;
        }
        return head;
    }
};