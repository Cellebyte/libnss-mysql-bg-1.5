/* Copyright (C) 2002 Ben Goodwin
   This file is part of the nss-mysql library.

   The nss-mysql library is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as published
   by the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   The nss-mysql library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with the nss-mysql library; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

static const char rcsid[] =
    "$Id$";

#include "nss_mysql.h"
#include <stdlib.h>

void
xfree (void *ptr)
{
  function_enter;
  _nss_mysql_debug (FNAME, D_MEMORY, "free %p", ptr);
  if (ptr)
    free (ptr);
  ptr = NULL;
  function_leave;
}

void *
xmalloc (size_t size)
{
  static void *ptr;

  function_enter;
  ptr = malloc (size);
  _nss_mysql_debug (FNAME, D_MEMORY, "malloc (%d) = %p", size, ptr);
  if (ptr == NULL)
    _nss_mysql_log (LOG_ALERT, "malloc of %d bytes failed", size);
  function_leave;
  return (ptr);
}

void *
xrealloc (void *ptr, size_t size)
{
  void *before = ptr;

  function_enter;
  ptr = realloc (ptr, size);
  _nss_mysql_debug (FNAME, D_MEMORY, "realloc (%p, %d) = %p", before, size,
                    ptr);
  if (ptr == NULL)
    _nss_mysql_log (LOG_ALERT, "realloc of %d bytes failed", size);
  function_leave;
  return (ptr);
}
