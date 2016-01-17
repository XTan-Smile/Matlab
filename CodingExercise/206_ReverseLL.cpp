/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        /*** O(n) ***/
        ListNode * pre = NULL;
        ListNode * post = NULL;
        while (head != NULL) {
            post = head -> next;
            head -> next = pre;
            pre = head;
            head = post;
        }
        return pre;
        /*** end ***/
        /*** recursion ***/
        if (head == NULL || head -> next == NULL) return head;
        ListNode * lastNode = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return lastNode;
        /*** recursion end ***/
        /*** change direction ***/
        ListNode ** curr;
        ListNode * tempStore = head;
        if (head != NULL) {
            int flag = 1;
            while (head -> next != NULL) { // two or more nodes
                curr = &head;
                while ((*curr) -> next -> next != NULL) {
                    curr = &((*curr) -> next);
                }
                if (flag) {
                    flag = 0;
                    tempStore = (*curr) -> next;
                }
                (*curr) -> next -> next = *curr;
                (*curr) -> next = NULL;
            }
        }
        return tempStore;
        /*** change direction of next end ***/
        /*** swap values ***/
        ListNode ** curr;
        ListNode * pointH = head;
        ListNode * pointT = head;
        if (head != NULL) {
            // point to the end, with pointT; *curr save the second last node;
            while (pointT -> next != NULL) {
                pointT = pointT -> next;
            }
            while( !(pointH == pointT || pointT -> next == pointH)) {
                curr = &pointH;
                while ((*curr) -> next != pointT) {
                    curr = &((*curr) -> next);
                }
                // swap
                int temp = pointH -> val;
                pointH -> val = pointT -> val;
                pointT -> val = temp;
                pointH = pointH -> next;
                pointT = *curr;
            }
        }
        return head;
        /*** swap values end ***/
    }
};