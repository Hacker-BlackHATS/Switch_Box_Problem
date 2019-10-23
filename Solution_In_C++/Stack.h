//Roll no. : 18/94089
//Objective : Implementation of stack using pointer
#include<iostream>
using namespace std;
class Stack{
	public:
		int *arr;
		int top,size;
	public:
		Stack(){
			size=5;
			arr = new int [size];
			top=-1;
		}
		Stack(int n){
			size=n;
			arr = new int [size];
			top=-1;
		}
		bool isEmpty(){
			return top == -1;
		}
		void push(int ele){
			if(top>=size-1){
				cout<<"Stack Overflow!!!\n";
			}
			else{
				arr[++top]=ele;
			}
		}
		int pop(){
			if(top<0){
				return -1;
			}
			else{
				return arr[top--];
			}
		}
		int peek(){
			if(top<0){
				return -1;
			}
			return arr[top];
		}
};


