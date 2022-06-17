#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ATENÇÃO:Apenas uma ideia inicial para o trabalho
//falta adicionar caixa,mais produtos,metodo de pagamento,entre outros

void MenuProduto();
void MenuPrincipal();
void AdicionarProdutos();

typedef struct{
    float preco;

}DadosProdutos;
//falta adicionar mais produtos
DadosProdutos leite,arroz,queijo,maca;



void AdicionarProdutos(){
    float carrinho = 0;
    char escolherproduto;
    float escolherquantidade;
    float valor_total;
    leite.preco = 7.99;
    arroz.preco = 4.99;
    queijo.preco = 2.99;
    maca.preco = 1.99;

    


    while(1){
        printf("Digite o número correspondente ao produto ou 'P' para parar de adicionar produtos ao carrinho: \n");
        scanf(" %c",&escolherproduto);
        if(escolherproduto=='0'){
            printf("Agora escolha a quantidade de unidades: \n");
            scanf("%f",&escolherquantidade);
            carrinho+=leite.preco*escolherquantidade;
            continue;
        }
        if(escolherproduto=='1'){
            printf("Agora escolha a quantidade de unidades: \n");
            scanf("%f",&escolherquantidade);
            carrinho+=arroz.preco*escolherquantidade;
            continue;
        }
        if(escolherproduto=='2'){
            printf("Agora escolha a quantidade de unidades: \n");
            scanf("%f",&escolherquantidade);
            carrinho+=queijo.preco*escolherquantidade;
            continue;
        }
        if(escolherproduto=='3'){
            printf("Agora escolha a quantidade de unidades: \n");
            scanf("%f",&escolherquantidade);
            carrinho+=maca.preco*escolherquantidade;
            continue;
        }

        if(escolherproduto=='P'){
            carrinho;
            printf("R$:%.2f\n",carrinho);
            printf("Vá ao caixa para realizar o pagamento\n");
            break;
        }
    }   

}

void MenuProdutos(){
    
   
    char opcaomenuProdutos;
    printf("\nDigite 'C' para adicionar o produto ao carrinho \nOu digite 'V' para voltar ao menu principal: \n");
    scanf(" %c",&opcaomenuProdutos);
    if(opcaomenuProdutos=='V'){
        system("clear");
        MenuPrincipal();
    }
    else if(opcaomenuProdutos=='C'){
        AdicionarProdutos();
    }
    



}
//adicionar produtos diretamente no arquivo txt
void VerProduto(){
    FILE *produtos;
    char texto_str[50];
    
    produtos = fopen("produtos.txt","r");

    while(fgets(texto_str,50,produtos)!=NULL){
        printf("\n%s",texto_str);
    }

    fclose(produtos);
    

}
void MenuPrincipal(){
    int opcaomenu;
    
    printf("\n\n ========================== \n");
    printf(" Bem vindo ao supermercado! \n");
    printf(" ========================== \n");

    printf("\n\n /=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/ \n");
    printf(" 1-VER PRODUTOS DISPONIVEIS\n");
    printf(" 2-SAIR\n");
    printf(" /=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/\n");
    printf(" \nDigite a opção: ");
    scanf("%d",&opcaomenu);

    if(opcaomenu==1){
        printf("\n~~~~~~~~~~~~~~~~~~~~~~");
        VerProduto();
        printf("\n~~~~~~~~~~~~~~~~~~~~~~");
        MenuProdutos();
    }
    else if(opcaomenu==2){
        printf("\n ---Agradecemos a preferencia e volte novamente!!!---");
        exit(1);
    }



}



int main(){

    MenuPrincipal();

}
