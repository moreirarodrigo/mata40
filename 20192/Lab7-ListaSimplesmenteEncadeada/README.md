**Universidade Federal da Bahia - UFBA**<br>
**Instituto de Matemática - IM**<br>
**Departamento de Ciência da Computação - DCC**<br>
**Curso de Bacharelado em Ciência da Computação**<br>
**MATA40 - Estrutura de Dados | Período: 2019.2 | Data: 08/10/2019**<br>
**Prof. Antonio L. Apolinário Junior**

<h1 align="center">Laboratório 7 - Listas Encadeadas com Apontadores</h1>

**Objetivos:**

-   Reforçar os conceitos de alocação dinâmica de memória;
-   Compreender de forma prática o conceito de encadeamento em listas baseadas em Apontadores;
-   Implementar, em linguagem C, um TAD Lista Encadeada, baseada em apontadores.

**Conceitos básicos:**

-   **Lista Encadeada baseada em Apontadores:**
    O uso de alocação dinâmica de memória (ver Lab. 5) pode ser extendido para que os nós da lista sejam alocados sob demanda, e não de forma arbitrária e em bloco como nas soluções baseadas em Arranjos (ver Lab. 6 e 7). Dessa forma a estrutura de dados nó passa a apontar não para elemento do vetor (índice inteiro) mas para um endereço de memória que contem um outro nó. Ou seja:

    ```c
    typedef struct No {
    	float dado; // informação armazenada no nó da lista
    	struct No* prox; // encadeamento - endereço do nó sucessor
    } tNo;
    ```

    Dessa forma a lista não necessita mais de um vetor/arranjo para suporte, mas apenas de um ponteiro para o primeiro nó da lista. Portanto, a <u>**lista encadeada baseada em apontadores**</u> é definida por:

    ```c
    typedef struct {
    	tNo *inicio;        // armazena o endereço do 1º. nó da lista
    	int numElems;       // numero atual de nós na lista
    } tListaEncadeada;
    ```

**Roteiro:**

1. Baixe do Moodle os códigos fonte base para esse Laboratório.

2. Analise os códigos fonte fornecidos e sua organização em módulos.

3. Compile os programas utilizando o utilitário **make**.

4. Não havendo erros, execute o programa **main**. Verifique que, tal como no Laboratório anterior,nem todas as funções relativas ao TAD **tListaEncadeada** estão implementadas.

5. Abra o arquivo **listaSimplesmenteEncadeada.c** e analise as funções já implementadas: **initLista(), alocaNo(), insereFinalLista()** e **imprimeLista()**. Analise as estratégias utilizadas na implementação de cada função.

6. Codifique a função **insereInicioLista()**, que promove a inserção dos novos elementos no início da lista simplesmente encadeada, e é utilizada na função **main()** para montar uma lista invertida.

7. Compile e teste sua função usando o programa **main**;

8. Implemente agora a função **insereOrdenadoLista()**, que insere um novo elemento na lista mantendo-a ordenada. Considere sempre a ordenação crescente. Analise cuidadosamente os casos que podem acontecer nesse tipo de inserção, já que para manter a ordenação o novo elemento poderá ser inserido em qualquer ponto da lista. Lembrando que essa função só gera resultados coerentes se TODAS as inserções nesse tipo de lista usarem essa função.

9. Compile e teste sua rotina usando o programa **main.**

10. Agora só falta implementar a função **limpaLista()**, que remove todos os elementos da lista. Cuidado pois os elementos agora devem ser removidos individualmente física e logicamente!

11. Compile e teste sua rotina usando o programa **main**;

12. Agora que voce já tem todas as funções básicas de uma lista encadeada baseada em apontadores finalizada, podemos pensar em alternativas para a estrutura da lista. Considere uma mudança que inclua um novo campo na estrutura **tListaEncadeada**: um ponteiro **fim**, que armazena o endereço do último nó da lista. Crie esse novo TAD e analise quais modificações devem ser feitas nas funções já codificadas de forma a manter essa nova informação na lista. As funções ficarão mais simples ou mais complexas com esse novo ponteiro? Implemente as mudanças que você analisou e teste sua nova versão de lista.

13. Seguindo a mesma lógica, modifique a estrutura **tListaEncadeada** para que seus nós armazenem não só a referência para o próximo elemento mas também uma referência para o elemento anterior. Crie um novo módulo para esse TAD chamado **tListaDuplamenteEncadeada** e adapte as funções considerando essa nova estrutura de dados. Analise a complexidade das operações comparando-as com as suas equivalentes na **tListaEncadeada**.

**Para avançar nas listas...**
É possível conceber muitas outras operações que manipulam listas encadeadas, sejam elas simplesmente ou duplamente encadeadas. Operações como, por exemplo:

1. **<u>Concatenação de listas</u>**: dadas 2 listas, concatenar a primeira na segunda, tal que os elementos da segunda sejam incorporados no final da primeira. A segunda lista termina vazia.

2. **<u>Mistura de listas</u>**: dadas 2 listas, misturar os elementos da segunda na primeira, presumindo que ambas as listas são ordenadas. A segunda lista termina vazia.

3. **<u>Intercalação de listas</u>**: dadas 2 listas, intercalar os elementos da segunda na primeira. A segunda lista termina vazia.
4. **<u>_Matching_ de listas</u>**: dadas 2 lista verificar se a segunda esta contida na primeira.

5. **<u>Inserir uma lista em outra</u>**: dadas 2 listas, inserir o conteúdo da segunda lista a partir de uma posição **k** da primeira. A segunda lista termina vazia.
