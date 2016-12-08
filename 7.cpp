#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
    int value;
    struct tree *left;
    struct tree *right;
} tree;

void deep (int x, tree *t) {
    if (!x) {
        printf("%d ", t -> value);
        return;
    }
    if (t -> left != NULL) {
        deep(x - 1, t -> left);
    }
    if (t -> right != NULL) {
        deep(x - 1, t -> right);
    }
}

void freemem(tree *t)
{
    if (t -> left != NULL) {
        freemem(t -> left);
    }
    if (t -> right != NULL) {
        freemem(t -> right);
    }
    free(t);
    return;
}

int
main ()
{
    int x, f = 0;
    scanf("%d", &x);
    if (!x) {
        return 0;
    }
    tree *t = (tree*)malloc(sizeof(tree));
    t->left = NULL;
    t -> right = NULL;
    t -> value = x;
    scanf("%d", &x);
    while (x) {
        f = 0;
        tree *t1 = t, *t2 = t;
        while (t1 != NULL) {
            t2 = t1;
            if (x == t1 -> value) {
                f = 1;
                scanf("%d", &x);
                break;
            }
            if (x < t1 -> value) {
                t1 = t1 ->left;
            } else {
                t1 = t1 -> right;
            }
        }
        if (f == 1) {
            continue;
        }
        t1 = (tree*)malloc(sizeof(tree));
        t1->left = NULL;
        t1 -> right = NULL;
        t1 -> value = x;
        if (x < t2 -> value) {
            t2 -> left = t1;
        } else {
            t2 -> right = t1;
        }
        scanf("%d", &x);
    }
    scanf("%d", &x);
    deep(x, t);
    freemem(t);
    return 0;
}
