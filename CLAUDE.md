# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Overview

This is a QMK firmware fork customized for **Keychron K11 Max** (ANSI encoder, RGB variant) with a personal Swedish Eurkey layout. The active branch is `wireless_playground`. Primary work happens in the `eurkey` keymap.

## Build Commands

```bash
# Build the custom Eurkey keymap (primary target)
qmk compile -kb keychron/k11_max/ansi_encoder/rgb -km eurkey

# Build other variants
qmk compile -kb keychron/k11_max/ansi_encoder/rgb -km default
qmk compile -kb keychron/k11_max/ansi_encoder/rgb -km via

# Flash firmware
qmk flash -kb keychron/k11_max/ansi_encoder/rgb -km eurkey
```

QMK must be set up in the environment. If `qmk` is not available, use `make keychron/k11_max/ansi_encoder/rgb:eurkey` from the repo root.

## Architecture

### Config hierarchy (each level overrides the parent)

```
keyboards/keychron/k11_max/config.h         # Wireless, encoder, matrix hardware
keyboards/keychron/k11_max/ansi_encoder/rgb/config.h   # RGB LED drivers (2× SNLED27351, 68 LEDs)
keyboards/.../keymaps/eurkey/config.h       # TAPPING_TERM for home row mods
```

### rules.mk chain

The keyboard `rules.mk` includes two shared files:
- `keyboards/keychron/common/wireless/wireless.mk` — enables LKBT51 Bluetooth, battery management, P2P4G
- `keyboards/keychron/common/keychron_common.mk` — enables factory test, adaptive NKRO, raw HID, Keychron RGB

The `eurkey` keymap adds `KEY_OVERRIDE_ENABLE` and `CAPS_WORD_ENABLE`.

## Eurkey Keymap Structure

**File:** [keyboards/keychron/k11_max/ansi_encoder/rgb/keymaps/eurkey/keymap.c](keyboards/keychron/k11_max/ansi_encoder/rgb/keymaps/eurkey/keymap.c)

### Layers

| Layer | Name | Purpose |
|-------|------|---------|
| 0 | `MAC_BASE` | macOS QWERTY base |
| 1 | `WIN_BASE` | Windows QWERTY base |
| 2 | `MAC_FN1` | macOS symbols, RGB, BT hosts, Spotlight |
| 3 | `WIN_FN1` | Windows equivalents |
| 4 | `FN2` | F1–F12, volume, RGB |

### Home row mods (HRMS)

Left hand: `A`=Shift, `S`=Ctrl, `D`=Alt, `F`=GUI  
Right hand: `J`=GUI, `K`=Alt, `L`=Ctrl, `Ö`=Shift

These use `MT()` macros, so `TAPPING_TERM` in the keymap `config.h` controls tap vs. hold behavior.

### Key overrides

Defined via `key_override_t` entries — modify shift/alt behavior for punctuation keys:
- Shift+`,` → `;`, Shift+`.` → `:`, Shift+`/` → `\`, Alt+`/` → `|`, Shift+`?` → `!`

### Eurkey characters

`keymap_eurkey.h` defines macros for Nordic and international characters (Å, Ä, Ö, ß, €, etc.) that are typed as host-side Unicode sequences.

## Wireless / Hardware Notes

- **Connectivity:** USB, 3× Bluetooth hosts (BT1–BT3), 1× P2P4G (2.4 GHz dongle)
- **Battery indicators:** LEDs 1–10; charging/low indicator: LED 12
- **Host connection indicators:** LEDs 15–18
- **Backlight timeout:** 40 s disconnected, 600 s connected
- **Encoder:** Volume on base layer, RGB brightness on FN1

## Key Files

| File | Role |
|------|------|
| [keyboards/keychron/k11_max/config.h](keyboards/keychron/k11_max/config.h) | Wireless pins, encoder, LED index assignments |
| [keyboards/keychron/k11_max/k11_max.c](keyboards/keychron/k11_max/k11_max.c) | DIP switch handling, power-on indicator, battery/wireless task logic |
| [keyboards/keychron/k11_max/ansi_encoder/rgb/rgb.c](keyboards/keychron/k11_max/ansi_encoder/rgb/rgb.c) | 68-LED layout mapping across 2 driver chips |
| [keyboards/keychron/k11_max/ansi_encoder/rgb/keymaps/eurkey/keymap.c](keyboards/keychron/k11_max/ansi_encoder/rgb/keymaps/eurkey/keymap.c) | All layer definitions, encoder map, key overrides |
| [keyboards/keychron/k11_max/ansi_encoder/rgb/keymaps/eurkey/keymap_eurkey.h](keyboards/keychron/k11_max/ansi_encoder/rgb/keymaps/eurkey/keymap_eurkey.h) | Eurkey Unicode character macros |
