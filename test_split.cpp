/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

void print(Node*& in)
{
  while(in != NULL)
  {
    std::cout << in->value << std::endl;
    in = in->next;
  }
}

int main(int argc, char* argv[])
{
	Node* in = nullptr;  
 /* Node in2(7, nullptr);
  Node in3(6, &in2);
  Node in4(5, &in3);
	Node in5(4, &in4);
	Node in6(3, &in5);
  Node in7(2, &in6);
  Node in8(1, &in7);*/
	Node in8(1, nullptr);
  in = &in8; 

  Node* odds = nullptr;
  Node* evens = nullptr;

  split(in, odds, evens);
  std::cout << "Odd linked list:" << std::endl;
  print(odds); 
  std::cout << "Even linked list:" << std::endl;
  print(evens); 
  std::cout << "in: " << std::endl;
	print(in);
  return 0;
}
