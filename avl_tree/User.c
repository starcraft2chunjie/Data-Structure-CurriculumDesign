#include "tree.h"
#include <string.h>
#include <malloc.h>


int Init_User(User * T){
    T->ID = 0;
    initAVL(T->Q[0]->t);
    initAVL(T->Q[1]->t);
    initAVL(T->Q[2]->t);
    return SUCCESS;
}


User *Search_User(int ID, User *t){
    if(t == NULL){
        return NULL;
    }
    else if(ID < t->ID){
        return(Search_User(ID, t->leftnode));
    }
    else if(ID > t->ID){
        return(Search_User(ID, t->rightnode));
    }
    else{
        return t;
    }
}

int getbalance_U(User *t){
    if(t == NULL){
        return 0;
    }
    else{
        return User_Height(t->leftnode) - User_Height(t->rightnode);
    }
}

User *Insert_User(User *t, int key){
    /*perform the normal BST rotation*/
    if(t == NULL){
        t = (User *)malloc(sizeof(User));
        t->ID = key;
        strcpy(t->name, "unnamed");
        t->leftnode = NULL;
        t->rightnode = NULL;
        for(int i = 0; i < 3; i++){
            t->Q[i] = (ADT *)malloc(sizeof(ADT));
            t->Q[i]->data = t->ID;
            t->favourate[i] = i + 1;
            t->Q[i]->t = NULL;
        }
        return t;
    }
    if(key < t->ID){
        t->leftnode = Insert_User(t->leftnode, key);
    }
    else if(key > t->ID){
        t->rightnode = Insert_User(t->rightnode, key);
    }
    else{
        printf("The key has existed!");
        return t;
    }

    /*get the balance factor this ancestor node to check whether this node became unbalanced*/
    int balance = getbalance_U(t);
    //if this node becomes unbalanced, then there are four cases
    //left left case
    if(balance > 1 && key < t->leftnode->ID){
        return single_rotate_with_left_U(t);
    }
    //right right case
    if(balance < -1 && key > t->rightnode->ID){
        return single_rotate_with_right_U(t);
    }
    //left right case
    if(balance > 1 && key > t->leftnode->ID){
        return double_rotate_with_left_U(t);
    }
    //right left case
    if(balance < -1 && key < t->rightnode->ID){
        return double_rotate_with_right_U(t);
    }
    return t;

}

User *Insert_User_as(User *t, User * P){
    /*perform the normal BST rotation*/
    if(t == NULL){
        t = P;
        return t;
    }
    if(P->ID < t->ID){
        t->leftnode = Insert_User(t->leftnode, P->ID);
    }
    else if(P->ID > t->ID){
        t->rightnode = Insert_User(t->rightnode, P->ID);
    }
    else{
        printf("The P->ID has existed!");
        return t;
    }

    /*get the balance factor this ancestor node to check whether this node became unbalanced*/
    int balance = getbalance_U(t);
    //if this node becomes unbalanced, then there are four cases
    //left left case
    if(balance > 1 && P->ID < t->leftnode->ID){
        return single_rotate_with_left_U(t);
    }
    //right right case
    if(balance < -1 && P->ID > t->rightnode->ID){
        return single_rotate_with_right_U(t);
    }
    //left right case
    if(balance > 1 && P->ID > t->leftnode->ID){
        return double_rotate_with_left_U(t);
    }
    //right left case
    if(balance < -1 && P->ID < t->rightnode->ID){
        return double_rotate_with_right_U(t);
    }
    return t;

}



/* Given a non-empty binary search tree, return the
   node with minimum key value found in that tree.
   Note that the entire tree does not need to be
   searched. */


User * minValueNode_U(User* node)
{
    User* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->leftnode != NULL)
        current = current->leftnode;
    return current;
}

User * Delete_User_full(User *t, int ID){
    t = Delete_User(t, ID);
    DeleteAVL_other(t, ID);
    return t;
}

int DeleteAVL_other(User *t, int ID){
    if(t != NULL){
        DeleteAVL_other(t->leftnode, ID);
        DeleteAVL_other(t->rightnode, ID);
        for(int i = 0; i < 3; i++){
            AVLnode * P = SearchAVL(ID, t->Q[i]->t);
            if(P != NULL){
                t->Q[i]->t = DeleteAVL(ID, t->Q[i]->t);
            }
        }
        return SUCCESS;
    }
    return -1;
}

