#include "push_swap.h"

stack	build_stack(int size, char *elements[])
{
	int	i;
	stack			stk;

	ft_printf("\n%s>>> Building a list with %d elements: <<<%s\n", B_TEAL, size, RESET);
	stk = (stack)malloc(sizeof(t_node));
	if (stk == NULL)
		return (0);
	i = 1;
	while (i <= size)
	{
		push(&stk, ft_atoi(&elements[i][0]));
		i++;
	}
	return (stk);
}

int	push(stack *stk, int value)
{
	t_node	*newstk;

	newstk = (t_node *)malloc(sizeof(t_node));
	if (newstk == NULL)
		return (1);
	newstk->value = value;
	newstk->next = *stk;
	*stk = newstk;
	return (0);
}

int	pop(stack *stk)
{
	int		result;
	t_node	*tmp;

	if ((*stk)->next == 0)
		return (-1);
	result = (*stk)->value;
	tmp = *stk;
	*stk = (*stk)->next;
	free(tmp);
	return (result);
}
