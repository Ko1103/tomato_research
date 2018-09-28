/* Include files */

#include "test_kinect_ver2_sfun.h"
#include "c2_test_kinect_ver2.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "test_kinect_ver2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(S);

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
static const char * c2_debug_family_names[13] = { "I", "channel1Min",
  "channel1Max", "channel2Min", "channel2Max", "channel3Min", "channel3Max",
  "sliderBW", "nargin", "nargout", "RGB", "value", "BW" };

/* Function Declarations */
static void initialize_c2_test_kinect_ver2(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance);
static void initialize_params_c2_test_kinect_ver2
  (SFc2_test_kinect_ver2InstanceStruct *chartInstance);
static void enable_c2_test_kinect_ver2(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance);
static void disable_c2_test_kinect_ver2(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_test_kinect_ver2
  (SFc2_test_kinect_ver2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_test_kinect_ver2
  (SFc2_test_kinect_ver2InstanceStruct *chartInstance);
static void set_sim_state_c2_test_kinect_ver2
  (SFc2_test_kinect_ver2InstanceStruct *chartInstance, const mxArray *c2_st);
static void finalize_c2_test_kinect_ver2(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance);
static void sf_gateway_c2_test_kinect_ver2(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance);
static void mdl_start_c2_test_kinect_ver2(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance);
static void c2_chartstep_c2_test_kinect_ver2(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance);
static void initSimStructsc2_test_kinect_ver2
  (SFc2_test_kinect_ver2InstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c2_d_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_c_y[651264]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static real_T c2_b_emlrt_marshallIn(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c2_d_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c2_b_sliderBW, const char_T *c2_identifier,
  boolean_T c2_c_y[217088]);
static void c2_d_emlrt_marshallIn(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c2_d_u, const emlrtMsgIdentifier *c2_parentId,
  boolean_T c2_c_y[217088]);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_e_emlrt_marshallIn(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c2_d_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_f_emlrt_marshallIn(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_test_kinect_ver2, const
  char_T *c2_identifier);
static uint8_T c2_g_emlrt_marshallIn(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c2_d_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_test_kinect_ver2(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc2_test_kinect_ver2(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_test_kinect_ver2 = 0U;
}

static void initialize_params_c2_test_kinect_ver2
  (SFc2_test_kinect_ver2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c2_test_kinect_ver2(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_test_kinect_ver2(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_test_kinect_ver2
  (SFc2_test_kinect_ver2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_test_kinect_ver2
  (SFc2_test_kinect_ver2InstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_c_y = NULL;
  const mxArray *c2_d_y = NULL;
  uint8_T c2_hoistedGlobal;
  const mxArray *c2_e_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_createcellmatrix(2, 1), false);
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", *chartInstance->c2_b_BW, 11, 0U, 1U,
    0U, 2, 424, 512), false);
  sf_mex_setcell(c2_c_y, 0, c2_d_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_test_kinect_ver2;
  c2_e_y = NULL;
  sf_mex_assign(&c2_e_y, sf_mex_create("y", &c2_hoistedGlobal, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c2_c_y, 1, c2_e_y);
  sf_mex_assign(&c2_st, c2_c_y, false);
  return c2_st;
}

static void set_sim_state_c2_test_kinect_ver2
  (SFc2_test_kinect_ver2InstanceStruct *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_d_u;
  int32_T c2_i0;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_d_u = sf_mex_dup(c2_st);
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_d_u, 0)),
                        "BW", chartInstance->c2_bv0);
  for (c2_i0 = 0; c2_i0 < 217088; c2_i0++) {
    (*chartInstance->c2_b_BW)[c2_i0] = chartInstance->c2_bv0[c2_i0];
  }

  chartInstance->c2_is_active_c2_test_kinect_ver2 = c2_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_d_u, 1)),
     "is_active_c2_test_kinect_ver2");
  sf_mex_destroy(&c2_d_u);
  c2_update_debugger_state_c2_test_kinect_ver2(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_test_kinect_ver2(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_test_kinect_ver2(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance)
{
  int32_T c2_i1;
  int32_T c2_i2;
  int32_T c2_i3;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i1 = 0; c2_i1 < 6; c2_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_value)[c2_i1], 1U);
  }

  for (c2_i2 = 0; c2_i2 < 651264; c2_i2++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_b_RGB)[c2_i2], 0U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_test_kinect_ver2(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i3 = 0; c2_i3 < 217088; c2_i3++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c2_b_BW)[c2_i3], 2U);
  }
}

static void mdl_start_c2_test_kinect_ver2(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance)
{
  sim_mode_is_external(chartInstance->S);
}

static void c2_chartstep_c2_test_kinect_ver2(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance)
{
  int32_T c2_i4;
  int32_T c2_i5;
  uint32_T c2_debug_family_var_map[13];
  real_T c2_b_value[6];
  real_T c2_channel1Min;
  real_T c2_channel1Max;
  real_T c2_channel2Min;
  real_T c2_channel2Max;
  real_T c2_channel3Min;
  real_T c2_channel3Max;
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  int32_T c2_i15;
  int32_T c2_i16;
  int32_T c2_i17;
  int32_T c2_i18;
  int32_T c2_i19;
  int32_T c2_i20;
  int32_T c2_i21;
  int32_T c2_i22;
  int32_T c2_i23;
  int32_T c2_i24;
  int32_T c2_i25;
  int32_T c2_i26;
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i30;
  int32_T c2_i31;
  int32_T c2_i32;
  int32_T c2_i33;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
  for (c2_i4 = 0; c2_i4 < 651264; c2_i4++) {
    chartInstance->c2_RGB[c2_i4] = (*chartInstance->c2_b_RGB)[c2_i4];
  }

  for (c2_i5 = 0; c2_i5 < 6; c2_i5++) {
    c2_b_value[c2_i5] = (*chartInstance->c2_value)[c2_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_I, 0U,
    c2_sf_marshallOut, c2_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_channel1Min, 1U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_channel1Max, 2U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_channel2Min, 3U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_channel2Max, 4U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_channel3Min, 5U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_channel3Max, 6U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_sliderBW, 7U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 8U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 9U, c2_b_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(chartInstance->c2_RGB, 10U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_value, 11U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(chartInstance->c2_BW, 12U,
    c2_c_sf_marshallOut, c2_c_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 14);
  for (c2_i6 = 0; c2_i6 < 651264; c2_i6++) {
    chartInstance->c2_X[c2_i6] = chartInstance->c2_RGB[c2_i6];
  }

  for (c2_i7 = 0; c2_i7 < 651264; c2_i7++) {
    chartInstance->c2_outputImage[c2_i7] = chartInstance->c2_I[c2_i7];
  }

  for (c2_i8 = 0; c2_i8 < 651264; c2_i8++) {
    chartInstance->c2_I[c2_i8] = chartInstance->c2_outputImage[c2_i8];
  }

  rgb2hsv_tbb_uint8(chartInstance->c2_X, 217088.0, chartInstance->c2_I, true);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 17);
  c2_channel1Min = c2_b_value[0];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
  c2_channel1Max = c2_b_value[1];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 20);
  c2_channel2Min = c2_b_value[2];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
  c2_channel2Max = c2_b_value[3];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
  c2_channel3Min = c2_b_value[4];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 24);
  c2_channel3Max = c2_b_value[5];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 27);
  c2_i9 = 0;
  for (c2_i10 = 0; c2_i10 < 512; c2_i10++) {
    for (c2_i12 = 0; c2_i12 < 424; c2_i12++) {
      chartInstance->c2_bv1[c2_i12 + c2_i9] = (chartInstance->c2_I[c2_i12 +
        c2_i9] >= c2_channel1Min);
    }

    c2_i9 += 424;
  }

  c2_i11 = 0;
  for (c2_i13 = 0; c2_i13 < 512; c2_i13++) {
    for (c2_i15 = 0; c2_i15 < 424; c2_i15++) {
      chartInstance->c2_bv2[c2_i15 + c2_i11] = (chartInstance->c2_I[c2_i15 +
        c2_i11] <= c2_channel1Max);
    }

    c2_i11 += 424;
  }

  for (c2_i14 = 0; c2_i14 < 217088; c2_i14++) {
    chartInstance->c2_bv1[c2_i14] = (chartInstance->c2_bv1[c2_i14] ||
      chartInstance->c2_bv2[c2_i14]);
  }

  c2_i16 = 0;
  for (c2_i17 = 0; c2_i17 < 512; c2_i17++) {
    for (c2_i19 = 0; c2_i19 < 424; c2_i19++) {
      chartInstance->c2_bv2[c2_i19 + c2_i16] = (chartInstance->c2_I[(c2_i19 +
        c2_i16) + 217088] >= c2_channel2Min);
    }

    c2_i16 += 424;
  }

  for (c2_i18 = 0; c2_i18 < 217088; c2_i18++) {
    chartInstance->c2_bv1[c2_i18] = (chartInstance->c2_bv1[c2_i18] &&
      chartInstance->c2_bv2[c2_i18]);
  }

  c2_i20 = 0;
  for (c2_i21 = 0; c2_i21 < 512; c2_i21++) {
    for (c2_i23 = 0; c2_i23 < 424; c2_i23++) {
      chartInstance->c2_bv2[c2_i23 + c2_i20] = (chartInstance->c2_I[(c2_i23 +
        c2_i20) + 217088] <= c2_channel2Max);
    }

    c2_i20 += 424;
  }

  for (c2_i22 = 0; c2_i22 < 217088; c2_i22++) {
    chartInstance->c2_bv1[c2_i22] = (chartInstance->c2_bv1[c2_i22] &&
      chartInstance->c2_bv2[c2_i22]);
  }

  c2_i24 = 0;
  for (c2_i25 = 0; c2_i25 < 512; c2_i25++) {
    for (c2_i27 = 0; c2_i27 < 424; c2_i27++) {
      chartInstance->c2_bv2[c2_i27 + c2_i24] = (chartInstance->c2_I[(c2_i27 +
        c2_i24) + 434176] >= c2_channel3Min);
    }

    c2_i24 += 424;
  }

  for (c2_i26 = 0; c2_i26 < 217088; c2_i26++) {
    chartInstance->c2_bv1[c2_i26] = (chartInstance->c2_bv1[c2_i26] &&
      chartInstance->c2_bv2[c2_i26]);
  }

  c2_i28 = 0;
  for (c2_i29 = 0; c2_i29 < 512; c2_i29++) {
    for (c2_i31 = 0; c2_i31 < 424; c2_i31++) {
      chartInstance->c2_bv2[c2_i31 + c2_i28] = (chartInstance->c2_I[(c2_i31 +
        c2_i28) + 434176] <= c2_channel3Max);
    }

    c2_i28 += 424;
  }

  for (c2_i30 = 0; c2_i30 < 217088; c2_i30++) {
    chartInstance->c2_sliderBW[c2_i30] = (chartInstance->c2_bv1[c2_i30] &&
      chartInstance->c2_bv2[c2_i30]);
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 31);
  for (c2_i32 = 0; c2_i32 < 217088; c2_i32++) {
    chartInstance->c2_BW[c2_i32] = chartInstance->c2_sliderBW[c2_i32];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -31);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i33 = 0; c2_i33 < 217088; c2_i33++) {
    (*chartInstance->c2_b_BW)[c2_i33] = chartInstance->c2_BW[c2_i33];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_test_kinect_ver2
  (SFc2_test_kinect_ver2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)(c2_machineNumber);
  (void)(c2_chartNumber);
  (void)(c2_instanceNumber);
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i34;
  int32_T c2_i35;
  const mxArray *c2_c_y = NULL;
  int32_T c2_i36;
  int32_T c2_i37;
  int32_T c2_i38;
  SFc2_test_kinect_ver2InstanceStruct *chartInstance;
  chartInstance = (SFc2_test_kinect_ver2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i34 = 0;
  for (c2_i35 = 0; c2_i35 < 3; c2_i35++) {
    c2_i36 = 0;
    for (c2_i37 = 0; c2_i37 < 512; c2_i37++) {
      for (c2_i38 = 0; c2_i38 < 424; c2_i38++) {
        chartInstance->c2_u[(c2_i38 + c2_i36) + c2_i34] = (*(real_T (*)[651264])
          c2_inData)[(c2_i38 + c2_i36) + c2_i34];
      }

      c2_i36 += 424;
    }

    c2_i34 += 217088;
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", chartInstance->c2_u, 0, 0U, 1U, 0U,
    3, 424, 512, 3), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_c_y, false);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c2_d_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_c_y[651264])
{
  int32_T c2_i39;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_d_u), chartInstance->c2_dv0, 1, 0, 0U,
                1, 0U, 3, 424, 512, 3);
  for (c2_i39 = 0; c2_i39 < 651264; c2_i39++) {
    c2_c_y[c2_i39] = chartInstance->c2_dv0[c2_i39];
  }

  sf_mex_destroy(&c2_d_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_I;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_i40;
  int32_T c2_i41;
  int32_T c2_i42;
  int32_T c2_i43;
  int32_T c2_i44;
  SFc2_test_kinect_ver2InstanceStruct *chartInstance;
  chartInstance = (SFc2_test_kinect_ver2InstanceStruct *)chartInstanceVoid;
  c2_b_I = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_I), &c2_thisId,
                      chartInstance->c2_y);
  sf_mex_destroy(&c2_b_I);
  c2_i40 = 0;
  for (c2_i41 = 0; c2_i41 < 3; c2_i41++) {
    c2_i42 = 0;
    for (c2_i43 = 0; c2_i43 < 512; c2_i43++) {
      for (c2_i44 = 0; c2_i44 < 424; c2_i44++) {
        (*(real_T (*)[651264])c2_outData)[(c2_i44 + c2_i42) + c2_i40] =
          chartInstance->c2_y[(c2_i44 + c2_i42) + c2_i40];
      }

      c2_i42 += 424;
    }

    c2_i40 += 217088;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  real_T c2_d_u;
  const mxArray *c2_c_y = NULL;
  SFc2_test_kinect_ver2InstanceStruct *chartInstance;
  chartInstance = (SFc2_test_kinect_ver2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_d_u = *(real_T *)c2_inData;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_c_y, false);
  return c2_mxArrayOutData;
}

