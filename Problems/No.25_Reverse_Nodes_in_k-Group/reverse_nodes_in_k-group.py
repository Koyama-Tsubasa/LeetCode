# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        
        # reverse K nodes from first to last
        def reverseKnodes(first, last):
        
            connect = last.next
            while (first != last):
                temp = first.next
                first.next = connect
                connect = first
                first = temp
            first.next = connect
            
            return last
        
        # parameters
        first, last, previous = None, None, None
        starting_flag = True
        
        if (head.next==None or k==1):
            return head
        else:
            
            first, last = head, head
            
            # iterate until the last collides into NULL
            while (last):
                
                # check if the remaining nodes have more than k
                for i in range(1, k):
                    last = last.next
                    if (not last):
                        return head
                
                # check if it is the first reversion
                if starting_flag:
                    head = reverseKnodes(first, last);
                    starting_flag = False
                else:
                    previous.next = reverseKnodes(first, last);
                
                previous = first
                last = first.next
                first = first.next
                
            return head
        
