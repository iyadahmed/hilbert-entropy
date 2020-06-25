/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef _GREY_H
#define _GREY_H
#include <stdint.h>
#include <stdbool.h>
#ifdef __SIZEOF_INT128__
#define grey(X) __extension__ _Generic((X),\
              char: _grey_u8, \
     unsigned char: _grey_8,  \
             short: _grey_16, \
    unsigned short: _grey_u16 \
               int: _grey_32, \
      unsigned int: _grey_u32,\
              long: _grey_32, \
     unsigned long: _grey_u32,\
         long long: _grey_64, \
unsigned long long: _grey_u64,\
	      __int128: _grey_128,\
 unsigned __int128: _grey_u128\
)(X, 0)
#define ungrey(X) __extension__ _Generic((X),\
              char: _grey_u8, \
     unsigned char: _grey_8,  \
             short: _grey_16, \
    unsigned short: _grey_u16 \
               int: _grey_32, \
      unsigned int: _grey_u32,\
              long: _grey_32, \
     unsigned long: _grey_u32,\
         long long: _grey_64, \
unsigned long long: _grey_u64,\
	      __int128: _grey_128,\
 unsigned __int128: _grey_u128\
)(X, 1)
#else
#define grey(X) _Generic((X), \
              char: _grey_u8, \
     unsigned char: _grey_8,  \
             short: _grey_16, \
    unsigned short: _grey_u16 \
               int: _grey_32, \
      unsigned int: _grey_u32,\
              long: _grey_32, \
     unsigned long: _grey_u32,\
         long long: _grey_64, \
unsigned long long: _grey_u64 \
)(X,0)
#define ungrey(X) _Generic((X),\
              char: _grey_u8, \
     unsigned char: _grey_8,  \
             short: _grey_16, \
    unsigned short: _grey_u16 \
               int: _grey_32, \
      unsigned int: _grey_u32,\
              long: _grey_32, \
     unsigned long: _grey_u32,\
         long long: _grey_64, \
unsigned long long: _grey_u64 \
)(X,1)
#endif

uint8_t _grey_u8(uint8_t x, bool g){
	x ^= g?x/2:x*2;
	x=((x>>1)&0x55)|((x&0x55)<<1);
	x=((x>>2)&0x33)|((x&0x33)<<2);
	x=((x>>4)&0x0F)|((x&0x0F)<<4);
	return x;
}

int8_t _grey_8(int8_t x, bool g){
	x ^= g?x/2:x*2;
	x=((x>>1)&0x55)|((x&0x55)<<1);
	x=((x>>2)&0x33)|((x&0x33)<<2);
	x=((x>>4)&0x0F)|((x&0x0F)<<4);
	return x;
}

uint16_t _grey_u16(uint16_t x, bool g){
	x ^= g?x/2:x*2;
	x=((x>>1)&0x5555)|((x&0x5555)<<1);
	x=((x>>2)&0x3333)|((x&0x3333)<<2);
	x=((x>>4)&0x0F0F)|((x&0x0F0F)<<4);
	x=((x>>8)&0x00FF)|((x&0x00FF)<<8);
	return x;
}

int16_t _grey_16(int16_t x, bool g){
	x ^= g?x/2:x*2;
	x=((x>>1)&0x5555)|((x&0x5555)<<1);
	x=((x>>2)&0x3333)|((x&0x3333)<<2);
	x=((x>>4)&0x0F0F)|((x&0x0F0F)<<4);
	x=((x>>8)&0x00FF)|((x&0x00FF)<<8);
	return x;
}

uint32_t _grey_u32(uint32_t x, bool g){
	x ^= g?x/2:x*2;
	x=((x>>1)&0x55555555)|((x&0x55555555)<<1);
	x=((x>>2)&0x33333333)|((x&0x33333333)<<2);
	x=((x>>4)&0x0F0F0F0F)|((x&0x0F0F0F0F)<<4);
	x=((x>>8)&0x00FF00FF)|((x&0x00FF00FF)<<8);
	x=(x>>16)|(x<<16);
	return x;
}

int32_t _grey_32(int32_t x, bool g){
	x ^= g?x/2:x*2;
	x=((x>>1)&0x55555555)|((x&0x55555555)<<1);
	x=((x>>2)&0x33333333)|((x&0x33333333)<<2);
	x=((x>>4)&0x0F0F0F0F)|((x&0x0F0F0F0F)<<4);
	x=((x>>8)&0x00FF00FF)|((x&0x00FF00FF)<<8);
	x=(x>>16)|(x<<16);
	return x;
}

uint64_t _grey_u64(uint64_t x, bool g){
	x ^= g?x/2:x*2;
	x=((x>>1)&0x55555555)|((x&0x55555555)<<1);
	x=((x>>2)&0x33333333)|((x&0x33333333)<<2);
	x=((x>>4)&0x0F0F0F0F)|((x&0x0F0F0F0F)<<4);
	x=((x>>8)&0x00FF00FF)|((x&0x00FF00FF)<<8);
	x=((x>>16)&0x0000FFFF)|((x&0x0000FFFF)<<16);
	x=(x>>32)|(x<<32);
	return x;
}

int64_t _grey_64(int64_t x, bool g){
	x ^= g?x/2:x*2;
	x=((x>>1)&0x55555555)|((x&0x55555555)<<1);
	x=((x>>2)&0x33333333)|((x&0x33333333)<<2);
	x=((x>>4)&0x0F0F0F0F)|((x&0x0F0F0F0F)<<4);
	x=((x>>8)&0x00FF00FF)|((x&0x00FF00FF)<<8);
	x=((x>>16)&0x0000FFFF)|((x&0x0000FFFF)<<16);
	x=(x>>32)|(x<<32);
	return x;
}
#ifdef __SIZEOF_INT128__
__extension__ unsigned __int128 _grey_u128(unsigned __int128 x, bool g){
	x ^= g?x/2:x*2;
	x=((x>>1)&0x5555555555555555)|((x&0x5555555555555555)<<1);
	x=((x>>2)&0x3333333333333333)|((x&0x3333333333333333)<<2);
	x=((x>>4)&0x0F0F0F0F0F0F0F0F)|((x&0x0F0F0F0F0F0F0F0F)<<4);
	x=((x>>8)&0x00FF00FF00FF00FF)|((x&0x00FF00FF00FF00FF)<<8);
	x=((x>>16)&0x0000FFFF0000FFFF)|((x&0x0000FFFF0000FFFF)<<16);
	x=((x>>32)&0x00000000FFFFFFFF)|((x&0x00000000FFFFFFFF)<<32);
	x=(x>>64)|(x<<64);
	return x;
}

__extension__ __int128 _grey_128(__int128 x, bool g){
	x ^= g?x/2:x*2;
	x=((x>>1)&0x5555555555555555)|((x&0x5555555555555555)<<1);
	x=((x>>2)&0x3333333333333333)|((x&0x3333333333333333)<<2);
	x=((x>>4)&0x0F0F0F0F0F0F0F0F)|((x&0x0F0F0F0F0F0F0F0F)<<4);
	x=((x>>8)&0x00FF00FF00FF00FF)|((x&0x00FF00FF00FF00FF)<<8);
	x=((x>>16)&0x0000FFFF0000FFFF)|((x&0x0000FFFF0000FFFF)<<16);
	x=((x>>32)&0x00000000FFFFFFFF)|((x&0x00000000FFFFFFFF)<<32);
	x=(x>>64)|(x<<64);
	return x;
}
#endif /*_INT128*/
#endif /*_GREY_H*/