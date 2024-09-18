ENCODER_MAP_ENABLE = yes
RAW_ENABLE = yes

ENVIRON=mac
ifeq ($(ENVIRON),mac)
    SRC += /usr/local/share/qmkontext/qmkontext.c
else
    SRC += /usr/share/qmkontext/qmkontext.c
endif

# Enable debug
# CONSOLE_ENABLE = yes
# COMMAND_ENABLE = yes
