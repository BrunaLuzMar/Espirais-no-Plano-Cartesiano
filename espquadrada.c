#include <stdio.h>
#include <math.h>

int calcularDistancia(int valor1, int valor2){
    if(valor1 > valor2){
        return valor1 - valor2;
    }else if(valor1 < valor2){
        return valor2 - valor1;
    }

    return 0;
}

int maisProximo(int n, int valor1, int valor2){
    int distancia1, distancia2;
    distancia1 = calcularDistancia(n, valor1);
    distancia2 = calcularDistancia(n, valor2);

    if(distancia1 < distancia2){
        return valor1;
    }else{
        return valor2;
    }
}

int calcularPonto(int n){
    int x, y;
    double raiz = sqrt(n);
    int teto = ceil(raiz);
    int piso = floor(raiz);

    int ponto = maisProximo(n, pow(piso, 2), pow(teto, 2));

    raiz = sqrt(ponto);

    if(ponto%2 == 0){
        x = (raiz/2) * (-1);
        y = (raiz/2) * (-1);

        if(n > ponto){
            x = x + (n - ponto);
            y = y;
        }else{
            x = x;
            y = x + (ponto - n);
        }
    }else{
        x = floor(raiz/2);
        y = ceil(raiz/2);

        if(n > ponto){
            x = x - (n - ponto);
            y = y;
        }else{
            x = x;
            y = y - (ponto - n);
        }
    }

    printf("(%d, %d)\n", x, y);

    return 0;
}

int main(){
    int ponto_n;
    scanf("%d", &ponto_n);

    calcularPonto(ponto_n);

    return 0;
}
