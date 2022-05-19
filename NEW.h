#include "malloc.h"
#define NEW(STRUCT_NAME) ((struct STRUCT_NAME*) malloc(sizeof(struct STRUCT_NAME)))