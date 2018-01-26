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
#include "utils_wsmp.h"

void test_bytes(int mode) {
     size_t len;
     uint8_t *bs = gen_bytes(&len);

     size_t cnt = 0;
     int err = 0;
     struct wsmp_iex *iex = wsmp_iex_decode(bs, &cnt, len, &err, mode);

     if (err)
          ; //printf("ERR: %d CNT: %lu LEN: %lu MODE: %d\n", err, cnt, len, mode);
     else
          print_iex(iex);

     free_iex(iex);
     free(bs);
}

int cmp_bytes(uint8_t *b1, uint8_t *b2, size_t i) {
     int j;
     for (j = 0; j < i; j++) {
          if (b1[j] != b2[j])
               return 0;
     }

     return 1;
}

void test_iex(int mode) {
     struct wsmp_iex *iex1 = gen_iex(mode);
     struct wsmp_iex *iex2;
     uint8_t *buf1;
     uint8_t *buf2;
     size_t cnt1 = 0;
     size_t cnt2 = 0;
     int err1 = 0;
     int err2 = 0;


     buf1 = wsmp_iex_encode(iex1, &cnt1, &err1, mode);
     iex2 = wsmp_iex_decode(buf1, &cnt2, cnt1, &err2, mode);
     buf2 = wsmp_iex_encode(iex2, &cnt2, &err2, mode);

     if (cnt1 != cnt2 || err1 || err2 || !cmp_bytes(buf1, buf2, cnt1)) {
          printf("ERR1 %d ERR2 %d\n", err1, err2);
          printf("BUG: PACKETS NOT EQUAL\n\n");
          fflush(stdout);
     }

     free_iex(iex1);
     free_iex(iex2);
     free(buf1);
     free(buf2);
}

void test_sii(int mode) {
     struct wsmp_sii *sii1 = gen_sii(mode);
     struct wsmp_sii *sii2;
     uint8_t *buf1;
     uint8_t *buf2;
     size_t cnt1 = 0;
     size_t cnt2 = 0;
     int err1 = 0;
     int err2 = 0;

     buf1 = wsmp_sii_encode(sii1, &cnt1, &err1, mode);
     sii2 = wsmp_sii_decode(buf1, &cnt2, cnt1, &err2, mode);
     buf2 = wsmp_sii_encode(sii2, &cnt2, &err2, mode);

     if (cnt1 != cnt2 || err1 || err2 || !cmp_bytes(buf1, buf2, cnt1)) {
          printf("ERR1 %d ERR2 %d\n", err1, err2);
          printf("BUG: PACKETS NOT EQUAL\n\n");
          fflush(stdout);
     }

     free_sii(sii1);
     free_sii(sii2);
     free(buf1);
     free(buf2);
}

void test_cii(int mode) {
     struct wsmp_cii *cii1 = gen_cii(mode);
     struct wsmp_cii *cii2;
     uint8_t *buf1;
     uint8_t *buf2;
     size_t cnt1 = 0;
     size_t cnt2 = 0;
     int err1 = 0;
     int err2 = 0;

     buf1 = wsmp_cii_encode(cii1, &cnt1, &err1, mode);
     cii2 = wsmp_cii_decode(buf1, &cnt2, cnt1, &err2, mode);
     buf2 = wsmp_cii_encode(cii2, &cnt2, &err2, mode);

     if (cnt1 != cnt2 || err1 || err2 || !cmp_bytes(buf1, buf2, cnt1)) {
          printf("ERR1 %d ERR2 %d\n", err1, err2);
          printf("BUG: PACKETS NOT EQUAL\n\n");
          fflush(stdout);
     }

     free_cii(cii1);
     free_cii(cii2);
     free(buf1);
     free(buf2);
}

void test_wra(int mode) {
     struct wsmp_wra *wra1 = gen_wra(mode);
     struct wsmp_wra *wra2;
     uint8_t *buf1;
     uint8_t *buf2;
     size_t cnt1 = 0;
     size_t cnt2 = 0;
     int err1 = 0;
     int err2 = 0;

     buf1 = wsmp_wra_encode(wra1, &cnt1, &err1, mode);
     wra2 = wsmp_wra_decode(buf1, &cnt2, cnt1, &err2, mode);
     buf2 = wsmp_wra_encode(wra2, &cnt2, &err2, mode);

     if (cnt1 != cnt2 || err1 || err2 || !cmp_bytes(buf1, buf2, cnt1)) {
          printf("ERR1 %d ERR2 %d\n", err1, err2);
          printf("BUG: PACKETS NOT EQUAL\n\n");
          fflush(stdout);
     }

     free_wra(wra1);
     free_wra(wra2);
     free(buf1);
     free(buf2);
}

