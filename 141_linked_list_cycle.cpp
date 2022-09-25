/**
 * Fast and slow pointer approach. Slow pointer advances by one each time and fast pointer
 * advances by two. If at any point the fast pointer is null, there is no cycle. If the
 * two pointers are equal, there is a cycle.
 * 
 * The two pointers are guaranteed to converge at some point if there is a cycle.
 */

/**
 * Definition for linked list node.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) {
            return false;
        }
        
        ListNode* fast = head->next;
        ListNode* slow = head;
        
        while (fast and fast->next) {
            if (fast == slow) {
                return true;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        
        return false;
    }
};