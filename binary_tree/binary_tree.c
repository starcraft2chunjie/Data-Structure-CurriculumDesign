#include <stdio.h>
#include "binary_tree.h"
#include <math.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
int main(void){
  int op=1;
  int e = 0;
  int i = 0;
  int num = 0;
  int index;
  int value;
  int LorR;
  int *definition = NULL;
  TreeNode *p = NULL;
  TreeNode *l = NULL;
  TreeNode L[10];
  LinkQueue *T = (LinkQueue *)malloc(sizeof(LinkQueue));
  LinkQueue *Q = (LinkQueue *)malloc(sizeof(LinkQueue));
  LinkQueue *K = (LinkQueue *)malloc(sizeof(LinkQueue));
  for(int j = 0; j<10; j++){
      L[j].index = -1;
      L[j].value = -1;
  }
  l = L;
  while(op){
	system("clear");
    printf("\n\n");
	printf("      Menu for Binary Tree \n");
	printf("------------------------------------------------------\n");
	printf("    	  1. InitBiTree       12. RightChild\n");
	printf("    	  2. DestroyBiTree    13. LeftSibling\n");
	printf("    	  3. CreateBiTree     14. RightSibling \n");
	printf("    	  4. ClearBiTree      15. InsertChild\n");
	printf("    	  5. BiTreeEmpty      16. DeleteChild\n");
	printf("    	  6. BiTreeDepth      17. PreOrderTraverse\n");
	printf("    	  7. Root             18. InOrderTraverse\n");
	printf("          8. Value            19. PostOrderTraverse\n");
	printf("          9. Assign           20. LevelOrderTraverse\n ");
	printf("          10.Parent           21. ChangeList\n");
	printf("          11.LeftChild        22. \n");
	printf("------------------------------------------------------\n");
    printf("   Please choose your operation[0~14]:");
	scanf("%d",&op);
	if(l->index == -1 && op != 1 && op != 0){
		printf("You must initialize it!");
		getchar();
		getchar();
		continue;
	}
    switch(op){
	   case 1:
		 if(InitBiTree(l) == SUCCESS){
			 printf("Initializing succeed!\n");
		 }
		 else{
			 printf("Initializing fail!\n");
		 }
		 getchar();getchar();
		 break;
	   case 2:
		 if(DestroyBiTree(l) == SUCCESS){
			 printf("Destroying succeed\n");
		 }
		 else{
			 printf("Destroying fail\n");
		 }     
		 getchar();getchar();
		 break;
	   case 3:
	     printf("Please enter the definition of length:\n ");
		 scanf("%d",&num);
		 definition = (int *)malloc(sizeof(int) * num);
		 for(i = 0; i<num; i++){
			 printf("Please enter the element of it\n");
			 scanf("%d", definition+i);			 
		 }
		 index = 0;
		 InitQueue(T);
		 if(CreateBiTree(l, definition, num, index, T) == SUCCESS){
			 printf("CreateBiTree succeed\n");
		 }
		 else{
			 printf("CreateBiTree failed\n");
		 }   
		 getchar();getchar();
		 break;
	   case 4:
		 if(ClearBiTree(l) == TRUE){
			printf("Clearing succeed\n");
		 }
		 else{
			 printf("Clearing failed\n");
		 }
		 getchar();getchar();
		 break;
	   case 5:
	     if(BiTreeEmpty(l) == TRUE){
			 printf("The tree is empty");
		 }
		 if(BiTreeEmpty(l) != TRUE){
			 printf("The tree is not empty");
		 }  
		 getchar();getchar();
		 break;
	   case 6:
		 printf("The tree's depth is %d",BiTreeDepth(l));
		 getchar();getchar();
		 break;
	   case 7:
		 printf("The tree's root is %d", Root(l)->value);
		 getchar();getchar();
		 break;
	   case 8:
		 printf("please enter the index\n");
		 scanf("%d", &i);
		 value = Value(l, i);
		 if(value == FAILURE){
			 printf("The index is wrong or the list is empty");
		 }
		 else{
			 printf("%d", value);
		 }     
		 getchar();getchar();
		 break;
	   case 9:
	     printf("please enter the index and the value\n");
		 scanf("%d%d", &index, &value);
		 Assign(l, index, value);
		 printf("Succeed");
		 getchar();getchar();
		 break;
	   case 10:
	     printf("please enter the index\n");
		 scanf("%d", &index);
		 p = Parent(l, index);
		 if(p == NULL){
			 printf("The index is wrong");
		 }
		 else{
			 printf("%d", p->value);
		 }  
		 getchar();getchar();
		 break;
	   case 11:
		 printf("Please enter the index\n");
		 scanf("%d", &index);
		 p = LeftChild(l, index);
		 if(p == NULL){
			 printf("The index is wrong!");
		 }
		 else{
			 printf("Success, and the element is %d", p->value);
		 }
		 getchar();getchar();
		 break;
	   case 12:
		 printf("Please enter the index\n");
		 scanf("%d", &index);
		 p = RightChild(l, index);
		 if(p == NULL){
			 printf("The index is wrong!");
		 }
		 else{
			 printf("Success, and the element is %d", p->value);
		 }
		 getchar();getchar();
		 break;
	   case 13:
		 printf("Please enter the index\n");
		 scanf("%d", &index);
		 p = LeftSibling(l, index);
		 if(p == NULL){
			 printf("The index is wrong!");
		 }
		 else{
			 printf("Success, and the element is %d", p->value);
		 }
		 getchar();getchar();
		 break;
	   case 14:
	     printf("Please enter the index\n");
		 scanf("%d", &index);
		 p = RightSibling(l, index);
		 if(p == NULL){
			 printf("The index is wrong!");
		 }
		 else{
			 printf("Success, and the element is %d", p->value);
		 }
		 getchar();getchar();
		 break;
       case 15:
         printf("Please enter the index of list and the value of LorR\n");
         scanf("%d%d", &index, &LorR);
		 InitQueue(Q);
		 InitQueue(K);
		 printf("Please enter the definition of length:\n ");
		 scanf("%d",&num);
		 definition = (int *)malloc(sizeof(int) * num);
		 for(i = 0; i<num; i++){
			 printf("Please enter the element of it\n");
			 scanf("%d", definition+i);
		 }
		 TreeNode * subTree = (TreeNode *)malloc(sizeof(TreeNode));
		 subTree->index = -1;
		 subTree->value = -1;
		 InitBiTree(subTree);
		 int indexs = 0;
		 CreateBiTree(subTree, definition, num, indexs, K);
		 e = InsertChild(l, index, LorR, subTree->leftChild, Q);
         getchar();getchar();
         break;
       case 16:
	     printf("Please enter the index and LorR\n");
		 scanf("%d%d", &index, &LorR);
		 InitQueue(Q);
	   	 if(DeleteChild(l, index, LorR, Q) == TRUE){
			 printf("Delete succeed");
		 }
		 else{
			 printf("Delete failed");  
		 }
		 getchar();getchar();
		 break;
	   case 17:
	   	 PreOrderTraverse(l, visit);
		 getchar();getchar();
		 break;
	   case 18:
	     InOrderTraverse(l, visit);
		 getchar();getchar();
		 break;
	   case 19:
	     PostOrderTraverse(l, visit);
		 getchar();getchar();
		 break;
	   case 20:
		 InitQueue(T);
		 LevelOrderTraverse(l, visit, T);
		 getchar();getchar();
		 break;
	   case 21:
	     printf("Please enter the index of list\n");
         int num;
         scanf("%d", &num);
         if(num > 10){
            printf("The index is wrong");
            getchar();getchar();
            break;
         }
         l = L + (num - 1);
         getchar();getchar();
		 break;
	}//end of switch
  }//end of while
  printf("Welcome to using the system again\n");
  return 0;
}//end of main()



