#include <Arduboy2.h>
#include <ArduboyPlaytune.h>
#include "scores.h"
#include <Adafruit_PixelDust.h> // For simulation
#define N_GRAINS    90 // Number of grains of sand

Arduboy2 arduboy;
ArduboyPlaytune tunes(arduboy.audio.enabled);
Adafruit_PixelDust sand(WIDTH / 2, HEIGHT / 2, N_GRAINS, 1, 256, false);

void setup()
{
  arduboy.begin();
  arduboy.setFrameRate(60);
  sand.begin();
  arduboy.initRandomSeed();
  sand.randomize(); // Initialize random sand positions
  tunes.initChannel(PIN_SPEAKER_1);
  tunes.initChannel(PIN_SPEAKER_2);
}

bool editor_mode = false, is_drawing, first_pixel, pen_color;
int gravityx = 0, gravityy = 0;
byte current_x = WIDTH / 4, current_y = HEIGHT / 4, current_pixel = 0, b_pressed = 0, current_score = 0, invert_hold = 0;
const int MAX_PIXELS = 100, MAX_GRAVITY = 3000, GRAVITY_REDUCTION = 2, BACKGROUND_TUNE_SWITCH_HOLD = 20;

void loop() {
  if (!(arduboy.nextFrame()))
    return;

  if (!editor_mode && arduboy.pressed(A_BUTTON)) {
    editor_mode = true;
    first_pixel = true;
    is_drawing = false;
  }

  if (arduboy.pressed(B_BUTTON))
    if (editor_mode) {
      editor_mode = false;
      if (arduboy.pressed(A_BUTTON))
        sand.clear();
    }
    else {
      // Get tone based on sand
      uint8_t     i;
      dimension_t x, y;
      uint16_t xsum = 0, ysum = 0;

      for (i = 0; i < N_GRAINS; i++) {
        sand.getPosition(i, &x, &y);
        xsum += x;
        ysum += y;
      }

      // Play tone
      tunes.tone(map((xsum / N_GRAINS), 0, WIDTH / 2, 800, 4000), map((ysum / N_GRAINS), 0, HEIGHT / 2, 50, 500));

      if (b_pressed < BACKGROUND_TUNE_SWITCH_HOLD)
        b_pressed++;

      if ( b_pressed >= BACKGROUND_TUNE_SWITCH_HOLD) {
        b_pressed = 0; // Do not retrigger
        if (current_score == 0)
          current_score = map((ysum / N_GRAINS), 0, HEIGHT / 2, 1, total_scores); // Select a score to play
        else        {
          current_score = 0; // Stop current score
          tunes.stopScore();
        }
        invert_hold = 7;
      }
    }
  else
    b_pressed = 0;

  // Start background tune
  if (current_score > 0 && !tunes.playing())
    tunes.playScore(scores[current_score - 1]);

  if (!editor_mode) { // Modify gravity
    if (arduboy.pressed(LEFT_BUTTON)) gravityx = -MAX_GRAVITY;
    if (arduboy.pressed(RIGHT_BUTTON)) gravityx = MAX_GRAVITY;
    if (arduboy.pressed(UP_BUTTON)) gravityy = MAX_GRAVITY;
    if (arduboy.pressed(DOWN_BUTTON)) gravityy = -MAX_GRAVITY;
  }

  sand.iterate(gravityx, -gravityy, 1);
  arduboy.clear();

  if (!editor_mode) { // Return to neutral gravity
    gravityx /= GRAVITY_REDUCTION;
    gravityy /= GRAVITY_REDUCTION;
  }
  else {
    // Move cursor
    arduboy.pollButtons();

    if (arduboy.pressed(LEFT_BUTTON)) current_x = max(0, current_x - 1);
    if (arduboy.pressed(RIGHT_BUTTON)) current_x = min(WIDTH / 2 -1, current_x + 1);
    if (arduboy.pressed(UP_BUTTON)) current_y = max(0, current_y - 1);
    if (arduboy.pressed(DOWN_BUTTON)) current_y = min(HEIGHT / 2 -1, current_y + 1);

    if (is_drawing && arduboy.pressed(A_BUTTON))
    {
      if (first_pixel)
      {
        pen_color = !sand.getPixel(current_x, current_y); // Check which color should I use for the pen
        first_pixel = false;
      }

      if (pen_color) sand.setPixel(current_x, current_y);
      else sand.clearPixel(current_x, current_y);
    }

    if (arduboy.notPressed(A_BUTTON))
    {
      first_pixel = true;
      if (!is_drawing)
        is_drawing = true;
    }
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
    for (byte _y = 0; _y < HEIGHT / 2; _y++) {
      if (sand.getPixel(_x, _y)) {
        bool skip = false;
        for (i = 0; i < N_GRAINS; i++) {
          sand.getPosition(i, &x, &y);
          if (_x == x && _y == y) {
            skip = true;
            break;
          }
        }

        if (!skip) arduboy.fillRect(_x * 2, _y * 2, 2, 2, WHITE);
      }
    }

  if (invert_hold > 0) {
    arduboy.invert(true);
    arduboy.setTextSize(2);

    if (current_score == 0)
    {
      arduboy.setCursor(WIDTH / 2 - 15, HEIGHT / 2 - 8);
      arduboy.print("OFF");
    }
    else
    {
      arduboy.setCursor(WIDTH / 2 - 10, HEIGHT / 2 - 8);
      if (current_score < 10)
        arduboy.print("0");
      arduboy.print(current_score);
    }
    invert_hold--;
  }
  else
    arduboy.invert(false);

  arduboy.display();
}