User *Delete_User(User *t, int ID){
    if(t == NULL){
        printf("the node doesn't exist");
        return t;
    }
    else if(ID < t->ID){
        t->leftnode = Delete_User(t->leftnode, ID);
    }
    else if(ID > t->ID){
        t->rightnode = Delete_User(t->rightnode, ID);
    }
    else{
        //node with only one child or no child
        if((t->leftnode == NULL) || (t->rightnode == NULL)){
            User *temp = t->leftnode? t->leftnode:t->rightnode;
            //No child case
            if(temp == NULL){
                temp = t;
                t = NULL;
            }
            else{//one child case
                *t = *temp;//copy the contents of the non-empty child
                free(temp);
            }
        }
        //node with two children: get the inorder successor(smallest in the right subtree)
        else{
            User *temp = minValueNode_U(t->rightnode);
            //Copy the inorder successor's data to this node
            t->ID = temp->ID;
            t->rightnode = Delete_User(t->rightnode,temp->ID);
        }
    }

    //If the tree had only one node than return
    if(t == NULL){
        return t;
    }
    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = getbalance_U(t);
    // If this node becomes unbalanced, then there are 4 cases
 
    // Left Left Case
    if (balance > 1 && getbalance_U(t->leftnode) >= 0)
        return single_rotate_with_left_U(t);
 
    // Left Right Case
    if (balance > 1 && getbalance_U(t->leftnode) < 0)
    {
        return double_rotate_with_left_U(t);
    }
 
    // Right Right Case
    if (balance < -1 && getbalance_U(t->rightnode) <= 0)
        return single_rotate_with_right_U(t);
 
    // Right Left Case
    if (balance < -1 && getbalance_U(t->rightnode) > 0)
    {
        return double_rotate_with_right_U(t);
    }
 
    return t;
}

User * newUser(int data){
    User *node = (User *)malloc(sizeof(User));
    node->ID = data;
    node->leftnode = NULL;
    node->rightnode = NULL;
    return node;
}

int User_Height(User *t){
    if(t == NULL){
        return 0;
    }
    else{
        return max(User_Height(t->leftnode), User_Height(t->rightnode)) + 1;
    }

}


User * Insert(User * T, int tag, int data){
    if(T == NULL){
        printf("the ID of user doesn't exist!\n");
        return NULL;
    }
    T->Q[tag-1] = set_insert(T->Q[tag-1], data);
    return T;
}

User * Delete(User *T, int tag, int data){
    T->Q[tag-1] = set_remove(T->Q[tag-1], data);
    return T;
}

int Modify_name(User * T,char name[15]){
        strcpy(T->name, name);
        return SUCCESS;
}

int tell_ind(int *favourate, int F){
    for(int i = 0; i < F; i++){
        for(int j = i+1; j < F; j++){
            if(favourate[i] == favourate[j]){
                return -1;
            }
        }
    }
    return 1;
}

int Modify_favourate(User *T, int order, int content){
    if(T != NULL){
        int j = T->favourate[order - 1];
        T->favourate[order-1] = content;
        if(tell_ind(T->favourate, 3) == -1){
            printf("Don't enter the same hobby!");
            T->favourate[order - 1] = j;
        }
        else{
            printf("Modifying succeed!");
        }
    }
    return SUCCESS;
}

ADT *co_watch(User *T, int ID1, int ID2){
    ADT *P = Search_User(ID1, T)->Q[2];
    ADT *Q = Search_User(ID2, T)->Q[2];
    AVLnode * H = set_intersection(P, Q);
    ADT *Z = (ADT *)malloc(sizeof(ADT));
    Z->t = H;
    Q->data = 0;
    return Z;
}

int co_favourate(User * P, User * Q){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(P->favourate[i] == Q->favourate[j]){
                printf("%d ", P->favourate[i]);
            }
        }
    }
    return SUCCESS;
}

AVLnode *indirect_fri(User *T, User *Q){// Q is the head of a avl tree
    AVLnode * P = T->Q[0]->t;
    ADT *H = (ADT *)malloc(sizeof(ADT));
    ADT *G = (ADT *)malloc(sizeof(ADT));
    G->t = NULL;
    G->data = 0;
    H->t = NULL;
    H->data = 0;
    H->t = indirect(P, Q, H);
    G->t = set_intersection(H, T->Q[0]);
    H->t = set_delete_group(H, G);
    return DeleteAVL(T->ID, H->t);
}

AVLnode *indirect(AVLnode * P, User *T, ADT *H){
    if(P != NULL){
        H->t = indirect(P->leftnode, T, H);
        H->t = indirect(P->rightnode, T, H);
        return (set_union(H, Search_User(P->data, T)->Q[0]));
    }
    else{
        return H->t;
    }
}

