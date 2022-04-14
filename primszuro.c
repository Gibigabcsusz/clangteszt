#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(){
	bool prim;
	int hatar;
	int counter=0;
	printf("Határ: ");
	scanf("%d",&hatar);
	printf("\n\nprímek:\n\n");
	for(int i=3; i<hatar; i+=2){
		prim=true;
		for(int j=2;j<i;j++){
			if(i%j==0)
				prim=false;
		}
		if(prim){
			counter++;
			printf("%d.  %d\n",counter,i);
		}
	}
	return 0;
}
