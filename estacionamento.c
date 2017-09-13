/*
 * File:   estacionamento.c
 * Author: Luis Sousa && Joel Babo
 *
 * Created on 28 de Novembro de 2010, 12:54
 */


#include <stdio.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

#define MAXUTILIZADORES  5
#define MAXESTACIONAMENTOS  100

struct utilizadores {
    char nome[255];
    char passe[10];

} utilizador[MAXUTILIZADORES];

struct estacionar {
    int id;
    char matricula[8];
    int classe;
    int hora;
    int minuto;
    int segundo;
    int dia;
    int mes;
    int ano;
    int tempo_inicial;
    int tempo_final;
    float altura;
    int reboque;
    int via_verde;
    int eixos;
    int motociclo;
    int ciclo_motor;
    float preco;

} estacionamento[MAXESTACIONAMENTOS];

struct terminar {
    int id;
    char matricula[8];
    int classe;
    int hora;
    int minuto;
    int segundo;
    int dia;
    int mes;
    int ano;
    int tempo_inicial;
    int tempo_final;
    float altura;
    int reboque;
    int via_verde;
    int eixos;
    int motociclo;
    int ciclo_motor;
    float preco;

} termina_estacionamento[MAXESTACIONAMENTOS];


int ct_utilizador = 0;
int ct_estacionamento = 0;
int ct_terminarEstacionamento = 0;

void sair() {
    int saida;

    system("cls");
    printf("Deseja mesmo sair?\n");
    printf("1- Sim\n");
    printf("0- Nao\n");
    printf("Opcao:");
    scanf("%d", &saida);
    getchar();


    switch (saida) {
        case 0: system("cls");
            break;
        case 1: system("cls");
            printf("Obrigado! \nVolte sempre.\n");
            sleep(1000);
            exit(1);
            break;
        default:
            printf("Opcao Invalida!");
            sleep(1000);
            sair();
            break;
    }
}

void sair1() {
    int saida;

    system("cls");
    printf("Deseja mesmo sair da conta?\n");
    printf("1-Sim\n");
    printf("0-Nao\n");
    printf("Opcao:");
    scanf("%d", &saida);
    getchar();


    switch (saida) {
        case 0: system("cls");
            break;
        case 1: system("cls");
            printf(" Logout Efectuado com Sucesso!\n");
            sleep(2000);
            main();
            break;
        default:
            printf(" Opcao Invalida!");
            sleep(1000);
            sair1();
            break;
    }
}

void criar_utilizador() {
    int i;
    int verificar;

    if (ct_utilizador == 0) {
        printf(" Introduza o nome utilizador -> ");
        fflush(stdin);
        scanf("%s", &utilizador[ct_utilizador].nome);
        printf(" Introduza a passe -> ");
        fflush(stdin);
        scanf("%s", &utilizador[ct_utilizador].passe);
        ct_utilizador++; // incremento o contador utilizadores
        printf("\n Utilizador criado com sucesso!");
        sleep(1000);

    } else {

        if (ct_utilizador <= MAXUTILIZADORES) {
            printf(" Introduza o nome utilizador -> ");
            fflush(stdin);
            scanf("%s", &utilizador[ct_utilizador].nome);

            for (i = 0; i < ct_utilizador; i++) {
                if (strcmp(utilizador[ct_utilizador].nome, utilizador[i].nome) == 0) {
                    verificar = 1; // variavel auxiliar para verificar se o utilizador existe
                    break;
                }
            }

            if (verificar == 1) {
                system("CLS");
                printf("  ----------------------------------------------------------------------------\n");
                printf(" |                                    REGISTO                                 |\n");
                printf("  ----------------------------------------------------------------------------\n");
                printf(" \n");
                printf("\n Utilizador ja utilizado por favor introduza um novo nome de utilizador\n\n");
                criar_utilizador();
            } else {
                printf(" Introduza a passe -> ");
                fflush(stdin);
                scanf("%s", &utilizador[ct_utilizador].passe);
                ct_utilizador++;
                printf("\n Utilizador criado com sucesso!");
                sleep(1000);
            }
        } else {
            printf("|n Nao pode criar mais utilizadores.");
            system("Pause");
        }
    }
}

