#include <gb/gb.h>
#include <stdint.h>
//#include <stdio.h> //to use printf function (unused here)

#include "../Plugins/gbt_player.h"
// music data
extern const unsigned char * song_Data[];
/*extern const unsigned char ArthursQuestIntro[];
extern const unsigned char ArthursQuestTheme[];*/

// bank tile data
// title stuff
extern unsigned char Title_Tiles[];
extern unsigned char Title_Map[];
extern unsigned char  Title_TextTiles[];

// world map
//extern unsigned char World_Map_Britain[];
extern unsigned char World_Map_Small[];
extern unsigned char World_Map_Ireland[];
// world tiles
extern unsigned char World_Tiles[];

// castle maps
extern unsigned char Castle0_Map[];
extern unsigned char Castle1_Map[];
extern unsigned char Castle2_Map[];
// castle tiles
extern unsigned char Castle_Tiles[];

// house maps
extern unsigned char Cottage_Map[];
extern unsigned char Brothel_Map[];
extern unsigned char Camp0_Map[];
extern unsigned char Camp1_Map[];
extern unsigned char Camp2_Map[];
extern unsigned char Camp3_Map[];
// house tiles
extern unsigned char Town_Tiles[];

// character sprites
extern unsigned char CharaSprites[];

// text boxes
extern unsigned char Windows_Text[];
// text tiles
extern unsigned char Windows_Tiles[];


void titleScreenAnim() BANKED;


// utility variables
uint8_t i; // for loops
uint8_t j; // for loops

uint8_t ua; // for unsigned temp values
uint16_t ub; // for large unsigned temp values
int8_t sa; // for signed temp values
int16_t sb; // for large signed temp values

uint8_t c; // quest counter
uint8_t q; // quest progress
uint8_t m; // current map (tiles) : 0=title, 1=world, 2=camelot, 3=othcastle, 4=town/camp
uint8_t x; // x coords on current map
uint8_t y; // y coords on current map
int8_t dx; // direction x
int8_t dy; // direction y

// interrupts
unsigned int tim_cnt;
uint8_t fastFrame;
uint8_t frame;
uint8_t slowFrame;



void performantDelay(uint8_t numloops){
	uint8_t ii;
	for(ii=0;ii<numloops;ii++){
		wait_vbl_done();
	}
}

void allSpritesOffScreen(){
	for(i=0;i<40;i++){
		move_sprite(i,0,0);
	}
}

void fadeToBlack(){
	for(i=0;i<4;i++){
		switch(i){
			case 0:
				BGP_REG = 0xE4;
				OBP0_REG = 0xE4;
				break;
			case 1: 
				BGP_REG = 0xF9;
				OBP0_REG = 0xF9;
				break;
			case 2:
				BGP_REG = 0xFE;
				OBP0_REG = 0xFE;
				break;
			case 3:
				BGP_REG = 0xFF;
				OBP0_REG = 0xFF;
				break;
		}
		performantDelay(10);
	} 
}
void fadeFromBlack(){
	for(i=0;i<4;i++){
		switch(i){
			case 0:
				BGP_REG = 0xFF;
				OBP0_REG = 0xFF;
				break;
			case 1:
				BGP_REG = 0xFE;
				OBP0_REG = 0xFE;
				break;
			case 2: 
				BGP_REG = 0xF9;
				OBP0_REG = 0xF9;
				break;
			case 3:
				BGP_REG = 0xE4;
				OBP0_REG = 0xE4;
				break;
		}
		performantDelay(10);
	} 
}
void fadeToWhite(){
	for(i=0;i<4;i++){
		switch(i){
			case 0:
				BGP_REG = 0xE4;
				OBP0_REG = 0xE4;
				break;
			case 1: 
				BGP_REG = 0x90;
				OBP0_REG = 0x90;
				break;
			case 2:
				BGP_REG = 0x40;
				OBP0_REG = 0x40;
				break;
			case 3:
				BGP_REG = 0x00;
				OBP0_REG = 0x00;
				break;
		}
		performantDelay(10);
	} 
}
void fadeFromWhite(){
	for(i=0;i<4;i++){
		switch(i){
			case 0:
				BGP_REG = 0x00;
				OBP0_REG = 0x00;
				break;
			case 1:
				BGP_REG = 0x40;
				OBP0_REG = 0x40;
				break;
			case 2: 
				BGP_REG = 0x90;
				OBP0_REG = 0x90;
				break;
			case 3:
				BGP_REG = 0xE4;
				OBP0_REG = 0xE4;
				break;
		}
		performantDelay(10);
	} 
}





