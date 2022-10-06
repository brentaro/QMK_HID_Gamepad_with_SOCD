// Copyright 2022 @waffle87
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum layers {
    _GAME1,
	_FN1,
    _GAME2,
	_FN2,
    _GAME3,
	_FN3
};

enum custom_keycodes {      
	GC_LSU = SAFE_RANGE,
	GC_LSD,
	GC_LSL,
	GC_LSR,
	GC_RSU,
	GC_RSD,
	GC_RSL,
	GC_RSR,
	GC_DPU,
	GC_DPD,
	GC_DPL,
	GC_DPR,
	GC_SQU,
	GC_CRO,
	GC_CIR,
	GC_TRI,
	GC_L1,
	GC_L2,
	GC_L3,
	GC_R1,
	GC_R2,
	GC_R3,
	GC_STA,
	GC_SEL,
	GC_HOM
};
	
// Joystick Config
joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
	[0] = JOYSTICK_AXIS_VIRTUAL,
	[1] = JOYSTICK_AXIS_VIRTUAL,
	[2] = JOYSTICK_AXIS_VIRTUAL,
	[3] = JOYSTICK_AXIS_VIRTUAL,
	[4] = JOYSTICK_AXIS_VIRTUAL,
	[5] = JOYSTICK_AXIS_VIRTUAL,
};

#define GAME2   TG(_GAME2)
#define GAME3   TG(_GAME3)
#define FN1		MO(_FN1)
#define FN2		MO(_FN2)
#define FN3		MO(_FN3)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_GAME1] = LAYOUT_ortho_5x12(
    GC_HOM,  GC_SEL,  GC_STA,  XXXXXXX, XXXXXXX, GC_L3,   GC_R3,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GC_SQU,  GC_TRI,  GC_R1,   GC_L1,   XXXXXXX,
    XXXXXXX, XXXXXXX, GC_DPL,  GC_DPD,  GC_DPR,  XXXXXXX, XXXXXXX, GC_CRO,  GC_CIR,  GC_R2,   GC_L2,   XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, FN1, 	  XXXXXXX, XXXXXXX, XXXXXXX, GC_DPU,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
  [_FN1] = LAYOUT_ortho_5x12(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, GAME2,   _______, _______, GAME3,   _______, _______, _______, _______
  ),
  [_GAME2] = LAYOUT_ortho_5x12(
    GC_HOM,  GC_SEL,  GC_STA,  XXXXXXX, XXXXXXX, GC_L3,   GC_R3,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GC_SQU,  GC_TRI,  GC_R1,   GC_L1,   XXXXXXX,
    XXXXXXX, XXXXXXX, GC_LSL,  GC_LSD,  GC_LSR,  XXXXXXX, XXXXXXX, GC_CRO,  GC_CIR,  GC_R2,   GC_L2,   XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, FN2, 	  XXXXXXX, XXXXXXX, XXXXXXX, GC_LSU,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),
  [_FN2] = LAYOUT_ortho_5x12(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, GAME2,   _______, _______, _______,   _______, _______, _______, _______
  ),
  [_GAME3] = LAYOUT_ortho_5x12(
    GC_HOM,  GC_SEL,  GC_STA,  XXXXXXX, XXXXXXX, GC_L3,   GC_R3,   GC_RSL,  GC_RSD,  GC_RSR,  XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, GC_LSU,  XXXXXXX, XXXXXXX, XXXXXXX, GC_SQU,  GC_TRI,  GC_R1,   GC_L1,   XXXXXXX,
    XXXXXXX, XXXXXXX, GC_LSL,  GC_LSD,  GC_LSR,  XXXXXXX, XXXXXXX, GC_CRO,  GC_CIR,  GC_R2,   GC_L2,   XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, FN3, 	  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GC_RSU,  XXXXXXX, GC_DPL,  GC_DPD,  GC_DPU,  GC_DPR
  ),
  [_FN3] = LAYOUT_ortho_5x12(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, GAME3,   _______, _______, _______, _______
  )
};

