# TP1 - O Plano de Campanha

## Algoritmos 1

## Data de entrega: 11/10/

## 1 Objetivos do trabalho

O objetivo deste trabalho ́e modelar o problema computacional descrito a seguir utilizando uma estrutura
de dados que permita resolvˆe-lo de forma eficiente com os algoritmos estudados nesta disciplina.
Ser ̃ao fornecidos alguns casos de teste bem como a resposta esperada para que o aluno possa verificar
a corretude de seu algoritmo. N ̃ao obstante, recomenda-se que o aluno crie casos de teste adicionais a fim
de validar sua pr ́opria implementa ̧c ̃ao. A sua solu ̧c ̃ao deve obrigatoriamente ser desenvolvida utilizando
algoritmos de grafos. O c ́odigo-fonte da solu ̧c ̃ao e uma documenta ̧c ̃ao sucinta (relat ́orio contendo n ̃ao mais
do que 5 p ́aginas) dever ̃ao ser submetidos via moodle at ́e a data limite de 11/10/2022. A especifica ̧c ̃ao do
conte ́udo do relat ́orio e linguagens de programa ̧c ̃ao aceitas ser ̃ao detalhadas nas se ̧c ̃oes subsequentes.

## 2 Defini ̧c ̃ao do problema

O atual deputado federal Alan Turing est ́a tentando se reeleger, ent ̃ao escreveu um plano de campanha com
v ́arias propostas diferentes para abranger a maior quantidade de eleitores poss ́ıvel. Infelizmente, com tantas
propostas, o candidato acabou se contradizendo e por isso ele precisa repensar seu plano de campanha.
Por sugest ̃ao de seu assessor, o deputado fez uma enquete no seu Instagram para que cada seguidor
fizesse 4 escolhas. Primeiro o seguidor deve escolher duas propostas que ele acha que devem continuar no
projeto de campanha, e em seguida escolher duas propostas que ele acha que devem ser retiradas do plano
de campanha.
Ap ́os a vota ̧c ̃ao o deputado deseja saber se existe um conjunto de propostas que agrade todos
os seus seguidores simultaneamente. Como esta ́e uma tarefa muito dif ́ıcil, foi decidido quepara
agradar um seguidor ao menos uma das propostas votadas a favor deve continuar no plano de
campanha do deputado, e ao menos uma das propostas com voto contr ́ario deve ser retirada
do plano.


## 3 Exemplo do Problema

O deputado possui 3 seguidores no seu Instagram e publicou 4 propostas diferentes para serem votadas. O
primeiro seguidor votou a favor das propostas 1 e 2 e votou contra as propostas 3 e 4. O segundo seguidor
votou a favor das propostas 3 e 4 e votou contra as propostas 1 e 2. E o ́ultimo seguidor votou a favor das
propostas 2 e 3 e votou contra as propostas 1 e 4. Para essa rodada de vota ̧c ̃oes, ́e poss ́ıvel que o deputado
agrade a todos os seguidores que votaram quando escolhemos manter as propostas 2 e 3 e removemos as
propostas 1 e 4. Podemos visualizar isso melhor na figura 1.

Figure 1: Exemplo com poss ́ıvel solu ̧c ̃ao. Nela podemos ver os votos dos seguidores e quais votos foram
satisfeitos ou n ̃ao. Observe que pelo menos uma escolha de manter de cada seguidor foi respeitada, assim
como pelo menos uma escolha de retirada de cada seguidor foi respeitada.

### 3.1 Modelagem do Problema

Este trabalho pr ́atico aborda a parte de grafos da ementa desta disciplina. Para a resolu ̧c ̃ao do problema a
sua modelagemprecisausar grafos.

### 3.2 Formato da Entrada Esperada

O seu programa dever ́a processar diversos casos de teste em uma ́unica execu ̧c ̃ao. A primeira linha de um
cen ́ario de teste ́e composta de dois n ́umero inteirosSeP, representando respectivamente o n ́umero de
seguidores que responderam a enquete (1≤S≤1000) e o n ́umero de propostas do plano de campanha
(1≤P ≤10000). Cada uma das pr ́oximasSlinhas descreve a preferˆencia de um seguidor, representada
por quatro inteirosX 1 ,X 2 ,Y 1 ,Y 2 (0≤X 1 , X 2 , Y 1 , Y 2 ≤P).X 1 eX 2 s ̃ao propostas que o seguidor deseja
manter no plano de campanha.Y 1 eY 2 s ̃ao propostas que o seguidor deseja retirar do plano de campanha.
Um valor 0 (zero) para qualquer uma das vari ́aveisX 1 ,X 2 ,Y 1 eY 2 significa que o seguidor n ̃ao est ́a fazendo
uso daquele voto. A entrada acaba quandoS=P= 0.

### 3.3 Formato da Sa ́ıda Esperada

Para cada caso de teste seu programa deve imprimir uma linha, contendo ou a palavra ’sim’ (se ́e poss ́ıvel
satisfazer a todos os seguidores que votaram) ou a palavra ’nao’ (se n ̃ao ́e poss ́ıvel).


### 3.4 Caso de teste

Entrada

3 4
0 2 3 4
0 4 1 2
2 3 1 4
4 4
1 2 3 4
3 4 1 2
1 3 2 4
1 4 2 3
4 4
1 2 3 4
3 4 1 0
1 3 2 4
2 4 0 3
7 6
1 3 4 2
1 2 4 5
2 3 5 1
4 5 1 6
1 2 3 4
1 4 3 6
2 6 1 3
0 0

```
Sa ́ıda
sim
sim
nao
nao
```
#### .

## 4 Implementa ̧c ̃ao

