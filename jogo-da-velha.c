#include "jogo-da-velha.h"

//-------------------------------------------------------------------------------------------------
//                                       MENUS
void printarMANUAL() {
    CENTROSemEspaco; printf("  \t\t  Jogo da velha\n");
    CENTROSemEspaco; printf("+-----------------------------------------------+");                       QUEBRA_LINHA;
    CENTROSemEspaco; printf("|\t\t %s MANUAL DE USO %19s|" ,VERMELHO, SEM_COR);                         QUEBRA_LINHA;
    CENTROSemEspaco; printf("|  Para selecionar uma das alternativas use:    |");                       QUEBRA_LINHA;
    CENTROSemEspaco; printf("|\t- Setas do teclado              \t|");                                  QUEBRA_LINHA;
    CENTROSemEspaco; printf("|\t- As letras: w, a, s, d         \t|");                                  QUEBRA_LINHA;
    CENTROSemEspaco; printf("|\t- Numeros das alternativas      \t|");                                  QUEBRA_LINHA;
    CENTROSemEspaco; printf("|  Apos ir ate a alternativa aperte %sENTER %9s|", VERDE, SEM_COR);        QUEBRA_LINHA;
    CENTROSemEspaco; printf("+-----------------------------------------------+");                       QUEBRA_LINHA;
    QUEBRA_LINHA;
}

//-------------------------------------------------------------------------------------------------

// Mostra uma mensagem de erro caso a tecla precionada não for valida
void tecla_invalida(char *CONTROLE_DE_COR[], void *(printarMENU) (char**)){
    APAGAR_TELA;
    printarMENU(CONTROLE_DE_COR);
    QUEBRA_LINHA;
    CENTRALIZAR; printf("\t\t%sTecla invalida!!%s\n", VERMELHO, SEM_COR);
    CENTRALIZAR; printf("\tPor favor, use uma tecla valida.\n");
    CENTRALIZAR; printf("\t  Caso tenha duvida aperte %sESC%s\n", VERMELHO, SEM_COR);
}
//-------------------------------------------------------------------------------------------------

void menuCentral(char *CONTROLE_DE_COR[]) {
    CENTRO; printf("+-----------------------------------------+\n");
    CENTRO; printf("| Escolha uma alternativa   |\n");
    CENTRO; printf("+-----------------------------------------+\n");
    CENTRO; printf("| [%s 0 %s] PROTOTIPO           \t     |\n",      CONTROLE_DE_COR[0], SEM_COR);
    CENTRO; printf("+-----------------------------------------+\n");
}

//-------------------------------------------------------------------------------------------------
void jogoDaVelha(char *CONTROLE_DE_COR[3][3]) {
    CENTRO; printf(" %s%c%s | %s%c%s | %s%c%s \n", CONTROLE_DE_COR[0][0], '1', SEM_COR, CONTROLE_DE_COR[0][1], '2', SEM_COR, CONTROLE_DE_COR[0][2], '3', SEM_COR);
    CENTRO; printf("---+---+---\n");
    CENTRO; printf(" %s%c%s | %s%c%s | %s%c%s \n", CONTROLE_DE_COR[1][0], '4', SEM_COR, CONTROLE_DE_COR[1][1], '5', SEM_COR, CONTROLE_DE_COR[1][2], '6', SEM_COR);
    CENTRO; printf("---+---+---\n");
    CENTRO; printf(" %s%c%s | %s%c%s | %s%c%s \n", CONTROLE_DE_COR[2][0], '7', SEM_COR, CONTROLE_DE_COR[2][1], '8', SEM_COR, CONTROLE_DE_COR[2][2], '9', SEM_COR);
}

//-------------------------------------------------------------------------------------------------

