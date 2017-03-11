#ifndef NETWORK_DEF_H
#define NETWORK_DEF_H

#define MAX_VERIFICATION_RESULT 2

typedef enum _ra_msg_types {
    RA_MSG0,
    RA_MSG1,
    RA_MSG2,
    RA_MSG3,
    RA_ATT_RESULT,
    RA_VERIFICATION,
    RA_APP_ATT_OK
} ra_msg_types;


typedef enum _ra_msg {
    TYPE_OK,
    TYPE_TERMINATE
} ra_msg;


#pragma pack(1)
typedef struct _ra_samp_request_header_t {
    uint8_t  type;     /* set to one of ra_msg_type_t*/
    uint32_t size;     /*size of request body*/
    uint8_t  align[3];
    uint8_t body[];
} ra_samp_request_header_t;

typedef struct _ra_samp_response_header_t {
    uint8_t  type;      /* set to one of ra_msg_type_t*/
    uint8_t  status[2];
    uint32_t size;      /*size of the response body*/
    uint8_t  align[1];
    uint8_t  body[];
} ra_samp_response_header_t;

#pragma pack()


#endif
