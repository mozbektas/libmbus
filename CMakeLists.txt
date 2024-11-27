cmake_minimum_required(VERSION 3.10)
project(libmbus_vba)

# C dilini kullanıyoruz
set(CMAKE_C_STANDARD 99)

# Libmbus kaynak dosyalarını ekleyin
set(MBUS_SOURCES
    mbus/mbus.c
    mbus/mbus-protocol.c
    mbus/mbus-protocol-aux.c
    mbus/mbus-serial.c
    mbus/mbus-tcp.c
)

# Wrapper fonksiyonlarını ekleyin
set(WRAPPER_SOURCES
    wrapper.c  # Bu dosya, Excel VBA ile uyumlu wrapper kodunu içeriyor
)

# DLL oluşturuyoruz
add_library(libmbus_vba SHARED ${MBUS_SOURCES} ${WRAPPER_SOURCES})

# DLL için Windows uyumlu derleme ayarları
target_compile_definitions(libmbus_vba PRIVATE -DWIN32 -D_CALLCONV=__stdcall)

# Include dizinini ekleyin
target_include_directories(libmbus_vba PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mbus)

# Linker komutları ile ekleme yapılabilir
# target_link_libraries(libmbus_vba PRIVATE some_required_library)
