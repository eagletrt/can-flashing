#include "inc/flash_type.h"

#include <string.h>
#include <assert.h>

#include "can/lib/primary/primary_network.h"
#include "can/lib/secondary/secondary_network.h"

uint16_t tx_ids[FLASH_TYPE_COUNT];
uint16_t rx_ids[FLASH_TYPE_COUNT];
uint16_t jump_ids[FLASH_TYPE_COUNT];
uint16_t request_ids[FLASH_TYPE_COUNT];
uint16_t response_ids[FLASH_TYPE_COUNT];

char* flash_type_name(FLASH_TYPE value) {
  switch (value) {
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
    case FLASH_TYPE_ACQUISINATOR_0:
      return "ACQUISINATOR_0";
    case FLASH_TYPE_ACQUISINATOR_1:
      return "ACQUISINATOR_1";
    case FLASH_TYPE_ACQUISINATOR_2:
      return "ACQUISINATOR_2";
    case FLASH_TYPE_ACQUISINATOR_3:
      return "ACQUISINATOR_3";
    case FLASH_TYPE_ACQUISINATOR_4:
      return "ACQUISINATOR_4";
    case FLASH_TYPE_ACQUISINATOR_5:
      return "ACQUISINATOR_5";
    case FLASH_TYPE_ACQUISINATOR_6:
      return "ACQUISINATOR_6";
    case FLASH_TYPE_ACQUISINATOR_7:
      return "ACQUISINATOR_7";
    case FLASH_TYPE_ACQUISINATOR_8:
      return "ACQUISINATOR_8";
    case FLASH_TYPE_ACQUISINATOR_9:
      return "ACQUISINATOR_9";
    case FLASH_TYPE_ACQUISINATOR_10:
      return "ACQUISINATOR_10";
    case FLASH_TYPE_ACQUISINATOR_11:
      return "ACQUISINATOR_11";
    case FLASH_TYPE_ACQUISINATOR_12:
      return "ACQUISINATOR_12";
    case FLASH_TYPE_ACQUISINATOR_13:
      return "ACQUISINATOR_13";
    case FLASH_TYPE_ACQUISINATOR_14:
      return "ACQUISINATOR_14";
    case FLASH_TYPE_ACQUISINATOR_15:
      return "ACQUISINATOR_15";
    case FLASH_TYPE_ACQUISINATOR_16:
      return "ACQUISINATOR_16";
    case FLASH_TYPE_ACQUISINATOR_17:
      return "ACQUISINATOR_17";
    case FLASH_TYPE_ACQUISINATOR_18:
      return "ACQUISINATOR_18";
    case FLASH_TYPE_ACQUISINATOR_19:
      return "ACQUISINATOR_19";
    case FLASH_TYPE_ACQUISINATOR_20:
      return "ACQUISINATOR_20";
    case FLASH_TYPE_ACQUISINATOR_21:
      return "ACQUISINATOR_21";
    case FLASH_TYPE_ACQUISINATOR_22:
      return "ACQUISINATOR_22";
    case FLASH_TYPE_ACQUISINATOR_23:
      return "ACQUISINATOR_23";
    case FLASH_TYPE_ACQUISINATOR_24:
      return "ACQUISINATOR_24";
    case FLASH_TYPE_ACQUISINATOR_25:
      return "ACQUISINATOR_25";
    case FLASH_TYPE_ACQUISINATOR_26:
      return "ACQUISINATOR_26";
    case FLASH_TYPE_ACQUISINATOR_27:
      return "ACQUISINATOR_27";
    case FLASH_TYPE_ACQUISINATOR_28:
      return "ACQUISINATOR_28";
    case FLASH_TYPE_ACQUISINATOR_29:
      return "ACQUISINATOR_29";
    case FLASH_TYPE_ACQUISINATOR_30:
      return "ACQUISINATOR_30";
    case FLASH_TYPE_ACQUISINATOR_31:
      return "ACQUISINATOR_31";
    default:
      return "\0";
  }
}
FLASH_TYPE flash_type_value(const char* name) {
  if (strcmp(name, "BMS_HV") == 0) {
    return FLASH_TYPE_BMS_HV;
  } else if (strcmp(name, "BMS_CELLBOARD_0") == 0) {
    return FLASH_TYPE_BMS_CELLBOARD_0;
  } else if (strcmp(name, "BMS_CELLBOARD_1") == 0) {
    return FLASH_TYPE_BMS_CELLBOARD_1;
  } else if (strcmp(name, "BMS_CELLBOARD_2") == 0) {
    return FLASH_TYPE_BMS_CELLBOARD_2;
  } else if (strcmp(name, "BMS_CELLBOARD_3") == 0) {
    return FLASH_TYPE_BMS_CELLBOARD_3;
  } else if (strcmp(name, "BMS_CELLBOARD_4") == 0) {
    return FLASH_TYPE_BMS_CELLBOARD_4;
  } else if (strcmp(name, "BMS_CELLBOARD_5") == 0) {
    return FLASH_TYPE_BMS_CELLBOARD_5;
  } else if (strcmp(name, "BMS_CELLBOARD_ALL") == 0) {
    return FLASH_TYPE_BMS_CELLBOARD_ALL;
  } else if (strcmp(name, "BMS_LV") == 0) {
    return FLASH_TYPE_BMS_LV;
  } else if (strcmp(name, "BMS_LV_BLT") == 0) {
    return FLASH_TYPE_BMS_LV_BLT;
  } else if (strcmp(name, "ECU") == 0) {
    return FLASH_TYPE_ECU;
  } else if (strcmp(name, "STEERING") == 0) {
    return FLASH_TYPE_STEERING;
  } else if (strcmp(name, "ACQUISINATOR_0") == 0) {
    return FLASH_TYPE_ACQUISINATOR_0;
  } else if (strcmp(name, "ACQUISINATOR_1") == 0) {
    return FLASH_TYPE_ACQUISINATOR_1;
  } else if (strcmp(name, "ACQUISINATOR_2") == 0) {
    return FLASH_TYPE_ACQUISINATOR_2;
  } else if (strcmp(name, "ACQUISINATOR_3") == 0) {
    return FLASH_TYPE_ACQUISINATOR_3;
  } else if (strcmp(name, "ACQUISINATOR_4") == 0) {
    return FLASH_TYPE_ACQUISINATOR_4;
  } else if (strcmp(name, "ACQUISINATOR_5") == 0) {
    return FLASH_TYPE_ACQUISINATOR_5;
  } else if (strcmp(name, "ACQUISINATOR_6") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_6; 
  } else if (strcmp(name, "ACQUISINATOR_7") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_7; 
  } else if (strcmp(name, "ACQUISINATOR_8") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_8; 
  } else if (strcmp(name, "ACQUISINATOR_9") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_9; 
  } else if (strcmp(name, "ACQUISINATOR_10") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_10; 
  } else if (strcmp(name, "ACQUISINATOR_11") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_11; 
  } else if (strcmp(name, "ACQUISINATOR_12") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_12; 
  } else if (strcmp(name, "ACQUISINATOR_13") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_13; 
  } else if (strcmp(name, "ACQUISINATOR_14") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_14; 
  } else if (strcmp(name, "ACQUISINATOR_15") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_15; 
  } else if (strcmp(name, "ACQUISINATOR_16") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_16; 
  } else if (strcmp(name, "ACQUISINATOR_17") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_17; 
  } else if (strcmp(name, "ACQUISINATOR_18") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_18; 
  } else if (strcmp(name, "ACQUISINATOR_19") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_19; 
  } else if (strcmp(name, "ACQUISINATOR_20") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_20; 
  } else if (strcmp(name, "ACQUISINATOR_21") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_21; 
  } else if (strcmp(name, "ACQUISINATOR_22") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_22; 
  } else if (strcmp(name, "ACQUISINATOR_23") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_23; 
  } else if (strcmp(name, "ACQUISINATOR_24") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_24; 
  } else if (strcmp(name, "ACQUISINATOR_25") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_25; 
  } else if (strcmp(name, "ACQUISINATOR_26") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_26; 
  } else if (strcmp(name, "ACQUISINATOR_27") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_27; 
  } else if (strcmp(name, "ACQUISINATOR_28") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_28; 
  } else if (strcmp(name, "ACQUISINATOR_29") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_29; 
  } else if (strcmp(name, "ACQUISINATOR_30") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_30; 
  } else if (strcmp(name, "ACQUISINATOR_31") == 0) { 
    return  FLASH_TYPE_ACQUISINATOR_31; 
  }
  return FLASH_TYPE_COUNT;
}