void efectuar_estacionamento() {

    int i;

    time_t currentTime;
    struct tm *timeinfo;

    /* Obtem a hora actual do sistema */
    currentTime = time(NULL);

    timeinfo = localtime(&currentTime);

    estacionamento[ct_estacionamento].id = ct_estacionamento;
    printf("Introduza a matricula -> ");
    fflush(stdin);
    scanf("%s", &estacionamento[ct_estacionamento].matricula);
    printf("Introduza a altura medida a vertical dp primeiro eixo -> ");
    scanf("%f", &estacionamento[ct_estacionamento].altura);
    printf("Quantos eixos -> ");
    scanf("%d", &estacionamento[ct_estacionamento].eixos);
    printf("\nNota: -> Responda 1-Sim 0-Nao \n\n");
    printf("Reboque -> ");
    scanf("%d", &estacionamento[ct_estacionamento].reboque);
    printf("Via Verde -> ");
    scanf("%d", &estacionamento[ct_estacionamento].via_verde);
    printf("Motociclo -> ");
    scanf("%d", &estacionamento[ct_estacionamento].motociclo);
    printf("Ciclo Motor -> ");
    fflush(stdin);
    scanf("%d", &estacionamento[ct_estacionamento].ciclo_motor);

    estacionamento[ct_estacionamento].hora = timeinfo->tm_hour;
    estacionamento[ct_estacionamento].minuto = timeinfo->tm_min;
    estacionamento[ct_estacionamento].segundo = timeinfo->tm_sec;
    estacionamento[ct_estacionamento].dia = timeinfo->tm_mday;
    estacionamento[ct_estacionamento].mes = timeinfo->tm_mon + 1; /* mês a partir de janeiro, 0-11 */
    estacionamento[ct_estacionamento].ano = timeinfo->tm_year + 1900;
    estacionamento[ct_estacionamento].tempo_inicial = currentTime;
    ct_estacionamento++;
}

void listar_estacionamento() {
    int i;
    if (ct_estacionamento == 0)
        printf("Sem estacionamentos\n");
    else {
        for (i = 0; i < ct_estacionamento; i++) {
            printf("ID Estacionamento -> %d\n", estacionamento[i].id);
            fflush(stdin);
            printf("Matricula -> %s\n", estacionamento[i].matricula);
            fflush(stdin);
            printf("Altura medida a vertical dp primeiro eixo -> %f\n", estacionamento[i].altura);
            printf("Hora Estacionamento -> %0.2d:%0.2d:%0.2d\n", estacionamento[i].hora, estacionamento[i].minuto, estacionamento[i].segundo);
            printf("Data Estacionamento -> %0.2d/%0.2d/%d\n", estacionamento[i].dia, estacionamento[i].mes, estacionamento[i].ano);
            printf("Eixos -> %d\n", estacionamento[i].eixos);
            printf("\nNota: -> 1-Sim 0-Nao\n\n");
            printf("Reboque -> %d\n", estacionamento[i].reboque);
            printf("Via Verde -> %d\n", estacionamento[i].via_verde);
            printf("Motociclo -> %d\n", estacionamento[i].motociclo);
            printf("Ciclo Motor -> %d\n", estacionamento[i].ciclo_motor);

            if (estacionamento[i].altura < 1.10 && (estacionamento[i].motociclo == 1 || estacionamento[i].ciclo_motor == 1 && estacionamento[i].via_verde == 0)) {
                estacionamento[i].classe = 1;
            }
            if (estacionamento[i].altura >= 1.10 && estacionamento[i].eixos == 2) {
                estacionamento[i].classe = 2;
            }
            if (estacionamento[i].altura >= 1.10 && estacionamento[i].eixos == 3) {
                estacionamento[i].classe = 3;
            }
            if (estacionamento[i].altura >= 1.10 && estacionamento[i].eixos > 3) {
                estacionamento[i].classe = 4;
            }
            if ((estacionamento[i].motociclo == 1 || estacionamento[i].ciclo_motor == 1) && estacionamento[i].via_verde == 1) {
                estacionamento[i].classe = 5;
            }
            printf("Classe -> %d\n\n\n", estacionamento[i].classe);
        }
    }
    system("Pause");
}

