#include <gb/gb.h>
#include <stdint.h>


// title screen map
#include "../Resources/Title_Map.c"
// title screen tiles
#include "../Resources/Title_Tiles.c"
#include "../Resources/Title_TextTiles.c"

// text boxes
#include "../Resources/Windows_Text.c"
// text tiles
#include "../Resources/Windows_Tiles.c"

void titleScreenAnim() BANKED 
{
	// start full white
	BGP_REG = 0x00; // background palette
	OBP0_REG = 0x00; // sprites palette
	
	// display title
	set_bkg_data(0, 87u, Title_Tiles); // 87 unsigned because 0 to 86 is 87 tiles
	set_bkg_tiles(0, 0, 20u,18u, Title_Map + 600); // 600 is offset so i don't have to scroll
	SHOW_BKG;
	
	//title & credits sprites
	SPRITES_8x16;
	set_sprite_data(0,30u,Title_TextTiles);
	
	set_sprite_tile( 0, 0); // A
	set_sprite_tile( 1, 2); // R
	set_sprite_tile( 2, 4); // T
	set_sprite_tile( 3, 6); // H
	set_sprite_tile( 4, 8); // U
	set_sprite_tile( 5, 2); // R
	set_sprite_tile( 6,10); // '
	set_sprite_tile( 7,12); // S
	set_sprite_tile( 8,14); // Q
	set_sprite_tile( 9, 8); // U
	set_sprite_tile(10,16); // E
	set_sprite_tile(11,12); // S
	set_sprite_tile(12, 4); // T
	move_sprite( 0,13u,21u);
	move_sprite( 1,21u,21u);
	move_sprite( 2,29u,21u);
	move_sprite( 3,37u,21u);
	move_sprite( 4,45u,21u);
	move_sprite( 5,53u,21u);
	move_sprite( 6,61u,21u);
	move_sprite( 7,69u,21u);
	move_sprite( 8,13u,38u);
	move_sprite( 9,21u,38u);
	move_sprite(10,29u,38u);
	move_sprite(11,37u,38u);
	move_sprite(12,45u,38u);
	
	set_sprite_tile(13,18); // b
	set_sprite_tile(14,20); // i
	set_sprite_tile(15,22); // s
	set_sprite_tile(16,24); // h
	set_sprite_tile(17,26); // o
	set_sprite_tile(18,28); // p
	move_sprite(13,115u,141u);
	move_sprite(14,123u,141u);
	move_sprite(15,131u,141u);
	move_sprite(16,139u,141u);
	move_sprite(17,147u,141u);
	move_sprite(18,155u,141u);
	SHOW_SPRITES;
	
	// fade from white
	fadeFromWhite();
}