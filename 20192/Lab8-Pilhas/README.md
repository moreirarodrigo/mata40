**Universidade Federal da Bahia - UFBA**<br>
**Instituto de Matemática - IM**<br>
**Departamento de Ciência da Computação - DCC**<br>
**Curso de Bacharelado em Ciência da Computação**<br>
**MATA40 - Estrutura de Dados | Período: 2019.2 | Data: 15/10/2019**<br>
**Prof. Antonio L. Apolinário Junior**

<h1 align="center">Laboratório 8 - Pilhas</h1>

**Objetivos:**

-   Compreender de forma prática o conceito de pilha, suas operações e aplicação;
-   Implementar, em linguagem C, um TAD Pilha, baseado em arranjo dinâmico;
-   Aplicar o TAD Pilha em um exemplo prático.

**Conceitos básicos:**

-   **Pilha:**
    Como visto em sala de aula, pilhas são estruturas de dados lineares e sequências que possuem um política de acesso bem definida: **_LIFO - Last In, First Out_**. Portanto, sua implementação pode ser feita utilizando qualquer estrutura de dados linear e sequencial, como listas encadeadas ou arranjos. Nesse laboratório utilizaremos um arranjo dinâmico para definir o TAD Pilha, tal que:

    ```c
    typedef struct {
        char *pilha; // arranjo dinamico
        int maxElems; // numero maximo de elementos no arranjo
        int topo; // indice do topo da pilha
    } tPilha;
    ```

**Roteiro:**

1. Baixe do **_Moodle_** os códigos fonte base para esse Laboratório.

2. Analise a estrutura de arquivos que compõe esse Laboratório.

3. Compile os programas executando na linha do console o comando **make**.

4. Não havendo erros, execute o programa **testePilha**. Verifique que, tal como nos outros roteiros de laboratório, as funções relativas ao TAD **tPilha** não estão todas implementadas, mas garantem um valor de retorno que permite que o programa principal seja executado.

5. Abra o arquivo **pilha.c** e analise as funções a serem implementadas.

6. Codifique a função **initPilha()** para que ela, crie uma pilha com **n** posições.

7. Implemente na sequência as funções **pilhaEVazia()** e **PilhaECheia()**. Compile e teste suas rotinas usando o programa de **testePilha**.

8. Codifique as funções **empilha()** e **desempilha()**. Compile e teste suas rotinas usando o programa de **testePilha**;

9. A essa altura seu TAD Pilha já está funcional. Agora é a hora de testá-lo para resolver um problema prático. Construa um novo programa de teste, chamado **validaExpressao** que pede ao usuário que digite uma expressão matemática com parênteses, colchetes e chaves. A seguir seu programa deve ser capaz de validar a expressão, considerando que o número e a posição relativa dos parênteses, colchetes e chaves estão corretas.

10. Teste seu programa com vários tipos de expressões, com erros e corretas para verificar se seu funcionamento está ok.

Para ler a expressão você deve utilizar um vetor de caracteres para armazenar a sequência de elementos da expressão. Esse vetor é tratado pela linguagem C como uma string e possui uma biblioteca de funções, **string.h**, suportada pela linguagem C. Para mais detalhes consulte: [http://www.ime.usp.br/~pf/algoritmos/aulas/string.html](http://www.ime.usp.br/~pf/algoritmos/aulas/string.html) ou [http://www.cplusplus.com/reference/cstring/](http://www.cplusplus.com/reference/cstring/)
