//
// Created by darius on 09/05/17.
//

#ifndef TALLERZ_TESTBASE_H
#define TALLERZ_TESTBASE_H

/*
 * Instalar: sudo apt-get install cxxtest;
 *
 * Ejemplo extraido del guide.pdf y resumido acá:
 * 1) En la terminal nos posicionamos en esta carpeta z_tests
 * 2) Ejecutamos: cxxtestgen --error-printer -o runner.cpp Test_Ejemplo.h
 * 3) Compilamos el runner: g++ runner.cpp -o runner
 * 4) Ejecutamos: ./runner
 * 5) Leemos el resultado: Running cxxtest tests (1 test).OK!
 */
#include <cxxtest/TestSuite.h>

class Test_Ejemplo : public CxxTest::TestSuite
{
public:
    void testAddition(void)
    {
        TS_ASSERT(1 + 1 > 1);
        TS_ASSERT_EQUALS(1 + 1, 2);
    }
};

#endif //TALLERZ_TESTBASE_H
