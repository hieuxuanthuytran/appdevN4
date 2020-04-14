#define ESC 27
enum FG {BLACK=30,RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN,WHITE};
#define bg(c) (c+10)

#define UNICODE
//#define BAR "\u2590"
#define BAR "\u2588"

#define DEBUG

// the following is the information of cursor position, this inf will be
//decoded by an escape sequence ESC[6n, and query reply should be a string
// consisting row and col numbers of the cursor. 
typedef struct{
	int row;
	int col;
}Position;

void setfgcolor(int);
void setbgcolor(int);
void resetcolors(void);
void setcolors(int, int);
void clearscreen(void);
void gotoXY(int, int);
void drawbar(int, int);
void drawobject(int,int);
Position getscreensize(void); //this function returns a compound date(2 ints)
