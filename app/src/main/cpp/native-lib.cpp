#include <jni.h>
#include <string>
#include <thread>
#include "Engine/Includes.hpp"

__attribute__ ((constructor))
void lib_main() {
    std::thread([]() {
        sleep(10);

        ProcMap map;
        do {
            map = KittyMemory::getElfBaseMap("libil2cpp.so");
        } while (!map.isValid() && !map.isValidELF());

        LOGI("libil2cpp.so: %p", (void *) map.startAddress);

        Il2Cpp::Init("libil2cpp.so");

        // Initialize the classes
        ListCBaseEntry::add({
            std::make_shared<GameManager>()
        });
        ListCBaseEntry::Initialize();
    }).detach();
}