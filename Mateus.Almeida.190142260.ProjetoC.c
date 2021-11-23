#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

//Objetivo: Voc� foi contratado por um clube esportivo para desenvolver um sistema informatizado para gerenciar
//os associados do clube. Esse sistema ser� usado pela secretaria e dever� conter um menu com as
//seguintes op��es:
//1. Cadastrar associado
//2. Cadastrar dependente
//3. Listar associados
//4. Listar associados por modalidade
//5. Pesquisar associados
//6. Gerar relat�rio de associados
//7. Finalizar Programa
//Cada item de menu dever� ser realizado por um procedimento/fun��o espec�fico.
//Entradas: Op��o desejada.
//Sa�das: Resultado da busca ou cadastro.

void menu(cad_associado, cad_dependente);
void cadastro_associado(cad_associado, cad_dependente);
void cadastro_dependente(cad_associado, cad_dependente);
void lista_associados(cad_associado, cad_dependente);
void lista_associados_modalidade(cad_associado, cad_dependente);
void pesquisa_associados(cad_associado, cad_dependente);
void relatorio_associados(cad_associado, cad_dependente);
void finalizar_programa();

typedef struct{
    char nome[20];
    int idade;
}Dependente;

typedef struct{
    int id;
    int idade;
    int qtdDep;
    Dependente dep[3];
    bool natacao;
    bool futsal;
    bool tenis;
    char nome[20];
}Associado;

int contador_associado;
int contador_dependente;

int main(){
    //Declara��es

    Dependente cad_dependente[200];
    Associado cad_associado[200];
    contador_associado=-1;
    contador_dependente=-1;

    //Instru��es

    setlocale(LC_ALL, "Portuguese");
    menu(cad_associado, cad_dependente);

}

//menu de op��es
void menu(Associado cad_associado[], Dependente cad_dependente[]){
    //Declara��es

    int opcao;

    //Instru��es

    printf("_________________________________________________________________");
    printf("\n____________ Sistema de Ger�ncia de Clube Esportivo _____________\n");
    printf("_________________________________________________________________\n\n");
    printf("Op��o 1 - Cadastrar associado\n");
    printf("Op��o 2 - Cadastrar dependente\n");
    printf("Op��o 3 - Listar associados\n");
    printf("Op�ao 4 - Listar associados por modalidade\n");
    printf("Op��o 5 - Pesquisar associados\n");
    printf("Op��o 6 - Gerar relat�rio de associados\n");
    printf("Op��o 7 - Finalizar Programa\n");
    printf("_________________________________________________________________");
    printf("\n\nOp��o desejada: ");
    scanf("%d", &opcao);

    while((opcao>7)||(opcao<1)){
        printf("Op��o n�o encontrada! Digite novamente: ");
        scanf("%d", &opcao);
    }

    switch(opcao){
        case 1:
            contador_associado = contador_associado + 1;
            cadastro_associado(cad_associado, cad_dependente);
            break;
        case 2:
            contador_dependente = contador_dependente + 1;
            cadastro_dependente(cad_associado, cad_dependente);
            break;
        case 3:
            lista_associados(cad_associado, cad_dependente);
            break;
        case 4:
            lista_associados_modalidade(cad_associado, cad_dependente);
            break;
        case 5:
            pesquisa_associados(cad_associado, cad_dependente);
            break;
        case 6:
            relatorio_associados(cad_associado, cad_dependente);
            break;
        case 7:
            finalizar_programa();
            break;
    }
}

