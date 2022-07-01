cmake_minimum_required(VERSION 3.20.0)
set(BOARD nucleo_f401re)
find_package(Zephyr)
project(my_zephyr_app)


set(TVMC_COMMAND python3 -m tvm.driver.tvmc)
set(TVMC_ARGS 
    --target="c" # C targets
    --runtime=crt # C Runtime
    --executor=aot # Ahead-of-Time Executor
    --executor-aot-unpacked-api=1 # Direct internal calls to operators
    --executor-aot-interface-api=c # Expose C interface to the model
    --pass-config=tir.disable_vectorize=1 # Disable vectorizer for C output
    --output-format=mlf # Output Model Library Format tarball
)

set(TVM_RUNTIME
    ${CMAKE_CURRENT_BINARY_DIR}/runtime/src/runtime/crt/common/crt_backend_api.c
    ${CMAKE_CURRENT_BINARY_DIR}/runtime/src/runtime/crt/memory/stack_allocator.c
)
set(CODEGEN_OUTPUT 
    ${CMAKE_CURRENT_BINARY_DIR}/codegen/host/src/default_lib0.c
    ${CMAKE_CURRENT_BINARY_DIR}/codegen/host/src/default_lib1.c
    # ${CMAKE_CURRENT_BINARY_DIR}/codegen/host/src/default_lib2.c
)
set(DATA_FILES 
    ${CMAKE_CURRENT_BINARY_DIR}/inputs.c 
    ${CMAKE_CURRENT_BINARY_DIR}/outputs.c 
    ${CMAKE_CURRENT_BINARY_DIR}/labels.c
)

add_custom_command(
    OUTPUT ${TVM_RUNTIME}
    OUTPUT ${CODEGEN_OUTPUT} 
    COMMAND ${TVMC_COMMAND} compile ${TVMC_ARGS} ${CMAKE_CURRENT_SOURCE_DIR}/model/cnn_s_quantized.tflite
    COMMAND tar xf ${CMAKE_CURRENT_BINARY_DIR}/module.tar
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
add_custom_command(
    OUTPUT ${DATA_FILES}
    COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/model/convert_input.py ${CMAKE_CURRENT_SOURCE_DIR}/model/input.txt ${CMAKE_CURRENT_BINARY_DIR}
    COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/model/convert_labels.py ${CMAKE_CURRENT_SOURCE_DIR}/model/labels.txt ${CMAKE_CURRENT_BINARY_DIR}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

target_sources(app PRIVATE 
    src/main.c
    ${TVM_RUNTIME}
    ${CODEGEN_OUTPUT}
    ${DATA_FILES}

)
target_include_directories(app 
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include 
    PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/runtime/include ${CMAKE_CURRENT_BINARY_DIR}/codegen/host/include
)
