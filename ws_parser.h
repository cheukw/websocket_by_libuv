//
//  ws_parser.h
//  nvr
//
//  Created by zhengyixiong on 15/8/12.
//  Copyright (c) 2015�� zhengyixiong. All rights reserved.
//

#ifndef _WS_PARSER_H_
#define _WS_PARSER_H_
#include "uv.h"

typedef enum OpcodeType
{
    OPCODE_CONTINUE = 0,	//��Ƭ֡
    OPCODE_TEXT,			//�ı�֡������json����
    OPCODE_FORWARD,		//������֡������ת��
    OPCODE_CLOSE = 8,	//���ӹر�
    OPCODE_PING,		//ping
    OPCODE_PONG			//pong
}OpcodeType;

typedef struct WsHeader
{
    uint8_t     fin;
    uint8_t     res[3];
    uint8_t     type;		//�ο�OpcodeType
    uint8_t     mask;
    uint8_t     maskkey[4];
    uint64_t	length;
}WsHeader;

int ParseHandShake(const char* req, int reqSize, char* res, const int maxResSize, int &resSize);
int Parse(const char* req, uint64_t reqSize, WsHeader &header, int &dataPos);
int Pack(OpcodeType type, char* pHeader, int &headerSize, uint64_t dataSize);

#endif
