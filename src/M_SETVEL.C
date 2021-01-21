/*-----------------------------------------------------------------------------
* File            : M_SETVEL.C
* Autore          : Alessandro
* Funzione        : Set cursor velocity
* Parametri in    : int :  cursor velocity (mikey/pixel ratio)
* Parametri out   : void
* Note            :
*-----------------------------------------------------------------------------*/
/******************************************************************************
INT 33 - MS MOUSE v1.0+ - DEFINE MICKEY/PIXEL RATIO
        AX = 000Fh
        CX = number of mickeys per 8 pixels horizontally (default 8)
        DX = number of mickeys per 8 pixels vertically (default 16)
SeeAlso: AX=0013h,AX=001Ah,INT 62/AX=0082h
******************************************************************************/
#include <dos.h>

void set_mouse_vel(int v)
{
   union REGS r;

   r.x.ax = 0xf;
   r.x.cx = v;
   r.x.dx = 2*v;
   int86(0x33, &r, &r);
}
