#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

//Structure of the Node
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

void Display()
{
 if ( isempty() )
  cout<<"Stack is Empty";
 else
 {
  Node *temp=top;
  while(temp!=NULL)
  {   cout<<temp->data<<" ";
   temp=temp->link;
  }
  cout<<endl;
 }
 }

int main() {
    auto start_time = high_resolution_clock::now();
    Push(8);
    Push(10);
    Push(11);
    Push(15);
    Push(23);
    Push(6);
    Push(18);
    Push(20);
    Push(17);
    Display();
    Pop();
    Pop();
    Pop();
    Pop();
    Pop();
    Display();
    Push(4);
    Push(30);
    Push(1);
    Display();
    auto end_time = high_resolution_clock::now();
    auto execution_time = duration_cast<microseconds>(end_time - start_time);
    cout << "Execution time: " << execution_time.count() << " us" << endl;
    return 0;
}
