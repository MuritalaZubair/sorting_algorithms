#include <stdio.h>
#include <string.h>
#include "deck.h"

/**
 * get_value - Get the numeric value of a card for sorting.
 * @card: The card to evaluate.
 *
 * Return: The numeric value of the card (2 for "2" up to 13 for "King").
 */
int get_value(const card_t *card)
{
	if (strcmp(card->value, "Ace") == 0)
		return (1);
	if (strcmp(card->value, "2") == 0)
		return (2);
	if (strcmp(card->value, "3") == 0)
		return (3);
	if (strcmp(card->value, "4") == 0)
		return (4);
	if (strcmp(card->value, "5") == 0)
		return (5);
	if (strcmp(card->value, "6") == 0)
		return (6);
	if (strcmp(card->value, "7") == 0)
		return (7);
	if (strcmp(card->value, "8") == 0)
		return (8);
	if (strcmp(card->value, "9") == 0)
		return (9);
	if (strcmp(card->value, "10") == 0)
		return (10);
	if (strcmp(card->value, "Jack") == 0)
		return (11);
	if (strcmp(card->value, "Queen") == 0)
		return (12);
	if (strcmp(card->value, "King") == 0)
		return (13); /* For King */
	return (0);
}

/**
 * get_kind - Get the suit (kind) value for sorting.
 * @card: The card to evaluate.
 *
 * Return: An integer value representing the suit of the card.
 */
int get_kind(const card_t *card)
{
	if (card->kind == SPADES)
		return (0);
	if (card->kind == HEARTS)
		return (1);
	if (card->kind == CLUBS)
		return (2);
	return (3); /* DIAMONDS */
}

/**
 * insertion_sort_deck_kind - Sort the deck by suit (kind) in ascending order.
 * @deck: A pointer to the head of the deck.
 */
void insertion_sort_deck_kind(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *temp;

	for (iter = (*deck)->next; iter != NULL; iter = temp)
	{
		temp = iter->next;
		insert = iter->prev;
		while (insert != NULL && get_kind(insert->card) > get_kind(iter->card))
		{
			/* Swap nodes */
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * insertion_sort_deck_value - Sort the deck by card value in ascending order.
 * @deck: A pointer to the head of the deck.
 */
void insertion_sort_deck_value(deck_node_t **deck)
{
	deck_node_t *iter, *insert, *temp;

	for (iter = (*deck)->next; iter != NULL; iter = temp)
	{
		temp = iter->next;
		insert = iter->prev;
		while (insert != NULL &&
			get_kind(insert->card) == get_kind(iter->card) &&
			get_value(insert->card) > get_value(iter->card))
		{
			/* Swap nodes */
			insert->next = iter->next;
			if (iter->next != NULL)
				iter->next->prev = insert;
			iter->prev = insert->prev;
			iter->next = insert;
			if (insert->prev != NULL)
				insert->prev->next = iter;
			else
				*deck = iter;
			insert->prev = iter;
			insert = iter->prev;
		}
	}
}

/**
 * sort_deck - Sort a deck of cards from Ace to King and from Spades to Diamonds.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
	if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
		return;

	insertion_sort_deck_kind(deck);
	insertion_sort_deck_value(deck);
}
