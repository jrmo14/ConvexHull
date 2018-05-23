#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Point.h"

typedef struct node {
    struct node *next;
    struct node *prev;
    point val;
} node;

void append_node(node *head, point val);

bool insert_node(node *head, point val, int pos);

node *create_head(point val);

void delete_node(node *head, int pos);

node *to_list(point *arr, int size);

point *to_arr(node *head);

point *to_arr_known_size(node *head, int size);

void print_list(node *head);

int list_size(node *head);

#endif
