/* Usually in a header file we have 2 parts:
	1. constant definitions: making a constant in a name will make your program more meaningful/readable.
	2. function declarations */

/*	1. Constant definitions */

#define ESC 27		// or using hex 0x1B

#define bg(c) (c+10)

#define UNICODE

#define BAR "\u2588"

#define DEBUG

enum FG {BLACK=30,RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN,WHITE};	// make enumeration for fg colors

/*	The following is the information of cursor position, this inf will be
	decoded by an escape sequence ESC[6n, and query reply should be a string
	consisting row and col numbers of the cursor. */
	
typedef struct{
	int row;
	int col;
}Position;

/* 2. Function declarations */

void setfgcolor(int);
void setbgcolor(int);
void resetcolors(void);
void setcolors(int, int);
void clearscreen(void);
void gotoXY(int, int);
void drawbar(int, int);
void drawobject(int,int);
Position getscreensize(void);	 // this function returns a compound date(2 ints)
int devicestatus(void);