//cadastro associado
void cadastro_associado (Associado cad_associado[], Dependente cad_dependente[]){
    //Declara��es

    int i;
    int natacao, futsal, tenis;

    //Instru��es

    printf("_________________________________________________________________");
    for(i=contador_associado; i <= contador_associado; i++){

        //identificador
        printf("\n\nDigite o identificador: ");
        scanf("%d", &cad_associado[i].id);

        //Nome
        printf("\nDigite seu Nome: ");
        fflush(stdin);
        gets(cad_associado[i].nome);



        //Idade
        printf("\nDigite sua idade: ");
        scanf("%d", &cad_associado[i].idade);

        //while para caso idade seja negativa
        while(cad_associado[i].idade<0){
            printf("\nErro! A idade deve ser positiva! Digite sua idade novamente: ");
            scanf("%d", &cad_associado[i].idade);
        }

        //Nata��o
        printf("\nDeclare as modalidades que voc� participa, [0] para n�o participo [1] para participo!\n");
        //caso a op��o seja diferente de 1 e 0 o la�o pede pra digitar novamente
        do{
            printf("\nPratica nata��o?\n");
            printf("0. N�o\n");
            printf("1. Sim\n");
            printf("Digite a op��o: ");
            scanf("%d", &natacao);
            printf("\n");
        }while((natacao != 1)&&(natacao != 0));
        if(natacao == 1){
            cad_associado[i].natacao = true;
        }else{
            cad_associado[i].natacao = false;
        }
        //futsal
        //caso a op��o seja diferente de 1 e 0 o la�o pede pra digitar novamente
        do{
            printf("Pratica futsal?\n");
            printf("0. N�o\n");
            printf("1. Sim\n");
            printf("Digite a op��o: ");
            scanf("%d", &futsal);
            printf("\n");
        }while((futsal!=1)&&(futsal!=0));
        if(futsal == 1){
            cad_associado[i].futsal = true;
        }else{
            cad_associado[i].futsal = false;
        }
        //t�nis
        //caso a op��o seja diferente de 1 e 0 o la�o pede pra digitar novamente
        do{
            printf("Pratica t�nis?\n");
            printf("0. N�o\n");
            printf("1. Sim\n");
            printf("Digite a op��o: ");
            scanf("%d", &tenis);
            printf("\n");
        }while((tenis!=1)&&(tenis!=0));
        if(tenis == 1){
            cad_associado[i].tenis = true;
        }else{
            cad_associado[i].tenis = false;
        }
    }
    //volta para o menu
    menu(cad_associado, cad_dependente);

}
void cadastro_dependente(Associado cad_associado[],Dependente cad_dependente[]){
    //Declara��es

    int i, m, x; //contadores para o for (i=0; i<=1; i++) por exemplo
    int cont_dependente=1, id_nao_encontrado=-1;
    int pesquisa;
    //Instru��es

    printf("_________________________________________________________________");
    //if para caso n�o haja nenhum associado cadastrado no sistema
    if(contador_associado==-1){
        printf("\n\nN�o h� associados cadastrados no sistema!\n");
    }else{
        //pesquisa o identificador de um associado
        printf("\n\nDigite o identificador do associado: ");
        scanf("%d", &pesquisa);
        //for para verificar se existe um associado com o identificador
        for(i=0; i<=contador_associado; i++){
            //se tiver entra no if
            if(cad_associado[i].id == pesquisa){
                //quantidade de dependentes
                printf("Digite a quantidade de dependentes para o cadastro: ");
                scanf("%d", &cad_associado[i].qtdDep);
                while(cad_associado[i].qtdDep > 3){
                    printf("\nO n�mero m�ximo de dependentes foi excedido. M�ximo de 3 dependentes por associado\n");
                    printf("Digite a quantidade de dependentes para o cadastro: ");
                    scanf("%d", &cad_associado[i].qtdDep);
                }
                for(m=0; m<cad_associado[i].qtdDep; m++){
                    //nome dependente
                    printf("\nDigite o nome do %d� dependente: ", cont_dependente);
                    fflush(stdin);
                    gets(cad_dependente[m].nome);
                    //idade dependente
                    printf("Digite a idade do %d� dependente: ", cont_dependente);
                    scanf("%d", &cad_dependente[m].idade);
                    //while para caso a idade do dependente seja negativa
                    while(cad_dependente[m].idade<0){
                        printf("Erro! A idade do dependente deve ser positiva! Digite a idade novamente: ");
                        scanf("%d", &cad_dependente[m].idade);
                    }
                    cont_dependente=cont_dependente+1; //contador para situar qual dependente est� sendo cadastrado
                }
                printf("\nLista dos nomes e idade cadastrados pelo associado para seus dependentes: \n");
                for(x=0; x<cad_associado[i].qtdDep; x++){
                    printf("%s - %d \n", cad_dependente[x].nome, cad_dependente[x].idade);
                }
            }
            if(pesquisa!=cad_associado[i].id){
                id_nao_encontrado=id_nao_encontrado+1;
            }
        }

    }
    if(id_nao_encontrado == contador_associado){
        //caso o identificador nao seja seja encontrado
        printf("Identificador n�o encontrado no sistema!\n");
    }
    //volta para o menu
    menu(cad_associado, cad_dependente);
}

