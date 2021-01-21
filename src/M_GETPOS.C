/*-----------------------------------------------------------------------------
* File            : M_GETPOS.C
* Autore          : Alessandro
* Funzione        : Get current cursor position
* Parametri in    : int *x, *y position
* Note            :
*-----------------------------------------------------------------------------*/
/******************************************************************************
INT 33 - MS MOUSE v1.0+ - RETURN POSITION AND BUTTON STATUS
        AX = 0003h
Return: BX = button status (see #1615)
        CX = column
        DX = row
Note:   in text modes, all coordinates are specified as multiples of the cell
          size, typically 8x8 pixels
SeeAlso: AX=0004h,AX=000Bh,INT 2F/AX=D000h"ZWmous"

Bitfields for mouse button status:
Bit(s)  Description     (Table 1615)
 0      left button pressed if 1
 1      right button pressed if 1
 2      middle button pressed if 1 (Mouse Systems/Logitech/Genius)
******************************************************************************/
#include <dos.h>

void get_mouse_position(int *x, int *y)
{
   union REGS r;

   r.x.ax = 3;
   int86(0x33, &r, &r);
   *x = r.x.cx;
   *y = r.x.dx;
}