static real_T c2_b_emlrt_marshallIn(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c2_d_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_c_y;
  real_T c2_d0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_d_u), &c2_d0, 1, 0, 0U, 0, 0U, 0);
  c2_c_y = c2_d0;
  sf_mex_destroy(&c2_d_u);
  return c2_c_y;
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_channel1Min;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_c_y;
  SFc2_test_kinect_ver2InstanceStruct *chartInstance;
  chartInstance = (SFc2_test_kinect_ver2InstanceStruct *)chartInstanceVoid;
  c2_channel1Min = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_c_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_channel1Min),
    &c2_thisId);
  sf_mex_destroy(&c2_channel1Min);
  *(real_T *)c2_outData = c2_c_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i45;
  int32_T c2_i46;
  const mxArray *c2_c_y = NULL;
  int32_T c2_i47;
  SFc2_test_kinect_ver2InstanceStruct *chartInstance;
  chartInstance = (SFc2_test_kinect_ver2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i45 = 0;
  for (c2_i46 = 0; c2_i46 < 512; c2_i46++) {
    for (c2_i47 = 0; c2_i47 < 424; c2_i47++) {
      chartInstance->c2_c_u[c2_i47 + c2_i45] = (*(boolean_T (*)[217088])
        c2_inData)[c2_i47 + c2_i45];
    }

    c2_i45 += 424;
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", chartInstance->c2_c_u, 11, 0U, 1U,
    0U, 2, 424, 512), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_c_y, false);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c2_b_sliderBW, const char_T *c2_identifier,
  boolean_T c2_c_y[217088])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sliderBW), &c2_thisId,
                        c2_c_y);
  sf_mex_destroy(&c2_b_sliderBW);
}