// story maps sprites : always arthur + a knight
void storyMapSprites(){
	allSpritesOffScreen();
	set_sprite_tile(0,0); // knight a
	set_sprite_tile(1,2); // knight b
	move_sprite(0,80,60);
	move_sprite(1,88,60);
	set_sprite_tile(2,52); // arthur a
	set_sprite_tile(3,54); // arthur b
	move_sprite(2,80,80);
	move_sprite(3,88,80);
}

void camelotSprites(){
	allSpritesOffScreen();
	set_sprite_tile(0,16); // merlin a
	set_sprite_tile(1,18); // merlin b
	move_sprite(0,80,36);
	move_sprite(1,88,36);
	set_sprite_tile(2,52); // arthur a
	set_sprite_tile(3,54); // arthur b
	move_sprite(2,80,55);
	move_sprite(3,88,55);
	
	switch (q){
		case 9:
		set_sprite_tile(4,0); // knight 8 a
		set_sprite_tile(5,2); // knight 8 b
		move_sprite(4,124,52);
		move_sprite(5,132,52);
		case 8:
		set_sprite_tile(6,0); // knight 7 a
		set_sprite_tile(7,2); // knight 7 b
		move_sprite(6,22,70);
		move_sprite(7,30,70);
		case 7:
		set_sprite_tile(8,0); // knight 6 a
		set_sprite_tile(9,2); // knight 6 b
		move_sprite(8,36,52);
		move_sprite(9,44,52);
		case 6:
		set_sprite_tile(10,0); // knight 5 a
		set_sprite_tile(11,2); // knight 5 b
		move_sprite(10,134,98);
		move_sprite(11,142,98);
		case 5:
		set_sprite_tile(12,0); // knight 4 a
		set_sprite_tile(13,2); // knight 4 b
		move_sprite(12,26,98);
		move_sprite(13,34,98);
		case 4:
		set_sprite_tile(14,0); // knight 3 a
		set_sprite_tile(15,2); // knight 3 b
		move_sprite(14,104,46);
		move_sprite(15,112,46);
		case 3:
		set_sprite_tile(16,0); // knight 2 a
		set_sprite_tile(17,2); // knight 2 b
		move_sprite(16,138,70);
		move_sprite(17,146,70);
		case 2:
		set_sprite_tile(18,0); // knight 1 a
		set_sprite_tile(19,2); // knight 1 b
		move_sprite(18,56,46);
		move_sprite(19,64,46);
		break;
	}
}

// tiles loading
void loadCastleTiles(){
	set_bkg_data(0, 74u, Castle_Tiles);
}
void loadTownTiles(){
	set_bkg_data(0, 35u, Town_Tiles);
}

// map loading 
void loadMapCamelot(){ // castle camelot
	SWITCH_RAM_MBC1(0);
	loadCastleTiles();
	set_bkg_tiles(0, 0, 20u,18u, Castle0_Map );
}

void loadMapKnight1(){ // percival's cottage
	SWITCH_RAM_MBC1(0);
	loadTownTiles();
	set_bkg_tiles(0, 0, 20u,18u, Cottage_Map );
}

void loadMapKnight2(){ // leondegrance's castle
	SWITCH_RAM_MBC1(0);
	loadCastleTiles();
	set_bkg_tiles(0, 0, 20u,18u, Castle1_Map );
}

