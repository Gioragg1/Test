/*
 * oppserver.c
 *
 * An OBEX Push Profile server application for Bluetooth
 *
 * Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/
 *
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>      
#include <netinet/in.h>
#include <sys/socket.h>
#include <openobex/obex.h>
#include <bluetooth/bluetooth.h>

#define OBEX_PULL_HANDLE	9
#define RX_TIMEOUT 60

obex_t *handle = NULL;
volatile int finished = 0;

struct context
{
    int serverdone;
    int clientdone;
    char *get_name; 
};

void obex_event(obex_t *handle, obex_object_t *object, int mode, int event, int obex_cmd, int obex_rsp);

int main(int argc, char **argv)
{
    obex_object_t  *object;
    struct context lcontext = {0};
    int channel = OBEX_PULL_HANDLE; 
    int ret = 0;


    if (argc > 2) 
    {
        printf ("Usage is oppserver <channel number> \n");
        exit(0);
    }
    else if (argc == 2)
    {
        channel = atoi(argv[1]);
    }

    if (! (handle = OBEX_Init(OBEX_TRANS_BLUETOOTH, obex_event, 0))) 
    {
        printf( "OBEX_Init failed");
        exit(0);
    }

    OBEX_SetUserData(handle, &lcontext);

    if(BtOBEX_ServerRegister(handle, BDADDR_ANY, 9) < 0)
    {
        printf("Server register error! (Bluetooth)\n");
        exit(0);
    }

    printf("Waiting for connection...\n");

    while (!lcontext.serverdone)
    {
        /* Wait for RX_TIMEOUT */
        ret = OBEX_HandleInput(handle, RX_TIMEOUT);
        if(ret < 0)
        {
            printf("OBEX_HandleInput() returned!!\n");
            break;
        }
    }

} /* end of main () */
