// https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1
// T.C => O(n*log(n))
Node* merge(Node* l1, Node* l2) {
    Node *cur = new Node(0);
    Node *temp = cur;
    while (l1 && l2) {
        if (l1->data < l2->data) {
            cur->next = l1;
            l1 = l1->next;
        }
        else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    if (l1) cur->next = l1;
    if (l2) cur->next = l2;
    return temp->next;
}

Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;
    Node *slow = head, *fast = head->next;
    // Finding mid
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    // Divide the list into two parts (one start with head and other with fast)
    fast = slow->next;
    slow->next = NULL;
    // Merge two list after Sorting
    return merge(mergeSort(head), mergeSort(fast));
}