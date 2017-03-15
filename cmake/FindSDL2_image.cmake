message("Looking for SDL2_Image")

SET(SDL2_IMAGE_SEARCH_PATHS /usr/local ${SDL2_IMAGE_PATH})

FIND_PATH(SDL2_IMAGE_INCLUDE_DIR SDL_image.h
	HINTS
	$ENV{SDL2IMAGEDIR}
	PATH_SUFFIXES include/SDL2 include
	PATHS ${SDL2_IAMGE_SEARCH_PATHS}
)

FIND_PATH(SDL2_IMAGE_LIB_DIR libSDL2_image.a
	HINTS
	$ENV{SDL2DIR}
	PATH_SUFFIXES lib
	PATHS ${SDL2_IMAGE_SEARCH_PATHS}
)

FIND_LIBRARY(SDL2_IMAGE_LIBRARY_TEMP
	NAMES SDL2_image
	HINTS
	$ENV{SDL2IMAGEDIR}
	PATH_SUFFIXES ${PATH_SUFFIXES}
	PATHS ${SDL2_IMAGE_SEARCH_PATHS}
)


if(SDL2_IMAGE_INCLUDE_DIR AND EXISTS "${SDL2_IMAGE_INCLUDE_DIR}/SDL_image.h")

endif()