void listar_termina() {
    int i;

    for (i = 0; i < ct_terminarEstacionamento; i++) {
        printf("ID termina Estacionamento -> %d\n", termina_estacionamento[i].id);
        fflush(stdin);
        printf("Matricula -> %s\n", termina_estacionamento[i].matricula);
        fflush(stdin);
        printf("Altura medida a vertical dp primeiro eixo -> %f\n", termina_estacionamento[i].altura);
        printf("Hora Estacionamento -> %0.2d:%0.2d:%0.2d\n", termina_estacionamento[i].hora, termina_estacionamento[i].minuto, termina_estacionamento[i].segundo);
        printf("Data Estacionamento -> %0.2d/%0.2d/%d\n", termina_estacionamento[i].dia, termina_estacionamento[i].mes, termina_estacionamento[i].ano);
        printf("Eixos -> %d\n", termina_estacionamento[i].eixos);
        printf("\nNota: -> 1-Sim 0-Nao\n\n");
        printf("Reboque -> %d\n", termina_estacionamento[i].reboque);
        printf("Via Verde -> %d\n", termina_estacionamento[i].via_verde);
        printf("Motociclo -> %d\n", termina_estacionamento[i].motociclo);
        printf("Ciclo Motor -> %d\n", termina_estacionamento[i].ciclo_motor);
        printf("Preco -> %f\n", termina_estacionamento[i].preco);
        printf("Classe -> %d\n\n\n", termina_estacionamento[i].classe);
        fflush(stdin);
    }
    system("Pause");
}

