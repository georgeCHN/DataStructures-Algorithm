#pragma once
#ifndef LISTAPP_H_
#define LISTAPP_H_

#include "my_bool.h"
#include "linklist.h"
//delete all of node that value equal x, use recurit
extern LinkList list_delete_x(LinkList list, int x);
//delete all of node that value equal x. use non-recur
extern void list_delete_x_NonRecursion(LinkList list, int x);
//inversly print linklist
extern void list_print_inverse(LinkList list);
//make linklist inversly
extern LinkList list_inverse(LinkList list);
//delete min node, we can assume min value is unique
extern void list_delete_min(LinkList list);
//sort the linklist
extern LinkList list_sort(LinkList list);
//delete node that value between i and j
extern void list_delete_range(LinkList list, int i, int j);
//return commmon part of list a and list b
extern LinkList list_comm(LinkList a, LinkList b);
extern void list_seperate_by_odd_and_even(LinkList list, LinkList a, LinkList b);
//remove all duplicated element in list
extern void list_remove_duplicated(LinkList list);
//merge two list and order by desc
extern LinkList list_merge_by_desc(LinkList a, LinkList b);
//merge two list by comm element
extern LinkList list_merge_comm(LinkList a, LinkList b);
extern void list_interaction(LinkList a, LinkList b);
//if list b is list a's subsequence return true, else return false
extern bool list_is_subsequence(LinkList a, LinkList b);
//visit the last N node
extern int list_408_lastN(LinkList list, int k);
//
extern void list_408_remove_duplicate(LinkList list, int n);
#endif