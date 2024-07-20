ifeq ($(strip $(AUDIO_ENABLE)), yes)
    SRC += muse.c
endif

CONSOLE_ENABLE = yes
COMMAND_ENABLE = no
MOUSEKEY_ENABLE = no
RGB_MATRIX_CUSTOM_USER = yes
