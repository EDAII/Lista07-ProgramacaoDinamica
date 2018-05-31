#include<stdlib.h>
#include<stdio.h>

#define TAMREGISTROS 10

void preencheRegistros(int *registros){
    int i;
    for (i = 0; i < TAMREGISTROS; ++i){
      registros[i] = rand() % (TAMREGISTROS+300);
    }
}

void maiorSequenciaCrescente(int *registros){
  //Código para identificar maior sequencia
}

void maiorSequenciaX(int *registros, int posicao){
  //Código para identificar maior sequencia até posicao x
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

  int registros[TAMREGISTROS], opcao;

  preencheRegistros(registros);

  do{
    opcao = menu();
    switch (opcao) {
      case 0: printf("Encerrando ...\n");
      break;
      case 1:
        maiorSequenciaCrescente(registros);
      break;
      case 2: imprimeRegistros(registros);
      break;
      default:
        printf("Opcao Inexistente\n");
    }
  }while (opcao!=0);
  return 0;
}