// Verifica se uma tecla foi precionada, caso tenha sido devolve a numero inteiro da tecla
int tecla(){
    int vartecla=0;
    while(1){
        if(kbhit()){
            int vartecla = getch();
            return(vartecla);
        }
    }
}
//-------------------------------------------------------------------------------------------------
int centralDeJogo(){
 // Array de cores, COM_COR vai pintar o texto de uma certa cor, já a SEM_COR vai deixar o texto com a cor padrão
    char *CONTROLE_DE_COR[][3] = {VERDE, SEM_COR, SEM_COR, SEM_COR, SEM_COR, SEM_COR, SEM_COR, SEM_COR, SEM_COR, SEM_COR, SEM_COR, SEM_COR};

    // A variavel lugar é usada para saber onde se encontra o numero "COM_COR"
    // Ela é alterada baseado na escolha do usuario
    int horizontal = 0;
    int vertical = 0;
    // Printa o menu que esta sendo utilizado no momento
    jogoDaVelha(CONTROLE_DE_COR);

    while(1) {
        int tecla_precionada = controleTeclaJogo(&vertical, &horizontal, 9, jogoDaVelha, CONTROLE_DE_COR);

        if(tecla_precionada == 13) {
            CENTROSemEspaco; printf("\t    %s Programa finalizado!! %s\n", VERMELHO ,SEM_COR);
            exit(0);
        }

        // Se foi precionado ENTER finaliza a função, ENTER = 13
        if(tecla_precionada == 13){
            APAGAR_TELA;
            // A variavel lugar começa a ser contado do 0, enquanto todos os switch-case começam no 1 então para se adequar soma 1 a ele
            return 0;
        }
    } // Fim do while
}
//-------------------------------------------------------------------------------------------------

// Controla qual tecla foi precionada, função generica para funcionar nos outros menus
// Geral:
// Letra A = 97 || Letra S = 115 || Letra D  = 100 || Letra W = 119
// ESC = 27

// No windows:
// Seta para cima =  72 || Seta para direita = 77 || Seta para baixo = 80 || Seta para esquerda = 75  || ENTER = 13

// No linux:
// Seta para cima =  65 || Seta para direita = 67 || Seta para baixo = 66 || Seta para esquerda = 68  || ENTER = 10

int controleTeclaJogo(int *vertical, int *horizontal,  int limite, void *(printarMENU) (char***), char *CONTROLE_DE_COR[3][3]) {

        int tecla_precionada = 0;

        do {
            if(kbhit()) {
                tecla_precionada = tecla();
            }
        } while(tecla_precionada == 0 || tecla_precionada == 224);


        if(tecla_precionada == 13){
            return tecla_precionada;
        }

        if(tecla_precionada == BAIXO || tecla_precionada == 115 ) {
            CONTROLE_DE_COR[*vertical][*horizontal] = SEM_COR;

            // Faz o numero com cor descer uma casa
            (*vertical)++;

            // Faz o numero com cor voltar pro inicio
            if(*vertical >= 3){
                *vertical = 0;
            }

        } else if (tecla_precionada == CIMA || tecla_precionada == 119) {
            CONTROLE_DE_COR[*vertical][*horizontal] = SEM_COR;

            // Faz o numero com cor descer uma casa
            (*vertical)--;

            // Faz o numero com cor voltar pro inicio
            if(*vertical < 0){
                *vertical = 2;
            }

        } else if (tecla_precionada == DIREITA || tecla_precionada == 100) {
            CONTROLE_DE_COR[*vertical][*horizontal] = SEM_COR;

            // Faz o numero com cor descer uma casa
            (*horizontal)++;

            // Faz o numero com cor voltar pro inicio
            if(*horizontal >= 3){
                *horizontal = 0;
            }

        } else if (tecla_precionada == ESQUERDA || tecla_precionada == 97) {
            CONTROLE_DE_COR[*vertical][*horizontal] = SEM_COR;

            // Faz o numero com cor descer uma casa
            (*horizontal)--;

            // Faz o numero com cor voltar pro inicio
            if(*horizontal < 0){
                *horizontal = 2;
            }

        }



        APAGAR_TELA;
        CONTROLE_DE_COR[*vertical][*horizontal] = VERDE;  // Pinta o nome com cor, antes ele estava apenas sendo "monitorado"

        printarMENU(CONTROLE_DE_COR);
        printf("Tecla precionada: %i\n", tecla_precionada);
        return tecla_precionada;
/*
        else if (tecla_precionada == ESQUERDA || tecla_precionada == CIMA || tecla_precionada == 97 || tecla_precionada == 119) {
            CONTROLE_DE_COR[*lugar] = SEM_COR;

            // Faz o numero com cor subir uma casa
           (*lugar)--;

            // Faz o numero com cor voltar pro final
            if(*lugar < 0){
                *lugar = limite;
            }

        // Verifica se foi apertado um numero(0 a 9)
        } else if (tecla_precionada >= 48 && tecla_precionada <= 57) {
            CONTROLE_DE_COR[*lugar] = SEM_COR;
            alterar_variavel_lugar(tecla_precionada, lugar);

            if((*lugar) > limite) {
                *lugar = 0;
                CONTROLE_DE_COR[*lugar] = COM_COR;
                tecla_invalida(CONTROLE_DE_COR, printarMENU);
                return tecla_precionada;
            }
            // Simula um ENTER precionado, para quando o usuario apertar um numero ir direto
            tecla_precionada = 13;
            APAGAR_TELA;
            return tecla_precionada;
        } else if(tecla_precionada == 27) {
            APAGAR_TELA;
            printarMANUAL();
            printarMENU(CONTROLE_DE_COR);
            return tecla_precionada;
        } else {
                tecla_invalida(CONTROLE_DE_COR, printarMENU);
                return tecla_precionada;
        }
    APAGAR_TELA;
    CONTROLE_DE_COR[*lugar] = COM_COR;  // Pinta o nome com cor, antes ele estava apenas sendo "monitorado"

    printarMENU(CONTROLE_DE_COR);
    return tecla_precionada;*/
}

