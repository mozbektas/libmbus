#include <windows.h>
#include "mbus/mbus.h"  // Libmbus başlık dosyasını dahil edin.

// Libmbus fonksiyonlarını Excel VBA ile uyumlu hale getiren wrapper fonksiyonları.

__declspec(dllexport) int __stdcall vb_mbus_init() {
    return mbus_init(); // Libmbus'un orijinal fonksiyonunu çağırıyoruz.
}

__declspec(dllexport) int __stdcall vb_mbus_ping() {
    // Örnek bir test fonksiyonu
    return 42; // Sabit bir değer döndürüyoruz (42).
}
