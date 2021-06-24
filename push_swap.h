#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define SUCCESS				0
# define FAIL					1
# define ERROR_MALLOC			2
# define INVALID_ARG			3
# define ENTER_ARGUMENT			4
# define DUPLICATE_SYMBOLS		6
# define NOT_ENOUGH_ELEMENTS	7
# define ALREADY_SORTED			8

# define B_INT_MAX				2147483647
# define B_INT_MIN				-2147483648l
# define B_UINT64_MAX			18446744073709551615u
# define B_INT64_MAX			922337203685477580ul
# define B_INT64_MIN			-922337203685477580
# define MINUS					1
# define MINIMUM_NUM_ARGS		2

# define NOT_SORTED				0

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

# define KEEP_IN		1
# define MOVE			0

typedef unsigned long long		t__uint64_b;
typedef long long int			t__int64_b;
typedef int						t__int_b;

typedef struct s_stack
{
	t__int_b		value;
	t__int_b		order;
	t_bool			keep_in;
	struct s_stack	*up;
	struct s_stack	*down;
}				t_stack;

typedef struct s_commands
{
	char				*command;
	struct s_commands	*next;
}				t_commands;

typedef struct s_base
{
	t_stack			*stack_a;
	t__int64_b		head;
	t_stack			*stack_b;
	t_commands		*cmds;
	int				(*method)(t_stack *, t__int_b *);
	int				(*pairs)(t_stack *, t_stack *);
}				t_base;

typedef struct s_teps
{
	t__int_b	rr;
	t__int_b	rrr;
	t__int_b	rra;
	t__int_b	rrb;
	t__int_b	ra;
	t__int_b	rb;
	t__int_b	res;
	t__int_b	order;
}				t_steps;

/*-------------------------ADDING INFO-------------------------*/

t__int_b		add_command(t_commands **cmds, char *command);
t__int_b		check_for_sorted(t_stack *stack);
t__int_b		add_number_to_stack(t_stack **stack, t__int64_b num);
t__int_b		argtoi(char **argv, t_base *base);
t__int_b		sorting_two_three(t_base *base);
t__int_b		get_count_nums(t_stack *stack);
t__int_b		edit_keep_in(t_base *base);
t__int_b		keep_in_index(t_stack *stack, t__int_b head, t_base *base);
t__int_b		keep_in_gt(t_stack *stack, t__int_b head);
t__int_b		max_order_stack(t_stack *stack);
t__int_b		gt_method(t_stack *a, t__int_b *index);
t__int_b		count_pairs_gt(t_stack *stack, t_stack *start);

/*------------------------CALCULATING-------------------------*/

t__int_b		sort_five(t_base *base);
t__int_b		perform_move(t_base *base);
t_bool			prepare_sa(t_base *base);
t__int_b		perform_sa(t_base *base);
t__int_b		is_sorted(t_stack *stack);
t_bool			find_false_keep(t_stack *stack);
t__int_b		count_true_rule(t_stack *stack);
t_steps			calculate_steps(t_base *base);
t__int_b		find_near_order(t_stack *stack, t__int_b target);
t__int_b		add_rr_step(t__int_b *ib, t__int_b *ia, t_steps *step);
t__int_b		add_rrr_step(int *ib, int *ia, t_steps *step, t_base *base);
t__int_b		add_rx(int *addr_rx, int *iter);
t__int_b		add_rrx(t__int_b *addr, int *count, int *iter);
t__int_b		find_head_index(t_stack *stack, t_base *base);
t__int_b		find_head_gt(t_stack *stack);
t__int_b		count_pairs_index(t_stack *stack, t_stack *start);
t__int_b		index_method(t_stack *a, t__int_b *index);

/*----------------------------UTILS----------------------------*/

int				write_error(int ret);
void			b_print_stack(t_stack *stack);
char			*b_strdup(const char *src);
void			b_bzero(void *s, t__uint64_b n);
t_stack			*get_last(t_stack *stack);
void			print_commands(t_commands *cmds);
size_t			ft_strlen(const char *s);
int				get_next_line(int fd, char **line);

/*--------------------------COMMANDS---------------------------*/

t__int_b		b_ra(t_stack **stack_a, t_commands **cmds);
t__int_b		b_rb(t_stack **stack_a, t_commands **cmds);
t__int_b		b_rrb(t_stack **stack_a, t_commands **cmds);
t__int_b		b_rra(t_stack **stack_a, t_commands **cmds);
t__int_b		b_rr(t_stack **stack_a, t_stack **stack_b, t_commands **cmds);
t__int_b		b_rrr(t_stack **stack_a, t_stack **stack_b, t_commands **cmds);
t__int_b		b_pa(t_stack **stack_a, t_stack **stack_b, t_commands **cmds);
t__int_b		b_pb(t_stack **stack_a, t_stack **stack_b, t_commands **cmds);
t__int_b		b_sa(t_stack **stack_b, t_commands **cmds);
t__int_b		b_sb(t_stack **stack_b, t_commands **cmds);

/*------------------------COMMANDS LOW-------------------------*/

t__int_b		b_reverse_rotate(t_stack **stack);
t__int_b		b_swap(t_stack *stack);
t__int_b		b_push(t_stack **stack_from, t_stack **stack_into);
t__int_b		b_rotate(t_stack **stack);

#endif
