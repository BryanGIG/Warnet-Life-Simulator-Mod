#include "../Includes.hpp"

void (*setGold)(GameManager *, int);
float (*getMoney)(GameManager *);
void (*setMoney)(GameManager *, float);
void (*setSpecialToken)(GameManager *, int);
void (*setGachaKey)(GameManager *, int);
void (*setWP)(GameManager *, int);

uintptr_t _money;

uintptr_t limitCurangSpecialToken;
uintptr_t hardLimitSpecialToken;

uintptr_t hardLimitWp;
uintptr_t limitCurangWp;

uintptr_t hardLimitGachaKey;
uintptr_t limitCurangGachaKey;

void setNoLimit(GameManager *instance) {
    Il2Cpp::SetField(instance, limitCurangWp, INT_MAX);
    Il2Cpp::SetField(instance, hardLimitWp, INT_MAX);

    Il2Cpp::SetField(instance, limitCurangSpecialToken, INT_MAX);
    Il2Cpp::SetField(instance, hardLimitSpecialToken, INT_MAX);

    Il2Cpp::SetField(instance, limitCurangGachaKey, INT_MAX);
    Il2Cpp::SetField(instance, hardLimitGachaKey, INT_MAX);
}

void new_setGold(GameManager *instance, int) {
    setNoLimit(instance);
    setGold(instance, 99999999);
}

float new_getMoney(GameManager *instance) {
    setNoLimit(instance);
    Il2Cpp::SetField(instance, _money, 100000000);
    return 100000000;
}

void new_setMoney(GameManager *instance, float val) {
    setNoLimit(instance);
    Il2Cpp::SetField(instance, _money, 100000000);
    setMoney(instance, 100000000);
}

void new_setSpecialToken(GameManager *instance, int) {
    setNoLimit(instance);
    setSpecialToken(instance, 99999999);
}

void new_setGachaKey(GameManager *instance, int) {
    setNoLimit(instance);
    setGachaKey(instance, 99999999);
}

void new_setWP(GameManager *instance, int) {
    setNoLimit(instance);
    setWP(instance, 99999999);
}

void GameManager::Initialize() {
    setPointer(setGold, "set_Gold", 1);
    setPointer(getMoney, "get_Money", 0);
    setPointer(setMoney, "set_Money", 1);
    setPointer(setSpecialToken, "set_SpecialToken", 1);
    setPointer(setGachaKey, "set_GachaKey", 1);
    setPointer(setWP, "set_WP", 1);

    getFieldOffset(_money, "_money");

    getFieldOffset(limitCurangSpecialToken, "limitCurangSpecialToken");
    getFieldOffset(hardLimitSpecialToken, "hardLimitSpecialToken");

    getFieldOffset(hardLimitWp, "hardLimitWp");
    getFieldOffset(limitCurangWp, "limitCurangWp");

    getFieldOffset(hardLimitGachaKey, "hardLimitGachaKey");
    getFieldOffset(limitCurangGachaKey, "limitCurangGachaKey");
}

void GameManager::Hook() {
    setHook(setGold, "set_Gold")
    setHook(getMoney, "get_Money")
    setHook(setMoney, "set_Money")
    setHook(setSpecialToken, "set_SpecialToken")
    setHook(setGachaKey, "set_GachaKey")
    setHook(setWP, "set_WP")
}

const char *GameManager::getAssembly() {
    return "Assembly-CSharp.dll";
}

const char *GameManager::getNamespace() {
    return "";
}

const char *GameManager::getClass() {
    return "GameManager";
}