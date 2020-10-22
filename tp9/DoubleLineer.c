#include "DoubleLineer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>

void insterList(Student **head, Student c)
{
   
    Student *tmp = *head;
    Student *new_node = (Student*)malloc(sizeof(Student));
    strcpy(new_node->name,c.name);
    strcpy(new_node->surname,c.surname);
    new_node->credit=random_credits();
    new_node->nots=random_nots();
    load_harfNotu(&new_node);
    new_node->ort=not_ortalamasi(new_node);
    sifrele(new_node);
    new_node->next = NULL;
    new_node->prev = NULL;
    if(tmp==NULL || strcmp((*head)->surname,c.surname)>=0) 
    {
    new_node->next = *head;
    *head = new_node;
    }
    else {
    while (tmp->next != NULL && strcmp(tmp->next->surname,c.surname)<0) {
    tmp = tmp->next;
    }
    Student *p=new_node->next;
    new_node->next = tmp->next;
    new_node->prev=tmp;
    tmp->next = new_node;
    if(p!=NULL)
    p->prev=new_node;
    }
   
}
int *random_credits(){
    int *r=malloc(sizeof(int)*nt);
    for(int i=0;i<nt;i++)
        r[i]=rand()%(5-2)+3;
    return r;
}
int *random_nots(){
    
    int *r=malloc(sizeof(int)*nt);
    for(int i=0;i<nt;i++)
     {   
        r[i]=rand()%100+1;
     }
    return r;
}
void new_Student(Student *d)
{
    printf("isim:\n");
    scanf("%s",d->name);
    printf("soyisim:\n");
    scanf("%s",d->surname);
    d->credit=random_credits();
    d->nots=random_credits();
    for (int i = 0; i < nt; i++)
    {
        d->harfnotu[i]=malloc(5);
    }
    load_harfNotu(&d);
    d->ort=not_ortalamasi(d);

   // scanf("%s",d->homeNumber);
}
void printlist(Student *s){
    printf("------List--------\n");
    Student *tmp=s;
    while (tmp)
    {   

        int n=tmp->ort/(tmp->name[0]*tmp->surname[0]);
        printf("name: %s - Surname: %s Nots:%d %d %d harfnotları: %s %s %s krediler: %d %d %d ort: %d\n",
        tmp->name,tmp->surname,tmp->nots[0],tmp->nots[1],tmp->nots[2],
        tmp->harfnotu[0],tmp->harfnotu[1],tmp->harfnotu[2],
        tmp->credit[0],tmp->credit[1],tmp->credit[2],n);
        tmp=tmp->next;
    }
    
}
void printlistByMean(Student *s,int o){
    printf("--Ortalaması %d üzeri olan öğrenciler Listesi----\n",o);
    Student *tmp=s;
    while (tmp!=NULL)
    {   
        int n=tmp->ort/(tmp->name[0]*tmp->surname[0]);
        if(n>=o)
        printf("name: %s - Surname: %s Nots:%d %d %d harfnotları: %s %s %s krediler: %d %d %d not ortalamasi: %d\n",
        tmp->name,tmp->surname,tmp->nots[0],tmp->nots[1],tmp->nots[2],
        tmp->harfnotu[0],tmp->harfnotu[1],tmp->harfnotu[2],
        tmp->credit[0],tmp->credit[1],tmp->credit[2],n);

        tmp=tmp->next;
    }
    
}
void load_harfNotu(Student **s){
   /* Notlar atandiktan sonra 0-50-> F, 50-60-> CC, 60-70-> CB, 70-80->BB, 80-90-> BA,
    90-100-> AA olacak sekilde harflendiren fonksiyonu yaziniz.*/
    int n=0;
    for (int i = 0; i < nt; i++)
    {
        (*s)->harfnotu[i]=malloc(5);
        n=(*s)->nots[i];
        if(n<50)
        {
            strcpy((*s)->harfnotu[i],"FF");
        }
        else if(n<60)
         strcpy((*s)->harfnotu[i],"CC");
        else if(n<70)
          strcpy((*s)->harfnotu[i],"CB");
        else if(n<80)
           strcpy((*s)->harfnotu[i],"BB");
        else if(n<90)
                strcpy((*s)->harfnotu[i],"BA");
        else
        {
             strcpy((*s)->harfnotu[i],"AA");
        }
        
    }
    

}
int not_ortalamasi(Student *s){
    int credits=0;
    int ortalama=0;
    for (int i = 0; i < nt; i++)
    {
        ortalama+=s->nots[i]*s->credit[i];
        credits+=s->credit[i];
    }
    
    return ortalama/credits;
}
void sifrele(Student *s){
    s->ort*=s->name[0]*s->surname[0];    
}

Student *newNode(Student c)
{
    Student *new_node = malloc(sizeof(Student));
    strcpy(new_node->name,c.name);
    strcpy(new_node->surname,c.surname);
    new_node->credit=random_credits();
    new_node->nots=random_nots();
    load_harfNotu(&new_node);
    new_node->ort=not_ortalamasi(new_node);
    sifrele(new_node);
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}
void insert_binary_tr(Student **head, Student c)
{
    if (*head == NULL)
    {
        *head = newNode(c);
        return;
    }
    if (strcmp((*head)->name , c.name)<0)
    {
        insert_binary_tr(&(*head)->next, c);
    }
    if (strcmp((*head)->name , c.name)>0)
    {
        insert_binary_tr(&(*head)->prev, c);
    }
   
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}


void inorder(Student *root)
{
    if (root != NULL)
    {
        inorder(root->prev);
        printf("name: %s: ->",  root->name);
        inorder(root->next);
    }
}