int InitBiTree(TreeNode * head){
    head->index = 0;
    head->value = 0;
    head->leftChild = NULL;
    head->rightChild = NULL;
	return SUCCESS;
}
int DestroyBiTree(TreeNode * head){
    ClearBiTree(head);
    head->value = -1;
	head->index = -1;
    return TRUE;
}

int CreateBiTree1(TreeNode *head, int *definition, int lengthOfDef, int indexs){
	if(head->value == -1){
		return FALSE;
	}
	TreeNode *left_node = NULL;
    TreeNode *right_node = NULL;
	if(head->index == 0){
		indexs = indexs * 2 + 1;
	}
	else{
		indexs = indexs * 2;
	}
	if(indexs <= lengthOfDef && *(definition + indexs - 1) != -1){
		left_node = (TreeNode *)malloc(sizeof(TreeNode));
		left_node->index = true_lengthOfDef(definition, indexs);
		left_node->value = *(definition + indexs - 1);
		head->leftChild = left_node;
		CreateBiTree1(left_node, definition, lengthOfDef, indexs);
	}
	indexs++;
	if(head->index != 0){
		if(indexs <= lengthOfDef && *(definition + indexs - 1) != -1){
			right_node = (TreeNode *)malloc(sizeof(TreeNode));
            right_node->index = true_lengthOfDef(definition, indexs);
            right_node->value = *(definition + indexs - 1);
            head->rightChild = right_node;
            CreateBiTree1(right_node, definition, lengthOfDef, indexs);
		}
	}
	return TRUE;
}
int CreateBiTree(TreeNode *head, int *definition, int lengthOfDef, int index, LinkQueue *Q){
	if(index < lengthOfDef){
		if(head->index == 0){
			if(*(definition + index) != -1){
				head->leftChild = (TreeNode *)malloc(sizeof(TreeNode));
				head->leftChild->value = *(definition + index);
				index++;
				head->leftChild->index = index;
				head->leftChild->leftChild = NULL;
				head->leftChild->rightChild = NULL;
				CreateBiTree(head->leftChild, definition, lengthOfDef, index, Q);
				return TRUE;
			}
			else{
				return FALSE;
			}
		}
		if(*(definition + index) != -1){
			head->leftChild = (TreeNode *)malloc(sizeof(TreeNode));
			head->leftChild->value = *(definition + index);
			index++;
			head->leftChild->index = true_lengthOfDef(definition, index);
			head->leftChild->leftChild = NULL;
			head->leftChild->rightChild = NULL;
			EnQueue(Q, head->leftChild);
		}
		else{
			index++;
		}
		if(*(definition + index) != -1){
			head->rightChild = (TreeNode *)malloc(sizeof(TreeNode));
			head->rightChild->value = *(definition + index);
			index++;
			head->rightChild->index = true_lengthOfDef(definition, index);
			head->rightChild->leftChild = NULL;
			head->rightChild->rightChild = NULL;
			EnQueue(Q, head->rightChild);
		}
		else{
			index++;
		}
		TreeNode * p = Dequeue(Q);
		CreateBiTree(p, definition, lengthOfDef, index, Q);
	}
	return TRUE;
}
int true_lengthOfDef(int *definition, int lengthOfDef){
	int i = 0;
	int sum = 0;
	while(i < lengthOfDef){
		if(*(definition + i) != -1){
			sum++;
		}
		i++;
	}
	return sum;
}

