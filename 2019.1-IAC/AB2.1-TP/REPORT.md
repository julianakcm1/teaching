# Identificação

* Página do repositório do trabalho ([link GitHub](https://github.com/esterandr02/teaching/blob/master/2019.1-IAC/AB2.1-TP/REPORT.md)) 

* Discente 1
	* Nome: Danilo Felipe Oliveira Silva
	* Matrícula: 19110976
	* Distribuição da nota (%): 36.6
* Discente 2
	* Nome: Ester Albuquerque Aleixo de Andrade
	* Matrícula: 19110982
	* Distribuição da nota (%): 41.3
* Discente 3
	* Nome: Juliana Karla de Carvalho Melo
	* Matrícula: 19111161
	* Distribuição da nota (%): 22.1		
	
# Resultados

* **Gráfico de consumo da CPU e da MEMÓRIA**:

![GRAFICO](https://i.imgur.com/7xEdD0J.png)

### Discussão Introdutória
* Preparatório para o processo:

Durante a avaliação do tema, o grupo precisou conhecer e dominar alguns pré-requisitos básicos relacionados ao
processamento de dados na **UCP** e ao consumo da memória **RAM**. Com isso, a equipe necessitou informar-se acerca de como funciona a função **fork** e qual a natureza da relação entre os processos que ela cria, bem como entender o procedimento de **alocação de memória** na linguagem **C** e como controlá-lo a partir do método de gerenciamento de processos que a função **FORK** oferece.

* Entendendo o Procedimento:

O procedimento consiste em replicar um processo de identificação x (esse novo processo é chamado de *processo filho*) e a partir disso controlá-lo por meio do processo original (chamado de *processo pai*). Os dois processos inicialmente são idênticos, porém ao longo da execução ambos irão se distinguir.

* Descrevendo o que foi feito:

1. Incluindo bibliotecas e Declarando variáveis:
	
* Bibliotecas:

Incluímos as bibliotecas **sys/types.h** e **unistd.h** para podermos usar uma chamada de sistema de criação de processos, 
a partir da chamada fork(). Após isso, tal chamada retorna um número, que originará o nosso **pid**, o qual será nosso identificador
relativo ao processo que foi criado.
**Obs: Além das duas bibliotecas citadas utilizamos algumas outras que irão permitir dar comandos para interagir com o SO, entre outras funcionalidades necessárias.**

* Variáveis:

Declaramos uma variável do tipo *inteiro* chamada de **pid**, que irá armazenar o id do processo criado. Após isso, declaramos duas strings: a "*comma*", que irá armazenar os comandos que serão dados ao sistema; e a "save_pid", que será responsável por armazenar o pid do processo.

2. Checando se a replicação foi válida e o Processo tratado: 

Para Pid:

* Se **pid** > 0, o processo filho foi criado com **SUCESSO**;
* Se **pid** == 0, o processo foi criado com **SUCESSO** e o processo atual é o filho;
* Se **pid** < 0, houve erro na criação do processo.

* Explicando o processo:

Inicialmente, o processo pai coordena a execução do processo filho por meio da inserção de comandos na chamada de sistema.
Esses comandos podem ser do tipo: **"ucp"** ou **"ucp-mem"** os quais monitoram, respectivamente, o uso do processador(apenas) e do processador e da memória (juntos), a partir da execução do processo filho. Para isso, o processo filho entra em um estado de looping infinito, sendo monitorado pelo pai, que permite esse estado por 10 segundos e, logo após esse período, o finaliza.

* Sobre os comandos:

O comando **"ucp"** consiste monitorar apenas a execução de processos na CPU (como já citado) por meio do pŕocesso filho e com isso forçar o processador ao máximo. Já o comando **"ucp-mem"** inspeciona, além do processo em execução, o consumo da memória principal ao utilizar a alocação de memória por meio da função **Malloc()**, que aloca um determinado espaço de *memória ram*, sucessivamente, e o faz de acordo com o tipo da variável requisitada, nesse caso, a variável *char*, que corresponde a *1 Byte* ou 8 *bits*.

## Utilização intensa da UCP

A equipe esperava que após o máximo de consumo da UCP ser atingido, a máquina travaria, porém, ao observarmos os dados resultantes do monitoramento, descobrimos que isso não ocorreu, bem como notamos que ao ultrapassar seu uso máximo, o processador aparentemente tenta regular a intensidade de uso na margem dos 100%. Conforme mostra o gráfico:

![GRAFICO](https://i.imgur.com/7xEdD0J.png)

* Dados: 

![GRAFICO](https://i.imgur.com/h0sPfAC.png)

## Utilização intensa da UCP e memória

Neste experimento, o acompanhamento do processador se deu da mesma maneira que no teste anterior e sua curva de crescimento foi novamente *linear*, entretanto o mesmo não ocorreu com o teste referente à memória. O resultado avaliado nesta apresentou uma curva *crescente de forma linear*, o que já era o esperado pela equipe. Vide o gráfico:

![GRAFICO](https://i.imgur.com/FKg7JYS.png)

* Dados:

![GRAFICO](https://i.imgur.com/XZ4AMz6.png)

