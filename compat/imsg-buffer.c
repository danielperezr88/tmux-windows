<<<<<<< C:\Users\danie\AppData\Local\Temp\w32m\cur.tmp
=======
/*	$OpenBSD: imsg-buffer.c,v 1.36 2025/08/25 08:29:49 claudio Exp $	*/

>>>>>>> C:\Users\danie\AppData\Local\Temp\w32m\master.tmp
/*
 * Copyright (c) 2007 Nicholas Marriott <nicholas.marriott@gmail.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING
 * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef COMPAT_H
#define COMPAT_H

#include <sys/types.h>
<<<<<<< C:\Users\danie\AppData\Local\Temp\w32m\cur.tmp
#include <sys/ioctl.h>
#include <sys/uio.h>
=======
#ifdef _WIN32
#include <winsock2.h>
#include <ws2tcpip.h>
#else
#include <sys/socket.h>
#include <sys/uio.h>
#include <arpa/inet.h>
#endif
>>>>>>> C:\Users\danie\AppData\Local\Temp\w32m\master.tmp

#include <fnmatch.h>
#include <limits.h>
#include <stdio.h>
#include <termios.h>
#include <wchar.h>

#ifdef HAVE_EVENT2_EVENT_H
#include <event2/event.h>
#include <event2/event_compat.h>
#include <event2/event_struct.h>
#include <event2/buffer.h>
#include <event2/buffer_compat.h>
#include <event2/bufferevent.h>
#include <event2/bufferevent_struct.h>
#include <event2/bufferevent_compat.h>
#else
#include <event.h>
#ifndef EVBUFFER_EOL_LF
/*
 * This doesn't really work because evbuffer_readline is broken, but gets us to
 * build with very old (older than 1.4.14) libevent.
 */
#define EVBUFFER_EOL_LF
#define evbuffer_readln(a, b, c) evbuffer_readline(a)
#endif
#endif

#ifdef HAVE_MALLOC_TRIM
#include <malloc.h>
#endif

#ifdef HAVE_UTF8PROC
#include <utf8proc.h>
#endif

#ifndef __GNUC__
#define __attribute__(a)
#endif

#ifdef BROKEN___DEAD
#undef __dead
#endif

#ifndef __unused
#define __unused __attribute__ ((__unused__))
#endif
#ifndef __dead
#define __dead __attribute__ ((__noreturn__))
#endif
#ifndef __packed
#define __packed __attribute__ ((__packed__))
#endif
#ifndef __weak
#define __weak __attribute__ ((__weak__))
#endif

#ifndef ECHOPRT
#define ECHOPRT 0
#endif

#ifndef ACCESSPERMS
#define ACCESSPERMS (S_IRWXU|S_IRWXG|S_IRWXO)
#endif

#if !defined(FIONREAD) && defined(__sun)
#include <sys/filio.h>
#endif

#ifdef HAVE_ERR_H
#include <err.h>
#else
void	err(int, const char *, ...);
void	errx(int, const char *, ...);
void	warn(const char *, ...);
void	warnx(const char *, ...);
#endif

#ifdef HAVE_PATHS_H
#include <paths.h>
#endif

#ifndef _PATH_BSHELL
#define _PATH_BSHELL	"/bin/sh"
#endif

#ifndef _PATH_TMP
#define _PATH_TMP	"/tmp/"
#endif

#ifndef _PATH_DEVNULL
#define _PATH_DEVNULL	"/dev/null"
#endif

#ifndef _PATH_TTY
#define _PATH_TTY	"/dev/tty"
#endif

#ifndef _PATH_DEV
#define _PATH_DEV	"/dev/"
#endif

#ifndef _PATH_DEFPATH
#define _PATH_DEFPATH	"/usr/bin:/bin"
#endif

#ifndef _PATH_VI
#define _PATH_VI	"/usr/bin/vi"
#endif

#ifndef __OpenBSD__
#define pledge(s, p) (0)
#endif

#ifndef IMAXBEL
#define IMAXBEL 0
#endif

#ifdef HAVE_STDINT_H
#include <stdint.h>
<<<<<<< C:\Users\danie\AppData\Local\Temp\w32m\cur.tmp
#else
#include <inttypes.h>
#endif

#ifdef HAVE_QUEUE_H
#include <sys/queue.h>
#else
#include "compat/queue.h"
#endif

#ifdef HAVE_TREE_H
#include <sys/tree.h>
#else
#include "compat/tree.h"
#endif

#ifdef HAVE_BITSTRING_H
#include <bitstring.h>
#else
#include "compat/bitstring.h"
#endif

#ifdef HAVE_LIBUTIL_H
#include <libutil.h>
#endif

#ifdef HAVE_PTY_H
#include <pty.h>
#endif

#ifdef HAVE_UTIL_H
#include <util.h>
#endif

#ifdef HAVE_VIS
#include <vis.h>
#else
#include "compat/vis.h"
#endif

#ifdef HAVE_IMSG
#include <imsg.h>
#else
#include "compat/imsg.h"
#endif

#ifdef BROKEN_CMSG_FIRSTHDR
#undef CMSG_FIRSTHDR
#define CMSG_FIRSTHDR(mhdr) \
	((mhdr)->msg_controllen >= sizeof(struct cmsghdr) ? \
	    (struct cmsghdr *)(mhdr)->msg_control :	    \
	    (struct cmsghdr *)NULL)
#endif

