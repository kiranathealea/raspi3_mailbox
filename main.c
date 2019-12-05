/*
 * Copyright (C) 2018 bzt (bztsrc@github)
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */


#include "mbox.h"
#include "delays.h"

void set_led(int state) //set state LED nyala atau mati
{
    if (state==1){ //LED nyala
        mbox[0] = 8*4;                  // length of the message
        mbox[1] = MBOX_REQUEST;         // this is a request message
    
        mbox[2] = 0x00038041;   // get serial number command
        mbox[3] = 8;                    // buffer size
        mbox[4] = 0;
        mbox[5] = 130;                    // clear output buffer
        mbox[6] = 1;
        mbox[7] = MBOX_TAG_LAST;
        mbox_call(8);
    }
    else if (state==0){ //LED mati
        mbox[0] = 8*4;                  // length of the message
        mbox[1] = MBOX_REQUEST;         // this is a request message
    
        mbox[2] = 0x00038041;   // get serial number command
        mbox[3] = 8;                    // buffer size
        mbox[4] = 0;
        mbox[5] = 130;                    // clear output buffer
        mbox[6] = 0;
        mbox[7] = MBOX_TAG_LAST;
        mbox_call(8);
    }
}

void delay(int miliseconds) 
{ 
    // Mengubah dari miliseconds menjadi micro second (tutorial 07.Delays) 
    int micro_seconds = 1000 * miliseconds; 
  
    wait_msec(micro_seconds); 
} 

void main()
{
    //Blinking LED sesuai NIU
    //Nama: Thea Kirana, NIU: 399921

    int digit1 = 3;
    int digit2 = 9;
    int digit3 = 9;
    int digit4 = 9;
    int digit5 = 2;
    int digit6 = 1;
    int i = 0;
    
    
    while (1)
    {
        for (i = 1; i <= digit1; i++) 
        { 
            set_led(1);
            delay(200);
            set_led(0);
            delay(200); 
        } 

        delay(2000);

        for (i = 1; i <= digit2; i++) 
        { 
            set_led(1);
            delay(200);
            set_led(0);
            delay(200); 
        } 

        delay(2000);

        for (i = 1; i <= digit3; i++) 
        { 
            set_led(1);
            delay(200);
            set_led(0);
            delay(200); 
        } 

        delay(2000);

        for (i = 1; i <= digit4; i++) 
        { 
            set_led(1);
            delay(200);
            set_led(0);
            delay(200); 
        } 

        delay(2000);

        for (i = 1; i <= digit5; i++) 
        { 
            set_led(1);
            delay(200);
            set_led(0);
            delay(200); 
        } 

        delay(2000);

        for (i = 1; i <= digit6; i++) 
        { 
            set_led(1);
            delay(200);
            set_led(0);
            delay(200); 
        } 

        delay(2000);
    }
    
    
}
