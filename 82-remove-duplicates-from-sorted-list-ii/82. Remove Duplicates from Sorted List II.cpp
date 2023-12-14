/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        map <int, int> mp;

        while(head != NULL)
        {
            mp[head -> val]++;
            head = head -> next;
        }

        ListNode* newHead = new ListNode(); //Creating new list for answer
        ListNode* temp = newHead; //temp variable to keep track of the last node
        for(auto & it: mp)
        {
            if(it.second == 1)
            {
                ListNode* ans = new ListNode(it.first); //to avoid integer to pointer conversion
                temp -> next = ans;
                temp = ans;
            }
        }
        return newHead -> next;
    }
};