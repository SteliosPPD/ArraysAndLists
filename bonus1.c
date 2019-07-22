/*

Give the 3rd dimension (N) of the array: 5
The matrix is :
a b c d e
f g h i j
k l m n o
p q r s t
b c d e f
g h i j k
l m n o p
q r s t u
c d e f g
h i j k l
m n o p q
r s t u v
 

*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	char *array[3][4];
	int i, j, k, N;
	char input[12];
	char gramma = 'a';
	
	printf("Give the 3rd dimension (N) of the array: ");
	scanf("%s", input);
	
	N = atoi(input);
	
	while (N < 2){
		printf("Lathos eisodos!\n");
		scanf("%s", input);	
		N = atoi(input);
	}
	
	for (i = 0 ; i < 3 ; i++){
		for (j = 0 ; j < 4 ; j++){
			array[i][j] = (char*)malloc(sizeof(char) * N);
			if (array[i][j] == NULL){
				printf("malloc error\n");
				return 1;
			}
		}	
	}

	for (i = 0 ; i < 3 ; i++){
		gramma = 'a' + i;
		for (j = 0 ; j < 4 ; j++){
			for (k = 0 ; k < N ; k++){
				array[i][j][k] = gramma++;
			}
		}
	}
	
	for (i = 0 ; i < 3 ; i++){
		for (j = 0 ; j < 4 ; j++){
			for (k = 0 ; k < N ; k++){
				printf("%c ", array[i][j][k]);
			}
			printf("\n");
		}
		
		printf("\n\n");
	}
	
	for (i = 0 ; i < 3 ; i++){
		for (j = 0 ; j < 4 ; j++){
			free(array[i][j]);
		}
	}
	return 0;
}
