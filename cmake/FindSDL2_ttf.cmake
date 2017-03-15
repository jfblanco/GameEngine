message("Looking for SDL2_TTF")

SET(SDL2_TTF_SEARCH_PATHS /usr/local ${SDL2_TTF_PATH})

FIND_PATH(SDL2_TTF_INCLUDE_DIR SDL_ttf.h
	HINTS
	$ENV{SDL2_TTFDIR}
	PATH_SUFFIXES include/SDL2 include
	PATHS ${SDL2_TTF_SEARCH_PATHS}
)

FIND_PATH(SDL2_TTF_LIB_DIR libSDL2_ttf.a
	HINTS
	$ENV{SDL2DIR}
	PATH_SUFFIXES lib
	PATHS ${SDL2_TTF_SEARCH_PATHS}
)

find_library(SDL2_TTF_LIBRARY
	NAMES SDL2_ttf
	HINTS
	ENV SDL2TTFDIR
	ENV SDL2TTFDIR
	PATH_SUFFIXES lib ${VC_LIB_PATH_SUFFIX}
	PATHS ${SDL2_TTF_PATH}
)