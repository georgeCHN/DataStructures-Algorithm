#pragma once
#include"dLoopLinkList.h"
#include<stdio.h>
//if double linklist is symmetry,return true,else return false
extern bool dloop_list_is_symmetry(DLoopLinkList list);
//将b链表合并在a链表，保证合并之后仍然为循环双链表
extern void dloop_list_joint(DLoopLinkList a, DLoopLinkList b);