#ifndef __c21_rail_ver01_0311_Nomotor_h__
#define __c21_rail_ver01_0311_Nomotor_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_c21_struct_T
#define typedef_c21_struct_T

typedef struct {
  char_T f1[5];
  char_T f2[6];
  char_T f3[6];
  char_T f4[6];
} c21_struct_T;

#endif                                 /*typedef_c21_struct_T*/

#ifndef typedef_c21_b_struct_T
#define typedef_c21_b_struct_T

typedef struct {
  char_T f1[4];
} c21_b_struct_T;

#endif                                 /*typedef_c21_b_struct_T*/

#ifndef typedef_SFc21_rail_ver01_0311_NomotorInstanceStruct
#define typedef_SFc21_rail_ver01_0311_NomotorInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c21_sfEvent;
  boolean_T c21_doneDoubleBufferReInit;
  uint8_T c21_is_active_c21_rail_ver01_0311_Nomotor;
  real_T c21_I[651264];
  real_T c21_outputImage[651264];
  uint8_T c21_RGB[651264];
  uint8_T c21_X[651264];
  boolean_T c21_sliderBW[217088];
  boolean_T c21_BW[217088];
  boolean_T c21_bv1[217088];
  boolean_T c21_bv2[217088];
  real_T c21_y[651264];
  real_T c21_dv0[651264];
  real_T c21_u[651264];
  uint8_T c21_b_u[651264];
  boolean_T c21_b_y[217088];
  boolean_T c21_bv3[217088];
  boolean_T c21_bv0[217088];
  boolean_T c21_c_u[217088];
  void *c21_fEmlrtCtx;
  uint8_T (*c21_b_RGB)[651264];
  boolean_T (*c21_b_BW)[217088];
  real_T (*c21_value)[6];
} SFc21_rail_ver01_0311_NomotorInstanceStruct;

#endif                                 /*typedef_SFc21_rail_ver01_0311_NomotorInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c21_rail_ver01_0311_Nomotor_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c21_rail_ver01_0311_Nomotor_get_check_sum(mxArray *plhs[]);
extern void c21_rail_ver01_0311_Nomotor_method_dispatcher(SimStruct *S, int_T
  method, void *data);

#endif
