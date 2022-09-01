#include "push_swap.h" 

void	print_list(stack *stk)
{
	stack	tmp;

	tmp = *stk;
	ft_printf("\nTOP at Start: %d\n", (*stk)->value);
	ft_printf("[ %s", GOLD);
	while (tmp->next)
	{
		ft_printf("%d %s", tmp->value, RESET);
		tmp = tmp->next;
	}
	ft_printf("]");
	ft_printf("\nTOP at Finish: %d\n\n", (*stk)->value);
	ft_printf("List size: %d\n", ft_stack_size(stk)); 
}

int	main(int argc, char *argv[])
{
	stack	a;
	stack	b;
	size_t	size;

	a = NULL;
	if (argc <= 1)
		print_error_arguments();
	a = build_stack(argc - 1, argv);
	b = NULL;
	size = ft_stack_size(&a);


	print_list(&a);
	ft_printf("Popped %s%d%s from the stack.\n", B_RED,pop(&a), RESET);
	ft_printf("Popped %s%d%s from the stack.\n", B_RED,pop(&a), RESET);
	ft_printf("Popped %s%d%s from the stack.\n", B_RED,pop(&a), RESET);

	sa(&a, size);

	print_list(&a);
	return (0);
}

