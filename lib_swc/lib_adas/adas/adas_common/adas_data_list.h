#ifndef CTRL_UTILITY_DATA_LIST_H_
#define CTRL_UTILITY_DATA_LIST_H_

#include "adas_types.h"
#include "adas_project_input.h"

#define MAX_DATA_LIST_SIZE  16

typedef struct _DataListTag_
{
    float32_t f32Value[MAX_DATA_LIST_SIZE];
    float32_t f32Sum;

    uint8_t   u8Capacity;
    uint8_t   u8Count;
    uint8_t   u8StoreIndex; //the index we will store the value for next.
    uint8_t   res;
}DataList;

void  DataList_Init(DataList* pThis, uint8_t capacity);
void  DataList_Add(DataList* pThis, float a);
float DataList_Average(DataList* pThis);
float DataList_Current(DataList* pThis);

#endif //CTRL_UTILITY_DATA_LIST_H_
