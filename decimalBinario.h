typedef struct celula Cell;

Cell* criar_nova_celula(int num);
int acessar_valor(Cell *a);
void liberar_cell(Cell *a);

typedef struct pilha PilhaEncadeada;

PilhaEncadeada* criar_nova_pilha_encadeada();
int verifica_se_pilha_vazia(PilhaEncadeada *a);
int empilhar_item(PilhaEncadeada *a, int num);
int desenpilhar_item(PilhaEncadeada *a);
Cell* teste_desenpilhar_cell_pilha(PilhaEncadeada *a);
void imprimir_conteudo_pilha(PilhaEncadeada *a);
void teste_imprimir_conteudo_pilha(PilhaEncadeada *a);
int liberar_pilha(PilhaEncadeada *a);
int cont_elementos_pilha(PilhaEncadeada *a);
int teste_empilhar_cell(PilhaEncadeada *a, Cell *b);
char* converter_int_para_binario(int inteiro);
