/* Include files */

#include "test_kinect_ver2_sfun.h"
#include "c6_test_kinect_ver2.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "test_kinect_ver2_sfun_debug_macros.h"
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
static const char * c6_debug_family_names[13] = { "I", "channel1Min",
  "channel1Max", "channel2Min", "channel2Max", "channel3Min", "channel3Max",
  "sliderBW", "nargin", "nargout", "RGB", "value", "BW" };

/* Function Declarations */
static void initialize_c6_test_kinect_ver2(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance);
static void initialize_params_c6_test_kinect_ver2
  (SFc6_test_kinect_ver2InstanceStruct *chartInstance);
static void enable_c6_test_kinect_ver2(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance);
static void disable_c6_test_kinect_ver2(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance);
static void c6_update_debugger_state_c6_test_kinect_ver2
  (SFc6_test_kinect_ver2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c6_test_kinect_ver2
  (SFc6_test_kinect_ver2InstanceStruct *chartInstance);
static void set_sim_state_c6_test_kinect_ver2
  (SFc6_test_kinect_ver2InstanceStruct *chartInstance, const mxArray *c6_st);
static void finalize_c6_test_kinect_ver2(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance);
static void sf_gateway_c6_test_kinect_ver2(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance);
static void mdl_start_c6_test_kinect_ver2(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance);
static void c6_chartstep_c6_test_kinect_ver2(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance);
static void initSimStructsc6_test_kinect_ver2
  (SFc6_test_kinect_ver2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static void c6_emlrt_marshallIn(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c6_c_BW, const char_T *c6_identifier, boolean_T
  c6_c_y[217088]);
static void c6_b_emlrt_marshallIn(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c6_d_u, const emlrtMsgIdentifier *c6_parentId,
  boolean_T c6_c_y[217088]);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static real_T c6_c_emlrt_marshallIn(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c6_d_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static void c6_d_emlrt_marshallIn(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c6_d_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_c_y[651264]);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_f_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_e_emlrt_marshallIn(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c6_d_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static uint8_T c6_f_emlrt_marshallIn(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_test_kinect_ver2, const
  char_T *c6_identifier);
static uint8_T c6_g_emlrt_marshallIn(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c6_d_u, const emlrtMsgIdentifier *c6_parentId);
static void init_dsm_address_info(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c6_test_kinect_ver2(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc6_test_kinect_ver2(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c6_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_is_active_c6_test_kinect_ver2 = 0U;
}

static void initialize_params_c6_test_kinect_ver2
  (SFc6_test_kinect_ver2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c6_test_kinect_ver2(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c6_test_kinect_ver2(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c6_update_debugger_state_c6_test_kinect_ver2
  (SFc6_test_kinect_ver2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c6_test_kinect_ver2
  (SFc6_test_kinect_ver2InstanceStruct *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_c_y = NULL;
  const mxArray *c6_d_y = NULL;
  uint8_T c6_hoistedGlobal;
  const mxArray *c6_e_y = NULL;
  c6_st = NULL;
  c6_st = NULL;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_createcellmatrix(2, 1), false);
  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_create("y", *chartInstance->c6_b_BW, 11, 0U, 1U,
    0U, 2, 424, 512), false);
  sf_mex_setcell(c6_c_y, 0, c6_d_y);
  c6_hoistedGlobal = chartInstance->c6_is_active_c6_test_kinect_ver2;
  c6_e_y = NULL;
  sf_mex_assign(&c6_e_y, sf_mex_create("y", &c6_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c6_c_y, 1, c6_e_y);
  sf_mex_assign(&c6_st, c6_c_y, false);
  return c6_st;
}

static void set_sim_state_c6_test_kinect_ver2
  (SFc6_test_kinect_ver2InstanceStruct *chartInstance, const mxArray *c6_st)
{
  const mxArray *c6_d_u;
  int32_T c6_i0;
  chartInstance->c6_doneDoubleBufferReInit = true;
  c6_d_u = sf_mex_dup(c6_st);
  c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell("BW", c6_d_u, 0)),
                      "BW", chartInstance->c6_bv0);
  for (c6_i0 = 0; c6_i0 < 217088; c6_i0++) {
    (*chartInstance->c6_b_BW)[c6_i0] = chartInstance->c6_bv0[c6_i0];
  }

  chartInstance->c6_is_active_c6_test_kinect_ver2 = c6_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("is_active_c6_test_kinect_ver2",
       c6_d_u, 1)), "is_active_c6_test_kinect_ver2");
  sf_mex_destroy(&c6_d_u);
  c6_update_debugger_state_c6_test_kinect_ver2(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void finalize_c6_test_kinect_ver2(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c6_test_kinect_ver2(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance)
{
  int32_T c6_i1;
  int32_T c6_i2;
  int32_T c6_i3;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  for (c6_i1 = 0; c6_i1 < 6; c6_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c6_value)[c6_i1], 1U, 1U, 0U,
                          chartInstance->c6_sfEvent, false);
  }

  for (c6_i2 = 0; c6_i2 < 651264; c6_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c6_b_RGB)[c6_i2], 0U, 1U, 0U,
                          chartInstance->c6_sfEvent, false);
  }

  chartInstance->c6_sfEvent = CALL_EVENT;
  c6_chartstep_c6_test_kinect_ver2(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_test_kinect_ver2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c6_i3 = 0; c6_i3 < 217088; c6_i3++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c6_b_BW)[c6_i3], 2U, 1U, 0U,
                          chartInstance->c6_sfEvent, false);
  }
}

static void mdl_start_c6_test_kinect_ver2(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c6_chartstep_c6_test_kinect_ver2(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance)
{
  int32_T c6_i4;
  int32_T c6_i5;
  uint32_T c6_debug_family_var_map[13];
  real_T c6_b_value[6];
  real_T c6_channel1Min;
  real_T c6_channel1Max;
  real_T c6_channel2Min;
  real_T c6_channel2Max;
  real_T c6_channel3Min;
  real_T c6_channel3Max;
  real_T c6_nargin = 2.0;
  real_T c6_nargout = 1.0;
  int32_T c6_i6;
  int32_T c6_i7;
  int32_T c6_i8;
  int32_T c6_i9;
  int32_T c6_i10;
  int32_T c6_i11;
  int32_T c6_i12;
  int32_T c6_i13;
  int32_T c6_i14;
  int32_T c6_i15;
  int32_T c6_i16;
  int32_T c6_i17;
  int32_T c6_i18;
  int32_T c6_i19;
  int32_T c6_i20;
  int32_T c6_i21;
  int32_T c6_i22;
  int32_T c6_i23;
  int32_T c6_i24;
  int32_T c6_i25;
  int32_T c6_i26;
  int32_T c6_i27;
  int32_T c6_i28;
  int32_T c6_i29;
  int32_T c6_i30;
  int32_T c6_i31;
  int32_T c6_i32;
  int32_T c6_i33;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  for (c6_i4 = 0; c6_i4 < 651264; c6_i4++) {
    chartInstance->c6_RGB[c6_i4] = (*chartInstance->c6_b_RGB)[c6_i4];
  }

  for (c6_i5 = 0; c6_i5 < 6; c6_i5++) {
    c6_b_value[c6_i5] = (*chartInstance->c6_value)[c6_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c6_debug_family_names,
    c6_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c6_I, 0U,
    c6_e_sf_marshallOut, c6_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_channel1Min, 1U, c6_d_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_channel1Max, 2U, c6_d_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_channel2Min, 3U, c6_d_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_channel2Max, 4U, c6_d_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_channel3Min, 5U, c6_d_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_channel3Max, 6U, c6_d_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c6_sliderBW, 7U,
    c6_sf_marshallOut, c6_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 8U, c6_d_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 9U, c6_d_sf_marshallOut,
    c6_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c6_RGB, 10U, c6_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c6_b_value, 11U, c6_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c6_BW, 12U,
    c6_sf_marshallOut, c6_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 14);
  for (c6_i6 = 0; c6_i6 < 651264; c6_i6++) {
    chartInstance->c6_X[c6_i6] = chartInstance->c6_RGB[c6_i6];
  }

  for (c6_i7 = 0; c6_i7 < 651264; c6_i7++) {
    chartInstance->c6_outputImage[c6_i7] = chartInstance->c6_I[c6_i7];
  }

  for (c6_i8 = 0; c6_i8 < 651264; c6_i8++) {
    chartInstance->c6_I[c6_i8] = chartInstance->c6_outputImage[c6_i8];
  }

  rgb2hsv_tbb_uint8(chartInstance->c6_X, 217088.0, chartInstance->c6_I);
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 17);
  c6_channel1Min = c6_b_value[0];
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 18);
  c6_channel1Max = c6_b_value[1];
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 20);
  c6_channel2Min = c6_b_value[2];
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 21);
  c6_channel2Max = c6_b_value[3];
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 23);
  c6_channel3Min = c6_b_value[4];
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 24);
  c6_channel3Max = c6_b_value[5];
  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 27);
  c6_i9 = 0;
  for (c6_i10 = 0; c6_i10 < 512; c6_i10++) {
    for (c6_i12 = 0; c6_i12 < 424; c6_i12++) {
      chartInstance->c6_bv1[c6_i12 + c6_i9] = (chartInstance->c6_I[c6_i12 +
        c6_i9] >= c6_channel1Min);
    }

    c6_i9 += 424;
  }

  c6_i11 = 0;
  for (c6_i13 = 0; c6_i13 < 512; c6_i13++) {
    for (c6_i15 = 0; c6_i15 < 424; c6_i15++) {
      chartInstance->c6_bv2[c6_i15 + c6_i11] = (chartInstance->c6_I[c6_i15 +
        c6_i11] <= c6_channel1Max);
    }

    c6_i11 += 424;
  }

  for (c6_i14 = 0; c6_i14 < 217088; c6_i14++) {
    chartInstance->c6_bv1[c6_i14] = (chartInstance->c6_bv1[c6_i14] ||
      chartInstance->c6_bv2[c6_i14]);
  }

  c6_i16 = 0;
  for (c6_i17 = 0; c6_i17 < 512; c6_i17++) {
    for (c6_i19 = 0; c6_i19 < 424; c6_i19++) {
      chartInstance->c6_bv2[c6_i19 + c6_i16] = (chartInstance->c6_I[(c6_i19 +
        c6_i16) + 217088] >= c6_channel2Min);
    }

    c6_i16 += 424;
  }

  for (c6_i18 = 0; c6_i18 < 217088; c6_i18++) {
    chartInstance->c6_bv1[c6_i18] = (chartInstance->c6_bv1[c6_i18] &&
      chartInstance->c6_bv2[c6_i18]);
  }

  c6_i20 = 0;
  for (c6_i21 = 0; c6_i21 < 512; c6_i21++) {
    for (c6_i23 = 0; c6_i23 < 424; c6_i23++) {
      chartInstance->c6_bv2[c6_i23 + c6_i20] = (chartInstance->c6_I[(c6_i23 +
        c6_i20) + 217088] <= c6_channel2Max);
    }

    c6_i20 += 424;
  }

  for (c6_i22 = 0; c6_i22 < 217088; c6_i22++) {
    chartInstance->c6_bv1[c6_i22] = (chartInstance->c6_bv1[c6_i22] &&
      chartInstance->c6_bv2[c6_i22]);
  }

  c6_i24 = 0;
  for (c6_i25 = 0; c6_i25 < 512; c6_i25++) {
    for (c6_i27 = 0; c6_i27 < 424; c6_i27++) {
      chartInstance->c6_bv2[c6_i27 + c6_i24] = (chartInstance->c6_I[(c6_i27 +
        c6_i24) + 434176] >= c6_channel3Min);
    }

    c6_i24 += 424;
  }

  for (c6_i26 = 0; c6_i26 < 217088; c6_i26++) {
    chartInstance->c6_bv1[c6_i26] = (chartInstance->c6_bv1[c6_i26] &&
      chartInstance->c6_bv2[c6_i26]);
  }

  c6_i28 = 0;
  for (c6_i29 = 0; c6_i29 < 512; c6_i29++) {
    for (c6_i31 = 0; c6_i31 < 424; c6_i31++) {
      chartInstance->c6_bv2[c6_i31 + c6_i28] = (chartInstance->c6_I[(c6_i31 +
        c6_i28) + 434176] <= c6_channel3Max);
    }

    c6_i28 += 424;
  }

  for (c6_i30 = 0; c6_i30 < 217088; c6_i30++) {
    chartInstance->c6_sliderBW[c6_i30] = (chartInstance->c6_bv1[c6_i30] &&
      chartInstance->c6_bv2[c6_i30]);
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, 31);
  for (c6_i32 = 0; c6_i32 < 217088; c6_i32++) {
    chartInstance->c6_BW[c6_i32] = chartInstance->c6_sliderBW[c6_i32];
  }

  _SFD_EML_CALL(0U, chartInstance->c6_sfEvent, -31);
  _SFD_SYMBOL_SCOPE_POP();
  for (c6_i33 = 0; c6_i33 < 217088; c6_i33++) {
    (*chartInstance->c6_b_BW)[c6_i33] = chartInstance->c6_BW[c6_i33];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
}

