/*-----------------------------------------------------------------------------
* File            : M_SETPOS.C
* Autore          : Alessandro
* Funzione        : Set mouse cursor position
* Parametri in    : int x, y pixel position
* Note            :
*-----------------------------------------------------------------------------*/
/******************************************************************************
INT 33 - MS MOUSE v1.0+ - POSITION MOUSE CURSOR
        AX = 0004h
        CX = column
        DX = row
Note:   the row and column are truncated to the next lower multiple of the cell
          size (typically 8x8 in text modes); however, some versions of the
          Microsoft documentation incorrectly state that the coordinates are
          rounded
SeeAlso: AX=0003h,INT 62/AX=0081h
******************************************************************************/
#include <dos.h>

void set_mouse_position(int x, int y)
{
   union REGS r;

   r.x.ax = 4;
   r.x.cx = x;
   r.x.dx = y;
   int86(0x33, &r, &r);
}
