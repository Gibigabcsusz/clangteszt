#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct elem{
	int ertek;
	struct elem* kovetkezo;
	struct elem* elozo;
}elem;

void felszabadit(elem* fej){
	if(fej == NULL){
		printf("Nem szabadítok fel nullpointert!\n");
		return;
	}
	else{
		int byteSzam=0;
		struct elem* utolso = fej;
		while(utolso->kovetkezo!=NULL){
			utolso = utolso->kovetkezo;
			byteSzam += sizeof(elem);
		}
		while(utolso != fej){
			utolso = utolso->elozo;
			free(utolso->kovetkezo);
		}
		free(fej);
		printf("Sikeres felszabadítás: %d B \n",byteSzam);
		return;
	}
}

// bemenete egy láncolt lista farka és a hozzáfűzendő elem
// kimenete a hozzáfűzés utáni farok
elem* hozzafuz(struct elem* farok, int ujErtek){
	if(farok == NULL){
		farok = (elem*)malloc(sizeof(elem));
		farok->elozo = NULL;
		farok->kovetkezo = NULL;
	}
	else{
		farok->kovetkezo = (elem*)malloc(sizeof(elem));
		farok->kovetkezo->elozo = farok;
		farok->kovetkezo->kovetkezo = NULL;
		farok = farok->kovetkezo;
	}
	farok->ertek = ujErtek;
	return farok;
}

int main(){
	bool lehetPrim;
	int hatar;
	int counter=1;
	struct elem* aktualElemPtr;
	// linkelt lista feje és farka, vagyis első és utolsó eleme
	struct elem *fejPtr, *farokPtr;
       	fejPtr = hozzafuz(NULL, 2);
	farokPtr = fejPtr;
	
	printf("Határ: "); // felső határérték beolvasása
	scanf("%d",&hatar);

	clock_t kezdet = clock();
	printf("\n\nPrímek %d-ig:\n\n", hatar); // prímek felsorolása
	if(hatar > 1)
		printf("1.  2\n");
	for(int i=3; i<=hatar; i+=2){
		lehetPrim = true;
		aktualElemPtr = fejPtr;
		while(aktualElemPtr != NULL && lehetPrim){
			if(i % aktualElemPtr->ertek == 0){
				lehetPrim = false;
			}
			else{
				aktualElemPtr = aktualElemPtr->kovetkezo;
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
	printf("\n");
	felszabadit(fejPtr);
	// időmérés
	clock_t veg = clock();
	double eltelt = (double)(veg-kezdet)/CLOCKS_PER_SEC;
	printf("Futási idő: %f másodperc\n", eltelt);
	
	return 0;
}