static void initSimStructsc6_test_kinect_ver2
  (SFc6_test_kinect_ver2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber)
{
  (void)(c6_machineNumber);
  (void)(c6_chartNumber);
  (void)(c6_instanceNumber);
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData;
  int32_T c6_i34;
  int32_T c6_i35;
  const mxArray *c6_c_y = NULL;
  int32_T c6_i36;
  SFc6_test_kinect_ver2InstanceStruct *chartInstance;
  chartInstance = (SFc6_test_kinect_ver2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_mxArrayOutData = NULL;
  c6_i34 = 0;
  for (c6_i35 = 0; c6_i35 < 512; c6_i35++) {
    for (c6_i36 = 0; c6_i36 < 424; c6_i36++) {
      chartInstance->c6_c_u[c6_i36 + c6_i34] = (*(boolean_T (*)[217088])
        c6_inData)[c6_i36 + c6_i34];
    }

    c6_i34 += 424;
  }

  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", chartInstance->c6_c_u, 11, 0U, 1U,
    0U, 2, 424, 512), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_c_y, false);
  return c6_mxArrayOutData;
}

static void c6_emlrt_marshallIn(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c6_c_BW, const char_T *c6_identifier, boolean_T
  c6_c_y[217088])
{
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = (const char *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_c_BW), &c6_thisId, c6_c_y);
  sf_mex_destroy(&c6_c_BW);
}