void destacionar() {

    int id;
    int i;
    int ver_id;
    int pos;

    time_t currentTime;
    struct tm *timeinfo;

    if (ct_estacionamento == 0) {
        printf("Sem estacionamentos efectuados - Impossivel Terminar estacionamentos\n\n");
        system("Pause");
    } else {
        printf("Qual o id do veiculo que deseja terminar o estacionamento -> ");
        scanf("%d", &id);

        for (i = 0; i < ct_estacionamento; i++) {
            if (estacionamento[i].id == id) {
                ver_id = 1;
                break;
            }
        }

        if (ver_id == 1) {

            currentTime = time(NULL);
            timeinfo = localtime(&currentTime);
            estacionamento[id].tempo_final = currentTime - estacionamento[id].tempo_inicial;

            if (estacionamento[id].tempo_final <= 7200) {
                if (estacionamento[id].classe == 1) {
                    if (estacionamento[id].tempo_final >= 0 && estacionamento[id].tempo_final <= 1800) {
                        estacionamento[id].preco = 0.50;
                        printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                    }
                    if (estacionamento[id].tempo_final > 1800 && estacionamento[id].tempo_final <= 3600) {
                        estacionamento[id].preco = 1.00;
                        printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                    }
                    if (estacionamento[id].tempo_final > 3600 && estacionamento[id].tempo_final <= 5400) {
                        estacionamento[id].preco = 1.50;
                        printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                    }
                    if (estacionamento[id].tempo_final > 5400 && estacionamento[id].tempo_final <= 7200) {
                        estacionamento[id].preco = 2.00;
                        printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                    }


                }
                if (estacionamento[id].classe == 2) {
                    if (estacionamento[id].tempo_final >= 0 && estacionamento[id].tempo_final <= 1800) {
                        estacionamento[id].preco = 1.00;
                        printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                    }
                    if (estacionamento[id].tempo_final > 1800 && estacionamento[id].tempo_final <= 3600) {
                        estacionamento[id].preco = 2.00;
                        printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                    }
                    if (estacionamento[id].tempo_final > 3600 && estacionamento[id].tempo_final <= 5400) {
                        estacionamento[id].preco = 3.00;
                        printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                    }
                    if (estacionamento[id].tempo_final > 5400 && estacionamento[id].tempo_final <= 7200) {
                        estacionamento[id].preco = 4.00;
                        printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                    }
                }
                if (estacionamento[id].classe == 3) {
                    if (estacionamento[id].tempo_final >= 0 && estacionamento[id].tempo_final <= 1800) {
                        estacionamento[id].preco = 1.20;
                        printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                    }
                    if (estacionamento[id].tempo_final > 1800 && estacionamento[id].tempo_final <= 3600) {
                        estacionamento[id].preco = 2.40;
                        printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                    }
                    if (estacionamento[id].tempo_final > 3600 && estacionamento[id].tempo_final <= 5400) {
                        estacionamento[id].preco = 3.60;
                        printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                    }
                    if (estacionamento[id].tempo_final > 5400 && estacionamento[id].tempo_final <= 7200) {
                        estacionamento[id].preco = 4.80;
                        printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                    }
                }
                if (estacionamento[id].classe == 4) {
                    if (estacionamento[id].tempo_final >= 0 && estacionamento[id].tempo_final <= 1800) {
                        estacionamento[id].preco = 1.50;
                        printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                    }
                    if (estacionamento[id].tempo_final > 1800 && estacionamento[id].tempo_final <= 3600) {
                        estacionamento[id].preco = 3.00;
                        printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                    }
                    if (estacionamento[id].tempo_final > 3600 && estacionamento[id].tempo_final <= 5400) {
                        estacionamento[id].preco = 4.50;
                        printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                    }
                    if (estacionamento[id].tempo_final > 5400 && estacionamento[id].tempo_final <= 7200) {
                        estacionamento[id].preco = 6.00;
                        printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                    }
                }
                if (estacionamento[id].classe == 5) {
                    if (estacionamento[id].tempo_final >= 0 && estacionamento[id].tempo_final <= 1800) {
                        estacionamento[id].preco = 0.10;
                        printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                    }
                    if (estacionamento[id].tempo_final > 1800 && estacionamento[id].tempo_final <= 3600) {
                        estacionamento[id].preco = 0.20;
                        printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                    }
                    if (estacionamento[id].tempo_final > 3600 && estacionamento[id].tempo_final <= 5400) {
                        estacionamento[id].preco = 0.30;
                        printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                    }
                    if (estacionamento[id].tempo_final > 5400 && estacionamento[id].tempo_final <= 7200) {
                        estacionamento[id].preco = 0.40;
                        printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                    }
                }
            } else {
                if (estacionamento[id].classe == 1) {
                    estacionamento[id].preco = (estacionamento[id].tempo_final / 3600) * 0.21;
                    printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                }
                if (estacionamento[id].classe == 2) {
                    estacionamento[id].preco = (estacionamento[id].tempo_final / 3600) * 0.42;
                    printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                }
                if (estacionamento[id].classe == 3) {
                    estacionamento[id].preco = (estacionamento[id].tempo_final / 3600) * 0.50;
                    printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                }
                if (estacionamento[id].classe == 4) {
                    estacionamento[id].preco = (estacionamento[id].tempo_final / 3600) * 0.63;
                    printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                }
                if (estacionamento[id].classe == 5) {
                    estacionamento[id].preco = (estacionamento[id].tempo_final / 3600) * 0.042;
                    printf("Devera pagar %f euro(s)\n", estacionamento[id].preco);
                }
            }


            // Pega no estacionamento e passa-o para termina_estacionamento
            termina_estacionamento[ct_terminarEstacionamento].id = ct_terminarEstacionamento;
            fflush(stdin);
            strcpy(termina_estacionamento[ct_terminarEstacionamento].matricula, estacionamento[id].matricula);
            fflush(stdin);
            termina_estacionamento[ct_terminarEstacionamento].altura = estacionamento[id].altura;
            termina_estacionamento[ct_terminarEstacionamento].eixos = estacionamento[id].eixos;
            termina_estacionamento[ct_terminarEstacionamento].reboque = estacionamento[id].reboque;
            termina_estacionamento[ct_terminarEstacionamento].via_verde = estacionamento[id].via_verde;
            termina_estacionamento[ct_terminarEstacionamento].motociclo = estacionamento[id].motociclo;
            termina_estacionamento[ct_terminarEstacionamento].ciclo_motor = estacionamento[id].ciclo_motor;
            termina_estacionamento[ct_terminarEstacionamento].classe = estacionamento[id].classe;
            termina_estacionamento[ct_terminarEstacionamento].hora = estacionamento[id].hora;
            termina_estacionamento[ct_terminarEstacionamento].minuto = estacionamento[id].minuto;
            termina_estacionamento[ct_terminarEstacionamento].segundo = estacionamento[id].segundo;
            termina_estacionamento[ct_terminarEstacionamento].dia = estacionamento[id].dia;
            termina_estacionamento[ct_terminarEstacionamento].mes = estacionamento[id].mes;
            termina_estacionamento[ct_terminarEstacionamento].ano = estacionamento[id].ano;
            termina_estacionamento[ct_terminarEstacionamento].preco = estacionamento[id].preco;

            ct_terminarEstacionamento++;



            for (i = 0; i < ct_estacionamento; i++) {
                if (estacionamento[i].id == id) {
                    pos = i;
                    break;
                }
            }

            for (i = pos; i < ct_estacionamento; i++) {
                estacionamento[i] = estacionamento[i + 1];
            }
            ct_estacionamento--;
            printf("Estacionamento terminado com sucesso\n");
            system("Pause");
        } else {
            printf("ID nao existente\n");
            sleep(2000);
        }
    }

}

