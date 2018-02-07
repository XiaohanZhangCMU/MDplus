/*
  lattice.h
  by Wei Cai  caiwei@mit.edu
  Last Modified : Thu Feb 28 11:09:52 2008

  FUNCTION  :
*/

#ifndef _LATTICE_H
#define _LATTICE_H

    const double sc_basis[3]={0,0,0};
    const double bcc_basis[6]={0,0,0, .5,.5,.5};
    const double fcc_basis[12]={0,0,0, .5,.5,0, 0,.5,.5, .5,0,.5};
    const double nacl_basis[24]={ 0,0,0, .5,.5,0, 0,.5,.5, .5,0,.5,
                                 .5,0,0,  0,.5,0, 0,0,.5, .5,.5,.5};
    const double dc_basis[24]={0,0,0, .5,.5,0, 0,.5,.5, .5,0,.5,
             .25,.25,.25, .75,.75,.25, .25,.75,.75, .75,.25,.75};
    const double betatin_basis[12]={0,  0.75,0.125,  0,0.25, 0.875,
                                    0.5,0.25,0.625, 0.5,0.75,0.375};
    const double graphite_basis[24]={0,0,0,   0.5,0.1666666667,0,   0.5,0.5,0,   0,  0.6666666667,0,
                                     0,0,0.5, 0,  0.3333333333,0.5, 0.5,0.5,0.5, 0.5,0.8333333333,0.5};
    const double graphene_basis[12]={0,0,0,   0.5,0.1666666667,0,   0.5,0.5,0,   0,  0.6666666667,0 };
    const double caf2_basis[36]={0,0,0, .5,.5,0, 0,.5,.5, .5,0,.5,
             .25,.25,.25, .75,.75,.25, .25,.75,.75, .75,.25,.75,
             .75,.75,.75, .25,.25,.75, .75,.25,.25, .25,.75,.25 };