static void c6_b_emlrt_marshallIn(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c6_d_u, const emlrtMsgIdentifier *c6_parentId,
  boolean_T c6_c_y[217088])
{
  int32_T c6_i37;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_d_u), chartInstance->c6_bv3, 1, 11,
                0U, 1, 0U, 2, 424, 512);
  for (c6_i37 = 0; c6_i37 < 217088; c6_i37++) {
    c6_c_y[c6_i37] = chartInstance->c6_bv3[c6_i37];
  }

  sf_mex_destroy(&c6_d_u);
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_c_BW;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_i38;
  int32_T c6_i39;
  int32_T c6_i40;
  SFc6_test_kinect_ver2InstanceStruct *chartInstance;
  chartInstance = (SFc6_test_kinect_ver2InstanceStruct *)chartInstanceVoid;
  c6_c_BW = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = (const char *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_c_BW), &c6_thisId,
                        chartInstance->c6_b_y);
  sf_mex_destroy(&c6_c_BW);
  c6_i38 = 0;
  for (c6_i39 = 0; c6_i39 < 512; c6_i39++) {
    for (c6_i40 = 0; c6_i40 < 424; c6_i40++) {
      (*(boolean_T (*)[217088])c6_outData)[c6_i40 + c6_i38] =
        chartInstance->c6_b_y[c6_i40 + c6_i38];
    }

    c6_i38 += 424;
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData;
  int32_T c6_i41;
  const mxArray *c6_c_y = NULL;
  real_T c6_d_u[6];
  SFc6_test_kinect_ver2InstanceStruct *chartInstance;
  chartInstance = (SFc6_test_kinect_ver2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_mxArrayOutData = NULL;
  for (c6_i41 = 0; c6_i41 < 6; c6_i41++) {
    c6_d_u[c6_i41] = (*(real_T (*)[6])c6_inData)[c6_i41];
  }

  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", c6_d_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_c_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData;
  int32_T c6_i42;
  int32_T c6_i43;
  const mxArray *c6_c_y = NULL;
  int32_T c6_i44;
  int32_T c6_i45;
  int32_T c6_i46;
  SFc6_test_kinect_ver2InstanceStruct *chartInstance;
  chartInstance = (SFc6_test_kinect_ver2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_mxArrayOutData = NULL;
  c6_i42 = 0;
  for (c6_i43 = 0; c6_i43 < 3; c6_i43++) {
    c6_i44 = 0;
    for (c6_i45 = 0; c6_i45 < 512; c6_i45++) {
      for (c6_i46 = 0; c6_i46 < 424; c6_i46++) {
        chartInstance->c6_b_u[(c6_i46 + c6_i44) + c6_i42] = (*(uint8_T (*)
          [651264])c6_inData)[(c6_i46 + c6_i44) + c6_i42];
      }

      c6_i44 += 424;
    }

    c6_i42 += 217088;
  }

  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", chartInstance->c6_b_u, 3, 0U, 1U, 0U,
    3, 424, 512, 3), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_c_y, false);
  return c6_mxArrayOutData;
}

