
#ifndef _UENENT_H_
#define _UENENT_H_

#include <stdint.h>
#include <string.h>

typedef struct {
	uint16_t evt_id;
	void* content;
} uevt_t;
#include "platform.h"

void user_event_broadcast(uevt_t evt);

#if NRF_LOG_ENABLED==1 && EVT_LOG_ENABLED==1
#define uevt_bc(x,y) LOG_RAW("EVT:" #x "\r\n"); \
	user_event_broadcast((uevt_t){x,y})
#define uevt_bc_e(x) LOG_RAW("EVT:" #x "\r\n"); \
	user_event_broadcast((uevt_t){x,NULL})
#else
#define uevt_bc(x,y) user_event_broadcast((uevt_t){x,y})
#define uevt_bc_e(x) user_event_broadcast((uevt_t){x,NULL})
#endif

#endif
