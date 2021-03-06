/***************************************************************************

 NBitmap.mcc - New Bitmap MUI Custom Class
 Copyright (C) 2006 by Daniel Allsopp
 Copyright (C) 2007-2018 NList Open Source Team

 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.

 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.

 NList classes Support Site:  http://www.sf.net/projects/nlist-classes

 $Id$

***************************************************************************/

#ifndef DITHERIMAGE_H
#define DITHERIMAGE_H 1

#ifndef EXEC_TYPES_H
  #include <exec/types.h>
#endif
#ifndef UTILITY_TAGITEM_H
  #include <utility/tagitem.h>
#endif
#ifndef SDI_STDARG_H
  #include <SDI_stdarg.h>
#endif

APTR DitherImageA(CONST_APTR data, struct TagItem *tags);
#if defined(__AROS__) || defined(__MORPHOS__)
#define DitherImage(data, ...) \
 ({ IPTR __args[] = { SDI_VACAST(__VA_ARGS__) }; \
    DitherImageA(data, (struct TagItem *)__args); })
#else
APTR STDARGS VARARGS68K DitherImage(CONST_APTR data, ...);
#endif
void FreeDitheredImage(APTR image, APTR mask);

#define DITHERA_Width                  (TAG_USER+2)
#define DITHERA_Height                 (TAG_USER+3)
#define DITHERA_Format                 (TAG_USER+4)
#define DITHERA_ColorMap               (TAG_USER+5)
#define DITHERA_ColorMapSize           (TAG_USER+6)
#define DITHERA_IsDefaultColorMap      (TAG_USER+7)
#define DITHERA_PenMap                 (TAG_USER+8)
#define DITHERA_MaskPlane              (TAG_USER+9)

#define PADWIDTH(w) (((((UWORD)(w))+15)>>4) << 4)
#define RAWWIDTH(w) ((((UWORD)(w))+15)>>3 & 0xFFFE)

#endif /* DITHERIMAGE_H */
