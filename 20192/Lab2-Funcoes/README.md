**Universidade Federal da Bahia - UFBA**<br>
**Instituto de Matemática - IM**<br>
**Departamento de Ciência da Computação - DCC**<br>
**Curso de Bacharelado em Ciência da Computação**<br>
**MATA40 - Estrutura de Dados | Período: 2019.2 | Data: 20/08/2019**<br>
**Prof. Antonio L. Apolinário Junior**

<h1 align="center">Roteiro do Laboratório 2 - Funções</h1>

**Objetivos:**

-   Compreender o conceito de **subprogramação** e **modularidade**;
-   Apresentar os mecanismos de definição e uso de funções em Linguagem C;
-   Definir escopo de variáveis local e global, no contexto de funções;
-   Discutir os conceitos de passagem de parâmetros em Linguagem C, com destaque para os mecanismos de passagem por valor e por referência;
-   Implementar exemplos de funções em linguagem C.

**Conceitos básicos:**

-   **Funções:**
    Em linguagem C, uma função representa um conjunto/bloco de comandos pode ser chamado em qualquer ponto do programa. A definição de uma função segue o padrão: 
	```c
	tipo_de_retorno nome_da_função (listagem de parâmetros) {
		bloco de comandos e declarações de variáveis locais
	}
	```

	Os **parâmetros formais** da função são considerados como variáveis locais a função, que são inicializadas quando do início da execução da função, a partir das variáveis/valores/expressões utilizadas na chamada da função, chamados de **parâmetros reais**.<br>
	Parâmetros podem ser passados por valor ou por referência. No primeiro caso, uma cópia dos parâmetros reais é atribuída aos parâmetros formais. Nesse caso, mudanças feitas nos parâmetros formais dentro da função não afetam os parâmetros reais. No caso de passagem de parâmetros por referência, o endereço do parâmetro real é atribuido ao parametro formal, que portanto tem acesso ao mesmo endereço de memória do parametro real. Portanto, mudanças feitas no parametro formal resultam em mudanças no parametro real. Um exemplo da diferença de sintaxe dos dois tipos de passagem é mostrado a seguir.

	```c
	void A(int x, int y) {
		x = 10*y;
		y = x + 20;
	}

	void B(int* x, int* y) {
		*x = 10*(*y);
		*y = *x + 20;
	}

	int main() {
		int temp1 = 10, temp2 = 20;
		printf("%d %d\n", temp1, temp2);
		A(temp1, temp2);
		printf("%d %d\n", temp1, temp2);
		B(&temp1, &temp2);
		printf("%d %d\n", temp1, temp2);
	}
	```

**Roteiro:**

1. Baixe do _Moodle_ os códigos fontes desse Laboratório, descompacte e identifique os arquivos gerados.

2. Analise o código fonte do arquivo **main.c**. Entenda o que o programa faz e qual a saída esperada. Tire todas as suas dúvidas quanto ao seu funcionamento antes de prosseguir para o próximo item.

3. Analise o módulo **tadVetor.\***. Esse módulo é responsável por implementar todas as funções utilizadas no programa **main.c**. Veja que o programa principal usa a estrutura de dados definido no arquivo **tadVetor.h** e as funções implementadas em **tadVetor.c.**

4. Para compilar os dois módulos, utilize o script **Makefile**. O utilitário **make** interpreta esse script e gera os códigos objeto e o código executável do programa **main**. Para compilar execute no terminal o comando: **make**

5. Sua tarefa nesse laboratório é implementar todas as funções especificadas no módulo **tadVetor.c**. Os comentários no arquivo **tadVetor.h** descrevem o que se espera de cada função. Em caso de dúvida chame o professor/monitor.

**Desafio:**

1. Crie uma variante desse programa para um **tadVetorPtos**, que armazena não de **floats** mas de pontos 3D. Cada ponto deve conter as seguintes informações:

    - Identificador (ID), um valor inteiro;
    - Coordenadas (X, Y, Z) em valores reais;
    - Cor (R, G, B) em valores inteiros no intervalo [0...255].

2. Acrescente operações que calculem:

    - O baricentro do conjunto de pontos;
    - Os limites nas 3 direções (X,Y,Z) desse conjunto de pontos;
    - Busque um ponto no conjunto, considerando uma certa tolerancia.
