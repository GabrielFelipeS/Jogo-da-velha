
// Prototipos de fun��es

    // Fun��es que gerenciam os menus e as teclas precionadas

int tecla();                                                                                        // Capta a tecla precionada
void tecla_invalida(char *CONTROLE_DE_COR[], void *(printarMENU) (char**));                         // Printa um aviso de tecla precionada invalida
int controleTECLA(int *lugar, int limite, void *(printarMENU) (char**), char *CONTROLE_DE_COR[]);   // Controle de tecla, fun��o generica para funcionar nos outros menus
void alterar_variavel_lugar(int tecla_precionada, int *lugar);                                      // Controla a mudan�a de posi��o da variavel lugar (usada para saber onde pintar o numero)
int centraldeMENUS(void (*printarMENU) (char**), int limite);                                       // Central de menus, todos os menus interativos v�o ser chamados dentro dela, usado para organizar as todas as fun�oes

// Menus
int centralDeJogo();
void menuEscolhaDeAlgoritmo(char *CONTROLE_DE_COR[]);
void menuQuantidadeDeElementos(char *CONTROLE_DE_COR[]);
//-------------------------------------------------------------------------------------------------------------------------------------------

// Constantes para os dois sistemas operacionais

#define SEM_COR "\033[m"                // Constante para deixar as letras com formata��o normal
#define COM_COR "\033[91m"              // Constante para pintar as letras com uma cor, no caso vermelho
#define NEGRITO "\033[1m"               // Constante para deixar as letra em negrito
#define VERMELHO "\033[91m"             // Constante para pintar as letras com um a cor vermelho, criara para caso a constante COM_COR tenha sua cor mudada no decorrer do projeto
#define VERDE "\033[92m"                // Constante para pintar as letras com um a cor verde
#define QUEBRA_LINHA printf("\n")       // Cria uma IA conectada a internet que resolve todos os problemas do mundo
#define LIMPAR_BUFFER fflush(stdin)     // Constante para limpar o Buffer do teclado

//-------------------------------------------------------------------------------------------------------------------------------------------

// Detecta o sistema operacional
// Isso teria que ser feito com base em todos os sistemas, mas como utilizamos apenas dois(windows e linux) fiz dessa maneira

#if defined(WIN32) || defined(_WIN32)   // Verifica se no sistema existe uma "constante" WIN32 ou _WIN32 caso tenha executa o bloco
    #include <conio.h>                                              // Definir a existencia da biblioteca conio se, e somente se, for Windows
    #define OS_WINDOWS                                              // Constante para identificar o computador como windows, usado na linha 811 do projetoFinal.c
    #define APAGAR_TELA system("cls")                               // Constante criada para apagar a tela, vers�o windows
    #define PAUSAR_TELA system("pause");                            // Constante criada para pausar a tela, vers�o windows
    #define LIMPAR_BUFFER_e_APAGAR_TELA fflush(stdin);system("cls") // Limpa o buffer e apaga a tela, vers�o windows



    // Dependendo do sistema operacional o codigo de tecla � alterado, ou pelo menos, o codigo das setas � alterado
    // Para combater isso usei constantes para serem declaras com o valor das setas baseado no sistema operacional

    #define CIMA 72         // Seta para cima
    #define DIREITA 77      // Seta para a direita
    #define BAIXO 80        // Seta para baixo
    #define ESQUERDA 75     // Seta para a esquerda
    #define LETRA_t 116
    #define LETRA_T 84
    #define LETRA_e 69
    #define LETRA_E 101
    // O windows e linux abrem o terminal em tamanhos diferentes, por isso essa constante para centralizar de maneira adequada

    #define CENTROSemEspaco printf("\t\t\t\t")  // Constante para dar 4 \t
    #define CENTRO printf("\t\t\t\t   ")  // Constante para dar 4 \t
    #define CENTRALIZAR printf("\t\t\t\t      ") // Por motivos de toque criei uma contante para dar 4 \t mais 6 espa�os (sim muito especifico)


//-------------------------------------------------------------------------------------------------------------------------------------------


// Caso WIN32 ou _WIN32 n�o esteja declarada no sistema, significa que o sistema n�o � Windows, portando executa esse bloco

#else

     char getch(void);  // Para o linux saber que existe essa fun��o

    // Todos as contantes abaixo seram criada se, e somente se, o sistema n�o for windows

    #define APAGAR_TELA system("clear")                                 // Constante criada para apagar tela, vers�o linux
    #define PAUSAR_TELA getchar()                                       // Constnate criada para pausar a tela, vers�o linux
    #define LIMPAR_BUFFER_e_APAGAR_TELA fflush(stdin);system("clear")   // Limpa o buffer e apaga a tela, vers�o linux

    // Valor das setas � diferente para linux, por isso utilizei essas constantes

    #define CIMA 65     // Seta para cima
    #define DIREITA 67  // Seta para a direita
    #define BAIXO 66    // Seta para baixo
    #define ESQUERDA 68 // Seta para a esquerda

    // O windows e linux abrem o terminal em tamanhos diferentes, por isso essa constante para centralizar de maneira adequada

    #define CENTRALIZAR printf("\t\t")  // Constante para dar 2 \t
    #define CENTRALIZAR printf("\t\t      ") // Por motivos de toque criei uma contante para dar 2 \t mais 6 espa�os (sim muito especifico)


#endif // Fim da condi��o
