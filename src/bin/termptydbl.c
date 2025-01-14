/* XXX: Code generated by tool unicode_dbl_width.py */
#include "private.h"

#include <Elementary.h>
#include "termpty.h"
#include "termptydbl.h"

__attribute__((const))
Eina_Bool
_termpty_is_ambigous_wide(Eina_Unicode g)
{
    switch (g)
      {
       case 0xA1: EINA_FALLTHROUGH;
       case 0xA4: EINA_FALLTHROUGH;
       case 0xA7 ... 0xA8: EINA_FALLTHROUGH;
       case 0xAA: EINA_FALLTHROUGH;
       case 0xAD ... 0xAE: EINA_FALLTHROUGH;
       case 0xB0 ... 0xB4: EINA_FALLTHROUGH;
       case 0xB6 ... 0xBA: EINA_FALLTHROUGH;
       case 0xBC ... 0xBF: EINA_FALLTHROUGH;
       case 0xC6: EINA_FALLTHROUGH;
       case 0xD0: EINA_FALLTHROUGH;
       case 0xD7 ... 0xD8: EINA_FALLTHROUGH;
       case 0xDE ... 0xE1: EINA_FALLTHROUGH;
       case 0xE6: EINA_FALLTHROUGH;
       case 0xE8 ... 0xEA: EINA_FALLTHROUGH;
       case 0xEC ... 0xED: EINA_FALLTHROUGH;
       case 0xF0: EINA_FALLTHROUGH;
       case 0xF2 ... 0xF3: EINA_FALLTHROUGH;
       case 0xF7 ... 0xFA: EINA_FALLTHROUGH;
       case 0xFC: EINA_FALLTHROUGH;
       case 0xFE: EINA_FALLTHROUGH;
       case 0x101: EINA_FALLTHROUGH;
       case 0x111: EINA_FALLTHROUGH;
       case 0x113: EINA_FALLTHROUGH;
       case 0x11B: EINA_FALLTHROUGH;
       case 0x126 ... 0x127: EINA_FALLTHROUGH;
       case 0x12B: EINA_FALLTHROUGH;
       case 0x131 ... 0x133: EINA_FALLTHROUGH;
       case 0x138: EINA_FALLTHROUGH;
       case 0x13F ... 0x142: EINA_FALLTHROUGH;
       case 0x144: EINA_FALLTHROUGH;
       case 0x148 ... 0x14B: EINA_FALLTHROUGH;
       case 0x14D: EINA_FALLTHROUGH;
       case 0x152 ... 0x153: EINA_FALLTHROUGH;
       case 0x166 ... 0x167: EINA_FALLTHROUGH;
       case 0x16B: EINA_FALLTHROUGH;
       case 0x1CE: EINA_FALLTHROUGH;
       case 0x1D0: EINA_FALLTHROUGH;
       case 0x1D2: EINA_FALLTHROUGH;
       case 0x1D4: EINA_FALLTHROUGH;
       case 0x1D6: EINA_FALLTHROUGH;
       case 0x1D8: EINA_FALLTHROUGH;
       case 0x1DA: EINA_FALLTHROUGH;
       case 0x1DC: EINA_FALLTHROUGH;
       case 0x251: EINA_FALLTHROUGH;
       case 0x261: EINA_FALLTHROUGH;
       case 0x2C4: EINA_FALLTHROUGH;
       case 0x2C7: EINA_FALLTHROUGH;
       case 0x2C9 ... 0x2CB: EINA_FALLTHROUGH;
       case 0x2CD: EINA_FALLTHROUGH;
       case 0x2D0: EINA_FALLTHROUGH;
       case 0x2D8 ... 0x2DB: EINA_FALLTHROUGH;
       case 0x2DD: EINA_FALLTHROUGH;
       case 0x2DF: EINA_FALLTHROUGH;
       case 0x300 ... 0x36F: EINA_FALLTHROUGH;
       case 0x391 ... 0x3A9: EINA_FALLTHROUGH;
       case 0x3B1 ... 0x3C1: EINA_FALLTHROUGH;
       case 0x3C3 ... 0x3C9: EINA_FALLTHROUGH;
       case 0x401: EINA_FALLTHROUGH;
       case 0x410 ... 0x44F: EINA_FALLTHROUGH;
       case 0x451: EINA_FALLTHROUGH;
       case 0x1100 ... 0x115F: EINA_FALLTHROUGH;
       case 0x2010: EINA_FALLTHROUGH;
       case 0x2013 ... 0x2016: EINA_FALLTHROUGH;
       case 0x2018 ... 0x2019: EINA_FALLTHROUGH;
       case 0x201C ... 0x201D: EINA_FALLTHROUGH;
       case 0x2020 ... 0x2022: EINA_FALLTHROUGH;
       case 0x2024 ... 0x2027: EINA_FALLTHROUGH;
       case 0x2030: EINA_FALLTHROUGH;
       case 0x2032 ... 0x2033: EINA_FALLTHROUGH;
       case 0x2035: EINA_FALLTHROUGH;
       case 0x203B: EINA_FALLTHROUGH;
       case 0x203E: EINA_FALLTHROUGH;
       case 0x2074: EINA_FALLTHROUGH;
       case 0x207F: EINA_FALLTHROUGH;
       case 0x2081 ... 0x2084: EINA_FALLTHROUGH;
       case 0x20AC: EINA_FALLTHROUGH;
       case 0x2103: EINA_FALLTHROUGH;
       case 0x2105: EINA_FALLTHROUGH;
       case 0x2109: EINA_FALLTHROUGH;
       case 0x2113: EINA_FALLTHROUGH;
       case 0x2116: EINA_FALLTHROUGH;
       case 0x2121 ... 0x2122: EINA_FALLTHROUGH;
       case 0x2126: EINA_FALLTHROUGH;
       case 0x212B: EINA_FALLTHROUGH;
       case 0x2153 ... 0x2154: EINA_FALLTHROUGH;
       case 0x215B ... 0x215E: EINA_FALLTHROUGH;
       case 0x2160 ... 0x216B: EINA_FALLTHROUGH;
       case 0x2170 ... 0x2179: EINA_FALLTHROUGH;
       case 0x2189: EINA_FALLTHROUGH;
       case 0x2190 ... 0x2199: EINA_FALLTHROUGH;
       case 0x21B8 ... 0x21B9: EINA_FALLTHROUGH;
       case 0x21D2: EINA_FALLTHROUGH;
       case 0x21D4: EINA_FALLTHROUGH;
       case 0x21E7: EINA_FALLTHROUGH;
       case 0x2200: EINA_FALLTHROUGH;
       case 0x2202 ... 0x2203: EINA_FALLTHROUGH;
       case 0x2207 ... 0x2208: EINA_FALLTHROUGH;
       case 0x220B: EINA_FALLTHROUGH;
       case 0x220F: EINA_FALLTHROUGH;
       case 0x2211: EINA_FALLTHROUGH;
       case 0x2215: EINA_FALLTHROUGH;
       case 0x221A: EINA_FALLTHROUGH;
       case 0x221D ... 0x2220: EINA_FALLTHROUGH;
       case 0x2223: EINA_FALLTHROUGH;
       case 0x2225: EINA_FALLTHROUGH;
       case 0x2227 ... 0x222C: EINA_FALLTHROUGH;
       case 0x222E: EINA_FALLTHROUGH;
       case 0x2234 ... 0x2237: EINA_FALLTHROUGH;
       case 0x223C ... 0x223D: EINA_FALLTHROUGH;
       case 0x2248: EINA_FALLTHROUGH;
       case 0x224C: EINA_FALLTHROUGH;
       case 0x2252: EINA_FALLTHROUGH;
       case 0x2260 ... 0x2261: EINA_FALLTHROUGH;
       case 0x2264 ... 0x2267: EINA_FALLTHROUGH;
       case 0x226A ... 0x226B: EINA_FALLTHROUGH;
       case 0x226E ... 0x226F: EINA_FALLTHROUGH;
       case 0x2282 ... 0x2283: EINA_FALLTHROUGH;
       case 0x2286 ... 0x2287: EINA_FALLTHROUGH;
       case 0x2295: EINA_FALLTHROUGH;
       case 0x2299: EINA_FALLTHROUGH;
       case 0x22A5: EINA_FALLTHROUGH;
       case 0x22BF: EINA_FALLTHROUGH;
       case 0x2312: EINA_FALLTHROUGH;
       case 0x231A ... 0x231B: EINA_FALLTHROUGH;
       case 0x2329 ... 0x232A: EINA_FALLTHROUGH;
       case 0x23E9 ... 0x23EC: EINA_FALLTHROUGH;
       case 0x23F0: EINA_FALLTHROUGH;
       case 0x23F3: EINA_FALLTHROUGH;
       case 0x2460 ... 0x24E9: EINA_FALLTHROUGH;
       case 0x24EB ... 0x254B: EINA_FALLTHROUGH;
       case 0x2550 ... 0x2573: EINA_FALLTHROUGH;
       case 0x2580 ... 0x258F: EINA_FALLTHROUGH;
       case 0x2592 ... 0x2595: EINA_FALLTHROUGH;
       case 0x25A0 ... 0x25A1: EINA_FALLTHROUGH;
       case 0x25A3 ... 0x25A9: EINA_FALLTHROUGH;
       case 0x25B2 ... 0x25B3: EINA_FALLTHROUGH;
       case 0x25B6 ... 0x25B7: EINA_FALLTHROUGH;
       case 0x25BC ... 0x25BD: EINA_FALLTHROUGH;
       case 0x25C0 ... 0x25C1: EINA_FALLTHROUGH;
       case 0x25C6 ... 0x25C8: EINA_FALLTHROUGH;
       case 0x25CB: EINA_FALLTHROUGH;
       case 0x25CE ... 0x25D1: EINA_FALLTHROUGH;
       case 0x25E2 ... 0x25E5: EINA_FALLTHROUGH;
       case 0x25EF: EINA_FALLTHROUGH;
       case 0x25FD ... 0x25FE: EINA_FALLTHROUGH;
       case 0x2605 ... 0x2606: EINA_FALLTHROUGH;
       case 0x2609: EINA_FALLTHROUGH;
       case 0x260E ... 0x260F: EINA_FALLTHROUGH;
       case 0x2614 ... 0x2615: EINA_FALLTHROUGH;
       case 0x261C: EINA_FALLTHROUGH;
       case 0x261E: EINA_FALLTHROUGH;
       case 0x2640: EINA_FALLTHROUGH;
       case 0x2642: EINA_FALLTHROUGH;
       case 0x2648 ... 0x2653: EINA_FALLTHROUGH;
       case 0x2660 ... 0x2661: EINA_FALLTHROUGH;
       case 0x2663 ... 0x2665: EINA_FALLTHROUGH;
       case 0x2667 ... 0x266A: EINA_FALLTHROUGH;
       case 0x266C ... 0x266D: EINA_FALLTHROUGH;
       case 0x266F: EINA_FALLTHROUGH;
       case 0x267F: EINA_FALLTHROUGH;
       case 0x2693: EINA_FALLTHROUGH;
       case 0x269E ... 0x269F: EINA_FALLTHROUGH;
       case 0x26A1: EINA_FALLTHROUGH;
       case 0x26AA ... 0x26AB: EINA_FALLTHROUGH;
       case 0x26BD ... 0x26BF: EINA_FALLTHROUGH;
       case 0x26C4 ... 0x26E1: EINA_FALLTHROUGH;
       case 0x26E3: EINA_FALLTHROUGH;
       case 0x26E8 ... 0x26FF: EINA_FALLTHROUGH;
       case 0x2705: EINA_FALLTHROUGH;
       case 0x270A ... 0x270B: EINA_FALLTHROUGH;
       case 0x2728: EINA_FALLTHROUGH;
       case 0x273D: EINA_FALLTHROUGH;
       case 0x274C: EINA_FALLTHROUGH;
       case 0x274E: EINA_FALLTHROUGH;
       case 0x2753 ... 0x2755: EINA_FALLTHROUGH;
       case 0x2757: EINA_FALLTHROUGH;
       case 0x2776 ... 0x277F: EINA_FALLTHROUGH;
       case 0x2795 ... 0x2797: EINA_FALLTHROUGH;
       case 0x27B0: EINA_FALLTHROUGH;
       case 0x27BF: EINA_FALLTHROUGH;
       case 0x2B1B ... 0x2B1C: EINA_FALLTHROUGH;
       case 0x2B50: EINA_FALLTHROUGH;
       case 0x2B55 ... 0x2B59: EINA_FALLTHROUGH;
       case 0x2E80 ... 0x303E: EINA_FALLTHROUGH;
       case 0x3041 ... 0x4DBF: EINA_FALLTHROUGH;
       case 0x4E00 ... 0xA4C6: EINA_FALLTHROUGH;
       case 0xA960 ... 0xA97C: EINA_FALLTHROUGH;
       case 0xAC00 ... 0xD7A3: EINA_FALLTHROUGH;
       case 0xF900 ... 0xFAD9: EINA_FALLTHROUGH;
       case 0xFE00 ... 0xFE19: EINA_FALLTHROUGH;
       case 0xFE30 ... 0xFE6B: EINA_FALLTHROUGH;
       case 0xFF01 ... 0xFF60: EINA_FALLTHROUGH;
       case 0xFFE0 ... 0xFFE6: EINA_FALLTHROUGH;
       case 0xFFFD: EINA_FALLTHROUGH;
       case 0x16FE0 ... 0x1B2FB: EINA_FALLTHROUGH;
       case 0x1F004: EINA_FALLTHROUGH;
       case 0x1F0CF: EINA_FALLTHROUGH;
       case 0x1F100 ... 0x1F10A: EINA_FALLTHROUGH;
       case 0x1F110 ... 0x1F12D: EINA_FALLTHROUGH;
       case 0x1F130 ... 0x1F169: EINA_FALLTHROUGH;
       case 0x1F170 ... 0x1F1AC: EINA_FALLTHROUGH;
       case 0x1F200 ... 0x1F320: EINA_FALLTHROUGH;
       case 0x1F32D ... 0x1F335: EINA_FALLTHROUGH;
       case 0x1F337 ... 0x1F37C: EINA_FALLTHROUGH;
       case 0x1F37E ... 0x1F393: EINA_FALLTHROUGH;
       case 0x1F3A0 ... 0x1F3CA: EINA_FALLTHROUGH;
       case 0x1F3CF ... 0x1F3D3: EINA_FALLTHROUGH;
       case 0x1F3E0 ... 0x1F3F0: EINA_FALLTHROUGH;
       case 0x1F3F4: EINA_FALLTHROUGH;
       case 0x1F3F8 ... 0x1F43E: EINA_FALLTHROUGH;
       case 0x1F440: EINA_FALLTHROUGH;
       case 0x1F442 ... 0x1F4FC: EINA_FALLTHROUGH;
       case 0x1F4FF ... 0x1F53D: EINA_FALLTHROUGH;
       case 0x1F54B ... 0x1F54E: EINA_FALLTHROUGH;
       case 0x1F550 ... 0x1F567: EINA_FALLTHROUGH;
       case 0x1F57A: EINA_FALLTHROUGH;
       case 0x1F595 ... 0x1F596: EINA_FALLTHROUGH;
       case 0x1F5A4: EINA_FALLTHROUGH;
       case 0x1F5FB ... 0x1F64F: EINA_FALLTHROUGH;
       case 0x1F680 ... 0x1F6C5: EINA_FALLTHROUGH;
       case 0x1F6CC: EINA_FALLTHROUGH;
       case 0x1F6D0 ... 0x1F6D2: EINA_FALLTHROUGH;
       case 0x1F6D5 ... 0x1F6DF: EINA_FALLTHROUGH;
       case 0x1F6EB ... 0x1F6EC: EINA_FALLTHROUGH;
       case 0x1F6F4 ... 0x1F6FC: EINA_FALLTHROUGH;
       case 0x1F7E0 ... 0x1F7F0: EINA_FALLTHROUGH;
       case 0x1F90C ... 0x1F93A: EINA_FALLTHROUGH;
       case 0x1F93C ... 0x1F945: EINA_FALLTHROUGH;
       case 0x1F947 ... 0x1F9FF: EINA_FALLTHROUGH;
       case 0x1FA70 ... 0x1FAF8: EINA_FALLTHROUGH;
       case 0x20000 ... 0x323AF: EINA_FALLTHROUGH;
       case 0xE0100 ... 0xE01EF:

        return EINA_TRUE;
    }
   return EINA_FALSE;
}

