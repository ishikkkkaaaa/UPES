#include<iostream>
using namespace std;

void multiplication(int A1[2][2],int A2[2][2],int A3[2][2]){
	static int i=0,j=0,k=0;
	if(i>=2)
		return;
	if(j<2){
		if(k>2){
			A3[i][j]+=A1[i][k]*A2[k][j];
			k++;
			multiplication(A1,A2,A3);
		}
		k=0;
		j++;
		multiplication(A1,A2,A3);
	}
	j=0;
	i++;
	multiplication(A1,A2,A3);
}

int main(){
	int A1[2][2],A2[2][2],A3[2][2]={0};
	cout<<"Enter the elements for matrix-1: "<<endl;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			cin>>A2[i][j];
	cout<<"Enter the elements for matrix-2: "<<endl;
	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++)
			cin>>A2[i][j];
	cout<<"Matrix-1: "<<endl;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++)
		cout<<A1[i][j]<<" ";
	cout<<endl;
	}
	cout<<"Matrix-2: "<<endl;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++)
		cout<<A2[i][j]<<" ";
	cout<<endl;
	}
	multiplication(A1,A2,A3);
	cout<<"Matrix after multiplication: "<<endl;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++)
		cout<<A3[i][j]<<" ";
	cout<<endl;
	}
}
