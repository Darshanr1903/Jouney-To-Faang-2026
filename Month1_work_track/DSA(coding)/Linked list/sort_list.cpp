// 148. Sort List
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Given the head of a linked list, return the list after sorting it in ascending order.

 

// Example 1:


// Input: head = [4,2,1,3]
// Output: [1,2,3,4]
// Example 2:


// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]
// Example 3:

// Input: head = []
// Output: []
 

// Constraints:

// The number of nodes in the list is in the range [0, 5 * 104].
// -105 <= Node.val <= 105
 

// Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
#include<iostream>
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
ListNode* merge(ListNode* head1,ListNode* head2){
    if(head1==NULL) return head2;
    if(head2==NULL) return head1;
    ListNode* dummy=new ListNode(-1);
    ListNode* res=dummy;
    while(head1&&head2){
        if(head1->val<head2->val){
            res->next=head1;
            res=head1;
            head1=head1->next;
        }
        else{
            res->next=head2;
            res=head2;
            head2=head2->next;
        }
    }
    if(head1) res->next=head1;
    if(head2) res->next=head2;
    return dummy->next;
}
ListNode* mergesort(ListNode* head){
    if(head==NULL||head->next==NULL) return head;
    ListNode* fast=head->next;
    ListNode* slow=head;
    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode* head2=slow->next;
    slow->next=NULL;
    ListNode* head1=mergesort(head);
    ListNode* head3=mergesort(head2);
    return merge(head1,head3);

}
    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};
