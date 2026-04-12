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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>arr;
        for(ListNode* lst:lists){
            while(lst){
                arr.push_back(lst->val);
                lst=lst->next;
            }
        }
        sort(arr.begin(),arr.end());
        ListNode* res=new ListNode(0);
        ListNode* cur=res;
        for(int node:arr){
            cur->next=new ListNode(node);
            cur=cur->next;
        }
        return res->next;
    }
};