void setup_flash_ids() {
  tx_ids[FLASH_TYPE_BMS_HV] = PRIMARY_HV_FLASH_MAINBOARD_RX_FRAME_ID;
  rx_ids[FLASH_TYPE_BMS_HV] = PRIMARY_HV_FLASH_MAINBOARD_TX_FRAME_ID;
  jump_ids[FLASH_TYPE_BMS_HV] = PRIMARY_HV_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_BMS_HV] = UINT16_MAX;
  response_ids[FLASH_TYPE_BMS_HV] = UINT16_MAX;

  tx_ids[FLASH_TYPE_BMS_CELLBOARD_0] = PRIMARY_HV_FLASH_CELLBOARD_0_RX_FRAME_ID;
  rx_ids[FLASH_TYPE_BMS_CELLBOARD_0] = PRIMARY_HV_FLASH_CELLBOARD_0_TX_FRAME_ID;
  jump_ids[FLASH_TYPE_BMS_CELLBOARD_0] = PRIMARY_HV_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_BMS_CELLBOARD_0] = UINT16_MAX;
  response_ids[FLASH_TYPE_BMS_CELLBOARD_0] = UINT16_MAX;

  tx_ids[FLASH_TYPE_BMS_CELLBOARD_1] = PRIMARY_HV_FLASH_CELLBOARD_1_RX_FRAME_ID;
  rx_ids[FLASH_TYPE_BMS_CELLBOARD_1] = PRIMARY_HV_FLASH_CELLBOARD_1_TX_FRAME_ID;
  jump_ids[FLASH_TYPE_BMS_CELLBOARD_1] = PRIMARY_HV_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_BMS_CELLBOARD_1] = UINT16_MAX;
  response_ids[FLASH_TYPE_BMS_CELLBOARD_1] = UINT16_MAX;

  tx_ids[FLASH_TYPE_BMS_CELLBOARD_2] = PRIMARY_HV_FLASH_CELLBOARD_2_RX_FRAME_ID;
  rx_ids[FLASH_TYPE_BMS_CELLBOARD_2] = PRIMARY_HV_FLASH_CELLBOARD_2_TX_FRAME_ID;
  jump_ids[FLASH_TYPE_BMS_CELLBOARD_2] = PRIMARY_HV_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_BMS_CELLBOARD_2] = UINT16_MAX;
  response_ids[FLASH_TYPE_BMS_CELLBOARD_2] = UINT16_MAX;

  tx_ids[FLASH_TYPE_BMS_CELLBOARD_3] = PRIMARY_HV_FLASH_CELLBOARD_3_RX_FRAME_ID;
  rx_ids[FLASH_TYPE_BMS_CELLBOARD_3] = PRIMARY_HV_FLASH_CELLBOARD_3_TX_FRAME_ID;
  jump_ids[FLASH_TYPE_BMS_CELLBOARD_3] = PRIMARY_HV_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_BMS_CELLBOARD_3] = UINT16_MAX;
  response_ids[FLASH_TYPE_BMS_CELLBOARD_3] = UINT16_MAX;

  tx_ids[FLASH_TYPE_BMS_CELLBOARD_4] = PRIMARY_HV_FLASH_CELLBOARD_4_RX_FRAME_ID;
  rx_ids[FLASH_TYPE_BMS_CELLBOARD_4] = PRIMARY_HV_FLASH_CELLBOARD_4_TX_FRAME_ID;
  jump_ids[FLASH_TYPE_BMS_CELLBOARD_4] = PRIMARY_HV_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_BMS_CELLBOARD_4] = UINT16_MAX;
  response_ids[FLASH_TYPE_BMS_CELLBOARD_4] = UINT16_MAX;

  tx_ids[FLASH_TYPE_BMS_CELLBOARD_5] = PRIMARY_HV_FLASH_CELLBOARD_5_RX_FRAME_ID;
  rx_ids[FLASH_TYPE_BMS_CELLBOARD_5] = PRIMARY_HV_FLASH_CELLBOARD_5_TX_FRAME_ID;
  jump_ids[FLASH_TYPE_BMS_CELLBOARD_5] = PRIMARY_HV_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_BMS_CELLBOARD_5] = UINT16_MAX;
  response_ids[FLASH_TYPE_BMS_CELLBOARD_5] = UINT16_MAX;

  tx_ids[FLASH_TYPE_BMS_CELLBOARD_ALL] = UINT16_MAX;
  rx_ids[FLASH_TYPE_BMS_CELLBOARD_ALL] = UINT16_MAX;
  jump_ids[FLASH_TYPE_BMS_CELLBOARD_ALL] = PRIMARY_HV_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_BMS_CELLBOARD_ALL] = UINT16_MAX;
  response_ids[FLASH_TYPE_BMS_CELLBOARD_ALL] = UINT16_MAX;

  tx_ids[FLASH_TYPE_BMS_LV] = PRIMARY_LV_FLASH_RX_FRAME_ID;
  rx_ids[FLASH_TYPE_BMS_LV] = PRIMARY_LV_FLASH_TX_FRAME_ID;
  jump_ids[FLASH_TYPE_BMS_LV] = PRIMARY_LV_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_BMS_LV] = PRIMARY_LV_CAN_FLASH_REQ_TLM_FRAME_ID;
  response_ids[FLASH_TYPE_BMS_LV] = PRIMARY_LV_CAN_FLASH_ACK_FRAME_ID;

  tx_ids[FLASH_TYPE_BMS_LV_BLT] = PRIMARY_LV_FLASH_RX_FRAME_ID;
  rx_ids[FLASH_TYPE_BMS_LV_BLT] = PRIMARY_LV_FLASH_TX_FRAME_ID;
  jump_ids[FLASH_TYPE_BMS_LV_BLT] = PRIMARY_LV_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_BMS_LV_BLT] = UINT16_MAX;
  response_ids[FLASH_TYPE_BMS_LV_BLT] = UINT16_MAX;

  tx_ids[FLASH_TYPE_ECU] = PRIMARY_ECU_FLASH_RX_FRAME_ID;
  rx_ids[FLASH_TYPE_ECU] = PRIMARY_ECU_FLASH_TX_FRAME_ID;
  jump_ids[FLASH_TYPE_ECU] = PRIMARY_ECU_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ECU] = UINT16_MAX;
  response_ids[FLASH_TYPE_ECU] = UINT16_MAX;

  tx_ids[FLASH_TYPE_STEERING] = PRIMARY_STEERING_WHEEL_FLASH_RX_FRAME_ID;
  rx_ids[FLASH_TYPE_STEERING] = PRIMARY_STEERING_WHEEL_FLASH_TX_FRAME_ID;
  jump_ids[FLASH_TYPE_STEERING] = PRIMARY_STEERING_WHEEL_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_STEERING] = UINT16_MAX;
  response_ids[FLASH_TYPE_STEERING] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_0] = SECONDARY_ACQUISINATOR_FLASH_0_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_0] = SECONDARY_ACQUISINATOR_FLASH_0_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_0] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_0] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_0] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_1] = SECONDARY_ACQUISINATOR_FLASH_1_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_1] = SECONDARY_ACQUISINATOR_FLASH_1_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_1] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_1] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_1] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_2] = SECONDARY_ACQUISINATOR_FLASH_2_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_2] = SECONDARY_ACQUISINATOR_FLASH_2_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_2] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_2] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_2] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_3] = SECONDARY_ACQUISINATOR_FLASH_3_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_3] = SECONDARY_ACQUISINATOR_FLASH_3_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_3] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_3] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_3] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_4] = SECONDARY_ACQUISINATOR_FLASH_4_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_4] = SECONDARY_ACQUISINATOR_FLASH_4_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_4] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_4] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_4] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_5] = SECONDARY_ACQUISINATOR_FLASH_5_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_5] = SECONDARY_ACQUISINATOR_FLASH_5_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_5] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_5] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_5] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_6] = SECONDARY_ACQUISINATOR_FLASH_6_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_6] = SECONDARY_ACQUISINATOR_FLASH_6_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_6] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_6] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_6] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_7] = SECONDARY_ACQUISINATOR_FLASH_7_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_7] = SECONDARY_ACQUISINATOR_FLASH_7_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_7] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_7] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_7] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_8] = SECONDARY_ACQUISINATOR_FLASH_8_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_8] = SECONDARY_ACQUISINATOR_FLASH_8_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_8] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_8] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_8] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_9] = SECONDARY_ACQUISINATOR_FLASH_9_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_9] = SECONDARY_ACQUISINATOR_FLASH_9_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_9] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_9] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_9] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_10] = SECONDARY_ACQUISINATOR_FLASH_10_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_10] = SECONDARY_ACQUISINATOR_FLASH_10_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_10] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_10] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_10] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_11] = SECONDARY_ACQUISINATOR_FLASH_11_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_11] = SECONDARY_ACQUISINATOR_FLASH_11_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_11] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_11] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_11] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_12] = SECONDARY_ACQUISINATOR_FLASH_12_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_12] = SECONDARY_ACQUISINATOR_FLASH_12_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_12] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_12] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_12] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_13] = SECONDARY_ACQUISINATOR_FLASH_13_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_13] = SECONDARY_ACQUISINATOR_FLASH_13_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_13] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_13] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_13] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_14] = SECONDARY_ACQUISINATOR_FLASH_14_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_14] = SECONDARY_ACQUISINATOR_FLASH_14_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_14] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_14] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_14] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_15] = SECONDARY_ACQUISINATOR_FLASH_15_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_15] = SECONDARY_ACQUISINATOR_FLASH_15_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_15] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_15] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_15] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_16] = SECONDARY_ACQUISINATOR_FLASH_16_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_16] = SECONDARY_ACQUISINATOR_FLASH_16_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_16] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_16] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_16] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_17] = SECONDARY_ACQUISINATOR_FLASH_17_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_17] = SECONDARY_ACQUISINATOR_FLASH_17_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_17] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_17] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_17] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_18] = SECONDARY_ACQUISINATOR_FLASH_18_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_18] = SECONDARY_ACQUISINATOR_FLASH_18_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_18] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_18] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_18] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_19] = SECONDARY_ACQUISINATOR_FLASH_19_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_19] = SECONDARY_ACQUISINATOR_FLASH_19_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_19] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_19] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_19] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_20] = SECONDARY_ACQUISINATOR_FLASH_20_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_20] = SECONDARY_ACQUISINATOR_FLASH_20_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_20] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_20] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_20] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_21] = SECONDARY_ACQUISINATOR_FLASH_21_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_21] = SECONDARY_ACQUISINATOR_FLASH_21_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_21] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_21] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_21] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_22] = SECONDARY_ACQUISINATOR_FLASH_22_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_22] = SECONDARY_ACQUISINATOR_FLASH_22_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_22] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_22] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_22] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_23] = SECONDARY_ACQUISINATOR_FLASH_23_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_23] = SECONDARY_ACQUISINATOR_FLASH_23_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_23] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_23] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_23] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_24] = SECONDARY_ACQUISINATOR_FLASH_24_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_24] = SECONDARY_ACQUISINATOR_FLASH_24_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_24] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_24] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_24] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_25] = SECONDARY_ACQUISINATOR_FLASH_25_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_25] = SECONDARY_ACQUISINATOR_FLASH_25_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_25] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_25] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_25] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_26] = SECONDARY_ACQUISINATOR_FLASH_26_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_26] = SECONDARY_ACQUISINATOR_FLASH_26_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_26] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_26] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_26] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_27] = SECONDARY_ACQUISINATOR_FLASH_27_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_27] = SECONDARY_ACQUISINATOR_FLASH_27_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_27] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_27] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_27] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_28] = SECONDARY_ACQUISINATOR_FLASH_28_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_28] = SECONDARY_ACQUISINATOR_FLASH_28_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_28] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_28] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_28] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_29] = SECONDARY_ACQUISINATOR_FLASH_29_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_29] = SECONDARY_ACQUISINATOR_FLASH_29_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_29] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_29] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_29] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_30] = SECONDARY_ACQUISINATOR_FLASH_30_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_30] = SECONDARY_ACQUISINATOR_FLASH_30_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_30] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_30] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_30] = UINT16_MAX;

  rx_ids[FLASH_TYPE_ACQUISINATOR_31] = SECONDARY_ACQUISINATOR_FLASH_31_TX_FRAME_ID;
  tx_ids[FLASH_TYPE_ACQUISINATOR_31] = SECONDARY_ACQUISINATOR_FLASH_31_RX_FRAME_ID;
  jump_ids[FLASH_TYPE_ACQUISINATOR_31] = SECONDARY_ACQUISINATOR_JMP_TO_BLT_FRAME_ID;
  request_ids[FLASH_TYPE_ACQUISINATOR_31] = UINT16_MAX;
  response_ids[FLASH_TYPE_ACQUISINATOR_31] = UINT16_MAX;
}


