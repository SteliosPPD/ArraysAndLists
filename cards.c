#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle( int [][ 13 ] );
void deal( const int [][ 13 ], const char *[], const char *[] );

int main(){
	const char *suit[ 4 ] = {"Hearts", "Diamonds", "Clubs", "Spades"};
	const char *face[ 13 ] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	int deck[ 4 ][ 13 ] = {0};

	srand(time(NULL));

	shuffle( deck );
	deal( deck, face, suit );

	return 0;
}

void shuffle( int wDeck[][ 13 ] ){
	int row, column, card;
	for ( card = 1; card <= 52; card++ ) {
		do {
			row = rand() % 4;
			column = rand() % 13;
		} while( wDeck[ row ][ column ] != 0 );
		wDeck[ row ][ column ] = card; /* the numbers 1-52 are randomly placed into the deck array */
	}
}

void deal( const int wDeck[][ 13 ], const char *wFace[], const char *wSuit[] ){
	int card, row, column;

	for ( card = 1; card <= 52; card++ )

		for ( row = 0; row <= 3; row++ )

			for ( column = 0; column <= 12; column++ )

				/* searches deck for the card number, then prints the face and suit. */
				/* uses card % 2 == 0 ? '\n' : '\t' to change lines after printing 2 cards, or put tab after printing 1st card*/
				if ( wDeck[ row ][ column ] == card )	printf( "%5s of %-8s%c", wFace[ column ], wSuit[ row ],	card % 2 == 0 ? '\n' : '\t' );
}
