// Fun��o para limpar a tela do console
void limparTela()
{
    system("cls");
}

// Fun��o para estilizar a tela do console
void estilizarTela()
{
    // Define o t�tulo da janela do console como "Matrix 4"
    SetConsoleTitle("Matrix 4");
    // Define as cores de fundo e texto como preto e verde claro (0A)
    system("color 0A");
}

// Fun��o para animar a mensagem "Salvando..."
void animacaoSalvar()
{
    limparTela();
    printf("\t\t\t\t\t\tS");
    Sleep(200);
    limparTela();
    printf("\t\t\t\t\t\tSa");
    Sleep(200);
    limparTela();
    printf("\t\t\t\t\t\tSal");
    Sleep(200);
    limparTela();
    printf("\t\t\t\t\t\tSalv");
    Sleep(200);
    limparTela();
    printf("\t\t\t\t\t\tSalva");
    Sleep(200);
    limparTela();
    printf("\t\t\t\t\t\tSalvan");
    Sleep(200);
    limparTela();
    printf("\t\t\t\t\t\tSalvand");
    Sleep(200);
    limparTela();
    printf("\t\t\t\t\t\tSalvando .");
    Sleep(200);
    limparTela();
    printf("\t\t\t\t\t\tSalvando . .");
    Sleep(200);
    limparTela();
    printf("\t\t\t\t\t\tSalvando . . .");
    Sleep(200);
}

// Fun��o para animar a mensagem "Carregando..."
void animacaoCarregar()
{
    limparTela();
    printf("\t\t\t\t\t\tC");
    Sleep(150);
    limparTela();
    printf("\t\t\t\t\t\tCa");
    Sleep(150);
    limparTela();
    printf("\t\t\t\t\t\tCar");
    Sleep(150);
    limparTela();
    printf("\t\t\t\t\t\tCarr");
    Sleep(150);
    limparTela();
    printf("\t\t\t\t\t\tCarre");
    Sleep(150);
    limparTela();
    printf("\t\t\t\t\t\tCarreg");
    Sleep(150);
    limparTela();
    printf("\t\t\t\t\t\tCarrega");
    Sleep(150);
    limparTela();
    printf("\t\t\t\t\t\tCarregan");
    Sleep(150);
    limparTela();
    printf("\t\t\t\t\t\tCarregand");
    Sleep(150);
    limparTela();
    printf("\t\t\t\t\t\tCarregando");
    Sleep(150);
    limparTela();
    printf("\t\t\t\t\t\tCarregando .");
    Sleep(150);
    limparTela();
    printf("\t\t\t\t\t\tCarregando . .");
    Sleep(150);
    limparTela();
    printf("\t\t\t\t\t\tCarregando . . .");
    Sleep(150);
}

// Fun��o para uma anima��o inicial com texto estilizado
void animacaoInicio()
{
    printf("\n\t\t\t\t#     #    #    ####### ######  ### #     #    #       ");
    Sleep(200);
    printf("\n\t\t\t\t##   ##   # #      #    #     #  #   #   #     #    #  ");
    Sleep(200);
    printf("\n\t\t\t\t# # # #  #   #     #    #     #  #    # #      #    #  ");
    Sleep(200);
    printf("\n\t\t\t\t#  #  # #     #    #    ######   #     #       #    #  ");
    Sleep(200);
    printf("\n\t\t\t\t#     # #######    #    #   #    #    # #      ####### ");
    Sleep(200);
    printf("\n\t\t\t\t#     # #     #    #    #    #   #   #   #          #  ");
    Sleep(200);
    printf("\n\t\t\t\t#     # #     #    #    #     # ### #     #         #  ");
    Sleep(2000);
}
