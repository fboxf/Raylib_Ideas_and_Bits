#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "raymath.h"
#include "core.h"

#define SIZE_OF_ARRAY 200

int main (void){
	const int screenWidth = 800;
	const int screenHeight = 800;

	InitWindow(screenWidth, screenHeight, "physics");

	Object test[SIZE_OF_ARRAY] = {0}; // array of SIZE_OF_ARRAY pointers to object struct
	
	for (size_t i = 0; i < SIZE_OF_ARRAY; i++){
		test[i] = createObject();
		setPos(test[i], (screenWidth / SIZE_OF_ARRAY) * i, (screenHeight / SIZE_OF_ARRAY) * i);
		setAcceleration(test[i], 0.001 * i + 0.0001, 0);
		setVelocity(test[i], 0, 0.00002 * i + 0.0001);
	}

	while (!WindowShouldClose()){

		for (size_t i = 0; i < SIZE_OF_ARRAY; i++){
			if (getPos(test[i]).y > screenHeight){ // if at bottom move to top
				setPos(test[i], (screenWidth / SIZE_OF_ARRAY) * i, 100);
				setAcceleration(test[i], 0.001 * i + 0.0001, 0);
				setVelocity(test[i], 0, 0.00002 * i + 0.0001);
			} 

			setAcceleration(test[i], 
					getAcceleration(test[i]).x + getVelocity(test[i]).x, 
					getAcceleration(test[i]).y + getVelocity(test[i]).y
					); 
			setPos(test[i],
					getPos(test[i]).x + getAcceleration(test[i]).x, 
					getPos(test[i]).y + getAcceleration(test[i]).y);


		}


		BeginDrawing();

		{

			for (size_t i = 0; i < SIZE_OF_ARRAY; i++){
				DrawCircle(getPos(test[i]).x, getPos(test[i]).y, getSize(test[i]).x, (i % 2 == 0) ? BLUE : SKYBLUE);
			}

			ClearBackground(RAYWHITE);
		}
		EndDrawing();
	}

	free(test[0]);
	free(test[1]);
	free(test[2]);

	CloseWindow();

	return 0;
}
