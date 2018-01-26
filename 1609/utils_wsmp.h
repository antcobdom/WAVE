#ifndef _UTILS_WSMP_H
#define _UTILS_WSMP_H

/* WAVE Short Message Protocol - IEEE 1609
 * Copyright (C) 2017 Nicholas Haltmeyer <ginsback@protonmail.com>,
 *                    Duncan Woodbury    <p3n3troot0r@protonmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 */

#include <time.h>
#include <stdlib.h>
#include <assert.h>

#include "wsmp.h"
#include "encode.h"
#include "decode.h"

int randr(int a, int b);
int urandr(unsigned int a, unsigned int b);

void print_iex(struct wsmp_iex *iex);
void print_wsm(struct wsmp_wsm *wsm);
void print_sii(struct wsmp_sii *sii);
void print_cii(struct wsmp_cii *cii);
void print_wra(struct wsmp_wra *wra);
void print_wsa(struct wsmp_wsa *wsa);

struct wsmp_iex *gen_iex(int mode);
struct wsmp_sii *gen_sii(int mode);
struct wsmp_cii *gen_cii(int mode);
struct wsmp_wra *gen_wra(int mode);
struct wsmp_wsa *gen_wsa(int mode);
struct wsmp_wsm *gen_wsm(int mode);

uint8_t *gen_bytes(size_t *len);

#endif