estacionamento_todos() {
    int i;


    for (i = 0; i < ct_estacionamento; i++) {
            fflush(stdin);
            printf("Matricula -> %s\n", estacionamento[i].matricula);
            fflush(stdin);
            printf("Altura medida a vertical dp primeiro eixo -> %f\n", estacionamento[i].altura);
            printf("Hora Estacionamento -> %0.2d:%0.2d:%0.2d\n", estacionamento[i].hora, estacionamento[i].minuto, estacionamento[i].segundo);
            printf("Data Estacionamento -> %0.2d/%0.2d/%d\n", estacionamento[i].dia, estacionamento[i].mes, estacionamento[i].ano);
            printf("Tempo inicial -> %d\n", estacionamento[i].tempo_inicial);
            printf("Eixos -> %d\n", estacionamento[i].eixos);
            printf("\nNota: -> 1-Sim 0-Nao\n\n");
            printf("Reboque -> %d\n", estacionamento[i].reboque);
            printf("Via Verde -> %d\n", estacionamento[i].via_verde);
            printf("Motociclo -> %d\n", estacionamento[i].motociclo);
            printf("Ciclo Motor -> %d\n", estacionamento[i].ciclo_motor);
            printf("Classe -> %d\n\n\n", estacionamento[i].classe);
        }

    for (i = 0; i < ct_terminarEstacionamento; i++) {

            fflush(stdin);
            printf("Matricula -> %s\n", termina_estacionamento[i].matricula);
            fflush(stdin);
            printf("Altura medida a vertical dp primeiro eixo -> %f\n", termina_estacionamento[i].altura);
            printf("Hora Estacionamento -> %0.2d:%0.2d:%0.2d\n", termina_estacionamento[i].hora, termina_estacionamento[i].minuto, termina_estacionamento[i].segundo);
            printf("Data Estacionamento -> %0.2d/%0.2d/%d\n", termina_estacionamento[i].dia, termina_estacionamento[i].mes, termina_estacionamento[i].ano);
            printf("Eixos -> %d\n", termina_estacionamento[i].eixos);
            printf("\nNota: -> 1-Sim 0-Nao\n\n");
            printf("Reboque -> %d\n", termina_estacionamento[i].reboque);
            printf("Via Verde -> %d\n", termina_estacionamento[i].via_verde);
            printf("Motociclo -> %d\n", termina_estacionamento[i].motociclo);
            printf("Ciclo Motor -> %d\n", termina_estacionamento[i].ciclo_motor);
            printf("Classe -> %d\n\n\n", termina_estacionamento[i].classe);

    }
    system("Pause");
}

