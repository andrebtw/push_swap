#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_list
{
    int             value;
    struct s_list   *next;
} t_list;

// fn -> creer maillon: param: int;
// fn -> lstlast: tant que next
// fn -> addback: param: new

t_list  *lstlast(t_list *lst)
{
    while (lst->next)
    {
        lst = lst->next;
    }
    return (lst);
}

t_list *createlst(int value)
{
    t_list  *r_list;

    r_list = malloc (sizeof(t_list));
    if (!r_list)
        return (NULL);
    r_list->value = value;
    r_list->next = NULL;
    return (r_list);
}

void    addback(t_list **lst, t_list *new)
{
    t_list  *tmp = *lst;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    tmp->next = new;
}

int main ()
{
    t_list  *list;

    list = createlst(5);
    printf("%d", list->value);
    addback(&list, createlst(6));
    list = list->next;
    printf("%d", list->value);
}
