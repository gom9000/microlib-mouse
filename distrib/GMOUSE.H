/* gmouse.h: Header file */

/* FUNCTIONS */
int  mouse_init(void);
void mouse_show(int);
void set_mouse_position(int, int);
void get_mouse_position(int*, int*);
int  get_mouse_button_pressed(void);
void set_mouse_vel(int);
void set_mouse_sensitivity(int);
int  get_mouse_sensitivity(void);
int  get_mouse_type(void);
int  get_mouse_irq(void);
int  get_mouse_motion(void);
int  mouse_button_press(int*, int*, int);
int  mouse_button_release(int*, int*, int);

/* MACROS */


/* CONSTANTS */
#define NO_MOUSE_DETECTED  -1

#define BUS_MOUSE           1
#define SERIAL_MOUSE        2
#define PS2_MOUSE           4

#define NO_BUTTON_PRESSED   0
#define L_BUTTON            1
#define R_BUTTON            2
#define M_BUTTON            4
#define LR_BUTTON           3
#define LM_BUTTON           5
#define RM_BUTTON           6
#define LRM_BUTTON          7

#define NOT_MOVED           0
#define LEFT                1
#define RIGHT               2
#define UP                  4
#define DOWN                8
#define LEFT_UP             5
#define RIGHT_UP            6
#define LEFT_DOWN           9
#define RIGHT_DOWN         10
