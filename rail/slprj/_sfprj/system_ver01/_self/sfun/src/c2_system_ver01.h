#ifndef __c2_system_ver01_h__
#define __c2_system_ver01_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_c2_struct_T
#define typedef_c2_struct_T

typedef struct {
  char_T f1[5];
  char_T f2[6];
  char_T f3[6];
  char_T f4[6];
} c2_struct_T;

#endif                                 /*typedef_c2_struct_T*/

#ifndef typedef_c2_b_struct_T
#define typedef_c2_b_struct_T

typedef struct {
  char_T f1[4];
} c2_b_struct_T;

#endif                                 /*typedef_c2_b_struct_T*/

#ifndef typedef_SFc2_system_ver01InstanceStruct
#define typedef_SFc2_system_ver01InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_system_ver01;
  real_T c2_I[651264];
  real_T c2_outputImage[651264];
  uint8_T c2_RGB[651264];
  uint8_T c2_X[651264];
  boolean_T c2_sliderBW[217088];
  boolean_T c2_BW[217088];
  boolean_T c2_bv1[217088];
  boolean_T c2_bv2[217088];
  real_T c2_y[651264];
  real_T c2_dv0[651264];
  real_T c2_u[651264];
  uint8_T c2_b_u[651264];
  boolean_T c2_b_y[217088];
  boolean_T c2_bv3[217088];
  boolean_T c2_bv0[217088];
  boolean_T c2_c_u[217088];
  void *c2_fEmlrtCtx;
  uint8_T (*c2_b_RGB)[651264];
  boolean_T (*c2_b_BW)[217088];
  real_T (*c2_value)[6];
} SFc2_system_ver01InstanceStruct;

#endif                                 /*typedef_SFc2_system_ver01InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_system_ver01_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_system_ver01_get_check_sum(mxArray *plhs[]);
extern void c2_system_ver01_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
