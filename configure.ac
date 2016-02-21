# Process this file with autoconf to produce a configure script.

AC_INIT([sim], [0.0.1])
AC_CONFIG_SRCDIR([src/main.cc])
AM_INIT_AUTOMAKE([subdir-objects])
AM_CONFIG_HEADER([config.h])
AC_SUBST(VERSION)

ISODATE=`date +%Y-%m-%d`
AC_SUBST(ISODATE)

AC_CANONICAL_HOST

# Checks for programs.
AC_PROG_INSTALL
AC_PROG_CC
AC_PROG_CXX

# Checks for libraries.
AC_CHECK_LIB([m],[cos])

AX_BOOST_BASE()
AX_BOOST_DATE_TIME()
AX_BOOST_SYSTEM()
AX_BOOST_LOG()
AX_BOOST_LOG_SETUP()
AX_BOOST_THREAD()

dnl Check for SDL
SDL_VERSION=2.0.3
AM_PATH_SDL2($SDL_VERSION,
             :,
             AC_MSG_ERROR([*** SDL version $SDL_VERSION not found!])
)
CFLAGS="$CFLAGS $SDL_CFLAGS"
LIBS="$LIBS $SDL_LIBS"

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS(unistd.h sys/param.h sys/time.h time.h sys/mkdev.h sys/sysmacros.h string.h memory.h fcntl.h dirent.h sys/ndir.h ndir.h alloca.h locale.h )

AC_HEADER_MAJOR
AC_FUNC_ALLOCA
AC_STRUCT_TM
AC_STRUCT_ST_BLOCKS
AC_FUNC_CLOSEDIR_VOID
AC_CHECK_FUNCS(mkfifo)
AC_CHECK_FUNC(mknod)

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_OUTPUT(Makefile)
