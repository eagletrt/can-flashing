/******************************************************************************
Finite State Machine
Project: can-flashing
Description: G

Generated by gv_fsm ruby gem, see https://rubygems.org/gems/gv_fsm
gv_fsm version 0.3.3
Generation date: 2023-06-22 12:56:27 +0200
Generated from: fsm.dot
The finite state machine has:
  8 states
  0 transition functions
******************************************************************************/
#include "inc/flash_fsm.h"

#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

#include "can/lib/primary/primary_network.h"

// SEARCH FOR Your Code Here FOR CODE INSERTION POINTS!

// GLOBALS
// State human-readable names
const char *state_names[] = {"start", "setup_can",  "error",    "flash_request",
                             "end",   "flash_wait", "flashing", "success"};

// List of state functions
state_func_t *const state_table[NUM_STATES] = {
    do_start,          // in state start
    do_setup_can,      // in state setup_can
    do_error,          // in state error
    do_flash_request,  // in state flash_request
    do_end,            // in state end
    do_flash_wait,     // in state flash_wait
    do_flashing,       // in state flashing
    do_success,        // in state success
};
// No transition functions

/*  ____  _        _
 * / ___|| |_ __ _| |_ ___
 * \___ \| __/ _` | __/ _ \
 *  ___) | || (_| | ||  __/
 * |____/ \__\__,_|\__\___|
 *
 *   __                  _   _
 *  / _|_   _ _ __   ___| |_(_) ___  _ __  ___
 * | |_| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
 * |  _| |_| | | | | (__| |_| | (_) | | | \__ \
 * |_|  \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
 */

// Function to be executed in state start
// valid return states: STATE_SETUP_CAN
state_t do_start(state_data_t *data) {
  state_t next_state = STATE_SETUP_CAN;

  printf("[FSM] In state start\n");
  /* Your Code Here */

  switch (next_state) {
    case STATE_SETUP_CAN:
      break;
    default:
      printf("[FSM] Cannot pass from start to %s, remaining in this state\n",
             state_names[next_state]);
      next_state = NO_CHANGE;
  }

  return next_state;
}

// Function to be executed in state setup_can
// valid return states: STATE_ERROR, STATE_FLASH_REQUEST
state_t do_setup_can(state_data_t *data) {
  state_t next_state = STATE_ERROR;

  printf("[FSM] In state setup_can\n");
  /* Your Code Here */

  can_init("can1", &data->can);

  if (can_open_socket(&data->can) < 0)
    next_state = STATE_ERROR;
  else
    next_state = STATE_FLASH_REQUEST;

  switch (next_state) {
    case STATE_ERROR:
    case STATE_FLASH_REQUEST:
      break;
    default:
      printf(
          "[FSM] Cannot pass from setup_can to %s, remaining in this state\n",
          state_names[next_state]);
      next_state = NO_CHANGE;
  }

  return next_state;
}

// Function to be executed in state error
// valid return states: STATE_END
state_t do_error(state_data_t *data) {
  state_t next_state = STATE_END;

  printf("[FSM] In state error\n");
  /* Your Code Here */

  switch (next_state) {
    case STATE_END:
      break;
    default:
      printf("[FSM] Cannot pass from error to %s, remaining in this state\n",
             state_names[next_state]);
      next_state = NO_CHANGE;
  }

  return next_state;
}

// Function to be executed in state flash_request
// valid return states: STATE_ERROR, STATE_FLASH_WAIT
state_t do_flash_request(state_data_t *data) {
  state_t next_state = STATE_ERROR;

  printf("[FSM] In state flash_request\n");
  /* Your Code Here */
  if (request_ids[data->flash_device] != UINT16_MAX) {
    uint8_t frame[1];
    for (int i = 0; i < 10; i++) {
      if (can_send(request_ids[data->flash_device], (char *)frame, 1,
                   &data->can) <= 0)
        next_state = STATE_ERROR;
      else
        next_state = STATE_FLASH_WAIT;
      usleep(100);
    }
  } else {
    printf("[FSM] No flash_request procedure needed.\n");
    next_state = STATE_FLASHING;
  }

  switch (next_state) {
    case STATE_ERROR:
    case STATE_FLASHING:
    case STATE_FLASH_WAIT:
      break;
    default:
      printf(
          "[FSM] Cannot pass from flash_request to %s, remaining in this "
          "state\n",
          state_names[next_state]);
      next_state = NO_CHANGE;
  }

  return next_state;
}

