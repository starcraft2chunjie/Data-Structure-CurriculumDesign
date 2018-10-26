#include <stdio.h>
#include "tree.h"
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

int main(void){
  printf("Please choose the operation\n");
  printf("1:AVL, 2:ADT, 3:User\n");
  int option;
  scanf("%d", &option);
  if(option == 3){
  	User *L = NULL;
  	User *T = NULL;
  	int op=1;
  	int i = 1;
  	int num = 0;
  	int tag = 0;
  	int data = 0;
  	int order = 0;
  	char name[15];
	FILE * fp;
  	while(op){
		system("clear");
    	printf("\n\n");
		printf("      Menu for member system On AVLTree Structure \n");
		printf("------------------------------------------------------\n");
		printf("    	  1. Insert_User     7. Modify_favourate\n");
		printf("    	  2. Search_User     8. co_watch\n");
		printf("    	  3. Delete_User     9. co_favourate \n");
		printf("    	  4. Insert_member  10. indirect_fri\n");
		printf("    	  5. Delete_member  11. User_traverse\n");
		printf("    	  6. Modify_name    12. LoadFile\n");
		printf("    	  0. Exit           13. SaveFile\n");
		printf("          14.friends        15. fans\n");
		printf("          16.watch          17. favourate\n");
		printf("------------------------------------------------------\n");
    	printf("   Please choose your operation[0~13]:");
		scanf("%d",&op);
    	switch(op){
	   	case 1:
         	printf("Please enter the number you want to label\n");
         	scanf("%d", &num);
         	L = Insert_User(L, num);
		 	getchar();getchar();
		 	break;
	   	case 2:
         	printf("Please enter the number you want to search\n");
         	scanf("%d", &num);
         	User *P = NULL;
		 	if((P = Search_User(num, L)) != NULL){
             	printf("The name is %s", P->name);
			 	printf("\n");
		 	}
		 	else{
			 	printf("There no exist this Users\n");
		 	}     
		 	getchar();getchar();
		 	break;
	   	case 3:
		    printf("Please enter the ID you want to delete\n");
			scanf("%d", &num);
		 	L = Delete_User_full(L, num); 
		 	getchar();getchar();
		 	break;
	   	case 4:
         	printf("Please enter the tag and the ID that you want to operate to and the ID of User\n");
			printf("tag 1: make friends, tag 2 : watch somebody\n");
         	scanf("%d%d%d", &tag, &num, &data);
			if(tag == 1){
				T = Search_User(num, L);
		 		T = Insert(T, tag, data);
				T = Search_User(data, L);
				T = Insert(T, tag, num);
			}
			if(tag == 2){
				T = Search_User(num, L);
				T = Insert(T, tag + 1, data);
				T = Search_User(data, L);
				T = Insert(T, tag, num);
			}
		 	getchar();getchar();
		 	break;
	   	case 5:
		 	printf("Please enter the tag and the ID that you want to delete and the ID you want to be deleted\n");
         	scanf("%d%d%d", &tag, &num, &data);
         	T = Search_User(num, L);
         	T = Delete(T, tag, data);  
		 	getchar();getchar();
		 	break;
	   	case 6:
         	printf("Please enter the number\n");
         	scanf("%d", &num);
         	printf("Please enter the new name\n");
         	scanf("%s", name);
		 	Modify_name(Search_User(num, L), name);
		 	getchar();getchar();
		 	break;
	   	case 7:
         	printf("Please enter the number, the order\n");
         	scanf("%d%d", &num, &order);
         	printf("Please enter the favourate you want to modify\n");
         	scanf("%d", &tag);
		 	Modify_favourate(Search_User(num, L), order, tag);
		 	getchar();getchar();
		 	break;
	   	case 8:
	   	 	printf("Please enter the two num that you want find the co_watch\n");
		 	scanf("%d%d", &data, &num);
		 	ADT * temp = co_watch(L, num, data);
		 	TraverseAVL(temp->t);
		 	getchar();getchar();
		 	break;
	   	case 9:
	   	 	printf("Please enter the two number that you want find the co_favourate\n");
		 	scanf("%d%d", &num, &data);
	     	co_favourate(Search_User(num, L), Search_User(data, L));  
		 	getchar();getchar();
		 	break;
	   	case 10:
	   	 	printf("Please enter the number that you want to find the indirect friends\n");
		 	scanf("%d", &num);
	     	TraverseAVL(indirect_fri(Search_User(num, L), L));
		 	getchar();getchar();
			break;
	   	case 11:
		 	User_traverse(L);
		 	getchar();getchar();
		 	break;
	   	case 12:
	   	 	printf("Please enter the filename that you want to load\n");
		 	char filename[10];
		 	scanf("%s", filename);
		 	fp = fopen(filename, "rb");
		 	L = Load_file(L, fp);
		 	getchar();getchar();
		 	break;
	   	case 13:
	     	printf("Please enter the filename that you want to save\n");
            //printf("1\n");
		 	scanf("%s", filename);
			//printf("2\n");
		 	fp = fopen(filename, "wb");
			//printf("3\n");
		 	Save_file(L, fp);
			fclose(fp);
		 	getchar();getchar();
		 	break;
		case 14:
			printf("Please enter the ID\n");
			scanf("%d", &num);
			T = Search_User(num, L);
			if(T != NULL){
				TraverseAVL(T->Q[0]->t);
			}
			else{
				printf("The ID doesn't exist!\n");
			}
			getchar();getchar();
			break;
		case 15:
			printf("Please enter the ID\n");
			scanf("%d", &num);
			T = Search_User(num, L);
			if(T != NULL){
				TraverseAVL(T->Q[1]->t);
			}
			else{
				printf("The ID doesn't exist!\n");
			}
			getchar();getchar();
			break;
		case 16:
			printf("Please enter the ID\n");
			scanf("%d", &num);
			T = Search_User(num, L);
			if(T != NULL){
				TraverseAVL(T->Q[2]->t);
			}
			else{
				printf("The ID doesn't exist!\n");
			}
			getchar();getchar();
			break;
		case 17:
			printf("Please enter the ID\n");
			scanf("%d", &num);
			T = Search_User(num, L);
			printf("%d %d %d", T->favourate[0], T->favourate[1], T->favourate[2]);
			getchar(); getchar();
			break;	
		case 0:
         	break;
		}
  	}
  }
  else if(option == 1){
	  AVLnode * L = (AVLnode *)malloc(sizeof(AVLnode));
	  AVLnode * T = NULL;
	  int op = 1;
	  int i = 0;
  	  int num = 0;
  	  int tag = 0;
  	  int data = 0;
  	  int order = 0;
  	  char name[15];
	  while(op){
		system("clear");
    	printf("\n\n");
		printf("      Menu for member system On AVLTree Structure \n");
		printf("------------------------------------------------------\n");
		printf("    	  1. initAVL        4. InsertAVL\n");
		printf("    	  2. DestroyAVL     5. DeleteAVL\n");
		printf("    	  3. SearchAVL      6. TraverseAVL \n");
		printf("    	  0. exit           7. pre_traverseAVL \n");
		printf("    	                    8. in_traverseAVL \n");
		printf("------------------------------------------------------\n");
    	printf("   Please choose your operation[0~6]:");
		scanf("%d",&op);
		if(i == 0 && op != 1){
			printf("You have to initialize it first!\n");
			continue;
		}
		else{
	    switch(op){
		  case 1:
		  initAVL(L);
		  L = NULL;
		  i = 1;
		  printf("Succeed!\n");
		  getchar();getchar();
		  break;
	   	  case 2:
          DestroyAVL(L);
		  L = (AVLnode *)malloc(sizeof(AVLnode));   
		  i = 0; 
		  getchar();getchar();
		  break;
	   	  case 3:
		  printf("Please enter the ID that you want to search\n");
		  scanf("%d", &num);
		  if(SearchAVL(num, L) != NULL){
			  printf("There exist this node\n");
		  } 
		  else{
			  printf("There no exist this node\n");
		  }
	      getchar();getchar();
		  break;
	   	  case 4:
		  printf("Please enter the num you want to insert\n");
		  scanf("%d", &num);
		  L = InsertAVL(L, num);
		  getchar();getchar();
		  break;
	   	  case 5:
		  printf("Please enter the ID that you want to delete\n");
		  scanf("%d", &num);
		  L = DeleteAVL(num, L);
		  getchar();getchar();
		  break;
	   	  case 6:
          TraverseAVL(L);
		  getchar();getchar();
		  break;
		  case 7:
		  pre_traverseAVL(L);
		  getchar();getchar();
		  break;
		  case 8:
		  in_traverseAVL(L);
		  getchar(); getchar();
		  break;
  	  }
    }
	}
  }
  else if(option == 2){
	  ADT *L[2];
	  L[0] = (ADT *)malloc(sizeof(ADT)); 
	  L[1] = (ADT *)malloc(sizeof(ADT));
	  int op = 1;
	  int i = 0;
  	  int ID = 0;
  	  int num = 0;
	  int num1 = 0;
	  int num2 = 0;
	  int tag = 0;
  	  char name[15];
	  while(op){
		system("clear");
    	printf("\n\n");
		printf("      Menu for member system On ADT Structure \n");
		printf("------------------------------------------------------\n");
		printf("    	  1. set_init        6. set_union\n");
		printf("    	  2. set_destroy     7. set_difference\n");
		printf("    	  3. set_insert      8. set_size      \n");
		printf("    	  4. set_remove      9. set_member     \n");
		printf("          5. set_intersection10.set_subset    \n");
		printf("          0. exit            11.set_equal      \n");
		printf("                             12.traverse       \n");
		printf("------------------------------------------------------\n");
    	printf("   Please choose your operation[0~6]:");
		scanf("%d",&op);
		if(i == 0 && op != 1){
			printf("You have to initialize it first!");
			continue;
		}
		else{
	  	switch(op){
	   	case 1:
		    printf("Please choose the the ADT, first or second?\n");
			scanf("%d", &num);
			if(num == 1){
				L[0] = set_init(L[0]);
			}
			else{
				L[1] = set_init(L[1]);
			}
			i = 1;
		 	getchar();getchar();
		 	break;
	   	case 2:
		    printf("Please choose the the ADT, first or second?\n");
			scanf("%d", &num);
			if(num == 1){
				set_destroy(L[0]);
				L[0] = (ADT *)malloc(sizeof(ADT));
			}
			else{
				set_destroy(L[1]);
				L[1] = (ADT *)malloc(sizeof(ADT));
			}   
			i = 0;
		 	getchar();getchar();
		 	break;
	   	case 3:
		    printf("Please choose the the ADT, first or second?\n");
			scanf("%d", &num);
			if(num == 1){
				printf("Please enter the ID that you want to Insert\n");
				scanf("%d", &ID);
		 		L[0] = set_insert(L[0], ID);
				TraverseAVL(L[0]->t);
			}
			else{
				printf("Please enter the ID that you want to Insert\n");
				scanf("%d", &ID);
		 		L[1] = set_insert(L[1], ID);
				TraverseAVL(L[1]->t);
			}
		 	getchar();getchar();
		 	break;
	   	case 4:
		    printf("Please choose the the ADT, first or second?\n");
			scanf("%d", &num);
			if(num == 1){
				printf("Please enter the ID you want to remove\n");
				scanf("%d", &ID);
				L[0] = set_remove(L[0], ID);
			}
			else{
				printf("Please enter the ID you want to remove\n");
				scanf("%d", &ID);
				L[0] = set_remove(L[0], ID);
			}
		 	getchar();getchar();
		 	break;
	   	case 5:
		   	TraverseAVL(set_intersection(L[0], L[1]));
		 	getchar();getchar();
		 	break;
	   	case 6:
         	TraverseAVL(set_union(L[0], L[1]));
		 	getchar();getchar();
		 	break;
		case 7:
			TraverseAVL(set_difference(L[0], L[1]));
			getchar();getchar();
			break;
		case 8:
			printf("Please choose the the ADT, first or second?\n");
			scanf("%d", &num);
			if(num == 1){
				printf("%d", set_size(L[0]));
			}
			else{
				printf("%d", set_size(L[1]));
			}
			getchar();getchar();
			break;
		case 9:
			printf("Please choose the the ADT, first or second?\n");
			scanf("%d", &num);
			if(num == 1){
				printf("Please enter the ID\n");
				scanf("%d", &ID);
				tag = set_member(L[0], ID);
				if(tag == 0){
					printf("There no exist this member\n");
				}
				else{
					printf("There exist this member\n");
				}
			}
			else{
				printf("Please enter the ID\n");
				scanf("%d", &ID);
				tag = set_member(L[1], ID);
				if(tag == 0){
					printf("There no exist this member\n");
				}
				else{
					printf("There exist this member\n");
				}
			}
			getchar(); getchar();
			break;
		case 10:
			printf("Please enter the order\n");
			scanf("%d%d", &num1, &num2);
			if(num1 == 1){
				tag = set_subset(L[0], L[1]);
				if(tag == 1){
					printf("the first is the second's subset\n");
				}
				else{
					printf("the first is not the second's subset\n");
				}
			}
			if(num1 == 2){
				tag = set_subset(L[1], L[0]);
				if(tag == 1){
					printf("the second is the first's subset\n");
				}
				else{
					printf("the second is not the first's subset\n");
				}
			}
			getchar();getchar();
			break;
		case 11:
			tag = set_equal(L[0], L[1]);
			if(tag == 1){
				printf("The two are equal\n");
			}
			else{
				printf("The two are inequal\n");
			}
			getchar();getchar();
			break;
		case 12:
			printf("Please choose the the ADT, first or second?\n");
			scanf("%d", &num);
			if(num == 1){
				TraverseAVL(L[0]->t);
			}
			else{
				TraverseAVL(L[1]->t);
			}
			getchar(); getchar();
			break;
			
     }
	}
	}
   }
   return 0;
}