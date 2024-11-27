cmake_minimum_required(VERSION 3.10)
project(libmbus_vba)

set(CMAKE_C_STANDARD 99)

set(MBUS_SOURCES
    mbus/mbus.c
    mbus/mbus-protocol.c
    mbus/mbus-protocol-aux.c
    mbus/mbus-serial.c
    mbus/mbus-tcp.c
)

set(WRAPPER_SOURCES
    wrapper.c  # Bu dosya, Excel VBA ile uyumlu wrapper kodunu içeriyor
)

add_library(libmbus_vba SHARED ${MBUS_SOURCES} ${WRAPPER_SOURCES})

target_compile_definitions(libmbus_vba PRIVATE -DWIN32 -D_CALLCONV=__stdcall)

target_include_directories(libmbus_vba PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mbus)
