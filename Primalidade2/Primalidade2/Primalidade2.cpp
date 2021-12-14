#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/spirit/include/qi_uint.hpp>
using namespace std;


//Structures para tamanho de bits usados   
//Cada vez que usar um tamanho diferente deve trocar todos os uint's com o adequado 
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<40, 40, boost::multiprecision::unsigned_magnitude>> uint40_t;
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<56, 56, boost::multiprecision::unsigned_magnitude>> uint56_t;
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<80, 80, boost::multiprecision::unsigned_magnitude>> uint80_t;
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<128, 128, boost::multiprecision::unsigned_magnitude>> uint128_t;
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<168, 168, boost::multiprecision::unsigned_magnitude>> uint168_t;
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<224, 224, boost::multiprecision::unsigned_magnitude>> uint224_t;
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<256, 256, boost::multiprecision::unsigned_magnitude>> uint256_t;
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<512, 512, boost::multiprecision::unsigned_magnitude>> uint512_t;
typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<1024, 1024, boost::multiprecision::unsigned_magnitude>> uint1024_t;
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<2048, 2048, boost::multiprecision::unsigned_magnitude>> uint2048_t;
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<4096, 4096, boost::multiprecision::unsigned_magnitude>> uint4096_t;

// Função para calculo de maximo divisor comum
uint1024_t MaximoDivCom(uint1024_t a, uint1024_t b) {
    // se esta na ordem errada
    if (a < b) {
        return MaximoDivCom(b, a);
    }
    // se o maximo é b
    else if (a % b == 0) {
        return b;
    }
    // atualiza recursivamente para encontrar o MDC
    else {
        return MaximoDivCom(b, a % b);
    }
}

// Função de calculo para Fermat
uint1024_t calc(uint1024_t a, uint1024_t n, uint1024_t p) {
    // valor que vai ser retornado
    uint1024_t valor = 1;
    // caso a > p atualiza
    a = a % p;  

    // while que vai reduzindo
    while (n > 0) {
        // Quando n é impar atualiza
        if (n % 2 != 0) {
            valor = (valor * a) % p;
        }
        // reduz e atualiza
        n = n/2;
        a = (a * a) % p;
    }
    return valor;
}

// Função de teste, se composto, se negativo, e se menor que 4, além da primalidade após 4
bool primo(uint1024_t n, uint1024_t k) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    // K iterações
    while (k > 0) {
        // numero a randomico
        uint1024_t a = rand() % (n - 2);
        // Caso a rand for < 2 e não entrar na situação anterior ele soma 2 
        if (a < 2) {
            a = +2;
        }
        // Testando coprimalidade
        if (MaximoDivCom(n, a) != 1) {
            return false;
        }
        // Teorema
        if (calc(a, n - 1, n) != 1) {
            return false;
        }
        k--;
    }
    return true;
}

// Teste de um numero de 1024 bits
uint1024_t number() {
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

int main()
{
    // numero de Iterações
    uint1024_t k = 10;
    // Numero testado inicialmente, pode ser trocado para verificar, como por exemplo pela função "number", onde tem varios resultados proximos
    //uint1024_t n = number();
    uint1024_t n = (uint1024_t)pow(2, 512) * (uint1024_t)pow(2, 511);
    // While para printar todos os numeros primos até o bit requerido, demora muito tempo devido a adição de 1 por vez
    while (n < (uint1024_t)pow(2, 512) * (uint1024_t)pow(2, 512) - 1) {
        if (primo(n, k) == true) {
            cout << n << " ";
        }
        n++;
    }
    return 0;
}

