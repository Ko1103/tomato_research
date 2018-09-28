/* Include files */

#include "demoFile_sfun.h"
#include "c21_demoFile.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "demoFile_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c21_debug_family_names[13] = { "I", "channel1Min",
  "channel1Max", "channel2Min", "channel2Max", "channel3Min", "channel3Max",
  "sliderBW", "nargin", "nargout", "RGB", "value", "BW" };

/* Function Declarations */
static void initialize_c21_demoFile(SFc21_demoFileInstanceStruct *chartInstance);
static void initialize_params_c21_demoFile(SFc21_demoFileInstanceStruct
  *chartInstance);
static void enable_c21_demoFile(SFc21_demoFileInstanceStruct *chartInstance);
static void disable_c21_demoFile(SFc21_demoFileInstanceStruct *chartInstance);
static void c21_update_debugger_state_c21_demoFile(SFc21_demoFileInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c21_demoFile(SFc21_demoFileInstanceStruct
  *chartInstance);
static void set_sim_state_c21_demoFile(SFc21_demoFileInstanceStruct
  *chartInstance, const mxArray *c21_st);
static void finalize_c21_demoFile(SFc21_demoFileInstanceStruct *chartInstance);
static void sf_gateway_c21_demoFile(SFc21_demoFileInstanceStruct *chartInstance);
static void mdl_start_c21_demoFile(SFc21_demoFileInstanceStruct *chartInstance);
static void c21_chartstep_c21_demoFile(SFc21_demoFileInstanceStruct
  *chartInstance);
static void initSimStructsc21_demoFile(SFc21_demoFileInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c21_machineNumber, uint32_T
  c21_chartNumber, uint32_T c21_instanceNumber);
static const mxArray *c21_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static void c21_emlrt_marshallIn(SFc21_demoFileInstanceStruct *chartInstance,
  const mxArray *c21_b_BW, const char_T *c21_identifier, boolean_T c21_b_y[5000]);
static void c21_b_emlrt_marshallIn(SFc21_demoFileInstanceStruct *chartInstance,
  const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId, boolean_T
  c21_b_y[5000]);
static void c21_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static const mxArray *c21_b_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static const mxArray *c21_c_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static const mxArray *c21_d_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static real_T c21_c_emlrt_marshallIn(SFc21_demoFileInstanceStruct *chartInstance,
  const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void c21_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static const mxArray *c21_e_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static void c21_d_emlrt_marshallIn(SFc21_demoFileInstanceStruct *chartInstance,
  const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId, real_T c21_b_y
  [15000]);
static void c21_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static const mxArray *c21_f_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static int32_T c21_e_emlrt_marshallIn(SFc21_demoFileInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void c21_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static uint8_T c21_f_emlrt_marshallIn(SFc21_demoFileInstanceStruct
  *chartInstance, const mxArray *c21_b_is_active_c21_demoFile, const char_T
  *c21_identifier);
static uint8_T c21_g_emlrt_marshallIn(SFc21_demoFileInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void init_dsm_address_info(SFc21_demoFileInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc21_demoFileInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c21_demoFile(SFc21_demoFileInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc21_demoFile(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c21_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c21_is_active_c21_demoFile = 0U;
}

static void initialize_params_c21_demoFile(SFc21_demoFileInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c21_demoFile(SFc21_demoFileInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c21_demoFile(SFc21_demoFileInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c21_update_debugger_state_c21_demoFile(SFc21_demoFileInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c21_demoFile(SFc21_demoFileInstanceStruct
  *chartInstance)
{
  const mxArray *c21_st;
  const mxArray *c21_b_y = NULL;
  const mxArray *c21_c_y = NULL;
  uint8_T c21_hoistedGlobal;
  const mxArray *c21_d_y = NULL;
  c21_st = NULL;
  c21_st = NULL;
  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_createcellmatrix(2, 1), false);
  c21_c_y = NULL;
  sf_mex_assign(&c21_c_y, sf_mex_create("y", *chartInstance->c21_BW, 11, 0U, 1U,
    0U, 2, 250, 20), false);
  sf_mex_setcell(c21_b_y, 0, c21_c_y);
  c21_hoistedGlobal = chartInstance->c21_is_active_c21_demoFile;
  c21_d_y = NULL;
  sf_mex_assign(&c21_d_y, sf_mex_create("y", &c21_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c21_b_y, 1, c21_d_y);
  sf_mex_assign(&c21_st, c21_b_y, false);
  return c21_st;
}

static void set_sim_state_c21_demoFile(SFc21_demoFileInstanceStruct
  *chartInstance, const mxArray *c21_st)
{
  const mxArray *c21_u;
  boolean_T c21_bv0[5000];
  int32_T c21_i0;
  chartInstance->c21_doneDoubleBufferReInit = true;
  c21_u = sf_mex_dup(c21_st);
  c21_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("BW", c21_u, 0)),
                       "BW", c21_bv0);
  for (c21_i0 = 0; c21_i0 < 5000; c21_i0++) {
    (*chartInstance->c21_BW)[c21_i0] = c21_bv0[c21_i0];
  }

  chartInstance->c21_is_active_c21_demoFile = c21_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c21_demoFile", c21_u, 1)),
     "is_active_c21_demoFile");
  sf_mex_destroy(&c21_u);
  c21_update_debugger_state_c21_demoFile(chartInstance);
  sf_mex_destroy(&c21_st);
}

static void finalize_c21_demoFile(SFc21_demoFileInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c21_demoFile(SFc21_demoFileInstanceStruct *chartInstance)
{
  int32_T c21_i1;
  int32_T c21_i2;
  int32_T c21_i3;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 18U, chartInstance->c21_sfEvent);
  for (c21_i1 = 0; c21_i1 < 6; c21_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c21_value)[c21_i1], 1U, 1U, 0U,
                          chartInstance->c21_sfEvent, false);
  }

  for (c21_i2 = 0; c21_i2 < 15000; c21_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c21_RGB)[c21_i2], 0U, 1U, 0U,
                          chartInstance->c21_sfEvent, false);
  }

  chartInstance->c21_sfEvent = CALL_EVENT;
  c21_chartstep_c21_demoFile(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_demoFileMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c21_i3 = 0; c21_i3 < 5000; c21_i3++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c21_BW)[c21_i3], 2U, 1U, 0U,
                          chartInstance->c21_sfEvent, false);
  }
}

static void mdl_start_c21_demoFile(SFc21_demoFileInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c21_chartstep_c21_demoFile(SFc21_demoFileInstanceStruct
  *chartInstance)
{
  int32_T c21_i4;
  int32_T c21_i5;
  uint8_T c21_b_RGB[15000];
  uint32_T c21_debug_family_var_map[13];
  real_T c21_b_value[6];
  real_T c21_channel1Min;
  real_T c21_channel1Max;
  real_T c21_channel2Min;
  real_T c21_channel2Max;
  real_T c21_channel3Min;
  real_T c21_channel3Max;
  boolean_T c21_sliderBW[5000];
  real_T c21_nargin = 2.0;
  real_T c21_nargout = 1.0;
  boolean_T c21_b_BW[5000];
  int32_T c21_i6;
  int32_T c21_i7;
  uint8_T c21_X[15000];
  int32_T c21_i8;
  real_T c21_outputImage[15000];
  int32_T c21_i9;
  int32_T c21_i10;
  int32_T c21_i11;
  int32_T c21_i12;
  int32_T c21_i13;
  boolean_T c21_bv1[5000];
  int32_T c21_i14;
  int32_T c21_i15;
  int32_T c21_i16;
  boolean_T c21_bv2[5000];
  int32_T c21_i17;
  int32_T c21_i18;
  int32_T c21_i19;
  int32_T c21_i20;
  int32_T c21_i21;
  int32_T c21_i22;
  int32_T c21_i23;
  int32_T c21_i24;
  int32_T c21_i25;
  int32_T c21_i26;
  int32_T c21_i27;
  int32_T c21_i28;
  int32_T c21_i29;
  int32_T c21_i30;
  int32_T c21_i31;
  int32_T c21_i32;
  int32_T c21_i33;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 18U, chartInstance->c21_sfEvent);
  for (c21_i4 = 0; c21_i4 < 15000; c21_i4++) {
    c21_b_RGB[c21_i4] = (*chartInstance->c21_RGB)[c21_i4];
  }

  for (c21_i5 = 0; c21_i5 < 6; c21_i5++) {
    c21_b_value[c21_i5] = (*chartInstance->c21_value)[c21_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c21_debug_family_names,
    c21_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c21_I, 0U,
    c21_e_sf_marshallOut, c21_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_channel1Min, 1U,
    c21_d_sf_marshallOut, c21_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_channel1Max, 2U,
    c21_d_sf_marshallOut, c21_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_channel2Min, 3U,
    c21_d_sf_marshallOut, c21_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_channel2Max, 4U,
    c21_d_sf_marshallOut, c21_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_channel3Min, 5U,
    c21_d_sf_marshallOut, c21_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_channel3Max, 6U,
    c21_d_sf_marshallOut, c21_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c21_sliderBW, 7U, c21_sf_marshallOut,
    c21_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_nargin, 8U, c21_d_sf_marshallOut,
    c21_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_nargout, 9U, c21_d_sf_marshallOut,
    c21_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c21_b_RGB, 10U, c21_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c21_b_value, 11U, c21_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c21_b_BW, 12U, c21_sf_marshallOut,
    c21_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 14);
  for (c21_i6 = 0; c21_i6 < 15000; c21_i6++) {
    c21_X[c21_i6] = c21_b_RGB[c21_i6];
  }

  for (c21_i7 = 0; c21_i7 < 15000; c21_i7++) {
    c21_outputImage[c21_i7] = chartInstance->c21_I[c21_i7];
  }

  for (c21_i8 = 0; c21_i8 < 15000; c21_i8++) {
    chartInstance->c21_I[c21_i8] = c21_outputImage[c21_i8];
  }

  rgb2hsv_tbb_uint8(c21_X, 5000.0, chartInstance->c21_I);
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 17);
  c21_channel1Min = c21_b_value[0];
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 18);
  c21_channel1Max = c21_b_value[1];
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 20);
  c21_channel2Min = c21_b_value[2];
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 21);
  c21_channel2Max = c21_b_value[3];
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 23);
  c21_channel3Min = c21_b_value[4];
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 24);
  c21_channel3Max = c21_b_value[5];
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 27);
  c21_i9 = 0;
  for (c21_i10 = 0; c21_i10 < 20; c21_i10++) {
    for (c21_i12 = 0; c21_i12 < 250; c21_i12++) {
      c21_bv1[c21_i12 + c21_i9] = (chartInstance->c21_I[c21_i12 + c21_i9] >=
        c21_channel1Min);
    }

    c21_i9 += 250;
  }

  c21_i11 = 0;
  for (c21_i13 = 0; c21_i13 < 20; c21_i13++) {
    for (c21_i15 = 0; c21_i15 < 250; c21_i15++) {
      c21_bv2[c21_i15 + c21_i11] = (chartInstance->c21_I[c21_i15 + c21_i11] <=
        c21_channel1Max);
    }

    c21_i11 += 250;
  }

  for (c21_i14 = 0; c21_i14 < 5000; c21_i14++) {
    c21_bv1[c21_i14] = (c21_bv1[c21_i14] || c21_bv2[c21_i14]);
  }

  c21_i16 = 0;
  for (c21_i17 = 0; c21_i17 < 20; c21_i17++) {
    for (c21_i19 = 0; c21_i19 < 250; c21_i19++) {
      c21_bv2[c21_i19 + c21_i16] = (chartInstance->c21_I[(c21_i19 + c21_i16) +
        5000] >= c21_channel2Min);
    }

    c21_i16 += 250;
  }

  for (c21_i18 = 0; c21_i18 < 5000; c21_i18++) {
    c21_bv1[c21_i18] = (c21_bv1[c21_i18] && c21_bv2[c21_i18]);
  }

  c21_i20 = 0;
  for (c21_i21 = 0; c21_i21 < 20; c21_i21++) {
    for (c21_i23 = 0; c21_i23 < 250; c21_i23++) {
      c21_bv2[c21_i23 + c21_i20] = (chartInstance->c21_I[(c21_i23 + c21_i20) +
        5000] <= c21_channel2Max);
    }

    c21_i20 += 250;
  }

  for (c21_i22 = 0; c21_i22 < 5000; c21_i22++) {
    c21_bv1[c21_i22] = (c21_bv1[c21_i22] && c21_bv2[c21_i22]);
  }

  c21_i24 = 0;
  for (c21_i25 = 0; c21_i25 < 20; c21_i25++) {
    for (c21_i27 = 0; c21_i27 < 250; c21_i27++) {
      c21_bv2[c21_i27 + c21_i24] = (chartInstance->c21_I[(c21_i27 + c21_i24) +
        10000] >= c21_channel3Min);
    }

    c21_i24 += 250;
  }

  for (c21_i26 = 0; c21_i26 < 5000; c21_i26++) {
    c21_bv1[c21_i26] = (c21_bv1[c21_i26] && c21_bv2[c21_i26]);
  }

  c21_i28 = 0;
  for (c21_i29 = 0; c21_i29 < 20; c21_i29++) {
    for (c21_i31 = 0; c21_i31 < 250; c21_i31++) {
      c21_bv2[c21_i31 + c21_i28] = (chartInstance->c21_I[(c21_i31 + c21_i28) +
        10000] <= c21_channel3Max);
    }

    c21_i28 += 250;
  }

  for (c21_i30 = 0; c21_i30 < 5000; c21_i30++) {
    c21_sliderBW[c21_i30] = (c21_bv1[c21_i30] && c21_bv2[c21_i30]);
  }

  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 31);
  for (c21_i32 = 0; c21_i32 < 5000; c21_i32++) {
    c21_b_BW[c21_i32] = c21_sliderBW[c21_i32];
  }

  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, -31);
  _SFD_SYMBOL_SCOPE_POP();
  for (c21_i33 = 0; c21_i33 < 5000; c21_i33++) {
    (*chartInstance->c21_BW)[c21_i33] = c21_b_BW[c21_i33];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c21_sfEvent);
}

