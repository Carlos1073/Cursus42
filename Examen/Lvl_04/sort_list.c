#include "list.h"
 #include <stdio.h>
#include <stdlib.h>

//int ascending(int a, int b)
//{
//	return (a <= b);
//}


t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int tmp;
	t_list *lst_tmp = lst;
	int flag = 1;

	while(flag)
	{
		flag = 0;
		while(lst_tmp && lst_tmp->next)
		{
			if(cmp(lst_tmp->data, lst_tmp->next->data) == 0)
			{
				flag = 1;
				tmp = lst_tmp->data;
				lst_tmp->data = lst_tmp->next->data;
				lst_tmp->next->data = tmp;
			}
			lst_tmp = lst_tmp->next;	
		}
		lst_tmp = lst;
	}
	return(lst);
}



//int	main(void)
//{
//	t_list *a = calloc(1, sizeof(t_list));
//	t_list *b = calloc(1, sizeof(t_list));
//	t_list *c = calloc(1, sizeof(t_list));
//	c->data = 45;
//	b->data = 73;
//	b->next = c;
//	a->data = 108;
//	a->next = b;
//
//printf("\t\tfunc %d\n",ascending(b->data, c->data));
//
//	t_list *cur = a;
//	while(cur)
//	{
//		printf("%d\n", cur->data);
//		cur= cur->next;
//	}
//
//	t_list *res = sort_list(a, ascending);
//	while(res)
//	{
//		printf("\t%d\n", res->data);
//		res = res->next;
//	}
//}
