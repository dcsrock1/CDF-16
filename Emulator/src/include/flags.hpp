#pragma once
struct Flags {
    bool halt : 1;
    bool reset : 1;
    bool memoryBankSelector : 1;
    bool storageBankSelector : 1;
    bool keyboardEnable : 1;
    bool screenEnable : 1;
    bool interruptEnable : 1;
    bool interruptTriggered : 1;
    void default_flags();
} __attribute__((packed));

