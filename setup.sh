#!/bin/sh

triggeredFolder=`pwd`

openGLFolder="/usr/lib/nvidia-390/"
openGLIncludesFolder="/usr/include/nvidia-390/"

export LDFLAGS="-L$openGLFolder -L$triggeredFolder/external/lib"
export CFLAGS="-I$openGLIncludesFolder -I$triggeredFolder/external/include"
export GL_LDFLAGS="-L/usr/lib/nvidia-390"
export GLEW_DEST="$triggeredFolder/external"
export GLEW_NO_GLU="yes"

cd SDL2-2.0.8/
./configure --prefix=$triggeredFolder/external
make -j8
make install

cd $triggeredFolder

cd SDL2_image-2.0.3/external/libpng-1.6.32
./configure --prefix=$triggeredFolder/external
make -j8
make install

cd $triggeredFolder

cd SDL2_image-2.0.3/external/jpeg-9b
./configure --prefix=$triggeredFolder/external
make -j8
make install

cd $triggeredFolder

cd SDL2_mixer-2.0.2/external/libogg-1.3.2/
./configure --prefix=$triggeredFolder/external
make -j8
make install

cd $triggeredFolder

cd SDL2_mixer-2.0.2/external/libvorbis-1.3.5
./configure --prefix=$triggeredFolder/external
make -j8
make install

cd SDL2_mixer-2.0.2/external/libvorbisidec-1.2.1
./configure --prefix=$triggeredFolder/external
make -j8
make install

cd $triggeredFolder

cd SDL2_mixer-2.0.2/external/mpg123-1.25.6
./configure --prefix=$triggeredFolder/external --enable-static=yes
make -j8
make install

cd $triggeredFolder

cd SDL2_ttf-2.0.14/external/freetype-2.4.12
./configure --prefix=$triggeredFolder/external --enable-static=yes
make -j8
make install

cd $triggeredFolder

cd SDL2_image-2.0.3/
./configure --prefix=$triggeredFolder/external --with-sdl-prefix=$triggeredFolder/external --libdir=$triggeredFolder/external/lib --includedir=$triggeredFolder/external/include --bindir=$triggeredFolder/external/bin
make -j8
make install

cd $triggeredFolder

cd SDL2_mixer-2.0.2/
./configure --prefix=$triggeredFolder/external --with-sdl-prefix=$triggeredFolder/external --libdir=$triggeredFolder/external/lib --includedir=$triggeredFolder/external/include --bindir=$triggeredFolder/external/bin
make -j8
make install

cd $triggeredFolder

cd SDL2_net-2.0.1/
./configure --prefix=$triggeredFolder/external --with-sdl-prefix=$triggeredFolder/external --libdir=$triggeredFolder/external/lib --includedir=$triggeredFolder/external/include --bindir=$triggeredFolder/external/bin
make -j8
make install

cd $triggeredFolder

cd SDL2_ttf-2.0.14/
./configure --prefix=$triggeredFolder/external --with-sdl-prefix=$triggeredFolder/external --libdir=$triggeredFolder/external/lib --includedir=$triggeredFolder/external/include --bindir=$triggeredFolder/external/bin
make -j8
make install

cd $triggeredFolder

cd glew-2.1.0/
make -j8
make install

cd $triggeredFolder