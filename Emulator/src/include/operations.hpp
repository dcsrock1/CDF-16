#pragma once
#include <cstdint>

#define LDAC_IM_M 0x01
constexpr uint8_t LDAC_IM_P = 0x01;

class Operations {
public:
    static constexpr uint8_t NOP_OP = 0x00; // No Operation
    // All instructions for loading data into CPU registers are listed here
    //LDAC
    static constexpr uint8_t LDAC_IM_OP = 0x01; // e.g. LDAC #0000;
    static constexpr uint8_t LDAC_ZP_OP = 0x02; // e.g. LDAC $00;
    static constexpr uint8_t LDAC_ZPAI_OP = 0x03; // e.g. LDAC $00, A;
    static constexpr uint8_t LDAC_AB_OP = 0x04; // e.g. LDAC $0000;
    static constexpr uint8_t LDAC_ABAI_OP = 0x05; // e.g. LDAC $0000, A;
    static constexpr uint8_t LDAC_ABCI_OP = 0x06; // e.g. LDAC $0000, C;
    static constexpr uint8_t LDAC_ICI_OP = 0x07; // e.g. LDAC ($0000, C);
    static constexpr uint8_t LDAC_IDI_OP = 0x08; // e.g. LDAC ($0000), D;
    //LDA
    static constexpr uint8_t LDA_IM_OP = 0x09; // e.g. LDA #00;
    static constexpr uint8_t LDA_ZP_OP = 0x0A; // e.g. LDA $00;
    static constexpr uint8_t LDA_ZPAI_OP = 0x0B; // e.g. LDA $00, A;
    static constexpr uint8_t LDA_AB_OP = 0x0C; // e.g. LDA $0000;
    static constexpr uint8_t LDA_ABAI_OP = 0x0D; // e.g. LDA $0000, A;
    static constexpr uint8_t LDA_ABCI_OP = 0x0E; // e.g. LDA $0000, C;
    static constexpr uint8_t LDA_ICI_OP = 0x0F; // e.g. LDA ($0000, C);
    static constexpr uint8_t LDA_IDI_OP = 0x10; // e.g. LDA ($0000), D;
    //LDB
    static constexpr uint8_t LDB_IM_OP = 0x11; // e.g. LDB #00;
    static constexpr uint8_t LDB_ZP_OP = 0x12; // e.g. LDB $00;
    static constexpr uint8_t LDB_ZPAI_OP = 0x13; // e.g. LDB $00, A;
    static constexpr uint8_t LDB_AB_OP = 0x14; // e.g. LDB $0000;
    static constexpr uint8_t LDB_ABAI_OP = 0x15; // e.g. LDB $0000, A;
    static constexpr uint8_t LDB_ABCI_OP = 0x16; // e.g. LDB $0000, C;
    static constexpr uint8_t LDB_ICI_OP = 0x17; // e.g. LDB ($0000, C);
    static constexpr uint8_t LDB_IDI_OP = 0x18; // e.g. LDB ($0000), D;
    //LDD
    static constexpr uint8_t LDD_IM_OP = 0x19; // e.g. LDD #0000;
    static constexpr uint8_t LDD_ZP_OP = 0x1A; // e.g. LDD $00;
    static constexpr uint8_t LDD_ZPAI = 0x1B; // e.g. LDD $00, A;
    static constexpr uint8_t LDD_AB = 0x1C; // e.g. LDD $0000;
    static constexpr uint8_t LDD_ABAI = 0x1D; // e.g. LDD $0000, A;
    static constexpr uint8_t LDD_ABCI = 0x1E; // e.g. LDD $0000, C;
    static constexpr uint8_t LDD_ICI = 0x1F; // e.g. LDD ($0000, C);
    static constexpr uint8_t LDD_IDI = 0x20; // e.g. LDD ($0000), D;
    //STAC
    static constexpr uint8_t STAC_IM_OP = 0x21; // e.g. STAC #0000;
    static constexpr uint8_t STAC_ZP_OP = 0x22; // e.g. STAC $00;
    static constexpr uint8_t STAC_ZPAI_OP = 0x23; // e.g. STAC $00, A;
    static constexpr uint8_t STAC_AB_OP = 0x24; // e.g. STAC $0000;
    static constexpr uint8_t STAC_ABAI_OP = 0x25; // e.g. STAC $0000, A;
    static constexpr uint8_t STAC_ABCI_OP = 0x26; // e.g. STAC $0000, C;
    static constexpr uint8_t STAC_ICI_OP = 0x27; // e.g. STAC ($0000, C);
    static constexpr uint8_t STAC_IDI_OP = 0x28; // e.g. STAC ($0000), D;
    //STA
    static constexpr uint8_t STA_IM_OP = 0x29; // e.g. STA #00;
    static constexpr uint8_t STA_ZP_OP = 0x2A; // e.g. STA $00;
    static constexpr uint8_t STA_ZPAI_OP = 0x2B; // e.g. STA $00, A;
    static constexpr uint8_t STA_AB_OP = 0x2C; // e.g. STA $0000;
    static constexpr uint8_t STA_ABAI_OP = 0x2C; // e.g. STA $0000, A;
    static constexpr uint8_t STA_ABCI_OP = 0x2D; // e.g. STA $0000, C;
    static constexpr uint8_t STA_ICI_OP = 0x2E; // e.g. STA ($0000, C);
    static constexpr uint8_t STA_IDI_OP = 0x2F; // e.g. STA ($0000), D;
    //STB
    static constexpr uint8_t STB_IM_OP = 0x30; // e.g. STB #00;
    static constexpr uint8_t STB_ZP_OP = 0x31; // e.g. STB $00;
    static constexpr uint8_t STB_ZPAI_OP = 0x32; // e.g. STB $00, A;
    static constexpr uint8_t STB_AB_OP = 0x33; // e.g. STB $0000;
    static constexpr uint8_t STB_ABAI_OP = 0x34; // e.g. STB $0000, A;
    static constexpr uint8_t STB_ABCI_OP = 0x35; // e.g. STB $0000, C;
    static constexpr uint8_t STB_ICI_OP = 0x36; // e.g. STB ($0000, C);
    static constexpr uint8_t STB_IDI_OP = 0x37; // e.g. STB ($0000), D;
    //STC
    static constexpr uint8_t STC_IM_OP = 0x38; // e.g. STC #0000;
    static constexpr uint8_t STC_ZP_OP = 0x39; // e.g. STC $00;
    static constexpr uint8_t STC_ZPAI_OP = 0x3A; // e.g. STC $00, A;
    static constexpr uint8_t STC_AB_OP = 0x3B; // e.g. STC $0000;
    static constexpr uint8_t STC_ABAI_OP = 0x3C; // e.g. STC $0000, A;
    static constexpr uint8_t STC_ABCI_OP = 0x3D; // e.g. STC $0000, C;
    static constexpr uint8_t STC_ICI_OP = 0x3E; // e.g. STC ($0000, C);
    static constexpr uint8_t STC_IDI_OP = 0x3F; // e.g. STC ($0000), D;
    //STD
    static constexpr uint8_t STD_IM_OP = 0x40; // e.g. STD #0000;
    static constexpr uint8_t STD_ZP_OP = 0x41; // e.g. STD $00;
    static constexpr uint8_t STD_ZPAI_OP = 0x42; // e.g. STD $00, A;
    static constexpr uint8_t STD_AB_OP = 0x43; // e.g. STD $0000;
    static constexpr uint8_t STD_ABAI_OP = 0x44; // e.g. STD $0000, A;
    static constexpr uint8_t STD_ABCI_OP = 0x45; // e.g. STD $0000, C;
    static constexpr uint8_t STD_ICI_OP = 0x46; // e.g. STD ($0000, C);
    static constexpr uint8_t STD_IDI_OP = 0x47; // e.g. STD ($0000), D;
};
