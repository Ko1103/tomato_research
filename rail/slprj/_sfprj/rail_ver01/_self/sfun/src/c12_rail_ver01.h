#ifndef __c12_rail_ver01_h__
#define __c12_rail_ver01_h__

/* Type Definitions */
#ifndef typedef_SFc12_rail_ver01InstanceStruct
#define typedef_SFc12_rail_ver01InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c12_sfEvent;
  boolean_T c12_doneDoubleBufferReInit;
  uint8_T c12_is_active_c12_rail_ver01;
  real_T c12_I[651264];
  real_T c12_outputImage[651264];
  uint8_T c12_RGB[651264];
  uint8_T c12_X[651264];
  boolean_T c12_sliderBW[217088];
  boolean_T c12_BW[217088];
  boolean_T c12_bv1[217088];
  boolean_T c12_bv2[217088];
  real_T c12_y[651264];
  real_T c12_dv0[651264];
  real_T c12_u[651264];
  uint8_T c12_b_u[651264];
  boolean_T c12_b_y[217088];
  boolean_T c12_bv3[217088];
  boolean_T c12_bv0[217088];
  boolean_T c12_c_u[217088];
  void *c12_fEmlrtCtx;
  uint8_T (*c12_b_RGB)[651264];
  boolean_T (*c12_b_BW)[217088];
  real_T (*c12_value)[6];
} SFc12_rail_ver01InstanceStruct;

#endif                                 /*typedef_SFc12_rail_ver01InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c12_rail_ver01_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c12_rail_ver01_get_check_sum(mxArray *plhs[]);
extern void c12_rail_ver01_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