estacionamento_classe()
{
  int i;
  int classe_saber;

  printf("Introduza a classe que quer saber ->");
  scanf("%d",&classe_saber);


  for (i = 0; i < ct_estacionamento; i++) {
      if(estacionamento[i].classe == classe_saber)
      {
            fflush(stdin);
            printf("\nMatricula -> %s\n", estacionamento[i].matricula);
            fflush(stdin);
            printf("Altura medida a vertical dp primeiro eixo -> %f\n", estacionamento[i].altura);
            printf("Hora Estacionamento -> %0.2d:%0.2d:%0.2d\n", estacionamento[i].hora, estacionamento[i].minuto, estacionamento[i].segundo);
            printf("Data Estacionamento -> %0.2d/%0.2d/%d\n", estacionamento[i].dia, estacionamento[i].mes, estacionamento[i].ano);
            printf("Eixos -> %d\n", estacionamento[i].eixos);
            printf("\nNota: -> 1-Sim 0-Nao\n\n");
            printf("Reboque -> %d\n", estacionamento[i].reboque);
            printf("Via Verde -> %d\n", estacionamento[i].via_verde);
            printf("Motociclo -> %d\n", estacionamento[i].motociclo);
            printf("Ciclo Motor -> %d\n", estacionamento[i].ciclo_motor);
            printf("Classe -> %d\n\n\n", estacionamento[i].classe);
            }
        }

    for (i = 0; i < ct_terminarEstacionamento; i++) {

         if(termina_estacionamento[i].classe == classe_saber)
         {
            fflush(stdin);
            printf("Matricula -> %s\n", termina_estacionamento[i].matricula);
            fflush(stdin);
            printf("Altura medida a vertical dp primeiro eixo -> %f\n", termina_estacionamento[i].altura);
            printf("Hora Estacionamento -> %0.2d:%0.2d:%0.2d\n", termina_estacionamento[i].hora, termina_estacionamento[i].minuto, termina_estacionamento[i].segundo);
            printf("Data Estacionamento -> %0.2d/%0.2d/%d\n", termina_estacionamento[i].dia, termina_estacionamento[i].mes, termina_estacionamento[i].ano);
            printf("Eixos -> %d\n", termina_estacionamento[i].eixos);
            printf("\nNota: -> 1-Sim 0-Nao\n\n");
            printf("Reboque -> %d\n", termina_estacionamento[i].reboque);
            printf("Via Verde -> %d\n", termina_estacionamento[i].via_verde);
            printf("Motociclo -> %d\n", termina_estacionamento[i].motociclo);
            printf("Ciclo Motor -> %d\n", termina_estacionamento[i].ciclo_motor);
            printf("Classe -> %d\n\n\n", termina_estacionamento[i].classe);
            }
    }
    system("Pause");
}
montante_estacionamentos() {
    int i;
    float auxiliar = 0;

    for (i = 0; i < ct_terminarEstacionamento; i++) {
        auxiliar = auxiliar + termina_estacionamento[i].preco;

    }
    printf("A soma de todos os estacionamentos da: %f euro(s)\n", auxiliar);
    system("Pause");
}

montante_estacionamento_mes() {
    int i, m;
    float auxiliar = 0;

    printf(" Introduza o mes que quer saber montante ");
    scanf("%d", &m);

    for (i = 0; i < ct_terminarEstacionamento; i++) {
        if (termina_estacionamento[i].mes == m) {
            auxiliar = auxiliar + termina_estacionamento[i].preco;
        }
    }
    printf("A soma dos estacionamentos no mes: %f euro(s)\n", auxiliar);
    system("Pause");
}

montante_estacionamento_ano() {
    int i;
    int a;
    float auxiliar = 0;

    printf(" Introduza o ano que quer saber montante ");
    scanf("%d", &a);

    for (i = 0; i < ct_terminarEstacionamento; i++) {
        if (termina_estacionamento[i].ano == a) {
            auxiliar = auxiliar + termina_estacionamento[i].preco;
        }
    }
    printf("A soma dos estacionamentos no ano: %f euro(s)\n", auxiliar);
    system("Pause");
}

montante_estacionamento_viatura() {
    int i;
    char matricula1[8];
    float auxiliar = 0;

    printf(" Introduza a matricula da viatura que quer saber montante ");
    fflush(stdin);
    scanf("%s", &matricula1);

    for (i = 0; i < ct_terminarEstacionamento; i++) {
        if (strcmp(termina_estacionamento[i].matricula, matricula1) == 0) {
            auxiliar = auxiliar + termina_estacionamento[i].preco;
        }
    }
    printf("A soma dos estacionamentos da viatura e: %f euro(s)\n", auxiliar);
    system("Pause");
}

