#include "adas_data_list.h"

void  DataList_Init(DataList* pThis, uint8_t capacity)
{
    memset(pThis, 0, sizeof (DataList));
    if( capacity > MAX_DATA_LIST_SIZE )
    {
        capacity = MAX_DATA_LIST_SIZE;
    }
    pThis->u8Capacity = capacity;
}

void  DataList_Add(DataList* pThis, float a)
{
    if (pThis->u8Count < pThis->u8Capacity)
    {
        pThis->u8Count++;
    }
    else
    {
        pThis->f32Sum -= pThis->f32Value[pThis->u8StoreIndex];
    }

    pThis->f32Sum += a;
    pThis->f32Value[pThis->u8StoreIndex] = a;
    pThis->u8StoreIndex = (pThis->u8StoreIndex + 1) % pThis->u8Capacity;

}

float DataList_Average(DataList* pThis)
{
    if(0 == pThis->u8Count )
    {
        return 0;
    }

    return pThis->f32Sum/pThis->u8Count;
}

float  DataList_Current(DataList* pThis)
{
    uint8_t cur = (pThis->u8StoreIndex + pThis->u8Capacity - 1)%pThis->u8Capacity;
    return pThis->f32Value[cur];
}
