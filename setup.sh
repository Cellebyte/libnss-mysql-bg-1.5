#!/bin/sh

############################################################################
# $Id$
# Quick script to set up a build environment from CVS
############################################################################
set -x
aclocal && \
autoheader && \
autoconf && \
libtoolize --copy --automake --force && \
automake --add-missing --copy

