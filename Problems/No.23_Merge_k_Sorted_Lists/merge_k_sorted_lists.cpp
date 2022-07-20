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
        
        // parameters, priority queue with accending order
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
        pair<int, int> temp;
        ListNode *ans = NULL, *cur = NULL;
        int top_index;
        
        if (lists.size() == 0) return nullptr;
        else if (lists.size() == 1) return lists[0];
        else {
            
            // push the first values into priority queue
            for (int i=0; i<lists.size(); i++) {
                
                if (lists[i] != NULL) {
                    
                    temp.first = lists[i]->val;
                    temp.second = i;
                    PQ.push(temp);
                    
                }
                
            }
            
            // start computing, connect the highest priority in PQ until there is nothing in PQ
            while (PQ.size()) {
                
                top_index = PQ.top().second;
                PQ.pop();
                
                // check if it is the first node
                if (ans == NULL) {
                    
                    ans = lists[top_index];
                    cur = ans;
                    
                }
                else {
                    
                    cur->next = lists[top_index];
                    cur = cur->next;
                    
                }
                
                // check whether the next pointer is null or not
                if (lists[top_index]->next) {
                        
                    lists[top_index] = lists[top_index]->next;
                    temp.first = lists[top_index]->val;
                    temp.second = top_index;
                    PQ.push(temp);

                }
                
            }
            
            return ans;
            
        }
        
    }
};
