// Fun��o para exibir o texto armazenado na estrutura de dados
void exibirTexto(NoLinha* cabecaTexto)
{
    // Percorre as linhas do texto
    NoLinha* linhaTemp = cabecaTexto;
    while (linhaTemp != NULL)
    {
        // Percorre as colunas de cada linha e imprime os caracteres
        No* colunaTemp = linhaTemp->cabecaColuna;
        while (colunaTemp != NULL)
        {
            putchar(colunaTemp->dado);
            colunaTemp = colunaTemp->prox;
        }
        putchar('\n'); // Ao final de cada linha, imprime uma quebra de linha
        linhaTemp = linhaTemp->proxLinha;
    }
}

// Fun��o para tratar a tecla "Enter"
void teclaEnter(NoLinha** cabecaTexto, int* linha_cursor, int* coluna_cursor)
{
    // L�gica para criar uma nova linha e mover o texto ap�s o cursor para ela
    if (*linha_cursor < MAX_LINHAS - 1)
    {
        NoLinha* linhaAtual = obterLinha(*cabecaTexto, *linha_cursor);
        NoLinha* novaLinha = criarNovaLinha();

        if (linhaAtual->cabecaColuna != NULL)
        {
            No* atual = linhaAtual->cabecaColuna;
            int contador = 0;
            while (atual != NULL && contador < *coluna_cursor)
            {
                atual = atual->prox;
                contador++;
            }

            if (atual != NULL)
            {
                // Criar uma nova lista para a nova linha e mover o texto ap�s o cursor para ela
                novaLinha->cabecaColuna = atual->prox;
                atual->prox = NULL;
            }
        }

        novaLinha->proxLinha = linhaAtual->proxLinha;
        linhaAtual->proxLinha = novaLinha;

        (*linha_cursor)++;
        *coluna_cursor = 0;
    }
}

// Fun��o para tratar a tecla "Backspace"
void teclaBackspace(NoLinha **cabecaTexto, int *linha_cursor, int *coluna_cursor)
{
    // L�gica para apagar caracteres ou mover texto para a linha acima
    NoLinha* linhaAtual = obterLinha(*cabecaTexto, *linha_cursor);
    NoLinha* linhaAnterior = obterLinha(*cabecaTexto, *linha_cursor - 1);

    if (*coluna_cursor > 0 && linhaAtual->cabecaColuna != NULL)
    {
        // Se a coluna do cursor n�o estiver no in�cio e a linha n�o estiver vazia
        removerCaractere(linhaAtual, *coluna_cursor - 1);
        (*coluna_cursor)--;
    }
    else if (*linha_cursor > 0 && linhaAnterior != NULL && linhaAnterior->cabecaColuna == NULL && linhaAtual->cabecaColuna != NULL)
    {
        // Se a linha acima estiver vazia e a linha atual n�o estiver vazia
        No* ultimoCaractere = linhaAtual->cabecaColuna;
        while (ultimoCaractere->prox != NULL)
        {
            ultimoCaractere = ultimoCaractere->prox;
        }

        ultimoCaractere->prox = linhaAnterior->cabecaColuna;
        linhaAnterior->cabecaColuna = linhaAtual->cabecaColuna; // Move o conte�do para a linha acima
        linhaAnterior->proxLinha = linhaAtual->proxLinha;
        free(linhaAtual);

        (*linha_cursor)--;
        *coluna_cursor = contarColunas(linhaAnterior);
    }
    else if (*linha_cursor > 0)
    {
        NoLinha* linhaAnterior = obterLinha(*cabecaTexto, *linha_cursor - 1);

        if (linhaAnterior->cabecaColuna != NULL)
        {
            // Se a linha anterior n�o estiver vazia, mova os caracteres para ela
            No* ultimoCaractere = linhaAnterior->cabecaColuna;
            while (ultimoCaractere->prox != NULL)
            {
                ultimoCaractere = ultimoCaractere->prox;
            }

            ultimoCaractere->prox = linhaAtual->cabecaColuna;
            linhaAnterior->proxLinha = linhaAtual->proxLinha;
            free(linhaAtual);

            (*linha_cursor)--;
            *coluna_cursor = contarColunas(linhaAnterior);
        }
        else
        {
            // Se a linha anterior estiver vazia, insira um caractere para reativ�-la
            inserirCaractere(linhaAnterior, 0, ' ');
            (*linha_cursor)--;
            *coluna_cursor = 1;
        }
    }
}

// Fun��o para tratar a tecla "Delete"
void teclaDelete(NoLinha **cabecaTexto, int *linha_cursor, int *coluna_cursor)
{
    // L�gica para apagar caracteres ou mover texto para a linha abaixo
    NoLinha* linhaAtual = obterLinha(*cabecaTexto, *linha_cursor);

    if (*coluna_cursor > 0)
    {
        removerCaractere(linhaAtual, *coluna_cursor);
        (*coluna_cursor)--;
    }
    else if (*linha_cursor < MAX_LINHAS - 1 && linhaAtual->cabecaColuna == NULL)
    {
        NoLinha* proximaLinha = obterLinha(*cabecaTexto, *linha_cursor + 1);

        if (proximaLinha != NULL && proximaLinha->cabecaColuna != NULL)
        {
            No* atual = proximaLinha->cabecaColuna;

            while (atual->prox != NULL)
            {
                atual = atual->prox;
            }

            atual->prox = linhaAtual->cabecaColuna;
            proximaLinha->proxLinha = linhaAtual->proxLinha;
            free(linhaAtual);

            *coluna_cursor = 0;
        }
        else
        {
            NoLinha* temp = obterLinha(*cabecaTexto, *linha_cursor);
            NoLinha* proxima = obterLinha(*cabecaTexto, *linha_cursor + 1);

            if (temp != NULL && proxima != NULL)
            {
                temp->proxLinha = proxima->proxLinha;
                free(proxima);

                *coluna_cursor = contarColunas(temp);
            }
        }
    }
}

