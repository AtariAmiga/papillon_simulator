#ifndef NEW_H_INCLUDED
#define NEW_H_INCLUDED

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

#include "malloc.h"
#define NEW(STRUCT_NAME) ((struct STRUCT_NAME*) malloc(sizeof(struct STRUCT_NAME)))

#endif