# trabalho_md_espirais

## Descrição
Os programas calculam as coordenadas de um dado ponto em um plano cartesiano de acordo com os padrões determinados pela espiral quadrada e triangular. Dado esse ponto o teto e o piso de sua raiz são calculados, o quadrado desses valores correspondem a pontos nas espirais e a divisão da raiz do quadrado mais proximo ao ponto de entrada resulta na posição desse quadrado, a partir dele o algoritmo encontra da posição do número informado.

## Pré-Requisitos
O sistema operacional Linux utilizado foi Ubuntu, na versão 22.04.3. A versão do compilador gcc utilizada foi 11.4.0. Para compilar cada um dos programas são necessários os seguintes comandos:

gcc espquadrada.c -o espquadrada -lm
gcc esptriangular.c -o esptriangular -lm

Em seguida, para executar os programas, utilize os seguintes comandos:

./espquadrada
./esptriangular

## Funcionamento
O programa irá solicitar que você digite um número, ele irá calcular as coordenadas do ponto informado a partir de pontos estrategicos mais proximos a ele e imprimi-las. Digite um número e pressione Enter.

Exemplo:
$ ./espquadrada
13
(-2, 1)

As coordenadas do ponto 13 são (-2, 1).
