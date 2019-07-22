/*
	STATIKOI PINAKES
	================
Einai pinakes poy exoun stathero megethos. To megethos tous einai gnosto prin apo tin 
enarksi ektelesis tou programmatos, kai den borei na allazei kata tin ektelesi.

Na grafei programma poy diavazei 5 akeraious kai tous apothikevei se pinaka. Katopin 
tous emfanizei me adistrofi seira
*/
#include <stdio.h>
#define SIZE 5

int main(){
	int a[SIZE];
	int i;
	
	printf("Dose %d akeraious: \n", SIZE);
	for (i = 0 ; i < SIZE; i++){
		printf("a[%d] = ", i);
		scanf("%d", &a[i]);
	}
	
	printf("Oi akeraioi se adistrofi seira einai:\n");
	for (i = SIZE - 1 ; i > -1 ; i--){
		printf("\t a[%d] = %d \n", i, a[i]);
	}

	return 0;
}