#ifndef __c6_test_kinect_ver2_h__
#define __c6_test_kinect_ver2_h__

/* Type Definitions */
#ifndef typedef_SFc6_test_kinect_ver2InstanceStruct
#define typedef_SFc6_test_kinect_ver2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c6_sfEvent;
  boolean_T c6_doneDoubleBufferReInit;
  uint8_T c6_is_active_c6_test_kinect_ver2;
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
} SFc6_test_kinect_ver2InstanceStruct;

#endif                                 /*typedef_SFc6_test_kinect_ver2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c6_test_kinect_ver2_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c6_test_kinect_ver2_get_check_sum(mxArray *plhs[]);
extern void c6_test_kinect_ver2_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
