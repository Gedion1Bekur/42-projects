/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linklist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbekur <gbekur@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 19:15:20 by gbekur            #+#    #+#             */
/*   Updated: 2026/06/28 22:55:58 by gbekur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct			node
{
	int			data;
	struct node	*link;
};
// there must be alwa

void	count_of_nodes(struct node *head)
{
	int			count;
	struct node	*ptr;

	count = 0;
	if (head == NULL)
	{
		printf("single linked list is empty");
		return ;
	}
	ptr = head;
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->link;
	}
	printf("linked list count : %d\n", count);
}

// best was printing data in linked list

void	add_at_end(struct node *head, int data)
{
	struct node *ptr, *temp;
	ptr = head;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;
	while (ptr->link != NULL)
	{
		ptr = ptr->link;
	}
	ptr->link = temp;
}

void	node_printer(struct node *head)
{
	struct node	*ptr;

	ptr = head;
	while (ptr != NULL)
	{
		printf("%d here\n", ptr->data);
		ptr = ptr->link;
	}
}

int	main(void)
{
	struct node *head = NULL;
	head = (struct node *)malloc(sizeof(struct node));
	head->data = 50;
	head->link = NULL;
	struct node *currnet = malloc(sizeof(struct node));
	currnet->data = 51;
	currnet->link = NULL;
	head->link = currnet;

	currnet = malloc(sizeof(struct node));
	currnet->data = 52;
	currnet->link = NULL;

	head->link->link = currnet;

	currnet = malloc(sizeof(struct node));
	currnet->data = 53;
	currnet->link = NULL;
	head->link->link->link = currnet;
	;

	printf("/*********************/\n");
	add_at_end(head, 55);
	add_at_end(head, 100);
	node_printer(head);
	count_of_nodes(head);
	// struct node *current = malloc(sizeof(struct node));

	// current->data = 51;
	// current->link = NULL;

	// head->link = current;

	// struct node *third = malloc(sizeof(struct node));

	// third->data = 52;
	// third->link = NULL;
	// struct node *forth = malloc(sizeof(struct node));

	// forth->data = 53;
	// forth->link = NULL;

	// third->link = forth;

	// current->link = third;

	// node insertion at end node

	// printf("%d\n", head->data);
	// printf("%p\n", head->link);

	// printf("%d\n", head->link->link->data);
	// printf("%p\n", head->link->link->link);

	// printf("%d\n", currnet->data);
	// printf("%p\n", currnet->link);
	// // printf("%p\n", third->link);
	// // printf("%d\n",forth->data);
	// // printf("%p\n", forth->link);

	return (0);
}