static void c2_d_emlrt_marshallIn(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c2_d_u, const emlrtMsgIdentifier *c2_parentId,
  boolean_T c2_c_y[217088])
{
  int32_T c2_i48;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_d_u), chartInstance->c2_bv3, 1, 11,
                0U, 1, 0U, 2, 424, 512);
  for (c2_i48 = 0; c2_i48 < 217088; c2_i48++) {
    c2_c_y[c2_i48] = chartInstance->c2_bv3[c2_i48];
  }

  sf_mex_destroy(&c2_d_u);
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sliderBW;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_i49;
  int32_T c2_i50;
  int32_T c2_i51;
  SFc2_test_kinect_ver2InstanceStruct *chartInstance;
  chartInstance = (SFc2_test_kinect_ver2InstanceStruct *)chartInstanceVoid;
  c2_b_sliderBW = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sliderBW), &c2_thisId,
                        chartInstance->c2_b_y);
  sf_mex_destroy(&c2_b_sliderBW);
  c2_i49 = 0;
  for (c2_i50 = 0; c2_i50 < 512; c2_i50++) {
    for (c2_i51 = 0; c2_i51 < 424; c2_i51++) {
      (*(boolean_T (*)[217088])c2_outData)[c2_i51 + c2_i49] =
        chartInstance->c2_b_y[c2_i51 + c2_i49];
    }

    c2_i49 += 424;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i52;
  int32_T c2_i53;
  const mxArray *c2_c_y = NULL;
  int32_T c2_i54;
  int32_T c2_i55;
  int32_T c2_i56;
  SFc2_test_kinect_ver2InstanceStruct *chartInstance;
  chartInstance = (SFc2_test_kinect_ver2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_i52 = 0;
  for (c2_i53 = 0; c2_i53 < 3; c2_i53++) {
    c2_i54 = 0;
    for (c2_i55 = 0; c2_i55 < 512; c2_i55++) {
      for (c2_i56 = 0; c2_i56 < 424; c2_i56++) {
        chartInstance->c2_b_u[(c2_i56 + c2_i54) + c2_i52] = (*(uint8_T (*)
          [651264])c2_inData)[(c2_i56 + c2_i54) + c2_i52];
      }

      c2_i54 += 424;
    }

    c2_i52 += 217088;
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", chartInstance->c2_b_u, 3, 0U, 1U, 0U,
    3, 424, 512, 3), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_c_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_i57;
  const mxArray *c2_c_y = NULL;
  real_T c2_d_u[6];
  SFc2_test_kinect_ver2InstanceStruct *chartInstance;
  chartInstance = (SFc2_test_kinect_ver2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  for (c2_i57 = 0; c2_i57 < 6; c2_i57++) {
    c2_d_u[c2_i57] = (*(real_T (*)[6])c2_inData)[c2_i57];
  }

  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", c2_d_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_c_y, false);
  return c2_mxArrayOutData;
}

const mxArray *sf_c2_test_kinect_ver2_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c2_nameCaptureInfo;
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData;
  int32_T c2_d_u;
  const mxArray *c2_c_y = NULL;
  SFc2_test_kinect_ver2InstanceStruct *chartInstance;
  chartInstance = (SFc2_test_kinect_ver2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_mxArrayOutData = NULL;
  c2_d_u = *(int32_T *)c2_inData;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_d_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_c_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_e_emlrt_marshallIn(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c2_d_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_c_y;
  int32_T c2_i58;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_d_u), &c2_i58, 1, 6, 0U, 0, 0U, 0);
  c2_c_y = c2_i58;
  sf_mex_destroy(&c2_d_u);
  return c2_c_y;
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_c_y;
  SFc2_test_kinect_ver2InstanceStruct *chartInstance;
  chartInstance = (SFc2_test_kinect_ver2InstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_c_y = c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_c_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_f_emlrt_marshallIn(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_test_kinect_ver2, const
  char_T *c2_identifier)
{
  uint8_T c2_c_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = (const char *)c2_identifier;
  c2_thisId.fParent = NULL;
  c2_thisId.bParentIsCell = false;
  c2_c_y = c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_test_kinect_ver2), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_test_kinect_ver2);
  return c2_c_y;
}

static uint8_T c2_g_emlrt_marshallIn(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance, const mxArray *c2_d_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_c_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_d_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_c_y = c2_u0;
  sf_mex_destroy(&c2_d_u);
  return c2_c_y;
}

static void init_dsm_address_info(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_test_kinect_ver2InstanceStruct
  *chartInstance)
{
  chartInstance->c2_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c2_b_RGB = (uint8_T (*)[651264])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_b_BW = (boolean_T (*)[217088])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_value = (real_T (*)[6])ssGetInputPortSignal_wrapper
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

void sf_c2_test_kinect_ver2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(949831362U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(779030516U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1473264971U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2462456872U);
}

mxArray* sf_c2_test_kinect_ver2_get_post_codegen_info(void);
mxArray *sf_c2_test_kinect_ver2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("USH9Ngqn11gcx6fvmtjlQD");
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
    mxArray* mxPostCodegenInfo = sf_c2_test_kinect_ver2_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_test_kinect_ver2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,1);
  mxSetCell(mxcell3p, 0, mxCreateString(
             "images.internal.coder.buildable.Rgb2hsvBuildable"));
  return(mxcell3p);
}

