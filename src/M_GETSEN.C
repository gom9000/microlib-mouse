/*-----------------------------------------------------------------------------
* File            : M_GETSEN.C
* Autore          : Alessandro
* Funzione        : Get mouse sensitivity
* Parametri in    : void
* Parametri out   : int  : mouse speed
* Note            :
*-----------------------------------------------------------------------------*/
/******************************************************************************
INT 33 - MS MOUSE v6.0+ - RETURN MOUSE SENSITIVITY
        AX = 001Bh
Return: BX = horizontal speed
        CX = vertical speed
        DX = double speed threshold
SeeAlso: AX=000Bh,AX=001Ah
******************************************************************************/
#include <dos.h>

int get_mouse_sensitivity(void)
{
   union REGS r;

   r.x.ax = 0x1b;
   int86(0x33, &r, &r);
   return (int)r.x.bx;
}
