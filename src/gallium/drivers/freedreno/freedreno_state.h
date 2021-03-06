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

#ifndef FREEDRENO_STATE_H_
#define FREEDRENO_STATE_H_

#include "pipe/p_context.h"

struct fd_vertexbuf_stateobj;
struct fd_zsa_stateobj;
struct fd_framebuffer_stateobj;
struct fd_ringbuffer;

void fd_state_init(struct pipe_context *pctx);

struct fd_vertex_buf {
	unsigned offset, size;
	struct pipe_resource *prsc;
};

void fd_emit_vertex_bufs(struct fd_ringbuffer *ring, uint32_t val,
		struct fd_vertex_buf *vbufs, uint32_t n);
void fd_emit_framebuffer_state(struct fd_ringbuffer *ring,
		struct fd_framebuffer_stateobj *fb);
void fd_state_emit(struct pipe_context *pctx, uint32_t dirty);
void fd_state_emit_setup(struct pipe_context *pctx);

#endif /* FREEDRENO_STATE_H_ */
