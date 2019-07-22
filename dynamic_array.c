/*
	DYNAMIKOI PINAKES (MONODIASTATOI)
	=================================
Einai pinakes poy DEN exoun stathero megethos. To megethos tous einai agnosto prin apo tin 
enarksi ektelesis tou programmatos, kai borei na allazei kata tin ektelesi.

Gia tin kataskevi dinamikon pinakon xreiazomaste deiktes.

void* malloc(size_t): zitame na ekxorithei mnimi sti RAM megethous size_t bytes se 
	sinexomenes theseis mnimis. An i malloc apotixei mas epistrefei NULL, allios mas
	epistrefei tin diefthinsi tis protis theseis pou exei ekxorithei.
	
	char *str = (char*)malloc(sizeof(char) * (strlen("Hello") + 1));
	
	H malloc epistrefei deikti tipou void*. O tipos aftos deikti einai eidikos kai borei 
	na deixnei se otidipote. Omos iparxei asimfonia tipon se sxesi me ton deikti str
	poy exei tipo char*. Gia na to diorthosoume prepei na kanoume typecast opote grafoume
	
	char* str = (char*)malloc(... )

Na grafei programma poy diavazei to plithos ton akeraion pou thelei na apothikefsei o
xristis, kataskevazei dinamiko pinaka toson theseon kai sti sinexeia eisagei tous
akeraious pou apothikevontai ston pinaka. Katopin tous emfanizei me adistrofi seira.
*/
#include <stdio.h>
#include <stdlib.h> // malloc free

int main(){
	int* a = NULL;
	int i, N;
	
	printf("Dose plithos akeraion: ");
	scanf("%d", &N);
	
	// kataskevi pinaka
	a = (int*)malloc(sizeof(int) * N);
	if (a == NULL){ // <----- SOS
		printf("malloc error\n");
		return 1;
	}
	
	// eisagogi dedomenon
	printf("Dose %d akeraious: \n", N);
	for (i = 0 ; i < N; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	
	printf("Oi akeraioi se adistrofi seira einai:\n");
	for (i = N - 1 ; i > -1 ; i--){
		printf("\t a[%d] = %d \n", i, a[i]);
	}

	free(a); // <----- SOS
	return 0;
}