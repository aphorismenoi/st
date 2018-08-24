/* Terminal colors (16 first used in escape sequence) */
const char *colorname[] = {
	/* 8 normal colors */
	"#282A2E", /* t_current_line */
	"#AC4142", /* b_red */
	"#90A959", /* b_green */
	"#DE935F", /* t_orange */
	"#6A9FB5", /* b_blue */
	"#AA759F", /* b_purple */
	"#75B5AA", /* b_aqua */
	"#707880", /* t_comment */

	/* 8 bright colors */
	"#373B41", /* t_selection */
	"#CC6666", /* t_red */
	"#B5BD68", /* t_green */
	"#F4BF75", /* t_yellow */
	"#81A2BE", /* t_blue */
	"#B294BB", /* t_purple */
	"#8ABEB7", /* t_aqua */
	"#C5C8C6", /* t_foreground */

	[255] = 0,

	/* more colors can be added after 255 to use with DefaultXX */
	"#1D1F21", /* t_background */
	"#C5C8C6", /* t_foreground */
};

/*
 * Default colors (colorname index)
 * foreground, background, cursor, reverse cursor
 */
unsigned int defaultfg = 257;
unsigned int defaultbg = 256;
static unsigned int defaultcs = 11;
static unsigned int defaultrcs = 256;