void loadMapKnight3(){ // lancelot's camp
	SWITCH_RAM_MBC1(0);
	loadTownTiles();
	set_bkg_tiles(0, 0, 20u,18u, Camp0_Map );
}

void loadMapKnight4(){ // gawain's brothel
	SWITCH_RAM_MBC1(0);
	loadTownTiles();
	set_bkg_tiles(0, 0, 20u,18u, Brothel_Map );
}

void loadMapKnight5(){ // tristan's camp
	SWITCH_RAM_MBC1(0);
	loadTownTiles();
	set_bkg_tiles(0, 0, 20u,18u, Camp1_Map );
}

void loadMapKnight6(){ // caradoc's camp
	SWITCH_RAM_MBC1(0);
	loadTownTiles();
	set_bkg_tiles(0, 0, 20u,18u, Camp2_Map );
}

void loadMapKnight7(){ // galahad's castle
	SWITCH_RAM_MBC1(0);
	loadCastleTiles();
	set_bkg_tiles(0, 0, 20u,18u, Castle2_Map );
}

void loadMapKnight8(){ // mordred's camp
	SWITCH_RAM_MBC1(0);
	loadTownTiles();
	set_bkg_tiles(0, 0, 20u,18u, Camp3_Map );
}

void loadMapKnight(){ // all knights
	switch(q){
		case 1:
		loadMapKnight1();
		break;
		case 2:
		loadMapKnight2();
		break;
		case 3:
		loadMapKnight3();
		break;
		case 4:
		loadMapKnight4();
		break;
		case 5:
		loadMapKnight5();
		break;
		case 6:
		loadMapKnight6();
		break;
		case 7:
		loadMapKnight7();
		break;
		case 8:
		loadMapKnight8();
		break;
	}
}


// world maps
/*void loadMapBritain(){ // world map 1, bank 1
	allSpritesOffScreen();
	set_bkg_data(0, 64u, World_Tiles);
	SWITCH_RAM_MBC1(1);
	// no bg loading here, since it'll have to be updated each step
}
void segmentMapBritain(){
	// base it off of xy coords
	set_bkg_submap();
}*/

/*void loadMapIreland(){ // world map 2, bank 2
	allSpritesOffScreen();
	set_bkg_data(0, 64u, World_Tiles);
	SWITCH_RAM_MBC1(2);
	// no bg loading here, since it'll have to be updated each step
}*/

void loadMapWorld(){
	allSpritesOffScreen();
	set_bkg_data(0, 64u, World_Tiles);
	SWITCH_RAM_MBC1(1);
	set_bkg_tiles(0,0,20,18,World_Map_Small);
}

// text windows
void displayText(uint8_t t){
	ub = 100u*t;
	for(i=0;i<20;i++){
		for(j=0;j<5;j++){
			set_win_tile_xy(i,j,Windows_Text[ub + i + j*20]+206);
		}
	}
	move_win(7,104);
}
void hideText(){
	move_win(7,144);
}
void displayandAPressText(uint8_t t){
	displayText(t);
	waitpad(J_A);
	hideText();
	performantDelay(20);
}

void getDirInput(){
	uint8_t joy = joypad();
	dx = (joy == J_RIGHT) ? 1 : (joy == J_LEFT) ? -1 : 0;
	dy = (joy == J_UP) ? -1 : (joy == J_DOWN) ? 1 : 0;
}

uint8_t downSpriteOffsets[] = {1,1,0,0};
uint8_t upSpriteOffsets[] = {1,1,0,0};
uint8_t sideSpriteOffsets[] = {0,1,1,0};

uint8_t warpCoords[] = 
{
	13,12, // percival
	19,16, // leondegrance
	 4,12, // lancelot
	15, 8, // gawain
	 3,16, // tristan
	13,17, // caradoc
	17,12, // galahad
	13, 3  // mordred
};

uint8_t mapSequence[] = {
	4,3,4,4,4,4,3,4
};

