#include <stdio.h>
#include <locale.h>
#ifndef INFOALUNO_H
#define INFOALUNO_H

void exibirInformacoes()
{
    setlocale(LC_ALL, "Portuguese");
    printf("\n\t\t\t***                             INFORMA��ES DO ALUNO                      ***");
    printf("\n\t\t\t+---------------------------------------------------------------------------+");
    printf("\n\t\t\t| Nome            - Lucas Cano Puerta                                       |");
    printf("\n\t\t\t| Prontu�rio      - PE3009777                                               |");
    printf("\n\t\t\t| Curso           - Bacharelado em Ci�ncias da Computa��o                   |");
    printf("\n\t\t\t| Ano de Ingresso - 2021                                                    |");
    printf("\n\t\t\t+---------------------------------------------------------------------------+");

    printf("\n\n\n\t\t\t Pressione ESC para voltar ao editor");

    int tecla;
    while (1)
    {
        tecla = getch();
        if (tecla == 27)   // Verifica se a tecla pressionada � o "Esc" (c�digo 27)
        {
            break; // Sai do loop quando o "Esc" � pressionado
        }
    }
}

#endif // INFOALUNO_H
