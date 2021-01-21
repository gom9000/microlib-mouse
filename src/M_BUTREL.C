/*-----------------------------------------------------------------------------
* File            : M_BUTREL.C
* Autore          : Alessandro
* Funzione        : Return button release data
* Parametri in    : int *x : column at time specified button was last released
*                   int *y : row at time specified button was last released
*                   int b  : button number (0=left, 1=right, 2=middle)
* Parametri out   : int    : number of times specified button has been released
*                            since last call
* Note            :
*-----------------------------------------------------------------------------*/
/******************************************************************************
INT 33 - MS MOUSE v1.0+ - RETURN BUTTON RELEASE DATA
        AX = 0006h
        BX = button number (see #1616)
Return: AX = button states (see #1615)
        BX = number of times specified button has been released since last call
        CX = column at time specified button was last released
        DX = row at time specified button was last released
Note:   at least for the Genius mouse driver, the number of button releases
          returned is limited to 7FFFh
SeeAlso: AX=0005h,INT 62/AX=007Ch
******************************************************************************/
#include <dos.h>

int mouse_button_release(int *x, int *y, int button)
{
   union REGS r;

   r.x.ax = 6;
   r.x.bx = button>>1;
   int86(0x33, &r, &r);
   *x = r.x.cx;
   *y = r.x.dx;
   return r.x.bx;
}