//    const double hex_ortho_basis[12]={0,0,0, .5,.5,0, .5,.1830127019,
//                                      .5, 0,.6830127019,.5};
    const double hex_ortho_basis[12]={0,0,0, .5,.5,0, .5,.1666666667,.5, 
				      0,.6666666667,.5};
    const double wurtzite_basis[24]={0,0,0, .5,.5,0, .5,.1666666667,.5, 
				     0,.6666666667,.5, .5,.1666666667,.125, 
				     0,0,.625, .5,.5,.625, 0,.6666666667,
				     .125};
    const double alpha_quartz_basis[54] = {
      0.2349500060,  -0.2349500060,   0.6666666667,  /*Si*/
      0.2349500060,   0.2349500060,   0.3333333333,  /*Si*/
      0.7349500060,   0.2650499940,   0.6666666667,  /*Si*/
      0.7349500060,  -0.2650499940,   0.3333333333,  /*Si*/
      0.0300999880,  -0.5000000000,   0.0000000000,  /*Si*/
      0.5300999880,   0.0000000000,   0.0000000000,  /*Si*/
      0.3410999924,  -0.0729999989,   0.7853999734,  /*O */
      0.3410999924,   0.0729999989,   0.2146000266,  /*O */
      0.8410999924,   0.4270000011,   0.7853999734,  /*O */
      0.2199500054,   0.3659500033,   0.1187333067,  /*O */
      0.4389500022,   0.2929500043,   0.5479333599,  /*O */
      0.4389500022,  -0.2929500043,   0.4520666401,  /*O */
      0.8410999924,  -0.4270000011,   0.2146000266,  /*O */
      0.2199500054,  -0.3659500033,   0.8812666933,  /*O */
      0.9389500022,   0.2070499957,   0.4520666401,  /*O */
      0.7199500054,  -0.1340499967,   0.1187333067,  /*O */
      0.7199500054,   0.1340499967,   0.8812666933,  /*O */
      0.9389500022,  -0.2070499957,   0.5479333599,  /*O */
    };

    const double beta_quartz_basis[54] = {
      0.0000000000,  -0.5000000000,   0.3333333333,  /*Si*/
      0.5000000000,   0.0000000000,   0.3333333333,  /*Si*/
      0.2500000000,  -0.2500000000,   0.0000000000,  /*Si*/
      0.2500000000,   0.2500000000,   0.6666666667,  /*Si*/
      0.7500000000,   0.2500000000,   0.0000000000,  /*Si*/
      0.7500000000,  -0.2500000000,   0.6666666667,  /*Si*/
      0.0000000000,  -0.1969999969,   0.8333333333,  /*O */
      0.0000000000,   0.1969999969,   0.8333333333,  /*O */
      0.2954999954,   0.0984999985,   0.5000000000,  /*O */
      0.2954999954,  -0.0984999985,   0.1666666667,  /*O */
      0.5000000000,   0.3030000031,   0.8333333333,  /*O */
      0.2045000046,   0.4015000015,   0.5000000000,  /*O */
      0.7954999954,   0.4015000015,   0.1666666667,  /*O */
      0.5000000000,  -0.3030000031,   0.8333333333,  /*O */
      0.7954999954,  -0.4015000015,   0.5000000000,  /*O */
      0.2045000046,  -0.4015000015,   0.1666666667,  /*O */
      0.7045000046,  -0.0984999985,   0.5000000000,  /*O */
      0.7045000046,   0.0984999985,   0.1666666667  /*O */
    };

    const double tridymite_basis[72] = {
   0.0000000000,   0.6666666667,   0.0619999990,  /*Si*/
   0.0000000000,   0.3333333333,  -0.0619999990,  /*Si*/
   0.0000000000,   0.3333333333,   0.5619999990,  /*Si*/
   0.0000000000,   0.6666666667,   0.4380000010,  /*Si*/
   0.5000000000,   0.8333333333,  -0.0619999990,  /*Si*/
   0.5000000000,   0.8333333333,   0.5619999990,  /*Si*/
   0.5000000000,   0.1666666667,   0.0619999990,  /*Si*/
   0.5000000000,   0.1666666667,   0.4380000010,  /*Si*/
   0.0000000000,   0.6666666667,   0.2500000000,  /*O */
   0.0000000000,   0.3333333333,   0.7500000000,  /*O */
   0.0000000000,   0.5000000000,   0.0000000000,  /*O */
   0.0000000000,   0.5000000000,   0.5000000000,  /*O */
   0.5000000000,   0.8333333333,   0.7500000000,  /*O */
   0.2500000000,   0.7500000000,   0.0000000000,  /*O */
   0.2500000000,   0.7500000000,   0.5000000000,  /*O */
   0.5000000000,   0.1666666667,   0.2500000000,  /*O */
   0.2500000000,   0.2500000000,   0.0000000000,  /*O */
   0.5000000000,   0.0000000000,   0.0000000000,  /*O */
   0.2500000000,   0.2500000000,   0.5000000000,  /*O */
   0.5000000000,   0.0000000000,   0.5000000000,  /*O */
   0.7500000000,   0.2500000000,   0.0000000000,  /*O */
   0.7500000000,   0.7500000000,   0.0000000000,  /*O */
   0.7500000000,   0.2500000000,   0.5000000000,  /*O */
   0.7500000000,   0.7500000000,   0.5000000000   /*O */
    };

    const double cristobalite_basis[36] = {
      0.3000400066,   0.3000400066,   0.0000000000,  /*Si*/
      0.1999599934,   0.8000400066,   0.2500000000,  /*Si*/
      0.8000400066,   0.1999599934,   0.7500000000,  /*Si*/
      0.6999599934,   0.6999599934,   0.5000000000,  /*Si*/
      0.2397599965,   0.1032399982,   0.1784400046,  /*O */
      0.3967600018,   0.7397599965,   0.4284400046,  /*O */
      0.6032399982,   0.2602400035,   0.9284400046,  /*O */
      0.2602400035,   0.6032399982,   0.0715599954,  /*O */
      0.7397599965,   0.3967600018,   0.5715599954,  /*O */
      0.1032399982,   0.2397599965,   0.8215599954,  /*O */
      0.7602400035,   0.8967600018,   0.6784400046,  /*O */
      0.8967600018,   0.7602400035,   0.3215599954  /*O */
    };

    const double rhsige_basis[72]={0,  0,           0,            .5, .5,          0,               /* A  */
                                   0,  0,           0.125,        .5, .5,          0.125,           /* A' */
                                   0.5,0.1666666667,0.1666666667,  0, .6666666667, 0.1666666667,    /* B  */
                                   0.5,0.1666666667,0.2916666667,  0, .6666666667, 0.2916666667,    /* B' */
                                   0,  0.3333333333,0.3333333333,  .5,.8333333333, 0.3333333333,    /* C  */
                                   0,  0.3333333333,0.4583333333,  .5,.8333333333, 0.4583333333,    /* C' */
                                   0,  0,           0.5,          .5, .5,          0.5,             /* A  */
                                   0,  0,           0.625,        .5, .5,          0.625,           /* A' */
                                   0.5,0.1666666667,0.6666666667,  0, .6666666667, 0.6666666667,    /* B  */
                                   0.5,0.1666666667,0.7916666667,  0, .6666666667, 0.7916666667,    /* B' */
                                   0,  0.3333333333,0.8333333333,  .5,.8333333333, 0.8333333333,    /* C  */
                                   0,  0.3333333333,0.9583333333,  .5,.8333333333, 0.9583333333 };  /* C' */
    const double bc8_basis[48]={0.1,0.1,0.1, -0.1,-0.1,-0.1, 0.1,-0.1,0.4, -0.1, 0.1,-0.4,
                                0.4,0.1,-0.1,-0.4,-0.1, 0.1,-0.1, 0.4,0.1,  0.1,-0.4,-0.1,
                                0.6,0.6,0.6,  0.4, 0.4, 0.4, 0.6, 0.4,0.9,  0.4, 0.6, 0.1,
                                0.9,0.6,0.4,  0.1, 0.4, 0.6, 0.4, 0.9,0.6,  0.6, 0.1, 0.4};
    const double ice_Ih_O_basis[24]={0,0,0, .5,.5,0, .5,.1830127019,.5, 0,.6830127019,.5,
             0,0,.625, .5,.5,.625, .5,.1830127019,.125, 0,.6830127019,.125};
    const double ice_Ih_basis[72]=
      {0,0,0,    .5,.5,0,    .5,.1830127019,.5,   0,.6830127019,.5,  /*O*/
       0,0,.625, .5,.5,.625, .5,.1830127019,.125, 0,.6830127019,.125,/*O*/
       0.25,0.09150635095,0.0625,/* H 0-6 */ 0.75,0.09150635095,0.0625,/* H 0-6 */
       0,   0,            0.8125,/* H 0-4 */ 0,   0.84150635095,0.0625,/* H 0-7 */
       0.25,0.59150635095,0.0625,/* H 1-7 */ 0.75,0.59150635095,0.0625,/* H 1-7 */
       0.50,0.50000000000,0.8125,/* H 1-5 */ 0.50,0.34150635095,0.0625,/* H 1-6 */
       0.25,0.09150635095,0.5625,/* H 2-4 */ 0.75,0.09150635095,0.5625,/* H 2-4 */
       0.50,0.34150635095,0.5625,/* H 2-5 */ 0.50,0.18301270190,0.3125,/* H 2-6 */
       0.25,0.59150635095,0.5625,/* H 3-5 */ 0.75,0.59150635095,0.5625,/* H 3-5 */
       0,   0.84150635095,0.5625,/* H 3-4 */ 0,   0.68301270190,0.3125,/* H 3-7 */ };
    const double A11_basis[24]=
       {0,  0.1549,0.0810, 0,  0.8451,0.9190, 0,  0.6549,0.4190, 0,  0.3451,0.5810,
        0.5,0.6549,0.0810, 0.5,0.3451,0.9190, 0.5,0.1549,0.4190, 0.5,0.8451,0.5810};
    

    const int cscl_species[2]={0,1};
    const int betatin_2_species[4]={0,1,0,1};
    const int zb_species[8]={0,0,0,0,1,1,1,1};
    const int wurtzite_species[8]={0,0,0,0,1,1,1,1};
    const int rhsige_species[24]={0,0,0,0,1,1,1,1,0,0,0,0, 1,1,1,1,0,0,0,0,1,1,1,1};
    const int nacl_species[8]={0,0,0,0,1,1,1,1};
    const int caf2_species[12]={0,0,0,0,1,1,1,1,1,1,1,1};
    const int l12_species[4]={1,0,0,0};
    const int l10_species[4]={1,0,0,1};
    const int alpha_quartz_species[18]={0,0,0,0,0,0,
                                        1,1,1,1,1,1, 1,1,1,1,1,1};
    const int beta_quartz_species[18]={0,0,0,0,0,0,
                                       1,1,1,1,1,1, 1,1,1,1,1,1};
const int tridymite_species[24]={0,0,0,0,0,0,0,0,
				 1,1,1,1,1,1,1,1, 
				 1,1,1,1,1,1,1,1};

    const int cristobalite_species[12]={0,0,0,0,
					1,1,1,1,1,1,1,1};
    const int ice_Ih_species[24]={0,0,0,0,0,0,0,0,
                                  1,1,1,1,1,1,1,1, 1,1,1,1,1,1,1,1};


#endif // _LATTICE_H

