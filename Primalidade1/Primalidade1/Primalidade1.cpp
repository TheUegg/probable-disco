#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/spirit/include/qi_uint.hpp>
using namespace std;

//Structures para tamanho de bits usados  
//Cada vez que usar um tamanho diferente deve trocar todos os uint's com o adequado  

typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<40, 40, boost::multiprecision::unsigned_magnitude>> uint40_t;
typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<56, 56, boost::multiprecision::unsigned_magnitude>> uint56_t;
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<80, 80, boost::multiprecision::unsigned_magnitude>> uint80_t;
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<128, 128, boost::multiprecision::unsigned_magnitude>> uint128_t;
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<168, 168, boost::multiprecision::unsigned_magnitude>> uint168_t;
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<224, 224, boost::multiprecision::unsigned_magnitude>> uint224_t;
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<256, 256, boost::multiprecision::unsigned_magnitude>> uint256_t;
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<512, 512, boost::multiprecision::unsigned_magnitude>> uint512_t;
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<1024, 1024, boost::multiprecision::unsigned_magnitude>> uint1024_t;
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<2048, 2048, boost::multiprecision::unsigned_magnitude>> uint2048_t;
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<4096, 4096, boost::multiprecision::unsigned_magnitude>> uint4096_t;
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<4100, 4100, boost::multiprecision::unsigned_magnitude>> uint4100_t;

// Função que retorna a^d % n
uint40_t calc(uint40_t a, uint40_t d, uint40_t n) {
    // Valor que será retornado
    uint40_t valor = 1;
    // Se a >= que n, atualiza
    a = a % n;
    // Faz o while enquanto d n chegar em zero
    while (d > 0) {
        // Se d é par atualiza o valor
        if (d % 2 != 0) {
            valor = (valor * a) % n;
        }
        // d par
        d = d/2;
        a = (a * a) % n;
    }
    return valor;
}

// Função que retorna false se o numero é composto, e true se é primo(provavelmente), roda k vezes
bool primoMiller(uint40_t d, uint40_t n) {
    // rand do próprio C++, definindo um numero randomico de 2 a n - 2
    uint40_t a = rand() % (n - 2);
    // Caso a rand for < 2 e não entrar na situação anterior ele soma 2
    if (a < 2) {
        uint40_t a = +2;
    }
    
    // Chama função de calculo
    uint40_t x = calc(a, d, n);
    // se x retornar os extremos retorna true
    if (x == 1 || x == n - 1) {
        return true;
    }
    
    // Multiplica d até x cair em no if anterior, porém se for 1 como estamos multiplicando o d ao quadrado, se for 1 retorna false
    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;
        if (x == n - 1) {
            return true;
        }
        if (x == 1) {
            return false;
        }
    }
    // Retorna false(composto)
    return false;
}

// Função geral que testa os valores obvios e chama o método de miller
bool primo(uint40_t n, uint40_t k) {
    uint40_t d = n - 1;
    // n negativo ou 0
    if (n <= 1) {
        return false;
    }   
    // 2 ou 1 são primos
    if (n <= 3) {
        return true;
    }
    // Enquanto d for par, divide por 2 até chegar em um valor impar
    while (d % 2 == 0) {
        d /= 2;
    }
    // Faz o método de miller K vezes
    for (int i = 0; i < k; i++) {
        if (primoMiller(d, n) ==  false) {
            return false;
        }
    }
    return true;
}

// test for bigNUM
/*
uint1024_t number(){
    return (uint1024_t)2468 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 +
        (uint1024_t)2022242628 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 +
        (uint1024_t)4042444648 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 +
        (uint1024_t)6062646668 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 +
        (uint1024_t)8082848688 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 +
        (uint1024_t)2002022042 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 +
        (uint1024_t)620822022 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 +
        (uint1024_t)2224226228 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 +
        (uint1024_t)2402422442 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 +
        (uint1024_t)4624826026 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 +
        (uint1024_t)2264266268 * 10000000000 * 10000000000 * 10000000000 * 10000000000 +
        (uint1024_t)2802822842 * 10000000000 * 10000000000 * 10000000000 +
        (uint1024_t)8628840040 * 10000000000 * 10000000000 +
        (uint1024_t)2404406408 * 10000000000 +
        (uint1024_t)4204224247;
}
*/


// Programa n funciona para numeros grandes, testei diferentes formas, porém não funciona para bigNUM
int main()
{
    // Numero de iterações 
    int k = 10;
    // n para fazer a tabela de valores, pode trocar para um n com  
    uint40_t n = 0;
    // percorre até chgar em 41 bits 
    while (n < (uint56_t)pow(2, 41)) {
        // print caso primo 
        if (primo(n, k)) {
            cout << n << " ";
        }
        n++;
    }
    return 0;
}