// Controla a mudança da variavel logal, a mesma é usado para saber onde "pintar"
void alterar_variavel_posicao_matriz(int tecla_precionada, int *lugar) {
    // Os numeros de 48 a 57, são representaçoes respectivamente dos numeros de 0 a 9
    // O 48 fica em ultimo já que apenas um dos menus tem a opçao "0"
    if (tecla_precionada == 48){
        *lugar = 0;
    } else if(tecla_precionada == 49) {
        *lugar = 1;
    } else if(tecla_precionada == 50){
        *lugar = 2;
    } else if (tecla_precionada == 51){
        *lugar = 3;
    } else if (tecla_precionada == 52){
        *lugar = 4;
    } else if (tecla_precionada == 53){
        *lugar = 5;
    } else if (tecla_precionada == 54){
        *lugar = 6;
    } else if (tecla_precionada == 55){
        *lugar = 7;
    } else if (tecla_precionada == 56){
        *lugar = 8;
    } else if (tecla_precionada == 57){
        *lugar = 9;
    }
}
//-------------------------------------------------------------------------------------------------

// Controle de menu foi uma função criada para para controlar todos os menus do codigo
// O ponteiro pra função aponta sempre pra um dos menus interativos a cima (printarMANUAL não se qualifica como um deles)
// A variavel limite é sempre: (a quantidade de opções do menu - 1)
int centraldeMENUS(void (*printarMENU) (char**), int limite){

    // Array de cores, COM_COR vai pintar o texto de uma certa cor, já a SEM_COR vai deixar o texto com a cor padrão
    char *CONTROLE_DE_COR[] = {COM_COR, SEM_COR, SEM_COR, SEM_COR, SEM_COR, SEM_COR, SEM_COR, SEM_COR, SEM_COR, SEM_COR, SEM_COR, SEM_COR};

    // A variavel lugar é usada para saber onde se encontra o numero "COM_COR"
    // Ela é alterada baseado na escolha do usuario
    int lugar = 0;

    // Printa o menu que esta sendo utilizado no momento
    printarMENU(CONTROLE_DE_COR);
    while(1) {
        int tecla_precionada = controleTECLA(&lugar, limite, printarMENU, CONTROLE_DE_COR);


        if(tecla_precionada == 13 && lugar == 11) {
            CENTROSemEspaco; printf("\t    %s Programa finalizado!! %s\n", VERMELHO ,SEM_COR);
            exit(0);
        }

        // Se foi precionado ENTER finaliza a função, ENTER = 13
        if(tecla_precionada == 13){
            APAGAR_TELA;
            // A variavel lugar começa a ser contado do 0, enquanto todos os switch-case começam no 1 então para se adequar soma 1 a ele
            return lugar;
        }
    } // Fim do while

} //Fim da função menu
//-------------------------------------------------------------------------------------------------

// Controla qual tecla foi precionada, função generica para funcionar nos outros menus
// Geral:
// Letra A = 97 || Letra S = 115 || Letra D  = 100 || Letra W = 119
// ESC = 27

// No windows:
// Seta para cima =  72 || Seta para direita = 77 || Seta para baixo = 80 || Seta para esquerda = 75  || ENTER = 13

