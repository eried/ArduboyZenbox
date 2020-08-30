const byte PROGMEM m1_1[] = {3, 232, 0x90, 72, 3, 232, 0x80, 0xf0};
const byte PROGMEM m1_2[] = {3, 232, 0x90, 70, 3, 232, 0x80, 0xf0};
const byte PROGMEM m1_4[] = {3, 232, 0x90, 66, 3, 232, 0x80, 0xf0};
const byte PROGMEM m1_3[] = {3, 232, 0x90, 68, 3, 232, 0x80, 0xf0};
const byte PROGMEM m1_5[] = {3, 232, 0x90, 64, 3, 232, 0x80, 0xf0};
const byte PROGMEM m1_6[] = {3, 232, 0x90, 62, 3, 232, 0x80, 0xf0};
const byte PROGMEM m2_1[] = {0x90, 72, 3, 232, 0x80, 0x90, 71, 3, 232, 0x80, 0xf0};
const byte PROGMEM m2_2[] = {0x90, 70, 3, 232, 0x80, 0x90, 69, 3, 232, 0x80, 0xf0};
const byte PROGMEM m2_3[] = {0x90, 68, 3, 232, 0x80, 0x90, 67, 3, 232, 0x80, 0xf0};
const byte PROGMEM m2_4[] = {0x90, 65, 3, 232, 0x80, 0x90, 64, 3, 232, 0x80, 0xf0};
const byte PROGMEM m2_5[] = {0x90, 62, 3, 232, 0x80, 0x90, 61, 3, 232, 0x80, 0xf0};

const byte PROGMEM background1[] = {0x90, 68, // background1
                                      0, 250, 0x80, 0x90, 67, 0, 250, 0x80, 0x90, 66, 1, 244, 0x80, 0xf0
                                     };

const byte PROGMEM background10[] = {2, 238, 0x90, 60, 0, 250, 0x80, 0, 250, 0x90, 55, 0, 250, 0x80, 0x90, 60, 0, 250, 0x80, 0, 250,
                                       0x90, 55, 0, 250, 0x80, 0xf0
                                      };

const byte PROGMEM background11[] = {1, 244, 0x90, 57, 0, 250, 0x80, 0x90, 60, 0, 250, 0x80, 0, 250, 0x90, 57, 0, 250, 0x80, 0x90, 60,
                                       0, 250, 0x80, 0xf0
                                      };

const byte PROGMEM background2[] = {0x90, 63, 0, 250, 0x80, 0x90, 66, 0, 250, 0x80, 0x90, 63, 0, 250, 0x80, 0, 250, 0x90, 65, 0, 250,
                                      0x80, 0x90, 61, 0, 250, 0x80, 0x90, 65, 0, 250, 0x80, 0x90, 61, 0, 250, 0x80, 0xf0
                                     };

const byte PROGMEM background3[] = {3, 232, 0x90, 63, 0, 250, 0x80, 0x90, 67, 0, 250, 0x80, 0x90, 63, 0, 250, 0x80, 0x90, 67, 0, 250,
                                      0x80, 0xf0
                                     };

const byte PROGMEM background4[] = {2, 238, 0x90, 67, 0, 250, 0x80, 0x90, 63, 0, 250, 0x80, 0x90, 67, 0, 250, 0x80, 0x90, 63, 0, 250,
                                      0x80, 0x90, 71, 0, 250, 0x80, 0x90, 66, 0, 250, 0x80, 0x90, 71, 0, 250, 0x80, 0x90, 66, 0, 250, 0x80,
                                      0xf0
                                     };

const byte PROGMEM background5[] = {2, 238, 0x90, 67, 0, 250, 0x80, 0x90, 68, 0, 250, 0x80, 0x90, 69, 2, 238, 0x80, 0xf0};

const byte PROGMEM background6[] = {1, 244, 0x90, 70, 0, 250, 0x80, 0, 250, 0x90, 71, 0, 250, 0x80, 0, 250, 0x90, 72, 0, 250, 0x80,
                                      0, 250, 0x90, 70, 0, 250, 0x80, 0, 250, 0x90, 68, 0, 250, 0x80, 0xf0
                                     };

const byte PROGMEM background7[] = {0x90, 68, // background1
                                      0, 250, 0x80, 0x90, 67, 0, 250, 0x80, 0x90, 66, 0, 250, 0x80, 0x90, 65, 0, 250, 0x80, 0x90, 64,
                                      0, 250, 0x80, 0x90, 67, 0, 250, 0x80, 0x90, 66, 0, 250, 0x80, 0x90, 65, 0, 250, 0x80, 0x90, 68, 0, 250,
                                      0x80, 0x90, 67, 0, 250, 0x80, 0x90, 66, 0, 250, 0x80, 0x90, 65, 0, 250, 0x80, 0x90, 64, 0, 250, 0x80,
                                      0x90, 63, 1, 244, 0x80, 0xf0
                                     };

const byte PROGMEM background8[] = {0x90, 63, 0, 200, 0x80, 0x90, 64, 0, 200, 0x80, 0x90, 65, 0, 200, 0x80, 0x90, 66, 0, 200, 0x80, 0x90, 67,
                                      0, 200, 0x80, 0x90, 68, 0, 200, 0x80, 0x90, 69, 0, 200, 0x80, 0x90, 70, 0, 200, 0x80, 0x90, 71, 0, 200,
                                      0x80, 0x90, 72, 0, 200, 0x80, 0xf0
                                     };

const byte PROGMEM background9[] = {1, 144, 0x90, 55, 0, 200, 0x80, 0, 200, 0x90, 55, 0, 200, 0x80, 0, 200, 0x90, 55, 0, 200, 0x80,
                                      0, 200, 0x90, 53, 0, 200, 0x80, 1, 144, 0x90, 53, 0, 200, 0x80, 0, 200, 0x90, 52, 0, 200, 0x80,
                                      0x90, 52, 0, 200, 0x80, 0xf0
                                     };

const byte PROGMEM simple_120[] = {// background1
  0, 250, 0x90, 61, 0, 250, 0x80, 1, 244, 0x90, 63, 0, 250, 0x80, 0xf0
};

const byte PROGMEM simple_150[] = {0, 200, 0x90, 57, 1, 144, 0x80, 0x90, 55, 0, 200, 0x80, 0x90, 53, 0, 200, 0x80, 0xf0};

const byte PROGMEM simple2_120[] = {// background1
  0, 250, 0x90, 61, 0, 250, 0x80, 0x90, 65, 1, 244, 0x80, 0x90, 63, 0, 250, 0x80, 0xf0
};

const byte PROGMEM simple2_80[] = {// background1
  1, 119, 0x90, 61, 1, 119, 0x80, 0x90, 65, 2, 238, 0x80, 0x90, 63, 1, 119, 0x80, 0xf0
};

const byte total_scores = 30; // Repeating the first and last just in case
const byte* const scores[total_scores] = { m1_1, m1_1, m1_2, m1_4, m1_3, m1_5, m1_6, m2_1, m2_2, m2_3, m2_4, m2_5, background1, background10,
                                       background11, background2, background3, background4, background5, background6, background7, background8, background9,
                                       simple_120, simple_150, simple2_120, simple2_80, simple2_80, simple2_80, simple2_80
                                     };