static void initSimStructsc21_demoFile(SFc21_demoFileInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c21_machineNumber, uint32_T
  c21_chartNumber, uint32_T c21_instanceNumber)
{
  (void)(c21_machineNumber);
  (void)(c21_chartNumber);
  (void)(c21_instanceNumber);
}

static const mxArray *c21_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData;
  int32_T c21_i34;
  int32_T c21_i35;
  const mxArray *c21_b_y = NULL;
  int32_T c21_i36;
  boolean_T c21_u[5000];
  SFc21_demoFileInstanceStruct *chartInstance;
  chartInstance = (SFc21_demoFileInstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_mxArrayOutData = NULL;
  c21_i34 = 0;
  for (c21_i35 = 0; c21_i35 < 20; c21_i35++) {
    for (c21_i36 = 0; c21_i36 < 250; c21_i36++) {
      c21_u[c21_i36 + c21_i34] = (*(boolean_T (*)[5000])c21_inData)[c21_i36 +
        c21_i34];
    }

    c21_i34 += 250;
  }

  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", c21_u, 11, 0U, 1U, 0U, 2, 250, 20),
                false);
  sf_mex_assign(&c21_mxArrayOutData, c21_b_y, false);
  return c21_mxArrayOutData;
}

static void c21_emlrt_marshallIn(SFc21_demoFileInstanceStruct *chartInstance,
  const mxArray *c21_b_BW, const char_T *c21_identifier, boolean_T c21_b_y[5000])
{
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = (const char *)c21_identifier;
  c21_thisId.fParent = NULL;
  c21_thisId.bParentIsCell = false;
  c21_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_BW), &c21_thisId,
    c21_b_y);
  sf_mex_destroy(&c21_b_BW);
}

