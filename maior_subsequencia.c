#include<stdlib.h>
#include<stdio.h>

#define TAMREGISTROS 10

void preencheRegistros(int *registros){
    int i;
    for (i = 0; i < TAMREGISTROS; ++i){
      registros[i] = rand() % (TAMREGISTROS+300);
    }
}

int maximo(int maiorSequencia, int atual){
  return maiorSequencia > atual ? maiorSequencia : atual;
}

int maiorSequenciaCrescente(int *registros,int *tamSubSequencias,int *predecessor){
  //Código para identificar maior sequencia
  int j, i, maiorSequencia;

  for(j=1; j<= TAMREGISTROS; j++){
    tamSubSequencias[j] = 1;
    predecessor[j] = 0;
    for(i=1; i<= j-1; i++){
      if((registros[i]<registros[j]) && (tamSubSequencias[i] + 1 > tamSubSequencias[j])){
        tamSubSequencias[j] = tamSubSequencias[i] + 1;
        predecessor[j] = i;
      }
    }
  }

  maiorSequencia = 0;

  for(i=1; i<= TAMREGISTROS; i++){
    maiorSequencia = maximo(maiorSequencia, tamSubSequencias[i]);
  }

  return maiorSequencia;
}

void imprimeRegistros(int *registros){
  int i;
  printf("\n\nREGISTROS\n");
  printf("--------------------------------------------------------------------------------------------------------------------------------------------\n" );
  for (i = 0; i < TAMREGISTROS; i++){
    printf("%d - ",registros[i]);
  }
}

int menu(){
  int op;
  printf("\n\n\n===================================================== MENU ==================================================================\n");
  printf("1 - Maior Sequencia Crescente \n");
  printf("2 - Printar o vetor original\n");
  printf("0 - SAIR");
  printf("\n\n");
  printf("Digite a opcao desejada:");
  scanf("%d", &op);
  return op;
}


int main(){

  int registros[TAMREGISTROS], opcao, maiorSequencia;
  int tamSubSequencias[TAMREGISTROS], predecessor[TAMREGISTROS];

  preencheRegistros(registros);

  do{
    opcao = menu();
    switch (opcao) {
      case 0: printf("Encerrando ...\n");
      break;
      case 1:
        maiorSequencia = maiorSequenciaCrescente(registros, tamSubSequencias, predecessor);
        printf("\nA maior sequencia e: %d", maiorSequencia);
      break;
      case 2: imprimeRegistros(registros);
      break;
      default:
        printf("Opcao Inexistente\n");
    }
  }while (opcao!=0);
  return 0;
}
