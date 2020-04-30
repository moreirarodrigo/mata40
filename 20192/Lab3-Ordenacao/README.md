**Universidade Federal da Bahia - UFBA**<br>
**Instituto de Matemática - IM**<br>
**Departamento de Ciência da Computação - DCC**<br>
**Curso de Bacharelado em Ciência da Computação**<br>
**MATA40 - Estrutura de Dados | Período: 2019.2 | Data: 27/08/2019**<br>
**Prof. Antonio L. Apolinário Junior**

<h1 align="center">Roteiro do Laboratório 3 - Algoritmos de Ordenação</h1>

**Objetivos:**

-   Compreender o processo de **ordenação em arranjos homogêneos** (vetores);
-   Apresentar e implementar 3 algoritmos de ordenação básicos: **Seleção**, **Inserção** e **Bolha**;
-   Reiterar os conceitos de **Tipo Abstrado de Dados** (**TAD**) e **Modularização**.

**Conceitos básicos:**

-   **O problema de ordenação:**
    Dado um conjunto **<u>V</u>** composto de **<u>n</u>** chaves k<sub>0</sub>, k<sub>1</sub>, ... k<sub>n-1</sub>, um algoritmo de ordenação coloca essas chaves em uma certa ordem, em geral numérica ou lexicográfica.

-   **Algoritmos de ordenação básicos:**
    Os algoritmos de ordenação mais básicos se baseiam na comparação quase que exaustiva das chaves do conjunto entre si. Podemos destacar 3 algoritmos desse tipo<a href="#ftnt"><sup>1</sup></a>:

    1. **Seleção:** A cada passo deste algoritmo uma chave é posicionada. Procura-se pela posição da menor chave no conjunto. Encontrada a posição, a chave é trocada com a posição 0 do vetor. O processo é repetido a partir da posição 1, que será trocada pela menor chave do conjunto restante. O processo termina quando a última chave é alcançada.

    2. **Inserção:** A idéia é similar a um jogador de cartas que recebe uma carta por vez e tenta inseri-la em sua mão, que tem um conjunto já ordenado de cartas. Percorre-se o vetor, começando com o índice 1. Cada nova posição é comparada com as chaves a esquerda, que já estarão ordenadas. A nova chave troca de lugar com sua vizinha a esquerda enquanto esta for maior que a chave inserida.

    3. **Bolha:** Compara as chaves aos pares efetuando trocas toda a vez que k<sub>i</sub> > k<sub>i+1</sub>. A cada passo a maior chave do conjunto é posicionada e o processo se repete excluindo a chave já posicionada. Caso uma etapa do processo de comparação não efetue nenhuma troca de chaves o processo de ordenação é dado por concluído.

---

<sup id="ftnt">1</sup> Nas descrições a seguir presumimos sempre que a ordenação é numérica e crescente.

**Roteiro:**

1. Baixe do _Moodle_ os códigos fontes desse Laboratório, descompactando o arquivo.tgz em um diretório.

2. Analise o código fonte do arquivo **ordena.c**. Ele é um programa de teste que usa uma estrutura de dados semelhante ao Laboratório 1, **<u>tVetor</u>**, para definir um vetor de números inteiros.

3. Analise o módulo **tadVetor.\***. Nele algumas funções já estão codificadas.

4. Compile (usado make). Se você analisou esse programa pode perceber que ele cria um vetor com o máximo de sua capacidade a menos que o usuário forneça o número de elementos menor na chamada do programa. Experimente executar o programa **ordena** sem nenhum argumento e passando números menores e maiores que a constante **MAX**.

5. Agora finalmente chegou a hora de colocar a mão na massa. Codifique a função **selectioSort()** chamada pelo programa ordena, para que esta **ordene** o vetor pelo algoritmo de Seleção. Execute e teste sua função avaliando se o conjunto foi mesmo ordenado (sugestão, defina um número pequeno de elementos para esse teste).

6. A verificação manual por inspeção visual não é adequada para vetores grandes. Codifique uma função que verifique se um vetor esta ordenada, retornando um valor booleano indicativo. Utilize essa função depois do processo de ordenação para garantir que seu algoritmo está correto.

7. Implemente os outros dois métodos de ordenação, **insertSort()** e **bubbleSort()**. Proceda o mesmo teste feito com o método **selectionSort()**.

8. Tente analisar a complexidade desses 3 algoritmos. Anote os valores obtidos.

9. Modifique as funções que implementam os métodos de ordenação para elas calculem o número total de comparações executadas pelo algoritmo. Compare com o esperado pela analise feita no item (8).

10. Tente avaliar os algoritmos em seus casos melhor, pior e médio. Nos  2  primeiros crie por meio de funções conjuntos de dados para essas condições. Para o caso médio, simule um conjunto razoável de entradas aleatórias e calcule o número médio de comparações.