static void c21_b_emlrt_marshallIn(SFc21_demoFileInstanceStruct *chartInstance,
  const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId, boolean_T
  c21_b_y[5000])
{
  boolean_T c21_bv3[5000];
  int32_T c21_i37;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), c21_bv3, 1, 11, 0U, 1, 0U, 2,
                250, 20);
  for (c21_i37 = 0; c21_i37 < 5000; c21_i37++) {
    c21_b_y[c21_i37] = c21_bv3[c21_i37];
  }

  sf_mex_destroy(&c21_u);
}

static void c21_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_b_BW;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  boolean_T c21_b_y[5000];
  int32_T c21_i38;
  int32_T c21_i39;
  int32_T c21_i40;
  SFc21_demoFileInstanceStruct *chartInstance;
  chartInstance = (SFc21_demoFileInstanceStruct *)chartInstanceVoid;
  c21_b_BW = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = (const char *)c21_identifier;
  c21_thisId.fParent = NULL;
  c21_thisId.bParentIsCell = false;
  c21_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_BW), &c21_thisId,
    c21_b_y);
  sf_mex_destroy(&c21_b_BW);
  c21_i38 = 0;
  for (c21_i39 = 0; c21_i39 < 20; c21_i39++) {
    for (c21_i40 = 0; c21_i40 < 250; c21_i40++) {
      (*(boolean_T (*)[5000])c21_outData)[c21_i40 + c21_i38] = c21_b_y[c21_i40 +
        c21_i38];
    }

    c21_i38 += 250;
  }

  sf_mex_destroy(&c21_mxArrayInData);
}

