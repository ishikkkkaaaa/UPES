//<<<< Default function argument >>>

//C++ allows a function to assign a parameter a default value when no argument
//corresponding to that parameter is specified in a call to that function.

//The default value is specified in a manner syntactically
//similar to a variable initialization.

#include<iostream>
using namespace std;

void default_fun(int a = 100);

int main(){
	default_fun();
	default_fun(200);
}

void default_fun(int a){
	cout<<a<<endl;
}
