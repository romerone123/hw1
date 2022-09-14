#include "split.h"
#include <iostream>
#include <cstddef> 
using namespace std;

void print(Node*& in)
{
  while(in != NULL)
  {
    cout << in->value << endl;
    in = in->next;
  }
}

int main()
{
  Node* in = NULL;  
  Node in2(7, NULL);
  Node in3(6, &in2);
  Node in4(5, &in3);
	Node in5(4, &in4);
	Node in6(3, &in5);
  Node in7(2, &in6);
  Node in8(1, &in7);
  in = &in8; 
  


  Node* odds = NULL;
  Node* evens = NULL;
  //Node* temp = NULL;

  split(in, odds, evens);
  cout << "Odd linked list:" << endl;
  print(odds); 
  cout << "Even linked list:" << endl;
  print(evens); 
  
  return 0;
}