#ifndef CMSG_ALIGN
#ifdef _CMSG_DATA_ALIGN
#define CMSG_ALIGN _CMSG_DATA_ALIGN
#else
#define CMSG_ALIGN(len) (((len) + sizeof(long) - 1) & ~(sizeof(long) - 1))
#endif
#endif

#ifndef CMSG_SPACE
#define CMSG_SPACE(len) (CMSG_ALIGN(sizeof(struct cmsghdr)) + CMSG_ALIGN(len))
#endif

#ifndef CMSG_LEN
#define CMSG_LEN(len) (CMSG_ALIGN(sizeof(struct cmsghdr)) + (len))
#endif

#ifndef O_DIRECTORY
#define O_DIRECTORY 0
#endif

#ifndef FNM_CASEFOLD
#ifdef FNM_IGNORECASE
#define FNM_CASEFOLD FNM_IGNORECASE
#else
#define FNM_CASEFOLD 0
#endif
#endif

#ifndef INFTIM
#define INFTIM -1
#endif

#ifndef WAIT_ANY
#define WAIT_ANY -1
#endif

#ifndef SUN_LEN
#define SUN_LEN(sun) (sizeof (sun)->sun_path)
#endif

#ifndef timercmp
#define	timercmp(tvp, uvp, cmp)						\
	(((tvp)->tv_sec == (uvp)->tv_sec) ?				\
	    ((tvp)->tv_usec cmp (uvp)->tv_usec) :			\
	    ((tvp)->tv_sec cmp (uvp)->tv_sec))
#endif

#ifndef timeradd
#define	timeradd(tvp, uvp, vvp)						\
	do {								\
		(vvp)->tv_sec = (tvp)->tv_sec + (uvp)->tv_sec;		\
		(vvp)->tv_usec = (tvp)->tv_usec + (uvp)->tv_usec;	\
		if ((vvp)->tv_usec >= 1000000) {			\
			(vvp)->tv_sec++;				\
			(vvp)->tv_usec -= 1000000;			\
		}							\
	} while (0)
#endif

#ifndef timersub
#define timersub(tvp, uvp, vvp)                                         \
	do {                                                            \
		(vvp)->tv_sec = (tvp)->tv_sec - (uvp)->tv_sec;          \
		(vvp)->tv_usec = (tvp)->tv_usec - (uvp)->tv_usec;       \
		if ((vvp)->tv_usec < 0) {                               \
			(vvp)->tv_sec--;                                \
			(vvp)->tv_usec += 1000000;                      \
		}                                                       \
	} while (0)
#endif

#ifndef TTY_NAME_MAX
#define TTY_NAME_MAX 32
#endif

#ifndef HOST_NAME_MAX
#define HOST_NAME_MAX 255
#endif

#ifndef CLOCK_REALTIME
#define CLOCK_REALTIME 0
#endif
#ifndef CLOCK_MONOTONIC
#define CLOCK_MONOTONIC CLOCK_REALTIME
#endif

#ifndef HAVE_FLOCK
#define LOCK_SH 0
#define LOCK_EX 0
#define LOCK_NB 0
#define flock(fd, op) (0)
#endif

#ifndef HAVE_EXPLICIT_BZERO
/* explicit_bzero.c */
void		 explicit_bzero(void *, size_t);
#endif

#ifndef HAVE_GETDTABLECOUNT
/* getdtablecount.c */
int		 getdtablecount(void);
#endif

#ifndef HAVE_GETDTABLESIZE
/* getdtablesize.c */
int		 getdtablesize(void);
#endif

#ifndef HAVE_CLOSEFROM
/* closefrom.c */
void		 closefrom(int);
#endif

#ifndef HAVE_STRCASESTR
/* strcasestr.c */
char		*strcasestr(const char *, const char *);
#endif

#ifndef HAVE_STRSEP
/* strsep.c */
char		*strsep(char **, const char *);
#endif

#ifndef HAVE_STRTONUM
/* strtonum.c */
long long	 strtonum(const char *, long long, long long, const char **);
#endif

#ifndef HAVE_STRLCPY
/* strlcpy.c */
size_t	 	 strlcpy(char *, const char *, size_t);
#endif

#ifndef HAVE_STRLCAT
/* strlcat.c */
size_t	 	 strlcat(char *, const char *, size_t);
#endif

#ifndef HAVE_STRNLEN
/* strnlen.c */
size_t		 strnlen(const char *, size_t);
#endif

#ifndef HAVE_STRNDUP
/* strndup.c */
char		*strndup(const char *, size_t);
#endif

#ifndef HAVE_MEMMEM
/* memmem.c */
void		*memmem(const void *, size_t, const void *, size_t);
#endif

#ifndef HAVE_HTONLL
/* htonll.c */
#undef htonll
uint64_t	 htonll(uint64_t);
#endif

#ifndef HAVE_NTOHLL
/* ntohll.c */
#undef ntohll
uint64_t	 ntohll(uint64_t);
#endif

#ifndef HAVE_GETPEEREID
/* getpeereid.c */
int		getpeereid(int, uid_t *, gid_t *);
#endif

#ifndef HAVE_DAEMON
/* daemon.c */
int	 	 daemon(int, int);
#endif

#ifndef HAVE_GETPROGNAME
/* getprogname.c */
const char	*getprogname(void);
#endif

#ifndef HAVE_SETPROCTITLE
/* setproctitle.c */
void		 setproctitle(const char *, ...);
#endif

#ifndef HAVE_CLOCK_GETTIME
/* clock_gettime.c */
int		 clock_gettime(int, struct timespec *);
#endif

