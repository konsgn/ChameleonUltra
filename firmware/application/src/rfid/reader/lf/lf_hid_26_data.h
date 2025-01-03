#ifndef __HID_26_DATA_H__
#define __HID_26_DATA_H__


#include "data_utils.h"
#include "bsp_time.h"

#ifdef __cplusplus
extern "C"
{
#endif
// #define CARD_BUF_BYTES_SIZE 10       // Card byte buffer size (manchestered)

// #define RAW_BUF_SIZE 24           // The maximum record buffer (used in filtering data before)
// #define CARD_BUF_SIZE 8           // Card size

// typedef struct {
//     uint8_t rawa[RAW_BUF_SIZE];    // The time difference between recording changes
//     uint8_t rawb[RAW_BUF_SIZE];    // The time difference between recording changes
//     uint8_t hexbuf[CARD_BUF_SIZE]; // manchester card data
//     uint8_t capture_started_bit;

#define CARD_BUF_BYTES_SIZE 5       // Card byte buffer size

#define RAW_BUF_SIZE 24           // The maximum record buffer
#define CARD_BUF_SIZE 8           // Card size

typedef struct {
    uint8_t rawa[RAW_BUF_SIZE];    // The time difference between recording changes
    uint8_t rawb[RAW_BUF_SIZE];    // The time difference between recording changes
    uint8_t hexbuf[CARD_BUF_SIZE]; // Patriotic card data
    uint8_t startbit;
} RAWBUF_TYPE_S;

//Card data
extern uint8_t cardbufbyte[CARD_BUF_BYTES_SIZE];


// void init_hid26_hw(void);
// void hid26_encoder(uint8_t *pData, uint8_t *pOut);
// uint8_t hid26_decoder(uint8_t *pData, uint8_t size, uint8_t *pOut);
// uint8_t hid26_read(uint8_t *uid, uint32_t timeout_ms);

void init_em410x_hw(void);
void em410x_encoder(uint8_t *pData, uint8_t *pOut);
uint8_t em410x_decoder(uint8_t *pData, uint8_t size, uint8_t *pOut);
uint8_t em410x_read(uint8_t *uid, uint32_t timeout_ms);


#ifdef __cplusplus
}
#endif

#endif
