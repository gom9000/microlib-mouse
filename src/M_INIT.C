/*-----------------------------------------------------------------------------
* File            : M_INIT.C
* Autore          : Alessandro
* Funzione        : Reset driver and read mouse status
* Parametri in    : void
* Parametri out   : int :  -1 = hardware/driver not installed
                            2 = number of buttons is 2
                            3 = Mouse System/Logitec three button mouse
                            5 = other than two
* Note            :
*-----------------------------------------------------------------------------*/
/******************************************************************************
INT 33 - MS MOUSE - RESET DRIVER AND READ STATUS
        AX = 0000h
Return: AX = status
            0000h hardware/driver not installed
            FFFFh hardware/driver installed
        BX = number of buttons
            0000h other than two
            0002h two buttons (many drivers)
            0003h Mouse Systems/Logitech three-button mouse
            FFFFh two buttons
Notes:  to use mouse on a Hercules-compatible monographics card in graphics
          mode, you must first set 0040h:0049h to 6 for page 0 or 5 for page 1,
          and then call this function.  Logitech drivers v5.01 and v6.00
          reportedly do not correctly use Hercules graphics in dual-monitor
          systems, while version 4.10 does.
        the Logitech mouse driver contains the signature string "LOGITECH"
          three bytes past the interrupt handler; many of the Logitech mouse
          utilities check for this signature.
SeeAlso: AX=0011h,AX=0021h,AX=002Fh,INT 62/AX=007Ah,INT 74
******************************************************************************/
#include <dos.h>

int mouse_init(void)
{
   union REGS r;

   r.x.ax = 0;
   int86(0x33, &r, &r);
/*   if( (int)r.x.ax != -1 )*/
   if( (int)r.x.ax == 0 )
      return -1;
   if( r.x.bx == 2 || (int)r.x.bx == -1 )
      return 2;
   if( r.x.bx == 3 )
      return 3;
   return 5;
}