// No linux:
// Seta para cima =  65 || Seta para direita = 67 || Seta para baixo = 66 || Seta para esquerda = 68  || ENTER = 10

int controleTECLA(int *lugar, int limite, void *(printarMENU) (char**), char *CONTROLE_DE_COR[]) {

        int tecla_precionada = 0;

        // Enquanto nenhuma tecla é precionada o tecla_precionada ficara 0,
        // Quando alguma seta é usada ela pode retornar 224 além do seu número de identificação da tabela ASCII

        // Por ambos os motivos usei o DO-WHILE
        do {
            if(kbhit()) {
                tecla_precionada = tecla();
            }
        } while(tecla_precionada == 0 || tecla_precionada == 224);


        //printf("TECLA: %i", tecla_precionada);

        // ENTER é representado por 13 na tabela ASCII
        if(tecla_precionada == 13){
            return tecla_precionada;
        }

        if(tecla_precionada == LETRA_T || tecla_precionada == LETRA_t) {
            if(limite == 11) {
                *lugar = 10;
                return 13;
            } else {
                *lugar = 7;
                return 13;
            }
        }

        if((tecla_precionada == LETRA_E || tecla_precionada == LETRA_e) && limite == 11) {
            *lugar = 11;
            return 13;
        }

        if(tecla_precionada == BAIXO || tecla_precionada == DIREITA || tecla_precionada == 100 || tecla_precionada == 115) {
            CONTROLE_DE_COR[*lugar] = SEM_COR;

            // Faz o numero com cor descer uma casa
            (*lugar)++;

            // Faz o numero com cor voltar pro inicio
            if(*lugar > limite){
                *lugar = 0;
            }

        } else if (tecla_precionada == ESQUERDA || tecla_precionada == CIMA || tecla_precionada == 97 || tecla_precionada == 119) {
            CONTROLE_DE_COR[*lugar] = SEM_COR;

            // Faz o numero com cor subir uma casa
           (*lugar)--;

            // Faz o numero com cor voltar pro final
            if(*lugar < 0){
                *lugar = limite;
            }

        // Verifica se foi apertado um numero(0 a 9)
        } else if (tecla_precionada >= 48 && tecla_precionada <= 57) {
            CONTROLE_DE_COR[*lugar] = SEM_COR;
            alterar_variavel_lugar(tecla_precionada, lugar);

            if((*lugar) > limite) {
                *lugar = 0;
                CONTROLE_DE_COR[*lugar] = COM_COR;
                tecla_invalida(CONTROLE_DE_COR, printarMENU);
                return tecla_precionada;
            }
            // Simula um ENTER precionado, para quando o usuario apertar um numero ir direto
            tecla_precionada = 13;
            APAGAR_TELA;
            return tecla_precionada;
        } else if(tecla_precionada == 27) {
            APAGAR_TELA;
            printarMANUAL();
            printarMENU(CONTROLE_DE_COR);
            return tecla_precionada;
        } else {
                tecla_invalida(CONTROLE_DE_COR, printarMENU);
                return tecla_precionada;
        }
    APAGAR_TELA;
    CONTROLE_DE_COR[*lugar] = COM_COR;  // Pinta o nome com cor, antes ele estava apenas sendo "monitorado"

    printarMENU(CONTROLE_DE_COR);
    return tecla_precionada;
}

// Controla a mudança da variavel logal, a mesma é usado para saber onde "pintar"
void alterar_variavel_lugar(int tecla_precionada, int *lugar) {
    // Os numeros de 48 a 57, são representaçoes respectivamente dos numeros de 0 a 9
    // O 48 fica em ultimo já que apenas um dos menus tem a opçao "0"
    if (tecla_precionada == 48){
        *lugar = 0;
    } else if(tecla_precionada == 49) {
        *lugar = 1;
    } else if(tecla_precionada == 50){
        *lugar = 2;
    } else if (tecla_precionada == 51){
        *lugar = 3;
    } else if (tecla_precionada == 52){
        *lugar = 4;
    } else if (tecla_precionada == 53){
        *lugar = 5;
    } else if (tecla_precionada == 54){
        *lugar = 6;
    } else if (tecla_precionada == 55){
        *lugar = 7;
    } else if (tecla_precionada == 56){
        *lugar = 8;
    } else if (tecla_precionada == 57){
        *lugar = 9;
    }
}
//-------------------------------------------------------------------------------------------------
