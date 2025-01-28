/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
using namespace std;

/* Add a prototype for a helper function here if you need */
void push_back(Node*& linkedlist, Node*& node);

// 1) if head of the original ll is empty -> return
// 2) else, set head of og ll as temporary
// 3) move og head to point to next element
// 4) check the value at temp either odd or even
// 5) set temp->next to nulptr
// 6) push_back to the corresponding list
// 7) call recursive split again
void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  if (in==nullptr) {
    return;
  }
  Node* temp = in;
  in = in->next;
  temp->next = nullptr;
  if (temp->value%2==0){
    push_back(evens, temp);
  }
  else {
    push_back(odds, temp);
  }
  split(in, odds, evens);
}

/* If you needed a helper function, write it here */
// push_back function, works like a normal push_back but using recursive method
void push_back(Node*& linkedlist, Node*& node) {
  if (linkedlist==nullptr){
    linkedlist = node;
    return;
  }
  if (linkedlist->next == nullptr){
    linkedlist->next = node;
    return;
  }
  else {
    push_back(linkedlist->next, node);
  }
}