static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData;
  real_T c6_d_u;
  const mxArray *c6_c_y = NULL;
  SFc6_test_kinect_ver2InstanceStruct *chartInstance;
  chartInstance = (SFc6_test_kinect_ver2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_mxArrayOutData = NULL;
  c6_d_u = *(real_T *)c6_inData;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_c_y, false);
  return c6_mxArrayOutData;
}

static real_T c6_c_emlrt_marshallIn(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c6_d_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_c_y;
  real_T c6_d0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_d_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_c_y = c6_d0;
  sf_mex_destroy(&c6_d_u);
  return c6_c_y;
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_nargout;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_c_y;
  SFc6_test_kinect_ver2InstanceStruct *chartInstance;
  chartInstance = (SFc6_test_kinect_ver2InstanceStruct *)chartInstanceVoid;
  c6_nargout = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = (const char *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_c_y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nargout),
    &c6_thisId);
  sf_mex_destroy(&c6_nargout);
  *(real_T *)c6_outData = c6_c_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData;
  int32_T c6_i47;
  int32_T c6_i48;
  const mxArray *c6_c_y = NULL;
  int32_T c6_i49;
  int32_T c6_i50;
  int32_T c6_i51;
  SFc6_test_kinect_ver2InstanceStruct *chartInstance;
  chartInstance = (SFc6_test_kinect_ver2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_mxArrayOutData = NULL;
  c6_i47 = 0;
  for (c6_i48 = 0; c6_i48 < 3; c6_i48++) {
    c6_i49 = 0;
    for (c6_i50 = 0; c6_i50 < 512; c6_i50++) {
      for (c6_i51 = 0; c6_i51 < 424; c6_i51++) {
        chartInstance->c6_u[(c6_i51 + c6_i49) + c6_i47] = (*(real_T (*)[651264])
          c6_inData)[(c6_i51 + c6_i49) + c6_i47];
      }

      c6_i49 += 424;
    }

    c6_i47 += 217088;
  }

  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", chartInstance->c6_u, 0, 0U, 1U, 0U,
    3, 424, 512, 3), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_c_y, false);
  return c6_mxArrayOutData;
}

