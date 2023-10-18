//
// Created by Jev on 2022/10/21.
//
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 //剑指 Offer 52. 两个链表的第一个公共节点
 //输入两个链表，找出它们的第一个公共节点。

 //输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
 //输出：Reference of the node with value = 8
 //输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。
 // 在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        class Solution {
        public:
            ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
                ListNode *A = headA, *B = headB;
                while (A != B) {
                    A = A != nullptr ? A->next : headB;
                    B = B != nullptr ? B->next : headA;
                }
                return A;
            }
        };
    }
};