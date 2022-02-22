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

static class TestDescription_suite_fwaveSolver_test_testNetUpdateComputation1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_fwaveSolver_test_testNetUpdateComputation1() : CxxTest::RealTestDescription( Tests_fwaveSolver_test, suiteDescription_fwaveSolver_test, 39, "testNetUpdateComputation1" ) {}
 void runTest() { suite_fwaveSolver_test.testNetUpdateComputation1(); }
} testDescription_suite_fwaveSolver_test_testNetUpdateComputation1;

static class TestDescription_suite_fwaveSolver_test_testNetUpdateComputation2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_fwaveSolver_test_testNetUpdateComputation2() : CxxTest::RealTestDescription( Tests_fwaveSolver_test, suiteDescription_fwaveSolver_test, 50, "testNetUpdateComputation2" ) {}
 void runTest() { suite_fwaveSolver_test.testNetUpdateComputation2(); }
} testDescription_suite_fwaveSolver_test_testNetUpdateComputation2;

static class TestDescription_suite_fwaveSolver_test_testNetUpdateComputation3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_fwaveSolver_test_testNetUpdateComputation3() : CxxTest::RealTestDescription( Tests_fwaveSolver_test, suiteDescription_fwaveSolver_test, 60, "testNetUpdateComputation3" ) {}
 void runTest() { suite_fwaveSolver_test.testNetUpdateComputation3(); }
} testDescription_suite_fwaveSolver_test_testNetUpdateComputation3;

static class TestDescription_suite_fwaveSolver_test_testNetUpdateComputation4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_fwaveSolver_test_testNetUpdateComputation4() : CxxTest::RealTestDescription( Tests_fwaveSolver_test, suiteDescription_fwaveSolver_test, 70, "testNetUpdateComputation4" ) {}
 void runTest() { suite_fwaveSolver_test.testNetUpdateComputation4(); }
} testDescription_suite_fwaveSolver_test_testNetUpdateComputation4;

static class TestDescription_suite_fwaveSolver_test_testNetUpdateComputation5 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_fwaveSolver_test_testNetUpdateComputation5() : CxxTest::RealTestDescription( Tests_fwaveSolver_test, suiteDescription_fwaveSolver_test, 80, "testNetUpdateComputation5" ) {}
 void runTest() { suite_fwaveSolver_test.testNetUpdateComputation5(); }
} testDescription_suite_fwaveSolver_test_testNetUpdateComputation5;

static class TestDescription_suite_fwaveSolver_test_testNetUpdateComputation6 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_fwaveSolver_test_testNetUpdateComputation6() : CxxTest::RealTestDescription( Tests_fwaveSolver_test, suiteDescription_fwaveSolver_test, 90, "testNetUpdateComputation6" ) {}
 void runTest() { suite_fwaveSolver_test.testNetUpdateComputation6(); }
} testDescription_suite_fwaveSolver_test_testNetUpdateComputation6;

static class TestDescription_suite_fwaveSolver_test_testNetUpdateComputation7 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_fwaveSolver_test_testNetUpdateComputation7() : CxxTest::RealTestDescription( Tests_fwaveSolver_test, suiteDescription_fwaveSolver_test, 100, "testNetUpdateComputation7" ) {}
 void runTest() { suite_fwaveSolver_test.testNetUpdateComputation7(); }
} testDescription_suite_fwaveSolver_test_testNetUpdateComputation7;

static class TestDescription_suite_fwaveSolver_test_testEigenvalueComputation1 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_fwaveSolver_test_testEigenvalueComputation1() : CxxTest::RealTestDescription( Tests_fwaveSolver_test, suiteDescription_fwaveSolver_test, 107, "testEigenvalueComputation1" ) {}
 void runTest() { suite_fwaveSolver_test.testEigenvalueComputation1(); }
} testDescription_suite_fwaveSolver_test_testEigenvalueComputation1;

static class TestDescription_suite_fwaveSolver_test_testEigenvalueComputation2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_fwaveSolver_test_testEigenvalueComputation2() : CxxTest::RealTestDescription( Tests_fwaveSolver_test, suiteDescription_fwaveSolver_test, 123, "testEigenvalueComputation2" ) {}
 void runTest() { suite_fwaveSolver_test.testEigenvalueComputation2(); }
} testDescription_suite_fwaveSolver_test_testEigenvalueComputation2;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
