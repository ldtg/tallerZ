/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_Test_Ejemplo_init = false;
#include "/home/darius/CLionProjects/tallerZ/z_tests/Test_Ejemplo.h"

static Test_Ejemplo suite_Test_Ejemplo;

static CxxTest::List Tests_Test_Ejemplo = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_Test_Ejemplo( "Test_Ejemplo.h", 10, "Test_Ejemplo", suite_Test_Ejemplo, Tests_Test_Ejemplo );

static class TestDescription_suite_Test_Ejemplo_testAddition : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_Test_Ejemplo_testAddition() : CxxTest::RealTestDescription( Tests_Test_Ejemplo, suiteDescription_Test_Ejemplo, 13, "testAddition" ) {}
 void runTest() { suite_Test_Ejemplo.testAddition(); }
} testDescription_suite_Test_Ejemplo_testAddition;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
