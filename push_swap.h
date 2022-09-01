#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "colortag.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
} t_node;

typedef t_node * stack;

int		push(stack *stk, int value);
int		pop(stack *stk);
stack	build_stack(int size, char *elements[]); 

void	print_error_arguments(void);

size_t	ft_stack_size(stack *stk);

void	sa(stack *a, int size);

#endif
