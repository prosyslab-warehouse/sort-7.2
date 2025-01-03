/* -*- buffer-read-only: t -*- vi: set ro: */
/* DO NOT EDIT! GENERATED AUTOMATICALLY! */
#line 1
/* Test of filevercmp() function.
   Copyright (C) 2008-2009 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */

#include <config.h>

#include "filevercmp.h"

#include <stdio.h>
#include <stdlib.h>

#define ASSERT(expr) \
  do									     \
    {									     \
      if (!(expr))							     \
        {								     \
          fprintf (stderr, "%s:%d: assertion failed\n", __FILE__, __LINE__); \
          fflush (stderr);						     \
          abort ();							     \
        }								     \
    }									     \
  while (0)

/* set of well sorted examples */
static const char *const examples[] =
{
  ".",
  "..",
  ".a~",
  ".a",
  ".b~",
  ".b",
  "a~",
  "a",
  "a.b~",
  "a.b",
  "a.bc~",
  "a.bc",
  "b~",
  "b",
  "gcc-c++-10.fc9.tar.gz",
  "gcc-c++-10.fc9.tar.gz.~1~",
  "gcc-c++-10.fc9.tar.gz.~2~",
  "gcc-c++-10.8.12-0.7rc2.fc9.tar.bz2",
  "gcc-c++-10.8.12-0.7rc2.fc9.tar.bz2.~1~",
  "glibc-2-0.1.beta1.fc10.rpm",
  "glibc-common-5-0.2.beta2.fc9.ebuild",
  "glibc-common-5-0.2b.deb",
  "glibc-common-11b.ebuild",
  "glibc-common-11-0.6rc2.ebuild",
  "libstdc++-0.5.8.11-0.7rc2.fc10.tar.gz",
  "libstdc++-4a.fc8.tar.gz",
  "libstdc++-4.10.4.20040204svn.rpm",
  "libstdc++-devel-3.fc8.ebuild",
  "libstdc++-devel-3a.fc9.tar.gz",
  "libstdc++-devel-8.fc8.deb",
  "libstdc++-devel-8.6.2-0.4b.fc8",
  "nss_ldap-1-0.2b.fc9.tar.bz2",
  "nss_ldap-1-0.6rc2.fc8.tar.gz",
  "nss_ldap-1.0-0.1a.tar.gz",
  "nss_ldap-10beta1.fc8.tar.gz",
  "nss_ldap-10.11.8.6.20040204cvs.fc10.ebuild",
  NULL
};

int
main (int argc, char **argv)
{
  const char *const *i;

  /* Following tests taken from test-strverscmp.c */
  ASSERT (filevercmp ("", "") == 0);
  ASSERT (filevercmp ("a", "a") == 0);
  ASSERT (filevercmp ("a", "b") < 0);
  ASSERT (filevercmp ("b", "a") > 0);
  ASSERT (filevercmp ("a0", "a") > 0);
  ASSERT (filevercmp ("00", "01") < 0);
  ASSERT (filevercmp ("01", "010") < 0);
  ASSERT (filevercmp ("9", "10") < 0);
  ASSERT (filevercmp ("0a", "0") > 0);

  /* compare each version string with each other - O(n^2) */
  for (i = examples; *i; i++)
    {
      const char *const *j;
      for (j = examples; *j; j++)
	{
	  int result = filevercmp (*i, *j);
	  if (result < 0)
	    ASSERT (i < j);
	  else if (0 < result)
	    ASSERT (j < i);
	  else
	    ASSERT (i == j);
	}
    }

  return 0;
}
