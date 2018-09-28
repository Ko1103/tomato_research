#ifndef __c12_demoFile_h__
#define __c12_demoFile_h__

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

#ifndef typedef_SFc12_demoFileInstanceStruct
#define typedef_SFc12_demoFileInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c12_sfEvent;
  boolean_T c12_doneDoubleBufferReInit;
  uint8_T c12_is_active_c12_demoFile;
  real_T c12_I[15000];
  real_T c12_y[15000];
  void *c12_fEmlrtCtx;
  uint8_T (*c12_RGB)[15000];
  boolean_T (*c12_BW)[5000];
  real_T (*c12_value)[6];
} SFc12_demoFileInstanceStruct;

#endif                                 /*typedef_SFc12_demoFileInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c12_demoFile_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c12_demoFile_get_check_sum(mxArray *plhs[]);
extern void c12_demoFile_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
