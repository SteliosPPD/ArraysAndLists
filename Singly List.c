/*
		LISTES
		======
Otan den gnorizoume to plithos ton stoixeion pou theloume na 
apothikefsoume apo tin arxi den boroume na kataskevasoume 
dinamikous pinakes, giati tha prepei na kanoume malloc gia
sigekrimeno plithos stoixeion. Stis periptoseis aftes prepei
na xrisimopoiisoume listes. Stis listes boroume na prosthetoume
osous komvous theloume, otn to theloume.

Stis listes kathe komvos exei toulaxiston 1 deikti pou deixnei 
ston epomeno komvo tis listas. Gia paradeigma:

	struct human{
		char* onoma;
		char epitheto[45];
		
		struct human* next; <---- deiktis pou deixnei ston epomeno komvo
	};
	
Gia na theoroume oti gorizoume ta stoixeia mias listas arkei na gnorizoume
ti thesi tou protou stoixeiou tis listas pou onomazetai kefali (head).

Iparxoun 4 vasikoi tipoi listas:
	1. APLH GRAMMIKH: kathe komvos exei enan deikti next pou deixnei sto
		epomeno stoixeio tis listas. O teleftaios komvos deixnei me ton 
		deikti next se NULL.
	2. DIPLH GRAMMIKH: kathe komvos exei enan deikti next pou deixnei sto
		epomeno stoixeio tis listas kai enan deikti previous pou deixnei 
		ston proigoumeno komvo tis listas. O protos komvos (head) deixnei 
		me ton deikti previous se NULL kai o teleftaios komvos deixnei me
		ton deikti next se NULL.
	3. APLH KIKLIKH: kathe komvos exei enan deikti next pou deixnei sto
		epomeno stoixeio tis listas. O teleftaios komvos deixnei me ton 
		deikti next ston proto komvo (head) kai etsi kleinei o kiklos.
	4. DIPLH KIKLIKH: kathe komvos exei enan deikti next pou deixnei sto
		epomeno stoixeio tis listas kai enan deikti previous pou deixnei 
		ston proigoumeno komvo tis listas. O protos komvos (head) deixnei 
		me ton deikti previous ston teleftaio okmvo kai o teleftaios komvos 
		deixnei me ton deikti next ston proto komvo (head) tis listas kai 
		etsi kleinei o kiklos.
		
Na grafei programma pou diavazei ta stoixeia atomon kai ta apothikevei se
APLH GRAMMIKH lista. Telos emfanizei ta stoixeia sti lista.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct human{
	char *onoma;
	char epitheto[45];
	
	struct human* next;
};		

struct human* insert2tail(struct human* head, char *onoma, char *epitheto){
	struct human *tail;
	
	// kataskevi neou komvou
	struct human *neosKomvos = (struct human*)malloc(sizeof(struct human));
	if (neosKomvos == NULL){
		printf("malloc error\n");
		return head;
	}
	
	// apothikefsi neon stoixeion ston neo komvo
	neosKomvos->onoma = strdup(onoma); // malloc + strcpy
	strcpy(neosKomvos->epitheto, epitheto);
	
	neosKomvos->next = NULL;
	
	// eisagogi neou komvou sto TELOS tis listas
	// 1. i lista einai keni
	if (head == NULL){
		head = neosKomvos;
		return head;
	}
	// 2. iparxei 1 stoixeio sti lista (head)
	else if (head->next == NULL){
		head->next = neosKomvos;
		return head;
	}
	// 3.  iparxei lista  me perissotera stoixeia
	else {
		// prepei na vro to teleftaio stoixeio tis listas
		tail = head;
		
		// prepei na metavo ston teleftaio komvo
		while (tail->next != NULL) tail = tail->next;
		
		tail->next = neosKomvos;
		
		return head;
	}
}
struct human* insert2head(struct human* head, char *onoma, char *epitheto){
	struct human *tail;
	
	// kataskevi neou komvou
	struct human *neosKomvos = (struct human*)malloc(sizeof(struct human));
	if (neosKomvos == NULL){
		printf("malloc error\n");
		return head;
	}
	
	// apothikefsi neon stoixeion ston neo komvo
	neosKomvos->onoma = strdup(onoma); // malloc + strcpy
	strcpy(neosKomvos->epitheto, epitheto);
	
	neosKomvos->next = NULL;
	
	// eisagogi neou komvou sto TELOS tis listas
	// 1. i lista einai keni
	if (head == NULL){
		head = neosKomvos;
		return head;
	}
	// 2. iparxei 1 stoixeio sti lista (head)
	/*else if (head->next == NULL){
		neosKomvos->next = head;
		head = neosKomvos;
		return head;
	}*/
	// 3.  iparxei lista me perissotera stoixeia
	else {
		neosKomvos->next = head;
		head = neosKomvos;
		return head;
	}
}
void print_list(struct human * head){
	struct human* d;
	
	if (head == NULL){
		printf("empty list\n");
		return;
	}
	else if (head->next == NULL){
		printf("%s %s \n", head->onoma, head->epitheto);
		return;
	}
	else {
		d = head;
		
		while (d != NULL){
			printf("%s %s \n", d->onoma, d->epitheto);
			d = d->next;
		}
	}
}
void free_list(struct human* head){
	struct human *pre, *post;
	
	if (head == NULL){
		return;
	}
	else if (head->next == NULL){
		free(head);
		return;
	}
	else {
		pre = head;
		post = head->next;
		
		while(post = NULL){
			free(pre);
			pre = post;
			post = post->next;
		}
	}
}
int main(){
	struct human* head = NULL;
	char onoma[45], epitheto[45];
	
	do {
		printf("Dose onoma atomou (termatismos me 'end'): ");
		scanf("%s", onoma);
		
		if (strcmp(onoma, "end") != 0) {
			printf("Dose to epitheto: ");
			scanf("%s", epitheto);
			
			//head = insert2tail(head, onoma, epitheto);
			head = insert2head(head, onoma, epitheto);
		}
	}while (strcmp(onoma, "end") != 0);
	
	print_list(head);
	
	// free
	return 0;
}