#ifndef HAVE_B64_NTOP
/* base64.c */
#undef b64_ntop
#undef b64_pton
int		 b64_ntop(const u_char *, size_t, char *, size_t);
int		 b64_pton(const char *, u_char *, size_t);
#endif

#ifndef HAVE_FDFORKPTY
/* fdforkpty.c */
int		 getptmfd(void);
pid_t		 fdforkpty(int, int *, char *, struct termios *,
		     struct winsize *);
#endif

#ifndef HAVE_FORKPTY
/* forkpty.c */
pid_t		 forkpty(int *, char *, struct termios *, struct winsize *);
#endif

#ifndef HAVE_ASPRINTF
/* asprintf.c */
int		 asprintf(char **, const char *, ...);
int		 vasprintf(char **, const char *, va_list);
#endif

#ifndef HAVE_FGETLN
/* fgetln.c */
char		*fgetln(FILE *, size_t *);
#endif

#ifndef HAVE_GETLINE
/* getline.c */
ssize_t		 getline(char **, size_t *, FILE *);
#endif

#ifndef HAVE_SETENV
/* setenv.c */
int		 setenv(const char *, const char *, int);
int		 unsetenv(const char *);
#endif

#ifndef HAVE_CFMAKERAW
/* cfmakeraw.c */
void		 cfmakeraw(struct termios *);
#endif

#ifndef HAVE_FREEZERO
/* freezero.c */
void		 freezero(void *, size_t);
#endif

#ifndef HAVE_REALLOCARRAY
/* reallocarray.c */
void		*reallocarray(void *, size_t, size_t);
#endif

#ifndef HAVE_RECALLOCARRAY
/* recallocarray.c */
void		*recallocarray(void *, size_t, size_t, size_t);
#endif

#ifdef HAVE_SYSTEMD
/* systemd.c */
int		 systemd_activated(void);
int		 systemd_create_socket(int, char **);
int		 systemd_move_to_new_cgroup(char **);
#endif

#ifdef HAVE_UTF8PROC
/* utf8proc.c */
int		 utf8proc_wcwidth(wchar_t);
int		 utf8proc_mbtowc(wchar_t *, const char *, size_t);
int		 utf8proc_wctomb(char *, wchar_t);
#endif

#ifdef NEED_FUZZING
/* tmux.c */
#define main __weak main
#define regcomp(preg, pattern, cflags) (0)
#define regexec(preg, string, nmatch, pmatch, eflags) (REG_NOMATCH)
#define regfree(preg) ((void)0)
#endif

/* getopt.c */
extern int	 BSDopterr;
extern int	 BSDoptind;
extern int	 BSDoptopt;
extern int	 BSDoptreset;
extern char	*BSDoptarg;
int	BSDgetopt(int, char *const *, const char *);
#define getopt(ac, av, o)  BSDgetopt(ac, av, o)
#define opterr             BSDopterr
#define optind             BSDoptind
#define optopt             BSDoptopt
#define optreset           BSDoptreset
#define optarg             BSDoptarg

#endif /* COMPAT_H */
=======
#include <stdlib.h>
#include <string.h>
#ifndef _WIN32
#include <unistd.h>
#endif

#include "compat.h"
#include "imsg.h"

#undef htobe16
#define htobe16 htons
#undef htobe32
#define htobe32 htonl
#undef htobe64
#define htobe64 htonll
#undef be16toh
#define be16toh ntohs
#undef be32toh
#define be32toh ntohl
#undef be64toh
#define be64toh ntohll

struct ibufqueue {
	TAILQ_HEAD(, ibuf)	bufs;
	uint32_t		queued;
};

struct msgbuf {
	struct ibufqueue	 bufs;
	struct ibufqueue	 rbufs;
	char			*rbuf;
	struct ibuf		*rpmsg;
	struct ibuf		*(*readhdr)(struct ibuf *, void *, int *);
	void			*rarg;
	size_t			 roff;
	size_t			 hdrsize;
};

static void	msgbuf_drain(struct msgbuf *, size_t);
static void	ibufq_init(struct ibufqueue *);

#define	IBUF_FD_MARK_ON_STACK	-2

struct ibuf *
ibuf_open(size_t len)
{
	struct ibuf	*buf;

	if ((buf = calloc(1, sizeof(struct ibuf))) == NULL)
		return (NULL);
	if (len > 0) {
		if ((buf->buf = calloc(len, 1)) == NULL) {
			free(buf);
			return (NULL);
		}
	}
	buf->size = buf->max = len;
	buf->fd = -1;

	return (buf);
}

struct ibuf *
ibuf_dynamic(size_t len, size_t max)
{
	struct ibuf	*buf;

	if (max == 0 || max < len) {
		errno = EINVAL;
		return (NULL);
	}

	if ((buf = calloc(1, sizeof(struct ibuf))) == NULL)
		return (NULL);
	if (len > 0) {
		if ((buf->buf = calloc(len, 1)) == NULL) {
			free(buf);
			return (NULL);
		}
	}
	buf->size = len;
	buf->max = max;
	buf->fd = -1;

	return (buf);
}

void *
ibuf_reserve(struct ibuf *buf, size_t len)
{
	void	*b;

	if (len > SIZE_MAX - buf->wpos) {
		errno = ERANGE;
		return (NULL);
	}
	if (buf->fd == IBUF_FD_MARK_ON_STACK) {
		/* can not grow stack buffers */
		errno = EINVAL;
		return (NULL);
	}

	if (buf->wpos + len > buf->size) {
		unsigned char	*nb;

		/* check if buffer is allowed to grow */
		if (buf->wpos + len > buf->max) {
			errno = ERANGE;
			return (NULL);
		}
		nb = realloc(buf->buf, buf->wpos + len);
		if (nb == NULL)
			return (NULL);
		memset(nb + buf->size, 0, buf->wpos + len - buf->size);
		buf->buf = nb;
		buf->size = buf->wpos + len;
	}

	b = buf->buf + buf->wpos;
	buf->wpos += len;
	return (b);
}

