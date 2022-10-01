# QMK_HID_Gamepad_with_SOCD
QMK Keymap(s) to emulate a Gamepad/All Button Controller with SOCD cleaning. For use with keyboards running QMK firmware.

# Features
- Effectively emulates a Hitbox Cross|Up style controller.
- SOCD Cleaning on DPAD, and both Analog sticks.
- Can customize button layout by editing keymap (matrix).
- Ideal for fighting games and platform fighters.
- Can utilize third party program (i.e. Steam or x360ce) to emulate Xbox, Playstation, Nintendo controllers.
- 1000hz Polling Rate

# Requirements
- QMK enabled keyboard (V-USB devices not supported). i.e. OLKB planck/preonic, Keychron Q or V series keyboards, or Boardsource 4x12 or 5x12
- Text Editor (Recommend Notepad++)
- QMK MSYS
- QMK Toolbox

# Layouts
![layout1](https://user-images.githubusercontent.com/99369506/193212571-ce099852-6f4f-4345-be7b-93d21a037ca6.png)

**Layout 1:** Default Layout, ideal for fighting games and most styles.

SOCD: Left + Right = Neutral; Down + Up = Up

---

![layout2](https://user-images.githubusercontent.com/99369506/193212575-9f0531c5-93eb-492d-91da-7f803a3f87c1.png)

**Layout 2:** Secondary layout, ideal for fast as possible charge moves.

SOCD: Left + Right = Last Input Wins; Down + Up = Up

---

![layout3](https://user-images.githubusercontent.com/99369506/193212578-a2e78a99-dd1c-422f-873a-54da1e7f4b7b.png)

**Layout 3:** Ideal layout for platform fighters (i.e. Multiversus, Nickelodeon ASB, Rivals of Aether).

SOCD: Left + Right = Last Input Wins; Down + Up = Up

# Guide (WIP)

### 1. <ins>Setup the QMK MSYS environment:</ins>
- Download [QMK MSYS](https://github.com/qmk/qmk_distro_msys/releases/latest).
- Install and run QMK MSYS

![Screenshot 2022-09-30 200352](https://user-images.githubusercontent.com/99369506/193384158-07bf864e-7e77-4499-a7d9-8ee47a9849af.png)
- Input `qmk setup` in the terminal window. This will take a few minutes.

### 2. <ins>Backup your keyboard's original firmware:</ins>
- Compile default keymap firmware.
  - The default keymap is generated after setting up the environment. So I can compile the default firmware in QMK MSYS as follows: (Boardsource 5x12 keyboard as example)
```
qmk compile -kb boardsource/5x12 -km default
```
  - By default keyboards are located in "C:\Users\\{Username}\qmk_firmware\keyboards\" after you've setup the environment. If your keyboard is not within the environment, please contact manufacturer for the QMK files to import to your environment.

  - After compiling, the firmware is saved in the qmk_firmware directory as a .hex file. i.e. "C:\Users\\{Username}\qmk_firmware\boardsource_5x12_crossup.hex"

  - If you own one keyboard and want to default to it: (Boardsource 5x12 as example)
```
qmk config user.keyboard=boardsource/5x12
```
### 3. <ins>Create custom keymap:</ins>

- Create a copy of default keymap
```
qmk new-keymap
```
- It will prompt for keymap name of your choosing. For example, "crossup" will be used.
After inputting keymap name, it will output location of the new keymap. This is the location of the keymap you will be editing.

### 4. <ins>Enable keyboard joystick</ins>
- Navigate to your keyboard's folder i.e. "C:\Users\\{Username}\qmk_firmware\keyboards\boardsource\5x12\"
- Open the rules.mk file with your text editor.
- Add following and save.
<details><summary>Analog Input</summary>

```js
# Analog Input
JOYSTICK_ENABLE = yes
JOYSTICK_DRIVER = digital
```
</details>

### 5. <ins>Create config.h</ins>
- Navigate to your custom keymap location i.e. "C:\Users\\{Username}\qmk_firmware\keyboards\boardsource\5x12\keymaps\crossup"
- Create a new file "config.h"
- Open config.h in text editor and input the following. (Enables 1000hz polling rate and sets joystick/button parameters.)
<details><summary>config.h</summary>

```js
// 1000hz Polling Rate
#define USB_POLLING_INTERVAL_MS 1
#define QMK_KEYS_PER_SCAN 12

// Joystick Button Count
#define JOYSTICK_BUTTON_COUNT 32

// Joystick Axes Count
#define JOYSTICK_AXES_COUNT 6

// Joystick Axes Resolution
#define JOYSTICK_AXES_RESOLUTION 8
```
</details>

### 6. <ins>Edit custom keymap</ins>
- Open keymap.c in text editor.
- Edit "enum layers" to following:
<details><summary>enum layers</summary>

```js
enum layers {
  _GAME1,
  _FN1,
  _GAME2,
  _FN2,
  _GAME3,
  _FN3
};
```
</details>

- Add directly below/after "enum custom_keycodes", Joystick config, and define layer switching.
<details><summary>Custom Keycodes</summary>

```js
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

#define GAME2   TT(_GAME2)
#define GAME3   TT(_GAME3)
#define FN1		MO(_FN1)
#define FN2		MO(_FN2)
#define FN3		MO(_FN3)
```
</details>

- **Edit keymap layer matrices:** All keyboard matrices are different. The example matrices correspond with the custom keycodes enumerated earlier. You can customise these layers to your liking.

Example layer matrices for Boardsource 5x12:
<details><summary>Layer Matrices</summary>

```js
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_GAME1] = LAYOUT_ortho_5x12(
    GC_HOM,  GC_SEL,  GC_STA,  XXXXXXX, XXXXXXX, GC_L3,   GC_R3,   GC_LSL,  GC_LSD,  GC_LSR,  XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, GC_DPU,  XXXXXXX, XXXXXXX, XXXXXXX, GC_SQU,  GC_TRI,  GC_R1,   GC_L1,   XXXXXXX,
    XXXXXXX, XXXXXXX, GC_DPL,  GC_DPD,  GC_DPR,  XXXXXXX, XXXXXXX, GC_CRO,  GC_CIR,  GC_R2,   GC_L2,   XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, FN1,     XXXXXXX, XXXXXXX, XXXXXXX, GC_LSU,  XXXXXXX, XXXXXXX, GC_RSL,  GC_RSD,  GC_RSU,  GC_RSR
  ),
  [_FN1] = LAYOUT_ortho_5x12(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, GAME2,   _______, _______, GAME3,   _______, _______, _______, _______
  ),
  [_GAME2] = LAYOUT_ortho_5x12(
    GC_HOM,  GC_SEL,  GC_STA,  XXXXXXX, XXXXXXX, GC_L3,   GC_R3,   GC_DPL,  GC_DPD,  GC_DPR,  XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, GC_LSU,  XXXXXXX, XXXXXXX, XXXXXXX, GC_SQU,  GC_TRI,  GC_R1,   GC_L1,   XXXXXXX,
    XXXXXXX, XXXXXXX, GC_LSL,  GC_LSD,  GC_LSR,  XXXXXXX, XXXXXXX, GC_CRO,  GC_CIR,  GC_R2,   GC_L2,   XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, FN2,     XXXXXXX, XXXXXXX, XXXXXXX, GC_DPU,  XXXXXXX, XXXXXXX, GC_RSL,  GC_RSD,  GC_RSU,  GC_RSR
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
    XXXXXXX, FN3,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GC_RSU,  XXXXXXX, GC_DPL,  GC_DPD,  GC_DPU,  GC_DPR
  ),
  [_FN3] = LAYOUT_ortho_5x12(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, GAME3,   _______, _______, _______, _______
  )
};
```
</details>

- **Add custom keycode and SOCD code:** Add the following below/after the layer matrices.
<details><summary>SOCD Code</summary>

```js
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

layer_state_t layer_state_set_user(layer_state_t state) {
	switch (get_highest_layer(state)) {
		case _GAME1:
			SOCD = 0;
			break;
		case _FN1:
			SOCD = 0;
			break;
		case _GAME2:
			SOCD = 1;
			break;
		case _FN2:
			SOCD = 1;
			break;
		case _GAME3:
			SOCD = 1;
			break;
		case _FN3:
			SOCD = 1;
			break;
	}
	return state;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case GC_LSU:
			if (record->event.pressed) {
				LSU_STATE = true;
				if (DPD_STATE) {
					unregister_joystick_button(16);
				};
				joystick_status.axes[1] = -127;
			} else {
				LSU_STATE = false;
				if (LSD_STATE) {
					joystick_status.axes[1] = 127;
				} else if (DPD_STATE) {
					register_joystick_button(16);
					joystick_status.axes[1] = 0;
				} else {
					joystick_status.axes[1] = 0;
				}
			}
			joystick_status.status |= JS_UPDATED;
			return false;
		case GC_LSD:
			if (record->event.pressed) {
				LSD_STATE = true;
				if (!(LSU_STATE || DPU_STATE)) {
					joystick_status.axes[1] = 127;
				}
			} else {
				LSD_STATE = false;	
				if (!(LSU_STATE || DPU_STATE)) {
					joystick_status.axes[1] = 0;
				}	
			}
			joystick_status.status |= JS_UPDATED;
			return false;
		case GC_LSL:
			if (record->event.pressed) {
				LSL_STATE = true;
				if (SOCD == 0) {
					if (LSR_STATE) {
						joystick_status.axes[0] = 0;
					} else if (DPR_STATE) {
						joystick_status.axes[0] = 0;
						unregister_joystick_button(17);
					} else {
						joystick_status.axes[0] = -127;
					}
				} else if (SOCD == 1) {
					if (DPR_STATE) {
						unregister_joystick_button(17);
					};
					joystick_status.axes[0] = -127;
				}
			} else {
				LSL_STATE = false;
				if (LSR_STATE) {
					joystick_status.axes[0] = 127;
				} else if (DPR_STATE) {
					joystick_status.axes[0] = 0;
					register_joystick_button(17);
				} else {
					joystick_status.axes[0] = 0;
				}
			}
			joystick_status.status |= JS_UPDATED;
			return false;
		case GC_LSR:
			if (record->event.pressed) {
				LSR_STATE = true;
				if (SOCD == 0) {
					if (LSL_STATE) {
						joystick_status.axes[0] = 0;
					} else if (DPL_STATE) {
						unregister_joystick_button(15);
						joystick_status.axes[0] = 0;
					} else {
						joystick_status.axes[0] = 127;
					}
				} else if (SOCD == 1) {
					if (DPL_STATE) {
						unregister_joystick_button(15);
					};
					joystick_status.axes[0] = 127;
				}
			} else {
				LSR_STATE = false;
				if (LSL_STATE) {
					joystick_status.axes[0] = -127;
				} else if (DPL_STATE) {
					joystick_status.axes[0] = 0;
					register_joystick_button(15);
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
				} else if (LSD_STATE) {
					joystick_status.axes[1] = 0;
				};
				register_joystick_button(18);
			} else {
				DPU_STATE = false;
				unregister_joystick_button(18);
				if (DPD_STATE) {
					register_joystick_button(16);
				} else if (LSD_STATE) {
					joystick_status.axes[1] = 127;
				}
			}
			joystick_status.status |= JS_UPDATED;
			return false;
		case GC_DPD:
			if (record->event.pressed) {
				DPD_STATE = true;
				if (!(DPU_STATE || LSU_STATE)) {
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
				if (SOCD == 0) {
					if (DPR_STATE) {
						unregister_joystick_button(17);
					} else if (LSR_STATE) {
						joystick_status.axes[0] = 0;
					} else {
						register_joystick_button(15);
					}
				} else if (SOCD == 1) {
					if (DPR_STATE) {
						unregister_joystick_button(17);
					} else if (LSR_STATE) {
						joystick_status.axes[0] = 0;
					};
					register_joystick_button(15);
				}
			} else {
				DPL_STATE = false;
				unregister_joystick_button(15);
				if (DPR_STATE) {
					register_joystick_button(17);
				} else if (LSR_STATE) {
					joystick_status.axes[0] = 127;
				}
			}
			joystick_status.status |= JS_UPDATED;
			return false;
		case GC_DPR:
			if (record->event.pressed) {
				DPR_STATE = true;
				if (SOCD == 0) {
					if (DPL_STATE) {
						unregister_joystick_button(15);
					} else if (LSL_STATE) {
						joystick_status.axes[0] = 0;
					} else {
						register_joystick_button(17);
					}
				} else if (SOCD == 1) {
					if (DPL_STATE) {
						unregister_joystick_button(15);
					} else if (LSL_STATE) {
						joystick_status.axes[0] = 0;
					};
					register_joystick_button(17);
				}
			} else {
				DPR_STATE = false;
				unregister_joystick_button(17);
				if (DPL_STATE ) {
					register_joystick_button(15);
				} else if (LSL_STATE) {
					joystick_status.axes[0] = -127;
				}
			}
			joystick_status.status |= JS_UPDATED;
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
				if (RSR_STATE) {
					joystick_status.axes[3] = 0;
				} else {
					joystick_status.axes[3] = -127;
				}
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
				if (RSL_STATE) {
					joystick_status.axes[3] = 0;
				} else {
					joystick_status.axes[3] = 127;
				}
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
```
</details>

- Save your keymap.c file.
  - I'll attach my sample keymap.c file to cross reference.
  
### 7. <ins>Compile custom firmware:</ins>
- In QMK MSYS input the following: (Will take a few minutes and will check for errors)
```
qmk compile -km crossup
```
- Upon successful compile, it should output firmware file *crossup.hex located in your keyboard folder i.e. "C:\Users\\{Username}\qmk_firmware\boardsource_5x12_crossup.hex"

### 8. <ins>Flash keyboard with custom firmware:</ins>
- Download and run [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases)
- Click "Open" and select your custom firmware i.e. "C:\Users\\{Username}\qmk_firmware\boardsource_5x12_crossup.hex"
- Reset your keyboard. Refer to manufacturer where reset button is located.
- Click Flash. Will see keyboard disconnect from QMK Toolbox upon successful flash.

# Congratulations
- You've successfully flashed custom firmware onto your QMK keyboard to use as an HID Gamepad with SOCD.

# Usage
- To switch layers/layouts:
  - Hold the FN Key and Press GAME2 or GAME3 key 5 times to switch to the second or third layout.
- To return to default layer:
  - If on second layout: Hold FN Key and Press GAME2 5 times to switch back to default layout.
  - If on third layout: Hold FN Key and Press GAME3 5 times to switch back to default layout.

# Optional
Can use Steam to use keyboard/gamepad on Steam games and Steam Deck (setup requires Desktop Mode once).
- Instructions:
  - Open Steam (If on Steam Deck, switch to Desktop Mode and open the application)
  - Go to View > Settings
  - In the Controller Section, click on General Controller settings![settings](https://user-images.githubusercontent.com/99369506/193379186-0214adf6-8431-4932-aa46-32376e7ed754.png)
  - On this window, make sure at least General Gamepad Configuration Support and Xbox Configuration Support. On first setup, controller might be named after keyboard i.e. "5x12"![controller](https://user-images.githubusercontent.com/99369506/193379517-24dbeb58-efdc-437a-b196-35d88e5b2d85.png)
  - When ready, click on Define Layout and start mapping your keyboard keys to the on screen controller. Click Save when done.

- That should be it. If done on the Steam deck in Desktop mode, the next time you turn on the Steam Deck in Game Mode, your keyboard should act as an xinput controller.

# Tournament Legality
- All of this is done hardware side, but still requires setup with Steam to get controller to work. Does not work natively with consoles.
- Depending on game, Last Input Wins is not allowed (Street Fighter bans LIW, while Smash often allows it). Please refer to your TO and tournament rules.
- I'm only providing base code, but ultimately the user controls the firmware. Macros can be programmed into custom firmware.

# References/Resources
- [QMK Documentation](https://docs.qmk.fm/)
- [QMK Discord](https://discord.gg/fBGYurv)
- [r/OLKB](https://www.reddit.com/r/olkb/)
- [r/fightsticks](https://www.reddit.com/r/fightsticks/)
- [Hitbox Cross|Up](https://www.hitboxarcade.com/products/cross-up)

# To Do List
- Clean up Guide/Formatting
- Add Frame1/b0xx/Smashbox layout
- Add sample firmware retaining keyboard functionality