mxArray *sf_c2_test_kinect_ver2_jit_fallback_info(void)
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

mxArray *sf_c2_test_kinect_ver2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_test_kinect_ver2_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c2_test_kinect_ver2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"BW\",},{M[8],M[0],T\"is_active_c2_test_kinect_ver2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_test_kinect_ver2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_test_kinect_ver2InstanceStruct *chartInstance =
      (SFc2_test_kinect_ver2InstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _test_kinect_ver2MachineNumber_,
           2,
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
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6U;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 424U;
          dimVector[1]= 512U;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)
            c2_c_sf_marshallIn);
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
    SFc2_test_kinect_ver2InstanceStruct *chartInstance =
      (SFc2_test_kinect_ver2InstanceStruct *)sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)chartInstance->c2_b_RGB);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c2_b_BW);
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c2_value);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "swsaoHG2NiQmJYX8qBJU7LC";
}

static void sf_opaque_initialize_c2_test_kinect_ver2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_test_kinect_ver2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_test_kinect_ver2((SFc2_test_kinect_ver2InstanceStruct*)
    chartInstanceVar);
  initialize_c2_test_kinect_ver2((SFc2_test_kinect_ver2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_test_kinect_ver2(void *chartInstanceVar)
{
  enable_c2_test_kinect_ver2((SFc2_test_kinect_ver2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c2_test_kinect_ver2(void *chartInstanceVar)
{
  disable_c2_test_kinect_ver2((SFc2_test_kinect_ver2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c2_test_kinect_ver2(void *chartInstanceVar)
{
  sf_gateway_c2_test_kinect_ver2((SFc2_test_kinect_ver2InstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_test_kinect_ver2(SimStruct* S)
{
  return get_sim_state_c2_test_kinect_ver2((SFc2_test_kinect_ver2InstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_test_kinect_ver2(SimStruct* S, const
  mxArray *st)
{
  set_sim_state_c2_test_kinect_ver2((SFc2_test_kinect_ver2InstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c2_test_kinect_ver2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_test_kinect_ver2InstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_test_kinect_ver2_optimization_info();
    }

    finalize_c2_test_kinect_ver2((SFc2_test_kinect_ver2InstanceStruct*)
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
  initSimStructsc2_test_kinect_ver2((SFc2_test_kinect_ver2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_test_kinect_ver2(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_test_kinect_ver2((SFc2_test_kinect_ver2InstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c2_test_kinect_ver2(SimStruct *S)
{
  /* Set overwritable ports for inplace optimization */
  ssSetInputPortDirectFeedThrough(S, 0, 1);
  ssSetInputPortDirectFeedThrough(S, 1, 1);
  ssSetStatesModifiedOnlyInUpdate(S, 1);
  ssSetBlockIsPurelyCombinatorial_wrapper(S, 1);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_test_kinect_ver2_optimization_info
      (sim_mode_is_rtw_gen(S), sim_mode_is_modelref_sim(S), sim_mode_is_external
       (S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetSupportedForRowMajorCodeGen(S, 1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 2);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,2);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3421571592U));
  ssSetChecksum1(S,(2547295101U));
  ssSetChecksum2(S,(1712134156U));
  ssSetChecksum3(S,(2922148001U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_test_kinect_ver2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_test_kinect_ver2(SimStruct *S)
{
  SFc2_test_kinect_ver2InstanceStruct *chartInstance;
  chartInstance = (SFc2_test_kinect_ver2InstanceStruct *)utMalloc(sizeof
    (SFc2_test_kinect_ver2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc2_test_kinect_ver2InstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c2_test_kinect_ver2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_test_kinect_ver2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c2_test_kinect_ver2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_test_kinect_ver2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_test_kinect_ver2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_test_kinect_ver2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_test_kinect_ver2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_test_kinect_ver2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_test_kinect_ver2;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_test_kinect_ver2;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c2_test_kinect_ver2;
  chartInstance->chartInfo.callGetHoverDataForMsg = NULL;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartEventFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  chart_debug_initialization(S,1);
  mdl_start_c2_test_kinect_ver2(chartInstance);
}

void c2_test_kinect_ver2_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_test_kinect_ver2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_test_kinect_ver2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_test_kinect_ver2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_test_kinect_ver2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
