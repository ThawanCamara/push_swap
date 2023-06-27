/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 10:24:57 by tde-souz          #+#    #+#             */
/*   Updated: 2022/10/17 18:04:37 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define TRUE 1
# define FALSE 0
# define A 0
# define B 1
# define DEBUG 0

enum e_direction
{
	TOP = 0,
	BOT = 1
};

typedef struct s_picker
{
	int			size;
	int			abs_pos;
	int			cur_pos;
	int			steps;
	int			dir;
}	t_picker;

typedef struct s_stack
{
	int				value;
	int				size;
	int				abs_pos;
	int				init_pos;
	int				cur_pos;
	struct s_stack	*tail;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

void	push_swap(char **input);
void	three_sort(t_stack **stk);

char	**input_parse(int argc, char *argv[]);
int		check_doubles(char **input);
void	input_clear(char **input);
void	input_validchars(int argc, char *argv[]);

t_stack	*build_stack(t_stack *stk, char **input);
void	destroy_stack(t_stack **stk);
t_stack	*push(t_stack *stk, int value);
t_stack	*pop(t_stack *stk);
int		get_greater(t_stack *stk);
int		get_greater_above(t_stack *stk, int value);
int		get_lesser(t_stack *stk);
int		get_lesser_above(t_stack *stk, int value);
void	set_abs_position(t_stack **stk);
void	update_cur_position(t_stack **stk);
void	set_init_position(t_stack **stk);
void	remove_init_position(t_stack **stk);
void	insert_init_position(t_stack **stk);

int		order_check(t_stack *stk);
int		get_closest_prob(t_stack **stk);
int		get_closest_limit(t_stack **stk, int limit);
int		get_magnitude(t_stack *stk, t_stack **stks);
int		*get_cheapest(t_stack **stk);
void	picker(t_stack **stk, int val_a, int val_b);
void	swapper(t_stack **stk);
int		get_steps(int cur_pos, int size);
int		get_shortcut(t_picker **src, t_picker **dst);

void	pa(t_stack **stk);
void	pb(t_stack **stk);
void	sa(t_stack **stk);
void	sb(t_stack **stk);
void	ss(t_stack **stk);
void	ra(t_stack **stk);
void	rb(t_stack **stk);
void	rr(t_stack **stk);
void	rra(t_stack **stk);
void	rrb(t_stack **stk);
void	rrr(t_stack **stk);

#endif