__attribute__((const))
Eina_Bool
_termpty_is_wide(Eina_Unicode g)
{
    switch (g)
      {
       case 0x1100 ... 0x115F: EINA_FALLTHROUGH;
       case 0x231A ... 0x231B: EINA_FALLTHROUGH;
       case 0x2329 ... 0x232A: EINA_FALLTHROUGH;
       case 0x23E9 ... 0x23EC: EINA_FALLTHROUGH;
       case 0x23F0: EINA_FALLTHROUGH;
       case 0x23F3: EINA_FALLTHROUGH;
       case 0x25FD ... 0x25FE: EINA_FALLTHROUGH;
       case 0x2614 ... 0x2615: EINA_FALLTHROUGH;
       case 0x2648 ... 0x2653: EINA_FALLTHROUGH;
       case 0x267F: EINA_FALLTHROUGH;
       case 0x2693: EINA_FALLTHROUGH;
       case 0x26A1: EINA_FALLTHROUGH;
       case 0x26AA ... 0x26AB: EINA_FALLTHROUGH;
       case 0x26BD ... 0x26BE: EINA_FALLTHROUGH;
       case 0x26C4 ... 0x26C5: EINA_FALLTHROUGH;
       case 0x26CE: EINA_FALLTHROUGH;
       case 0x26D4: EINA_FALLTHROUGH;
       case 0x26EA: EINA_FALLTHROUGH;
       case 0x26F2 ... 0x26F3: EINA_FALLTHROUGH;
       case 0x26F5: EINA_FALLTHROUGH;
       case 0x26FA: EINA_FALLTHROUGH;
       case 0x26FD: EINA_FALLTHROUGH;
       case 0x2705: EINA_FALLTHROUGH;
       case 0x270A ... 0x270B: EINA_FALLTHROUGH;
       case 0x2728: EINA_FALLTHROUGH;
       case 0x274C: EINA_FALLTHROUGH;
       case 0x274E: EINA_FALLTHROUGH;
       case 0x2753 ... 0x2755: EINA_FALLTHROUGH;
       case 0x2757: EINA_FALLTHROUGH;
       case 0x2795 ... 0x2797: EINA_FALLTHROUGH;
       case 0x27B0: EINA_FALLTHROUGH;
       case 0x27BF: EINA_FALLTHROUGH;
       case 0x2B1B ... 0x2B1C: EINA_FALLTHROUGH;
       case 0x2B50: EINA_FALLTHROUGH;
       case 0x2B55: EINA_FALLTHROUGH;
       case 0x2E80 ... 0x303E: EINA_FALLTHROUGH;
       case 0x3041 ... 0x3247: EINA_FALLTHROUGH;
       case 0x3250 ... 0x4DBF: EINA_FALLTHROUGH;
       case 0x4E00 ... 0xA4C6: EINA_FALLTHROUGH;
       case 0xA960 ... 0xA97C: EINA_FALLTHROUGH;
       case 0xAC00 ... 0xD7A3: EINA_FALLTHROUGH;
       case 0xF900 ... 0xFAD9: EINA_FALLTHROUGH;
       case 0xFE10 ... 0xFE19: EINA_FALLTHROUGH;
       case 0xFE30 ... 0xFE6B: EINA_FALLTHROUGH;
       case 0xFF01 ... 0xFF60: EINA_FALLTHROUGH;
       case 0xFFE0 ... 0xFFE6: EINA_FALLTHROUGH;
       case 0x16FE0 ... 0x1B2FB: EINA_FALLTHROUGH;
       case 0x1F004: EINA_FALLTHROUGH;
       case 0x1F0CF: EINA_FALLTHROUGH;
       case 0x1F18E: EINA_FALLTHROUGH;
       case 0x1F191 ... 0x1F19A: EINA_FALLTHROUGH;
       case 0x1F200 ... 0x1F320: EINA_FALLTHROUGH;
       case 0x1F32D ... 0x1F335: EINA_FALLTHROUGH;
       case 0x1F337 ... 0x1F37C: EINA_FALLTHROUGH;
       case 0x1F37E ... 0x1F393: EINA_FALLTHROUGH;
       case 0x1F3A0 ... 0x1F3CA: EINA_FALLTHROUGH;
       case 0x1F3CF ... 0x1F3D3: EINA_FALLTHROUGH;
       case 0x1F3E0 ... 0x1F3F0: EINA_FALLTHROUGH;
       case 0x1F3F4: EINA_FALLTHROUGH;
       case 0x1F3F8 ... 0x1F43E: EINA_FALLTHROUGH;
       case 0x1F440: EINA_FALLTHROUGH;
       case 0x1F442 ... 0x1F4FC: EINA_FALLTHROUGH;
       case 0x1F4FF ... 0x1F53D: EINA_FALLTHROUGH;
       case 0x1F54B ... 0x1F54E: EINA_FALLTHROUGH;
       case 0x1F550 ... 0x1F567: EINA_FALLTHROUGH;
       case 0x1F57A: EINA_FALLTHROUGH;
       case 0x1F595 ... 0x1F596: EINA_FALLTHROUGH;
       case 0x1F5A4: EINA_FALLTHROUGH;
       case 0x1F5FB ... 0x1F64F: EINA_FALLTHROUGH;
       case 0x1F680 ... 0x1F6C5: EINA_FALLTHROUGH;
       case 0x1F6CC: EINA_FALLTHROUGH;
       case 0x1F6D0 ... 0x1F6D2: EINA_FALLTHROUGH;
       case 0x1F6D5 ... 0x1F6DF: EINA_FALLTHROUGH;
       case 0x1F6EB ... 0x1F6EC: EINA_FALLTHROUGH;
       case 0x1F6F4 ... 0x1F6FC: EINA_FALLTHROUGH;
       case 0x1F7E0 ... 0x1F7F0: EINA_FALLTHROUGH;
       case 0x1F90C ... 0x1F93A: EINA_FALLTHROUGH;
       case 0x1F93C ... 0x1F945: EINA_FALLTHROUGH;
       case 0x1F947 ... 0x1F9FF: EINA_FALLTHROUGH;
       case 0x1FA70 ... 0x1FAF8: EINA_FALLTHROUGH;
       case 0x20000 ... 0x323AF:

        return EINA_TRUE;
    }
   return EINA_FALSE;
}
