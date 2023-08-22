# AED2_EP1
Primeiro trabalho prático da disciplina de Algoritmos e Estruturas de Dados II

O objetivo do projeto é desenvolver programa em linguagem C que solucione 
o problema da escolha da altura da carreta baú para uso na movimentação
de carga por uma empresa de logística utilizando modelagem por grafos.

Definição do problema:

A ocorrência de entalamento de veículos de transporte de carga na passagem de
túneis, pontes, viadutos, praças de pedágios etc. é um problema recorrente no Brasil
devido ao legado das obras de engenharia, e que causa prejuízo à economia e
compromete a segurança da população (Figuras 1 e 2).

Uma empresa de logística de carga leve que opera em todo o território nacional
definiu cinco alturas padrões de 2.5, 3.0, 3.5, 4.0 e 4.5 metros, para as carretas baú
de sua frota.

Estas carretas são utilizadas para movimentação de carga entre as centenas de
centros de distribuição espalhados pelo Brasil. O software de logística da empresa
tem registrado o limite máximo de altura em metros da menor passagem existente
nas rotas entre os centros de distribuição da empresa.
No caso de não existir uma passagem limitante de altura, a empresa cadastrou a
altura do gabarito vertical mínimo para vias expressas estabelecido pelo DNIT que é
5.5 metros. A área de TI desta empresa quer implementar uma nova função no
sistema na qual serão informados dois centros de distribuição da empresa e o
sistema responda qual é a maior carreta baú que possa ser utilizada sem causar
atolamento mas também transportando o maior volume de carga possível entre os
centros de distribuição.

Arquivos de entrada e saída:

O arquivo de entrada contém várias linhas. Na primeira linha são informados o
número de centros de distribuição da empresa, o número de rotas entre estes
centros de distribuição e a quantidade de consultas desejadas. Exemplo:

4 5 3
1 2 4.0
1 4 4.3
2 3 3.8
2 4 5.5
3 4 3.3
1 3
1 4
1 2

Na primeira linha: 4 centros de distribuição,
5 rotas entre estes centros, e 3 consultas são desejadas. As cinco linhas seguintes
informam os limites máximos de altura existentes nas rotas entre dois centros de
distribuição. Por exemplo, a linha 2 indica que na rota entre o centro 1 e
o centro 2 existe um limite de altura de passagem de 4 metros. Todos
as rotas diretas definidas entre dois centros de distribuição devem ser informadas,
por exemplo, existe uma rota direta definida entre o centro 2 e o
centro 4, mas não existe uma rota direta definida entre o centro 1 
e o centro 3. As rotas são definidas segundo critérios e fatores logísticos
da empresa. O limite de altura existente entre um centro
e outro é o mesmo na ida e na volta, portanto adota-se no arquivo de entrada
a ordem crescente do número do centro de distribuição, ou seja, na linha 4 uma
entrada 3 2 3.8 é inválida.