static void c6_d_emlrt_marshallIn(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c6_d_u, const emlrtMsgIdentifier *c6_parentId,
  real_T c6_c_y[651264])
{
  int32_T c6_i52;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_d_u), chartInstance->c6_dv0, 1, 0, 0U,
                1, 0U, 3, 424, 512, 3);
  for (c6_i52 = 0; c6_i52 < 651264; c6_i52++) {
    c6_c_y[c6_i52] = chartInstance->c6_dv0[c6_i52];
  }

  sf_mex_destroy(&c6_d_u);
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_I;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_i53;
  int32_T c6_i54;
  int32_T c6_i55;
  int32_T c6_i56;
  int32_T c6_i57;
  SFc6_test_kinect_ver2InstanceStruct *chartInstance;
  chartInstance = (SFc6_test_kinect_ver2InstanceStruct *)chartInstanceVoid;
  c6_b_I = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = (const char *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_I), &c6_thisId,
                        chartInstance->c6_y);
  sf_mex_destroy(&c6_b_I);
  c6_i53 = 0;
  for (c6_i54 = 0; c6_i54 < 3; c6_i54++) {
    c6_i55 = 0;
    for (c6_i56 = 0; c6_i56 < 512; c6_i56++) {
      for (c6_i57 = 0; c6_i57 < 424; c6_i57++) {
        (*(real_T (*)[651264])c6_outData)[(c6_i57 + c6_i55) + c6_i53] =
          chartInstance->c6_y[(c6_i57 + c6_i55) + c6_i53];
      }

      c6_i55 += 424;
    }

    c6_i53 += 217088;
  }

  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_test_kinect_ver2_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  sf_mex_assign(&c6_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c6_nameCaptureInfo;
}

