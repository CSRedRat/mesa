/* -*- mode: C; c-file-style: "k&r"; tab-width 4; indent-tabs-mode: t; -*- */

/*
 * Copyright (C) 2012 Rob Clark <robclark@freedesktop.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice (including the next
 * paragraph) shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Authors:
 *    Rob Clark <robclark@freedesktop.org>
 */

#ifndef FREEDRENO_TEXTURE_H_
#define FREEDRENO_TEXTURE_H_

#include "pipe/p_context.h"

#include "freedreno_context.h"
#include "freedreno_resource.h"
#include "freedreno_util.h"

struct fd_sampler_stateobj {
	struct pipe_sampler_state base;
	uint32_t tex0, tex3, tex4, tex5;
};

struct fd_pipe_sampler_view {
	struct pipe_sampler_view base;
	struct fd_resource *tex_resource;
	enum sq_surfaceformat fmt;
	uint32_t tex0, tex2, tex3;
};

static INLINE struct fd_pipe_sampler_view *
fd_pipe_sampler_view(struct pipe_sampler_view *pview)
{
	return (struct fd_pipe_sampler_view *)pview;
}

unsigned fd_get_const_idx(struct fd_context *ctx,
		struct fd_texture_stateobj *tex, unsigned samp_id);

void fd_texture_init(struct pipe_context *pctx);

#endif /* FREEDRENO_TEXTURE_H_ */
