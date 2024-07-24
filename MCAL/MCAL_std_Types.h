/* 
 * File:   MCAL_std_Types.h
 * Author: hp
 *
 * Created on 09 ?????, 2023, 10:12 ?
 */

#ifndef MCAL_STD_TYPES_H
#define	MCAL_STD_TYPES_H

/* Section : includes */
#include "std_libraries.h"
#include "compiler.h"

/* Section : Data Type Declarations */
typedef unsigned char   uint8; 
typedef unsigned short  uint16;
typedef unsigned int    uint32;
typedef signed char     sint8; 
typedef signed short    sint16;
typedef signed int      sint32;
typedef float           f32;
typedef uint8           Std_ReturnType;

/* Section : Macro Declarations */
#define STD_HIGH       0x01
#define STD_LOW        0x00


#define STD_ON         0x01
#define STD_OFF        0x00

#define STD_ACTIVE     0x01
#define STD_IDEAL      0x00

#define E_OK           (Std_ReturnType)0x01;
#define E_NOK          (Std_ReturnType)0x00; 


/* Section : Macro Function Declarations */


/* Section : Function Declarations */

#endif	/* MCAL_STD_TYPES_H */

