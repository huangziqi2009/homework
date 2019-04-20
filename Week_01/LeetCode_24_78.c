/*

给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例:
给定 1->2->3->4, 你应该返回 2->1->4->3.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* swapPairs(struct ListNode* head) {

    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *curr = head;
    struct ListNode *next = NULL;
    struct ListNode *a = NULL;
    struct ListNode *b = NULL;

    struct ListNode node;
    node.val = -1;
    node.next = NULL;
    struct ListNode *prev = &node;

    while (curr && curr->next) {
        a = curr;
        b = curr->next;
        next = b->next;
        b->next = a;
        a->next = next;

        prev->next = b;
        prev = curr;
        curr = next;        
    }

    return node.next;
}


int main(int argc, char *argv[]) {
    struct ListNode *head = NULL;
    int i = 10;
    for (i = 5; i > 0; i--) {
        struct ListNode *Node= (struct ListNode*)calloc(1,sizeof(struct ListNode));
        Node->val = i;
        Node->next = head;
        head = Node;
    }
 
    struct ListNode *p = NULL;
    p = swapPairs(head);

    struct ListNode *tmp = NULL;
    while (p) {
        printf("%p, %d.\n", p, p->val);
        tmp = p;
        p = p->next;
        free(tmp);
    }

    return 0;
}
