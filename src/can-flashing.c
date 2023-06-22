#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>

#include "inc/flash_type.h"
#include "inc/flash_fsm.h"

bool file_exists (char *filename) {
  struct stat   buffer;   
  return (stat (filename, &buffer) == 0);
}

int main(int argc, char** argv){
  printf("CAN flashing\r\n");

  state_data_t data = {.flash_device = FLASH_TYPE_COUNT};

  if(argc != 3) {
    printf("Usage:\n");
    printf(" can-flashing <device-name> <srec-file>\n");
    printf("\n");
    printf("Supported devices are:\n");
    for(FLASH_TYPE type = 0; type < FLASH_TYPE_COUNT; type++)
      printf("  %d -> %s\n", type, flash_type_name(type));
    
    return EXIT_FAILURE;
  }

  data.flash_device = flash_type_value(argv[1]);
  if(data.flash_device == FLASH_TYPE_COUNT){
    printf("Error: Device name is not supported\n");
    printf("Supported devices are:\n");
    for(FLASH_TYPE type = 0; type < FLASH_TYPE_COUNT; type++)
      printf("  %d -> %s\n", type, flash_type_name(type));
    return EXIT_FAILURE;
  }

  if(!file_exists(argv[2])){
    printf("File does not exitst.\n");
    return EXIT_FAILURE;
  }
  data.binary_path = argv[2];

  if(strstr(data.binary_path, ".srec") == NULL){
    printf("File is not a .srec\n");
    return EXIT_FAILURE;
  }

  setup_flash_ids();
  state_t cur_state = STATE_START;
  do {
    cur_state = run_state(cur_state, &data);
  } while (cur_state != STATE_END);
  run_state(cur_state, NULL);

  return EXIT_SUCCESS;
}