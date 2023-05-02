#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *link;
};
Node *top = NULL;

bool isempty()
{
 if(top == NULL)
 return true; else
 return false;
}
void Push (int value)
{
  Node *ptr = new Node();
  ptr->data = value;
  ptr->link = top;
  top = ptr;
}

void Pop ( )
{
 if ( isempty() )
  cout<<"Stack is Empty";
 else
 {
  Node *ptr = top;
  top = top -> link;
  delete(ptr);
 }
}
int main() {
    return 0;
}
