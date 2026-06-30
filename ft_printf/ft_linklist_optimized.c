#include <stdio.h>
#include <stdlib.h>

struct			node
{
	int			data;
	struct node	*link;
};

struct node	*add_end_node(struct node *ptr, int end_data)
{
	struct node	*temp;

	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = end_data;
	temp->link = NULL;
	ptr->link = temp;
	return (temp);
}

int	main(void)
{
	struct node *head = (struct node *)malloc(sizeof(struct node));
	head->data = 10;
	head->link = NULL;

	struct node *ptr = head;
	ptr = add_end_node(ptr, 20);
	ptr = add_end_node(ptr, 30);
	ptr = add_end_node(ptr, 40);

	ptr = head;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->link;
	}
	return (0);
}