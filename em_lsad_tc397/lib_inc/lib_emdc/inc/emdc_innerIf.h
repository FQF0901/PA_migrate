#ifndef EMDC_INNERIF_H
#define EMDC_INNERIF_H

#include "emdc_types.h"

extern int get_local_mac(const char *nc, EM_U8* localMacAddr);

extern int emdc_innerIf_SendSocketCreate(const char *ifname,EM_U8 priority);

extern int emdc_innerIf_RecvSocketCreate(const char *ifname);

extern int emdc_innerIf_sendto(int sendfd, EM_U8* txData, size_t length);

extern int emdc_innerIf_recvfrom(int recvfd, EM_U8* txData, size_t length);

#endif /*EMDC_INNERIF_H*/