int
ibuf_add(struct ibuf *buf, const void *data, size_t len)
{
	void *b;

	if (len == 0)
		return (0);

	if ((b = ibuf_reserve(buf, len)) == NULL)
		return (-1);

	memcpy(b, data, len);
	return (0);
}

int
ibuf_add_ibuf(struct ibuf *buf, const struct ibuf *from)
{
	return ibuf_add(buf, ibuf_data(from), ibuf_size(from));
}

int
ibuf_add_n8(struct ibuf *buf, uint64_t value)
{
	uint8_t v;

	if (value > UINT8_MAX) {
		errno = EINVAL;
		return (-1);
	}
	v = value;
	return ibuf_add(buf, &v, sizeof(v));
}

int
ibuf_add_n16(struct ibuf *buf, uint64_t value)
{
	uint16_t v;

	if (value > UINT16_MAX) {
		errno = EINVAL;
		return (-1);
	}
	v = htobe16(value);
	return ibuf_add(buf, &v, sizeof(v));
}

int
ibuf_add_n32(struct ibuf *buf, uint64_t value)
{
	uint32_t v;

	if (value > UINT32_MAX) {
		errno = EINVAL;
		return (-1);
	}
	v = htobe32(value);
	return ibuf_add(buf, &v, sizeof(v));
}

int
ibuf_add_n64(struct ibuf *buf, uint64_t value)
{
	value = htobe64(value);
	return ibuf_add(buf, &value, sizeof(value));
}

int
ibuf_add_h16(struct ibuf *buf, uint64_t value)
{
	uint16_t v;

	if (value > UINT16_MAX) {
		errno = EINVAL;
		return (-1);
	}
	v = value;
	return ibuf_add(buf, &v, sizeof(v));
}

int
ibuf_add_h32(struct ibuf *buf, uint64_t value)
{
	uint32_t v;

	if (value > UINT32_MAX) {
		errno = EINVAL;
		return (-1);
	}
	v = value;
	return ibuf_add(buf, &v, sizeof(v));
}

int
ibuf_add_h64(struct ibuf *buf, uint64_t value)
{
	return ibuf_add(buf, &value, sizeof(value));
}

int
ibuf_add_zero(struct ibuf *buf, size_t len)
{
	void *b;

	if (len == 0)
		return (0);

	if ((b = ibuf_reserve(buf, len)) == NULL)
		return (-1);
	memset(b, 0, len);
	return (0);
}

int
ibuf_add_strbuf(struct ibuf *buf, const char *str, size_t len)
{
	char *b;
	size_t n;

	if ((b = ibuf_reserve(buf, len)) == NULL)
		return (-1);

	n = strlcpy(b, str, len);
	if (n >= len) {
		/* also covers the case where len == 0 */
		errno = EOVERFLOW;
		return (-1);
	}
	memset(b + n, 0, len - n);
	return (0);
}

void *
ibuf_seek(struct ibuf *buf, size_t pos, size_t len)
{
	/* only allow seeking between rpos and wpos */
	if (ibuf_size(buf) < pos || SIZE_MAX - pos < len ||
	    ibuf_size(buf) < pos + len) {
		errno = ERANGE;
		return (NULL);
	}

	return (buf->buf + buf->rpos + pos);
}

int
ibuf_set(struct ibuf *buf, size_t pos, const void *data, size_t len)
{
	void *b;

	if ((b = ibuf_seek(buf, pos, len)) == NULL)
		return (-1);

	if (len == 0)
		return (0);
	memcpy(b, data, len);
	return (0);
}

int
ibuf_set_n8(struct ibuf *buf, size_t pos, uint64_t value)
{
	uint8_t v;

	if (value > UINT8_MAX) {
		errno = EINVAL;
		return (-1);
	}
	v = value;
	return (ibuf_set(buf, pos, &v, sizeof(v)));
}

int
ibuf_set_n16(struct ibuf *buf, size_t pos, uint64_t value)
{
	uint16_t v;

	if (value > UINT16_MAX) {
		errno = EINVAL;
		return (-1);
	}
	v = htobe16(value);
	return (ibuf_set(buf, pos, &v, sizeof(v)));
}

int
ibuf_set_n32(struct ibuf *buf, size_t pos, uint64_t value)
{
	uint32_t v;

	if (value > UINT32_MAX) {
		errno = EINVAL;
		return (-1);
	}
	v = htobe32(value);
	return (ibuf_set(buf, pos, &v, sizeof(v)));
}

int
ibuf_set_n64(struct ibuf *buf, size_t pos, uint64_t value)
{
	value = htobe64(value);
	return (ibuf_set(buf, pos, &value, sizeof(value)));
}

int
ibuf_set_h16(struct ibuf *buf, size_t pos, uint64_t value)
{
	uint16_t v;

	if (value > UINT16_MAX) {
		errno = EINVAL;
		return (-1);
	}
	v = value;
	return (ibuf_set(buf, pos, &v, sizeof(v)));
}

int
ibuf_set_h32(struct ibuf *buf, size_t pos, uint64_t value)
{
	uint32_t v;

	if (value > UINT32_MAX) {
		errno = EINVAL;
		return (-1);
	}
	v = value;
	return (ibuf_set(buf, pos, &v, sizeof(v)));
}