int ClearBiTree(TreeNode * head){
	if(head->value == -1){
		printf("The tree doesn't exist");
		return FALSE;
	}
	if(head->leftChild == NULL && head->rightChild == NULL){
		free(head);
		return TRUE;
	}
    if(head->leftChild != NULL){
		ClearBiTree(head->leftChild);
	}
	if(head->rightChild != NULL){
		ClearBiTree(head->rightChild);
	}
}
int BiTreeEmpty(TreeNode * head){
	if(head->value == -1){
		printf("The tree doesn't exist");
		return FALSE;
	}
    if(head->leftChild == NULL && head->rightChild == NULL){
        return TRUE;
    }
    return FALSE;
}
int BiTreeDepth(TreeNode * head){
	if(head->value == -1){
		printf("The tree doesn't exist");
	}
    if(head->leftChild == NULL && head->rightChild == NULL){
		return 1;
	}
	if(head->leftChild != NULL && head->rightChild != NULL){
		return max(BiTreeDepth(head->leftChild) + 1, BiTreeDepth(head->rightChild) + 1);
	}
	if(head->leftChild != NULL && head->rightChild == NULL){
		return BiTreeDepth(head->leftChild) + 1;
	}
	if(head->leftChild == NULL && head->rightChild != NULL){
		return BiTreeDepth(head->rightChild) + 1;
	}
}
TreeNode * Root(TreeNode * head){
	if(head->value == 0 && head->leftChild != NULL){
		return head->leftChild;
	}
	else{
		printf("The tree dosen't exist");
		return NULL;
	}

}
int Value(TreeNode * head, int index){
	if(head->value == -1){
		printf("The tree doesn't exist");
		return FALSE;
	}
	if(head->index == index){
		return head->value;
	}
	if(head->leftChild == NULL && head->rightChild == NULL){
		return 0;
	}
	if(head->leftChild != NULL && head->rightChild != NULL){
		return Value(head->leftChild, index) + Value(head->rightChild, index);
	}
	if(head->leftChild != NULL && head->rightChild == NULL){
		return Value(head->leftChild, index);
	}
	if(head->leftChild == NULL && head->rightChild != NULL){
		return Value(head->rightChild, index);
	}
}
void Assign(TreeNode * head, int index, int value){
	TreeNode *p = getNode(head, index);
	p->value = value;
}

