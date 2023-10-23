#include <stdio.h>
#include <math.h>

typedef struct{
    int num_quadrante;
    int valor_diagonal;
    int primeiro_valor_diagonal;
    int segundo_valor_diagonal;
    int terceiro_valor_diagonal;
    int diferenca_entre_valores;
    int distancia;
}Quadrante;

Quadrante inicializarQuadrante(int _num_quadrante, int _primeiro_valor_diagonal, int _segundo_valor_diagona, int _terceiro_valor_diagonal, int _diferenca_entre_valores){
    Quadrante quadrante;
    quadrante.primeiro_valor_diagonal = _primeiro_valor_diagonal;
    quadrante.segundo_valor_diagonal = _segundo_valor_diagona;
    quadrante.terceiro_valor_diagonal = _terceiro_valor_diagonal;
    quadrante.diferenca_entre_valores = _diferenca_entre_valores;
    return quadrante;

}

int calcularDistancia(int n, int valor_diagonal){
    int distancia = 0;
    if(valor_diagonal < n){
        distancia = n - valor_diagonal;
    }else{
        distancia = valor_diagonal - n;
    }

    return distancia;
}

int definirQuadrante(int n, Quadrante Q){
    int ponto_diagonal;

    int distancia1 = calcularDistancia(n, Q.primeiro_valor_diagonal);
    int distancia2 = calcularDistancia(n, Q.segundo_valor_diagonal);

    int menor_distancia = distancia1;

    while(distancia1 > distancia2){
        Q.primeiro_valor_diagonal+=Q.diferenca_entre_valores;
        Q.diferenca_entre_valores+=8;
        Q.segundo_valor_diagonal+=Q.diferenca_entre_valores;

        distancia1 = calcularDistancia(n, Q.primeiro_valor_diagonal);
        distancia2 = calcularDistancia(n, Q.segundo_valor_diagonal);

    }

    ponto_diagonal = Q.primeiro_valor_diagonal;

    return ponto_diagonal;
}

int diagonalMaisProxima(int n, int diagonal[]){
    int distancia_1, distancia_2, distancia_3, distancia_4;
    int distancia[4];

    for(int i=0; i<=4; i++){
        distancia[i] = calcularDistancia(n, diagonal[i]);
    }

    distancia_1 = calcularDistancia(n, diagonal[1]);
    distancia_2 = calcularDistancia(n, diagonal[2]);
    distancia_3 = calcularDistancia(n, diagonal[3]);
    distancia_4 = calcularDistancia(n, diagonal[4]);

    int menor_distancia = distancia_1;
    int diagonal_mais_proxima = diagonal[1];

    if(distancia_2 < menor_distancia){
        menor_distancia = distancia_2;
        diagonal_mais_proxima = diagonal[2];
    }

    if(distancia_3 < menor_distancia){
        menor_distancia = distancia_3;
        diagonal_mais_proxima = diagonal[3];
    }

    if(distancia_4 < menor_distancia){
        menor_distancia = distancia_4;
        diagonal_mais_proxima = diagonal[4];
    }
    return diagonal_mais_proxima;
}

int primeiroQuadrante(int coordenadas, int ponto_diagonal, int ponto_n){
    int distancia_x;
    int coordenada_x, coordenada_y;

        if(ponto_n < ponto_diagonal){
            coordenada_x = coordenadas;
            distancia_x = ponto_diagonal - ponto_n;
            coordenada_y = coordenadas - distancia_x;
        }else if(ponto_n > ponto_diagonal){
            distancia_x = ponto_n - ponto_diagonal;
            if(distancia_x == 1){
                coordenada_x = coordenadas;
                coordenada_y = coordenadas + 1;
            }else{
                distancia_x-=1;
                //estara mais a esquerda da diagonal a depender da distancia do ponto
                coordenada_x = coordenadas - distancia_x;
                //sobe uma unidade em y, caracteristica exclusiva do quadrante 1
                coordenada_y = coordenadas + 1;
            }
        }else if(ponto_n == ponto_diagonal){
            coordenada_x = coordenadas;
            coordenada_y = coordenadas;
        }

    printf("(%d, %d)\n", coordenada_x, coordenada_y);    
}

