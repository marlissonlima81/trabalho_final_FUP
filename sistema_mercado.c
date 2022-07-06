#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float Caixa();
void MenuProduto();
void MenuPrincipal();
void MostrarCarrinho();
//void AdicionarProdutos();


typedef struct{
    char nome[100];
    char preco[100];
    char quantidade[100];

}DadosProdutos;

typedef struct{
    float preco_produto;

}valor_produto;

valor_produto leite,arroz,feijao,macarrao,oleo,macarrao,queijo,batata,carne_bovina,frango,peixe,banana;




void Estoque(){
    system("cls");
    char escolha;
    char voltarmenu;

    char estoque[50];
    
    FILE *arquivo_estoque;
    arquivo_estoque = fopen("estoque.txt","a+");
    while(fgets(estoque,50,arquivo_estoque)!=NULL){
        printf("\n%s",estoque);
    }
    
    
    printf("Digite a quantidade de produtos para adicionar ao estoque:");
    int qtdDeProdutosEstoque;
    scanf("%d",&qtdDeProdutosEstoque);
    DadosProdutos *lista_de_produtos = (DadosProdutos*) malloc(qtdDeProdutosEstoque*sizeof(DadosProdutos));

    if(qtdDeProdutosEstoque==0){
        system("cls");
        MenuPrincipal();
    }
    
    else{
        printf("Escreva o nome do produto, o preco dele e a quantidade(Pressione Enter sempre que terminar de escrever uma informacao)\n");
        for(int i=0;i<qtdDeProdutosEstoque;i++){
            scanf(" %[^\n]",lista_de_produtos[i].nome);
            scanf(" %[^\n]",lista_de_produtos[i].preco);
            scanf(" %[^\n]",lista_de_produtos[i].quantidade);
        }
        
        for(int i=0;i<qtdDeProdutosEstoque;i++){
            fprintf(arquivo_estoque,"%s unidades - ",lista_de_produtos[i].quantidade);
            fprintf(arquivo_estoque,"%s - ",lista_de_produtos[i].nome);
            fprintf(arquivo_estoque,"%s\n",lista_de_produtos[i].preco);
        }
        
        printf("Total de produtos adicionados: %d\n",qtdDeProdutosEstoque);
       
        printf("Voce deseja remover algum produto do estoque?\n");
        printf("Digite 'R' para remover e 'N' para nao\n");
        scanf(" %c",&escolha);
        if(escolha=='R'){
            char nome_produto[100];
            printf("Digite o nome do produto para remover do estoque\n");
            scanf(" %s",nome_produto);
            for(int i=0;i<qtdDeProdutosEstoque;i++){
                if(lista_de_produtos[i].nome==nome_produto){
                    lista_de_produtos[i] = lista_de_produtos[qtdDeProdutosEstoque-1];
                    lista_de_produtos = (DadosProdutos*) realloc(lista_de_produtos,(qtdDeProdutosEstoque-1)*sizeof(DadosProdutos));
                    qtdDeProdutosEstoque--;

                    break;

                }
                
            }
            fclose(arquivo_estoque);
            
        
        
        }
        
        else if(escolha=='N'){
            printf("Voltando ao menu principal.....");
            system("cls");
            MenuPrincipal();

            
        }


    }

    free(lista_de_produtos);

}



