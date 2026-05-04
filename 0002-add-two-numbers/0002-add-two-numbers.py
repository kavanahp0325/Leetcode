# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: Optional[ListNode]
        :type l2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        dummy = ListNode(0)
        c = dummy
        carry = 0

        while l1 or l2 or carry:
            v1=l1.val if l1 else 0
            v2=l2.val if l2 else 0
            sum=v1+v2+carry
            carry=sum//10
            new=ListNode(sum%10)
            c.next=new
            c=c.next
            if l1:
                l1=l1.next
            if l2:
                l2=l2.next
        return dummy.next

        