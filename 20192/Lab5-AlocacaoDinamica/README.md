**Universidade Federal da Bahia - UFBA**<br>
**Instituto de Matemática - IM**<br>
**Departamento de Ciência da Computação - DCC**<br>
**Curso de Bacharelado em Ciência da Computação**<br>
**MATA40 - Estrutura de Dados | Período: 2019.2 | Data: 24/09/2019**<br>
**Prof. Antonio L. Apolinário Junior**

<h1 align="center">Laboratório 5 - Alocação Dinâmica de Memória</h1>

**Objetivos:**

-   Compreender o conceito de **alocação dinâmica de memória**;
-   Apresentar os mecanismos de alocação dinâmica de memória em Linguagem C;
-   Apresentar um caso de uso: definição de vetores dinâmicos;
-   Reiterar o conceito de **Tipo Abstrato de Dados** (**TAD**);
-   Implementar funções que utilizam alocação dinâmica de memória em linguagem C.

**Conceitos básicos:**

-   **Alocação Dinâmica de Memória:**
    Mecanismo pelo qual uma linguagem de programação permite postergar a definição do endereço de memória de um dado para o tempo de execução da aplicação. Em linguagem C, esse tipo de alocação é gerenciada pelas funções (descritas no header **stdlib.h**):

    ```c
    void malloc (size_t size);
    void calloc (size_t num, size_t size);
    void realloc (void* ptr, size_t size);
    void free (void* ptr);
    ```

    As funções de 1 a 3 são responsáveis por, respectivamente, alocar, alocar com inicialização e redefinir a alocação de um bloco de memória de **size** bytes. Na segunda função a parâmetro **num** indica a quantidade de elemento e na terceira o ponteiro **ptr** indica o bloco de memória que será realocado. A função **free** libera o bloco de memória apontado por **ptr** para possível reuso. Importante notar que o tipo de retorno das funções de alocação (1-3) é sempre um ponteiro void, ou seja, sem tipo. O tipo do ponteiro deve ser definido a partir de uma conversão forçada de tipo (_type cast_) antes da atribuição do endereço retornado ao ponteiro que irá armazenar o endereço do bloco de memória alocado.

    Um exemplo do uso dessas funções:

    ```c
    #include <stdlib.h> // malloc, calloc, realloc, free
    int main () {
    	/* Três ponteiros que armazenarão os endereços dos blocs de memória alocados dinamicamente */
    	int *buffer1 = NULL;
    	int *buffer2 = NULL;
    	int *buffer3 = NULL;

    	/* aloca um bloco de memoria de 100 elementos do tipo int não há garantia de inicialização do bloco, ou seja, pode haver lixo nos elementos alocados. */
    	buffer1 = (int*) malloc (100*sizeof(int));

    	// verifica o sucesso da alocação
    	if (buffer1 == NULL) {
    		exit(-1); // endereço válido é não NULL.
    	}

    	/* aloca um bloco de memoria de 100 elementos do tipo int com a garantia de que estarão inicializados */
    	buffer2 = (int*) calloc (100,sizeof(int));

    	// verifica o sucesso da alocação
    	if (!buffer2) {
    		exit(-1);
    	}

    	/* realoca o bloco apontado por *buffer2 para conter 500 elementos do tipo int. Uma copia dos valores armazenados no bloco apontado por buffer2 é feita. o endereço de buffer */
    	buffer3 = (int*) realloc (buffer2,500*sizeof(int));

    	// verifica o sucesso da alocação
    	if (!buffer3) {
    		exit(-1);
    	}

    	// libera o bloco de memória apontado por *buffer1 para reuso
    	free (buffer1);

    	// libera o bloco de memória apontado por *buffer3 para reuso
    	free (buffer3);

    	return 0;
    }
    ```

**Roteiro:**

1. Baixe do _Moodle_ os códigos fontes desse Laboratório. Descompacte os arquivos.

2. Analise o código fonte do arquivo **exemplo.c**. É uma cópia do exemplo acima com alguns elementos adicionais. Entenda o que o programa faz e qual a saída esperada. Tire todas as suas dúvidas quanto ao seu funcionamento antes de prosseguir para o próximo item.

3. Compile o código fonte **exemplo.c**, execute o programa gerado e verifique se a saída corresponde ao que você esperava após a análise do código do item 2. Caso contrário peça explicações adicionais ao professor.

4. Uma vez entendido o conceito e uso de alocação dinâmica de memória, vamos a um exemplo concreto e direto: uso de alocação dinâmica para criação de vetores de tamanho definido em tempo de execução. Abra o código fonte **main.c** e analise o programa. Você pode perceber que o código é um programa de teste para o **TAD** **tVetorDinamico**. Apenas a função principal é definida neste código, porém várias chamadas a funções externas são feitas, todas relacionadas ao **TAD** tVetorDinamico. Para entender a estrutura de dados do tipo **tVetorDinamico**, abra o arquivo **vetorDinamico.h** e veja a definição do **TAD**. Abra também o arquivo **vetorDinamico.c** e analise a implementação das funções. Compile o programa **main** e execute-o. Analise a sua saída.

5. Como já era de se esperar o programa **main** não executa muita coisa pois as funções do **TAD** **tvetorDinamico** não estão preenchidas. Sua tarefa agora é analisar a descrição de cada função em **vetorDinamico.c**, codificar e testar cada uma delas.

6. Após implementar as operações definidas no TAD **tvetorDinamico**, acrescente mais algumas operações:

    - **insereFinal()** - um novo elemento é acrescentado no vetor na sua última posição vaga.
    - **insereInicio()** - um novo elemento é acrescentado no vetor na sua primeira posição.
    - **buscaElemento()** - promove a busca por um valor dentro do vetor.
    - **removeElemento()** - retira do vetor a primeira ocorrência do elemento informado.

7. Analise a complexidade das operações que você acabou de codificar.

8. Considere agora que queremos manter nosso vetor sempre ordenado, sem no entanto implementar um algoritmo de ordenação. Para isso você deve criar uma função **insereOrdenado()**, que presume receber um vetor já ordenado e promove a inserção de um novo elemento, preservando a ordenação dos demais. Pense nesse algoritmo, codifique-o e teste-o. Para testa-lo crie uma variante da função de **preencheVetorAleatorio()**, onde os elementos aleatórios não são mais colocados de forma sequencial no vetor, mas inseridos a partir da sua nova função **insereOrdenado()**.
