/*
 *     Copyright (C) 2010-2016 Marvell International Ltd.
 *     Copyright (C) 2002-2010 Kinoma, Inc.
 *
 *     Licensed under the Apache License, Version 2.0 (the "License");
 *     you may not use this file except in compliance with the License.
 *     You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *     Unless required by applicable law or agreed to in writing, software
 *     distributed under the License is distributed on an "AS IS" BASIS,
 *     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *     See the License for the specific language governing permissions and
 *     limitations under the License.
 */

#include "crypt.h"
#include "crypt_stream.h"
#include "crypt_common.h"
#include "kcl_symmetric.h"

void
xs_rc4_init(xsMachine *the)
{
	crypt_stream_t *stream = xsGetHostData(xsThis);
	void *key;
	size_t keysize;
	kcl_err_t err;

	key = xsToArrayBuffer(xsArg(0));
	keysize = xsGetArrayBufferLength(xsArg(0));
	if ((err = kcl_rc4_init(&stream->ctx, key, keysize)) != KCL_ERR_NONE)
		kcl_throw_error(the, err);
	stream->process = kcl_rc4_process;
	stream->finish = kcl_rc4_finish;
}
