#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct elem {
	int ertek;
	elem* kovetkezo;
	elem* elozo;
}elem_t;

void felszabadit(elem_t* fej){
	if(fej == NULL){
		printf("Nem szabadítok fel nullpointert!\n");
		return;
	}
	elem_t* utolso = fej;
	else{
		while(utolso->kovetkezo!=NULL)
			utolso = utolso->kovetkezo;
		while(utolso != fej){
			utolso = utolso->elozo;
			free(utolso->kovetkezo);
		}
		free(fej);
		printf("Sikeres felszabadítás!\n\n");
		return;
	}
}

// bemenete egy láncolt lista farka és a hozzáfűzendő elem
// kimenete a hozzáfűzés utáni farok
elem_t* hozzafuz(elem_t* farok, int ujErtek){
	if(farok==NULL){
		printf("Nem fűzök hozzá nullpointerhez!\n");
		return NULL;
	}
	else{
		farok->kovetkezo = (elem_t*)malloc(sizeof(elem_t));
		farok->kovetkezo->elozo = farok;
		farok->kovetkezo->kovetkezo = NULL;
		farok = farok->kovetkezo;
		return farok;
	}
}

int main(){
	bool lehetPrim;
	int hatar;
	int counter=1;
	elem_t* aktualElemPtr;
	void szemet;
	
	// linkelt lista feje és farka, vagyis első és utolsó eleme
	felem_t* fejPtr, farokPtr;
       	fejPtr = (elem_t*) malloc(sizeof(elem_t));
	farokPtr = fejPtr;
	
	printf("Határ: "); // felső határérték beolvasása
	szemet = (void)scanf("%d",&hatar);

	printf("\n\nPrímek %d-ig:\n\n", &hatar); // prímek felsorolása
	if(hatar > 1)
		printf("1.  2\n");

	for(int i=3; i<hatar; i+=2){
		lehetPrim=true;
		aktualElemPtr = fejPtr;
		while(aktualElemPtr != NULL && lehetPrim){
			
			aktualElemPtr = aktualElemPtr->kovi;
		}
		if(lehetPrim){
			counter++;
			printf("%d.  %d\n",counter,i);
		}
	}
	// felszabadítás
	felszabadit(fejPtr);
	return 0;
}
