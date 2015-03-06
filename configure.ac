  AC_PREREQ(2.61)

  AC_INIT([libselinux],1.0.0)

  AM_INIT_AUTOMAKE([foreign])

  AM_MAINTAINER_MODE

  AC_CONFIG_HEADER([config.h])
  AC_CONFIG_MACRO_DIR([m4])

  # Checks for programs.
  AM_PROG_AS
  AC_PROG_CC
  AM_PROG_CC_C_O
  AC_PROG_LIBTOOL
  AC_PROG_AWK
  AC_PROG_CPP
  AC_PROG_CXX
  AC_PROG_INSTALL
  AC_PROG_LN_S
  AC_PROG_MAKE_SET

  #
  # Build all components by default
  #
  # To add new components: add AC_ARG_ENABLE, AM_CONDITIONAL and update AC_OUTPUT
  #


  AC_MSG_CHECKING(for perl regular expressions support)
  AC_ARG_WITH(pcre, AC_HELP_STRING([--with-pcre],[Enable pcre support (default yes)]),
      [WITH_PCRE=$withval],[WITH_PCRE=yes])
  AC_MSG_RESULT([$WITH_PCRE])

  if test "$WITH_PCRE" != "no"; then
    AC_PATH_PROG(PCRECONFIG, pcre-config)

    if test x"$PCRECONFIG" != x; then
      PCRE_LIB=`$PCRECONFIG --libs`
      CPPFLAGS="$CPPFLAGS `$PCRECONFIG --cflags`"
      AC_DEFINE([HAVE_LIBPCRE], [1], [libpcre])
      AC_DEFINE([HAVE_PCRE_H], [1], [pcre.h])
    else
       AC_MSG_ERROR([pcre-config not found, install the pcre-devel package or build with --without-pcre])
    fi
  fi

  AC_SUBST(PCRE_LIB)

  AC_OUTPUT([ \
          Makefile \
          libselinux.pc
  ])
