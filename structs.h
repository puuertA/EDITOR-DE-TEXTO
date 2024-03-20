// Estrutura para um n� de lista encadeada de colunas
// Defini��o da estrutura do n� de caractere
typedef struct No
{
    char dado;
    struct No* prox;
} No;

// Defini��o da estrutura da linha
typedef struct NoLinha
{
    No* cabecaColuna;
    struct NoLinha* proxLinha;
} NoLinha;

// Fun��o para criar um novo n� de coluna
No* criarNo(char dado)
{
    // Aloca mem�ria para um novo n� de coluna e inicializa seus valores
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->dado = dado;
    novoNo->prox = NULL;
    return novoNo;
}

// Fun��o para criar uma nova linha vazia
NoLinha* criarNovaLinha()
{
    // Aloca mem�ria para uma nova linha e inicializa seus valores
    NoLinha* novaLinha = (NoLinha*)malloc(sizeof(NoLinha));
    novaLinha->cabecaColuna = NULL;
    novaLinha->proxLinha = NULL;
    return novaLinha;
}

// Fun��o para obter uma linha espec�fica dado o n�mero da linha
NoLinha* obterLinha(NoLinha* cabecaTexto, int numeroLinha)
{
    // Percorre as linhas at� encontrar a linha desejada pelo n�mero
    NoLinha* atual = cabecaTexto;
    int contador = 0;

    while (atual != NULL)
    {
        if (contador == numeroLinha)
        {
            return atual;
        }
        contador++;
        atual = atual->proxLinha;
    }

    return NULL;
}

// Fun��o para contar o n�mero de colunas em uma linha
int contarColunas(NoLinha* linha)
{
    // Conta o n�mero de n�s (caracteres) em uma linha
    int contador = 0;
    No* atual = linha->cabecaColuna;

    while (atual != NULL)
    {
        contador++;
        atual = atual->prox;
    }

    return contador;
}

// Fun��o para salvar o texto armazenado na estrutura de dados em um arquivo
void salvarTextoEmArquivo(NoLinha* cabecaTexto, const char* nomeArquivo)
{
    // Percorre as linhas e os caracteres e os escreve em um arquivo
    FILE* arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita.");
        return;
    }

    NoLinha* linhaTemp = cabecaTexto;
    while (linhaTemp != NULL)
    {
        No* colunaTemp = linhaTemp->cabecaColuna;
        while (colunaTemp != NULL)
        {
            fputc(colunaTemp->dado, arquivo);
            colunaTemp = colunaTemp->prox;
        }
        fputc('\n', arquivo); // Insere uma quebra de linha ao final de cada linha
        linhaTemp = linhaTemp->proxLinha;
    }

    fclose(arquivo);
}

// Fun��o para inserir um caractere em uma posi��o espec�fica na linha
void inserirCaractere(NoLinha* linha, int pos, char dado)
{
    // Insere um caractere em uma posi��o espec�fica na linha
    No* novoNo = criarNo(dado);

    if (linha->cabecaColuna == NULL || pos == 0)
    {
        novoNo->prox = linha->cabecaColuna;
        linha->cabecaColuna = novoNo;
    }
    else
    {
        No* atual = linha->cabecaColuna;
        int contador = 0;
        while (atual->prox != NULL && contador < pos - 1)
        {
            atual = atual->prox;
            contador++;
        }
        novoNo->prox = atual->prox;
        atual->prox = novoNo;
    }
}

// Fun��o para remover um caractere de uma posi��o espec�fica na linha
void removerCaractere(NoLinha* linha, int pos)
{
    // Remove um caractere de uma posi��o espec�fica na linha
    if (linha->cabecaColuna == NULL)
    {
        return;
    }

    No* temp = linha->cabecaColuna;
    if (pos == 0)
    {
        linha->cabecaColuna = temp->prox;
        free(temp);
    }
    else
    {
        No* anterior = NULL;
        int contador = 0;
        while (temp != NULL && contador < pos)
        {
            anterior = temp;
            temp = temp->prox;
            contador++;
        }
        if (temp == NULL)
        {
            return;
        }
        anterior->prox = temp->prox;
        free(temp);
    }
}

// Fun��o para carregar um texto de um arquivo para a estrutura de dados
NoLinha* carregarTextoDoArquivo(const char* nomeArquivo)
{
    // Carrega o texto de um arquivo para a estrutura de dados
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo para leitura.");
        return NULL;
    }

    NoLinha* cabecaTexto = criarNovaLinha();
    NoLinha* linhaAtual = cabecaTexto;
    int contLinhas = 0;

    char ch = fgetc(arquivo);
    while (ch != EOF && contLinhas < MAX_LINHAS)
    {
        if (ch == '\n')
        {
            linhaAtual = linhaAtual->proxLinha = criarNovaLinha();
            contLinhas++;
        }
        else
        {
            inserirCaractere(linhaAtual, contarColunas(linhaAtual), ch);
        }
        ch = fgetc(arquivo);
    }

    fclose(arquivo);
    return cabecaTexto;
}
