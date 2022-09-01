#include "push_swap.h"

void	sa(stack *a, int size)
{
	int	tmp;

	if (size < 1)
		return ;
	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
}
