/*-----------------------------------------------------------------------------
* File            : M_BUTPRE.C
* Autore          : Alessandro
* Funzione        : Return button press data
* Parametri in    : int *x : column at time specified button was last pressed
*                   int *y : row at time specified button was last pressed
*                   int b  : button number (0=left, 1=right, 2=middle)
* Parametri out   : int    : number of times specified button has been pressed
*                            since last call
* Note            :
*-----------------------------------------------------------------------------*/
/******************************************************************************
INT 33 - MS MOUSE v1.0+ - RETURN BUTTON PRESS DATA
        AX = 0005h
        BX = button number (see #1616)
Return: AX = button states (see #1615)
        BX = number of times specified button has been pressed since last call
        CX = column at time specified button was last pressed
        DX = row at time specified button was last pressed
Note:   at least for the Genius mouse driver, the number of button presses
          returned is limited to 7FFFh
SeeAlso: AX=0006h,INT 62/AX=007Ch

(Table 1616)
Values for mouse button number:
 0000h  left
 0001h  right
 0002h  middle (Mouse Systems/Logitech/Genius mouse)
******************************************************************************/
#include <dos.h>

int mouse_button_press(int *x, int *y, int button)
{
   union REGS r;

   r.x.ax = 5;
   r.x.bx = button>>1;
   int86(0x33, &r, &r);
   *x = r.x.cx;
   *y = r.x.dx;
   return r.x.bx;
}