int
ibuf_set_h64(struct ibuf *buf, size_t pos, uint64_t value)
{
	return (ibuf_set(buf, pos, &value, sizeof(value)));
}

int
ibuf_set_maxsize(struct ibuf *buf, size_t max)
{
	if (buf->fd == IBUF_FD_MARK_ON_STACK) {
		/* can't fiddle with stack buffers */
		errno = EINVAL;
		return (-1);
	}
	if (max > buf->max) {
		errno = ERANGE;
		return (-1);
	}
	buf->max = max;
	return (0);
}

void *
ibuf_data(const struct ibuf *buf)
{
	return (buf->buf + buf->rpos);
}

size_t
ibuf_size(const struct ibuf *buf)
{
	return (buf->wpos - buf->rpos);
}

size_t
ibuf_left(const struct ibuf *buf)
{
	/* on stack buffers have no space left */
	if (buf->fd == IBUF_FD_MARK_ON_STACK)
		return (0);
	return (buf->max - buf->wpos);
}

int
ibuf_truncate(struct ibuf *buf, size_t len)
{
	if (ibuf_size(buf) >= len) {
		buf->wpos = buf->rpos + len;
		return (0);
	}
	if (buf->fd == IBUF_FD_MARK_ON_STACK) {
		/* only allow to truncate down for stack buffers */
		errno = ERANGE;
		return (-1);
	}
	return ibuf_add_zero(buf, len - ibuf_size(buf));
}

void
ibuf_rewind(struct ibuf *buf)
{
	buf->rpos = 0;
}

void
ibuf_close(struct msgbuf *msgbuf, struct ibuf *buf)
{
	ibufq_push(&msgbuf->bufs, buf);
}

void
ibuf_from_buffer(struct ibuf *buf, void *data, size_t len)
{
	memset(buf, 0, sizeof(*buf));
	buf->buf = data;
	buf->size = buf->wpos = len;
	buf->fd = IBUF_FD_MARK_ON_STACK;
}

void
ibuf_from_ibuf(struct ibuf *buf, const struct ibuf *from)
{
	ibuf_from_buffer(buf, ibuf_data(from), ibuf_size(from));
}

int
ibuf_get(struct ibuf *buf, void *data, size_t len)
{
	if (ibuf_size(buf) < len) {
		errno = EBADMSG;
		return (-1);
	}

	memcpy(data, ibuf_data(buf), len);
	buf->rpos += len;
	return (0);
}

int
ibuf_get_ibuf(struct ibuf *buf, size_t len, struct ibuf *new)
{
	if (ibuf_size(buf) < len) {
		errno = EBADMSG;
		return (-1);
	}

	ibuf_from_buffer(new, ibuf_data(buf), len);
	buf->rpos += len;
	return (0);
}

int
ibuf_get_h16(struct ibuf *buf, uint16_t *value)
{
	return ibuf_get(buf, value, sizeof(*value));
}

int
ibuf_get_h32(struct ibuf *buf, uint32_t *value)
{
	return ibuf_get(buf, value, sizeof(*value));
}

int
ibuf_get_h64(struct ibuf *buf, uint64_t *value)
{
	return ibuf_get(buf, value, sizeof(*value));
}

int
ibuf_get_n8(struct ibuf *buf, uint8_t *value)
{
	return ibuf_get(buf, value, sizeof(*value));
}

int
ibuf_get_n16(struct ibuf *buf, uint16_t *value)
{
	int rv;

	rv = ibuf_get(buf, value, sizeof(*value));
	*value = be16toh(*value);
	return (rv);
}

int
ibuf_get_n32(struct ibuf *buf, uint32_t *value)
{
	int rv;

	rv = ibuf_get(buf, value, sizeof(*value));
	*value = be32toh(*value);
	return (rv);
}

int
ibuf_get_n64(struct ibuf *buf, uint64_t *value)
{
	int rv;

	rv = ibuf_get(buf, value, sizeof(*value));
	*value = be64toh(*value);
	return (rv);
}

char *
ibuf_get_string(struct ibuf *buf, size_t len)
{
	char *str;

	if (ibuf_size(buf) < len) {
		errno = EBADMSG;
		return (NULL);
	}

	str = strndup(ibuf_data(buf), len);
	if (str == NULL)
		return (NULL);
	buf->rpos += len;
	return (str);
}

int
ibuf_get_strbuf(struct ibuf *buf, char *str, size_t len)
{
	if (len == 0) {
		errno = EINVAL;
		return (-1);
	}

	if (ibuf_get(buf, str, len) == -1)
		return -1;
	if (str[len - 1] != '\0') {
		str[len - 1] = '\0';
		errno = EOVERFLOW;
		return -1;
	}
	return 0;
}

int
ibuf_skip(struct ibuf *buf, size_t len)
{
	if (ibuf_size(buf) < len) {
		errno = EBADMSG;
		return (-1);
	}

	buf->rpos += len;
	return (0);
}

void
ibuf_free(struct ibuf *buf)
{
	int save_errno = errno;

	if (buf == NULL)
		return;
	/* if buf lives on the stack abort before causing more harm */
	if (buf->fd == IBUF_FD_MARK_ON_STACK)
		abort();
	if (buf->fd >= 0)
		close(buf->fd);
	freezero(buf->buf, buf->size);
	free(buf);
	errno = save_errno;
}

int
ibuf_fd_avail(struct ibuf *buf)
{
	return (buf->fd >= 0);
}

