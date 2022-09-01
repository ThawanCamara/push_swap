#include "push_swap.h"

size_t	ft_stack_size(stack *stk)
{
	size_t	size;
	stack	tmp;

	size = 0;
	tmp = *stk;
	while ((tmp)->next)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