static const mxArray *c21_b_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData;
  int32_T c21_i41;
  const mxArray *c21_b_y = NULL;
  real_T c21_u[6];
  SFc21_demoFileInstanceStruct *chartInstance;
  chartInstance = (SFc21_demoFileInstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_mxArrayOutData = NULL;
  for (c21_i41 = 0; c21_i41 < 6; c21_i41++) {
    c21_u[c21_i41] = (*(real_T (*)[6])c21_inData)[c21_i41];
  }

  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", c21_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c21_mxArrayOutData, c21_b_y, false);
  return c21_mxArrayOutData;
}

static const mxArray *c21_c_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData;
  int32_T c21_i42;
  int32_T c21_i43;
  const mxArray *c21_b_y = NULL;
  int32_T c21_i44;
  uint8_T c21_u[15000];
  int32_T c21_i45;
  int32_T c21_i46;
  SFc21_demoFileInstanceStruct *chartInstance;
  chartInstance = (SFc21_demoFileInstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_mxArrayOutData = NULL;
  c21_i42 = 0;
  for (c21_i43 = 0; c21_i43 < 3; c21_i43++) {
    c21_i44 = 0;
    for (c21_i45 = 0; c21_i45 < 20; c21_i45++) {
      for (c21_i46 = 0; c21_i46 < 250; c21_i46++) {
        c21_u[(c21_i46 + c21_i44) + c21_i42] = (*(uint8_T (*)[15000])c21_inData)
          [(c21_i46 + c21_i44) + c21_i42];
      }

      c21_i44 += 250;
    }

    c21_i42 += 5000;
  }

  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", c21_u, 3, 0U, 1U, 0U, 3, 250, 20, 3),
                false);
  sf_mex_assign(&c21_mxArrayOutData, c21_b_y, false);
  return c21_mxArrayOutData;
}

