#include <stdio.h>
#include <stdlib.h>

struct			node
{
	int			data;
	struct node	*link;
};

struct node	*add_node_end(struct node *ptr, int data)
{
	struct node	*temp;

	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->link = NULL;
	ptr->link = temp;
	return (temp);
}

int	main(void)
{
	struct node *head = (struct node *)malloc(sizeof(struct node));
	head->data = 20;
	head->link = NULL;

	struct node *ptr = head;
    
	ptr = add_node_end(ptr, 25);
	ptr = add_node_end(ptr, 30);
	ptr = add_node_end(ptr, 40);
    ptr = add_node_end(ptr, 50);
    
	ptr = head;

	while (ptr != NULL)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->link;
	}
	return (0);
}