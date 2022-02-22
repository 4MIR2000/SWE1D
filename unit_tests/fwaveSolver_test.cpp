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
bool suite_fwaveSolver_test_init = false;
#include "fwaveSolver_test.hpp"

static fwaveSolver_test suite_fwaveSolver_test;

static CxxTest::List Tests_fwaveSolver_test = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_fwaveSolver_test( "fwaveSolver_test.hpp", 9, "fwaveSolver_test", suite_fwaveSolver_test, Tests_fwaveSolver_test );

static class TestDescription_suite_fwaveSolver_test_testEigenvalueComputation1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_fwaveSolver_test_testEigenvalueComputation1() : CxxTest::RealTestDescription( Tests_fwaveSolver_test, suiteDescription_fwaveSolver_test, 13, "testEigenvalueComputation1" ) {}
 void runTest() { suite_fwaveSolver_test.testEigenvalueComputation1(); }
} testDescription_suite_fwaveSolver_test_testEigenvalueComputation1;

static class TestDescription_suite_fwaveSolver_test_testEigenvalueComputation2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_fwaveSolver_test_testEigenvalueComputation2() : CxxTest::RealTestDescription( Tests_fwaveSolver_test, suiteDescription_fwaveSolver_test, 27, "testEigenvalueComputation2" ) {}
 void runTest() { suite_fwaveSolver_test.testEigenvalueComputation2(); }
} testDescription_suite_fwaveSolver_test_testEigenvalueComputation2;

static class TestDescription_suite_fwaveSolver_test_testNetUpdateComputation1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_fwaveSolver_test_testNetUpdateComputation1() : CxxTest::RealTestDescription( Tests_fwaveSolver_test, suiteDescription_fwaveSolver_test, 41, "testNetUpdateComputation1" ) {}
 void runTest() { suite_fwaveSolver_test.testNetUpdateComputation1(); }
} testDescription_suite_fwaveSolver_test_testNetUpdateComputation1;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