static const mxArray *c21_d_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData;
  real_T c21_u;
  const mxArray *c21_b_y = NULL;
  SFc21_demoFileInstanceStruct *chartInstance;
  chartInstance = (SFc21_demoFileInstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_mxArrayOutData = NULL;
  c21_u = *(real_T *)c21_inData;
  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", &c21_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c21_mxArrayOutData, c21_b_y, false);
  return c21_mxArrayOutData;
}

static real_T c21_c_emlrt_marshallIn(SFc21_demoFileInstanceStruct *chartInstance,
  const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  real_T c21_b_y;
  real_T c21_d0;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_d0, 1, 0, 0U, 0, 0U, 0);
  c21_b_y = c21_d0;
  sf_mex_destroy(&c21_u);
  return c21_b_y;
}

static void c21_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_nargout;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  real_T c21_b_y;
  SFc21_demoFileInstanceStruct *chartInstance;
  chartInstance = (SFc21_demoFileInstanceStruct *)chartInstanceVoid;
  c21_nargout = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = (const char *)c21_identifier;
  c21_thisId.fParent = NULL;
  c21_thisId.bParentIsCell = false;
  c21_b_y = c21_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_nargout),
    &c21_thisId);
  sf_mex_destroy(&c21_nargout);
  *(real_T *)c21_outData = c21_b_y;
  sf_mex_destroy(&c21_mxArrayInData);
}

static const mxArray *c21_e_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData;
  int32_T c21_i47;
  int32_T c21_i48;
  const mxArray *c21_b_y = NULL;
  int32_T c21_i49;
  real_T c21_u[15000];
  int32_T c21_i50;
  int32_T c21_i51;
  SFc21_demoFileInstanceStruct *chartInstance;
  chartInstance = (SFc21_demoFileInstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_mxArrayOutData = NULL;
  c21_i47 = 0;
  for (c21_i48 = 0; c21_i48 < 3; c21_i48++) {
    c21_i49 = 0;
    for (c21_i50 = 0; c21_i50 < 20; c21_i50++) {
      for (c21_i51 = 0; c21_i51 < 250; c21_i51++) {
        c21_u[(c21_i51 + c21_i49) + c21_i47] = (*(real_T (*)[15000])c21_inData)
          [(c21_i51 + c21_i49) + c21_i47];
      }

      c21_i49 += 250;
    }

    c21_i47 += 5000;
  }

  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", c21_u, 0, 0U, 1U, 0U, 3, 250, 20, 3),
                false);
  sf_mex_assign(&c21_mxArrayOutData, c21_b_y, false);
  return c21_mxArrayOutData;
}

