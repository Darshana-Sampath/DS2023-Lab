#include <iostream>

using namespace std;

int stack[10], n = 10, top = -1;

void Push(int val){
    if (top >= n-1){
        cout << "Stack Overflow";
    }
    else{
        top +=1;
        stack[top] = val;
    }
}
void Pop(){
    if (top == -1){
        cout << "Stack Underflow"; 
    }
    else{
        //cout << "Poped value is " << stack[top]<<endl;
        top--;
    }
}
int main(){
	return 0;
}