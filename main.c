#include <stdio.h>
#include "map.h"
#include "loc.h"
#include "tree.h"

int main() {
    t_map map = createMapFromFile("maps/example1.map");
    // printf("Map created with dimensions %d x %d\n", map.y_max, map.x_max);

    // displayMapSoils(map);

    // displayMap(map);

    // printf the costs, aligned left 5 digits

    displayMapCosts(map);

    // t_nary_tree tree = createExTree();
    // displayTree(tree);

    t_nary_tree tree = createEmptyTree();
    t_position pos;
    pos.x = 4;
    pos.y = 0;
    t_orientation ori = SOUTH;
    t_localisation loc;
    loc.ori = ori;
    loc.pos = pos;
    printf("\n");
    printf("pos.x : %d | pos.y : %d\n", pos.x, pos.y);
    printf("\n");
    insertNodes(&tree, loc, map);
    displayTree(tree);


    /*t_position pos;
    pos.x = 2;
    pos.y = 2;
    printf("Cost : %d\n", map.costs[pos.x][pos.y]);
    t_orientation ori;
    t_move move;
    for (int i = 0; i < 4; i++)
    {
        ori = i;
        switch (ori)
        {
        case NORTH:
            printf("\n--- NORTH ---\n\n");
            break;
        case EAST:
            printf("\n--- EAST ---\n\n");
            break;
        case SOUTH:
            printf("\n--- SOUTH ---\n\n");
            break;
        case WEST:
            printf("\n--- WEST ---\n\n");
            break;
        
        default:
            break;
        }
        for (int j = 0; j < 7; j++)
        {
            move = j;
            switch (move)
            {
            case F_10:
                printf("- Forward 10 -\n");
                break;
            case F_20:
                printf("- Forward 20 -\n");
                break;
            case F_30:
                printf("- Forward 30 -\n");
                break;
            case B_10:
                printf("- Backward 10 -\n");
                break;
            case T_LEFT:
                printf("- Turn right -\n");
                break;
            case T_RIGHT:
                printf("- Turn right -\n");
                break;
            case U_TURN:
                printf("- U turn -\n");
                break;
            default:
                break;
            }
            printf("Next cost : %d\n", nextCaseCost(pos, ori, move, map));
        }
    }*/

    return 0;
}
