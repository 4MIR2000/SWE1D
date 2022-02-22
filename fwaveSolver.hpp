#include<iostream> 
#include<math.h>
#include <cassert>
using namespace std;

namespace solver {
  template <typename T> class FWave;
}

template <typename T> class solver::FWave{
  public: 
    T hl;
    T hr; 
    T hul; 
    T hur; 
    T bl; 
    T br; 

    /**
     * @brief This enum stores the state of the cells:
     * Dry: both cells are dry
     * Wet: both cells are wet
     * WetDry: left cell is wet and the right one is dry
     * DryWet: right cell is dry and the right one is wet
     */
    enum CellState{
      Dry, 
      Wet, 
      WetDry, 
      DryWet
    }; 

    /**
     * @brief This function examines the current state according to the water heights
     * if the water height is below the tolerance the cell is considered to be dry 
     * 
     * @param state This is the output
     */
    void determineState(CellState &state){
      //tolerance
      double tol= 0.01; 

      if(hl<tol&&hr<tol){ 
        state = Dry; 
      }else if(hr<tol){
        state = WetDry; 
        hr = hl; 
        //wall reflects wave 
        hur = -hul; 
        br = bl; 

      }else if(hl<tol){
        state = DryWet; 
        hl = hr, 
        hul = -hur; 
        bl = br; 
      }else{
        state = Wet; 
      }
    }

    /**
    * @brief This function computes the netupdates (A-deltaQ, A+deltaQ)
    * 
    * @tparam T (type parameter could be double for example)
    * @param i_hl water height of the left cell
    * @param i_hr water height of the right cell
    * @param i_hul momentum of the left cell
    * @param i_hur momentum of the right cell
    * @param i_bl bathymetry of the left cell
    * @param i_br bathymetry of the right cell
    * @param o_hUpdateL output: left-going update of h 
    * @param o_hUpdateR output: right-going update of h
    * @param o_huUpdateL output: left-going update of hu
    * @param o_huUpdateR output: right-going update of hu
    * @param o_maxWaveSpeed output: wavespeed(eigenvalue) with the biggest absolute value
    */
    void computeNetUpdates (const T &i_hl,  const T &i_hr,
                          const T &i_hul, const T &i_hur,
                          const T &i_bl,  const T &i_br,
                          T &o_hUpdateL,
                          T &o_hUpdateR,
                          T &o_huUpdateL,
                          T &o_huUpdateR,
                          T &o_maxWaveSpeed )
    {
      //the second case is the one for the dry cells
      assert(i_hl > 0||(i_hl==0&&i_hul==0&&i_bl>=0));      
      assert(i_hr > 0||(i_hr==0&&i_hur==0&&i_br>=0));

      hl = i_hl; 
      hr = i_hr; 
      hul = i_hul; 
      hur = i_hur; 
      bl = i_bl; 
      br = i_br; 

      o_hUpdateL = 0;
      o_hUpdateR = 0;
      o_huUpdateL = 0;
      o_huUpdateR = 0;

      
      CellState state; 
      //Get the current state
      determineState(state); 
      if(state==Dry){
        //both sides dry => no update
        return;
      }
      
      int t = 0; 

      T ul = hul/hl; 
      T ur = hur/hr; 
      T g = 9.81; 

      T hlSqrt = sqrt(hl);
      T hrSqrt = sqrt(hr);

      T h_roe = 0.5*(hl+hr);
      T u_roe = (ul*hlSqrt+ur*hrSqrt)/(hlSqrt+hrSqrt); 

      T lambda1 = u_roe-sqrt(g*h_roe); 
      T lambda2 = u_roe+sqrt(g*h_roe);

      //determine the wavespeed(eigenvalue) with the biggest absolute value
      o_maxWaveSpeed = std::max(std::abs(lambda1),std::abs(lambda2)); 
      
      //effect of bathymetry 
      T deltaXPsi [2] = {0, -g*(br-bl)*(hl+hr)*0.5} ;

      T fqr[2] = {hur, hr*ur*ur+0.5*g*hr*hr}; 
      T fql[2] = {hul, hl*ul*ul+0.5*g*hl*hl}; 

      //jump in the flux
      T deltaF[2] = {fqr[0]-fql[0],fqr[1]-fql[1]};

      //due bathymetry
      deltaF[1] -= deltaXPsi[1]; 

      T r_inv[2][2];
      T det = (lambda1 - lambda2);
      
      r_inv[0][0] = -lambda2 / det;
      r_inv[0][1] =        1 / det;
      r_inv[1][0] =  lambda1 / det;
      r_inv[1][1] = -      1 / det;

      T alpha[2] = {r_inv[0][0] * deltaF[0] + r_inv[0][1] * deltaF[1],
        r_inv[1][0] * deltaF[0] + r_inv[1][1] * deltaF[1]};


      //compute the actual netupdates (A-deltaQ, A+deltaQ)
      //first iteration(p=1)
      if(lambda1>0){
          o_hUpdateR=alpha[0]; 
          o_huUpdateR=alpha[0]*lambda1; 
      }else{
          o_hUpdateL = alpha[0];
          o_huUpdateL = alpha[0]*lambda1;
      }

      //second iteration (p=2)
      if(lambda2>0){
          //calculates Z2
          o_hUpdateR+=alpha[1]; 
          o_huUpdateR+=alpha[1]*lambda2; 
      }else{
          o_hUpdateL+=alpha[1]; 
          o_huUpdateL+=alpha[1]*lambda2; 
      }

      //Dry wall on the right => no update         
      if(state==WetDry){
        o_hUpdateR = 0; 
        o_huUpdateR = 0; 
      }else if(state==DryWet){
        o_hUpdateL = 0; 
        o_hUpdateR = 0; 
      }

   // std::cout<<"i_hl: "<<i_hl<<", i_hr: "<<i_hr<<", i_hul: "<<i_hul<<", i_hur: "<<i_hur<<", i_bl: "<<i_bl<<", i_br: "<<i_br<<", o_hUpdateL: "<<o_hUpdateL<<", o_hUpdateR: "<<o_hUpdateR<<", o_huUdateL: "<<o_huUpdateL<<", o_huUpdateR: "<<o_huUpdateR<<"\n"; 
    }
};
