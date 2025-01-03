/* -*- buffer-read-only: t -*- vi: set ro: */
/* DO NOT EDIT! GENERATED AUTOMATICALLY! */
#line 1
/* Test the getaddrinfo module.

   Copyright (C) 2006-2009 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* Written by Simon Josefsson.  */

#include <config.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>

/* Whether to print debugging messages.  */
#define ENABLE_DEBUGGING 0

#if ENABLE_DEBUGGING
# define dbgprintf printf
#else
# define dbgprintf if (0) printf
#endif

/* BeOS does not have AF_UNSPEC.  */
#ifndef AF_UNSPEC
# define AF_UNSPEC 0
#endif

#ifndef EAI_SERVICE
# define EAI_SERVICE 0
#endif

int simple (char *host, char *service)
{
  char buf[BUFSIZ];
  static int skip = 0;
  struct addrinfo hints;
  struct addrinfo *ai0, *ai;
  int res;

  /* Once we skipped the test, do not try anything else */
  if (skip)
    return 0;

  dbgprintf ("Finding %s service %s...\n", host, service);

  /* This initializes "hints" but does not use it.  Is there a reason
     for this?  If so, please fix this comment.  */
  memset (&hints, 0, sizeof (hints));
  hints.ai_flags = AI_CANONNAME;
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  res = getaddrinfo (host, service, 0, &ai0);

  dbgprintf ("res %d: %s\n", res, gai_strerror (res));

  if (res != 0)
    {
      /* EAI_AGAIN is returned if no network is available. Don't fail
	 the test merely because someone is down the country on their
	 in-law's farm. */
      if (res == EAI_AGAIN)
	{
	  skip++;
	  fprintf (stderr, "skipping getaddrinfo test: no network?\n");
	  return 77;
	}
      /* IRIX reports EAI_NONAME for "https".  Don't fail the test
	 merely because of this.  */
      if (res == EAI_NONAME)
	return 0;
      /* Solaris reports EAI_SERVICE for "http" and "https".  Don't
         fail the test merely because of this.  */
      if (res == EAI_SERVICE)
	return 0;
      /* AIX reports EAI_NODATA for "https".  Don't fail the test
	 merely because of this.  */
      if (res == EAI_NODATA)
	return 0;

      return 1;
    }

  for (ai = ai0; ai; ai = ai->ai_next)
    {
      dbgprintf ("\tflags %x\n", ai->ai_flags);
      dbgprintf ("\tfamily %x\n", ai->ai_family);
      dbgprintf ("\tsocktype %x\n", ai->ai_socktype);
      dbgprintf ("\tprotocol %x\n", ai->ai_protocol);
      dbgprintf ("\taddrlen %ld: ", (unsigned long) ai->ai_addrlen);
      dbgprintf ("\tFound %s\n",
		 inet_ntop (ai->ai_family,
			    &((struct sockaddr_in *)
			      ai->ai_addr)->sin_addr,
			    buf, sizeof (buf) - 1));
      if (ai->ai_canonname)
	dbgprintf ("\tFound %s...\n", ai->ai_canonname);

      {
	char ipbuf[BUFSIZ];
	char portbuf[BUFSIZ];

	res = getnameinfo (ai->ai_addr, ai->ai_addrlen,
			   ipbuf, sizeof (ipbuf) - 1,
			   portbuf, sizeof (portbuf) - 1,
			   NI_NUMERICHOST|NI_NUMERICSERV);
	dbgprintf ("\t\tgetnameinfo %d: %s\n", res, gai_strerror (res));
	if (res == 0)
	  {
	    dbgprintf ("\t\tip %s\n", ipbuf);
	    dbgprintf ("\t\tport %s\n", portbuf);
	  }
      }

    }

  freeaddrinfo (ai0);

  return 0;
}

#define HOST1 "www.gnu.org"
#define SERV1 "http"
#define HOST2 "www.ibm.com"
#define SERV2 "https"
#define HOST3 "microsoft.com"
#define SERV3 "http"
#define HOST4 "google.org"
#define SERV4 "ldap"

int main (void)
{
#if _WIN32
  {
    WORD requested;
    WSADATA data;
    int err;

    requested = MAKEWORD (1, 1);
    err = WSAStartup (requested, &data);
    if (err != 0)
      return 1;

    if (data.wVersion < requested)
      {
	WSACleanup ();
	return 2;
      }
  }
#endif

  return simple (HOST1, SERV1)
    + simple (HOST2, SERV2)
    + simple (HOST3, SERV3)
    + simple (HOST4, SERV4);
}
