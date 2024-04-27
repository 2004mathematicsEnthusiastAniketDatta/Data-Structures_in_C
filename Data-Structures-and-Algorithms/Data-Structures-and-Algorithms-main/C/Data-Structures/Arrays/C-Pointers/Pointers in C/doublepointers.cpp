#include <stdio.h>
int main(){
	int a=1000;
	int *ptr;
	ptr= &a;
	int **doubleptr;
	doubleptr=&ptr;
	printf("%d \n",ptr); //address of a
	printf("%d \n",&ptr); //address of ptr
	printf("%d \n",doubleptr);//address of ptr
	printf("%d \n",*doubleptr);//address of a
	printf("%d \n",**doubleptr);//value of a
}
