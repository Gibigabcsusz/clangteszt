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
	farok->kovetkezo = (elem_t*)malloc(sizeof(elem_t));
	farok->kovetkezo->elozo = farok;
	farok->kovetkezo->kovetkezo = NULL;
	farok = farok->kovetkezo;
	return farok;
}

int main(){
	bool lehetPrim;
	int hatar;
	int counter=1;
	elem_t* aktualElemPtr;
	void szemet;
	
	// linkelt lista feje és farka, vagyis első és utolsó eleme
	felem_t* fejPtr, farokPtr;
       	fejPtr = hozzafuz((elem_t*)NULL, 2);
	farokPtr = fejPtr;
	
	printf("Határ: "); // felső határérték beolvasása
	szemet = (void)scanf("%d",&hatar);

	printf("\n\nPrímek %d-ig:\n\n", &hatar); // prímek felsorolása

	for(int i=3; i<hatar; i+=2){
		lehetPrim = true;
		aktualElemPtr = fejPtr;
		while(aktualElemPtr != NULL && lehetPrim){
			if(i % aktualElemPtr->ertek == 0){
				lehetPrim = false;
			}
			else{
				aktualElemPtr = aktualElemPtr->kovi;
			}
		}
		// ha prím a vizsgált szám
		if(lehetPrim){
			counter++;
			farokPtr = hozzafuz(farokPtr, i);
			printf("%d.  %d\n",counter,i);
		}
	}
	// felszabadítás
	felszabadit(fejPtr);
	return 0;
}
