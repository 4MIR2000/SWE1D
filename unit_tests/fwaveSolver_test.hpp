#ifndef FWAVESOLVER_TEST_H
#define FWAVESOLVER_TEST_H

#include <cxxtest/TestSuite.h>
#include "../fwaveSolver.hpp"
using namespace solver;


class fwaveSolver_test : public CxxTest::TestSuite
{
    public :
        double tolerance = 0.01;
        void checkNetUpdates(double i_hl,  double i_hr,
                             double i_hul, double i_hur,
                             double i_bl,  double i_br,
                             double o_hUpdateL_exp, double o_hUpdateR_exp, 
                             double o_huUpdateL_exp, double o_huUpdateR_exp){

            FWave<double> solver = FWave<double>();
            double o_hUpdateL; 
            double o_hUpdateR; 
            double o_huUpdateL;
            double o_huUpdateR;
            double o_maxwavespeed; 
            solver.computeNetUpdates(i_hl, i_hr, i_hul, i_hur, i_bl, i_br, 
                    o_hUpdateL, o_hUpdateR, o_huUpdateL, o_huUpdateR, o_maxwavespeed); 
            
            TS_ASSERT(std::abs(o_hUpdateL_exp-o_hUpdateL) <= tolerance);
            TS_ASSERT(std::abs(o_hUpdateR_exp-o_hUpdateR) <= tolerance);
            TS_ASSERT(std::abs(o_huUpdateL_exp-o_huUpdateL) <= tolerance);
            TS_ASSERT(std::abs(o_huUpdateR_exp-o_huUpdateR) <= tolerance);

        }  

        /**
         * @brief standard test without bathymetry 
         * 
         */
        void testNetUpdateComputation1(void){
            FWave<double> solver = FWave<double>();
            checkNetUpdates(15,15,30,30,0,0,
                            0,0,0,0);
             
        }

        /**
         * @brief test at discontinuity of shock-shock without bathymetry 
         * 
         */
        void testNetUpdateComputation2(void){
            FWave<double> solver = FWave<double>();
            checkNetUpdates(15,15,30,-30,0,0,
                            -30,-30,363.91,-363.91);
        }

        /**
         * @brief test at discontinuity of rare-rare without bathymetry 
         * 
         */
        void testNetUpdateComputation3(void){
            FWave<double> solver = FWave<double>();
            checkNetUpdates(15,15,-30,30,0,0,
                            30,30,-363.91,363.91);
        }

        /**
         * @brief standard test for wet-wet state with bathymetry 
         * 
         */
        void testNetUpdateComputation4(void){
            FWave<double> solver = FWave<double>();
            checkNetUpdates(15,15,30,30,-15,-15,
                            -0,-0,0,0);
        }

        /**
         * @brief test at discontinuity of rare-rare with bathymetry 
         * 
         */
        void testNetUpdateComputation5(void){
            FWave<double> solver = FWave<double>();
            checkNetUpdates(15,15,-30,30,-15,-15,
                            30,30,-363.91,363.91);
        }

        /**
         * @brief test for wet-dry state with bathymetry 
         * 
         */
        void testNetUpdateComputation6(void){
            FWave<double> solver = FWave<double>();
            checkNetUpdates(15,15,30,-30,-15,0,
                        -120.979,60.97,1467.54,739.70);
        }

        /**
         * @brief test for dry-dry state with bathymetry 
         * 
         */
        void testNetUpdateComputation7(void){
            FWave<double> solver = FWave<double>();
            checkNetUpdates(0,0,0,0,0,0,
                        0,0,0,0);
        }


        void testEigenvalueComputation1(void) 
        {       
            FWave<double> solver = FWave<double>();
            double hl = 3;
            double hr = 1;
            double ul = 0;
            double ur = 1;
            double result1 = -4.06;
            double result2 = 4.79;
            double output1;
            double output2; 
            /*solver.computeEigenvalues(hl, hr, ul, ur, output1, output2);
            TS_ASSERT(std::abs(result1 - output1) <= tolerance);
            TS_ASSERT(std::abs(result2 - output2) <= tolerance);*/
        }

        void testEigenvalueComputation2(void) 
        {
            FWave<double> solver = FWave<double>();
            double hl = 1;
            double hr = 1;
            double ul = -0.5;
            double ur = 0.5;
            double result1 = -3.13;
            double result2 = 3.13;
            double output1;
            double output2;
            /*solver.computeEigenvalues(hl, hr, ul, ur, output1, output2);
            TS_ASSERT(std::abs(result1 - output1) <= tolerance);
            TS_ASSERT(std::abs(result2 - output2) <= tolerance);*/
        }
};

#endif //FWAVESOLVER_TEST_H