static void c21_d_emlrt_marshallIn(SFc21_demoFileInstanceStruct *chartInstance,
  const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId, real_T c21_b_y
  [15000])
{
  real_T c21_dv0[15000];
  int32_T c21_i52;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), c21_dv0, 1, 0, 0U, 1, 0U, 3,
                250, 20, 3);
  for (c21_i52 = 0; c21_i52 < 15000; c21_i52++) {
    c21_b_y[c21_i52] = c21_dv0[c21_i52];
  }

  sf_mex_destroy(&c21_u);
}

static void c21_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_b_I;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  int32_T c21_i53;
  int32_T c21_i54;
  int32_T c21_i55;
  int32_T c21_i56;
  int32_T c21_i57;
  SFc21_demoFileInstanceStruct *chartInstance;
  chartInstance = (SFc21_demoFileInstanceStruct *)chartInstanceVoid;
  c21_b_I = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = (const char *)c21_identifier;
  c21_thisId.fParent = NULL;
  c21_thisId.bParentIsCell = false;
  c21_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_I), &c21_thisId,
    chartInstance->c21_y);
  sf_mex_destroy(&c21_b_I);
  c21_i53 = 0;
  for (c21_i54 = 0; c21_i54 < 3; c21_i54++) {
    c21_i55 = 0;
    for (c21_i56 = 0; c21_i56 < 20; c21_i56++) {
      for (c21_i57 = 0; c21_i57 < 250; c21_i57++) {
        (*(real_T (*)[15000])c21_outData)[(c21_i57 + c21_i55) + c21_i53] =
          chartInstance->c21_y[(c21_i57 + c21_i55) + c21_i53];
      }

      c21_i55 += 250;
    }

    c21_i53 += 5000;
  }

  sf_mex_destroy(&c21_mxArrayInData);
}

const mxArray *sf_c21_demoFile_get_eml_resolved_functions_info(void)
{
  const mxArray *c21_nameCaptureInfo = NULL;
  c21_nameCaptureInfo = NULL;
  sf_mex_assign(&c21_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c21_nameCaptureInfo;
}

static const mxArray *c21_f_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData;
  int32_T c21_u;
  const mxArray *c21_b_y = NULL;
  SFc21_demoFileInstanceStruct *chartInstance;
  chartInstance = (SFc21_demoFileInstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_mxArrayOutData = NULL;
  c21_u = *(int32_T *)c21_inData;
  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", &c21_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c21_mxArrayOutData, c21_b_y, false);
  return c21_mxArrayOutData;
}

static int32_T c21_e_emlrt_marshallIn(SFc21_demoFileInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  int32_T c21_b_y;
  int32_T c21_i58;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_i58, 1, 6, 0U, 0, 0U, 0);
  c21_b_y = c21_i58;
  sf_mex_destroy(&c21_u);
  return c21_b_y;
}

static void c21_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_b_sfEvent;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  int32_T c21_b_y;
  SFc21_demoFileInstanceStruct *chartInstance;
  chartInstance = (SFc21_demoFileInstanceStruct *)chartInstanceVoid;
  c21_b_sfEvent = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = (const char *)c21_identifier;
  c21_thisId.fParent = NULL;
  c21_thisId.bParentIsCell = false;
  c21_b_y = c21_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_sfEvent),
    &c21_thisId);
  sf_mex_destroy(&c21_b_sfEvent);
  *(int32_T *)c21_outData = c21_b_y;
  sf_mex_destroy(&c21_mxArrayInData);
}

static uint8_T c21_f_emlrt_marshallIn(SFc21_demoFileInstanceStruct
  *chartInstance, const mxArray *c21_b_is_active_c21_demoFile, const char_T
  *c21_identifier)
{
  uint8_T c21_b_y;
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = (const char *)c21_identifier;
  c21_thisId.fParent = NULL;
  c21_thisId.bParentIsCell = false;
  c21_b_y = c21_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c21_b_is_active_c21_demoFile), &c21_thisId);
  sf_mex_destroy(&c21_b_is_active_c21_demoFile);
  return c21_b_y;
}

static uint8_T c21_g_emlrt_marshallIn(SFc21_demoFileInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  uint8_T c21_b_y;
  uint8_T c21_u0;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_u0, 1, 3, 0U, 0, 0U, 0);
  c21_b_y = c21_u0;
  sf_mex_destroy(&c21_u);
  return c21_b_y;
}

