# ========

MK_ROOT		= $(dir $(realpath $(firstword $(MAKEFILE_LIST))))
MK_NAME		= math	# NOTE: This probably should have a better name (thx libc)...

# ========

MODULES		= $(MK_ROOT)math.h 		\
			  $(MK_ROOT)common.h	\
			  $(MK_ROOT)vec2.h		\
			  $(MK_ROOT)vec3.h		\
			  $(MK_ROOT)vec4.h		\
			  $(MK_ROOT)mat4.h

# ========

.PHONY : all

all : install

.PHONY : install

install :
	mkdir -p /usr/local/include/$(MK_NAME)/
	cp -f $(MODULES) /usr/local/include/$(MK_NAME)/
	ln -nfs /usr/local/include/$(MK_NAME)/$(MK_NAME).h /usr/local/include/$(MK_NAME).h

.PHONY : remove

remove :
	rm -rf /usr/local/include/$(MK_NAME)
	rm -f /usr/local/include/$(MK_NAME).h

# ========