// Function to be executed in state end
// valid return states: NO_CHANGE
state_t do_end(state_data_t *data) {
  state_t next_state = NO_CHANGE;

  printf("[FSM] In state end\n");
  /* Your Code Here */

  switch (next_state) {
    case NO_CHANGE:
      break;
    default:
      printf("[FSM] Cannot pass from end to %s, remaining in this state\n",
             state_names[next_state]);
      next_state = NO_CHANGE;
  }

  return next_state;
}

// Function to be executed in state flash_wait
// valid return states: NO_CHANGE, STATE_ERROR, STATE_FLASH_WAIT, STATE_FLASHING
state_t do_flash_wait(state_data_t *data) {
  state_t next_state = NO_CHANGE;
  double interval;
  static struct timeval t2, t1 = {.tv_sec = 0, .tv_usec = 0};
  gettimeofday(&t2, NULL);

  interval = (t2.tv_sec - t1.tv_sec) * 1000.0;
  interval += (t2.tv_usec - t1.tv_usec) / 1000.0;

  if (t1.tv_sec == 0 && t1.tv_usec == 0) {
    t1 = t2;
  } else if (interval >= 1e3) {
    next_state = STATE_ERROR;
    goto end;
  }

  printf("[FSM] In state flash_wait\n");
  /* Your Code Here */
  struct can_frame frame;

  if (can_receive(&frame, &data->can) < 0) {
    next_state = STATE_ERROR;
    goto end;
  }
  if (response_ids[data->flash_device] == UINT16_MAX) {
    next_state = STATE_FLASHING;
    goto end;
  }
  if (frame.can_id != response_ids[data->flash_device]) {
    next_state = NO_CHANGE;
    goto end;
  }

  // primary_lv_can_flash_ack_t ack;
  // primary_lv_can_flash_ack_unpack(&ack, frame.data, frame.can_dlc);
  // if (ack.response == primary_lv_can_flash_ack_response_preparing_to_flash) {
  //   next_state = NO_CHANGE;
  // } else if (ack.response == primary_lv_can_flash_ack_response_FLASH) {
  //   next_state = STATE_FLASHING;
  // } else if (ack.response == primary_lv_can_flash_ack_response_NO_FLASH) {
  //   next_state = STATE_ERROR;
  // } else {
  //   next_state = STATE_ERROR;
  // }

end:
  switch (next_state) {
    case NO_CHANGE:
    case STATE_ERROR:
    case STATE_FLASH_WAIT:
    case STATE_FLASHING:
      break;
    default:
      printf(
          "[FSM] Cannot pass from flash_wait to %s, remaining in this state\n",
          state_names[next_state]);
      next_state = NO_CHANGE;
  }

  return next_state;
}