static void init_dsm_address_info(SFc21_demoFileInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc21_demoFileInstanceStruct *chartInstance)
{
  chartInstance->c21_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c21_RGB = (uint8_T (*)[15000])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c21_BW = (boolean_T (*)[5000])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c21_value = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c21_demoFile_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1044958558U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3610457874U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1611701702U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3652002924U);
}

mxArray* sf_c21_demoFile_get_post_codegen_info(void);
mxArray *sf_c21_demoFile_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("AO8WzO2TgIGFxJtjWHtoEH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,3,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(250);
      pr[1] = (double)(20);
      pr[2] = (double)(3);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(3));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,1,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(250);
      pr[1] = (double)(20);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c21_demoFile_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c21_demoFile_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Rgb2hsvBuildable"));
  return(mxcell3p);
}

mxArray *sf_c21_demoFile_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("late");
  mxArray *fallbackReason = mxCreateString("ir_function_calls");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("rgb2hsv_tbb_uint8");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c21_demoFile_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c21_demoFile_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c21_demoFile(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"BW\",},{M[8],M[0],T\"is_active_c21_demoFile\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c21_demoFile_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc21_demoFileInstanceStruct *chartInstance = (SFc21_demoFileInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _demoFileMachineNumber_,
           21,
           1,
           1,
           0,
           3,
           0,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_demoFileMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_demoFileMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _demoFileMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"RGB");
          _SFD_SET_DATA_PROPS(1,1,1,0,"value");
          _SFD_SET_DATA_PROPS(2,2,0,1,"BW");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1089);

        {
          unsigned int dimVector[3];
          dimVector[0]= 250U;
          dimVector[1]= 20U;
          dimVector[2]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 250U;
          dimVector[1]= 20U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_sf_marshallOut,(MexInFcnForType)
            c21_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _demoFileMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc21_demoFileInstanceStruct *chartInstance = (SFc21_demoFileInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c21_RGB);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c21_BW);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c21_value);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "sAhfW52MwrYXrcz6svOd8x";
}

static void sf_opaque_initialize_c21_demoFile(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc21_demoFileInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c21_demoFile((SFc21_demoFileInstanceStruct*)
    chartInstanceVar);
  initialize_c21_demoFile((SFc21_demoFileInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c21_demoFile(void *chartInstanceVar)
{
  enable_c21_demoFile((SFc21_demoFileInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c21_demoFile(void *chartInstanceVar)
{
  disable_c21_demoFile((SFc21_demoFileInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c21_demoFile(void *chartInstanceVar)
{
  sf_gateway_c21_demoFile((SFc21_demoFileInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c21_demoFile(SimStruct* S)
{
  return get_sim_state_c21_demoFile((SFc21_demoFileInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c21_demoFile(SimStruct* S, const mxArray *st)
{
  set_sim_state_c21_demoFile((SFc21_demoFileInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c21_demoFile(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc21_demoFileInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_demoFile_optimization_info();
    }

    finalize_c21_demoFile((SFc21_demoFileInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc21_demoFile((SFc21_demoFileInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c21_demoFile(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c21_demoFile((SFc21_demoFileInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c21_demoFile(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_demoFile_optimization_info(sim_mode_is_rtw_gen(S),
      sim_mode_is_modelref_sim(S), sim_mode_is_external(S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      21);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,21,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 21);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,21);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,21,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,21,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,21);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(436518542U));
  ssSetChecksum1(S,(3399970036U));
  ssSetChecksum2(S,(4048847627U));
  ssSetChecksum3(S,(1064748865U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c21_demoFile(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c21_demoFile(SimStruct *S)
{
  SFc21_demoFileInstanceStruct *chartInstance;
  chartInstance = (SFc21_demoFileInstanceStruct *)utMalloc(sizeof
    (SFc21_demoFileInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc21_demoFileInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c21_demoFile;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c21_demoFile;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c21_demoFile;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c21_demoFile;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c21_demoFile;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c21_demoFile;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c21_demoFile;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c21_demoFile;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c21_demoFile;
  chartInstance->chartInfo.mdlStart = mdlStart_c21_demoFile;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c21_demoFile;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c21_demoFile(chartInstance);
}

void c21_demoFile_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c21_demoFile(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c21_demoFile(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c21_demoFile(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c21_demoFile_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
