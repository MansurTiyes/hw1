/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
using namespace std;
#include <iostream>

int main(int argc, char* argv[])
{
    // new ll created (delete at the end)
    Node* ll = new Node(1, nullptr);
   for (size_t i = 2; i < 11; i++)
   {
    Node* node1 = new Node(i, nullptr);
    push_back(ll, node1);
   }
   Node* odds = nullptr;
   Node* evens = nullptr;
   split(ll, odds, evens);
   delete ll;
   Node* temp = odds;
   while(temp!=nullptr){
    cout << temp->value << endl;
    temp = temp->next;
   }
   temp = evens;
   while(temp!=nullptr){
    cout << temp->value << endl;
    temp = temp->next;
   }
   temp = odds;
   while(temp!=nullptr){
    Node* temp1 = temp;
    temp = temp->next;
    delete temp1;
   }
   temp = evens;
   while(temp!=nullptr){
    Node* temp2 = temp;
    temp = temp->next;
    delete temp2;
   }
}
