// 23. Merge k Sorted Lists
// Solved
// Hard
// Topics
// premium lock icon
// Companies
// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

 

// Example 1:

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted linked list:
// 1->1->2->3->4->4->5->6
// Example 2:

// Input: lists = []
// Output: []
// Example 3:

// Input: lists = [[]]
// Output: []
 

// Constraints:

// k == lists.length
// 0 <= k <= 104
// 0 <= lists[i].length <= 500
// -104 <= lists[i][j] <= 104
// lists[i] is sorted in ascending order.
// The sum of lists[i].length will not exceed 104.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        ListNode* dummy=new ListNode(-1);
        ListNode* res=dummy;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]) pq.push({lists[i]->val,lists[i]});
        }
        while(pq.size()){
            ListNode* temp=pq.top().second;
            res->next=temp;
            res=res->next;
            temp=temp->next;
            pq.pop();
            if(temp) pq.push({temp->val,temp});
        }
        return dummy->next;
        
    }
};