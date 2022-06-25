# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        
        # check if the initial lists contains NULL list
        if (list1 == None):
            return list2
        elif (list2 == None):
            return list1
        else:
            
            # add the first solution
            if (list1.val < list2.val):
                solution = list1
                list1 = list1.next
            else:
                solution = list2
                list2 = list2.next
            
            # check which value is smaller and add to the next of the current solution iteratively
            cur = solution
            while (list1 and list2):
                
                if (list1.val < list2.val):
                    cur.next = list1
                    list1 = list1.next
                else:
                    cur.next = list2
                    list2 = list2.next
                cur = cur.next
            
            # if one of the list is not all visited then add
            if list1:
                cur.next = list1
            elif list2:
                cur.next = list2
            
            return solution
        
