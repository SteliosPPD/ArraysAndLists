/*
	DYNAMIKOI PINAKES (2 DIASTASEON)
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

Gia na kataskevasoume pinakes perissoteron diastasevn the prepei na xrisimopoioume
deiktes se deiktes. Gia pinaka 2 diastseon theloume diplo deiktis, gia pinaka 3 diastseon
theloume triplo deikti kok.

Na grafei programma poy diavazei tis diastaseis N, M enos pinaka akeraion 
pou thelei na apothikefsei o xristis, na kataskevazei ton dinamiko pinaka 
kai sti sinexeia eisagei tous akeraious pou apothikevontai ston pinaka. 
Katopin na tous emfanizei.
*/
#include <stdio.h>
#include <stdlib.h> // malloc free

int main(){
	int** a = NULL;
	int i, j, N, M;
	
	printf("Dose diastaseis pinaka: ");
	scanf("%d%d", &N, &M);
	
	// kataskevi pinaka
	// kataskevi tis protis diastasis
	a = (int**)malloc(sizeof(int*) * N);
	if (a == NULL){ // <----- SOS
		printf("malloc error\n");
		return 1;
	}
	
	// kataskevi defteris diastasis
	for (i = 0 ; i < N ; i++){
		a[i] = (int*)malloc(sizeof(int) * M);
		if (a[i] == NULL){
			printf("malloc error\n");
			return 1;
		}
	}
	
	
	// eisagogi dedomenon
	printf("Dose akeraious: \n");
	for (i = 0 ; i < N ; i++){
		for (j = 0 ; j < M ; j++){
			printf("a[%d][%d] = ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	
	// emfanisi
	printf("Oi akeraioi einai:\n");
	for (i = 0 ; i < N ; i++){
		for (j = 0 ; j < M ; j++){
			printf("\t a[%d][%d] = %d", i, j, a[i][j]);
		}
		printf("\n");
	}
	
	// eleftherosi
	// osa einai ta malloc na einai kai ta free, prepei na ektelountai se adistrofi seira
	for (i = 0 ; i < N ; i++) free(a[i]);
	free(a); // <----- SOS
	return 0;
}