bool LSU_STATE = false;
bool LSD_STATE = false;
bool LSL_STATE = false;
bool LSR_STATE = false;
bool RSU_STATE = false;
bool RSD_STATE = false;
bool RSL_STATE = false;
bool RSR_STATE = false;
bool DPU_STATE = false;
bool DPD_STATE = false;
bool DPL_STATE = false;
bool DPR_STATE = false;
uint8_t SOCD = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case GC_LSU:
			if (record->event.pressed) {
				LSU_STATE = true;
				joystick_status.axes[1] = -127;
			} else {
				LSU_STATE = false;
				if (LSD_STATE) {
					joystick_status.axes[1] = 127;
				} else {
					joystick_status.axes[1] = 0;
				}
			}
			joystick_status.status |= JS_UPDATED;
			return false;
		case GC_LSD:
			if (record->event.pressed) {
				LSD_STATE = true;
				if (!LSU_STATE) {
					joystick_status.axes[1] = 127;
				}
			} else {
				LSD_STATE = false;	
				if (!LSU_STATE) {
					joystick_status.axes[1] = 0;
				}	
			}
			joystick_status.status |= JS_UPDATED;
			return false;
		case GC_LSL:
			if (record->event.pressed) {
				LSL_STATE = true;
				joystick_status.axes[0] = -127;
			} else {
				LSL_STATE = false;
				if (LSR_STATE) {
					joystick_status.axes[0] = 127;
				} else {
					joystick_status.axes[0] = 0;
				}
			}
			joystick_status.status |= JS_UPDATED;
			return false;
		case GC_LSR:
			if (record->event.pressed) {
				LSR_STATE = true;
				joystick_status.axes[0] = 127;
			} else {
				LSR_STATE = false;
				if (LSL_STATE) {
					joystick_status.axes[0] = -127;
				} else {
					joystick_status.axes[0] = 0;
				}
			}
			joystick_status.status |= JS_UPDATED;
			return false;
		case GC_DPU:
			if (record->event.pressed) {
				DPU_STATE = true;
				if (DPD_STATE) {
					unregister_joystick_button(16);
				}
				register_joystick_button(18);
			} else {
				DPU_STATE = false;
				unregister_joystick_button(18);
			}
			return false;
		case GC_DPD:
			if (record->event.pressed) {
				DPD_STATE = true;
				if (!DPU_STATE) {
					register_joystick_button(16);
				}
			} else {
				DPD_STATE = false;
				unregister_joystick_button(16);
			}
			return false;
		case GC_DPL:
			if (record->event.pressed) {
				DPL_STATE = true;
				if (DPR_STATE) {
					unregister_joystick_button(17);
				} else {
					register_joystick_button(15);
				}
			} else {
				DPL_STATE = false;
				unregister_joystick_button(15);
				if (DPR_STATE) {
					register_joystick_button(17);
				}
			}
			return false;
		case GC_DPR:
			if (record->event.pressed) {
				DPR_STATE = true;
				if (DPL_STATE) {
					unregister_joystick_button(15);
				} else {
					register_joystick_button(17);
				}
			} else {
				DPR_STATE = false;
				unregister_joystick_button(17);
				if (DPL_STATE) {
					register_joystick_button(15);
				}
			}
			return false;
		case GC_RSU:
			if (record->event.pressed) {
				RSU_STATE = true;
				joystick_status.axes[4] = -127;
			} else {
				RSU_STATE = false;
				if (RSD_STATE) {
					joystick_status.axes[4] = 127;
				} else {
					joystick_status.axes[4] = 0;
				}
			}
			joystick_status.status |= JS_UPDATED;
			return false;
		case GC_RSD:
			if (record->event.pressed) {
				RSD_STATE = true;
				if (!RSU_STATE) {
					joystick_status.axes[4] = 127;
				}
			} else {
				RSD_STATE = false;
				if (RSU_STATE) {
					joystick_status.axes[4] = -127;
				} else {
					joystick_status.axes[4] = 0;
				}
			}
			joystick_status.status |= JS_UPDATED;
			return false;
		case GC_RSL:
			if (record->event.pressed) {
				RSL_STATE = true;
				joystick_status.axes[3] = -127;
			} else {
				RSL_STATE = false;
				if (RSR_STATE) {
					joystick_status.axes[3] = 127;
				} else {
					joystick_status.axes[3] = 0;
				}
			}
			joystick_status.status |= JS_UPDATED;
			return false;
		case GC_RSR:
			if (record->event.pressed) {
				RSR_STATE = true;
				joystick_status.axes[3] = 127;
			} else {
				RSR_STATE = false;
				if (RSL_STATE) {
					joystick_status.axes[3] = -127;
				} else {
					joystick_status.axes[3] = 0;
				}
			}
			joystick_status.status |= JS_UPDATED;
			return false;
		case GC_SQU:
			if (record->event.pressed) {
				register_joystick_button(0);
			} else {
				unregister_joystick_button(0);
			}
			return false;
		case GC_CRO:
			if (record->event.pressed) {
				register_joystick_button(1);
			} else {
				unregister_joystick_button(1);
			}
			return false;
		case GC_CIR:
			if (record->event.pressed) {
				register_joystick_button(2);
			} else {
				unregister_joystick_button(2);
			}
			return false;
		case GC_TRI:
			if (record->event.pressed) {
				register_joystick_button(3);
			} else {
				unregister_joystick_button(3);
			}
			return false;
		case GC_L1:
			if (record->event.pressed) {
				register_joystick_button(4);
			} else {
				unregister_joystick_button(4);
			}
			return false;
		case GC_R1:
			if (record->event.pressed) {
				register_joystick_button(5);
			} else {
				unregister_joystick_button(5);
			}
			return false;
		case GC_L2:
			if (record->event.pressed) {
				register_joystick_button(6);
			} else {
				unregister_joystick_button(6);
			}
			return false;
		case GC_R2:
			if (record->event.pressed) {
				register_joystick_button(7);
			} else {
				unregister_joystick_button(7);
			}
			return false;
		case GC_SEL:
			if (record->event.pressed) {
				register_joystick_button(8);
			} else {
				unregister_joystick_button(8);
			}
			return false;
		case GC_STA:
			if (record->event.pressed) {
				register_joystick_button(9);
			} else {
				unregister_joystick_button(9);
			}
			return false;
		case GC_L3:
			if (record->event.pressed) {
				register_joystick_button(10);
			} else {
				unregister_joystick_button(10);
			}
			return false;
		case GC_R3:
			if (record->event.pressed) {
				register_joystick_button(11);
			} else {
				unregister_joystick_button(11);
			}
			return false;
		case GC_HOM:
			if (record->event.pressed) {
				register_joystick_button(12);
			} else {
				unregister_joystick_button(12);
			}
			return false;
		default:
			return true;
	}
};