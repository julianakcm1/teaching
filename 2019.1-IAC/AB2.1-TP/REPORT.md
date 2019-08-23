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
Inicialmente,incluimos as bibliotecas <b>sys/types.h</b> e <b>unistd.h</b> para podermos usar a chamada de sistema de criação de processos,a <b>fork()</b>.Após isso,a mesma retorna um número, que será o nosso <b>pid</b>,ou seja,nosso <b>identificador
</b> do processo que foi criado(logo mais utilizaremos esse <i>pid</i> para manipularmos comandos para o monitoramento).
</p>

<p>
</p>


## Utilização intensa da UCP

TODO: explicar se o comportamento da curva **UCP** foi o esperado, sempre justificando sua resposta, referenciando o código fonte do programa e o gráfico do experimento realizado.

## Utilização intensa da UCP e memória

TODO: explicar se o comportamento da curva **UCP-MEM** foi o esperado, sempre justificando sua resposta, referenciando o código fonte do programa e o gráfico do experimento realizado.