TreeNode * Parent(TreeNode * head, int index){
	if(index != 0 && head->index != -1 && index != 1){
		if(head->leftChild != NULL && head->rightChild != NULL){
			if(head->leftChild->index == index || head->rightChild->index == index){
				return head;
			}
			else if(Parent(head->leftChild, index) != NULL && Parent(head->rightChild, index) == NULL){
				return Parent(head->leftChild, index);
			}
			else if(Parent(head->leftChild, index) == NULL && Parent(head->rightChild, index) != NULL){
				return Parent(head->rightChild, index);
			}
			else if(Parent(head->leftChild, index) == NULL && Parent(head->rightChild, index) == NULL){
				return NULL;
			}
		}
		if(head->leftChild != NULL && head->rightChild == NULL){
			if(head->leftChild->index == index){
				return head;
			}
			else{
				return Parent(head->leftChild, index);
			}
		}
		if(head->leftChild == NULL && head->rightChild != NULL){
			if(head->rightChild->index == index){
				return head;
			}
			else{
				return Parent(head->rightChild, index);
			}
		}
		if(head->leftChild == NULL && head->rightChild == NULL){
			return NULL;
		}
	}
	else{
		return NULL;
	}
}
TreeNode * LeftChild(TreeNode * head, int index){
	if(head->value != -1){
		if(head->index == index){
			return head->leftChild;
		}
		if(head->leftChild == NULL && head->rightChild == NULL){
			return NULL;
		}
		if(head->leftChild != NULL && head->rightChild == NULL){
			return LeftChild(head->leftChild, index);
		}
		if(head->leftChild == NULL && head->rightChild != NULL){
			return LeftChild(head->rightChild, index);
		}
		if(head->leftChild != NULL && head->rightChild != NULL){
			TreeNode *left = LeftChild(head->leftChild, index);
			TreeNode *right = LeftChild(head->rightChild, index);
			if(left == NULL && right == NULL){
				return NULL;
			}
			if(left != NULL && right == NULL){
				return left;
			}
			if(left == NULL && right != NULL){
				return right;
			}
		}
	}
	else{
		printf("The tree doesn't exist!");
	}
}

TreeNode * RightChild(TreeNode * head, int index){
	if(head->value != -1){
		if(head->index == index){
			return head->rightChild;
		}
		if(head->leftChild == NULL && head->rightChild == NULL){
			return NULL;
		}
		if(head->leftChild != NULL && head->rightChild == NULL){
			return RightChild(head->leftChild, index);
		}
		if(head->leftChild == NULL && head->rightChild != NULL){
			return RightChild(head->rightChild, index);
		}
		if(head->leftChild != NULL && head->rightChild != NULL){
			TreeNode *left = RightChild(head->leftChild, index);
			TreeNode *right = RightChild(head->rightChild, index);
			if(left == NULL && right == NULL){
				return NULL;
			}
			if(left != NULL && right == NULL){
				return left;
			}
			if(left == NULL && right != NULL){
				return right;
			}
		}
	}
	else{
		printf("The tree doesn't exist!");
	}
}


TreeNode * LeftSibling(TreeNode * head, int index){
	TreeNode * left = Parent(head, index)->leftChild;
	if(left != NULL){
		return left;
	}
	else{
		printf("There's no leftsibling");
		return NULL;
	}
}
TreeNode * RightSibling(TreeNode * head, int index){
	TreeNode * right = Parent(head, index)->rightChild;
	if(right != NULL){
		return right;
	}
	else{
		printf("There's no rightsibling");
		return NULL;
	}
}

TreeNode *getNode(TreeNode *head, int index){
	if(head->index != -1){
		if(head->index == index){
			return head;
		}
		if(head->leftChild != NULL && head->rightChild != NULL){
			TreeNode *left = getNode(head->leftChild, index);
			TreeNode *right = getNode(head->rightChild, index);
			if(left != NULL && right == NULL){
				return left;
			}
			if(left == NULL && right != NULL){
				return right;
			}
			if(left == NULL && right == NULL){
				return NULL;
			}
		}
		if(head->leftChild != NULL && head->rightChild == NULL){
			return getNode(head->leftChild, index);
		}
		if(head->leftChild == NULL && head->rightChild != NULL){
			return getNode(head->rightChild, index);
		}
		if(head->leftChild == NULL && head->rightChild == NULL){
			return NULL;
		}
	}
}