uint8_t checkWarp(){
	uint8_t ii = (q-1)*2;
	if (x==warpCoords[ii] && y==warpCoords[ii+1]){
		return 1;
	}
	return 0;
}

void worldMapSection(){
	ua = q;
	x = 13+1;
	y = 14+1;
	
	set_sprite_tile(2,32); // arthur a
	set_sprite_tile(3,34); // arthur b
	move_sprite(2,x*8,y*8-3);
	move_sprite(3,x*8+8,y*8-3);
	
	fadeFromWhite();
	
	while (ua==q){
		getDirInput();
		if (dy==1 && y!=18){
			set_sprite_prop(2,0x00);
			set_sprite_prop(3,0x00);
			if (World_Map_Small[x-1+(y+0)*20]!=44 && World_Map_Small[x+0+(y+0)*20]!=44){
				for(i=0; i<4; i++){
					//set_sprite_tile(2,32+downSpriteOffsets[i]*4); // arthur a
					//set_sprite_tile(3,34+downSpriteOffsets[i]*4); // arthur b
					set_sprite_tile(2,32+(y%2+1)*4); // arthur a
					set_sprite_tile(3,34+(y%2+1)*4); // arthur b
					move_sprite(2,x*8,y*8+(i+i+0)-3);
					move_sprite(3,x*8+8,y*8+(i+i+0)-3);
					wait_vbl_done();
					wait_vbl_done();
					move_sprite(2,x*8,y*8+(i+i+1)-3);
					move_sprite(3,x*8+8,y*8+(i+i+1)-3);
					wait_vbl_done();
					wait_vbl_done();
				}
				y++;
			}
			set_sprite_tile(2,32); // arthur a
			set_sprite_tile(3,34); // arthur b
		} else if (dy==-1 && y!=3) {
			set_sprite_prop(2,0x00);
			set_sprite_prop(3,0x00);
			if (World_Map_Small[x-1+(y-3)*20]!=44 && World_Map_Small[x+0+(y-3)*20]!=44){
				for(i=0; i<4; i++){
					set_sprite_tile(2,52+(y%2+1)*upSpriteOffsets[i]*4); // arthur a
					set_sprite_tile(3,54+(y%2+1)*upSpriteOffsets[i]*4); // arthur b
					move_sprite(2,x*8,y*8-(i+i+0+3));
					move_sprite(3,x*8+8,y*8-(i+i+0+3));
					wait_vbl_done();
					wait_vbl_done();
					move_sprite(2,x*8,y*8-(i+i+1+3));
					move_sprite(3,x*8+8,y*8-(i+i+1+3));
					wait_vbl_done();
					wait_vbl_done();
				}
				y--;
			}
			set_sprite_tile(2,52); // arthur a
			set_sprite_tile(3,54); // arthur b
		} else if (dx==1 && x !=19) {
			set_sprite_prop(2,S_FLIPX);
			set_sprite_prop(3,S_FLIPX);
			if (World_Map_Small[x+1+(y-1)*20]!=44 && World_Map_Small[x+1+(y-2)*20]!=44){
				for(i=0; i<4; i++){
					set_sprite_tile(2,46+sideSpriteOffsets[i]*4); // arthur a
					set_sprite_tile(3,44+sideSpriteOffsets[i]*4); // arthur b
					move_sprite(2,x*8+(i+i+0),y*8-3);
					move_sprite(3,x*8+8+(i+i+0),y*8-3);
					wait_vbl_done();
					wait_vbl_done();
					move_sprite(2,x*8+(i+i+1),y*8-3);
					move_sprite(3,x*8+8+(i+i+1),y*8-3);
					wait_vbl_done();
					wait_vbl_done();
				}
				x++;
			}
			set_sprite_tile(2,46); // arthur a
			set_sprite_tile(3,44); // arthur b
		} else if (dx==-1 && x !=1) {
			set_sprite_prop(2,0x00);
			set_sprite_prop(3,0x00);
			if (World_Map_Small[x-2+(y-1)*20]!=44 && World_Map_Small[x+-2+(y-2)*20]!=44){
				for(i=0; i<4; i++){
					set_sprite_tile(2,44+sideSpriteOffsets[i]*4); // arthur a
					set_sprite_tile(3,46+sideSpriteOffsets[i]*4); // arthur b
					move_sprite(2,x*8-(i+i+0),y*8-3);
					move_sprite(3,x*8+8-(i+i+0),y*8-3);
					wait_vbl_done();
					wait_vbl_done();
					move_sprite(2,x*8-(i+i+1),y*8-3);
					move_sprite(3,x*8+8-(i+i+1),y*8-3);
					wait_vbl_done();
					wait_vbl_done();
				}
				x--;
			}
			set_sprite_tile(2,44); // arthur a
			set_sprite_tile(3,46); // arthur b
		}
		move_sprite(2,x*8,y*8-3);
		move_sprite(3,x*8+8,y*8-3);
		
		if (checkWarp()==1){
			fadeToWhite();
			set_sprite_prop(2,0x00);
			set_sprite_prop(3,0x00);
			return;
		}
	}
	
}