static const mxArray *c6_f_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData;
  int32_T c6_d_u;
  const mxArray *c6_c_y = NULL;
  SFc6_test_kinect_ver2InstanceStruct *chartInstance;
  chartInstance = (SFc6_test_kinect_ver2InstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_mxArrayOutData = NULL;
  c6_d_u = *(int32_T *)c6_inData;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_c_y, false);
  return c6_mxArrayOutData;
}

static int32_T c6_e_emlrt_marshallIn(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c6_d_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_c_y;
  int32_T c6_i58;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_d_u), &c6_i58, 1, 6, 0U, 0, 0U, 0);
  c6_c_y = c6_i58;
  sf_mex_destroy(&c6_d_u);
  return c6_c_y;
}

static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_c_y;
  SFc6_test_kinect_ver2InstanceStruct *chartInstance;
  chartInstance = (SFc6_test_kinect_ver2InstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = (const char *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_c_y = c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_c_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static uint8_T c6_f_emlrt_marshallIn(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c6_b_is_active_c6_test_kinect_ver2, const
  char_T *c6_identifier)
{
  uint8_T c6_c_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = (const char *)c6_identifier;
  c6_thisId.fParent = NULL;
  c6_thisId.bParentIsCell = false;
  c6_c_y = c6_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_is_active_c6_test_kinect_ver2), &c6_thisId);
  sf_mex_destroy(&c6_b_is_active_c6_test_kinect_ver2);
  return c6_c_y;
}

static uint8_T c6_g_emlrt_marshallIn(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c6_d_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_c_y;
  uint8_T c6_u0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_d_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_c_y = c6_u0;
  sf_mex_destroy(&c6_d_u);
  return c6_c_y;
}

static void init_dsm_address_info(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc6_test_kinect_ver2InstanceStruct
  *chartInstance)
{
  chartInstance->c6_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c6_b_RGB = (uint8_T (*)[651264])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c6_b_BW = (boolean_T (*)[217088])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c6_value = (real_T (*)[6])ssGetInputPortSignal_wrapper
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

void sf_c6_test_kinect_ver2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1052723909U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3038172582U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2642574109U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1593238241U);
}