O seu programa dever ́a ser implementado na linguagem C e dever ́a fazer uso apenas de fun ̧c ̃oes da biblioteca
padr ̃ao da linguagem. Trabalhos que utilizem qualquer outra linguagem de programa ̧c ̃ao e/ou que fa ̧cam uso
de bibliotecas que n ̃ao a padr ̃ao n ̃ao ser ̃ao aceitos.
O aluno pode implementar seu programa em qualquer ambiente (Windows, Linux, MacOS, etc...),
no entanto, deve garantir que seu c ́odigo compile e rode nas m ́aquinas do DCC (tigre.dcc.ufmg.br ou
jaguar.dcc.ufmg.br ou login.dcc.ufmg.br), pois ser ́a neste ambiente que o TP ser ́a corrigido. Note que essas
m ́aquinas s ̃ao acess ́ıveis a todos os alunos do DCC com seu login e senha, podendo inclusive ser realizado
acesso remoto via ssh. O aluno pode buscar informa ̧c ̃oes no site do CRC (Centro de Recursos Computa-
cionais) do DCC (https://www.crc.dcc.ufmg.br/).
Para facilitar o desenvolvimento vamos fornecer uma estrutura base de arquivos com Makefile j ́a configu-
rado. A pastaTP01-Template-CPP.zip, dispon ́ıvel para download na tarefa do Moodle, contem 4 arquivos:
main.cpp,campanha.cpp,campanha.hppeMakefile. O ponto de entrada do seu programa est ́a no arquivo
main.cpp. Para compilar seu programa basta executar o comando “make” no mesmo diret ́orio que o Makefile
est ́a. Ao final deste comando, se a compila ̧c ̃ao for bem sucedida, ser ́a criado um arquivo execut ́avel chamado
“tp01”. Esse arquivo pode ser executado pela linha de comando usando “./tp01”.
O arquivo da entrada deve ser passado ao seu programa como entrada padr ̃ao, atrav ́es da linha de
comando (e.g.,$ ./tp01 < casoTeste01.txt) e gerar o resultado tamb ́em na sa ́ıda padr ̃ao (n ̃ao gerar
sa ́ıda em arquivo).


## 5 O que deve ser entregue

Dever ́a ser submetido um arquivo .zip contendo apenas uma pasta chamada tp1, esta pasta dever ́a conter:
(i) Documenta ̧c ̃ao em formato PDF e (ii) Implementa ̧c ̃ao.

### 5.1 Documenta ̧c ̃ao

A documenta ̧c ̃ao deve ser sucinta e n ̃ao ultrapassar 5 p ́aginas. Vocˆe deve descrever cada solu ̧c ̃ao do problema
de maneira clara e precisa, detalhando e justificando os algoritmos e estruturas de dados utilizados. Para tal,
artif ́ıcios como pseudo-c ́odigos, exemplos ou diagramas podem ser ́uteis. Note que documentar uma solu ̧c ̃ao
n ̃ao ́e o mesmo que documentar seu c ́odigo. N ̃ao ́e necess ́ario incluir trechos de c ́odigo em sua documenta ̧c ̃ao
nem mostrar detalhes de sua implementa ̧c ̃ao, exceto quando estes influenciem o seu algoritmo principal, o
que se torna interessante.E essencial que a documenta ̧c ̃ao contenha ao menos: ́

```
1.Identifica ̧c ̃ao: Nome e Matr ́ıcula.
```
```
2.Introdu ̧c ̃ao: Breve resumo do problema com suas palavras.
```
```
3.Modelagem: Detalhamento e justificativa dos algoritmos e estruturas de dados escolhidos.
```
### 5.2 Implementa ̧c ̃ao

O c ́odigo fonte submetido deve conter todos os arquivos fonte e o Makefile usado para compilar o pro-
jeto. Lembre que seu c ́odigo deve ser leg ́ıvel, ent ̃aoevite vari ́aveis com nomes n ̃ao descritivos
(int a, aa, aaa;) e lembre-se decomentar seu c ́odigo. J ́a estamos fornecendo uma implementa ̧c ̃ao
base com os arquivos necess ́arios, ent ̃ao indicamos que vocˆe s ́o o altere se for necess ́ario.

### 5.3 Atrasos

Trabalhos poder ̃ao ser entregues ap ́os o prazo estabelecido, por ́em sujeitos a uma penaliza ̧c ̃ao regida pela
seguinte f ́ormula:

```
∆p=
```
```
2 d−^1
0. 32
```
#### % (1)

Nesta f ́ormuladrepresenta dias de atraso. Por exemplo, se a nota dada pelo corretor for 70 e vocˆe
entregou o TP com 4 dias corridos de atraso, sua penaliza ̧c ̃ao ser ́a de ∆p= 25% e, portanto, a sua nota final
ser ́a: Nf= 70(1−∆p) = 52.2. Note que a penaliza ̧c ̃ao ́e exponencial e 6 dias de atraso resultam em uma
penaliza ̧c ̃ao de 100%.

## 6 Considera ̧c ̃oes Finais

Assim como em todos os trabalhos dessa disciplina ́e estritamente proibida a c ́opia parcial ou integral de
c ́odigos, seja da internet ou de colegas. Utilizaremos o algoritmo MOSS para detec ̧c ̃ao de pl ́agio em trabalhos,
seja honesto. Vocˆe n ̃ao aprende nada copiando c ́odigo de terceiros nem pedindo a outra pessoa que fa ̧ca o
trabalho por vocˆe. Se a c ́opia for detectada, sua nota ser ́a zerada e os professores ser ̃ao informados para que
as devidas providˆencias sejam tomadas.


