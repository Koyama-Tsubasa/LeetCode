# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        
        # parameters, priority queue with accending order
        PQ = []
        mapping = {}
        ans = cur = None
        
        # start compute
        if (len(lists) == 0):
            return None
        elif (len(lists) == 1):
            return lists[0]
        else:
            
            # push the first values into priority queue
            for i in range(len(lists)):
                if lists[i] is not None:
                    heappush(PQ, (lists[i].val, i))
                    mapping[i] = lists[i]

            # start computing, connect the highest priority in PQ until there is nothing in PQ
            while PQ:
                
                val, index = heappop(PQ)
                
                # check if it is the first node
                if ans is None:
                    ans = cur = mapping[index]
                else:
                    cur.next = mapping[index]
                    cur = cur.next
                    
                # check whether the next pointer is null or not
                if mapping[index].next is not None:
                    mapping[index] = mapping[index].next
                    heappush(PQ, (mapping[index].val, index))

            return ans
        
