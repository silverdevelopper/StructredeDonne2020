#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include <time.h>
#include "DoubleLineer.h"
int main()
{
    
    int resp=1;
    Student *head=NULL;
      Student *binary=NULL;
    srand(time(NULL));
    Student c={"ccc","surname"};
    Student c1={"xxxx","surname1"};
    Student c4={"aa","surname4"};
    Student c2={"bbbb","surname2"};
    Student c3={"name3","surname3"};
    Student c5={"name5","surname5"};
    Student c6={"name6","surname6"};

    insterList(&head,c6);
    insterList(&head,c);
    insterList(&head,c2);
    insterList(&head,c1);
    insterList(&head,c4);
    insterList(&head,c5);
    insterList(&head,c3);
    
    //Soru 7
    insert_binary_tr(&binary,c6);
    insert_binary_tr(&binary,c);
    insert_binary_tr(&binary,c2);
    insert_binary_tr(&binary,c1);
    insert_binary_tr(&binary,c4);
    insert_binary_tr(&binary,c5);
    insert_binary_tr(&binary,c3);
    //ispatı
    printf("\ninorder\n");
    inorder(binary);
    Student *addcont=malloc(sizeof(Student));
    printf("\n");
    printlist(head);
    // Soru 8
    printf("Ortalama giriniz\n");
    int o=0;
    scanf("%d",&o);
    
    printlistByMean(head,o);
   
   
return 0;
}