int
ibuf_fd_get(struct ibuf *buf)
{
	int fd;

	/* negative fds are internal use and equivalent to -1 */
	if (buf->fd < 0)
		return (-1);
	fd = buf->fd;
	buf->fd = -1;
	return (fd);
}

void
ibuf_fd_set(struct ibuf *buf, int fd)
{
	/* if buf lives on the stack abort before causing more harm */
	if (buf->fd == IBUF_FD_MARK_ON_STACK)
		abort();
	if (buf->fd >= 0)
		close(buf->fd);
	buf->fd = -1;
	if (fd >= 0)
		buf->fd = fd;
}

struct msgbuf *
msgbuf_new(void)
{
	struct msgbuf *msgbuf;

	if ((msgbuf = calloc(1, sizeof(*msgbuf))) == NULL)
		return (NULL);
	ibufq_init(&msgbuf->bufs);
	ibufq_init(&msgbuf->rbufs);

	return msgbuf;
}

struct msgbuf *
msgbuf_new_reader(size_t hdrsz,
    struct ibuf *(*readhdr)(struct ibuf *, void *, int *), void *arg)
{
	struct msgbuf *msgbuf;
	char *buf;

	if (hdrsz == 0 || hdrsz > IBUF_READ_SIZE / 2) {
		errno = EINVAL;
		return (NULL);
	}

	if ((buf = malloc(IBUF_READ_SIZE)) == NULL)
		return (NULL);

	msgbuf = msgbuf_new();
	if (msgbuf == NULL) {
		free(buf);
		return (NULL);
	}

	msgbuf->rbuf = buf;
	msgbuf->hdrsize = hdrsz;
	msgbuf->readhdr = readhdr;
	msgbuf->rarg = arg;

	return (msgbuf);
}

void
msgbuf_free(struct msgbuf *msgbuf)
{
	if (msgbuf == NULL)
		return;
	msgbuf_clear(msgbuf);
	free(msgbuf->rbuf);
	free(msgbuf);
}

uint32_t
msgbuf_queuelen(struct msgbuf *msgbuf)
{
	return ibufq_queuelen(&msgbuf->bufs);
}

void
msgbuf_clear(struct msgbuf *msgbuf)
{
	/* write side */
	ibufq_flush(&msgbuf->bufs);

	/* read side */
	ibufq_flush(&msgbuf->rbufs);
	msgbuf->roff = 0;
	ibuf_free(msgbuf->rpmsg);
	msgbuf->rpmsg = NULL;
}

struct ibuf *
msgbuf_get(struct msgbuf *msgbuf)
{
	return ibufq_pop(&msgbuf->rbufs);
}

void
msgbuf_concat(struct msgbuf *msgbuf, struct ibufqueue *from)
{
	ibufq_concat(&msgbuf->bufs, from);
}

int
ibuf_write(int fd, struct msgbuf *msgbuf)
{
#ifdef _WIN32
	struct ibuf	*buf;
	ssize_t		 n;
	size_t		 total = 0;

	TAILQ_FOREACH(buf, &msgbuf->bufs.bufs, entry) {
 again:
		if ((n = send(fd, ibuf_data(buf), ibuf_size(buf), 0)) == -1) {
			int wsa_err = WSAGetLastError();
			if (wsa_err == WSAEINTR)
				goto again;
			if (wsa_err == WSAEWOULDBLOCK || wsa_err == WSAENOBUFS) {
				if (total > 0)
					break;
				return (0);
			}
			return (-1);
		}
		total += n;
	}
	if (total == 0)
		return (0);	/* nothing queued */

	msgbuf_drain(msgbuf, total);
	return (0);
#else
	struct iovec	 iov[IOV_MAX];
	struct ibuf	*buf;
	unsigned int	 i = 0;
	ssize_t	n;

	memset(&iov, 0, sizeof(iov));
	TAILQ_FOREACH(buf, &msgbuf->bufs.bufs, entry) {
		if (i >= IOV_MAX)
			break;
		iov[i].iov_base = ibuf_data(buf);
		iov[i].iov_len = ibuf_size(buf);
		i++;
	}
	if (i == 0)
		return (0);	/* nothing queued */

 again:
	if ((n = writev(fd, iov, i)) == -1) {
		if (errno == EINTR)
			goto again;
		if (errno == EAGAIN || errno == ENOBUFS)
			/* lets retry later again */
			return (0);
		return (-1);
	}

	msgbuf_drain(msgbuf, n);
	return (0);
#endif
}

