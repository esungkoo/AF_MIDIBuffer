/* -*- Mode: C; -*-
 *
 * ___ MIDIBufferPool.h _________________________________________
 * 
 * $URL: https://mm1.local/svn/private/trunk/lib/c/AF_MIDIBuffer/MIDIBufferPool.h $
 * $Id: MIDIBufferPool.h 211 2009-07-20 06:26:24Z greg $
 *
 * Copyright (c) 2004-2005, Gregory C. Wuller. All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or
 * without modification, are permitted provided that the following
 * conditions are met:
 * 
 *  - Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *  - Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR 'AS IS' AND ANY EXPRESSED
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef __MIDIBufferPool_h__
#define __MIDIBufferPool_h__

#include <CoreServices/CoreServices.h>
#include "MIDIBuffer.h"

struct MIDIBufferPool;
typedef struct MIDIBufferPool MIDIBufferPool;
typedef struct MIDIBufferPool* MIDIBufferPoolRef;

MIDIBufferPool *MIDIBufferPoolCreate(unsigned int count, unsigned int size);
void MIDIBufferPoolRelease(MIDIBufferPool *pool);

int MIDIBufferPoolSetAllocateFlag(MIDIBufferPool *pool, int flag);
int MIDIBufferPoolGetAllocateFlag(MIDIBufferPool *pool);

MIDIBuffer *MIDIBufferNextFromPool(MIDIBufferPool *pool, Duration timeout);
void MIDIBufferReleaseToPool(MIDIBuffer *buffer);

void MIDIBufferPoolResetCounters(MIDIBufferPool *pool);

unsigned int MIDIBufferPoolGetBufferSize(MIDIBufferPool *pool);
unsigned int MIDIBufferPoolGetBufferCount(MIDIBufferPool *pool);
unsigned long MIDIBufferPoolGetDynamicAllocationCount(MIDIBufferPool *pool);
unsigned int MIDIBufferPoolGetMinBufferCount(MIDIBufferPool *pool);
unsigned long MIDIBufferPoolGetBufferRequestCount(MIDIBufferPool *pool);
unsigned long MIDIBufferPoolGetLockErrorCount(MIDIBufferPool *pool);

#endif


