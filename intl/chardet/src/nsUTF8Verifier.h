/* -*- Mode: C; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 2 -*-
 *
 * The contents of this file are subject to the Netscape Public License
 * Version 1.0 (the "NPL"); you may not use this file except in
 * compliance with the NPL.  You may obtain a copy of the NPL at
 * http://www.mozilla.org/NPL/
 *
 * Software distributed under the NPL is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the NPL
 * for the specific language governing rights and limitations under the
 * NPL.
 *
 * The Initial Developer of this code under the NPL is Netscape
 * Communications Corporation.  Portions created by Netscape are
 * Copyright (C) 1998 Netscape Communications Corporation.  All Rights
 * Reserved.
 */
/* 
 * DO NOT EDIT THIS DOCUMENT MANUALLY !!!
 * THIS FILE IS AUTOMATICALLY GENERATED BY THE TOOLS UNDER
 *    mozilla/intl/chardet/tools/
 * Please contact ftang@netscape.com or mozilla-i18n@mozilla.org
 * if you have any question. Thanks
 */
#include "nsVerifier.h"
static PRUint32 UTF8_cls [ 256 / 8 ] = {
PCK4BITS(0,1,1,1,1,1,1,1),  // 00 - 07 
PCK4BITS(1,1,1,1,1,1,0,0),  // 08 - 0f 
PCK4BITS(1,1,1,1,1,1,1,1),  // 10 - 17 
PCK4BITS(1,1,1,0,1,1,1,1),  // 18 - 1f 
PCK4BITS(1,1,1,1,1,1,1,1),  // 20 - 27 
PCK4BITS(1,1,1,1,1,1,1,1),  // 28 - 2f 
PCK4BITS(1,1,1,1,1,1,1,1),  // 30 - 37 
PCK4BITS(1,1,1,1,1,1,1,1),  // 38 - 3f 
PCK4BITS(1,1,1,1,1,1,1,1),  // 40 - 47 
PCK4BITS(1,1,1,1,1,1,1,1),  // 48 - 4f 
PCK4BITS(1,1,1,1,1,1,1,1),  // 50 - 57 
PCK4BITS(1,1,1,1,1,1,1,1),  // 58 - 5f 
PCK4BITS(1,1,1,1,1,1,1,1),  // 60 - 67 
PCK4BITS(1,1,1,1,1,1,1,1),  // 68 - 6f 
PCK4BITS(1,1,1,1,1,1,1,1),  // 70 - 77 
PCK4BITS(1,1,1,1,1,1,1,1),  // 78 - 7f 
PCK4BITS(2,2,2,2,3,3,3,3),  // 80 - 87 
PCK4BITS(4,4,4,4,4,4,4,4),  // 88 - 8f 
PCK4BITS(4,4,4,4,4,4,4,4),  // 90 - 97 
PCK4BITS(4,4,4,4,4,4,4,4),  // 98 - 9f 
PCK4BITS(5,5,5,5,5,5,5,5),  // a0 - a7 
PCK4BITS(5,5,5,5,5,5,5,5),  // a8 - af 
PCK4BITS(5,5,5,5,5,5,5,5),  // b0 - b7 
PCK4BITS(5,5,5,5,5,5,5,5),  // b8 - bf 
PCK4BITS(0,0,6,6,6,6,6,6),  // c0 - c7 
PCK4BITS(6,6,6,6,6,6,6,6),  // c8 - cf 
PCK4BITS(6,6,6,6,6,6,6,6),  // d0 - d7 
PCK4BITS(6,6,6,6,6,6,6,6),  // d8 - df 
PCK4BITS(7,8,8,8,8,8,8,8),  // e0 - e7 
PCK4BITS(8,8,8,8,8,9,8,8),  // e8 - ef 
PCK4BITS(10,11,11,11,11,11,11,11),  // f0 - f7 
PCK4BITS(12,13,13,13,14,15,0,0)   // f8 - ff 
};


static PRUint32 UTF8_st [ 26] = {
PCK4BITS(eError,eStart,eError,eError,eError,eError,     12,     10),//00-07 
PCK4BITS(     9,     11,     8,     7,     6,     5,     4,     3),//08-0f 
PCK4BITS(eError,eError,eError,eError,eError,eError,eError,eError),//10-17 
PCK4BITS(eError,eError,eError,eError,eError,eError,eError,eError),//18-1f 
PCK4BITS(eItsMe,eItsMe,eItsMe,eItsMe,eItsMe,eItsMe,eItsMe,eItsMe),//20-27 
PCK4BITS(eItsMe,eItsMe,eItsMe,eItsMe,eItsMe,eItsMe,eItsMe,eItsMe),//28-2f 
PCK4BITS(eError,eError,     5,     5,     5,     5,eError,eError),//30-37 
PCK4BITS(eError,eError,eError,eError,eError,eError,eError,eError),//38-3f 
PCK4BITS(eError,eError,eError,     5,     5,     5,eError,eError),//40-47 
PCK4BITS(eError,eError,eError,eError,eError,eError,eError,eError),//48-4f 
PCK4BITS(eError,eError,     7,     7,     7,     7,eError,eError),//50-57 
PCK4BITS(eError,eError,eError,eError,eError,eError,eError,eError),//58-5f 
PCK4BITS(eError,eError,eError,eError,     7,     7,eError,eError),//60-67 
PCK4BITS(eError,eError,eError,eError,eError,eError,eError,eError),//68-6f 
PCK4BITS(eError,eError,     9,     9,     9,     9,eError,eError),//70-77 
PCK4BITS(eError,eError,eError,eError,eError,eError,eError,eError),//78-7f 
PCK4BITS(eError,eError,eError,eError,eError,     9,eError,eError),//80-87 
PCK4BITS(eError,eError,eError,eError,eError,eError,eError,eError),//88-8f 
PCK4BITS(eError,eError,     12,     12,     12,     12,eError,eError),//90-97 
PCK4BITS(eError,eError,eError,eError,eError,eError,eError,eError),//98-9f 
PCK4BITS(eError,eError,eError,eError,eError,     12,eError,eError),//a0-a7 
PCK4BITS(eError,eError,eError,eError,eError,eError,eError,eError),//a8-af 
PCK4BITS(eError,eError,     12,     12,     12,eError,eError,eError),//b0-b7 
PCK4BITS(eError,eError,eError,eError,eError,eError,eError,eError),//b8-bf 
PCK4BITS(eError,eError,eStart,eStart,eStart,eStart,eError,eError),//c0-c7 
PCK4BITS(eError,eError,eError,eError,eError,eError,eError,eError) //c8-cf 
};


static nsVerifier nsUTF8Verifier = {
     "UTF-8",
    {
       eIdxSft4bits, 
       eSftMsk4bits, 
       eBitSft4bits, 
       eUnitMsk4bits, 
       UTF8_cls 
    },
    16,
    {
       eIdxSft4bits, 
       eSftMsk4bits, 
       eBitSft4bits, 
       eUnitMsk4bits, 
       UTF8_st 
    }
};
