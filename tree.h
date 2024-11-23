#ifndef _TREE_H_
#define _TREE_H_

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "map.h"
#include "moves.h"

typedef struct s_node
{
    int value;
    int depth;
    int nbSons;
    struct s_node** sons;
}t_node;

typedef struct s_nary_tree
{
    t_node *root;
}t_nary_tree;

t_nary_tree createExTree();
t_nary_tree createEmptyTree();
t_node* createNode(int val, int nbsons, int node_depth);
int nextCaseCost(t_localisation loc, t_move move, t_map map);
void insertNodes(t_nary_tree* tree, t_localisation loc, t_map map);
void insertSons(t_node* node, t_localisation loc, t_map map);
void displayTree(t_nary_tree tree);
void displayNode(t_node* node);
int whatCost(t_map map, t_position pos);

#endif