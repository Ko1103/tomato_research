#ifndef __c12_system_ver03_h__
#define __c12_system_ver03_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_c12_struct_T
#define typedef_c12_struct_T

typedef struct {
  char_T f1[5];
  char_T f2[6];
  char_T f3[6];
  char_T f4[6];
} c12_struct_T;

#endif                                 /*typedef_c12_struct_T*/

#ifndef typedef_c12_b_struct_T
#define typedef_c12_b_struct_T

typedef struct {
  char_T f1[4];
} c12_b_struct_T;

#endif                                 /*typedef_c12_b_struct_T*/

#ifndef typedef_SFc12_system_ver03InstanceStruct
#define typedef_SFc12_system_ver03InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c12_sfEvent;
  boolean_T c12_doneDoubleBufferReInit;
  uint8_T c12_is_active_c12_system_ver03;
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
} SFc12_system_ver03InstanceStruct;

#endif                                 /*typedef_SFc12_system_ver03InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c12_system_ver03_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c12_system_ver03_get_check_sum(mxArray *plhs[]);
extern void c12_system_ver03_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
