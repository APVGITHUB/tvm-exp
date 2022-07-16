// tvm target: c -keys=cpu -link-params=0 -model=host
#define TVM_EXPORTS
#include "tvm/runtime/c_runtime_api.h"
#include "tvm/runtime/c_backend_api.h"
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif
static const int8_t __attribute__((section(".rodata.tvm"), aligned(16))) fused_multiply_constant_0[10] = {
    +0x01, +0x01, +0x01, +0x01, +0x01, +0x01, +0x01, +0x01, 
    +0x01, +0x01
};
#ifdef __cplusplus
}  // extern "C"
#endif
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_multiply_add(void* args, int32_t* arg_type_ids, int32_t num_args, void* out_ret_value, int32_t* out_ret_tcode, void* resource_handle) {
  void* arg_placeholder = (((TVMValue*)args)[0].v_handle);
  int32_t arg_placeholder_code = arg_type_ids[0];
  void* arg_T_add = (((TVMValue*)args)[1].v_handle);
  int32_t arg_T_add_code = arg_type_ids[1];
  void* placeholder = (((DLTensor*)arg_placeholder)[0].data);
  void* arg_placeholder_shape = (((DLTensor*)arg_placeholder)[0].shape);
  void* arg_placeholder_strides = (((DLTensor*)arg_placeholder)[0].strides);
  int32_t dev_id = (((DLTensor*)arg_placeholder)[0].device.device_id);
  void* T_add = (((DLTensor*)arg_T_add)[0].data);
  void* arg_T_add_shape = (((DLTensor*)arg_T_add)[0].shape);
  void* arg_T_add_strides = (((DLTensor*)arg_T_add)[0].strides);
  if (!(arg_placeholder_strides == NULL)) {
  }
  if (!(arg_T_add_strides == NULL)) {
  }
  for (int32_t ax0_inner = 0; ax0_inner < 10; ++ax0_inner) {
    ((int8_t*)T_add)[ax0_inner] = ((((int8_t*)placeholder)[ax0_inner] * ((int8_t*)placeholder)[ax0_inner]) + ((int8_t*)fused_multiply_constant_0)[ax0_inner]);
  }
  return 0;
}

#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default___tvm_main__(void* args, int32_t* arg_type_ids, int32_t num_args, void* out_ret_value, int32_t* out_ret_tcode, void* resource_handle) {
  TVMValue stack[2];
  void* stack_tcode = stack;
  TVMValue stack1[3];
  void* stack_value = stack1;
  TVMValue stack2[12];
  void* stack_array = stack2;
  TVMValue stack3[2];
  void* stack_shape = stack3;
  void* arg_x = (((TVMValue*)args)[0].v_handle);
  int32_t arg_x_code = arg_type_ids[0];
  void* arg_output = (((TVMValue*)args)[1].v_handle);
  int32_t arg_output_code = arg_type_ids[1];
  void* x_buffer_var = (((DLTensor*)arg_x)[0].data);
  void* arg_x_shape = (((DLTensor*)arg_x)[0].shape);
  void* arg_x_strides = (((DLTensor*)arg_x)[0].strides);
  int32_t dev_id = (((DLTensor*)arg_x)[0].device.device_id);
  void* output_buffer_var = (((DLTensor*)arg_output)[0].data);
  void* arg_output_shape = (((DLTensor*)arg_output)[0].shape);
  void* arg_output_strides = (((DLTensor*)arg_output)[0].strides);
  if (!(arg_x_strides == NULL)) {
  }
  if (!(arg_output_strides == NULL)) {
  }
  ((int64_t*)stack_shape)[0] = (int64_t)10;
  (((DLTensor*)stack_array)[0].data) = x_buffer_var;
  (((DLTensor*)stack_array)[0].shape) = (&(((int64_t*)stack_shape)[0]));
    uint64_t _1 = (uint64_t)0;
  (((DLTensor*)stack_array)[0].strides) = (int64_t*)(*(void* *)(&(_1)));
  (((DLTensor*)stack_array)[0].ndim) = (uint32_t)1;
  (((DLTensor*)stack_array)[0].dtype.code) = (uint8_t)0;
  (((DLTensor*)stack_array)[0].dtype.bits) = (uint8_t)8;
  (((DLTensor*)stack_array)[0].dtype.lanes) = (uint16_t)1;
  (((DLTensor*)stack_array)[0].byte_offset) = (uint64_t)0;
  (((DLTensor*)stack_array)[0].device.device_id) = dev_id;
  (((DLTensor*)stack_array)[0].device.device_type) = (DLDeviceType)1;
  ((int64_t*)stack_shape)[1] = (int64_t)10;
  (((DLTensor*)stack_array)[1].data) = output_buffer_var;
  (((DLTensor*)stack_array)[1].shape) = (&(((int64_t*)stack_shape)[1]));
    uint64_t _2 = (uint64_t)0;
  (((DLTensor*)stack_array)[1].strides) = (int64_t*)(*(void* *)(&(_2)));
  (((DLTensor*)stack_array)[1].ndim) = (uint32_t)1;
  (((DLTensor*)stack_array)[1].dtype.code) = (uint8_t)0;
  (((DLTensor*)stack_array)[1].dtype.bits) = (uint8_t)8;
  (((DLTensor*)stack_array)[1].dtype.lanes) = (uint16_t)1;
  (((DLTensor*)stack_array)[1].byte_offset) = (uint64_t)0;
  (((DLTensor*)stack_array)[1].device.device_id) = dev_id;
  (((DLTensor*)stack_array)[1].device.device_type) = (DLDeviceType)1;
  (((TVMValue*)stack_value)[0].v_handle) = (((DLTensor*)stack_array) + 0);
  ((int32_t*)stack_tcode)[0] = 7;
  (((TVMValue*)stack_value)[1].v_handle) = (((DLTensor*)stack_array) + 1);
  ((int32_t*)stack_tcode)[1] = 7;
  TVMValue ret_val;
  int ret_type_code;
  if (tvmgen_default_fused_multiply_add( (TVMValue*) stack_value , (int*) stack_tcode, 2, &ret_val, &ret_type_code, NULL) != 0){
    return -1;
  }
  return 0;
}

