#include <stdio.h>
int main(){
	int a1=0,a2=1,a3,i,temp;
	for(i=0;i<20;i++){
		a3=a1+a2;
		printf("%d ",a1);
		temp=a2;
		a2=a3;
		a1=temp;
	}
}
