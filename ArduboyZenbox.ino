#include <Arduboy2.h>
#include <Adafruit_PixelDust.h> // For simulation
#define N_GRAINS    110 // Number of grains of sand

Arduboy2 arduboy;
Adafruit_PixelDust sand(WIDTH / 2, HEIGHT / 2, N_GRAINS, 1, 256, false);

void setup()
{
  arduboy.begin();
  arduboy.setFrameRate(60);
  sand.begin();
  sand.randomize(); // Initialize random sand positions
}

bool editor_mode = false, just_switched;
int gravityx = 0, gravityy = 0;
byte current_x = WIDTH / 4, current_y = HEIGHT / 4, current_pixel = 0;
const int MAX_PIXELS = 100, MAX_GRAVITY = 3000, GRAVITY_REDUCTION = 2;

void loop() {
  if (!(arduboy.nextFrame()))
    return;

  if (!editor_mode && arduboy.pressed(A_BUTTON)){
    editor_mode = true;
    just_switched = true;
  }

  if (editor_mode && arduboy.pressed(B_BUTTON)){
    editor_mode = false;
    if (arduboy.pressed(A_BUTTON))
      sand.clear();
  }

  if (!editor_mode){ // Modify gravity
    if (arduboy.pressed(LEFT_BUTTON)) gravityx = -MAX_GRAVITY;
    if (arduboy.pressed(RIGHT_BUTTON)) gravityx = MAX_GRAVITY;
    if (arduboy.pressed(UP_BUTTON)) gravityy = MAX_GRAVITY;
    if (arduboy.pressed(DOWN_BUTTON)) gravityy = -MAX_GRAVITY;
  }

  sand.iterate(gravityx, -gravityy, 1);
  arduboy.clear();

  if (!editor_mode){ // Return to neutral gravity
    gravityx /= GRAVITY_REDUCTION;
    gravityy /= GRAVITY_REDUCTION;
  }
  else{
    // Move cursor
    arduboy.pollButtons();

    if (arduboy.justReleased(LEFT_BUTTON)) current_x= max(0,current_x-1);
    if (arduboy.justReleased(RIGHT_BUTTON)) current_x= min(WIDTH/2,current_x+1);
    if (arduboy.justReleased(UP_BUTTON)) current_y= max(0,current_y-1);
    if (arduboy.justReleased(DOWN_BUTTON)) current_y= min(HEIGHT/2,current_y+1);

    if (arduboy.justReleased(A_BUTTON))
      if (sand.getPixel(current_x, current_y))
        sand.clearPixel(current_x, current_y);
      else if (just_switched)
        just_switched = false;
      else
        sand.setPixel(current_x, current_y);
  }

  // Draw sand
  uint8_t     i;
  dimension_t x, y;

  for (i = 0; i < N_GRAINS; i++) {
    sand.getPosition(i, &x, &y);
    if (editor_mode) arduboy.drawPixel(x * 2, y * 2, WHITE);
    else  arduboy.fillRect(x * 2, y * 2, 2, 2, WHITE);
  }

  // Draw solids
  if (editor_mode) {
    bool inverted = millis() % 700 > 300; // Cursor blinking
    arduboy.drawRect(current_x * 2 - 1, current_y * 2 - 1, 4, 4, inverted);
    arduboy.fillRect(current_x * 2, current_y * 2, 2, 2, !inverted);
  }

  bool ignore;
  for (byte _x = 0; _x < WIDTH / 2; _x++)
    for (byte _y = 0; _y < HEIGHT / 2; _y++){
      if (sand.getPixel(_x, _y)){
        bool skip = false;
        for (i = 0; i < N_GRAINS; i++) {
          sand.getPosition(i, &x, &y);
          if (_x == x && _y == y){skip = true; break;}
        }

        if (!skip) arduboy.fillRect(_x * 2, _y * 2, 2, 2, WHITE);
      }
    }
  arduboy.display();
}
