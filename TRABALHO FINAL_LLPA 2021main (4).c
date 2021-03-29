#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome_cliente[60];
    char cpf[12];
    char numero_cartao[20];
    int senha;
} Cliente;

typedef struct
{
    float diaria_hotel;
    float valor_passagem;
    char origem [50];
    char destino[50];
    char mes_dia_saida[60];
    char mes_dia_retorno[60];
} viagem;


void cadastro(Cliente vet[], int num_cadastro)
{
    getchar();
    printf("\nNome: ");
    gets(vet[num_cadastro].nome_cliente);
    printf("\nCPF: ");
    gets(vet[num_cadastro].cpf);
    printf("\nNumero do cartao de credito: ");
    gets(vet[num_cadastro].numero_cartao);
    printf("\nSenha: ");
    scanf("%d", &vet[num_cadastro].senha);
}

void dados_viagem( viagem vet2[], int num_cadastro)
{
    getchar();
    printf("Origem: ");
    getchar();
    gets(vet2[num_cadastro].origem);
    printf("\nDestino: ");
    gets(vet2[num_cadastro].destino);
    printf("\nDia e mes da saida: ");
    gets(vet2[num_cadastro].mes_dia_saida);
    printf("\nDia e mes do retorno: ");
    gets(vet2[num_cadastro].mes_dia_retorno);
    printf("\nValor Diaria Hotel: ");
    scanf("%f", &vet2[num_cadastro].diaria_hotel);
    printf("\nValor Passagem: ");
    scanf("%f", &vet2[num_cadastro].valor_passagem);
}
void altera_viagem( viagem vet2[], int num_cadastro)
{
    getchar();
    printf("Origem: ");
    printf("Atualmente: %s",vet2[num_cadastro].origem);
    gets(vet2[num_cadastro].origem);
    printf("\nDestino: ");
    printf("Atualmente: %s",vet2[num_cadastro].destino);
    gets(vet2[num_cadastro].destino);
    printf("\nDia e mes da saida: ");
    printf("Atualmente: %s",vet2[num_cadastro].mes_dia_saida);
    gets(vet2[num_cadastro].mes_dia_saida);
    printf("\nDia e mes do retorno: ");
    printf("Atualmente: %s",vet2[num_cadastro].mes_dia_retorno);
    gets(vet2[num_cadastro].mes_dia_retorno);
    printf("\nValor Diaria Hotel: ");
    printf("Atualmente: %f",vet2[num_cadastro].diaria_hotel);
    scanf("%f", &vet2[num_cadastro].diaria_hotel);
    printf("\nValor Passagem: ");
    printf("Atualmente: %f",vet2[num_cadastro].valor_passagem);
    scanf("%f", &vet2[num_cadastro].valor_passagem);
}
float valor_total_viagem(  viagem vet2[], int num_cadastro, int num_noite)
{
    float total = 0;
    int i;
   for(i=0;i<=vet2[num_cadastro].diaria_hotel;i++)
   {
    total = vet2[num_cadastro].valor_passagem + (vet2[num_cadastro].diaria_hotel*num_noite);
   }

   return total;
}
void imprime_viagem( viagem vet2[], int num_cadastro)
{
    printf("Origem: ");
    printf("%s \n",vet2[num_cadastro].origem);
    printf("Destino: ");
    printf("%s \n",vet2[num_cadastro].destino);
    printf("Dia e mes da saida: ");
    printf("%s \n",vet2[num_cadastro].mes_dia_saida);
    printf("Dia e mes do retorno: ");
    printf("%s \n", vet2[num_cadastro].mes_dia_retorno);
    printf("Valor Diaria Hotel:\n ");
    printf("%.2f", vet2[num_cadastro].diaria_hotel);
    printf("\nValor Passagem: ");
    printf("%.2f",vet2[num_cadastro].valor_passagem);
}


int main()
{
    Cliente vet[50];
    viagem vet2[50];
    int i, op;
    int num_noites;

    float v_viagem;

    do
    {
        printf("\nMenu:");
    printf("\n1- Ler informacoes de cadastro");
    printf("\n2- Ler informacoes de viagem");
    printf("\n3- Valor total da viagem");
    printf("\n4- Alteracoes da viagem");
    printf("\n5- Imprimir todos os dados");
    scanf("%d", &op);

    switch(op)
    {
    case 1:
        printf("\nDigite sua posicao de cadastro: ");
        scanf("%d", &i);
        cadastro(vet, i);
        break;
    case 2:
        printf("\nDigite sua posicao de cadastro: ");
        scanf("%d", &i);
        dados_viagem(vet2, i);
        break;
    case 3:
        printf("\nDigite o cadastro da viagem: ");
        scanf("%d", &i);
        printf("\nDigite o numero de noites que pretende ficar ospedado");
        scanf("%d", &num_noites);
        v_viagem=valor_total_viagem(vet2, i, num_noites);
        printf("\nValor total da viagem: %f", v_viagem);
        break;
    case 4:
        printf("\nDigite o cadastro da viagem que deseja alterar: ");
        scanf("%d", &i);
        altera_viagem(vet2, i);
        v_viagem=valor_total_viagem(vet2,i, num_noites);
        break;
    case 5:
        printf("\nDigite sua posicao de cadastro: ");
        scanf("%d", &i);
        imprime_viagem(vet2, i);
        break;
    default :
        printf("\nOperacao invalida!");
         break;
    }
    }while(op!=0);
    return 0;
}
