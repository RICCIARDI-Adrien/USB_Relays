PATH_INCLUDES = Includes
PATH_OBJECTS = Objects
PATH_SOURCES = Sources

CC = xc8
CFLAGS = --chip=16F18854 --objdir=$(PATH_OBJECTS) --outdir=$(PATH_OBJECTS) -I$(PATH_INCLUDES) -D_XTAL_FREQ=32000000

BINARY = Firmware.hex
SOURCES = $(PATH_SOURCES)/Communication_Protocol.c $(PATH_SOURCES)/Led.c $(PATH_SOURCES)/Main.c $(PATH_SOURCES)/Relay.c $(PATH_SOURCES)/UART.c

all: $(PATH_OBJECTS)
	$(CC) $(CFLAGS) $(SOURCES) -O$(BINARY)
	cp $(PATH_OBJECTS)/$(BINARY) .

$(PATH_OBJECTS):
	mkdir -p $(PATH_OBJECTS)

clean:
	rm -f $(BINARY)
	rm -rf $(PATH_OBJECTS)