void menu2() {
    int opcao;
    while (opcao != 0) {
        system("cls");
        printf("  ----------------------------------------------------------------------------\n");
        printf(" |                               MENU SECUNDARIO                              |\n");
        printf("  ----------------------------------------------------------------------------\n");
        printf("  -------------------------------------------------- \n");
        printf(" |   1-  Registar Estacionamentos                   |\n");
        printf(" |   2-  Exibir Carros Estacionados                 |\n");
        printf(" |   3-  Terminar Estacionamento                    |\n");
        printf(" |   4-  Exibir Carros Terminaram Estacionamento    |\n");
        printf(" |--------------------------------------------------|\n");
        printf(" |   Estacionamentos:                               |\n");
        printf(" |                                                  |\n");
        printf(" |   5-  Todos                                      |\n");
        printf(" |   6-  Por classe                                 |\n");
        printf(" |--------------------------------------------------|\n");
        printf(" |   Montantes Apurados:                            |\n");
        printf(" |                                                  |\n");
        printf(" |   7-  Em Todos Estacionamentos                   |\n");
        printf(" |   8-  Num Dado Mes                               |\n");
        printf(" |   9-  Num Dado Ano                               |\n");
        printf(" |   10- Relativamente a Uma Determinada Viatura    |\n");
        printf(" |   11- Sair deste menu                            |\n");
        printf("  -------------------------------------------------- \n");
        printf("Opcao.: ");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao) {
            case 1: system("cls");
                efectuar_estacionamento();
                break;
            case 2: system("cls");
                listar_estacionamento();
                break;
                break;
            case 3: system("cls");
                destacionar();
                break;
            case 4: system("cls");
                listar_termina();
                break;
            case 5: system("cls");
                estacionamento_todos();
                break;
            case 6: system("cls");
                 estacionamento_classe();
                break;
            case 7: system("cls");
                montante_estacionamentos();
                break;
            case 8: system("cls");
                montante_estacionamento_mes();
                break;
            case 9: system("cls");
                montante_estacionamento_ano();
                break;
            case 10: system("cls");
                montante_estacionamento_viatura();
                break;
            case 11: system("cls");
                sair1();
                break;
            default:
                printf("Opcao Invalida!");
                sleep(1000);
                menu2();
                break;
        }
    }
}

void login() {
    int i = 0;
    int a = 0;
    int b = 4;
    int verificar;
    char utilizadores[255];
    char palavra[10];

    while (b > 1) {
        system("cls");
        b--;
        printf(" Tentativas Restantes: %d\n\n", b);
        printf(" Introduza o nome utilizador: ");
        fflush(stdin);
        scanf("%s", &utilizadores);
        printf(" Introduza a passe: ");
        fflush(stdin);
        scanf("%s", &palavra);

        for (i = 0; i <= ct_utilizador; i++) {

            if (strcmp(utilizadores, utilizador[i].nome) == 0 && strcmp(palavra, utilizador[i].passe) == 0) {
                verificar = 1;
            }
        }

        if (verificar == 1) {
            printf("\n Login efectuado com sucesso!\n");
            sleep(1000);
            menu2();
        } else {
            printf("\n Dados Incorrectos!\n");
            sleep(1000);
        }

    }

}

void menu1() {
    int opcao;

    while (opcao != 0) {
        system("cls");
        printf("  ----------------------------------------------------------------------------\n");
        printf(" |                               MENU PRINCIPAL                               |\n");
        printf("  ----------------------------------------------------------------------------\n");
        printf("  ----------------------------\n");
        printf(" |                            |\n");
        printf(" |   1- Registar Utilizador   |\n");
        printf(" |                            |\n");
        printf(" |   2- Fazer Login           |\n");
        printf(" |____________________________|\n");
        printf(" |                            |\n");
        printf(" |   3- Sair                  |\n");
        printf("  ----------------------------\n");
        printf(" Opcao .: ");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao) {
            case 1: system("cls");
                printf("  ----------------------------------------------------------------------------\n");
                printf(" |                                    REGISTO                                 |\n");
                printf("  ----------------------------------------------------------------------------\n");
                printf(" \n");
                criar_utilizador();
                break;
            case 2: system("cls");
                printf("  ----------------------------------------------------------------------------\n");
                printf(" |                                     LOGIN                                  |\n");
                printf("  ----------------------------------------------------------------------------\n");
                printf(" \n");
                login();
                break;
            case 3: system("cls");
                sair();
                break;
            default:
                printf("Opcao Invalida!");
                sleep(1000);
                menu1();
                break;
        }
    }
}

int main() {
    menu1();
    system("Pause");
}