int InsertChild(TreeNode * head, int index, int LorR, TreeNode * subTree, LinkQueue *Q){
	TreeNode *p = getNode(head, index);
	if(LorR == 0){
		if(p->leftChild != NULL){
			free(p->rightChild);
			p->rightChild = p->leftChild;
			p->leftChild = subTree;
		}
		else{
			p->leftChild = subTree;
		}
	}
	if(LorR == 1){
		if(p->rightChild != NULL){
			free(p->leftChild);
			p->leftChild = p->rightChild;
			p->rightChild = subTree;
		}
		else{
			p->rightChild = subTree;
		}
	}
	UpdateKey(head, Q, 0);
	return TRUE;

}
int DeleteChild(TreeNode *head, int index, int LorR, LinkQueue *Q){
	TreeNode *p = getNode(head, index);
	if(LorR == 0){
		if(p->leftChild != NULL){
			free(p->leftChild);
			p->leftChild = NULL;
		}
		else{
			printf("The leftchild doesn't exist");
		}
	}
	if(LorR == 1){
		if(p->rightChild != NULL){
			free(p->rightChild);
			p->rightChild = NULL;
		}
		else{
			printf("The rightchild doesn't exist");
		}
	}
	UpdateKey(head, Q, 0);
	return TRUE;
}
int PreOrderTraverse(TreeNode * head, void (*visit)(int value)){
	if(head->index != -1){
		PreOrder(head->leftChild, visit);
	}
	else{
		printf("The tree doesn't exist");
	}
}
int PreOrder(TreeNode * head, void (*visit)(int value)){
	if(head == NULL){
		return FALSE;
	}
	else{
		visit(head->value);
		PreOrder(head->leftChild, visit);
		PreOrder(head->rightChild, visit);
		return TRUE;
	}
}
int InOrderTraverse(TreeNode * head, void (*visit)(int value)){
	if(head->index != -1){
		InOrder(head->leftChild, visit);
	}
	else{
		printf("The tree doesn't exist");
	}
}
int InOrder(TreeNode * head, void (*visit)(int value)){
	if(head == NULL){
		return FALSE;
	}
	else{
		InOrder(head->leftChild, visit);
		visit(head->value);
		InOrder(head->rightChild, visit);
		return TRUE;
	}
}
int PostOrderTraverse(TreeNode * head, void (*visit)(int value)){
	if(head->index != -1){
		PostOrder(head->leftChild, visit);
	}
	else{
		printf("The tree doesn't exist");
	}
}
int PostOrder(TreeNode * head, void (*visit)(int value)){
	if(head == NULL){
		return FALSE;
	}
	else{
		PostOrder(head->leftChild, visit);
		PostOrder(head->rightChild, visit);
		visit(head->value);
		return TRUE;
	}
}
int LevelOrderTraverse(TreeNode * head, void (*visit)(int value), LinkQueue *Q){
	if(head->index == -1){
		printf("The Tree doesn't exist");
		return FALSE;
	}
	if(head->leftChild != NULL){
		visit(head->leftChild->value);
		EnQueue(Q, head->leftChild);
	}
	if(head->rightChild != NULL){
		visit(head->rightChild->value);
		EnQueue(Q, head->rightChild);
	}
	TreeNode *p = Dequeue(Q);
	if(p != NULL){
		LevelOrderTraverse(p, visit, Q);
	}
	return SUCCESS;
}
void visit(int value){
	printf("%d ", value);
}

int InitQueue(LinkQueue *Q){
	Q->rear = (QNode *)malloc(sizeof(QNode));
	Q->front = Q->rear ;
	if(!Q->front) exit(OVERFLOW);
	Q->front->next = NULL;
}

int EnQueue(LinkQueue *Q, TreeNode * e){
	QNode *p = (QNode *)malloc(sizeof(QNode));
	if(!p) exit(OVERFLOW);
	p->data = e; 
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return TRUE;
}

TreeNode * Dequeue(LinkQueue *Q){
	if(Q->front == Q->rear) return NULL;
	QNode * p = Q->front->next;
	TreeNode * e = p->data;
	Q->front->next = p->next;
	if(Q->rear == p){
		Q->rear = Q->front;
	}
	free(p);
	return e;
}

int UpdateKey(TreeNode *head, LinkQueue *Q, int index){
	if(head->leftChild != NULL){
		index++;
		head->leftChild->index = index;
		EnQueue(Q, head->leftChild);
	}
	if(head->rightChild != NULL){
		index++;
		head->rightChild->index = index;
		EnQueue(Q, head->rightChild);
	}
	TreeNode * p = Dequeue(Q);
	if(p != NULL){
		UpdateKey(p, Q, index);
	}
	return SUCCESS;
}

int max(int a,int b){
	if(a > b)
		return a;
	else
		return b;
}