void test_wsa(int mode) {
     struct wsmp_wsa *wsa1 = gen_wsa(mode);
     struct wsmp_wsa *wsa2;
     uint8_t *buf1;
     uint8_t *buf2;
     size_t cnt1 = 0;
     size_t cnt2 = 0;
     int err1 = 0;
     int err2 = 0;
     	
     buf1 = wsmp_wsa_encode(wsa1, &cnt1, &err1, mode);
     wsa2 = wsmp_wsa_decode(buf1, &cnt2, cnt1, &err2, mode);
     buf2 = wsmp_wsa_encode(wsa2, &cnt2, &err2, mode);

     if (cnt1 != cnt2 || err1 || err2 || !cmp_bytes(buf1, buf2, cnt1)) {
          printf("ERR1 %d ERR2 %d\n", err1, err2);
          printf("BUG: PACKETS NOT EQUAL\n\n");
          fflush(stdout);
     }

     free_wsa(wsa1);
     free_wsa(wsa2);
     free(buf1);
     free(buf2);
}

void test_wsm(int mode) {
     struct wsmp_wsm *wsm1 = gen_wsm(mode);
     struct wsmp_wsm *wsm2;
     uint8_t *buf1;
     uint8_t *buf2;
     size_t cnt1 = 0;
     size_t cnt2 = 0;
     int err1 = 0;
     int err2 = 0;

     buf1 = wsmp_wsm_encode(wsm1, &cnt1, &err1, mode);
     wsm2 = wsmp_wsm_decode(buf1, &cnt2, cnt1, &err2, mode);
     buf2 = wsmp_wsm_encode(wsm2, &cnt2, &err2, mode);

     if (cnt1 != cnt2 || err1 || err2 || !cmp_bytes(buf1, buf2, cnt1)) {
	print_wsm(wsm1);
	print_wsm(wsm2);
          printf("ERR1 %d ERR2 %d\n", err1, err2);
          printf("BUG: PACKETS NOT EQUAL\n\n");

	  printf("WSM1 FRAME:\n");
	  int i;
	  for (i = 0; i < cnt1; i++) {
		  printf("%02x ", buf1[i]);
	  }

	  printf("\nWSM2 FRAME:\n");
	  for (i = 0; i < cnt1; i++) {
		  printf("%02x ", buf2[i]);
	  }
	  printf("\n\n");
          fflush(stdout);
     }

     free_wsm(wsm1);
     free_wsm(wsm2);
     free(buf1);
     free(buf2);
}

int main(int ac, char **av) {
     if (ac != 3) {
          printf("usage: test seed it\n");
          exit(1);
     }

     srand(strtol(av[1], NULL, 10));

     printf("Beginning WSMP test...\n");
     int start = time(NULL);

     int i;
     for (i = 0; i < strtol(av[2], NULL, 10); i++) {
          // test_bytes(WSMP_STRICT);

	  test_wsm(WSMP_STRICT);
	  test_wsm(WSMP_LAX);
	  test_wsm(WSMP_LOOSE);
	  test_wsa(WSMP_STRICT);
	  test_wsa(WSMP_LAX);
	  test_wsa(WSMP_LOOSE);
	  test_iex(WSMP_STRICT);
	  test_iex(WSMP_LAX);
	  test_iex(WSMP_LOOSE);
	  test_sii(WSMP_STRICT);
	  test_sii(WSMP_LAX);
	  test_sii(WSMP_LOOSE);
	  test_cii(WSMP_STRICT);
	  test_cii(WSMP_LAX);
	  test_cii(WSMP_LOOSE);
	  test_wra(WSMP_STRICT);
	  test_wra(WSMP_LAX);
	  test_wra(WSMP_LOOSE);
     }

     int end = time(NULL);
     printf("Finished test in %d seconds.\n", (end-start));

     return 0;
}
