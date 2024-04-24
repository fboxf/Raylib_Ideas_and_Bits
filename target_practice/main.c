#include <stdlib.h>
#include "raylib.h"
#include "raymath.h"

#define SCALE 0.003

// create player
typedef struct Player {
	Vector2 position;
	Vector2 acceleration;
	Vector2 velocity;
} Player;

// create bullet
typedef struct Bullet {
	Vector2 position;
	bool fired;
	Vector2 target_vector;
	Vector2 target_vector_normalised;
	Vector2 scaled;
	Vector2 velocity;
} Bullet;

Player initPlayer(void);
void fireToMouse(Bullet*);

int main (void){
	const int screenWidth = 800;
	const int screenHeight = 800;

	InitWindow(screenWidth, screenHeight, "Left mouse fires A(LEFT) D(RIGHT)");

	Vector2 target = (Vector2){300,200};

	Player player = initPlayer();
	Bullet bullet = {0};
	bullet.fired = false;

	while (!WindowShouldClose()){
		// if enter is pressed fire bullet
		if(IsMouseButtonPressed(0) && bullet.fired == false){
			bullet.fired = true;
			bullet.position = (Vector2){player.position.x, player.position.y};
			fireToMouse(&bullet);
		}

		bullet.velocity = Vector2Add(bullet.velocity, bullet.scaled);
		bullet.position = Vector2Add(bullet.position, bullet.velocity);

		if(bullet.position.y < 0){
			bullet.fired = false;
			bullet.velocity.x = 0; bullet.velocity.y = 0;
		}

		if(IsKeyDown(KEY_A) && player.position.x > 0){
			if (player.velocity.x < 2){
				player.velocity.x += player.acceleration.x;
			}
			player.position.x = player.position.x - player.velocity.x;
		}
		if (IsKeyReleased(KEY_A)){
			player.velocity.x = 0;
		}

		if(IsKeyDown(KEY_D) && player.position.x < screenWidth){
			if (player.velocity.x < 2){
				player.velocity.x += player.acceleration.x;
			}
			player.position.x = player.position.x + player.velocity.x;
		}
		if (IsKeyReleased(KEY_D)){
			player.velocity.x = 0;
		}

		BeginDrawing();

		ClearBackground(RAYWHITE);

		// draw bullet
		if(bullet.fired == true){
			DrawCircle(bullet.position.x, bullet.position.y, 3, BLUE);
		}
		// draw player
		DrawCircle(player.position.x, player.position.y, 10, BLACK);
		
		//draw target
		DrawCircle(300,200,30,RED); 

		EndDrawing();
	}

	CloseWindow();

	return 0;
}

Player initPlayer(void){
	Player x;

	x.position = (Vector2){400,700};
	x.acceleration = (Vector2){0.001,0.001};
	x.velocity = (Vector2){0,0};

	return x;
}

// subtract origin from target (ie mouse)
void fireToMouse(Bullet* x){
	x->target_vector = Vector2Subtract(GetMousePosition(), x->position);
	x->target_vector_normalised = Vector2Normalize(x->target_vector);
	x->scaled = Vector2Scale(x->target_vector_normalised, SCALE);
}
