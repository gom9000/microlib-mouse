# Micro Mouse Library (Version 1.0 - 13/09/1999)


	*******************************************************************************

	#include gmouse.h
	int mouse_init()

	Resetta il Driver del mouse e restituisce un intero positivo che rappresenta il
	numero di bottoni, oppure -1 se non viene trovato il mouse stesso.

	*******************************************************************************

	#include gmouse.h
	void mouse_show(mode)
	int mode

	Visualizza o nasconde il puntatore del mouse.

	*******************************************************************************

	#include gmouse.h
	void set_mpos(x, y)
	int x, y

	Sposta il puntatore del mouse alle coordinate specificate in pixel da x, y.

	*******************************************************************************

	#include gmouse.h
	void get_mpos(x, y)
	int *x, *y

	Ritorna in x,y le coordinate correnti in pixel del puntatore del mouse.

	*******************************************************************************

	#include gmouse.h
	int get_mouse_button_pressed()

	Ritorna un intero positivo che rappresenta i bottoni del mouse correntemente
	premuti. Se nessun bottone e' premuto restituisce 0.
	I valori possibili sono:
	 0  =  NO_BUTTON_PRESSED       nessun tasto premuto
	 1  =  L_BUTTON                tasto sinistro premuto
	 2  =  R_BUTTON                tasto destro premuto
	 4  =  M_BUTTON                tasto centrale premuto
	 3  =  LR_BUTTON               tasti sinistro+destro premuti
	 5  =  LM_BUTTON               tasti sinistro+centrale premuti
	 6  =  RM_BUTTON               tasti destro+centrale premuti
	 7  =  LRM_BUTTON              tutti e tre i tasti premuti
	dove le macro utilizzate sono definite nel file di intestazione gmouse.h.

	*******************************************************************************

	#include gmouse.h
	void set_mouse_vel()

	Setta la velocita' di spostamento del puntatore del mouse.

	*******************************************************************************

	#include gmouse.h
	void set_mouse_sensitivity()
	int speed

	Setta la sensibilita' di spostamento del mouse.

	*******************************************************************************

	#include gmouse.h
	int get_mouse_sensitivity()

	Ritorna la sensibilita' di spostamento del mouse correntemente selezionata.

	*******************************************************************************

	#include gmouse.h
	int get_mouse_type()

	Ritorna il tipo di mouse correntemente istallato. I valori possibili sono:
	 1  =  BUS_MOUSE                mouse cablato su scheda madre
	 2  =  SERIAL_MOUSE             mouse connesso ad una porta seriale
	 4  =  PS2_MOUSE                mouse connesso ad una porta PS/2
	dove le macro utilizzate sono definite nel file di intestazione gmouse.h.

	*******************************************************************************

	#include gmouse.h
	int get_mouse_irq()

	Ritorna l'interrupt utilizzata dal mouse correntemente istallato.

	*******************************************************************************

	#include gmouse.h
	int get_mouse_motion()

	Ritorna lo stato di moto del mouse. I valori possibili sono:
	 0  =  NOT_MOVED
	 1  =  LEFT
	 2  =  RIGHT
	 4  =  UP
	 8  =  DOWN
	 5  =  LEFT_UP
	 6  =  RIGHT_UP
	 9  =  LEFT_DOWN
	 10 =  RIGHT_DOWN
	dove le macro utilizzate sono definite nel file di intestazione gmouse.h.

	*******************************************************************************

	#include gmouse.h
	int mouse_button_press(x, y, button)
	int x, y, button

	Ritorna in x,y la posizione del cursore al momento dell'ultima pressione del
	bottone specificato in button, e il numero di volte in cui lo stesso e' stato
	premuto dall'ultima chiamata.

	*******************************************************************************

	#include gmouse.h
	int mouse_button_release(x, y, button)
	int x, y, button

	Ritorna in x,y la posizione del cursore al momento dell'ultimo rilascio del
	bottone specificato in button, e il numero di volte in cui lo stesso e' stato
	rilasciato dall'ultima chiamata.

	*******************************************************************************