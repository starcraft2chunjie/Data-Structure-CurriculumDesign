#include <stdio.h>
#include "tree.h"
#include <malloc.h>
#include <string.h>

int max(int l, int r){
    return l > r ? l : r;
}


int initAVL(AVLnode *t){
    t->data = 0;
    t->leftnode = NULL;
    t->rightnode = NULL;
    return SUCCESS;
}

AVLnode *copy(AVLnode *t, AVLnode *h){
    if(t != NULL){
        h = copy(t->leftnode, h);
        h = copy(t->rightnode, h);
        h = InsertAVL(h, t->data);
    }
    return h;
}

AVLnode * newNode(int data, AVLnode * L){
    AVLnode *node = (AVLnode *)malloc(sizeof(AVLnode));
    node->data = data;
    node->leftnode = NULL;
    node->rightnode = NULL;
    L = node;
    return node;
}

int height(AVLnode *t){
    if(t == NULL){
        return 0;
    }
    else{
        return max(height(t->leftnode), height(t->rightnode)) + 1;
    }

}

void DestroyAVL(AVLnode *t){
    if (t != NULL){
        DestroyAVL(t->leftnode);
        DestroyAVL(t->rightnode);
        free(t);
    }
}

AVLnode * SearchAVL(int data, AVLnode *t){
    if(t == NULL){
        return NULL;
    }
    else if(data < t->data){
        return(SearchAVL(data, t->leftnode));
    }
    else if(data > t->data){
        return(SearchAVL(data, t->rightnode));
    }
    else{
        return t;
    }
}

AVLnode *single_rotate_with_left(AVLnode *k2){
    AVLnode *k1 = NULL;
    k1 = k2->leftnode;
    k2->leftnode = k1->rightnode;
    k1->rightnode = k2;
    return k1;
}

AVLnode *single_rotate_with_right(AVLnode *k1){
    AVLnode *k2 = NULL;
    k2 = k1->rightnode;
    k1->rightnode = k2->leftnode;
    k2->leftnode = k1;
    return k2;
}

AVLnode *double_rotate_with_left(AVLnode *k3){
    k3->leftnode = single_rotate_with_right(k3->leftnode);
    return single_rotate_with_left(k3);
}

AVLnode *double_rotate_with_right(AVLnode *k3){
    k3->rightnode = single_rotate_with_left(k3->rightnode);
    return single_rotate_with_right(k3);
}

int getbalance(AVLnode *t){
    if(t == NULL){
        return 0;
    }
    else{
        return height(t->leftnode) - height(t->rightnode);
    }
}

AVLnode *InsertAVL(AVLnode *t, int key){
    /*perform the normal BST rotation*/
    if(t == NULL){
        t = (AVLnode *)malloc(sizeof(AVLnode));
        t->data = key;
        t->leftnode = NULL;
        t->rightnode = NULL;
        return t;
    }
    if(key < t->data){
        t->leftnode = InsertAVL(t->leftnode, key);
    }
    else if(key > t->data){
        t->rightnode = InsertAVL(t->rightnode, key);
    }
    else{
        printf("The key has existed!");
        return t;
    }

    /*get the balance factor this ancestor node to check whether this node became unbalanced*/
    int balance = getbalance(t);
    //if this node becomes unbalanced, then there are four cases
    //left left case
    if(balance > 1 && key < t->leftnode->data){
        return single_rotate_with_left(t);
    }
    //right right case
    if(balance < -1 && key > t->rightnode->data){
        return single_rotate_with_right(t);
    }
    //left right case
    if(balance > 1 && key > t->leftnode->data){
        return double_rotate_with_left(t);
    }
    //right left case
    if(balance < -1 && key < t->rightnode->data){
        return double_rotate_with_right(t);
    }
    return t;
}


/* Given a non-empty binary search tree, return the
   node with minimum key value found in that tree.
   Note that the entire tree does not need to be
   searched. */
AVLnode * minValueNode(AVLnode* node)
{
    AVLnode* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->leftnode != NULL)
        current = current->leftnode;
    return current;
}


/*Recursive function to delete a node with given key
from subtree with given root. It returns root of the 
modified subtree*/
AVLnode *DeleteAVL(int data, AVLnode *t){
    if(t == NULL){
        printf("the node doesn't exist");
        return t;
    }
    else if(data < t->data){
        t->leftnode = DeleteAVL(data, t->leftnode);
    }
    else if(data > t->data){
        t->rightnode = DeleteAVL(data, t->rightnode);
    }
    else{
        //node with only one child or no child
        if((t->leftnode == NULL) || (t->rightnode == NULL)){
            AVLnode *temp = t->leftnode? t->leftnode:t->rightnode;
            //No child case
            if(temp == NULL){
                temp = t;
                t = NULL;
            }
            else{//one child case
                *t = *temp; //copy the contents of the non-empty child
                free(temp);
            }
        }
        //node with two children: get the inorder successor(smallest in the right subtree)
        else{
            AVLnode *temp = minValueNode(t->rightnode);
            //Copy the inorder successor's data to this node
            t->data = temp->data;
            t->rightnode = DeleteAVL(temp->data, t->rightnode);
        }
    }

    //If the tree had only one node than return
    if(t == NULL){
        return t;
    }
    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = getbalance(t);
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && getbalance(t->leftnode) >= 0)
        return single_rotate_with_left(t);
 
    // Left Right Case
    if (balance > 1 && getbalance(t->leftnode) < 0)
    {
        return double_rotate_with_left(t);
    }
 
    // Right Right Case
    if (balance < -1 && getbalance(t->rightnode) <= 0)
        return single_rotate_with_right(t);
 
    // Right Left Case
    if (balance < -1 && getbalance(t->rightnode) > 0)
    {
        return double_rotate_with_right(t);
    }
 
    return t;
}

void TraverseAVL(AVLnode * t){
    if(t == NULL){
        return;
    }
    TraverseAVL(t->leftnode);
    TraverseAVL(t->rightnode);
    printf("%d\t", t->data);
}

void pre_traverseAVL(AVLnode * t){
    if(t == NULL){
        return;
    }
    printf("%d\t", t->data);
    pre_traverseAVL(t->leftnode);
    pre_traverseAVL(t->rightnode);
}

void in_traverseAVL(AVLnode * t){
    if(t == NULL){
        return;
    }
    in_traverseAVL(t->leftnode);
    printf("%d\t", t->data);
    in_traverseAVL(t->rightnode);
}



int num_node(AVLnode * t, int num){
    if(t == NULL){
        return num;
    }
    num = num_node(t->leftnode, num);
    num = num_node(t->rightnode, num);
    num += 1;
    return num;
}

AVLnode * unflat(AVLnode * P, int *list, int num){
    for(int i = 0; i < num; i++){
        P = InsertAVL(P, list[i]);
    }
    return P;
}