int
msgbuf_write(int fd, struct msgbuf *msgbuf)
{
#ifdef _WIN32
	/*
	 * Windows does not support sendmsg/SCM_RIGHTS fd passing.
	 * Use simple send() calls instead.
	 */
	struct ibuf	*buf;
	ssize_t		 n;
	size_t		 total = 0;

	TAILQ_FOREACH(buf, &msgbuf->bufs.bufs, entry) {
 again:
		if ((n = send(fd, ibuf_data(buf), ibuf_size(buf), 0)) == -1) {
			int wsa_err = WSAGetLastError();
			if (wsa_err == WSAEINTR)
				goto again;
			if (wsa_err == WSAEWOULDBLOCK || wsa_err == WSAENOBUFS) {
				if (total > 0)
					break;
				return (0);
			}
			return (-1);
		}
		total += n;
	}
	if (total == 0)
		return (0);	/* nothing queued */

	msgbuf_drain(msgbuf, total);
	return (0);
#else
	struct iovec	 iov[IOV_MAX];
	struct ibuf	*buf, *buf0 = NULL;
	unsigned int	 i = 0;
	ssize_t		 n;
	struct msghdr	 msg;
	struct cmsghdr	*cmsg;
	union {
		struct cmsghdr	hdr;
		char		buf[CMSG_SPACE(sizeof(int))];
	} cmsgbuf;

	memset(&iov, 0, sizeof(iov));
	memset(&msg, 0, sizeof(msg));
	memset(&cmsgbuf, 0, sizeof(cmsgbuf));
	TAILQ_FOREACH(buf, &msgbuf->bufs.bufs, entry) {
		if (i >= IOV_MAX)
			break;
		if (i > 0 && buf->fd != -1)
			break;
		iov[i].iov_base = ibuf_data(buf);
		iov[i].iov_len = ibuf_size(buf);
		i++;
		if (buf->fd != -1)
			buf0 = buf;
	}

	if (i == 0)
		return (0);	/* nothing queued */

	msg.msg_iov = iov;
	msg.msg_iovlen = i;

	if (buf0 != NULL) {
		msg.msg_control = (caddr_t)&cmsgbuf.buf;
		msg.msg_controllen = sizeof(cmsgbuf.buf);
		cmsg = CMSG_FIRSTHDR(&msg);
		cmsg->cmsg_len = CMSG_LEN(sizeof(int));
		cmsg->cmsg_level = SOL_SOCKET;
		cmsg->cmsg_type = SCM_RIGHTS;
		*(int *)CMSG_DATA(cmsg) = buf0->fd;
	}

 again:
	if ((n = sendmsg(fd, &msg, 0)) == -1) {
		if (errno == EINTR)
			goto again;
		if (errno == EAGAIN || errno == ENOBUFS)
			/* lets retry later again */
			return (0);
		return (-1);
	}

	/*
	 * assumption: fd got sent if sendmsg sent anything
	 * this works because fds are passed one at a time
	 */
	if (buf0 != NULL) {
		close(buf0->fd);
		buf0->fd = -1;
	}

	msgbuf_drain(msgbuf, n);

	return (0);
#endif
}

static int
ibuf_read_process(struct msgbuf *msgbuf, int fd)
{
	struct ibuf rbuf, msg;
	ssize_t sz;

	ibuf_from_buffer(&rbuf, msgbuf->rbuf, msgbuf->roff);

	do {
		if (msgbuf->rpmsg == NULL) {
			if (ibuf_size(&rbuf) < msgbuf->hdrsize)
				break;
			/* get size from header */
			ibuf_from_buffer(&msg, ibuf_data(&rbuf),
			    msgbuf->hdrsize);
			if ((msgbuf->rpmsg = msgbuf->readhdr(&msg,
			    msgbuf->rarg, &fd)) == NULL)
				goto fail;
		}

		if (ibuf_left(msgbuf->rpmsg) <= ibuf_size(&rbuf))
			sz = ibuf_left(msgbuf->rpmsg);
		else
			sz = ibuf_size(&rbuf);

		/* neither call below can fail */
		if (ibuf_get_ibuf(&rbuf, sz, &msg) == -1 ||
		    ibuf_add_ibuf(msgbuf->rpmsg, &msg) == -1)
			goto fail;

		if (ibuf_left(msgbuf->rpmsg) == 0) {
			ibufq_push(&msgbuf->rbufs, msgbuf->rpmsg);
			msgbuf->rpmsg = NULL;
		}
	} while (ibuf_size(&rbuf) > 0);

	if (ibuf_size(&rbuf) > 0)
		memmove(msgbuf->rbuf, ibuf_data(&rbuf), ibuf_size(&rbuf));
	msgbuf->roff = ibuf_size(&rbuf);

	if (fd != -1)
		close(fd);
	return (1);

 fail:
	/* XXX how to properly clean up is unclear */
	if (fd != -1)
		close(fd);
	return (-1);
}

int
ibuf_read(int fd, struct msgbuf *msgbuf)
{
	ssize_t		n;

	if (msgbuf->rbuf == NULL) {
		errno = EINVAL;
		return (-1);
	}

#ifdef _WIN32
 again:
	if ((n = recv(fd, msgbuf->rbuf + msgbuf->roff,
	    IBUF_READ_SIZE - msgbuf->roff, 0)) == -1) {
		int wsa_err = WSAGetLastError();
		if (wsa_err == WSAEINTR)
			goto again;
		if (wsa_err == WSAEWOULDBLOCK)
			/* lets retry later again */
			return (1);
		return (-1);
	}
#else
	struct iovec	iov;

	iov.iov_base = msgbuf->rbuf + msgbuf->roff;
	iov.iov_len = IBUF_READ_SIZE - msgbuf->roff;

 again:
	if ((n = readv(fd, &iov, 1)) == -1) {
		if (errno == EINTR)
			goto again;
		if (errno == EAGAIN)
			/* lets retry later again */
			return (1);
		return (-1);
	}
#endif
	if (n == 0)	/* connection closed */
		return (0);

	msgbuf->roff += n;
	/* new data arrived, try to process it */
	return (ibuf_read_process(msgbuf, -1));
}

