// https://leetcode.com/problems/merge-k-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Comparator
{
    public:
        bool operator() (const ListNode *a, const ListNode *b)
        {
            return a->val>b->val;
        }
};

class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.empty())
            return NULL;
        
        priority_queue<ListNode*, std::vector<ListNode*>, Comparator> p;
        
        for(int i=0;i<lists.size();i++)
        {
            if(lists[i])
            {
                p.push(lists[i]);
            }
        }
        
        ListNode *head=NULL,*p1=NULL;
        
        while(!p.empty())
        {
            ListNode *a=p.top();
            p.pop();
            if(head==NULL)
            {
                head=a;
                p1=head;
            }
            else
            {
                p1->next=a;
                p1=p1->next;
            }
            
            if(a->next)
                p.push(a->next);
        }

        return head;
    }
};