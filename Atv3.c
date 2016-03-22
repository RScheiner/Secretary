  /*
Integrante 1 - Brunno Vega - RA :13144175	
Integrante 2 - Rafael Sperandio Scheiner - RA :12014569
*/

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

typedef struct cadastro{
  int RA;
  char nome[50];
  float nota;
  struct cadastro *prox;
}tipoCadastro;

void cadastro(tipoCadastro **lista);
void insere(tipoCadastro **lista,tipoCadastro *novo);
int remover(tipoCadastro **lista);
void busca(tipoCadastro *lista, int op);
void listar(tipoCadastro *lista);


int main(void)
{
  
  int op =0,ret=0;
   tipoCadastro *slot = NULL;
   
  system("clear");
  do{
    printf("1-Cadastrar\n");
    printf("2-Remover Cadastro\n");
    printf("3-Buscar (RA)\n");
    printf("4-Buscar (Nome)\n");
    printf("5-Exibir Todos\n");
    printf("6-Sair\n");
      scanf("%i",&op);
      
      
    switch (op) 
    {
     case 1:
       cadastro(&slot);
       break;
     case 2:
       ret=remover(&slot);
       if(ret ==1)
       {
	 printf("aluno removido\n");
       }
       if(ret == 0)
       {
	 printf("remoçao falhou\n");
       }
       if(ret == -1)
       {
	 printf("lista vazia\n");
       }
       break;
     case 3:
      busca(slot,op);
       break;
     case 4:
       busca(slot,op);
       break;
     case 5:  
       listar(slot);
       break;
     case 6:
       break;
    }
  }while(op != 6);
 return 0;
}

void cadastro(tipoCadastro **lista)
{
  system("clear");
  tipoCadastro *novo = ( tipoCadastro *)malloc(sizeof( tipoCadastro));
                                                                       
  printf("Digite o Nome:");
  __fpurge(stdin);
    fgets(novo->nome, 32, stdin);
  printf("\n Digite o RA:");
    scanf("%i", &(novo->RA));
  printf("\n Digite a Nota:");
    scanf("%f", &(novo->nota));
    
  
  insere(lista,novo);
}

void insere(tipoCadastro **lista,tipoCadastro *novo)
{
  tipoCadastro *atual = *lista;
  tipoCadastro *anterior = NULL;
 
  if(!(*lista)) //lista vazia
  {
   (*lista)=novo;
   novo->prox=NULL;
  }
  else
  {  
  while((atual)&&(atual->RA < novo->RA))
  {
    anterior=atual;
   atual=atual->prox;
  }
    if(!atual) //insere final
    {
      anterior->prox = novo;
      novo->prox= NULL;
    }
    else
    {
     if(!anterior) //insere inicio
     {
	novo->prox=(*lista);
	(*lista)=novo;
      }
      else{
      anterior->prox=novo; //insere qualquer lugar
      novo->prox=atual;
      }
    }
    }
   
}

int remover(tipoCadastro **lista)
{
 tipoCadastro *atual = *lista;
 tipoCadastro *anterior = NULL; 
 int auxRA=0;
 system("clear");
 
  printf("digite o RA que deseja excluir:");
  scanf("%i",&auxRA);
  
  if(!lista)
  {
    return -1;
  }
  else
  {
  while((atual) && (atual->RA != auxRA))
  {
    anterior=atual;
    atual=atual->prox;
  }
  if(!anterior)
  {
    *lista = atual->prox;
    free(atual);
    return 1;
  }
  else
  {
    if(!atual->prox)
    {
      anterior->prox=NULL;
      free(atual);
      return 1;
    }
    else
    {
      anterior->prox = atual->prox;
      free(atual);
      return 1;
    }
  }
  }
 return 0;
}

void busca(tipoCadastro *lista, int op)
{
  int auxRA=0;
  char auxNom[50];
  if(op == 3)
  {
    printf("digite o RA do aluno:");
      scanf("%d",&auxRA);
    while(lista)
    {
      if(lista->RA == auxRA)
      {
	printf("\nNome:%s\n",lista->nome);
	printf("RA:%i\n",lista->RA);
	printf("Nota:%.2f\n",lista->nota);
      }
      lista=lista->prox;
    }
  }
  else
  {
    printf("Digite o Nome do Aluno:");
      __fpurge(stdin);
      fgets(auxNom, 32, stdin);
      
   while(lista)
    {
      if(strcmp(lista->nome,auxNom) == 0)
      {
	printf("\nNome:%s\n",lista->nome);
	printf("RA:%i\n",lista->RA);
	printf("Nota:%.2f\n",lista->nota);
      }
      lista=lista->prox;
    }
  }
}

void listar(tipoCadastro *lista)
{	
  system("clear");
  
    while(lista)
  {
    printf("Nome: %s\nRA:%i\n Nota:%.2f\n",lista->nome,lista->RA,lista->nota);
    lista=lista->prox;
  }
}

