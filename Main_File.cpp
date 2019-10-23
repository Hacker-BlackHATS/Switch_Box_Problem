// Roll. no. : 18/94089 and 18/94092
// Objective : Switch Box Routing
/*
PROBLEM STATEMENT :: 

[+]In the switch box routing problem, we are given a rectangular routing region with pins at the periphery. Pairs of pins are to be connected together by laying a metal path between the two pins. This path is confined to the routing region and is called a wire. If two wires intersect, an electrical short occurs. So wire intersections are forbidden. Each pair of pins that is to be connected is called a net. We are to determine whether the given nets can be routed with no intersections.

(*)(In practice, we also require a minimum separation between adjacent wires. We ignore this additional requirement here.)
Our problem is to input a switch box routing instance and determine whether it is routable.

<*>In this program i had assumed that the number of pins is even and that each pin has only one net number.
*/

#include<iostream>
#include"Stack.h"		// Incliding Stack.h header file
using namespace std;
class Switch{
	public:
		int **ptr,*arr;
		int n;
		Stack st;
	public:

		// Default Constructor
		Switch(){
			n = 0;
			st.size = n;
			ptr = new int*[n];
			arr = new int[n];
			for(int i =0 ; i<n;i++){
				ptr[i] = new int[2];
			}
		}

		// Parameterised Constructor
		Switch(int size){
			n = size;
			st.size = n;
			ptr = new int*[n];
			arr = new int[n];
			for(int i =0 ; i<n;i++){
				ptr[i] = new int[2];
			}
		}

		// Taking Input
		void input(){
			cout<<"Enter the pairs of pin ::\n";
			for(int i = 0; i<n/2;i++){
				cin>>ptr[i][0]>>ptr[i][1];
			}cout<<endl;
			for(int j =1;j<=n;j++){
				arr[j-1] = j;
			}
		}

		// Checking whether the wires are intersecting or not
		void check(){
			bool flag = true;
			for(int i = 0; i  < n ; i++){
				int a = st.peek();
				if(!isPair(a,arr[i])){
					st.push(arr[i]);
					flag = false;
				}
				else{
					int k=st.pop();
					flag = true;
				}
			}
			if(!st.isEmpty() || !flag){
				cout<<"Unroutable...\n";
			}
			else{
				cout<<"Routable...\n";
			}
		}

		// Checking whether pins are in pair or not
		bool isPair(int x,int y){
			for(int i= 0; i <n/2;i++){
				if((ptr[i][0] == x || ptr[i][0] == y)&&(ptr[i][1] == x || ptr[i][1] == y)){
					return true;
				}
			}
			return false;
		}
		// Destructor
		~Switch(){
			delete ptr;
			delete arr;
		}
};

// MAin
int main(){
	int s;
	cout<<"Enter the number of pins : ";
	cin>>s;
	Switch obj(s);
	obj.input();
	obj.check();
	return 0;
}
