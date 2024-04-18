#ifndef _FLASH_TYPE_H_
#define _FLASH_TYPE_H_

#include <inttypes.h>
#include <stdbool.h>

typedef enum {
  FLASH_TYPE_BMS_HV = 0,
  FLASH_TYPE_BMS_CELLBOARD_0,
  FLASH_TYPE_BMS_CELLBOARD_1,
  FLASH_TYPE_BMS_CELLBOARD_2,
  FLASH_TYPE_BMS_CELLBOARD_3,
  FLASH_TYPE_BMS_CELLBOARD_4,
  FLASH_TYPE_BMS_CELLBOARD_5,
  FLASH_TYPE_BMS_CELLBOARD_ALL,
  FLASH_TYPE_BMS_LV,
  FLASH_TYPE_BMS_LV_BLT,
  FLASH_TYPE_ECU,
  FLASH_TYPE_STEERING,
  FLASH_TYPE_ACQUISINATOR_0,
  FLASH_TYPE_ACQUISINATOR_1,
  FLASH_TYPE_ACQUISINATOR_2,
  FLASH_TYPE_ACQUISINATOR_3,
  FLASH_TYPE_ACQUISINATOR_4,
  FLASH_TYPE_ACQUISINATOR_5,

  FLASH_TYPE_COUNT
}FLASH_TYPE;

char* flash_type_name(FLASH_TYPE value);
FLASH_TYPE flash_type_value(const char* name);

extern uint16_t tx_ids[FLASH_TYPE_COUNT];
extern uint16_t rx_ids[FLASH_TYPE_COUNT];
extern uint16_t jump_ids[FLASH_TYPE_COUNT];
extern uint16_t request_ids[FLASH_TYPE_COUNT];
extern uint16_t response_ids[FLASH_TYPE_COUNT];
void setup_flash_ids();
bool is_can_primary(FLASH_TYPE flash_device);

#endif // _FLASH_TYPE_H_
