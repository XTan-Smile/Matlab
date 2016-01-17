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
  ListNode* removeElements(ListNode* head, int val) {
    if (head == NULL) return head;
    ListNode ** curr = &head;
    while ((*curr) != NULL) {
      if ((*curr) -> val == val) {
	ListNode * temp = *curr;
	*curr = (*curr) -> next;
	delete temp;
      }
      else {
	curr = &((*curr) -> next);
      }
    }
    return head;
  }
};
