#ifndef TARIFF_H
#define TARIFF_H

#include <stdint.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

#define TARIFF_TABLE_ITEMS (24 >> 1)
#define TARIFF_ZONE_MAX (2*24)

#pragma pack(push, 1)
typedef struct {
    uint8_t hh0 :2; //����� ������ //half-hour �������
    uint8_t hh1 :2; //����� ������ //half-hour �������
    uint8_t hh2 :2; //����� ������ //half-hour �������
    uint8_t hh3 :2; //����� ������ //half-hour �������
} TARIFF_2hour; // 2 ����

typedef struct {
    TARIFF_2hour h2[TARIFF_TABLE_ITEMS];
} TARIFF_TABLE;
#pragma pack(pop)

extern TARIFF_TABLE tariff_table;

void TARIFF_init();
uint8_t TARIFF_set(void * data, uint8_t data_len);

// z = [0..47] �������
uint8_t TARIFF_from_zone(uint8_t z);
uint8_t TARIFF_from_time(uint32_t t);
uint8_t TARIFF_is_use(uint8_t tariff);

void TARIFF_set_curr_time(uint32_t t);
uint8_t TARIFF_get_curr();

#ifdef __cplusplus
}
#endif

#endif // TARIFF_H
