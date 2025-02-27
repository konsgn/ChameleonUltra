#ifndef __HID_26_DATA_H__
#define __HID_26_DATA_H__


#include "data_utils.h"
#include "bsp_time.h"

#ifdef __cplusplus
extern "C"
{
#endif


#define RAW_BUF_SIZE 128           // The maximum record buffer (used in filtering data before)
#define CARD_BUF_SIZE 16          // Card size of raw bits needing manchester decoding.
#define CARD_BUF_BYTES_SIZE 8     // Card byte buffer size (decoded from manchester data)

typedef enum _hid_decode_state{
    state_header_hunt=0, // starting our hunt for the non-manchester 3 "high" bits.
    state_bit_pull, // 3 "high" bits found, manchester data started.
    state_reset_needed, // unexpected length of bits, need reset.
    state_max_read_complete // we filled the max len of bits.. what now?
} hid_decode_state;

typedef struct {
    uint8_t rawa[RAW_BUF_SIZE];    // The bit groups length captured raw.
    uint8_t rawb[RAW_BUF_SIZE];    // The bit groups length captured raw.
    uint8_t hexbuf[CARD_BUF_SIZE]; // manchester card data
    uint8_t startbit;
    hid_decode_state decode_state;
} RAWBUF_TYPE_HID;

//Card data
extern uint8_t cardbufbyte[CARD_BUF_BYTES_SIZE]; // decoded manchester data


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
