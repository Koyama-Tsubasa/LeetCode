# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        # start compute
        if not head:
            return head
        else:
            
            current_node = head
            check = head.next
            current_value = current_node.val
            
            # start checking
            while check:
                
                if (check.val != current_value):
                    
                    current_node.next = check
                    current_node = check
                    current_value = current_node.val
                    
                check = check.next
                
            current_node.next = None
        
        return head
        
