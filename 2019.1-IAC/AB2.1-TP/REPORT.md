# Identificação

* Página do repositório do trabalho ([link GitHub](TODO)) 

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

![GRAFICO](https://i.imgur.com/f49cprn.png)

### Discussão Introdutória
* Preparatório para o processo:
<p>
Durante a avaliação do tema, o grupo precisou conhecer e dominar alguns pré-requisitos básicos relacionados ao
processamento de dados na <i>UCP</i> e ao consumo da memória <i>RAM</i>.Com isso, a equipe necessitou informar-se acerca de como funciona a função <i>FORK</i> e qual a natureza da relação entre os processos que ela cria, bem como também entender o procedimento de <i>ALOCAÇÃO DE MEMÓRIA</i> na linguagem <b>C</b> e como controlá-lo a partir do método de gerenciamento de processos que a função <i>FORK</i> oferece.
</p>

* Entendendo o Procedimento:
<p>
O procedimento consiste basicamente em replicar um processo de identificação x(esse novo processo é chamado de processo filho),e a partir disso controlá-lo por meio do processo original(chamado de processo pai).O processo filho é idêntico ao processo pai, porém, ao longo da execução de ambos eles irão se distinguir.
</p>

* Descrevendo o que foi feito:

<p>	
1. Incluindo bibliotecas e Declarando variáveis:
	
* Bibliotecas:

Inicialmente,incluimos as bibliotecas <b>sys/types.h</b> e <b>unistd.h</b> para podermos usar a chamada de sistema de criação de processos,a <b>fork()</b>.Após isso,a mesma retorna um número, que será o nosso <b>pid</b>,ou seja,nosso <b>identificador
</b> do processo que foi criado(logo mais utilizaremos esse <i>pid</i> para manipularmos comandos para o monitoramento).

<b>obs: Além das duas bibliotecas citadas utilizamos algumas outras que irão permitir dar comandos para interagir com o <i>SO</i>, entre outras funionalidades necessárias.</b>

* Variáveis:

Primeiro,declaramos uma variável do tipo inteira chamada pid,que irá armazenar o <b>id</b> do processo criado(id dado pela fork).Após isso, declaramos duas strings,a "<i>comma</i>", que irá armazenar os comandos de monitoramento que serão dados ao sistema durante a execução,e a "<i>save_pid</i>",que será responsável por armazenar o pid do processo.

</p>

<p>
2. Checando se a replicação foi válida e o Processo tratado: 

Após a função "<i>fork</i>" retornar o valor do pid na variável 'pid',analizamos:

* Se "<b>pid</b>" > 0, o processo foi criado com "<i>SUCESSO </i>",e o processo atual é o pai;
* Se "<b>pid</b>" == 0, o processo foi criado com "<i>SUCESSO </i>",e o processo atual é o filho;
* Se "<b>pid</b>" > 0, houve <b>erro</b> na criação do processo!;

* Explicando o processo:

Inicialmente,o processo pai coordena a execução do processo filho por meio da inserção de comandos na chamada de sistema.
Esses comandos podem ser: "ucp" ou "ucp-mem", que a monitoram o uso do processador(apenas) e do processador e da memória
(juntos),respectivamente, a partir da execução do filho.Para isso, o processo filho entra em um estado de looping infinito,
sendo que esse é monitorado pelo pai, que permite esse estado por 10 segundos, e, logo após esse período, o processo pai finaliza o filho.
* Sobre os comandos:
O comando 'ucp' consiste em fazer o monitoramento apenas da CPU que, por meio do pŕocesso filho, força o processador ao máximo.Já o comando "ucp-mem" inspenciona o processo em questão, além do consumo da memória principal, ao ultilizar a alocação de memória por meio da função "Malloc". O comando malloc aloca um determinado espaço de memória ram para uso,
e o reserva de acordo com o tipo de variável utilizada, nesse caso, o "character", que corresponde a 1 Byte / 8 bits.
  
</p>

## Utilização intensa da UCP

Com o experimento, esperávamos que após o uso da UCP elevar-se ao máximo, a máquina travaria, porém, ao observarmos os dados  resultantes do monitoramento, descobrimos que isso não ocorre, bem como notamos que ao ultrapassar seu uso máximo, o proces sador aparentemente tenta regular a intensidade de uso na margem dos 100 %. Conforme mostra o gráfico:

![GRAFICO](https://i.imgur.com/7xEdD0J.png)

* Dados: 

![GRAFICO](https://i.imgur.com/h0sPfAC.png)

TODO: explicar se o comportamento da curva **UCP** foi o esperado, sempre justificando sua resposta, referenciando o código fonte do programa e o gráfico do experimento realizado.

## Utilização intensa da UCP e memória

á com o comando ucp-mem o processador se comportou da mesma forma do processo anterior mas, desta vez, alocou memória ao máximo de forma a crescer linearmente. Assim, fazendo o computadador travar, pois diferente do processador que faz a mediação dos processos a memória pŕincipal uma vez alocada só é esavaziada por comandos ou na finalização do processo.   

TODO: explicar se o comportamento da curva **UCP-MEM** foi o esperado, sempre justificando sua resposta, referenciando o código fonte do programa e o gráfico do experimento realizado.