mxArray* sf_c6_test_kinect_ver2_get_post_codegen_info(void);
mxArray *sf_c6_test_kinect_ver2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("mgbKAOI1yjDlSzaNj23R4E");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,3,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(424);
      pr[1] = (double)(512);
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
      pr[0] = (double)(424);
      pr[1] = (double)(512);
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
    mxArray* mxPostCodegenInfo = sf_c6_test_kinect_ver2_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c6_test_kinect_ver2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Rgb2hsvBuildable"));
  return(mxcell3p);
}

mxArray *sf_c6_test_kinect_ver2_jit_fallback_info(void)
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

mxArray *sf_c6_test_kinect_ver2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c6_test_kinect_ver2_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c6_test_kinect_ver2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"BW\",},{M[8],M[0],T\"is_active_c6_test_kinect_ver2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_test_kinect_ver2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_test_kinect_ver2InstanceStruct *chartInstance =
      (SFc6_test_kinect_ver2InstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _test_kinect_ver2MachineNumber_,
           6,
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
        init_script_number_translation(_test_kinect_ver2MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_test_kinect_ver2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _test_kinect_ver2MachineNumber_,
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
          dimVector[0]= 424U;
          dimVector[1]= 512U;
          dimVector[2]= 3U;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 424U;
          dimVector[1]= 512U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)
            c6_sf_marshallIn);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _test_kinect_ver2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_test_kinect_ver2InstanceStruct *chartInstance =
      (SFc6_test_kinect_ver2InstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c6_b_RGB);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c6_b_BW);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c6_value);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "siLz3JX9P5KIKMeypi6Rs6C";
}

static void sf_opaque_initialize_c6_test_kinect_ver2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_test_kinect_ver2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c6_test_kinect_ver2((SFc6_test_kinect_ver2InstanceStruct*)
    chartInstanceVar);
  initialize_c6_test_kinect_ver2((SFc6_test_kinect_ver2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c6_test_kinect_ver2(void *chartInstanceVar)
{
  enable_c6_test_kinect_ver2((SFc6_test_kinect_ver2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c6_test_kinect_ver2(void *chartInstanceVar)
{
  disable_c6_test_kinect_ver2((SFc6_test_kinect_ver2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c6_test_kinect_ver2(void *chartInstanceVar)
{
  sf_gateway_c6_test_kinect_ver2((SFc6_test_kinect_ver2InstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c6_test_kinect_ver2(SimStruct* S)
{
  return get_sim_state_c6_test_kinect_ver2((SFc6_test_kinect_ver2InstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c6_test_kinect_ver2(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c6_test_kinect_ver2((SFc6_test_kinect_ver2InstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c6_test_kinect_ver2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_test_kinect_ver2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_test_kinect_ver2_optimization_info();
    }

    finalize_c6_test_kinect_ver2((SFc6_test_kinect_ver2InstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_test_kinect_ver2((SFc6_test_kinect_ver2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_test_kinect_ver2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c6_test_kinect_ver2((SFc6_test_kinect_ver2InstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c6_test_kinect_ver2(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_test_kinect_ver2_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,6,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 6);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,6);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1574867197U));
  ssSetChecksum1(S,(1775517334U));
  ssSetChecksum2(S,(222696371U));
  ssSetChecksum3(S,(1995773790U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_test_kinect_ver2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c6_test_kinect_ver2(SimStruct *S)
{
  SFc6_test_kinect_ver2InstanceStruct *chartInstance;
  chartInstance = (SFc6_test_kinect_ver2InstanceStruct *)utMalloc(sizeof
    (SFc6_test_kinect_ver2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc6_test_kinect_ver2InstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c6_test_kinect_ver2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c6_test_kinect_ver2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c6_test_kinect_ver2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_test_kinect_ver2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_test_kinect_ver2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c6_test_kinect_ver2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c6_test_kinect_ver2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c6_test_kinect_ver2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_test_kinect_ver2;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_test_kinect_ver2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c6_test_kinect_ver2;
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
  mdl_start_c6_test_kinect_ver2(chartInstance);
}

void c6_test_kinect_ver2_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_test_kinect_ver2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_test_kinect_ver2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_test_kinect_ver2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_test_kinect_ver2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