int
msgbuf_read(int fd, struct msgbuf *msgbuf)
{
#ifdef _WIN32
	/*
	 * Windows does not support recvmsg/SCM_RIGHTS fd passing.
	 * Use simple recv() instead.
	 */
	ssize_t			 n;

	if (msgbuf->rbuf == NULL) {
		errno = EINVAL;
		return (-1);
	}

again:
	if ((n = recv(fd, msgbuf->rbuf + msgbuf->roff,
	    IBUF_READ_SIZE - msgbuf->roff, 0)) == -1) {
		int wsa_err = WSAGetLastError();
		if (wsa_err == WSAEINTR)
			goto again;
		if (wsa_err == WSAEWOULDBLOCK)
			/* lets retry later again */
			return (1);
		return (-1);
	}
	if (n == 0)	/* connection closed */
		return (0);

	msgbuf->roff += n;

	/* new data arrived, try to process it (no fd passing on Windows) */
	return (ibuf_read_process(msgbuf, -1));
#else
	struct msghdr		 msg;
	struct cmsghdr		*cmsg;
	union {
		struct cmsghdr hdr;
		char	buf[CMSG_SPACE(sizeof(int) * 1)];
	} cmsgbuf;
	struct iovec		 iov;
	ssize_t			 n;
	int			 fdpass = -1;

	if (msgbuf->rbuf == NULL) {
		errno = EINVAL;
		return (-1);
	}

	memset(&msg, 0, sizeof(msg));
	memset(&cmsgbuf, 0, sizeof(cmsgbuf));

	iov.iov_base = msgbuf->rbuf + msgbuf->roff;
	iov.iov_len = IBUF_READ_SIZE - msgbuf->roff;
	msg.msg_iov = &iov;
	msg.msg_iovlen = 1;
	msg.msg_control = &cmsgbuf.buf;
	msg.msg_controllen = sizeof(cmsgbuf.buf);

again:
	if ((n = recvmsg(fd, &msg, 0)) == -1) {
		if (errno == EINTR)
			goto again;
		if (errno == EMSGSIZE)
			/*
			 * Not enough fd slots: fd passing failed, retry
			 * to receive the message without fd.
			 * imsg_get_fd() will return -1 in that case.
			 */
			goto again;
		if (errno == EAGAIN)
			/* lets retry later again */
			return (1);
		return (-1);
	}
	if (n == 0)	/* connection closed */
		return (0);

	msgbuf->roff += n;

	for (cmsg = CMSG_FIRSTHDR(&msg); cmsg != NULL;
	    cmsg = CMSG_NXTHDR(&msg, cmsg)) {
		if (cmsg->cmsg_level == SOL_SOCKET &&
		    cmsg->cmsg_type == SCM_RIGHTS) {
			int i, j, f;

			/*
			 * We only accept one file descriptor.  Due to C
			 * padding rules, our control buffer might contain
			 * more than one fd, and we must close them.
			 */
			j = ((char *)cmsg + cmsg->cmsg_len -
			    (char *)CMSG_DATA(cmsg)) / sizeof(int);
			for (i = 0; i < j; i++) {
				f = ((int *)CMSG_DATA(cmsg))[i];
				if (i == 0)
					fdpass = f;
				else
					close(f);
			}
		}
		/* we do not handle other ctl data level */
	}

	/* new data arrived, try to process it */
	return (ibuf_read_process(msgbuf, fdpass));
#endif
}

static void
msgbuf_drain(struct msgbuf *msgbuf, size_t n)
{
	struct ibuf	*buf;

	while ((buf = TAILQ_FIRST(&msgbuf->bufs.bufs)) != NULL) {
		if (n >= ibuf_size(buf)) {
			n -= ibuf_size(buf);
			TAILQ_REMOVE(&msgbuf->bufs.bufs, buf, entry);
			msgbuf->bufs.queued--;
			ibuf_free(buf);
		} else {
			buf->rpos += n;
			return;
		}
	}
}

static void
ibufq_init(struct ibufqueue *bufq)
{
	TAILQ_INIT(&bufq->bufs);
	bufq->queued = 0;
}

struct ibufqueue *
ibufq_new(void)
{
	struct ibufqueue *bufq;

	if ((bufq = calloc(1, sizeof(*bufq))) == NULL)
		return NULL;
	ibufq_init(bufq);
	return bufq;
}

void
ibufq_free(struct ibufqueue *bufq)
{
	if (bufq == NULL)
		return;
	ibufq_flush(bufq);
	free(bufq);
}

struct ibuf *
ibufq_pop(struct ibufqueue *bufq)
{
	struct ibuf *buf;

	if ((buf = TAILQ_FIRST(&bufq->bufs)) == NULL)
		return NULL;
	TAILQ_REMOVE(&bufq->bufs, buf, entry);
	bufq->queued--;
	return buf;
}

void
ibufq_push(struct ibufqueue *bufq, struct ibuf *buf)
{
	/* if buf lives on the stack abort before causing more harm */
	if (buf->fd == IBUF_FD_MARK_ON_STACK)
		abort();
	TAILQ_INSERT_TAIL(&bufq->bufs, buf, entry);
	bufq->queued++;
}

uint32_t
ibufq_queuelen(struct ibufqueue *bufq)
{
	return (bufq->queued);
}

void
ibufq_concat(struct ibufqueue *to, struct ibufqueue *from)
{
	to->queued += from->queued;
	TAILQ_CONCAT(&to->bufs, &from->bufs, entry);
	from->queued = 0;
}

void
ibufq_flush(struct ibufqueue *bufq)
{
	struct ibuf *buf;

	while ((buf = TAILQ_FIRST(&bufq->bufs)) != NULL) {
		TAILQ_REMOVE(&bufq->bufs, buf, entry);
		ibuf_free(buf);
	}
	bufq->queued = 0;
}
>>>>>>> C:\Users\danie\AppData\Local\Temp\w32m\master.tmp
