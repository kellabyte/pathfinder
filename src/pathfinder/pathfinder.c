#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "art.h"
#include "pathfinder.h"

struct pathfinder
{
    art_tree tree;
};

int pf_create(pathfinder** context)
{
    pathfinder* context_t = calloc(1, sizeof(pathfinder));
    int rc = art_tree_init(&context_t->tree);
    if (rc != 0)
        return -1;
    
    *context = context_t;
    return 0;
}

void pf_free(pathfinder* context)
{
    art_tree_destroy(&context->tree);
}

int pf_set(pathfinder* context, unsigned char* path, int path_length, void* value)
{
    art_insert(&context->tree, path, path_length, value);
    return 0;
}

int pf_find(pathfinder* context, unsigned char* path, int path_length, void** value)
{
    *value = art_search(&context->tree, path, path_length);
    return 0;
}

PATHFINDER_EXTERN pf_result* pf_match(pathfinder* context, unsigned char* path, int path_length)
{
    
}