void lista_associados(Associado cad_associado[], Dependente cad_dependente[]){
    //Declara��es

    int i;//contador para o for (i=0; i<=1; i++) por exemplo

    //Instru��es

    printf("_________________________________________________________________");
    //if para caso n�o haja nenhum associado cadastrado no sistema
    if(contador_associado==-1){
        printf("\n\nN�o h� associados cadastrados no sistema!\n");
    }else{
        //lista os associados
        for(i=0; i<= contador_associado; i++){
            printf("\nIdentificador do associado: %d - Nome do associado: %s - Idade do associado: %d - N�mero de dependentes: %d - ",  cad_associado[i].id, cad_associado[i].nome, cad_associado[i].idade, cad_associado[i].qtdDep);
            //if para saber se o associado pratica alguma aula
            if(cad_associado[i].natacao == 1){
                printf("Faz nata��o - ");
            }else{
                printf("N�o faz nata��o - ");
            }
            if(cad_associado[i].futsal == 1){
                printf("Faz futsal - ");
            }else{
                printf("N�o faz futsal - ");
            }
            if(cad_associado[i].tenis == 1){
                printf("Faz t�nis");
            }else{
                printf("N�o faz t�nis");
            }
            printf("\n");
        }
    }
    //volta para o menu
	menu(cad_associado, cad_dependente);

}
void lista_associados_modalidade(Associado cad_associado[], Dependente cad_dependente[]){
    //Declara��es
    int i;//contador para o for (i=0; i<=1; i++) por exemplo
    int opcao;

    //Instru��es

    printf("_________________________________________________________________");
    //if para caso n�o haja nenhum associado cadastrado no sistema
    if(contador_associado == -1){
        printf("\n\nN�o h� associados cadastrados no sistema!\n");
    }else{
        printf("\n_____________Menu lista de associados por modalidade_____________\n");
        printf("\nDigite o n�mero da modalidade para buscar associados que praticam o esporte\n");
        printf("1 - Nata��o\n");
        printf("2 - Futsal\n");
        printf("3 - t�nis\n");
        printf("Op�ao: ");
        scanf("%d", &opcao);
        //caso a op��o digitada n�o seja 1,2 ou 3 pede para o usu�rio digitar novamente
        while((opcao > 3)||(opcao < 1)){
            printf("\nOp��o n�o encontrada! Digite a op��o novamente.\n");
            printf("\nDigite o n�mero da modalidade para buscar associados que praticam o esporte\n");
            printf("1 - Nata��o\n");
            printf("2 - Futsal\n");
            printf("3 - t�nis\n");
            printf("Op�ao: ");
            scanf("%d", &opcao);
        }
        for(i=0; i<=contador_associado; i++){
            if(opcao == 1){ //printa a op��o escolhida, no caso nata��o
                if(cad_associado[i].natacao == 1){
                    printf("\nIdentificador do associado que faz nata��o: %d - Nome do associado que faz nata��o: %s\n", cad_associado[i].id, cad_associado[i].nome);
                }
            }
            if(opcao == 2){ //printa a op��o escolhida, no caso futsal
                if(cad_associado[i].futsal == 1){
                    printf("\nIdentificador do associado que faz futsal: %d - Nome do associado que faz futsal: %s\n", cad_associado[i].id, cad_associado[i].nome);
                }
            }
            if(opcao == 3){ //printa a op��o escolhida, no caso t�nis
                if(cad_associado[i].tenis == 1){
                    printf("\nIdentificador do associado que faz t�nis: %d - Nome do associado que faz t�nis: %s\n", cad_associado[i].id, cad_associado[i].nome);
                }
            }
        }
    }

    //volta para o menu
    menu(cad_associado, cad_dependente);
}
void pesquisa_associados(Associado cad_associado[], Dependente cad_dependente[]){
    //Declara��es

    char pesquisa[20];
    int i; //contador para o for (i=0; i<=1; i++) por exemplo
    int aluno_nao_encontrado=0, qtd_aulas;
    float mensalidade;

    //Instru��es

    printf("_________________________________________________________________");
    //if para caso n�o haja nenhum associado cadastrado no sistema
    if(contador_associado==-1){
        printf("\n\nN�o h� associados cadastrados no sistema!\n");
    }else{
        printf("\n\nDigite o nome do associado: *O nome deve ser digitado conforme cadastrado!*\n");
        fflush(stdin);
        gets(pesquisa);
        for(i=0; i<=contador_associado; i++){
            qtd_aulas=0;
            //compara o nome digitado com o banco de dados do sistema
            if(strcmp(pesquisa,cad_associado[i].nome) == 0 ){
                //ifs para contar quantas aulas o associado faz
                if(cad_associado[i].natacao == 1){
                        qtd_aulas = qtd_aulas + 1;
                    }
                if(cad_associado[i].futsal == 1){
                    qtd_aulas = qtd_aulas + 1;
                    }
                if(cad_associado[i].tenis == 1){
                    qtd_aulas = qtd_aulas + 1;
                    }
                    //c�lculo mensalidade
                    mensalidade = 100 + (50 * cad_associado[i].qtdDep) + (30 * qtd_aulas);
                    printf("Identificador do associado: %d - Nome do associado: %s - Idade do associado: %d - Quantidade de dependentes: %d - Quantidade de aulas praticadas: %d - Valor da mensalidade: R$%.2f \n",  cad_associado[i].id, cad_associado[i].nome, cad_associado[i].idade, cad_associado[i].qtdDep, qtd_aulas, mensalidade);
            }else{
                aluno_nao_encontrado=aluno_nao_encontrado+1;
            }
        }
        // if que retorna erro caso o nome n�o seja encontrado no sistema
        if((aluno_nao_encontrado-1) == contador_associado){
            printf("\nN�o h� associados cadastrados com esse nome no sistema!\n");
        }
    }

     //volta para o menu
    menu(cad_associado, cad_dependente);
}
void relatorio_associados(Associado cad_associado[], Dependente cad_dependente[]){
    //Declara��es
    //contadores -->
    int qtd_dependentes=0, i;
    int contador_natacao=0, contador_futsal=0;
    int contador_tenis=0, qtd_aulas;
    //coloquei as mensalidades como float para conseguir imprimir R$ 100,00 por exemplo, com inteiro o resultado seria s� RS 100.
    float mensalidade_total, maior_mensalidade=0, media_mensalidade;
    float mensalidade[200];
    int aulas_associado[3], mais_aulas=0;
    //Instru��es

    printf("_________________________________________________________________");
    printf("\n\nA quantidade de associado cadastrados no sistema �: %d\n", contador_associado+1 );
    for(i=0; i<=contador_associado; i++){
        //calcula a quantidade de dependentes
        qtd_dependentes= qtd_dependentes+cad_associado[i].qtdDep;
    }
    printf("O n�mero total de dependentes cadastrados �: %d\n", qtd_dependentes);
    //quantidades de aulas feitas por 1 associado
    for(i=0; i<=contador_associado; i++){
        qtd_aulas=0;
        if(cad_associado[i].natacao == 1){
            contador_natacao=contador_natacao+1;
            qtd_aulas=qtd_aulas+1;
        }
        if(cad_associado[i].futsal == 1){
            contador_futsal=contador_futsal+1;
            qtd_aulas=qtd_aulas+1;
        }
        if(cad_associado[i].tenis == 1){
            contador_tenis=contador_tenis+1;
            qtd_aulas=qtd_aulas+1;
        }
        //para listar o nome dos associados que fazem mais aulas
        aulas_associado[i]=qtd_aulas;

        //c�lculo das mensalidades solicitadas
        mensalidade[i] = 100 + (50 * cad_associado[i].qtdDep) + (30 * qtd_aulas);
        mensalidade_total = mensalidade_total + mensalidade[i];
        if(mensalidade[i]>maior_mensalidade){
            maior_mensalidade = mensalidade[i];
        }
        //para listar o nome dos associados que fazem mais aulas
        if(aulas_associado[i]>mais_aulas){
            mais_aulas=aulas_associado[i];
        }
    }
     media_mensalidade = mensalidade_total / (contador_associado + 1);


    printf("O n�mero de associados que fazem aula de Nata��o �: %d\n", contador_natacao);
    printf("O n�mero de associados que fazem aula de Futsal �: %d\n", contador_futsal);
    printf("O n�mero de associados que fazem aula de T�nis �: %d\n", contador_tenis);
    printf("Valor total de todas as mensalidades dos associados: R$ %.2f\n", mensalidade_total);
    printf("Valor m�dio das mensalidades dos associados: R$ %.2f\n", media_mensalidade);
    printf("Valor da mensalidade mais alta paga por um associado: R$ %.2f\n", maior_mensalidade);
    printf("Nome do(s) associado(s) que fazem mais aulas: \n");

    for(i=0; i<= contador_associado; i++){
        if(aulas_associado[i] == mais_aulas){
            printf("Nome: %s\n", cad_associado[i].nome);
        }
    }
    //volta para o menu
    menu(cad_associado, cad_dependente);
}
void finalizar_programa(){
    //Instru��es
    //finaliza o programa
    printf("______________________ Programa encerrado! ______________________\n\n");
}
