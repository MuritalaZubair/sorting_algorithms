#ifndef DECK_H
#define DECK_H

#include <stdlib.h>

/* Suit definitions */
#define SPADES   0
#define HEARTS   1
#define CLUBS    2
#define DIAMONDS 3

/**
 * enum kind_e - Enumeration of card suits.
 * @SPADE: Spades suit
 * @HEART: Hearts suit
 * @CLUB: Clubs suit
 * @DIAMOND: Diamonds suit
 */
typedef enum kind_e
{
	SPADE = SPADES,
	HEART = HEARTS,
	CLUB = CLUBS,
	DIAMOND = DIAMONDS
} kind_t;

/**
 * struct card_s - Represents a playing card.
 * @value: Value of the card (e.g., "Ace", "2", "3", ..., "King")
 * @kind: Suit of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Node in a doubly-linked list of cards.
 * @card: Pointer to the card data
 * @prev: Pointer to the previous node in the list
 * @next: Pointer to the next node in the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

/* Function prototype */
void sort_deck(deck_node_t **deck);

#endif /* DECK_H*/
