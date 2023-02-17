#ifndef PUSHSWAP_H
#define PUSHSWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct move{
	int			data;
	struct move	*next;
	struct move	*prev;
}	t_node;

//------------Pushswap.c------------
int		main(int argc, char **argv);
void	sorting_data(t_node **a, t_node **b, t_node **temp);
void	sorting_chunkz(t_node **a, t_node **b, t_node **temp);

//----------innit.c-----------------
void	init_alias(t_node **node, t_node **alias);
void	custom_alias(t_node **alias, int data);
void	init_args(t_node **a, char **argv);
void	init_str(t_node **a, char *str);

//----------utils.c------------------
int		elem_pos(t_node *node, int elem);
int		max_elem(t_node *node);
int		min_elem(t_node *node);
int		list_size(t_node *head);
int		is_sorted(t_node *head);

//-----------chunkz_sorting.c---------
void	small_chunkz_sort(t_node **a, t_node **b, int size);
void	a_to_b(t_node **a, t_node **b, int min, int max);
void	sort_chunkz(t_node **a, t_node **b);
void	medium_chunkz(t_node **a, t_node **b);
void	big_chungus(t_node **a, t_node **b);

//-----------sort.c-------------------
void	sort4two(t_node **a);
void	sort4three(t_node **a);
void	sort4threept2(t_node **a);

//----------sort2.c-------------------
void	sort4four(t_node **a, t_node **b);
void	sort4four2(t_node **a, t_node **b, int position);
void	sort4four3(t_node **a, t_node **b);
void	sort4more(t_node **a, t_node **b);
void	sort4more2(t_node **a, t_node **b, int n);

//-----------nodes.c------------------
void	free_list(t_node *head);
void	remove_first(t_node **node);
void	to_the_beginning(t_node **head, int data);
void	to_the_back(t_node **head, int data);
void	node_creation(t_node **head, int data);

//------------pushers.c--------------
void	push_a(t_node **a, t_node **b);
void	push_b(t_node **a, t_node **b);

//------------swappers.c-------------
void	swap_a(t_node **a);
void	swap_b(t_node **b);
void	swap_ab(t_node **a, t_node **b);

//-------------rotators.c------------
void	rotate_a(t_node **a);
void	rotate_b(t_node **b);
void	rotate_ab(t_node **a, t_node **b);
void	revrotate_a(t_node **a);
void	revrotate_b(t_node **a);

//-------------ft_split.c------------
int		ft_str_len(const char *str, char c, int *index);
int		ft_str_nbr(const char *str, char c);
char	**ft_split(const char *s, char c);
char	*ft_substr(char const *s, int start, int len);
int		ft_strlen(const char *str);

//-------------ft_atoi2.c-------------
void	freedom(char **split);
int		ft_atoil(char **split, char *str);
int		ft_atoi(const char *str);

//------------errors.c----------------
int		check_sign(char **argv);
int		check_letters(char **argv);
int		check_digit(int c);
int		check_dup(char **argv);
void	check_errors(int argc, char **argv);

//------------errors2.c---------------
int		ft_isalpha(int c);
int		check_sign2(char **argv);
int		check_letters2(char **argv);
int		check_dup2(char **argv);
void	checkpoint(char **argv);

#endif