// Fun��o para alternar o modo de escrita entre inser��o e sobreescrita
void alternarModoInsercao(int *modoEscrita)
{
    *modoEscrita = !(*modoEscrita); // Alterna o estado atual do modo de escrita
}

// Fun��o para exibir o texto se houver modifica��es
void exibirTextoSeModificado(NoLinha* cabecaTexto, int *texto_mudado, int *cursor_atualizado)
{
    // Se o texto foi modificado, exibe o texto na tela e reseta as variaveis
    if (*texto_mudado)
    {
        limparTela();
        exibirTexto(cabecaTexto);
        *texto_mudado = 0; // Reseta a varivel ap�s a exibi��o
        *cursor_atualizado = 0;
    }
}

// Fun��o para inserir caracteres no modo de inser��o
void modoInsercao(NoLinha** cabecaTexto, int* linha_cursor, int* coluna_cursor, char ch)
{
    // L�gica para inserir caracteres na posi��o atual do cursor
    NoLinha* linhaAtual = obterLinha(*cabecaTexto, *linha_cursor);

    if (linhaAtual != NULL)
    {
        if (*coluna_cursor < MAX_COLUNAS)
        {
            if (linhaAtual->cabecaColuna == NULL)
            {
                inserirCaractere(linhaAtual, 0, ch);
                (*coluna_cursor)++;
            }
            else if (contarColunas(linhaAtual) < MAX_COLUNAS - 1)
            {
                inserirCaractere(linhaAtual, *coluna_cursor, ch);
                (*coluna_cursor)++;
            }
            else     // Caso ultrapasse o limite de 80 caracteres
            {
                teclaEnter(cabecaTexto, linha_cursor, coluna_cursor); // Move para a pr�xima linha
                modoInsercao(cabecaTexto, linha_cursor, coluna_cursor, ch); // Insere o caractere na pr�xima linha
            }
        }
    }
}

// Fun��o para sobre-escrever caracteres no modo de sobreescrita
void modoSobreescrita(NoLinha* linhaAtual, int coluna_cursor, char ch)
{
    // L�gica para sobre-escrever caracteres na posi��o atual do cursor
    No* colunaAtual = linhaAtual->cabecaColuna;
    int contador = 0;

    while (colunaAtual != NULL && contador < coluna_cursor)
    {
        colunaAtual = colunaAtual->prox;
        contador++;
    }

    if (colunaAtual != NULL && contador == coluna_cursor)
    {
        colunaAtual->dado = ch;
    }
    else if (contador == coluna_cursor - 1)
    {
        inserirCaractere(linhaAtual, coluna_cursor, ch);
    }
}

void liberarMemoria(NoLinha** cabecaTexto) {
    NoLinha* temp;
    while (*cabecaTexto != NULL) {
        temp = *cabecaTexto;
        *cabecaTexto = (*cabecaTexto)->proxLinha;
        while (temp->cabecaColuna != NULL) {
            No* tempColuna = temp->cabecaColuna;
            temp->cabecaColuna = temp->cabecaColuna->prox;
            free(tempColuna);
        }
        free(temp);
    }
}

// Fun��o para tratar a tecla "Esc"
int teclaEsc(NoLinha* cabecaTexto, int *continuar_execucao)
{
    // L�gica para lidar com a tecla "Esc" e poss�veis a��es de sa�da do programa
    char desejaSair;
    char desejaSalvar;

    printf("\nDeseja realmente sair? (s/n) \n\n>>> ");
    fflush(stdin);
    scanf("%c", &desejaSair);
    if(desejaSair == 's')
    {
        do
        {
            printf("\nDeseja salvar o texto digitado em um arquivo antes de sair? (s/n) \n\n>>> ");
            fflush(stdin);
            scanf("%c", &desejaSalvar);
            if(desejaSalvar == 's')
            {
                salvarTextoEmArquivo(cabecaTexto, "LucasPuerta_texto.txt");
                animacaoSalvar();
                liberarMemoria(&cabecaTexto);
                *continuar_execucao = 0;
                liberarMemoria(&cabecaTexto);
                break;
            }
            else if(desejaSalvar == 'n')
            {
                liberarMemoria(&cabecaTexto);
                *continuar_execucao = 0;
                liberarMemoria(&cabecaTexto);
                break;
            }
            else
            {
                printf("\nEscolha uma op��o v�lida! (s/n)");
            }
        }
        while(desejaSalvar != 's' || desejaSalvar != 'n');
    }
    else if(desejaSair == 'n')
    {
        *continuar_execucao = 1;
        return 0;
    }
    else
    {
        printf("\nEscolha uma op��o v�lida! (s/n)");
    }
}