bool is_can_primary(FLASH_TYPE flash_device) {
  switch (flash_device) {
  case FLASH_TYPE_BMS_CELLBOARD_0:
  case FLASH_TYPE_BMS_CELLBOARD_1:
  case FLASH_TYPE_BMS_CELLBOARD_2:
  case FLASH_TYPE_BMS_CELLBOARD_3:
  case FLASH_TYPE_BMS_CELLBOARD_4:
  case FLASH_TYPE_BMS_CELLBOARD_5:
  case FLASH_TYPE_BMS_CELLBOARD_ALL:
  case FLASH_TYPE_BMS_LV:
  case FLASH_TYPE_BMS_LV_BLT:
  case FLASH_TYPE_ECU:
  case FLASH_TYPE_STEERING:
    return true;
  case FLASH_TYPE_ACQUISINATOR_0:
  case FLASH_TYPE_ACQUISINATOR_1:
  case FLASH_TYPE_ACQUISINATOR_2:
  case FLASH_TYPE_ACQUISINATOR_3:
  case FLASH_TYPE_ACQUISINATOR_4:
  case FLASH_TYPE_ACQUISINATOR_5:
  case FLASH_TYPE_ACQUISINATOR_6:
  case FLASH_TYPE_ACQUISINATOR_7:
  case FLASH_TYPE_ACQUISINATOR_8:
  case FLASH_TYPE_ACQUISINATOR_9:
  case FLASH_TYPE_ACQUISINATOR_10:
  case FLASH_TYPE_ACQUISINATOR_11:
  case FLASH_TYPE_ACQUISINATOR_12:
  case FLASH_TYPE_ACQUISINATOR_13:
  case FLASH_TYPE_ACQUISINATOR_14:
  case FLASH_TYPE_ACQUISINATOR_15:
  case FLASH_TYPE_ACQUISINATOR_16:
  case FLASH_TYPE_ACQUISINATOR_17:
  case FLASH_TYPE_ACQUISINATOR_18:
  case FLASH_TYPE_ACQUISINATOR_19:
  case FLASH_TYPE_ACQUISINATOR_20:
  case FLASH_TYPE_ACQUISINATOR_21:
  case FLASH_TYPE_ACQUISINATOR_22:
  case FLASH_TYPE_ACQUISINATOR_23:
  case FLASH_TYPE_ACQUISINATOR_24:
  case FLASH_TYPE_ACQUISINATOR_25:
  case FLASH_TYPE_ACQUISINATOR_26:
  case FLASH_TYPE_ACQUISINATOR_27:
  case FLASH_TYPE_ACQUISINATOR_28:
  case FLASH_TYPE_ACQUISINATOR_29:
  case FLASH_TYPE_ACQUISINATOR_30:
  case FLASH_TYPE_ACQUISINATOR_31:
    return false;
  default:
      assert(false && "Can interface is not specified");
  }
}

