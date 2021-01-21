/*-----------------------------------------------------------------------------
* File            : M_GETMOV.C
* Autore          : Alessandro
* Funzione        : Read motion status
* Parametri in    : void
* Parametri out   : int :  horizontally and vertically mouse direction
                           0000 = NOT_MOVED
                           0001 = LEFT
                           0010 = RIGHT
                           0100 = UP
                           0101 = LEFT UP
                           0110 = RIGHT UP
                           1000 = DOWN
                           1001 = LEFT DOWN
                           1010 = RIGHT DOWN
* Note            :
*-----------------------------------------------------------------------------*/
/******************************************************************************
INT 33 - MS MOUSE v1.0+ - READ MOTION COUNTERS
        AX = 000Bh
Return: CX = number of mickeys mouse moved horizontally since last call
        DX = number of mickeys mouse moved vertically
Notes:  a mickey is the smallest increment the mouse can sense
        positive values indicate down/right
SeeAlso: AX=0003h,AX=001Bh,AX=0027h
******************************************************************************/
#include <dos.h>

int get_mouse_motion(void)
{
   union REGS r;
   int flag = 0;

   r.x.ax = 0xb;
   int86(0x33, &r, &r);
   if( (int)r.x.cx > 0 ) flag |= 1;
   if( (int)r.x.cx < 0 ) flag |= 2;
   if( (int)r.x.dx > 0 ) flag |= 4;
   if( (int)r.x.dx < 0 ) flag |= 8;
   return flag;
}
