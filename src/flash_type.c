#include "inc/flash_type.h"
#include "can/lib/primary/primary_network.h"

#include <string.h>

uint16_t tx_ids[FLASH_TYPE_COUNT];
uint16_t rx_ids[FLASH_TYPE_COUNT];
uint16_t jump_ids[FLASH_TYPE_COUNT];
uint16_t request_ids[FLASH_TYPE_COUNT];
uint16_t response_ids[FLASH_TYPE_COUNT];

char* flash_type_name(FLASH_TYPE value){
  switch (value){
    case FLASH_TYPE_BMS_HV:
      return "BMS_HV";
    case FLASH_TYPE_BMS_CELLBOARD_0:
      return "BMS_CELLBOARD_0";
    case FLASH_TYPE_BMS_CELLBOARD_1:
      return "BMS_CELLBOARD_1";
    case FLASH_TYPE_BMS_CELLBOARD_2:
      return "BMS_CELLBOARD_2";
    case FLASH_TYPE_BMS_CELLBOARD_3:
      return "BMS_CELLBOARD_3";
    case FLASH_TYPE_BMS_CELLBOARD_4:
      return "BMS_CELLBOARD_4";
    case FLASH_TYPE_BMS_CELLBOARD_5:
      return "BMS_CELLBOARD_5";
    case FLASH_TYPE_BMS_CELLBOARD_ALL:
      return "BMS_CELLBOARD_ALL";
    case FLASH_TYPE_BMS_LV:
      return "BMS_LV";
    case FLASH_TYPE_BMS_LV_BLT:
      return "BMS_LV_BLT";
    case FLASH_TYPE_ECU:
      return "ECU";
    case FLASH_TYPE_STEERING:
      return "STEERING";
    default:
      return "\0";
  }
}
FLASH_TYPE flash_type_value(const char* name){
  if(strcmp(name, "BMS_HV") == 0){
    return FLASH_TYPE_BMS_HV;
  }else if (strcmp(name, "BMS_CELLBOARD_0") == 0){
    return FLASH_TYPE_BMS_CELLBOARD_0;
  }else if (strcmp(name, "BMS_CELLBOARD_1") == 0){
    return FLASH_TYPE_BMS_CELLBOARD_1;
  }else if (strcmp(name, "BMS_CELLBOARD_2") == 0){
    return FLASH_TYPE_BMS_CELLBOARD_2;
  }else if (strcmp(name, "BMS_CELLBOARD_3") == 0){
    return FLASH_TYPE_BMS_CELLBOARD_3;
  }else if (strcmp(name, "BMS_CELLBOARD_4") == 0){
    return FLASH_TYPE_BMS_CELLBOARD_4;
  }else if (strcmp(name, "BMS_CELLBOARD_5") == 0){
    return FLASH_TYPE_BMS_CELLBOARD_5;
  }else if (strcmp(name, "BMS_CELLBOARD_ALL") == 0){
    return FLASH_TYPE_BMS_CELLBOARD_ALL;
  }else if (strcmp(name, "BMS_LV") == 0){
    return FLASH_TYPE_BMS_LV;
  }else if (strcmp(name, "BMS_LV_BLT") == 0){
    return FLASH_TYPE_BMS_LV_BLT;
  }else if (strcmp(name, "ECU") == 0){
    return FLASH_TYPE_ECU;
  }else if (strcmp(name, "STEERING") == 0){
    return FLASH_TYPE_STEERING;
  }
  return FLASH_TYPE_COUNT;
}