void AdicionarProdutos(){
    float carrinho = 0;
    char escolherproduto;
    int escolherquantidade;
    float valor_total;
    leite.preco_produto = 7.99;
    arroz.preco_produto = 4.99;
    feijao.preco_produto = 5.99;
    oleo.preco_produto = 3.99;
    macarrao.preco_produto = 6.99;
    queijo.preco_produto=5.99;
    batata.preco_produto=3.99;
    carne_bovina.preco_produto=20.00;
    frango.preco_produto=15.99;
    peixe.preco_produto=10.00;
    banana.preco_produto=1.99;
    
    FILE *arquivo_carrinho = fopen("carrinho.txt","a");


    while(1){
        printf("Digite o numero correspondente ao produto ou 'P' para parar de adicionar produtos ao carrinho: \n");
        scanf(" %c",&escolherproduto);
        switch(escolherproduto){


        
            case '0':
            printf("Agora escolha a quantidade de unidades: \n");
            scanf("%d",&escolherquantidade);
            carrinho+=arroz.preco_produto*escolherquantidade;
            fprintf(arquivo_carrinho,"Arroz - %d unidades",escolherquantidade);
            continue;
        
        
            case '1':
            printf("Agora escolha a quantidade de unidades: \n");
            scanf(" %d",&escolherquantidade);
            carrinho+=leite.preco_produto*escolherquantidade;
            fprintf(arquivo_carrinho,"Leite - %d unidades",escolherquantidade);
            continue;
        
            case '2':
            printf("Agora escolha a quantidade de unidades: \n");
            scanf(" %d",&escolherquantidade);
            carrinho+=feijao.preco_produto*escolherquantidade;
            fprintf(arquivo_carrinho,"Feijao - %d unidades",escolherquantidade);
            continue;
        
            case '3':
            printf("Agora escolha a quantidade de unidades: \n");
            scanf(" %d",&escolherquantidade);
            carrinho+=oleo.preco_produto*escolherquantidade;
            fprintf(arquivo_carrinho,"Oleo - %d unidades",escolherquantidade);
            continue;

            case '4':
            printf("Agora escolha a quantidade de unidades: \n");
            scanf(" %d",&escolherquantidade);
            carrinho+=macarrao.preco_produto*escolherquantidade;
            fprintf(arquivo_carrinho,"Macarrao - %d unidades",escolherquantidade);
            continue;

            case '5':
            printf("Agora escolha a quantidade de unidades: \n");
            scanf(" %d",&escolherquantidade);
            carrinho+=queijo.preco_produto*escolherquantidade;
            fprintf(arquivo_carrinho,"Queijo - %d unidades",escolherquantidade);
            continue;
            
            case '6':
            printf("Agora escolha a quantidade de unidades: \n");
            scanf(" %d",&escolherquantidade);
            carrinho+=batata.preco_produto*escolherquantidade;
            fprintf(arquivo_carrinho,"Batata - %d unidades",escolherquantidade);
            continue;
            
            case '7':
            printf("Agora escolha a quantidade de unidades: \n");
            scanf(" %d",&escolherquantidade);
            carrinho+=carne_bovina.preco_produto*escolherquantidade;
            fprintf(arquivo_carrinho,"Carne Bovina - %d unidades",escolherquantidade);
            continue;
            case '8':
            printf("Agora escolha a quantidade de unidades: \n");
            scanf(" %d",&escolherquantidade);
            carrinho+=frango.preco_produto*escolherquantidade;
            fprintf(arquivo_carrinho,"Frango - %d unidades",escolherquantidade);
            continue;
            case '9':
            printf("Agora escolha a quantidade de unidades: \n");
            scanf(" %d",&escolherquantidade);
            carrinho+=peixe.preco_produto*escolherquantidade;
            fprintf(arquivo_carrinho,"Peixe - %d unidades",escolherquantidade);
            continue;
            case '10':
            printf("Agora escolha a quantidade de unidades: \n");
            scanf(" %d",&escolherquantidade);
            carrinho+=banana.preco_produto*escolherquantidade;
            fprintf(arquivo_carrinho,"Banana - %d unidades",escolherquantidade);
            continue;

            case 'P':
            printf("R$:%.2f\n",carrinho);
            printf("Vá ao caixa para realizar o pagamento\n");
            Caixa(carrinho);
            break;
        }

    }  
    fclose(arquivo_carrinho);


}
float Caixa(double valor_total){
    char escolherPagamento;
    float dinheiroCliente;
    float dinheiroRestante;
    system("cls");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n ");
    printf(" Bem vindo ao Caixa!\n");
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=- \n\n");
    printf(".....Mostrando Carrinho.....");
    MostrarCarrinho();
    printf("\n");
    printf("Sua compra totalizou em R$: %.2f\n",valor_total);

    printf("Qual a forma de pagamento?\n Pix[P]\n Dinheiro[D]\n ");
    printf("\n\nDigite a letra correspondente ao pagamento desejado: ");
    scanf(" %c",&escolherPagamento);

    if(escolherPagamento=='P'){
        printf("\nQR CODE DO PIX: \n");
        char qr_code[100];
        FILE *arquivo_pix = fopen("pix.txt","r");
        while(fgets(qr_code,100,arquivo_pix)!=NULL){
        printf("%s",qr_code);
        }

        fclose(arquivo_pix);
    

    }
    else if(escolherPagamento=='D'){
        printf("Digite a quantia de dinheiro para realizar o pagamento: ");
        scanf("%f",&dinheiroCliente);
        if(dinheiroCliente==valor_total){
            printf("Pagamento realizado com sucesso!\n");
            printf("Obrigado pela compra e volte sempre");
            
        }
        else if(dinheiroCliente<valor_total){
            while(dinheiroCliente<valor_total){
                printf("\n\nValor insuficiente para pagar pela compra\n Adicione R$ %.2f para completar o valor da compra: ",valor_total-dinheiroCliente);
                scanf("%f",&dinheiroRestante);
                dinheiroCliente+=dinheiroRestante;
            }
            printf("Obrigado pela compra e volte sempre");
            
        }
        else{
            printf("Troco:R$ %.2f\n",dinheiroCliente-valor_total);
            printf("Obrigado pela compra e volte sempre");
        }

        
    }

}


void MenuProdutos(){
    
   
    char opcaomenuProdutos;
    printf("\nDigite 'C' para adicionar o produto ao carrinho \nOu digite 'V' para voltar ao menu principal: \n");
    scanf(" %c",&opcaomenuProdutos);
    if(opcaomenuProdutos=='V'){
        system("cls");
        MenuPrincipal();
    }
    else if(opcaomenuProdutos=='C'){
        AdicionarProdutos();
    }
    



}

void MostrarCarrinho(){
    FILE *vercarrinho;
    char texto_str[50];
    
    vercarrinho = fopen("carrinho.txt","r");

    while(fgets(texto_str,50,vercarrinho)!=NULL){
        printf("\n%s",texto_str);
    }

    fclose(vercarrinho);






}

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
    printf(" 2-ESTOQUE(APENAS FUNCIONARIOS)\n");
    printf(" 3-SAIR\n");
    printf(" /=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/\n");
    printf(" \nDigite a opcao: ");
    scanf("%d",&opcaomenu);

    if(opcaomenu==1){
        system("cls");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        VerProduto();
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
        MenuProdutos();
    }
    else if(opcaomenu==2){
        system("cls");
        Estoque();
    }
    else if(opcaomenu==3){
        printf("\n ---Agradecemos a preferencia e volte novamente!!!---");
        exit(1);

    }



}



int main(){

    MenuPrincipal();

}