User *single_rotate_with_left_U(User *k2){
    User *k1 = NULL;
    k1 = k2->leftnode;
    k2->leftnode = k1->rightnode;
    k1->rightnode = k2;
    return k1;
}

User *single_rotate_with_right_U(User *k1){
    User *k2 = NULL;
    k2 = k1->rightnode;
    k1->rightnode = k2->leftnode;
    k2->leftnode = k1;
    return k2;
}

User *double_rotate_with_left_U(User *k3){
    k3->leftnode = single_rotate_with_right_U(k3->leftnode);
    return single_rotate_with_left_U(k3);
}

User *double_rotate_with_right_U(User *k3){
    k3->rightnode = single_rotate_with_left_U(k3->rightnode);
    return single_rotate_with_right_U(k3);
}

void User_traverse(User *L){
    if(L != NULL){
        User_traverse(L->leftnode);
        User_traverse(L->rightnode);
        printf("%d : %s\n", L->ID,L->name);
    }
}

int User_num(User *L, int num){
    if(L == NULL){
        return num;
    }
    num = User_num(L->leftnode, num);
    num = User_num(L->rightnode, num);
    num += 1;
    return num;
}


User *unflat_User(User * t, User **list, int num){
    for(int i = 0; i < num; i++){
        t = Insert_User_as(t, list[i]);
    }
    return t;
}

int Save(User *L, FILE * filename){
    if(L != NULL){
        Save(L->leftnode, filename);
        Save(L->rightnode, filename);
        fwrite(&(L->ID), sizeof(int), 1, filename);
        fwrite(L->favourate, sizeof(int) * 3, 1, filename);
        fwrite(L->name, sizeof(char) * 15, 1, filename);
        AVLnode * P1 = L->Q[0]->t;
        AVLnode * P2 = L->Q[1]->t;
        AVLnode * P3 = L->Q[2]->t;
        int num1 = num_node(P1, 0);
        int num2 = num_node(P2, 0);
        int num3 = num_node(P3, 0);
        if(num1 != 0){
            int list1[num1];
            flat(P1, list1, 0);
            fwrite(&(num1), sizeof(int), 1, filename);
            fwrite(list1, sizeof(int) * num1, 1, filename);
        }
        else{
            fwrite(&(num1), sizeof(int), 1, filename);
        }
        if(num2 != 0){
            int list2[num2];
            flat(P2, list2, 0);
            fwrite(&(num2), sizeof(int), 1, filename);
            fwrite(list2, sizeof(int) * num2, 1, filename);
        }
        else{
            fwrite(&(num2), sizeof(int), 1, filename);
        }
        if(num3 != 0){
            int list3[num3];
            flat(P3, list3, 0);
            fwrite(&(num3), sizeof(int), 1, filename);
            fwrite(list3, sizeof(int) * num3, 1, filename);
        }
        else{
            fwrite(&(num3), sizeof(int), 1, filename);
        }
    }
    return SUCCESS;
}


int Save_file(User *L, FILE * filename){
    int num = User_num(L, 0);
    fwrite(&(num), sizeof(int), 1, filename);
    Save(L, filename);
    return SUCCESS;
}

User * Load_file(User * L, FILE * filename){
    int num; 
    fread(&(num), sizeof(int), 1, filename);
    User * list[num];
    for(int i = 0; i < num; i++){
        int ID;
        fread(&(ID), sizeof(int), 1, filename);
        L = Insert_User(L, ID);
        User * t = Search_User(ID, L);
        fread(t->favourate, sizeof(int) * 3, 1, filename);
        fread(t->name, sizeof(char) * 15, 1, filename);
        int num1;
        int num2;
        int num3;
        AVLnode * P1 = NULL; 
        AVLnode * P2 = NULL; 
        AVLnode * P3 = NULL;
        fread(&(num1), sizeof(int), 1, filename);
        if(num1 != 0){
            int list1[num1];
            fread(list1, sizeof(int) * num1, 1, filename);
            P1 = unflat(P1, list1, num1);
        }
        fread(&(num2), sizeof(int), 1, filename);
        if(num2 != 0){
            int list2[num2];
            fread(list2, sizeof(int) * num2, 1, filename);
            P2 = unflat(P2, list2, num2);
        }
        fread(&(num3), sizeof(int), 1, filename);
        if(num3 != 0){
            int list3[num3];
            fread(list3, sizeof(int) * num3, 1, filename);
            P3 = unflat(P3, list3, num3);
        }
        t->Q[0]->t = P1;
        t->Q[1]->t = P2;
        t->Q[2]->t = P3;
        list[i] = t;
    }
    return L;
}





