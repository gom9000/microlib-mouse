/*-----------------------------------------------------------------------------
* File            : M_GETIRQ.C
* Autore          : Alessandro
* Funzione        : Get mouse type
* Parametri in    : void
* Parametri out   : int irq (0=PS/2, 2=IRQ2, 3=IRQ3,...,7=IRQ7)
* Note            :
*-----------------------------------------------------------------------------*/
/******************************************************************************
INT 33 - MS MOUSE v6.26+ - GET SOFTWARE VERSION, MOUSE TYPE, AND IRQ NUMBER
        AX = 0024h
Return: AX = FFFFh on error
        otherwise,
            BH = major version
            BL = minor version
            CH = type (1=bus, 2=serial, 3=InPort, 4=PS/2, 5=HP)
            CL = interrupt (0=PS/2, 2=IRQ2, 3=IRQ3,...,7=IRQ7)
SeeAlso: AX=004Dh,AX=006Dh
******************************************************************************/
#include <dos.h>

int get_mouse_irq(void)
{
   union REGS r;

   r.x.ax = 0x24;
   int86(0x33, &r, &r);
   return (int)r.h.cl;
}
