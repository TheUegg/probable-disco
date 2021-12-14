#include <iostream>
#include <cmath>
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
typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<224, 224, boost::multiprecision::unsigned_magnitude>> uint224_t;
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<256, 256, boost::multiprecision::unsigned_magnitude>> uint256_t;
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<512, 512, boost::multiprecision::unsigned_magnitude>> uint512_t;
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<1024, 1024, boost::multiprecision::unsigned_magnitude>> uint1024_t;
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<2048, 2048, boost::multiprecision::unsigned_magnitude>> uint2048_t;
//typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<4096, 4096, boost::multiprecision::unsigned_magnitude>> uint4096_t;

// ant � o X do teorema 
uint224_t ant = 5368709;
// A utilizado no teorema 
uint224_t A = 16807;

// Rand criado pelo teorema, tendo o tamanho maximo de M, no caso boost_product 
uint224_t rand(uint224_t A, uint224_t ant, uint224_t boost_product) {
    ant = (A * ant ) % (uint224_t)boost_product;
    return ant;
}

// M utilizado no teorema, assim como as structures devem ser usados os adequados, dependendo do tamanho de bits requeridos 
uint224_t boost_product() {
    // M for 40 bits
    //uint40_t ans = (uint40_t)549755813887;
    // M for 56 bits
    //uint56_t ans = (uint56_t)72057594037927935;
    // M for 80 bits
    //uint80_t ans = (uint80_t)3 * 5 * 5 * 11 * 17 * 31 * 41 * 257 * 61681 * 4278255361;
    // M for 128 bits
    //uint128_t ans = (uint128_t)3 * 5 * 17 * 257 * 641 * 65537 * 274177 * 6700417 * 67280421310721;
    // M for 168 bits
    //uint168_t ans = (uint168_t)3 * 3 * 5 * 7 * 7 * 13 * 17 * 29 * 43 * 113 * 127 * 241 * 337 * 1429 * 3361 * 5419 * 14449 * 15790321 * 88959882481;
    // M for 224 bits
    uint224_t ans = (uint224_t)pow(2, 224) - 1;
    // M for 256 bits
    //uint256_t ans = (uint256_t)pow(2, 256) - 1;
    // M for 512 bits
    //uint512_t ans = (uint512_t)pow(2, 512) - 1;
    // M for 1024 bits
    //uint1024_t ans = (uint1024_t)pow(2, 512) * (uint1024_t)pow(2, 512) - 1;
    // M for 2048 bits
    //uint2048_t ans = (uint2048_t)pow(2, 512) * (uint2048_t)pow(2, 512) * (uint2048_t)pow(2, 512) * (uint2048_t)pow(2, 512) - 1;
    // M for 4096 bits
    //uint4096_t ans = (uint4096_t)pow(2, 512) * (uint4096_t)pow(2, 512) * (uint4096_t)pow(2, 512) * (uint4096_t)pow(2, 512) * (uint4096_t)pow(2, 512) * (uint4096_t)pow(2, 512) * (uint4096_t)pow(2, 512) * (uint4096_t)pow(2, 512) - 1;
    return ans;
}

// Max no while, minha determina��o de parada, logo assim que passar deste num�ro, ou seja o bit requerido, o calculo para e retorna o n�mero  
// assim como as structures devem ser usados os adequados, dependendo do tamanho de bits requeridos 
uint224_t size_MAX() {
    // MAX for 40 bits
    //uint40_t ans = (uint40_t)10995116 * 10000;
    // MAX for 56 bits
    //uint56_t ans = (uint56_t)72057594 * 100000000;
    // MAX for 80 bits
     //uint80_t ans = (uint80_t)12089258 * 1000000000 * 10000000;
    // MAX for 128 bits
    //uint128_t ans = (uint128_t)34028237 * 100000000 * 1000000000 * 1000000000 * 10;
    // MAX for 168 bits
    //uint168_t ans = (uint168_t)37414442 * 100000000 * 1000000000 * 1000000000 * 1000000000 * 1000;
    // MAX for 224 bits
    uint224_t ans = (uint224_t)26959947 * 100000000 * 1000000000 * 1000000000 * 1000000000 * 1000000000 * 1000000000;
    // MAX for 256 bits
    //uint256_t ans = (uint256_t)11579209 * 100000000 * 1000000000 * 1000000000 * 1000000000 * 1000000000 * 1000000000 * 1000000000;
    // MAX for 512 bitds
    //uint512_t ans = (uint512_t)1340781 * 100000000 * 1000000000 * 1000000000 * 1000000000 * 1000000000 * 1000000000 * 1000000000 * 1000000000 * 1000000000 * 1000000000 * 1000000000 * 1000000000 * 1000000000 * 1000000000 * 10000000;
    // MAX for 1024 bits
    //uint1024_t ans = (uint1024_t)17976931348.623159077293051907890247336179769789423065727343 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 100000000;
    // MAX for 2048 bits
    //uint2048_t ans = (uint2048_t)3231700.6071311007300714876688669951960444102669715484032130 * 1000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000;
    // MAX for 4096 bits
    //uint4096_t ans = (uint4096_t)1044.388881413152506691752710716624382579964249047383780384 * 1000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000 * 10000000000;
    return ans;
}

int main(int argc, char** argv)
{
    // Clock usado para verificar o tempo de execu��o
    clock_t tStart = clock();
    // Continua calculando at� chegar no bit requerido
    while (ant < size_MAX()) {
        ant = rand( A, ant, boost_product());
    }
    // Prints 
    std::cout << ant << "\n";
    std::cout << ("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC) << "\n";
    return 0;
}