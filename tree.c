#include "tree.h"

t_node* createNode(int val, int nbsons)
{
    t_node *node = malloc(sizeof(t_node));
    node->value = val;
    node->sons = malloc(sizeof(t_node*) * nbsons);
    return node;
}

t_nary_tree createEmptyTree()
{
    t_nary_tree tree;
    tree.root = NULL;
    return tree;
}

void insertSons(t_node* node, int val, int depth, int i)
{
    for (int i = 0; i < 9-depth; i++)
    {
        t_node* new_node = createNode(val, 9-depth);
        node->sons[i] = new_node;
    }
}

void insertNodes(t_nary_tree* tree, t_position pos, t_map map, int depth)
{
    const t_move moves[] = { F_10, F_20, F_30, B_10, T_LEFT, T_RIGHT, U_TURN };
    for (int i = 0; i < 9; i++)
    {
        insertNode(tree->root, 0, i, i);
    }
}

int nextCaseCost(t_position pos, t_orientation dir, t_move move, t_map map)
{
    switch (move)
    {
        case F_10:
            switch (dir)
            {
                case SOUTH:
                    if (pos.x+1 > map.x_max)
                        return -1;
                    return map.costs[pos.x+1][pos.y];
                    break;
                case EAST:
                    if (pos.y+1 > map.y_max)
                        return -1;
                    return map.costs[pos.x][pos.y+1];
                    break;
                case NORTH:
                    if (pos.x-1 < 0)
                        return -1;
                    return map.costs[pos.x-1][pos.y];
                    break;
                case WEST:
                    if (pos.y-1 < 0)
                            return -1;
                        return map.costs[pos.x][pos.y-1];
                    break;
                default:
                    break;
            }
            break;
        case F_20:
            switch (dir)
            {
                case SOUTH:
                    if (pos.x+2 > map.x_max)
                        return -1;
                    return map.costs[pos.x+2][pos.y];
                    break;
                case EAST:
                    if (pos.y+2 > map.y_max)
                        return -1;
                    return map.costs[pos.x][pos.y+2];
                    break;
                case NORTH:
                    if (pos.x-2 < 0)
                        return -1;
                    return map.costs[pos.x-2][pos.y];
                    break;
                case WEST:
                    if (pos.y-2 < 0)
                            return -1;
                        return map.costs[pos.x][pos.y-2];
                    break;
                default:
                    break;
            }
            break;
        case F_30:
            switch (dir)
            {
                case SOUTH:
                    if (pos.x+3 > map.x_max)
                        return -1;
                    return map.costs[pos.x+3][pos.y];
                    break;
                case EAST:
                    if (pos.y+3 > map.y_max)
                        return -1;
                    return map.costs[pos.x][pos.y+3];
                    break;
                case NORTH:
                    if (pos.x-3 < 0)
                        return -1;
                    return map.costs[pos.x-3][pos.y];
                    break;
                case WEST:
                    if (pos.y-3 < 0)
                            return -1;
                        return map.costs[pos.x][pos.y-3];
                    break;
                default:
                    break;
            }
            break;
        case B_10:
            switch (dir)
            {
                case SOUTH:
                    if (pos.x-1 < 0)
                        return -1;
                    return map.costs[pos.x-1][pos.y];
                    break;
                case EAST:
                    if (pos.y-1 < 0)
                        return -1;
                    return map.costs[pos.x][pos.y-1];
                    break;
                case NORTH:
                    if (pos.x+1 > map.y_max)
                        return -1;
                    return map.costs[pos.x+1][pos.y];
                    break;
                case WEST:
                    if (pos.y+1 > map.x_max)
                            return -1;
                        return map.costs[pos.x][pos.y+1];
                    break;
                default:
                    break;
            }
            break;
        case T_LEFT:
            return map.costs[pos.x][pos.y];
            break;
        case T_RIGHT:
            return map.costs[pos.x][pos.y];
            break;
        case U_TURN:
            return map.costs[pos.x][pos.y];
            break;

        default:
            break;
    }
}