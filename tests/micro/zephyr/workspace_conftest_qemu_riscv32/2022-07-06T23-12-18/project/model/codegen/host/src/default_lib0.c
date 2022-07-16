#include <tvm/runtime/crt/module.h>
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_fused_add(TVMValue* args, int* type_code, int num_args, TVMValue* out_value, int* out_type_code, void* resource_handle);
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default___tvm_main__(TVMValue* args, int* type_code, int num_args, TVMValue* out_value, int* out_type_code, void* resource_handle);
#ifdef __cplusplus
extern "C"
#endif
TVM_DLL int32_t tvmgen_default_get_c_metadata(TVMValue* args, int* type_code, int num_args, TVMValue* out_value, int* out_type_code, void* resource_handle);
static TVMBackendPackedCFunc _tvm_func_array[] = {
    (TVMBackendPackedCFunc)tvmgen_default_fused_add,
    (TVMBackendPackedCFunc)tvmgen_default___tvm_main__,
    (TVMBackendPackedCFunc)tvmgen_default_get_c_metadata,
};
static const TVMFuncRegistry _tvm_func_registry = {
    "\003\000tvmgen_default_fused_add\000tvmgen_default___tvm_main__\000tvmgen_default_get_c_metadata\000",    _tvm_func_array,
};
static const TVMModule _tvm_system_lib = {
    &_tvm_func_registry,
};
const TVMModule* TVMSystemLibEntryPoint(void) {
    return &_tvm_system_lib;
}
#include "tvm/runtime/c_runtime_api.h"
#ifdef __cplusplus
extern "C" {
#endif
TVM_DLL int32_t tvmgen_default___tvm_main__(TVMValue* args, int* type_code, int num_args, TVMValue* out_value, int* out_type_code, void* resource_handle);

int32_t tvmgen_default_run(TVMValue* args, int* type_code, int num_args, TVMValue* out_value, int* out_type_code, void* resource_handle) {
TVMValue tensors[3];
tensors[0] = ((TVMValue*)args)[0];
tensors[1] = ((TVMValue*)args)[1];
tensors[2] = ((TVMValue*)args)[2];
return tvmgen_default___tvm_main__((void*)tensors, type_code, num_args, out_value, out_type_code, resource_handle);
}
#ifdef __cplusplus
}
#endif
;