/*-----------------------------------------------------------------------------
* File            : M_SHOW.C
* Autore          : Alessandro
* Funzione        : Hide/show mouse cursor
* Parametri in    : int mode:     0 - hide cursor
                              not 0 - show cursor
* Parametri out   : void
* Note            : multiple calls to mouse_show(1) will not require multiple
                    calls to mouse_show(0) to unhide it.
*-----------------------------------------------------------------------------*/
/******************************************************************************
INT 33 - MS MOUSE v1.0+ - SHOW MOUSE CURSOR
        AX = 0001h
SeeAlso: AX=0002h,INT 16/AX=FFFEh,INT 62/AX=007Bh
-------------------------------------------
INT 33 - MS MOUSE v1.0+ - HIDE MOUSE CURSOR
        AX = 0002h
Note:   multiple calls to hide the cursor will require multiple calls to
          function 01h to unhide it.
SeeAlso: AX=0001h,AX=0010h,INT 16/AX=FFFFh,INT 62/AX=007Bh
******************************************************************************/
#include <dos.h>

void mouse_show(int mode)
{
   union REGS r;

   if(mode)  r.x.ax = 1;
   else      r.x.ax = 0;
   int86(0x33, &r, &r);
}
