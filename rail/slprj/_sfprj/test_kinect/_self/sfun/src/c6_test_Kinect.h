#ifndef __c6_test_Kinect_h__
#define __c6_test_Kinect_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_c6_struct_T
#define typedef_c6_struct_T

typedef struct {
  char_T f1[5];
  char_T f2[6];
  char_T f3[6];
  char_T f4[6];
} c6_struct_T;

#endif                                 /*typedef_c6_struct_T*/

#ifndef typedef_c6_b_struct_T
#define typedef_c6_b_struct_T

typedef struct {
  char_T f1[4];
} c6_b_struct_T;

#endif                                 /*typedef_c6_b_struct_T*/

#ifndef typedef_SFc6_test_KinectInstanceStruct
#define typedef_SFc6_test_KinectInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c6_sfEvent;
  boolean_T c6_doneDoubleBufferReInit;
  uint8_T c6_is_active_c6_test_Kinect;
  real_T c6_I[651264];
  real_T c6_outputImage[651264];
  uint8_T c6_RGB[651264];
  uint8_T c6_X[651264];
  boolean_T c6_sliderBW[217088];
  boolean_T c6_BW[217088];
  boolean_T c6_bv1[217088];
  boolean_T c6_bv2[217088];
  real_T c6_y[651264];
  real_T c6_dv0[651264];
  real_T c6_u[651264];
  uint8_T c6_b_u[651264];
  boolean_T c6_b_y[217088];
  boolean_T c6_bv3[217088];
  boolean_T c6_bv0[217088];
  boolean_T c6_c_u[217088];
  void *c6_fEmlrtCtx;
  uint8_T (*c6_b_RGB)[651264];
  boolean_T (*c6_b_BW)[217088];
  real_T (*c6_value)[6];
} SFc6_test_KinectInstanceStruct;

#endif                                 /*typedef_SFc6_test_KinectInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c6_test_Kinect_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_test_Kinect_get_check_sum(mxArray *plhs[]);
extern void c6_test_Kinect_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
