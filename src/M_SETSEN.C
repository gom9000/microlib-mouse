/*-----------------------------------------------------------------------------
* File            : M_SETSEN.C
* Autore          : Alessandro
* Funzione        : Set mouse sensitivity
* Parametri in    : int : mouse speed
* Parametri out   : void
* Note            :
*-----------------------------------------------------------------------------*/
/******************************************************************************
INT 33 - MS MOUSE v6.0+ - SET MOUSE SENSITIVITY
        AX = 001Ah
        BX = horizontal speed \
        CX = vertical speed   / (see AX=000Fh)
        DX = double speed threshold (see AX=0013h)
SeeAlso: AX=0013h,AX=001Bh,INT 62/AX=0082h
******************************************************************************/
#include <dos.h>

void set_mouse_sensitivity(int speed)
{
   union REGS r;

   r.x.ax = 0x1a;
   r.x.bx = speed;
   r.x.cx = 2*speed;
   int86(0x33, &r, &r);
}
