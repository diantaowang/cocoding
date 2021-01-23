
 // Definition for singly-linked list.
 struct ListNode {
     int val;
     struct ListNode *next;
 };
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *pos1 = l1, *pos2 = l2;
    int carry = 0;
    struct ListNode* head = (struct ListNode*) malloc(sizeof(struct ListNode));
    head->val = 0;
    head->next = NULL;
    struct ListNode* tail = head;
    while (pos1 != NULL) {
        struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
        int sum;
        if (pos2 != NULL) {
            sum = pos1->val + pos2->val + carry;
            pos2 = pos2->next;
        } else {
            sum = pos1->val + carry;
        }
        new_node->val = sum % 10;
        new_node->next = NULL;
        carry = sum / 10;
        tail->next = new_node;
        tail = new_node;
        pos1 = pos1->next;
    }
    while (pos2 != NULL) {
        struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
        int sum = pos2->val + carry; 
        new_node->val = sum % 10;
        new_node->next = NULL;
        carry = sum / 10;
        tail->next = new_node;
        tail = new_node;
        pos2 = pos2->next;
    } 
    if (carry > 0) {
        struct ListNode* new_node = (struct ListNode*) malloc(sizeof(struct ListNode));
        new_node->val = carry;
        new_node->next = NULL;
        tail->next = new_node;
        tail = new_node;
    }
    return head->next;
}
