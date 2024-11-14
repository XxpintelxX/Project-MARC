#ifndef _TREE_H_
#define _TREE_H_

#include <stddef.h>
#include <stdlib.h>
#include "map.h"
#include "moves.h"

typedef struct s_node
{
    int value;
    int depth;
    struct s_node** sons;
}t_node;

typedef struct s_nary_tree
{
    t_node *root;
}t_nary_tree;

t_nary_tree createEmptyTree();
t_node* createNode(int val, int sons);
int nextCaseCost(t_position pos, t_orientation dir, t_move move, t_map map);

#endif