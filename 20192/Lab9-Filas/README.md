**Universidade Federal da Bahia - UFBA**<br>
**Instituto de Matemática - IM**<br>
**Departamento de Ciência da Computação - DCC**<br>
**Curso de Bacharelado em Ciência da Computação**<br>
**MATA40 - Estrutura de Dados | Período: 2019.2 | Data: 22/10/2019**<br>
**Prof. Antonio L. Apolinário Junior**

<h1 align="center">Roteiro do Laboratório 9 - Filas</h1>

**Objetivos:**

-   Compreender de forma prática o conceito de **Fila**, suas operações e aplicação;
-   Implementar, em linguagem C, um **TAD Fila**;
-   Aplicar o **TAD Fila** em um exemplo prático.

**Conceitos básicos:**

-   **Fila:**
    Como visto em sala de aula, **filas** são estruturas de dados lineares e sequências que possuem um política de acesso bem definida: **_FIFO - First In, First Out_**. Portanto, sua implementação pode ser feita utilizando qualquer estrutura de dados linear e sequencial, como listas encadeadas ou arranjos. Neste laboratório você estará livre para implementar o TAD Fila como preferir.

**Roteiro:**

1. Baixe do **_Moodle_** o código fonte base para esse Laboratório.

2. Analise a estrutura de arquivos que compõe esse Laboratório. Voce notará que apenas o programa de teste esta especificado. O módulo **fila.h/fila.c** estão completamente vazios. Defina a estrutura de dados e codifique as operações, baseando-se nas operações invocadas pelo programa de teste **main.c**. Fique a vontade de criar outras operações que julgar pertinentes.

3. Compile os programas executando na linha do console o comando **make**. Verifique se o programa de teste **main** é executado com sucesso.

4. Com o **TAD Fila** testado e funcionando, imagine que agora você precisa implementar um sistema de controle de fila de impressão em um Sistema Operacional. Impressões são solicitadas e direcionadas para um _pool_ de impressoras da rede (no máximo 10). Cada _job_ de impressão indica a quantidade de páginas a serem impressas e qual a impressora destino. Construa um simulador que gere aleatoriamente _jobs_ de impressão e controle sua execução.