void animateKnight(uint8_t spr, uint8_t offset){
	set_sprite_tile(spr,   ((frame + offset)%4)*4);
	set_sprite_tile(spr+1, ((frame + offset)%4)*4+2);
}

void animateSprites(){
	uint8_t ii;
	switch(m){
		case 1:
		// water
		set_bkg_data(44,1,World_Tiles+(44+slowFrame)*16);
		break;
		case 2:
		// merlin, knights, flames
		set_sprite_tile(0,((frame)%4)*4+16);
		set_sprite_tile(1,((frame)%4)*4+18);
		for(ii=0;ii<8;ii++){
			animateKnight((ii+2)*2,ii%4);
		}
		set_bkg_data(29,1,Castle_Tiles+(70+fastFrame)*16);
		break;
		case 3:
		// knight, flames;
		animateKnight(0,0);
		set_bkg_data(29,1,Castle_Tiles+(70+fastFrame)*16);
		break;
		case 4 :
		// knight, water
		animateKnight(0,0);
		set_bkg_data(31,1,Town_Tiles+(31+slowFrame)*16);
		break;
	}
}

void timerBeep(){
	gbt_update();
	tim_cnt++;
	if (tim_cnt == 5){
		fastFrame = (fastFrame+1)%4;
		if (fastFrame%2 == 0){
			frame = (frame+1)%4;
			if (frame%2 == 0){
				slowFrame = (slowFrame+1)%4;
			}
		}
		animateSprites();
		tim_cnt=0;
	}
}

