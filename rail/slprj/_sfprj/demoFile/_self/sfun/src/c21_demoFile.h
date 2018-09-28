#ifndef __c21_demoFile_h__
#define __c21_demoFile_h__

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

#ifndef typedef_SFc21_demoFileInstanceStruct
#define typedef_SFc21_demoFileInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c21_sfEvent;
  boolean_T c21_doneDoubleBufferReInit;
  uint8_T c21_is_active_c21_demoFile;
  real_T c21_I[15000];
  real_T c21_y[15000];
  void *c21_fEmlrtCtx;
  uint8_T (*c21_RGB)[15000];
  boolean_T (*c21_BW)[5000];
  real_T (*c21_value)[6];
} SFc21_demoFileInstanceStruct;

#endif                                 /*typedef_SFc21_demoFileInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c21_demoFile_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c21_demoFile_get_check_sum(mxArray *plhs[]);
extern void c21_demoFile_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
