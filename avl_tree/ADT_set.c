#include <stdio.h>
#include <malloc.h>
#include "tree.h"

ADT *set_init(ADT *Q){
    Q = (ADT *)malloc(sizeof(ADT));
    Q->data = 0;
    Q->t = NULL;
    return Q;
}

int set_destroy(ADT *Q){
    DestroyAVL(Q->t);
    return SUCCESS;
}

ADT *set_insert(ADT *Q, int data){
    Q->t = InsertAVL(Q->t, data);
    return Q;
}

ADT *set_remove(ADT *Q, int data){
    Q->t = DeleteAVL(data, Q->t);
    return Q;
}

AVLnode * set_intersection(ADT *Q, ADT *T){
    AVLnode *h = NULL;
    h = intersection(Q->t, T->t, h);
    return h;
}


AVLnode * intersection(AVLnode *t, AVLnode *p, AVLnode *h){
    if(t != NULL){
        h = intersection(t->leftnode, p, h);
        h = intersection(t->rightnode, p, h);
        if(SearchAVL(t->data, p) == NULL){
            return h;
        }
        else{
            if(height(h) == 0){
                h = InsertAVL(h, SearchAVL(t->data,p)->data);
            }
            else{
                h = InsertAVL(h ,SearchAVL(t->data, p)->data);
            }
            return h;
        }
    }
    return h;
}

AVLnode * delete_group(AVLnode * t, AVLnode * p){
    if(p != NULL){
        t = delete_group(t, p->leftnode);
        t = delete_group(t, p->rightnode);
        t = DeleteAVL(p->data, t);
    }
    return t;
}

AVLnode * set_delete_group(ADT * Q, ADT * T){
    Q->t = delete_group(Q->t, T->t);
    return Q->t;
}

AVLnode *set_union(ADT *Q, ADT *T){
    AVLnode *h = NULL;
    if(Q != NULL){
        h = copy(Q->t, h);
    }
    h = unions(T->t, h);
    return h;
}


AVLnode *unions(AVLnode *p, AVLnode *h){
    if(p != NULL){
        h = unions(p->leftnode, h);
        h = unions(p->rightnode, h);
        if(SearchAVL(p->data, h) == NULL){
            if(height(h) == 0){
                h = InsertAVL(h, p->data);
            }
            else{
                h = InsertAVL(h, p->data);
            }
            return h;
        }
        else{
            return h;
        }
    }
    return h;
}

AVLnode *set_difference(ADT *Q, ADT *T){
    AVLnode * P1 = set_union(T, Q);
    AVLnode * P2 = set_intersection(T, Q);
    AVLnode *h = NULL;
    h = copy(P1, h);
    difference(P2, h);
    return h;
}

AVLnode * difference(AVLnode *P2, AVLnode *h){
    if(P2 != NULL){
        h = difference(P2->leftnode, h);
        h = difference(P2->rightnode, h);
        h = DeleteAVL(P2->data, h);
        return h;
    }
    return h;
}

int set_size(ADT *Q){
    int num = size(Q->t);
    return num;
}

int size(AVLnode *p){
    if(p != NULL){
        return size(p->leftnode) + size(p->rightnode) + 1;
    }
    else{
        return 0;
    }
}

int set_member(ADT *Q, int data){
    AVLnode * P = SearchAVL(data, Q->t);
    if(P == NULL){
        return 0;
    }
    else{
        return 1;
    }
}

int member(AVLnode *P, int data, int h){
    if(P != NULL){
        h = member(P->leftnode, data, h);
        h = member(P->rightnode, data, h);
        if(P->data == data){
            h++;
        }
    }
    return h;
}

//To tell if Q is the subset of T
int set_subset(ADT *Q, ADT *T){
    int h = subset(Q->t, T->t);
    if(h == set_size(Q)){
        return 1;
    }
    else{
        return -1;
    }
}

int subset(AVLnode *P, AVLnode *H){
    int h = 0;
    if(P == NULL){
        return 0;
    }
        return subset(P->leftnode, H) + subset(P->rightnode, H) + member(H, P->data, h);
}

int set_equal(ADT *Q, ADT *T){
    if(set_subset(Q, T) == 1 && set_size(Q) == set_size(T)){
        return 1;
    }
    else{
        return 0;
    }
}


int flat(AVLnode * P, int * list, int num){
    if(P == NULL){
        return num;
    }
    num = flat(P->leftnode, list, num);
    num = flat(P->rightnode, list, num);
    num += 1;
    list[num - 1] = P->data;
    return num;
}
















