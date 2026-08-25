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

/* Add a prototype for a helper function here if you need */
void addTarget(Node*& linkedList, Node*& target);   // prototype

void split(Node*& in, Node*& odds, Node*& evens){
  /* Add code here */
  // WRITE YOUR CODE HERE
  if (in == nullptr) return;

  Node* nextNode;
  if (in != nullptr) nextNode = in -> next;
  else nextNode = nullptr;


  if (((in -> value) % 2) == 0){ // current is even
    if (evens == nullptr){
      evens = in; 
      evens -> next = nullptr;
    }
    else addTarget(evens, in);
  }
  else{ // current is odd
    if (odds == nullptr){
      odds = in;
      odds -> next = nullptr;
    }
    else addTarget(odds, in);
  }
  in = nullptr;
  return split(nextNode, odds, evens);
}

/* If you needed a helper function, write it here */


void addTarget(Node*& linkedList, Node*& target){
  if (linkedList -> next == nullptr){
    linkedList -> next = target;
    linkedList -> next -> next = nullptr;
    return;
  }
  return addTarget(linkedList -> next, target);
}

