// 1670. Design Front Middle Back Queue
// Solved
// Medium
// Topics
// premium lock icon
// Companies
// Hint
// Design a queue that supports push and pop operations in the front, middle, and back.

// Implement the FrontMiddleBack class:

// FrontMiddleBack() Initializes the queue.
// void pushFront(int val) Adds val to the front of the queue.
// void pushMiddle(int val) Adds val to the middle of the queue.
// void pushBack(int val) Adds val to the back of the queue.
// int popFront() Removes the front element of the queue and returns it. If the queue is empty, return -1.
// int popMiddle() Removes the middle element of the queue and returns it. If the queue is empty, return -1.
// int popBack() Removes the back element of the queue and returns it. If the queue is empty, return -1.
// Notice that when there are two middle position choices, the operation is performed on the frontmost middle position choice. For example:

// Pushing 6 into the middle of [1, 2, 3, 4, 5] results in [1, 2, 6, 3, 4, 5].
// Popping the middle from [1, 2, 3, 4, 5, 6] returns 3 and results in [1, 2, 4, 5, 6].
 

// Example 1:

// Input:
// ["FrontMiddleBackQueue", "pushFront", "pushBack", "pushMiddle", "pushMiddle", "popFront", "popMiddle", "popMiddle", "popBack", "popFront"]
// [[], [1], [2], [3], [4], [], [], [], [], []]
// Output:
// [null, null, null, null, null, 1, 3, 4, 2, -1]

// Explanation:
// FrontMiddleBackQueue q = new FrontMiddleBackQueue();
// q.pushFront(1);   // [1]
// q.pushBack(2);    // [1, 2]
// q.pushMiddle(3);  // [1, 3, 2]
// q.pushMiddle(4);  // [1, 4, 3, 2]
// q.popFront();     // return 1 -> [4, 3, 2]
// q.popMiddle();    // return 3 -> [4, 2]
// q.popMiddle();    // return 4 -> [2]
// q.popBack();      // return 2 -> []
// q.popFront();     // return -1 -> [] (The queue is empty)
 

// Constraints:

// 1 <= val <= 109
// At most 1000 calls will be made to pushFront, pushMiddle, pushBack, popFront, popMiddle, and popBack.
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int data){
        val=data;
        next=prev=NULL;
    }
};
class FrontMiddleBackQueue {
public:
Node* head;
Node* tail;
    FrontMiddleBackQueue() {
        head=tail=NULL;
    }
    
    void pushFront(int val) {
        if(!head){
            head=tail=new Node(val);
            return;
        }
        else{
            Node* newHead=new Node(val);
            head->prev=newHead;
            newHead->next=head;
            head=newHead;
        }
    }
    
    void pushMiddle(int val) {
        if(!head){
            head=tail=new Node(val);
            return;
        }
        Node* slow=head;
        Node* fast=head->next;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node* temp=new Node(val);
        if(!fast){
             Node* prevnode=slow->prev;
             if(prevnode) prevnode->next=temp;
             else head=temp;
             temp->prev=prevnode;
             temp->next=slow;
             slow->prev=temp;
        }
        else{
            Node* nextnode=slow->next;
            temp->next=nextnode;
            if(nextnode) nextnode->prev=temp;
            else tail=temp;
            slow->next=temp;
            temp->prev=slow;
        }
    }
    
    void pushBack(int val) {
        Node* temp=new Node(val);
        if(!tail){
            head=tail=temp;
            return;
        }
        else{
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
        
    }
    
    int popFront() {
        if(!head) return -1;
        int val=head->val;
        head=head->next;
        if(head) head->prev=NULL;
        else head=tail=NULL;
        return val;
    }
    
    int popMiddle() {
        if(!head) return -1;
        Node* slow=head;
        Node* fast=head->next;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node* prevnode=slow->prev;
        Node* nextnode=slow->next;
        if(prevnode) prevnode->next=nextnode;
        else{
            head=head->next;
            if(head) head->prev=NULL;
        }
        if(nextnode) nextnode->prev=prevnode;
        else{
            tail=tail->prev;
            if(tail) tail->next=NULL;
        }
        return slow->val;
    }
    
    int popBack() {
        if(!head) return -1;
        int val=tail->val;
        tail=tail->prev;
        if(tail) tail->next=NULL;
        else{
            head=tail=NULL;
        }
        return val;
    }
};