// Function to be executed in state flashing
// valid return states: STATE_ERROR, STATE_SUCCESS
state_t do_flashing(state_data_t *data) {
  state_t next_state = STATE_ERROR;

  printf("[FSM] In state flashing\n");
  /* Your Code Here */
  if (jump_ids[data->flash_device] == UINT16_MAX) {
    next_state = STATE_ERROR;
    goto end;
  }

  uint8_t message_data[8] = {0};
  if (data->flash_device == FLASH_TYPE_BMS_HV) {
    primary_hv_jmp_to_blt_converted_t pack_conv;
    pack_conv.cellboard_id = 0;
    pack_conv.forward = false;
    primary_hv_jmp_to_blt_t pack_raw;
    primary_hv_jmp_to_blt_conversion_to_raw_struct(&pack_raw, &pack_conv);
    primary_hv_jmp_to_blt_pack(message_data, &pack_raw,
                               PRIMARY_HV_JMP_TO_BLT_BYTE_SIZE);
  } else if (data->flash_device == FLASH_TYPE_BMS_CELLBOARD_0 ||
             data->flash_device == FLASH_TYPE_BMS_CELLBOARD_1 ||
             data->flash_device == FLASH_TYPE_BMS_CELLBOARD_2 ||
             data->flash_device == FLASH_TYPE_BMS_CELLBOARD_3 ||
             data->flash_device == FLASH_TYPE_BMS_CELLBOARD_4 ||
             data->flash_device == FLASH_TYPE_BMS_CELLBOARD_5) {
    primary_hv_jmp_to_blt_converted_t pack_conv;
    pack_conv.cellboard_id = (data->flash_device - FLASH_TYPE_BMS_CELLBOARD_0);
    pack_conv.forward = true;
    primary_hv_jmp_to_blt_t pack_raw;
    primary_hv_jmp_to_blt_conversion_to_raw_struct(&pack_raw, &pack_conv);
    primary_hv_jmp_to_blt_pack(message_data, &pack_raw,
                               PRIMARY_HV_JMP_TO_BLT_BYTE_SIZE);
  }
  can_send(jump_ids[data->flash_device], (char *)message_data, 8, &data->can);

  // bootcommander
  char buff[COMMAND_BUFER_SIZE];
  snprintf(buff, COMMAND_BUFER_SIZE,
           "/home/control/can-test/Host/bootcommander -t=xcp_can -d=%s "
           "-b=1000000 -tid=%x -rid=%x %s",
           can_get_device(&data->can), tx_ids[data->flash_device],
           rx_ids[data->flash_device], data->binary_path);
  printf("[FSM] launching bootcommander:\n%s\n", buff);
  fflush(stdout);
  usleep(1000);
  system(buff);

  if (data->flash_device == FLASH_TYPE_BMS_CELLBOARD_0 ||
      data->flash_device == FLASH_TYPE_BMS_CELLBOARD_1 ||
      data->flash_device == FLASH_TYPE_BMS_CELLBOARD_2 ||
      data->flash_device == FLASH_TYPE_BMS_CELLBOARD_3 ||
      data->flash_device == FLASH_TYPE_BMS_CELLBOARD_4 ||
      data->flash_device == FLASH_TYPE_BMS_CELLBOARD_5) {
    message_data[0] = 0x00;
    can_send(jump_ids[data->flash_device], (char *)message_data, 8, &data->can);
  }

end:
  switch (next_state) {
    case STATE_ERROR:
    case STATE_SUCCESS:
      break;
    default:
      printf("[FSM] Cannot pass from flashing to %s, remaining in this state\n",
             state_names[next_state]);
      next_state = NO_CHANGE;
  }

  return next_state;
}

// Function to be executed in state success
// valid return states: STATE_END
state_t do_success(state_data_t *data) {
  state_t next_state = STATE_END;

  printf("[FSM] In state success\n");
  /* Your Code Here */

  switch (next_state) {
    case STATE_END:
      break;
    default:
      printf("[FSM] Cannot pass from success to %s, remaining in this state\n",
             state_names[next_state]);
      next_state = NO_CHANGE;
  }

  return next_state;
}

/*  ____  _        _
 * / ___|| |_ __ _| |_ ___
 * \___ \| __/ _` | __/ _ \
 *  ___) | || (_| | ||  __/
 * |____/ \__\__,_|\__\___|
 *
 *
 *  _ __ ___   __ _ _ __   __ _  __ _  ___ _ __
 * | '_ ` _ \ / _` | '_ \ / _` |/ _` |/ _ \ '__|
 * | | | | | | (_| | | | | (_| | (_| |  __/ |
 * |_| |_| |_|\__,_|_| |_|\__,_|\__, |\___|_|
 *                              |___/
 */

state_t run_state(state_t cur_state, state_data_t *data) {
  state_t new_state = state_table[cur_state](data);
  if (new_state == NO_CHANGE) new_state = cur_state;
  return new_state == NO_CHANGE ? cur_state : new_state;
};

#ifdef TEST_MAIN
#include <unistd.h>
int main() {
  state_t cur_state = STATE_START;
  openlog("SM", LOG_PID | LOG_PERROR, LOG_USER);
  printf("Starting SM");
  do {
    cur_state = run_state(cur_state, NULL);
    sleep(1);
  } while (cur_state != STATE_END);
  run_state(cur_state, NULL);
  return 0;
}
#endif