// main
void main(void)
{
	//disable_interrupts();
	
	// setup for bank usage
	ENABLE_RAM_MBC1;
	SWITCH_4_32_MODE_MBC1;
	
	// setup timer interrupt
	CRITICAL{
		tim_cnt = 0;
		add_VBL(timerBeep);
	}
	TMA_REG = 0x00U;
    TAC_REG = 0x04U;
	set_interrupts(VBL_IFLAG);
	
	// setup music
	gbt_play(song_Data, 2, 7); // track, bank, speed
	gbt_loop(1); // should loop
	enable_interrupts();
	
    // Loop forever (unused for now, left here to avoid issues)
    while(1) {
		// preload window stuff
		set_win_data(206,47,Windows_Tiles);
		move_win(7,144);
		SHOW_WIN;
		
		// fade in title screen
		m = 0;
		frame = 0;
		fastFrame = 0;
		slowFrame = 0;
		allSpritesOffScreen();
		titleScreenAnim();
		
		// wait for input
		waitpad(J_A);
		
		// fade to black
		fadeToBlack();
		
		// some more setup
		allSpritesOffScreen();
		SWITCH_RAM_MBC1(0);
		set_sprite_data(0,68u,CharaSprites); // setup chara sprites in ram since they'll be used for the rest of the game
		q = 0; // set quest to display intro text
		
		// load camelot map and sprites
		m=2;
		loadMapCamelot();
		camelotSprites();
		
		// fade from black
		fadeFromBlack();
		
		// display startup text *4
		displayandAPressText(0);
		displayandAPressText(1);
		displayandAPressText(2);
		displayandAPressText(3);
		
		// final setup
		q = 1; // set quest to looking for knight 1
		
		// fade to white
		fadeToWhite();
		
		// main world=>knight=>camelot loop
		for(c=0;c<8;c++){
			// world map section
			m=1;
			loadMapWorld();
			worldMapSection();
			
			// load knight stuff
			m = mapSequence[q-1];
			loadMapKnight();
			storyMapSprites();
			fadeFromWhite();
			displayandAPressText(c*2+4);
			fadeToBlack();
			
			// back to camelot
			m=2;
			q++;
			loadMapCamelot();
			camelotSprites();
			fadeFromBlack();
			displayandAPressText(c*2+5);
			if (q==9)displayandAPressText(c*2+6);
			fadeToWhite();
		}
		
		/*loadMapKnight1();
		storyMapSprites();
		fadeFromWhite();
		displayandAPressText(4);
		fadeToWhite(); // or black ?
		q=2;
		loadMapCamelot();
		camelotSprites();
		fadeFromWhite();
		displayandAPressText(5);
		fadeToWhite();
		// map part goes here
		
		loadMapWorld();
		worldMapSection();
		
		loadMapKnight2();
		storyMapSprites();
		fadeFromWhite();
		displayandAPressText(6);
		fadeToWhite(); // or black ?
		q=3;
		loadMapCamelot();
		camelotSprites();
		fadeFromWhite();
		displayandAPressText(7);
		fadeToWhite();
		// map part goes here
		
		loadMapWorld();
		worldMapSection();
		
		loadMapKnight3();
		storyMapSprites();
		fadeFromWhite();
		displayandAPressText(8);
		fadeToWhite(); // or black ?
		q=4;
		loadMapCamelot();
		camelotSprites();
		fadeFromWhite();
		displayandAPressText(9);
		fadeToWhite();
		// map part goes here
		
		loadMapWorld();
		worldMapSection();
		
		loadMapKnight4();
		storyMapSprites();
		fadeFromWhite();
		displayandAPressText(10);
		fadeToWhite(); // or black ?
		q=5;
		loadMapCamelot();
		camelotSprites();
		fadeFromWhite();
		displayandAPressText(11);
		fadeToWhite();
		// map part goes here
		
		loadMapWorld();
		worldMapSection();
		
		loadMapKnight5();
		storyMapSprites();
		fadeFromWhite();
		displayandAPressText(12);
		fadeToWhite(); // or black ?
		q=6;
		loadMapCamelot();
		camelotSprites();
		fadeFromWhite();
		displayandAPressText(13);
		fadeToWhite();
		// map part goes here
		
		loadMapWorld();
		worldMapSection();
		
		loadMapKnight6();
		storyMapSprites();
		fadeFromWhite();
		displayandAPressText(14);
		fadeToWhite(); // or black ?
		q=7;
		loadMapCamelot();
		camelotSprites();
		fadeFromWhite();
		displayandAPressText(15);
		fadeToWhite();
		// map part goes here
		
		loadMapWorld();
		worldMapSection();
		
		loadMapKnight7();
		storyMapSprites();
		fadeFromWhite();
		displayandAPressText(16);
		fadeToWhite(); // or black ?
		q=8;
		loadMapCamelot();
		camelotSprites();
		fadeFromWhite();
		displayandAPressText(17);
		fadeToWhite();
		// map part goes here
		
		loadMapWorld();
		worldMapSection();
		
		loadMapKnight8();
		storyMapSprites();
		fadeFromWhite();
		displayandAPressText(18);
		fadeToWhite(); // or black ?
		q=9;
		loadMapCamelot();
		camelotSprites();
		fadeFromWhite();
		displayandAPressText(19);
		displayandAPressText(20);
		fadeToWhite();*/
    }
}
