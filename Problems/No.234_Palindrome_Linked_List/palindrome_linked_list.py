# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """

        # parameters
        front, back, reverse_back = head, head, None

        # start computing (use Floyd's algorithm)

        # find the midium value
        while (back and back.next):
            front = front.next
            back = back.next.next

        # reversal step
        reverse_back = front.next
        front.next = None
        while reverse_back:
            back = reverse_back.next
            reverse_back.next = front
            front = reverse_back
            reverse_back = back

        # comparison step
        back = front
        front = head
        while back:
            if (front.val == back.val):
                front = front.next
                back = back.next
            else:
                return False

        return True
