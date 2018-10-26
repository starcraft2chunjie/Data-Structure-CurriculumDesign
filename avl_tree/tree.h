#ifndef TREE_H_
#define TREE_H_
#define SUCCESS 1
#define FAIL -1

#define FRIEND = 1;
#define FANS = 2;
#define WATCH = 3;
#include <string.h>
#include <malloc.h>
// AVLnode.h

typedef struct AVLnode{
    int data;
    struct AVLnode *leftnode;
    struct AVLnode *rightnode;
}AVLnode;



// ADT.h

typedef struct ADT{
    AVLnode *t;
    int data;
}ADT;


// apply_ADT.h

typedef struct User{
    ADT *Q[3];//1 represent the friends set, 2 represent the fans set, 3 represent the watch set
    int ID;
    int favourate[3];
    char name[15];
    struct User *leftnode;
    struct User *rightnode;
}User;

AVLnode *copy(AVLnode *t, AVLnode *h);
AVLnode *SearchAVL(int e, AVLnode *t);
AVLnode *InsertAVL(AVLnode * t, int key);
AVLnode *DeleteAVL(int data, AVLnode *t);
void TraverseAVL(AVLnode *t);
int initAVL(AVLnode *t);
void DestroyAVL(AVLnode *t);
int height(AVLnode *t);
int num_node(AVLnode * t, int num);
AVLnode * unflat(AVLnode * P, int *list, int num);
int max(int l, int r);



ADT * set_init(ADT *Q);
int set_destroy(ADT *Q);
ADT *set_insert(ADT *Q, int data);
ADT *set_remove(ADT *Q, int data);
AVLnode * set_intersection(ADT *Q, ADT *T);
AVLnode *intersection(AVLnode *t, AVLnode *p, AVLnode *h);
AVLnode *set_union(ADT *Q, ADT *T);
AVLnode *unions(AVLnode *p, AVLnode *h);
AVLnode *set_difference(ADT *Q, ADT *T);
AVLnode *difference(AVLnode *P2, AVLnode *h);
int set_size(ADT *Q);
int size(AVLnode *t);
int set_member(ADT *Q, int data);
int member(AVLnode *p, int data, int h);
int set_subset(ADT *Q, ADT *T);
int subset(AVLnode *P, AVLnode *Q);
int set_equal(ADT *Q, ADT *T);
int flat(AVLnode * P, int * list, int num);




int Init_User(User * T);
User * Insert(User * T, int tag, int data);
User * Delete(User * T, int tag, int data);
int Modify_name(User * T,char name[15]);
int Modify_favourate(User * T, int order, int content);
ADT *co_watch(User *T, int num1, int num2);
int co_favourate(User *P, User *Q);
AVLnode *indirect_fri(User *T, User *Q);
AVLnode *indirect(AVLnode * P, User *T, ADT *H);
void User_traverse(User *L);


User *Search_User(int num, User *t);
User * newUser(int data);
User * Insert_User(User *t, int ID);
User * Delete_User(User *t, int ID);
User * Delete_User_full(User *t, int ID);
int DeleteAVL_other(User *t, int ID);
int User_Height(User *t);
User *single_rotate_with_left_U(User *k2);
User *single_rotate_with_right_U(User *k1);
User *double_rotate_with_left_U(User *k3);
User *double_rotate_with_right_U(User *k3);
User *Insert_User_as(User *t, User * P);
int Save_file(User *L, FILE * filename);
User * unflat_User(User * t, User **list, int num);
User * Load_file(User * L, FILE * filename);
#endif