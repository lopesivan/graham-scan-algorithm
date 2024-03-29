/*  
 * file : point.c
 *     
 * Plataforma Alvo : Raspberry Pi
 * Compilador : GCC
 * IDE :  VSCode(editor de texto)
 *  
 * Funcoes que sao usadas pela funcao convexHull para calcular o fecho convexo
 * 
 *  Authors : Jessica Lewinter e Thalys Viana
 *  Copyright (C) 2018 Jessica Lewinter <jessicalewinter@gmail.com>
 *  Copyright (C) 2018 Thalys Viana  <thalysvianaguiar@gmail.com>
 *  Data de Atualizacao : 01 de outubro de 2018
 */

#include "point.h"
#include "graham_scan.h"

/*
 * Função  : Troca a posição de dois pontos entre si dados com entrada
 * 
 * Entrada : p1, p2 -> pontos no plano 2D
 * Retorno : Nada, OBS:(altera a posição de dois pontos entre si)
 * Saída   : Nada
 * Variáveis Locais: temp(variavel auxiliar)
 * Variáveis Globais Usadas : Nenhuma
 * Variáveis Globais Alteradas : Nenhuma
 */

int swap(Point *p1, Point *p2)
{
    Point temp = *p1; //seta o valor da variavel auxiliar temp para o valor inicial de p1 
    *p1 = *p2;  //coloca o novo valor de p1 com o antigo de p2 
    *p2 = temp; //agora, muda o valor de p2 com o antigo valor de p1(usando temp como auxiliar) 
}

/*
 * Função  : Calcula o quadrado da distância entre dois pontos p1 e p2
 * 
 * Entrada : p1, p2 -> pontos no plano 2D
 * Retorno : Quadrado da distância entre dois pontos dado como entrada
 * Saída   : Nada
 * Variáveis Locais: Nenhuma
 * Variáveis Globais Usadas : Nenhuma
 * Variáveis Globais Alteradas : Nenhuma
 */

int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x) * (p1.x - p2.x) +
           (p1.y - p2.y) * (p1.y - p2.y); //retorna o quadrado da distância entre os pontos
}
/*
 * Função  : Função usada para achar a orientação do grupo de três pontos (p, q, r) calcula o 
 * coeficiente angular entre os pontos, para não deixar a função complexa, não calcula os ângulos 
 * polares pois com a orientação é possível saber quais pontos irá formar o fecho convexo
 * 
 * Entrada : p, q, r -> pontos no plano 2D
 * Retorno : A função retorna os seguintes valores:
                0 --> p, q e r são colineares (colinear)
                1 --> Sentido horário (clockwise)
                2 --> Sentido anti-horário (counterclockwise)
 * Saída   : Nada 
 * Variáveis Locais: val
 * Variáveis Globais Usadas : Nenhuma
 * Variáveis Globais Alteradas : Nenhuma
 */

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y); //calcula o coeficiente angular entre os pontos

    if (val == 0)
        return 0;             // colinear
    return (val > 0) ? 1 : 2; // horário ou anti-horário
}

/*
 * Função  : Ordena os pontos com base no seu ângulo polar(no caso da nossa função o coeficente angular)
 * 
 * Entrada : vp1, vp2 -> pontos no plano 2D
 * Retorno : Retorna uma função usada pela função de biblioteca qsort() para ordenar os pontos com relação ao primeiro ponto
 * Saída   : Nada 
 * Variáveis Locais: o -> orientação do segmento de reta
 * Variáveis Globais Usadas : p0 -> ponto de referência no plano 2D
 * Variáveis Globais Alteradas : Nenhuma
 */

int compare(const void *vp1, const void *vp2)
{
    Point *p1 = (Point *)vp1; // Cria um ponteiro p1 e seta ao valor de vp1
    Point *p2 = (Point *)vp2;

    // Achar orientação
    int o = orientation(p0, *p1, *p2); //Cria uma variavel o com o retorno da função orientation
    if (o == 0)
        return (distSq(p0, *p2) >= distSq(p0, *p1)) ? -1 : 1; // se a variavel o for igual a 0 significa que os pontos são colineares, faz um comparativo entre as distâncias de (p0, *p2)e de (p0, *p1), se a de (p0, *p2) for maior retorna -1(anti-horario), caso contrário 1(hoŕario)

    return (o == 2) ? -1 : 1; //retorna -1 se for anti-horário e 1 se for horário
}