void setup_flash_ids(){
  tx_ids[FLASH_TYPE_BMS_HV] = PRIMARY_FLASH_BMS_HV_RX_FRAME_ID;
  rx_ids[FLASH_TYPE_BMS_HV] = PRIMARY_FLASH_BMS_HV_TX_FRAME_ID;
  jump_ids[FLASH_TYPE_BMS_HV] = PRIMARY_BMS_HV_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_BMS_HV] = UINT16_MAX;
  response_ids[FLASH_TYPE_BMS_HV] = UINT16_MAX;

  tx_ids[FLASH_TYPE_BMS_CELLBOARD_0] = PRIMARY_FLASH_CELLBOARD_0_RX_FRAME_ID;
  rx_ids[FLASH_TYPE_BMS_CELLBOARD_0] = PRIMARY_FLASH_CELLBOARD_0_TX_FRAME_ID;
  jump_ids[FLASH_TYPE_BMS_CELLBOARD_0] = PRIMARY_HV_CAN_FORWARD_FRAME_ID;
  request_ids[FLASH_TYPE_BMS_CELLBOARD_0] = UINT16_MAX;
  response_ids[FLASH_TYPE_BMS_CELLBOARD_0] = UINT16_MAX;

  tx_ids[FLASH_TYPE_BMS_CELLBOARD_1] = PRIMARY_FLASH_CELLBOARD_1_RX_FRAME_ID;
  rx_ids[FLASH_TYPE_BMS_CELLBOARD_1] = PRIMARY_FLASH_CELLBOARD_1_TX_FRAME_ID;
  jump_ids[FLASH_TYPE_BMS_CELLBOARD_1] = PRIMARY_HV_CAN_FORWARD_FRAME_ID;
  request_ids[FLASH_TYPE_BMS_CELLBOARD_1] = UINT16_MAX;
  response_ids[FLASH_TYPE_BMS_CELLBOARD_1] = UINT16_MAX;

  tx_ids[FLASH_TYPE_BMS_CELLBOARD_2] = PRIMARY_FLASH_CELLBOARD_2_RX_FRAME_ID;
  rx_ids[FLASH_TYPE_BMS_CELLBOARD_2] = PRIMARY_FLASH_CELLBOARD_2_TX_FRAME_ID;
  jump_ids[FLASH_TYPE_BMS_CELLBOARD_2] = PRIMARY_HV_CAN_FORWARD_FRAME_ID;
  request_ids[FLASH_TYPE_BMS_CELLBOARD_2] = UINT16_MAX;
  response_ids[FLASH_TYPE_BMS_CELLBOARD_2] = UINT16_MAX;

  tx_ids[FLASH_TYPE_BMS_CELLBOARD_3] = PRIMARY_FLASH_CELLBOARD_3_RX_FRAME_ID;
  rx_ids[FLASH_TYPE_BMS_CELLBOARD_3] = PRIMARY_FLASH_CELLBOARD_3_TX_FRAME_ID;
  jump_ids[FLASH_TYPE_BMS_CELLBOARD_3] = PRIMARY_HV_CAN_FORWARD_FRAME_ID;
  request_ids[FLASH_TYPE_BMS_CELLBOARD_3] = UINT16_MAX;
  response_ids[FLASH_TYPE_BMS_CELLBOARD_3] = UINT16_MAX;

  tx_ids[FLASH_TYPE_BMS_CELLBOARD_4] = PRIMARY_FLASH_CELLBOARD_4_RX_FRAME_ID;
  rx_ids[FLASH_TYPE_BMS_CELLBOARD_4] = PRIMARY_FLASH_CELLBOARD_4_TX_FRAME_ID;
  jump_ids[FLASH_TYPE_BMS_CELLBOARD_4] = PRIMARY_HV_CAN_FORWARD_FRAME_ID;
  request_ids[FLASH_TYPE_BMS_CELLBOARD_4] = UINT16_MAX;
  response_ids[FLASH_TYPE_BMS_CELLBOARD_4] = UINT16_MAX;

  tx_ids[FLASH_TYPE_BMS_CELLBOARD_5] = PRIMARY_FLASH_CELLBOARD_5_RX_FRAME_ID;
  rx_ids[FLASH_TYPE_BMS_CELLBOARD_5] = PRIMARY_FLASH_CELLBOARD_5_TX_FRAME_ID;
  jump_ids[FLASH_TYPE_BMS_CELLBOARD_5] = PRIMARY_HV_CAN_FORWARD_FRAME_ID;
  request_ids[FLASH_TYPE_BMS_CELLBOARD_5] = UINT16_MAX;
  response_ids[FLASH_TYPE_BMS_CELLBOARD_5] = UINT16_MAX;

  tx_ids[FLASH_TYPE_BMS_CELLBOARD_ALL] = UINT16_MAX;
  rx_ids[FLASH_TYPE_BMS_CELLBOARD_ALL] = UINT16_MAX;
  jump_ids[FLASH_TYPE_BMS_CELLBOARD_ALL] = PRIMARY_HV_CAN_FORWARD_FRAME_ID;
  request_ids[FLASH_TYPE_BMS_CELLBOARD_ALL] = UINT16_MAX;
  response_ids[FLASH_TYPE_BMS_CELLBOARD_ALL] = UINT16_MAX;
  
  tx_ids[FLASH_TYPE_BMS_LV] = PRIMARY_FLASH_BMS_LV_RX_FRAME_ID;
  rx_ids[FLASH_TYPE_BMS_LV] = PRIMARY_FLASH_BMS_LV_TX_FRAME_ID;
  jump_ids[FLASH_TYPE_BMS_LV] = PRIMARY_BMS_LV_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_BMS_LV] = PRIMARY_LV_CAN_FLASH_REQ_FRAME_ID;
  response_ids[FLASH_TYPE_BMS_LV] = PRIMARY_LV_CAN_FLASH_ACK_FRAME_ID;

  tx_ids[FLASH_TYPE_BMS_LV_BLT] = PRIMARY_FLASH_BMS_LV_RX_FRAME_ID;
  rx_ids[FLASH_TYPE_BMS_LV_BLT] = PRIMARY_FLASH_BMS_LV_TX_FRAME_ID;
  jump_ids[FLASH_TYPE_BMS_LV_BLT] = PRIMARY_BMS_LV_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_BMS_LV_BLT] = UINT16_MAX;
  response_ids[FLASH_TYPE_BMS_LV_BLT] = UINT16_MAX;

  tx_ids[FLASH_TYPE_ECU] = PRIMARY_FLASH_ECU_RX_FRAME_ID;
  rx_ids[FLASH_TYPE_ECU] = PRIMARY_FLASH_ECU_TX_FRAME_ID;
  jump_ids[FLASH_TYPE_ECU] = PRIMARY_ECU_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ECU] = UINT16_MAX;
  response_ids[FLASH_TYPE_ECU] = UINT16_MAX;

  tx_ids[FLASH_TYPE_STEERING] = PRIMARY_FLASH_STEERING_RX_FRAME_ID;
  rx_ids[FLASH_TYPE_STEERING] = PRIMARY_FLASH_STEERING_TX_FRAME_ID;
  jump_ids[FLASH_TYPE_STEERING] = PRIMARY_STEERING_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_STEERING] = UINT16_MAX;
  response_ids[FLASH_TYPE_STEERING] = UINT16_MAX;
}
