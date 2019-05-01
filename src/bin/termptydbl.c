#include "private.h"

#include <Elementary.h>
#include "termpty.h"
#include "termptydbl.h"

Eina_Bool
_termpty_is_dblwidth_slow_get(const Termpty *ty, int g)
{
   // check for east asian full-width (F), half-width (H), wide (W),
   // narrow (Na) or ambiguous (A) codepoints
   // ftp://ftp.unicode.org/Public/UNIDATA/EastAsianWidth.txt

   // emoji should be double:
   // http://www.unicode.org/emoji/charts/full-emoji-list.html
   //
   // [ 0x0080 ->  0x02AF] !!! handle carefully **
   // [ 0x1DC0 ->  0x1DFF]
   // [ 0x1E00 ->  0x1EFF]
   // [ 0x2000 ->  0x209F] !!! handle carefully **
   // [ 0x20D0 ->  0x214F]
   // [ 0x2190 ->  0x23FF]
   // [ 0x2460 ->  0x24FF]
   // [ 0x2600 ->  0x262F]
   // [ 0x2638 ->  0x27EF]
   // [ 0x2900 ->  0x29FF]
   // [ 0x2B00 ->  0x2BFF] !!! unicode only 2B55 2B50
   // [ 0x2C60 ->  0x2C7F]
   // [ 0x2E00 ->  0x2E7F]
   // [ 0x3000 ->  0x303F] !! not 33D1
   // [ 0xA490 ->  0xA4CF]
   // [ 0xFE00 ->  0xFE0F]
   // [ 0xFE30 ->  0xFE4F]
   // [0x1F000 -> 0x1F02F]
   // [0x1F0A0 -> 0x1F0FF]
   // [0x1F100 -> 0x1F64F]
   // [0x1F680 -> 0x1F6FF]
   // [0x1F910 -> 0x1F96B]
   // [0x1F980 -> 0x1F9E0]
   // 
   // ** this range includes ye olde:
   // © (copyright)                00A9
   // ® (registered)               00AE
   // ‼ (double exclamation)       203C
   // ⁉ (exclamation questionmark) 2049
   // which should be single width, so ignore them

   // (W)
   // optimization: only look into more detailed ranges if within larger block
   if ((g >= 0x1100) && (g <= 0x3FFFD))
     {
        if (
            // 1XXX
            ((g >= 0x1100) && (g <= 0x115f)) ||
            // 2XXX
            ((g == 0x2329) || (g == 0x232a)) ||
            ((g >= 0x2e80) && (g <= 0x2ffb)) ||
            // 3XXX -> A4C6
            ((g >= 0x3001) && (g <= 0x303f)) ||
            ((g >= 0x3041) && (g <= 0x3247)) ||
            ((g >= 0x3250) && (g <= 0x33D0)) ||
            ((g >= 0x33D2) && (g <= 0x4dbf)) ||
            ((g >= 0x4e00) && (g <= 0xa4c6)) ||
            // aXXX
            ((g >= 0xa960) && (g <= 0xa97c)) ||
            ((g >= 0xac00) && (g <= 0xd7a3)) ||
            // fXXX
            ((g >= 0xf900) && (g <= 0xfaff)) ||
            ((g >= 0xfe10) && (g <= 0xfe19)) ||
            ((g >= 0xfe30) && (g <= 0xfe6b)) ||
            // 1XXXX
            ((g >= 0x1b000) && (g <= 0x1b001)) ||
            ((g >= 0x1f200) && (g <= 0x1f202)) ||
            ((g >= 0x1f210) && (g <= 0x1f251)) ||
            // 2XXXX
            ((g >= 0x20000) && (g <= 0x2fffd)) ||
            // 3XXXX
            ((g >= 0x30000) && (g <= 0x3FFFD)))
        return EINA_TRUE;
     }
   // optimization: only look into more detailed ranges if within larger block
   if ((g >= 0x0300) && (g <= 0x1F9E0))
     {
        if (
            // ** this is latin and should not be handled
            // ((g >= 0x0080) && (g <= 0x02AF)) ||
            ((g >= 0x1DC0) && (g <= 0x1DFF)) ||
            ((g >= 0x1E00) && (g <= 0x1EFF)) ||
            // this is subscripts and should not be handled
            // ((g >= 0x2000) && (g <= 0x209F)) ||
            ((g >= 0x20D0) && (g <= 0x214F)) ||
            ((g >= 0x2190) && (g <= 0x23FF)) ||
            ((g >= 0x2460) && (g <= 0x24FF)) ||
            ((g >= 0x2600) && (g <= 0x262F)) ||
            ((g >= 0x2638) && (g <= 0x27EF)) ||
            ((g >= 0x2900) && (g <= 0x29FF)) ||
            ((g >= 0x2B50)) ||
            ((g >= 0x2B55)) ||
            ((g >= 0x2C60) && (g <= 0x2C7F)) ||
            ((g >= 0x2E00) && (g <= 0x2E7F)) ||
            ((g >= 0x3000) && (g <= 0x303F)) ||
            ((g >= 0xA490) && (g <= 0xA4CF)) ||
            ((g >= 0xFE00) && (g <= 0xFE0F)) ||
            ((g >= 0xFE30) && (g <= 0xFE4F)) ||
            ((g >= 0x1F000) && (g <= 0x1F02F)) ||
            ((g >= 0x1F0A0) && (g <= 0x1F0FF)) ||
            ((g >= 0x1F100) && (g <= 0x1F64F)) ||
            ((g >= 0x1F680) && (g <= 0x1F6FF)) ||
            ((g >= 0x1F910) && (g <= 0x1F96B)) ||
            ((g >= 0x1F980) && (g <= 0x1F9E0))
           )
        return EINA_TRUE;
     }

   // FIXME: can optimize by breaking into tree and ranges
   // (A)
   if (ty->termstate.cjk_ambiguous_wide)
     {
        if ((g >= 0xa1) && (g <= 0x10fffd))
          {
             // grep ';A #' EastAsianWidth.txt | wc -l
             // :(
             if (
                 // aX
                 (((g >> 4) == 0xa) &&
                     (
                         (g == 0x00a1) ||
                         (g == 0x00a4) ||
                         ((g >= 0x00a7) && (g <= 0x00a8)) ||
                         (g == 0x00aa) ||
                         ((g >= 0x00ad) && (g <= 0x00ae)))) ||
                 // bX
                 (((g >> 4) == 0xb) &&
                     (((g >= 0x00b0) && (g <= 0x00bf)))) ||
                 // cX
                 (((g >> 4) == 0xc) &&
                     ((g == 0x00c6))) ||
                 // dX
                 (((g >> 4) == 0xd) &&
                     (
                         (g == 0x00d0) ||
                         ((g >= 0x00d7) && (g <= 0x00d8)) ||
                         ((g >= 0x00de) && (g <= 0x00df)))) ||
                 // eX
                 (((g >> 4) == 0xe) &&
                     (
                         (g == 0x00e0) ||
                         (g == 0x00e1) ||
                         (g == 0x00e6) ||
                         ((g >= 0x00e8) && (g <= 0x00e9)) ||
                         (g == 0x00ea) ||
                         ((g >= 0x00ec) && (g <= 0x00ed)))) ||
                 // fX
                 (((g >> 4) == 0xf) &&
                     (
                         (g == 0x00f0) ||
                         ((g >= 0x00f2) && (g <= 0x00f3)) ||
                         ((g >= 0x00f7) && (g <= 0x00f9)) ||
                         (g == 0x00fa) ||
                         (g == 0x00fc) ||
                         (g == 0x00fe))) ||
            // 1XX
                 (((g >> 8) == 0x1) &&
                     (
                         (g == 0x0101) ||
                         (g == 0x0111) ||
                         (g == 0x0113) ||
                         (g == 0x011b) ||
                         ((g >= 0x0126) && (g <= 0x0127)) ||
                         (g == 0x012b) ||
                         ((g >= 0x0131) && (g <= 0x0133)) ||
                         (g == 0x0138) ||
                         ((g >= 0x013f) && (g <= 0x0142)) ||
                         (g == 0x0144) ||
                         ((g >= 0x0148) && (g <= 0x014b)) ||
                         (g == 0x014d) ||
                         ((g >= 0x0152) && (g <= 0x0153)) ||
                         ((g >= 0x0166) && (g <= 0x0167)) ||
                         (g == 0x016b) ||
                         (g == 0x01ce) ||
                         (g == 0x01d0) ||
                         (g == 0x01d2) ||
                         (g == 0x01d4) ||
                         (g == 0x01d6) ||
                         (g == 0x01d8) ||
                         (g == 0x01da) ||
                         (g == 0x01dc))) ||
                 // 2XX
                 (((g >> 8) == 0x2) &&
                     (
                         (g == 0x0251) ||
                         (g == 0x0261) ||
                         (g == 0x02c4) ||
                         (g == 0x02c7) ||
                         (g == 0x02c9) ||
                         ((g >= 0x02ca) && (g <= 0x02cb)) ||
                         (g == 0x02cd) ||
                         (g == 0x02d0) ||
                         ((g >= 0x02d8) && (g <= 0x02d9)) ||
                         ((g >= 0x02da) && (g <= 0x02db)) ||
                         (g == 0x02dd) ||
                         (g == 0x02df))) ||
            // 3XX
                 (((g >> 8) == 0x3) &&
                     (
                         ((g >= 0x0300) && (g <= 0x036f)) ||
                         ((g >= 0x0391) && (g <= 0x03c9)))) ||
            // 4XX
                 (((g >> 8) == 0x4) &&
                     (
                         (g == 0x0401) ||
                         ((g >= 0x0410) && (g <= 0x044f)) ||
                         (g == 0x0451))) ||
                 // 2XXX
                 (((g >> 12) == 0x2) &&
                     ((((g >> 8) == 0x20) &&
                       (
                           (g == 0x2010) ||
                           ((g >= 0x2013) && (g <= 0x2016)) ||
                           ((g >= 0x2018) && (g <= 0x2019)) ||
                           (g == 0x201c) ||
                           (g == 0x201d) ||
                           ((g >= 0x2020) && (g <= 0x2022)) ||
                           ((g >= 0x2024) && (g <= 0x2027)) ||
                           (g == 0x2030) ||
                           ((g >= 0x2032) && (g <= 0x2033)) ||
                           (g == 0x2035) ||
                           (g == 0x203b) ||
                           (g == 0x203e) ||
                           (g == 0x2074) ||
                           (g == 0x207f) ||
                           ((g >= 0x2081) && (g <= 0x2084)) ||
                           (g == 0x20ac))) ||
                         (((g >> 8) == 0x21) &&
                             (
                                 (g == 0x2103) ||
                                 (g == 0x2105) ||
                                 (g == 0x2109) ||
                                 (g == 0x2113) ||
                                 (g == 0x2116) ||
                                 ((g >= 0x2121) && (g <= 0x2122)) ||
                                 (g == 0x2126) ||
                                 (g == 0x212b) ||
                                 ((g >= 0x2153) && (g <= 0x2154)) ||
                                 ((g >= 0x215b) && (g <= 0x215e)) ||
                                 ((g >= 0x2160) && (g <= 0x216b)) ||
                                 ((g >= 0x2170) && (g <= 0x2179)) ||
                                 ((g >= 0x2189) && (g <= 0x2199)) ||
                                 ((g >= 0x21b8) && (g <= 0x21b9)) ||
                                 (g == 0x21d2) ||
                                 (g == 0x21d4) ||
                                 (g == 0x21e7))) ||
                         (((g >> 8) == 0x22) &&
                             (
                                 (g == 0x2200) ||
                                 ((g >= 0x2202) && (g <= 0x2203)) ||
                                 ((g >= 0x2207) && (g <= 0x2208)) ||
                                 (g == 0x220b) ||
                                 (g == 0x220f) ||
                                 (g == 0x2211) ||
                                 (g == 0x2215) ||
                                 (g == 0x221a) ||
                                 ((g >= 0x221d) && (g <= 0x221f)) ||
                                 (g == 0x2220) ||
                                 (g == 0x2223) ||
                                 (g == 0x2225) ||
                                 ((g >= 0x2227) && (g <= 0x222e)) ||
                                 ((g >= 0x2234) && (g <= 0x2237)) ||
                                 ((g >= 0x223c) && (g <= 0x223d)) ||
                                 (g == 0x2248) ||
                                 (g == 0x224c) ||
                                 (g == 0x2252) ||
                                 ((g >= 0x2260) && (g <= 0x2261)) ||
                                 ((g >= 0x2264) && (g <= 0x2267)) ||
                                 ((g >= 0x226a) && (g <= 0x226b)) ||
                                 ((g >= 0x226e) && (g <= 0x226f)) ||
                                 ((g >= 0x2282) && (g <= 0x2283)) ||
                                 ((g >= 0x2286) && (g <= 0x2287)) ||
                                 (g == 0x2295) ||
                                 (g == 0x2299) ||
                                 (g == 0x22a5) ||
                                 (g == 0x22bf))) ||
                         (((g >> 8) == 0x23) &&
                             ((g == 0x2312))) ||
                         ((((g >> 8) == 0x24) || ((g >> 8) == 0x25)) &&
                             (((g >= 0x2460) && (g <= 0x2595)))) ||
                         (((g >> 8) == 0x25) &&
                             (
                                 ((g >= 0x25a0) && (g <= 0x25bd)) ||
                                 ((g >= 0x25c0) && (g <= 0x25c1)) ||
                                 ((g >= 0x25c6) && (g <= 0x25c7)) ||
                                 (g == 0x25c8) ||
                                 (g == 0x25cb) ||
                                 ((g >= 0x25ce) && (g <= 0x25cf)) ||
                                 ((g >= 0x25d0) && (g <= 0x25d1)) ||
                                 ((g >= 0x25e2) && (g <= 0x25e3)) ||
                                 ((g >= 0x25e4) && (g <= 0x25e5)) ||
                                 (g == 0x25ef))) ||
                         (((g >> 8) == 0x26) &&
                             (
                                 ((g >= 0x2605) && (g <= 0x2606)) ||
                                 (g == 0x2609) ||
                                 ((g >= 0x260e) && (g <= 0x260f)) ||
                                 ((g >= 0x2614) && (g <= 0x2615)) ||
                                 (g == 0x261c) ||
                                 (g == 0x261e) ||
                                 (g == 0x2640) ||
                                 (g == 0x2642) ||
                                 ((g >= 0x2660) && (g <= 0x2661)) ||
                                 ((g >= 0x2663) && (g <= 0x2665)) ||
                                 ((g >= 0x2667) && (g <= 0x266a)) ||
                                 ((g >= 0x266c) && (g <= 0x266d)) ||
                                 (g == 0x266f) ||
                                 ((g >= 0x269e) && (g <= 0x269f)) ||
                                 ((g >= 0x26be) && (g <= 0x26bf)) ||
                                 ((g >= 0x26c4) && (g <= 0x26cd)) ||
                                 (g == 0x26cf) ||
                                 ((g >= 0x26d0) && (g <= 0x26e1)) ||
                                 (g == 0x26e3) ||
                                 ((g >= 0x26e8) && (g <= 0x26ff)))) ||
                         (((g >> 8) == 0x27) &&
                             (
                                 (g == 0x273d) ||
                                 (g == 0x2757) ||
                                 ((g >= 0x2776) && (g <= 0x277f)))) ||
                         (((g >> 8) == 0x2b) &&
                             (((g >= 0x2b55) && (g <= 0x2b59)))))) ||
                 // 3XXX
                 (((g >> 12) == 0x3) &&
                     (((g >= 0x3248) && (g <= 0x324f)))) ||
                 // eXXX
                 (((g >> 12) == 0xe) &&
                     (((g >= 0xe000) && (g <= 0xf8ff)))) ||
                 // fXXX
                 (((g >> 12) == 0xf) &&
                     (
                         ((g >= 0xfe00) && (g <= 0xfe0f)) ||
                         (g == 0xfffd))) ||
                 // 1XXXX
                 (((g >> 16) == 0x1) &&
                     (
                         ((g >= 0x1f100) && (g <= 0x1f12d)) ||
                         ((g >= 0x1f130) && (g <= 0x1f169)) ||
                         ((g >= 0x1f170) && (g <= 0x1f19a)))) ||
                 // eXXXX
                 (((g >> 16) == 0xe) &&
                     (((g >= 0xe0100) && (g <= 0xe01ef)))) ||
                 // fXXXX
                 (((g >> 16) == 0xf) &&
                     (((g >= 0xf0000) && (g <= 0xffffd)))) ||
                 // 1XXXXX
                 (((g >> 24) == 0x1) &&
                     (((g >= 0x100000) && (g <= 0x10fffd)))))
             return EINA_TRUE;
          }
     }

   // Na, H -> not checked
   return EINA_FALSE;
}
