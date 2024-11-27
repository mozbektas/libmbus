cmake_minimum_required(VERSION 3.10)
project(libmbus)

# C standart versiyonu
set(CMAKE_C_STANDARD 99)

# Libmbus kaynak dosyalarını belirtiyoruz
set(MBUS_SOURCES
    mbus/mbus.c
    mbus/mbus-protocol.c
    mbus/mbus-protocol-aux.c
    mbus/mbus-serial.c
    mbus/mbus-tcp.c
)

# Kütüphaneyi SHARED (DLL) olarak derliyoruz
add_library(mbus SHARED ${MBUS_SOURCES})

# Include dizinlerini ekliyoruz
target_include_directories(mbus PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mbus)
