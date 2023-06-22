#include <stdio.h>
#include <stdlib.h>

#include "flash_type.h"

int main(int argc, char** argv){
  printf("CAN flashing\r\n");

  if(argc != 2) {
    printf("Usage:\n");
    printf(" can-flashing <device-name>\n");
    printf("\n");
    printf("Supported devices are:\n");
    for(FLASH_TYPE type = 0; type < FLASH_TYPE_COUNT; type++)
      printf("  %d -> %s\n", type, flash_type_name(type));
    
    return EXIT_FAILURE;
  }

  if(flash_type_value(argv[1]) == FLASH_TYPE_COUNT){
    printf("Error: Device name is not supported\n");
    return EXIT_FAILURE;
  }

  

  return EXIT_SUCCESS;
}