int segundoQuadrante(int coordenadasxy, int ponto_diagonal, int ponto_n){
    int distancia;
    int coordenada_x, coordenada_y;


    distancia = calcularDistancia(ponto_n, ponto_diagonal);

    if(ponto_n > ponto_diagonal){
        coordenada_x = coordenadasxy * (-1);
        coordenada_y = coordenadasxy - distancia;
    }else if(ponto_n < ponto_diagonal){
        coordenada_x = (coordenadasxy - distancia) * (-1);
        coordenada_y = coordenadasxy;
    }else if(ponto_n == ponto_diagonal){
        coordenada_x = coordenadasxy * (-1);
        coordenada_y = coordenadasxy;
    }

    printf("(%d, %d)\n", coordenada_x, coordenada_y);
}

int terceiroQuadrante(int coordenadasxy, int ponto_diagonal, int ponto_n){
    int distancia;
    int coordenada_x, coordenada_y;


    distancia = calcularDistancia(ponto_n, ponto_diagonal);

    if(ponto_n > ponto_diagonal){
        coordenada_x = (coordenadasxy - distancia) * (-1);
        coordenada_y = coordenadasxy * (-1);
    }else if(ponto_n < ponto_diagonal){
        coordenada_x = coordenadasxy * (-1);
        coordenada_y = (coordenadasxy - distancia) * (-1);
    }else if(ponto_n == ponto_diagonal){
        coordenada_x = coordenadasxy * (-1);
        coordenada_y = coordenadasxy * (-1);
    }

    printf("(%d, %d)\n", coordenada_x, coordenada_y);
}

int quartoQuadrante(int coordenadasxy, int ponto_diagonal, int ponto_n){
    int distancia;
    int coordenada_x, coordenada_y;


    distancia = calcularDistancia(ponto_n, ponto_diagonal);

    if(ponto_n > ponto_diagonal){
        coordenada_x = coordenadasxy;
        coordenada_y = (coordenadasxy - distancia) * (-1);
    }else if(ponto_n < ponto_diagonal){
        coordenada_x = coordenadasxy - distancia;
        coordenada_y = coordenadasxy * (-1);
    }else if(ponto_n == ponto_diagonal){
        coordenada_x = coordenadasxy;
        coordenada_y = coordenadasxy * (-1);
    }

    printf("(%d, %d)\n", coordenada_x, coordenada_y);
}

int PosicaoDoPonto(int quadrante, int ponto_diagonal, int ponto_n){
    int raiz = sqrt(ponto_diagonal);

    int coordenadas;

    if(raiz%2 != 0){
        coordenadas = (raiz + 1)/2;
    }else{
        coordenadas = raiz/2;
    }

    if(quadrante == 1){
        primeiroQuadrante(coordenadas, ponto_diagonal, ponto_n);
    }

    if(quadrante == 2){
        segundoQuadrante(coordenadas, ponto_diagonal, ponto_n);
    }

    if(quadrante == 3){
        terceiroQuadrante(coordenadas, ponto_diagonal, ponto_n);
    }

    if(quadrante == 4){
        quartoQuadrante(coordenadas, ponto_diagonal, ponto_n);
    }
}

int main(){
    Quadrante Q1, Q2, Q3, Q4;
    Q1 = inicializarQuadrante(1, 8, 24, 48, 16);
    Q2 = inicializarQuadrante(2, 2, 12, 30, 10);
    Q3 = inicializarQuadrante(3, 4, 16, 36, 12);
    Q4 = inicializarQuadrante(4, 6, 20, 42, 14);

    int n;
    int ponto_diagonal;

    scanf("%d", &n);

    if(n == 0){
        printf("(0,0)\n");
        return 0;
    }

    Q1.valor_diagonal = definirQuadrante(n, Q1);
    Q2.valor_diagonal = definirQuadrante(n, Q2);
    Q3.valor_diagonal = definirQuadrante(n, Q3);
    Q4.valor_diagonal = definirQuadrante(n, Q4);

    int diagonais_candidatas[4];
    diagonais_candidatas[1] = Q1.valor_diagonal;
    diagonais_candidatas[2] = Q2.valor_diagonal;
    diagonais_candidatas[3] = Q3.valor_diagonal;
    diagonais_candidatas[4] = Q4.valor_diagonal;

    ponto_diagonal = diagonalMaisProxima(n, diagonais_candidatas);

    int quadrante;
    for(int i=0; i<=4; i++){
        if(diagonais_candidatas[i] == ponto_diagonal){
            quadrante = i;
        }
    }
    
    PosicaoDoPonto(quadrante, ponto_diagonal, n);

    return 0;
}
