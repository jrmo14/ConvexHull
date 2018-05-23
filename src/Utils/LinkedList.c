#include "LinkedList.h"

void append_node(node *head, point val) {
    node *ptr = head;
    node *append = malloc(sizeof(node));
    append->val = val;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = append;
    append->prev = ptr;
    append->next = NULL;
}

node *create_head(point val) {
    node *head = malloc(sizeof(node));
    head->prev = NULL;
    head->next = NULL;
    head->val = val;
    return head;
}

void delete_node(node *head, int pos) {
    // Special case for the head
    if (pos == 0) {
        head->val = head->next->val;
        head->next = head->next->next;
        return;
    }
    node *cur = head;
    while (cur->next != NULL && pos != 0) {
        pos--;
        cur = cur->next;
    }
    cur->prev->next = cur->next;
    cur->next->prev = cur->prev;
    free(cur);
}


node *to_list(point *arr, int size) {
    node *head;
    head = create_head(arr[0]);
    for (int i = 1; i < size; i++) {
        append_node(head, arr[i]);
    }
    return head;
}

point *to_arr(node *head) {
    return to_arr_known_size(head, list_size(head));
}


point *to_arr_known_size(node *head, int size) {
    printf("Size: %d\n", size);
    point *arr = malloc(sizeof(point) * size);
    for (int i = 0; i < size; i++) {
        arr[i] = head->val;
        head = head->next;
    }
    return arr;
}

bool insert_node(node *head, point val, int pos) {
    node *insert = (node *) malloc(sizeof(node));
    if (pos == 0) {
        insert->val = head->val;
        insert->next = head->next;
        head->next->prev = insert;
        insert->prev = head;
        head->val = val;
        head->next = insert;
        return true;
    }
    pos--;
    node *cur = head;
    while (pos != 0) {
        pos--;
        if (cur->next == NULL && pos > 0) {
            free(insert);
            return false;
        }
        cur = cur->next;
    }
    insert->val = val;
    insert->next = cur->next;
    cur->next = insert;
    insert->prev = cur;
    return true;
}

int list_size(node *head) {
    if (head == NULL)
        return 0;
    int acc = 1;
    while (head->next) {
        head = head->next;
        acc++;
    }
    return acc;
}

void print_list(node *head) {
    node *cur = head;
    while (cur->next != NULL) {
        print_point(cur->val);
        cur = cur->next;
    }
    print_point(cur->val);
}