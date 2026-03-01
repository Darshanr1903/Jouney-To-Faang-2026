// 82. Remove Duplicates from Sorted List II
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

// Example 1:


// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]
// Example 2:


// Input: head = [1,1,1,2,3]
// Output: [2,3]
 

// Constraints:

// The number of nodes in the list is in the range [0, 300].
// -100 <= Node.val <= 100
// The list is guaranteed to be sorted in ascending order. 

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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp&&temp->next){
            ListNode* curr=temp->next;
            while(curr&&curr->val==temp->val){
                curr=curr->next;
            }
            if(temp->next==curr){
                prev=temp;
                temp=curr;
            }
            else{
                if(prev){
                    prev->next=curr;
                    temp=prev;
                }
                else{
                    head=curr;
                    temp=curr;
                }
            }
        }
        return head;
    }
};