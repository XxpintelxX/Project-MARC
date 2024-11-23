#include "tree.h"

t_node* createNode(int val, int nbsons, int node_depth)
{
    t_node *node = (t_node*) malloc(sizeof(t_node));
    node->value = val;
    node->sons = (t_node**) malloc(sizeof(t_node*) * nbsons);
    node->depth = node_depth;
    node->nbSons = nbsons;
    return node;
}

t_nary_tree createEmptyTree()
{
    t_nary_tree tree;
    tree.root = NULL;
    return tree;
}

t_nary_tree createExTree()
{
    t_nary_tree tree = createEmptyTree(); //       |        0
    tree.root = createNode(0, 2, 1);      //       |      /   |
    t_node* node = tree.root;             //       |     1    2
    node->sons[0] = createNode(1, 1, 2);  //       |   /
    node->sons[1] = createNode(2, 0, 2);  //       |  3
    t_node* node1 = node->sons[0];        //       |
    node1->sons[0] = createNode(3, 0, 3); //       |
    return tree;
}

void displayTree(t_nary_tree tree)
{
    displayNode(tree.root);
}

/*
void displayTree(t_node* root, int level)
{
    if (root == NULL)
        return;

    // Display the right subtree
    displayTree(root->right, level + 1);

    // Print the current node with indentation based on the level
    for (int i = 0; i < level; i++)
        printf("\t");
    printf("%d\n", root->value);

    // Display the left subtree
    displayTree(root->left, level + 1);
}
*/

void displayNode(t_node* node)
{
    if (node == NULL) {
        return; // Base case: if the node is NULL, stop recursion
    }

    // Process the current node (e.g., print its value)
    for (int i = 0; i < node->depth; i++)
        printf("  ");
    printf("Node Value: %d, Depth: %d, Number of Sons: %d\n", node->value, node->depth, node->nbSons);
    // printf("%d ", node->value);

    // Recursively traverse each child node
    for (int i = 0; i < node->nbSons; i++) {
        displayNode(node->sons[i]);
    }
}

int checkNode(t_node* node)
{
    if (node == NULL)
    {
        printf("node is null\n");fflush(stdout);
        return 1;
    }
    if (node->sons == NULL)
    {
        printf("node sons is null\n");fflush(stdout);
        return 1;
    }
    for (int i = 0; i < node->nbSons; i++)
    {
        if (node->sons[i] == NULL)
        {
            printf("node son %d is null", i);fflush(stdout);
            return 1;
        }
    }
    return 0;
}

void insertSons(t_node* node, t_localisation loc, t_map map, t_move move)
{
    const t_move moves[] = { F_10, F_20, F_30, B_10, T_LEFT, T_RIGHT, U_TURN };
    for (int i = 0; i < 7 - node->depth; i++)
    {
        if (moves[i] != move)
        {
            t_node* new_node = createNode(
                                            nextCaseCost(
                                                            newPosition(map, loc, move),
                                                            moves[i],
                                                            map
                                                        ), 
                                            7 - node->depth, 
                                            node->depth+1
                                          );
            if (new_node == NULL)
            {
                printf("new node is null\n");fflush(stdout);
                return;
            }
            node->sons[i] = new_node;
        }
    }
}

void insertNodes(t_nary_tree* tree, t_localisation loc, t_map map)
{
    const t_move moves[] = { F_10, F_20, F_30, B_10, T_LEFT, T_RIGHT, U_TURN };
    tree->root = createNode(
                            whatCost(map, loc.pos),
                            7, 
                            0
                            );
    t_node* node = tree->root;
    insertSons(tree->root, loc, map, -1);
    for (int i = 0; i < 7; i++)
    {
        insertSons(node->sons[i], loc, map, moves[i]);
    }
}

int nextCaseCost(t_localisation loc, t_move move, t_map map)
{
    t_position pos = loc.pos;
    t_orientation dir = loc.ori;
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

int whatCost(t_map map, t_position pos)
{
    return map.costs[pos.y][pos.x];
}

// Function to get the new position after applying a move
t_localisation newPosition(t_map map, t_localisation loc, t_move move)
{
    t_localisation new_loc = loc; // Initialize new_loc with current location

    // Handle movement
    switch (move) {
        case F_10:
        case F_20:
        case F_30: {
            int distance = (move == F_10) ? 10 : (move == F_20) ? 20 : 30;
            // Update position based on orientation
            switch (loc.ori) {
                case WEST: new_loc.pos.y -= distance; break;
                case SOUTH:  new_loc.pos.x += distance; break;
                case EAST: new_loc.pos.y += distance; break;
                case NORTH:  new_loc.pos.x -= distance; break;
            }
            break;
        }
        case B_10: {
            int distance = 10;
            // Update position based on orientation (opposite direction)
            switch (loc.ori) {
                case WEST: new_loc.pos.y += distance; break;
                case SOUTH:  new_loc.pos.x -= distance; break;
                case EAST: new_loc.pos.y -= distance; break;
                case NORTH:  new_loc.pos.x += distance; break;
            }
            break;
        }
        // case T_LEFT: {
        //     // Turn left (+90 degrees)
        //     new_loc.ori = (loc.ori == NORTH) ? WEST : (t_orientation)(loc.ori - 1);
        //     break;
        // }
        // case T_RIGHT: {
        //     // Turn right (-90 degrees)
        //     new_loc.ori = (loc.ori == WEST) ? NORTH : (t_orientation)(loc.ori + 1);
        //     break;
        // }
        // case U_TURN: {
        //     // U-turn (180 degrees)
        //     new_loc.ori = (loc.ori + 2) % 4;
        //     break;
        // }
        default:
            // Invalid move, return the current location
            return loc;
    }

    // Boundary check
    if (new_loc.pos.x < 0 || new_loc.pos.x >= map.x_max ||
        new_loc.pos.y < 0 || new_loc.pos.y >= map.y_max) {
        printf("Warning: Move would place robot out of bounds. Ignoring.\n");
        return loc; // Return original position if out of bounds
    }

    // Update the cost of the move based on soil
    t_soil current_soil = map.soils[new_loc.pos.y][new_loc.pos.x];
    int move_cost = map.costs[new_loc.pos.y][new_loc.pos.x];

    if (_soil_cost[current_soil] == 10000) {
        printf("Warning: Move would place robot on impassable terrain. Ignoring.\n");
        return loc; // Return original position if terrain is impassable
    }

    return new_loc;
}