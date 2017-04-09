#!/bin/sh

############################################################################
# $Id$
# Quick script to set up a build environment from CVS
############################################################################
set -x
test ! -d out && mkdir out
aclocal -I out && \
autoheader && \
autoconf && \
libtoolize --copy --automake --force && \
automake --add-missing --copy
