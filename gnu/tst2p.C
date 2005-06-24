# 1 "<stdin>"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "<stdin>"
# 1 "/usr/include/c++/3.3/vector" 1
# 64 "/usr/include/c++/3.3/vector"
       
# 65 "/usr/include/c++/3.3/vector" 3

# 1 "/usr/include/c++/3.3/bits/functexcept.h" 1 3
# 34 "/usr/include/c++/3.3/bits/functexcept.h" 3
# 1 "/usr/include/c++/3.3/exception_defines.h" 1 3
# 35 "/usr/include/c++/3.3/bits/functexcept.h" 2 3

namespace std
{

  void
  __throw_bad_exception(void);


  void
  __throw_bad_alloc(void);


  void
  __throw_bad_cast(void);

  void
  __throw_bad_typeid(void);


  void
  __throw_logic_error(const char* __s);

  void
  __throw_domain_error(const char* __s);

  void
  __throw_invalid_argument(const char* __s);

  void
  __throw_length_error(const char* __s);

  void
  __throw_out_of_range(const char* __s);

  void
  __throw_runtime_error(const char* __s);

  void
  __throw_range_error(const char* __s);

  void
  __throw_overflow_error(const char* __s);

  void
  __throw_underflow_error(const char* __s);


  void
  __throw_ios_failure(const char* __s);
}
# 67 "/usr/include/c++/3.3/vector" 2 3
# 1 "/usr/include/c++/3.3/bits/stl_algobase.h" 1 3
# 64 "/usr/include/c++/3.3/bits/stl_algobase.h" 3
# 1 "/usr/include/c++/3.3/i486-linux/bits/c++config.h" 1 3
# 35 "/usr/include/c++/3.3/i486-linux/bits/c++config.h" 3
# 1 "/usr/include/c++/3.3/i486-linux/bits/os_defines.h" 1 3
# 39 "/usr/include/c++/3.3/i486-linux/bits/os_defines.h" 3
# 1 "/usr/include/features.h" 1 3 4
# 295 "/usr/include/features.h" 3 4
# 1 "/usr/include/sys/cdefs.h" 1 3 4
# 296 "/usr/include/features.h" 2 3 4
# 318 "/usr/include/features.h" 3 4
# 1 "/usr/include/gnu/stubs.h" 1 3 4
# 319 "/usr/include/features.h" 2 3 4
# 40 "/usr/include/c++/3.3/i486-linux/bits/os_defines.h" 2 3
# 36 "/usr/include/c++/3.3/i486-linux/bits/c++config.h" 2 3
# 65 "/usr/include/c++/3.3/bits/stl_algobase.h" 2 3
# 1 "/usr/include/c++/3.3/cstring" 1 3
# 47 "/usr/include/c++/3.3/cstring" 3
       
# 48 "/usr/include/c++/3.3/cstring" 3

# 1 "/usr/include/c++/3.3/cstddef" 1 3
# 46 "/usr/include/c++/3.3/cstddef" 3
       
# 47 "/usr/include/c++/3.3/cstddef" 3

# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 1 3
# 151 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 3
typedef int ptrdiff_t;
# 213 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 3
typedef unsigned int size_t;
# 325 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 3
typedef long int wchar_t;
# 49 "/usr/include/c++/3.3/cstddef" 2 3

namespace std
{
  using ::ptrdiff_t;
  using ::size_t;
}
# 50 "/usr/include/c++/3.3/cstring" 2 3

# 1 "/usr/include/string.h" 1 3 4
# 28 "/usr/include/string.h" 3 4





# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 1 3 4
# 34 "/usr/include/string.h" 2 3 4




extern void *memcpy (void * __dest,
                     const void * __src, size_t __n) ;


extern void *memmove (void *__dest, const void *__src, size_t __n)
     ;






extern void *memccpy (void * __dest, const void * __src,
                      int __c, size_t __n)
     ;





extern void *memset (void *__s, int __c, size_t __n) ;


extern int memcmp (const void *__s1, const void *__s2, size_t __n)
     ;


extern void *memchr (const void *__s, int __c, size_t __n)
      ;





extern void *rawmemchr (const void *__s, int __c) ;


extern void *memrchr (const void *__s, int __c, size_t __n)
      ;





extern char *strcpy (char * __dest, const char * __src)
     ;

extern char *strncpy (char * __dest,
                      const char * __src, size_t __n) ;


extern char *strcat (char * __dest, const char * __src)
     ;

extern char *strncat (char * __dest, const char * __src,
                      size_t __n) ;


extern int strcmp (const char *__s1, const char *__s2)
     ;

extern int strncmp (const char *__s1, const char *__s2, size_t __n)
     ;


extern int strcoll (const char *__s1, const char *__s2)
     ;

extern size_t strxfrm (char * __dest,
                       const char * __src, size_t __n) ;






# 1 "/usr/include/xlocale.h" 1 3 4
# 28 "/usr/include/xlocale.h" 3 4
typedef struct __locale_struct
{

  struct locale_data *__locales[13];


  const unsigned short int *__ctype_b;
  const int *__ctype_tolower;
  const int *__ctype_toupper;


  const char *__names[13];
} *__locale_t;
# 115 "/usr/include/string.h" 2 3 4


extern int strcoll_l (const char *__s1, const char *__s2, __locale_t __l)
     ;

extern size_t strxfrm_l (char *__dest, const char *__src, size_t __n,
                         __locale_t __l) ;




extern char *strdup (const char *__s) ;






extern char *strndup (const char *__string, size_t __n)
     ;
# 160 "/usr/include/string.h" 3 4


extern char *strchr (const char *__s, int __c) ;

extern char *strrchr (const char *__s, int __c) ;





extern char *strchrnul (const char *__s, int __c) ;





extern size_t strcspn (const char *__s, const char *__reject)
     ;


extern size_t strspn (const char *__s, const char *__accept)
     ;

extern char *strpbrk (const char *__s, const char *__accept)
     ;

extern char *strstr (const char *__haystack, const char *__needle)
     ;



extern char *strtok (char * __s, const char * __delim)
     ;




extern char *__strtok_r (char * __s,
                         const char * __delim,
                         char ** __save_ptr) ;

extern char *strtok_r (char * __s, const char * __delim,
                       char ** __save_ptr) ;




extern char *strcasestr (const char *__haystack, const char *__needle)
     ;






extern void *memmem (const void *__haystack, size_t __haystacklen,
                     const void *__needle, size_t __needlelen)
     ;



extern void *__mempcpy (void * __dest,
                        const void * __src, size_t __n) ;
extern void *mempcpy (void * __dest,
                      const void * __src, size_t __n) ;





extern size_t strlen (const char *__s) ;





extern size_t strnlen (const char *__string, size_t __maxlen)
     ;





extern char *strerror (int __errnum) ;




extern char *strerror_r (int __errnum, char *__buf, size_t __buflen) ;




extern void __bzero (void *__s, size_t __n) ;



extern void bcopy (const void *__src, void *__dest, size_t __n) ;


extern void bzero (void *__s, size_t __n) ;


extern int bcmp (const void *__s1, const void *__s2, size_t __n)
     ;


extern char *index (const char *__s, int __c) ;


extern char *rindex (const char *__s, int __c) ;



extern int ffs (int __i) ;




extern int ffsl (long int __l) ;







extern int strcasecmp (const char *__s1, const char *__s2)
     ;


extern int strncasecmp (const char *__s1, const char *__s2, size_t __n)
     ;





extern int strcasecmp_l (const char *__s1, const char *__s2,
                         __locale_t __loc) ;

extern int strncasecmp_l (const char *__s1, const char *__s2,
                          size_t __n, __locale_t __loc)
     ;





extern char *strsep (char ** __stringp,
                     const char * __delim) ;




extern int strverscmp (const char *__s1, const char *__s2)
     ;


extern char *strsignal (int __sig) ;


extern char *__stpcpy (char * __dest, const char * __src)
     ;
extern char *stpcpy (char * __dest, const char * __src)
     ;



extern char *__stpncpy (char * __dest,
                        const char * __src, size_t __n) ;
extern char *stpncpy (char * __dest,
                      const char * __src, size_t __n) ;


extern char *strfry (char *__string) ;


extern void *memfrob (void *__s, size_t __n) ;






extern char *basename (const char *__filename) ;
# 379 "/usr/include/string.h" 3 4

# 52 "/usr/include/c++/3.3/cstring" 2 3
# 77 "/usr/include/c++/3.3/cstring" 3
namespace std
{
  using ::memcpy;
  using ::memmove;
  using ::strcpy;
  using ::strncpy;
  using ::strcat;
  using ::strncat;
  using ::memcmp;
  using ::strcmp;
  using ::strcoll;
  using ::strncmp;
  using ::strxfrm;
  using ::strcspn;
  using ::strspn;
  using ::strtok;
  using ::memset;
  using ::strerror;
  using ::strlen;

  using ::memchr;

  inline void*
  memchr(void* __p, int __c, size_t __n)
  { return memchr(const_cast<const void*>(__p), __c, __n); }

  using ::strchr;

  inline char*
  strchr(char* __s1, int __n)
  { return __builtin_strchr(const_cast<const char*>(__s1), __n); }

  using ::strpbrk;

  inline char*
  strpbrk(char* __s1, const char* __s2)
  { return __builtin_strpbrk(const_cast<const char*>(__s1), __s2); }

  using ::strrchr;

  inline char*
  strrchr(char* __s1, int __n)
  { return __builtin_strrchr(const_cast<const char*>(__s1), __n); }

  using ::strstr;

  inline char*
  strstr(char* __s1, const char* __s2)
  { return __builtin_strstr(const_cast<const char*>(__s1), __s2); }
}
# 66 "/usr/include/c++/3.3/bits/stl_algobase.h" 2 3
# 1 "/usr/include/c++/3.3/climits" 1 3
# 47 "/usr/include/c++/3.3/climits" 3
       
# 48 "/usr/include/c++/3.3/climits" 3

# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/limits.h" 1 3
# 11 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/limits.h" 3
# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/syslimits.h" 1 3






# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/limits.h" 1 3
# 122 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/limits.h" 3
# 1 "/usr/include/limits.h" 1 3 4
# 45 "/usr/include/limits.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 46 "/usr/include/limits.h" 2 3 4
# 144 "/usr/include/limits.h" 3 4
# 1 "/usr/include/bits/posix1_lim.h" 1 3 4
# 130 "/usr/include/bits/posix1_lim.h" 3 4
# 1 "/usr/include/bits/local_lim.h" 1 3 4
# 36 "/usr/include/bits/local_lim.h" 3 4
# 1 "/usr/include/linux/limits.h" 1 3 4
# 37 "/usr/include/bits/local_lim.h" 2 3 4
# 131 "/usr/include/bits/posix1_lim.h" 2 3 4
# 145 "/usr/include/limits.h" 2 3 4



# 1 "/usr/include/bits/posix2_lim.h" 1 3 4
# 149 "/usr/include/limits.h" 2 3 4



# 1 "/usr/include/bits/xopen_lim.h" 1 3 4
# 34 "/usr/include/bits/xopen_lim.h" 3 4
# 1 "/usr/include/bits/stdio_lim.h" 1 3 4
# 35 "/usr/include/bits/xopen_lim.h" 2 3 4
# 153 "/usr/include/limits.h" 2 3 4
# 123 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/limits.h" 2 3
# 8 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/syslimits.h" 2 3
# 12 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/limits.h" 2 3
# 50 "/usr/include/c++/3.3/climits" 2 3
# 67 "/usr/include/c++/3.3/bits/stl_algobase.h" 2 3
# 1 "/usr/include/c++/3.3/cstdlib" 1 3
# 47 "/usr/include/c++/3.3/cstdlib" 3
       
# 48 "/usr/include/c++/3.3/cstdlib" 3




# 1 "/usr/include/stdlib.h" 1 3 4
# 33 "/usr/include/stdlib.h" 3 4
# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 1 3 4
# 34 "/usr/include/stdlib.h" 2 3 4








# 1 "/usr/include/bits/waitflags.h" 1 3 4
# 43 "/usr/include/stdlib.h" 2 3 4
# 1 "/usr/include/bits/waitstatus.h" 1 3 4
# 63 "/usr/include/bits/waitstatus.h" 3 4
# 1 "/usr/include/endian.h" 1 3 4
# 37 "/usr/include/endian.h" 3 4
# 1 "/usr/include/bits/endian.h" 1 3 4
# 38 "/usr/include/endian.h" 2 3 4
# 64 "/usr/include/bits/waitstatus.h" 2 3 4

union wait
  {
    int w_status;
    struct
      {

        unsigned int __w_termsig:7;
        unsigned int __w_coredump:1;
        unsigned int __w_retcode:8;
        unsigned int:16;







      } __wait_terminated;
    struct
      {

        unsigned int __w_stopval:8;
        unsigned int __w_stopsig:8;
        unsigned int:16;






      } __wait_stopped;
  };
# 44 "/usr/include/stdlib.h" 2 3 4
# 93 "/usr/include/stdlib.h" 3 4


typedef struct
  {
    int quot;
    int rem;
  } div_t;



typedef struct
  {
    long int quot;
    long int rem;
  } ldiv_t;







 typedef struct
  {
    long long int quot;
    long long int rem;
  } lldiv_t;


# 137 "/usr/include/stdlib.h" 3 4
extern size_t __ctype_get_mb_cur_max (void) ;




extern double atof (const char *__nptr) ;

extern int atoi (const char *__nptr) ;

extern long int atol (const char *__nptr) ;





 extern long long int atoll (const char *__nptr)
     ;





extern double strtod (const char * __nptr,
                      char ** __endptr) ;





extern float strtof (const char * __nptr,
                     char ** __endptr) ;

extern long double strtold (const char * __nptr,
                            char ** __endptr) ;





extern long int strtol (const char * __nptr,
                        char ** __endptr, int __base) ;

extern unsigned long int strtoul (const char * __nptr,
                                  char ** __endptr, int __base)
     ;

# 197 "/usr/include/stdlib.h" 3 4



extern long long int strtoll (const char * __nptr,
                              char ** __endptr, int __base) ;


extern unsigned long long int strtoull (const char * __nptr,
                                        char ** __endptr, int __base)
     ;

# 229 "/usr/include/stdlib.h" 3 4
extern long int strtol_l (const char * __nptr,
                          char ** __endptr, int __base,
                          __locale_t __loc) ;

extern unsigned long int strtoul_l (const char * __nptr,
                                    char ** __endptr,
                                    int __base, __locale_t __loc) ;


extern long long int strtoll_l (const char * __nptr,
                                char ** __endptr, int __base,
                                __locale_t __loc) ;


extern unsigned long long int strtoull_l (const char * __nptr,
                                          char ** __endptr,
                                          int __base, __locale_t __loc)
     ;

extern double strtod_l (const char * __nptr,
                        char ** __endptr, __locale_t __loc)
     ;

extern float strtof_l (const char * __nptr,
                       char ** __endptr, __locale_t __loc) ;

extern long double strtold_l (const char * __nptr,
                              char ** __endptr,
                              __locale_t __loc) ;






extern double __strtod_internal (const char * __nptr,
                                 char ** __endptr, int __group)
     ;
extern float __strtof_internal (const char * __nptr,
                                char ** __endptr, int __group)
     ;
extern long double __strtold_internal (const char * __nptr,
                                       char ** __endptr,
                                       int __group) ;

extern long int __strtol_internal (const char * __nptr,
                                   char ** __endptr,
                                   int __base, int __group) ;



extern unsigned long int __strtoul_internal (const char * __nptr,
                                             char ** __endptr,
                                             int __base, int __group) ;





extern long long int __strtoll_internal (const char * __nptr,
                                         char ** __endptr,
                                         int __base, int __group) ;




extern unsigned long long int __strtoull_internal (const char *
                                                   __nptr,
                                                   char ** __endptr,
                                                   int __base, int __group)
     ;
# 408 "/usr/include/stdlib.h" 3 4
extern char *l64a (long int __n) ;


extern long int a64l (const char *__s) ;




# 1 "/usr/include/sys/types.h" 1 3 4
# 29 "/usr/include/sys/types.h" 3 4


# 1 "/usr/include/bits/types.h" 1 3 4
# 28 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 29 "/usr/include/bits/types.h" 2 3 4


# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 1 3 4
# 32 "/usr/include/bits/types.h" 2 3 4


typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;


typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef signed short int __int16_t;
typedef unsigned short int __uint16_t;
typedef signed int __int32_t;
typedef unsigned int __uint32_t;
# 63 "/usr/include/bits/types.h" 3 4
typedef struct
{
  long __val[2];
} __quad_t;
typedef struct
{
  __u_long __val[2];
} __u_quad_t;
# 128 "/usr/include/bits/types.h" 3 4
# 1 "/usr/include/bits/typesizes.h" 1 3 4
# 129 "/usr/include/bits/types.h" 2 3 4


typedef unsigned long long int __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;
typedef unsigned long long int __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned int __nlink_t;
typedef long int __off_t;
typedef long long int __off64_t;
typedef int __pid_t;
typedef struct { int __val[2]; } __fsid_t;
typedef long int __clock_t;
typedef unsigned long int __rlim_t;
typedef unsigned long long int __rlim64_t;
typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;

typedef int __daddr_t;
typedef long int __swblk_t;
typedef int __key_t;


typedef int __clockid_t;


typedef int __timer_t;


typedef long int __blksize_t;




typedef long int __blkcnt_t;
typedef long long int __blkcnt64_t;


typedef unsigned long int __fsblkcnt_t;
typedef unsigned long long int __fsblkcnt64_t;


typedef unsigned long int __fsfilcnt_t;
typedef unsigned long long int __fsfilcnt64_t;




typedef int __ssize_t;
typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;


typedef int __intptr_t;


typedef unsigned int __socklen_t;
# 32 "/usr/include/sys/types.h" 2 3 4



typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;




typedef __loff_t loff_t;



typedef __ino_t ino_t;






typedef __ino64_t ino64_t;




typedef __dev_t dev_t;




typedef __gid_t gid_t;




typedef __mode_t mode_t;




typedef __nlink_t nlink_t;




typedef __uid_t uid_t;





typedef __off_t off_t;






typedef __off64_t off64_t;




typedef __pid_t pid_t;




typedef __id_t id_t;




typedef __ssize_t ssize_t;





typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;





typedef __key_t key_t;
# 133 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/time.h" 1 3 4
# 58 "/usr/include/time.h" 3 4


typedef __clock_t clock_t;



# 74 "/usr/include/time.h" 3 4


typedef __time_t time_t;



# 92 "/usr/include/time.h" 3 4
typedef __clockid_t clockid_t;
# 104 "/usr/include/time.h" 3 4
typedef __timer_t timer_t;
# 134 "/usr/include/sys/types.h" 2 3 4



typedef __useconds_t useconds_t;



typedef __suseconds_t suseconds_t;





# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 1 3 4
# 148 "/usr/include/sys/types.h" 2 3 4



typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;
# 163 "/usr/include/sys/types.h" 3 4
typedef char int8_t;
typedef short int int16_t;
typedef int int32_t;






typedef unsigned char u_int8_t;
typedef unsigned short int u_int16_t;
typedef unsigned int u_int32_t;




typedef int register_t;
# 216 "/usr/include/sys/types.h" 3 4
# 1 "/usr/include/sys/select.h" 1 3 4
# 31 "/usr/include/sys/select.h" 3 4
# 1 "/usr/include/bits/select.h" 1 3 4
# 32 "/usr/include/sys/select.h" 2 3 4


# 1 "/usr/include/bits/sigset.h" 1 3 4
# 23 "/usr/include/bits/sigset.h" 3 4
typedef int __sig_atomic_t;




typedef struct
  {
    unsigned long int __val[(1024 / (8 * sizeof (unsigned long int)))];
  } __sigset_t;
# 35 "/usr/include/sys/select.h" 2 3 4



typedef __sigset_t sigset_t;





# 1 "/usr/include/time.h" 1 3 4
# 118 "/usr/include/time.h" 3 4
struct timespec
  {
    __time_t tv_sec;
    long int tv_nsec;
  };
# 45 "/usr/include/sys/select.h" 2 3 4

# 1 "/usr/include/bits/time.h" 1 3 4
# 69 "/usr/include/bits/time.h" 3 4
struct timeval
  {
    __time_t tv_sec;
    __suseconds_t tv_usec;
  };
# 47 "/usr/include/sys/select.h" 2 3 4
# 55 "/usr/include/sys/select.h" 3 4
typedef long int __fd_mask;
# 67 "/usr/include/sys/select.h" 3 4
typedef struct
  {



    __fd_mask fds_bits[1024 / (8 * sizeof (__fd_mask))];





  } fd_set;






typedef __fd_mask fd_mask;
# 99 "/usr/include/sys/select.h" 3 4

# 109 "/usr/include/sys/select.h" 3 4
extern int select (int __nfds, fd_set * __readfds,
                   fd_set * __writefds,
                   fd_set * __exceptfds,
                   struct timeval * __timeout);
# 121 "/usr/include/sys/select.h" 3 4
extern int pselect (int __nfds, fd_set * __readfds,
                    fd_set * __writefds,
                    fd_set * __exceptfds,
                    const struct timespec * __timeout,
                    const __sigset_t * __sigmask);



# 217 "/usr/include/sys/types.h" 2 3 4


# 1 "/usr/include/sys/sysmacros.h" 1 3 4
# 220 "/usr/include/sys/types.h" 2 3 4




typedef __blksize_t blksize_t;






typedef __blkcnt_t blkcnt_t;



typedef __fsblkcnt_t fsblkcnt_t;



typedef __fsfilcnt_t fsfilcnt_t;
# 258 "/usr/include/sys/types.h" 3 4
typedef __blkcnt64_t blkcnt64_t;
typedef __fsblkcnt64_t fsblkcnt64_t;
typedef __fsfilcnt64_t fsfilcnt64_t;





# 1 "/usr/include/bits/pthreadtypes.h" 1 3 4
# 23 "/usr/include/bits/pthreadtypes.h" 3 4
# 1 "/usr/include/bits/sched.h" 1 3 4
# 82 "/usr/include/bits/sched.h" 3 4
struct __sched_param
  {
    int __sched_priority;
  };
# 24 "/usr/include/bits/pthreadtypes.h" 2 3 4

typedef int __atomic_lock_t;


struct _pthread_fastlock
{
  long int __status;
  __atomic_lock_t __spinlock;

};



typedef struct _pthread_descr_struct *_pthread_descr;





typedef struct __pthread_attr_s
{
  int __detachstate;
  int __schedpolicy;
  struct __sched_param __schedparam;
  int __inheritsched;
  int __scope;
  size_t __guardsize;
  int __stackaddr_set;
  void *__stackaddr;
  size_t __stacksize;
} pthread_attr_t;







typedef long __pthread_cond_align_t;


typedef struct
{
  struct _pthread_fastlock __c_lock;
  _pthread_descr __c_waiting;
  char __padding[48 - sizeof (struct _pthread_fastlock)
                 - sizeof (_pthread_descr) - sizeof (__pthread_cond_align_t)];
  __pthread_cond_align_t __align;
} pthread_cond_t;



typedef struct
{
  int __dummy;
} pthread_condattr_t;


typedef unsigned int pthread_key_t;





typedef struct
{
  int __m_reserved;
  int __m_count;
  _pthread_descr __m_owner;
  int __m_kind;
  struct _pthread_fastlock __m_lock;
} pthread_mutex_t;



typedef struct
{
  int __mutexkind;
} pthread_mutexattr_t;



typedef int pthread_once_t;




typedef struct _pthread_rwlock_t
{
  struct _pthread_fastlock __rw_lock;
  int __rw_readers;
  _pthread_descr __rw_writer;
  _pthread_descr __rw_read_waiting;
  _pthread_descr __rw_write_waiting;
  int __rw_kind;
  int __rw_pshared;
} pthread_rwlock_t;



typedef struct
{
  int __lockkind;
  int __pshared;
} pthread_rwlockattr_t;




typedef volatile int pthread_spinlock_t;


typedef struct {
  struct _pthread_fastlock __ba_lock;
  int __ba_required;
  int __ba_present;
  _pthread_descr __ba_waiting;
} pthread_barrier_t;


typedef struct {
  int __pshared;
} pthread_barrierattr_t;





typedef unsigned long int pthread_t;
# 267 "/usr/include/sys/types.h" 2 3 4



# 417 "/usr/include/stdlib.h" 2 3 4






extern long int random (void) ;


extern void srandom (unsigned int __seed) ;





extern char *initstate (unsigned int __seed, char *__statebuf,
                        size_t __statelen) ;



extern char *setstate (char *__statebuf) ;







struct random_data
  {
    int32_t *fptr;
    int32_t *rptr;
    int32_t *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int32_t *end_ptr;
  };

extern int random_r (struct random_data * __buf,
                     int32_t * __result) ;

extern int srandom_r (unsigned int __seed, struct random_data *__buf) ;

extern int initstate_r (unsigned int __seed, char * __statebuf,
                        size_t __statelen,
                        struct random_data * __buf) ;

extern int setstate_r (char * __statebuf,
                       struct random_data * __buf) ;






extern int rand (void) ;

extern void srand (unsigned int __seed) ;




extern int rand_r (unsigned int *__seed) ;







extern double drand48 (void) ;
extern double erand48 (unsigned short int __xsubi[3]) ;


extern long int lrand48 (void) ;
extern long int nrand48 (unsigned short int __xsubi[3]) ;


extern long int mrand48 (void) ;
extern long int jrand48 (unsigned short int __xsubi[3]) ;


extern void srand48 (long int __seedval) ;
extern unsigned short int *seed48 (unsigned short int __seed16v[3]) ;
extern void lcong48 (unsigned short int __param[7]) ;





struct drand48_data
  {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    unsigned long long int __a;
  };


extern int drand48_r (struct drand48_data * __buffer,
                      double * __result) ;
extern int erand48_r (unsigned short int __xsubi[3],
                      struct drand48_data * __buffer,
                      double * __result) ;


extern int lrand48_r (struct drand48_data * __buffer,
                      long int * __result) ;
extern int nrand48_r (unsigned short int __xsubi[3],
                      struct drand48_data * __buffer,
                      long int * __result) ;


extern int mrand48_r (struct drand48_data * __buffer,
                      long int * __result) ;
extern int jrand48_r (unsigned short int __xsubi[3],
                      struct drand48_data * __buffer,
                      long int * __result) ;


extern int srand48_r (long int __seedval, struct drand48_data *__buffer)
     ;

extern int seed48_r (unsigned short int __seed16v[3],
                     struct drand48_data *__buffer) ;

extern int lcong48_r (unsigned short int __param[7],
                      struct drand48_data *__buffer) ;









extern void *malloc (size_t __size) ;

extern void *calloc (size_t __nmemb, size_t __size)
     ;







extern void *realloc (void *__ptr, size_t __size) ;

extern void free (void *__ptr) ;




extern void cfree (void *__ptr) ;



# 1 "/usr/include/alloca.h" 1 3 4
# 25 "/usr/include/alloca.h" 3 4
# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 1 3 4
# 26 "/usr/include/alloca.h" 2 3 4







extern void *alloca (size_t __size) ;






# 579 "/usr/include/stdlib.h" 2 3 4




extern void *valloc (size_t __size) ;




extern int posix_memalign (void **__memptr, size_t __alignment, size_t __size)
     ;




extern void abort (void) ;



extern int atexit (void (*__func) (void)) ;





extern int on_exit (void (*__func) (int __status, void *__arg), void *__arg)
     ;






extern void exit (int __status) ;






extern void _Exit (int __status) ;






extern char *getenv (const char *__name) ;




extern char *__secure_getenv (const char *__name) ;





extern int putenv (char *__string) ;





extern int setenv (const char *__name, const char *__value, int __replace)
     ;


extern int unsetenv (const char *__name) ;






extern int clearenv (void) ;
# 663 "/usr/include/stdlib.h" 3 4
extern char *mktemp (char *__template) ;
# 674 "/usr/include/stdlib.h" 3 4
extern int mkstemp (char *__template);
# 683 "/usr/include/stdlib.h" 3 4
extern int mkstemp64 (char *__template);
# 693 "/usr/include/stdlib.h" 3 4
extern char *mkdtemp (char *__template) ;








extern int system (const char *__command);







extern char *canonicalize_file_name (const char *__name) ;
# 720 "/usr/include/stdlib.h" 3 4
extern char *realpath (const char * __name,
                       char * __resolved) ;






typedef int (*__compar_fn_t) (const void *, const void *);


typedef __compar_fn_t comparison_fn_t;






extern void *bsearch (const void *__key, const void *__base,
                      size_t __nmemb, size_t __size, __compar_fn_t __compar);



extern void qsort (void *__base, size_t __nmemb, size_t __size,
                   __compar_fn_t __compar);



extern int abs (int __x) ;
extern long int labs (long int __x) ;



 extern long long int llabs (long long int __x)
     ;







extern div_t div (int __numer, int __denom)
     ;
extern ldiv_t ldiv (long int __numer, long int __denom)
     ;




 extern lldiv_t lldiv (long long int __numer,
                                    long long int __denom)
     ;

# 784 "/usr/include/stdlib.h" 3 4
extern char *ecvt (double __value, int __ndigit, int * __decpt,
                   int * __sign) ;




extern char *fcvt (double __value, int __ndigit, int * __decpt,
                   int * __sign) ;




extern char *gcvt (double __value, int __ndigit, char *__buf) ;




extern char *qecvt (long double __value, int __ndigit,
                    int * __decpt, int * __sign) ;
extern char *qfcvt (long double __value, int __ndigit,
                    int * __decpt, int * __sign) ;
extern char *qgcvt (long double __value, int __ndigit, char *__buf) ;




extern int ecvt_r (double __value, int __ndigit, int * __decpt,
                   int * __sign, char * __buf,
                   size_t __len) ;
extern int fcvt_r (double __value, int __ndigit, int * __decpt,
                   int * __sign, char * __buf,
                   size_t __len) ;

extern int qecvt_r (long double __value, int __ndigit,
                    int * __decpt, int * __sign,
                    char * __buf, size_t __len) ;
extern int qfcvt_r (long double __value, int __ndigit,
                    int * __decpt, int * __sign,
                    char * __buf, size_t __len) ;







extern int mblen (const char *__s, size_t __n) ;


extern int mbtowc (wchar_t * __pwc,
                   const char * __s, size_t __n) ;


extern int wctomb (char *__s, wchar_t __wchar) ;



extern size_t mbstowcs (wchar_t * __pwcs,
                        const char * __s, size_t __n) ;

extern size_t wcstombs (char * __s,
                        const wchar_t * __pwcs, size_t __n)
     ;








extern int rpmatch (const char *__response) ;
# 866 "/usr/include/stdlib.h" 3 4
extern int getsubopt (char ** __optionp,
                      char *const * __tokens,
                      char ** __valuep) ;





extern void setkey (const char *__key) ;







extern int posix_openpt (int __oflag) ;







extern int grantpt (int __fd) ;



extern int unlockpt (int __fd) ;




extern char *ptsname (int __fd) ;






extern int ptsname_r (int __fd, char *__buf, size_t __buflen) ;


extern int getpt (void) ;






extern int getloadavg (double __loadavg[], int __nelem) ;






# 53 "/usr/include/c++/3.3/cstdlib" 2 3
# 84 "/usr/include/c++/3.3/cstdlib" 3
namespace std
{
  using ::div_t;
  using ::ldiv_t;

  using ::abort;
  using ::abs;
  using ::atexit;
  using ::atof;
  using ::atoi;
  using ::atol;
  using ::bsearch;
  using ::calloc;
  using ::div;
  using ::exit;
  using ::free;
  using ::getenv;
  using ::labs;
  using ::ldiv;
  using ::malloc;
  using ::mblen;
  using ::mbstowcs;
  using ::mbtowc;
  using ::qsort;
  using ::rand;
  using ::realloc;
  using ::srand;
  using ::strtod;
  using ::strtol;
  using ::strtoul;
  using ::system;
  using ::wcstombs;
  using ::wctomb;

  inline long
  abs(long __i) { return labs(__i); }

  inline ldiv_t
  div(long __i, long __j) { return ldiv(__i, __j); }
}
# 136 "/usr/include/c++/3.3/cstdlib" 3
namespace __gnu_cxx
{

  using ::lldiv_t;





  using ::_Exit;


  inline long long
  abs(long long __x) { return __x >= 0 ? __x : -__x; }

  inline long long
  llabs(long long __x) { return __x >= 0 ? __x : -__x; }


  inline lldiv_t
  div(long long __n, long long __d)
  { lldiv_t __q; __q.quot = __n / __d; __q.rem = __n % __d; return __q; }

  inline lldiv_t
  lldiv(long long __n, long long __d)
  { lldiv_t __q; __q.quot = __n / __d; __q.rem = __n % __d; return __q; }
# 172 "/usr/include/c++/3.3/cstdlib" 3
  using ::atoll;
  using ::strtoll;
  using ::strtoull;

  using ::strtof;
  using ::strtold;
}

namespace std
{

  using __gnu_cxx::lldiv_t;

  using __gnu_cxx::_Exit;
  using __gnu_cxx::abs;
  using __gnu_cxx::llabs;

  using __gnu_cxx::div;
  using __gnu_cxx::lldiv;

  using __gnu_cxx::atoll;
  using __gnu_cxx::strtof;
  using __gnu_cxx::strtoll;
  using __gnu_cxx::strtoull;
  using __gnu_cxx::strtold;
}
# 68 "/usr/include/c++/3.3/bits/stl_algobase.h" 2 3

# 1 "/usr/include/c++/3.3/new" 1 3
# 42 "/usr/include/c++/3.3/new" 3
# 1 "/usr/include/c++/3.3/exception" 1 3
# 40 "/usr/include/c++/3.3/exception" 3
extern "C++" {

namespace std
{
# 52 "/usr/include/c++/3.3/exception" 3
  class exception
  {
  public:
    exception() throw() { }
    virtual ~exception() throw();


    virtual const char* what() const throw();
  };



  class bad_exception : public exception
  {
  public:
    bad_exception() throw() { }


    virtual ~bad_exception() throw();
  };


  typedef void (*terminate_handler) ();

  typedef void (*unexpected_handler) ();


  terminate_handler set_terminate(terminate_handler) throw();


  void terminate() ;


  unexpected_handler set_unexpected(unexpected_handler) throw();


  void unexpected() ;
# 100 "/usr/include/c++/3.3/exception" 3
  bool uncaught_exception() throw();
}

namespace __gnu_cxx
{
# 113 "/usr/include/c++/3.3/exception" 3
  void __verbose_terminate_handler ();
}

}
# 43 "/usr/include/c++/3.3/new" 2 3

extern "C++" {

namespace std
{





  class bad_alloc : public exception
  {
  public:
    bad_alloc() throw() { }


    virtual ~bad_alloc() throw();
  };

  struct nothrow_t { };
  extern const nothrow_t nothrow;


  typedef void (*new_handler)();

  new_handler set_new_handler(new_handler) throw();
}
# 82 "/usr/include/c++/3.3/new" 3
void* operator new(std::size_t) throw (std::bad_alloc);
void* operator new[](std::size_t) throw (std::bad_alloc);
void operator delete(void*) throw();
void operator delete[](void*) throw();
void* operator new(std::size_t, const std::nothrow_t&) throw();
void* operator new[](std::size_t, const std::nothrow_t&) throw();
void operator delete(void*, const std::nothrow_t&) throw();
void operator delete[](void*, const std::nothrow_t&) throw();


inline void* operator new(std::size_t, void* __p) throw() { return __p; }
inline void* operator new[](std::size_t, void* __p) throw() { return __p; }


inline void operator delete (void*, void*) throw() { };
inline void operator delete[](void*, void*) throw() { };

}
# 70 "/usr/include/c++/3.3/bits/stl_algobase.h" 2 3
# 1 "/usr/include/c++/3.3/iosfwd" 1 3
# 43 "/usr/include/c++/3.3/iosfwd" 3
       
# 44 "/usr/include/c++/3.3/iosfwd" 3


# 1 "/usr/include/c++/3.3/i486-linux/bits/c++locale.h" 1 3
# 39 "/usr/include/c++/3.3/i486-linux/bits/c++locale.h" 3
       
# 40 "/usr/include/c++/3.3/i486-linux/bits/c++locale.h" 3

# 1 "/usr/include/c++/3.3/clocale" 1 3
# 47 "/usr/include/c++/3.3/clocale" 3
       
# 48 "/usr/include/c++/3.3/clocale" 3

# 1 "/usr/include/locale.h" 1 3 4
# 29 "/usr/include/locale.h" 3 4
# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 1 3 4
# 30 "/usr/include/locale.h" 2 3 4
# 1 "/usr/include/bits/locale.h" 1 3 4
# 27 "/usr/include/bits/locale.h" 3 4
enum
{
  __LC_CTYPE = 0,
  __LC_NUMERIC = 1,
  __LC_TIME = 2,
  __LC_COLLATE = 3,
  __LC_MONETARY = 4,
  __LC_MESSAGES = 5,
  __LC_ALL = 6,
  __LC_PAPER = 7,
  __LC_NAME = 8,
  __LC_ADDRESS = 9,
  __LC_TELEPHONE = 10,
  __LC_MEASUREMENT = 11,
  __LC_IDENTIFICATION = 12
};
# 31 "/usr/include/locale.h" 2 3 4


# 52 "/usr/include/locale.h" 3 4
struct lconv
{


  char *decimal_point;
  char *thousands_sep;





  char *grouping;





  char *int_curr_symbol;
  char *currency_symbol;
  char *mon_decimal_point;
  char *mon_thousands_sep;
  char *mon_grouping;
  char *positive_sign;
  char *negative_sign;
  char int_frac_digits;
  char frac_digits;

  char p_cs_precedes;

  char p_sep_by_space;

  char n_cs_precedes;

  char n_sep_by_space;






  char p_sign_posn;
  char n_sign_posn;


  char int_p_cs_precedes;

  char int_p_sep_by_space;

  char int_n_cs_precedes;

  char int_n_sep_by_space;






  char int_p_sign_posn;
  char int_n_sign_posn;
# 119 "/usr/include/locale.h" 3 4
};





extern char *setlocale (int __category, const char *__locale) ;


extern struct lconv *localeconv (void) ;


# 148 "/usr/include/locale.h" 3 4
typedef __locale_t locale_t;





extern __locale_t newlocale (int __category_mask, const char *__locale,
                             __locale_t __base) ;
# 189 "/usr/include/locale.h" 3 4
extern __locale_t duplocale (__locale_t __dataset) ;



extern void freelocale (__locale_t __dataset) ;






extern __locale_t uselocale (__locale_t __dataset) ;








# 50 "/usr/include/c++/3.3/clocale" 2 3





namespace std
{
  using ::lconv;
  using ::setlocale;
  using ::localeconv;
}
# 42 "/usr/include/c++/3.3/i486-linux/bits/c++locale.h" 2 3
# 1 "/usr/include/langinfo.h" 1 3 4
# 24 "/usr/include/langinfo.h" 3 4
# 1 "/usr/include/nl_types.h" 1 3 4
# 31 "/usr/include/nl_types.h" 3 4



typedef void *nl_catd;


typedef int nl_item;





extern nl_catd catopen (const char *__cat_name, int __flag);



extern char *catgets (nl_catd __catalog, int __set, int __number,
                      const char *__string) ;


extern int catclose (nl_catd __catalog) ;


# 25 "/usr/include/langinfo.h" 2 3 4

# 1 "/usr/include/bits/locale.h" 1 3 4
# 27 "/usr/include/langinfo.h" 2 3 4



# 43 "/usr/include/langinfo.h" 3 4
enum
{



  ABDAY_1 = (((__LC_TIME) << 16) | (0)),

  ABDAY_2,

  ABDAY_3,

  ABDAY_4,

  ABDAY_5,

  ABDAY_6,

  ABDAY_7,



  DAY_1,

  DAY_2,

  DAY_3,

  DAY_4,

  DAY_5,

  DAY_6,

  DAY_7,



  ABMON_1,

  ABMON_2,

  ABMON_3,

  ABMON_4,

  ABMON_5,

  ABMON_6,

  ABMON_7,

  ABMON_8,

  ABMON_9,

  ABMON_10,

  ABMON_11,

  ABMON_12,



  MON_1,

  MON_2,

  MON_3,

  MON_4,

  MON_5,

  MON_6,

  MON_7,

  MON_8,

  MON_9,

  MON_10,

  MON_11,

  MON_12,


  AM_STR,

  PM_STR,


  D_T_FMT,

  D_FMT,

  T_FMT,

  T_FMT_AMPM,


  ERA,

  __ERA_YEAR,



  ERA_D_FMT,

  ALT_DIGITS,

  ERA_D_T_FMT,

  ERA_T_FMT,


  _NL_TIME_ERA_NUM_ENTRIES,
  _NL_TIME_ERA_ENTRIES,

  _NL_WABDAY_1,
  _NL_WABDAY_2,
  _NL_WABDAY_3,
  _NL_WABDAY_4,
  _NL_WABDAY_5,
  _NL_WABDAY_6,
  _NL_WABDAY_7,


  _NL_WDAY_1,
  _NL_WDAY_2,
  _NL_WDAY_3,
  _NL_WDAY_4,
  _NL_WDAY_5,
  _NL_WDAY_6,
  _NL_WDAY_7,


  _NL_WABMON_1,
  _NL_WABMON_2,
  _NL_WABMON_3,
  _NL_WABMON_4,
  _NL_WABMON_5,
  _NL_WABMON_6,
  _NL_WABMON_7,
  _NL_WABMON_8,
  _NL_WABMON_9,
  _NL_WABMON_10,
  _NL_WABMON_11,
  _NL_WABMON_12,


  _NL_WMON_1,
  _NL_WMON_2,
  _NL_WMON_3,
  _NL_WMON_4,
  _NL_WMON_5,
  _NL_WMON_6,
  _NL_WMON_7,
  _NL_WMON_8,
  _NL_WMON_9,
  _NL_WMON_10,
  _NL_WMON_11,
  _NL_WMON_12,

  _NL_WAM_STR,
  _NL_WPM_STR,

  _NL_WD_T_FMT,
  _NL_WD_FMT,
  _NL_WT_FMT,
  _NL_WT_FMT_AMPM,

  _NL_WERA_YEAR,
  _NL_WERA_D_FMT,
  _NL_WALT_DIGITS,
  _NL_WERA_D_T_FMT,
  _NL_WERA_T_FMT,

  _NL_TIME_WEEK_NDAYS,
  _NL_TIME_WEEK_1STDAY,
  _NL_TIME_WEEK_1STWEEK,
  _NL_TIME_FIRST_WEEKDAY,
  _NL_TIME_FIRST_WORKDAY,
  _NL_TIME_CAL_DIRECTION,
  _NL_TIME_TIMEZONE,

  _DATE_FMT,

  _NL_W_DATE_FMT,

  _NL_TIME_CODESET,

  _NL_NUM_LC_TIME,




  _NL_COLLATE_NRULES = (((__LC_COLLATE) << 16) | (0)),
  _NL_COLLATE_RULESETS,
  _NL_COLLATE_TABLEMB,
  _NL_COLLATE_WEIGHTMB,
  _NL_COLLATE_EXTRAMB,
  _NL_COLLATE_INDIRECTMB,
  _NL_COLLATE_GAP1,
  _NL_COLLATE_GAP2,
  _NL_COLLATE_GAP3,
  _NL_COLLATE_TABLEWC,
  _NL_COLLATE_WEIGHTWC,
  _NL_COLLATE_EXTRAWC,
  _NL_COLLATE_INDIRECTWC,
  _NL_COLLATE_SYMB_HASH_SIZEMB,
  _NL_COLLATE_SYMB_TABLEMB,
  _NL_COLLATE_SYMB_EXTRAMB,
  _NL_COLLATE_COLLSEQMB,
  _NL_COLLATE_COLLSEQWC,
  _NL_COLLATE_CODESET,
  _NL_NUM_LC_COLLATE,




  _NL_CTYPE_CLASS = (((__LC_CTYPE) << 16) | (0)),
  _NL_CTYPE_TOUPPER,
  _NL_CTYPE_GAP1,
  _NL_CTYPE_TOLOWER,
  _NL_CTYPE_GAP2,
  _NL_CTYPE_CLASS32,
  _NL_CTYPE_GAP3,
  _NL_CTYPE_GAP4,
  _NL_CTYPE_GAP5,
  _NL_CTYPE_GAP6,
  _NL_CTYPE_CLASS_NAMES,
  _NL_CTYPE_MAP_NAMES,
  _NL_CTYPE_WIDTH,
  _NL_CTYPE_MB_CUR_MAX,
  _NL_CTYPE_CODESET_NAME,
  CODESET = _NL_CTYPE_CODESET_NAME,

  _NL_CTYPE_TOUPPER32,
  _NL_CTYPE_TOLOWER32,
  _NL_CTYPE_CLASS_OFFSET,
  _NL_CTYPE_MAP_OFFSET,
  _NL_CTYPE_INDIGITS_MB_LEN,
  _NL_CTYPE_INDIGITS0_MB,
  _NL_CTYPE_INDIGITS1_MB,
  _NL_CTYPE_INDIGITS2_MB,
  _NL_CTYPE_INDIGITS3_MB,
  _NL_CTYPE_INDIGITS4_MB,
  _NL_CTYPE_INDIGITS5_MB,
  _NL_CTYPE_INDIGITS6_MB,
  _NL_CTYPE_INDIGITS7_MB,
  _NL_CTYPE_INDIGITS8_MB,
  _NL_CTYPE_INDIGITS9_MB,
  _NL_CTYPE_INDIGITS_WC_LEN,
  _NL_CTYPE_INDIGITS0_WC,
  _NL_CTYPE_INDIGITS1_WC,
  _NL_CTYPE_INDIGITS2_WC,
  _NL_CTYPE_INDIGITS3_WC,
  _NL_CTYPE_INDIGITS4_WC,
  _NL_CTYPE_INDIGITS5_WC,
  _NL_CTYPE_INDIGITS6_WC,
  _NL_CTYPE_INDIGITS7_WC,
  _NL_CTYPE_INDIGITS8_WC,
  _NL_CTYPE_INDIGITS9_WC,
  _NL_CTYPE_OUTDIGIT0_MB,
  _NL_CTYPE_OUTDIGIT1_MB,
  _NL_CTYPE_OUTDIGIT2_MB,
  _NL_CTYPE_OUTDIGIT3_MB,
  _NL_CTYPE_OUTDIGIT4_MB,
  _NL_CTYPE_OUTDIGIT5_MB,
  _NL_CTYPE_OUTDIGIT6_MB,
  _NL_CTYPE_OUTDIGIT7_MB,
  _NL_CTYPE_OUTDIGIT8_MB,
  _NL_CTYPE_OUTDIGIT9_MB,
  _NL_CTYPE_OUTDIGIT0_WC,
  _NL_CTYPE_OUTDIGIT1_WC,
  _NL_CTYPE_OUTDIGIT2_WC,
  _NL_CTYPE_OUTDIGIT3_WC,
  _NL_CTYPE_OUTDIGIT4_WC,
  _NL_CTYPE_OUTDIGIT5_WC,
  _NL_CTYPE_OUTDIGIT6_WC,
  _NL_CTYPE_OUTDIGIT7_WC,
  _NL_CTYPE_OUTDIGIT8_WC,
  _NL_CTYPE_OUTDIGIT9_WC,
  _NL_CTYPE_TRANSLIT_TAB_SIZE,
  _NL_CTYPE_TRANSLIT_FROM_IDX,
  _NL_CTYPE_TRANSLIT_FROM_TBL,
  _NL_CTYPE_TRANSLIT_TO_IDX,
  _NL_CTYPE_TRANSLIT_TO_TBL,
  _NL_CTYPE_TRANSLIT_DEFAULT_MISSING_LEN,
  _NL_CTYPE_TRANSLIT_DEFAULT_MISSING,
  _NL_CTYPE_TRANSLIT_IGNORE_LEN,
  _NL_CTYPE_TRANSLIT_IGNORE,
  _NL_CTYPE_EXTRA_MAP_1,
  _NL_CTYPE_EXTRA_MAP_2,
  _NL_CTYPE_EXTRA_MAP_3,
  _NL_CTYPE_EXTRA_MAP_4,
  _NL_CTYPE_EXTRA_MAP_5,
  _NL_CTYPE_EXTRA_MAP_6,
  _NL_CTYPE_EXTRA_MAP_7,
  _NL_CTYPE_EXTRA_MAP_8,
  _NL_CTYPE_EXTRA_MAP_9,
  _NL_CTYPE_EXTRA_MAP_10,
  _NL_CTYPE_EXTRA_MAP_11,
  _NL_CTYPE_EXTRA_MAP_12,
  _NL_CTYPE_EXTRA_MAP_13,
  _NL_CTYPE_EXTRA_MAP_14,
  _NL_NUM_LC_CTYPE,




  __INT_CURR_SYMBOL = (((__LC_MONETARY) << 16) | (0)),



  __CURRENCY_SYMBOL,



  __MON_DECIMAL_POINT,



  __MON_THOUSANDS_SEP,



  __MON_GROUPING,



  __POSITIVE_SIGN,



  __NEGATIVE_SIGN,



  __INT_FRAC_DIGITS,



  __FRAC_DIGITS,



  __P_CS_PRECEDES,



  __P_SEP_BY_SPACE,



  __N_CS_PRECEDES,



  __N_SEP_BY_SPACE,



  __P_SIGN_POSN,



  __N_SIGN_POSN,



  _NL_MONETARY_CRNCYSTR,

  __INT_P_CS_PRECEDES,



  __INT_P_SEP_BY_SPACE,



  __INT_N_CS_PRECEDES,



  __INT_N_SEP_BY_SPACE,



  __INT_P_SIGN_POSN,



  __INT_N_SIGN_POSN,



  _NL_MONETARY_DUO_INT_CURR_SYMBOL,
  _NL_MONETARY_DUO_CURRENCY_SYMBOL,
  _NL_MONETARY_DUO_INT_FRAC_DIGITS,
  _NL_MONETARY_DUO_FRAC_DIGITS,
  _NL_MONETARY_DUO_P_CS_PRECEDES,
  _NL_MONETARY_DUO_P_SEP_BY_SPACE,
  _NL_MONETARY_DUO_N_CS_PRECEDES,
  _NL_MONETARY_DUO_N_SEP_BY_SPACE,
  _NL_MONETARY_DUO_INT_P_CS_PRECEDES,
  _NL_MONETARY_DUO_INT_P_SEP_BY_SPACE,
  _NL_MONETARY_DUO_INT_N_CS_PRECEDES,
  _NL_MONETARY_DUO_INT_N_SEP_BY_SPACE,
  _NL_MONETARY_DUO_P_SIGN_POSN,
  _NL_MONETARY_DUO_N_SIGN_POSN,
  _NL_MONETARY_DUO_INT_P_SIGN_POSN,
  _NL_MONETARY_DUO_INT_N_SIGN_POSN,
  _NL_MONETARY_UNO_VALID_FROM,
  _NL_MONETARY_UNO_VALID_TO,
  _NL_MONETARY_DUO_VALID_FROM,
  _NL_MONETARY_DUO_VALID_TO,
  _NL_MONETARY_CONVERSION_RATE,
  _NL_MONETARY_DECIMAL_POINT_WC,
  _NL_MONETARY_THOUSANDS_SEP_WC,
  _NL_MONETARY_CODESET,
  _NL_NUM_LC_MONETARY,



  __DECIMAL_POINT = (((__LC_NUMERIC) << 16) | (0)),



  RADIXCHAR = __DECIMAL_POINT,

  __THOUSANDS_SEP,



  THOUSEP = __THOUSANDS_SEP,

  __GROUPING,



  _NL_NUMERIC_DECIMAL_POINT_WC,
  _NL_NUMERIC_THOUSANDS_SEP_WC,
  _NL_NUMERIC_CODESET,
  _NL_NUM_LC_NUMERIC,

  __YESEXPR = (((__LC_MESSAGES) << 16) | (0)),

  __NOEXPR,

  __YESSTR,



  __NOSTR,



  _NL_MESSAGES_CODESET,
  _NL_NUM_LC_MESSAGES,

  _NL_PAPER_HEIGHT = (((__LC_PAPER) << 16) | (0)),
  _NL_PAPER_WIDTH,
  _NL_PAPER_CODESET,
  _NL_NUM_LC_PAPER,

  _NL_NAME_NAME_FMT = (((__LC_NAME) << 16) | (0)),
  _NL_NAME_NAME_GEN,
  _NL_NAME_NAME_MR,
  _NL_NAME_NAME_MRS,
  _NL_NAME_NAME_MISS,
  _NL_NAME_NAME_MS,
  _NL_NAME_CODESET,
  _NL_NUM_LC_NAME,

  _NL_ADDRESS_POSTAL_FMT = (((__LC_ADDRESS) << 16) | (0)),
  _NL_ADDRESS_COUNTRY_NAME,
  _NL_ADDRESS_COUNTRY_POST,
  _NL_ADDRESS_COUNTRY_AB2,
  _NL_ADDRESS_COUNTRY_AB3,
  _NL_ADDRESS_COUNTRY_CAR,
  _NL_ADDRESS_COUNTRY_NUM,
  _NL_ADDRESS_COUNTRY_ISBN,
  _NL_ADDRESS_LANG_NAME,
  _NL_ADDRESS_LANG_AB,
  _NL_ADDRESS_LANG_TERM,
  _NL_ADDRESS_LANG_LIB,
  _NL_ADDRESS_CODESET,
  _NL_NUM_LC_ADDRESS,

  _NL_TELEPHONE_TEL_INT_FMT = (((__LC_TELEPHONE) << 16) | (0)),
  _NL_TELEPHONE_TEL_DOM_FMT,
  _NL_TELEPHONE_INT_SELECT,
  _NL_TELEPHONE_INT_PREFIX,
  _NL_TELEPHONE_CODESET,
  _NL_NUM_LC_TELEPHONE,

  _NL_MEASUREMENT_MEASUREMENT = (((__LC_MEASUREMENT) << 16) | (0)),
  _NL_MEASUREMENT_CODESET,
  _NL_NUM_LC_MEASUREMENT,

  _NL_IDENTIFICATION_TITLE = (((__LC_IDENTIFICATION) << 16) | (0)),
  _NL_IDENTIFICATION_SOURCE,
  _NL_IDENTIFICATION_ADDRESS,
  _NL_IDENTIFICATION_CONTACT,
  _NL_IDENTIFICATION_EMAIL,
  _NL_IDENTIFICATION_TEL,
  _NL_IDENTIFICATION_FAX,
  _NL_IDENTIFICATION_LANGUAGE,
  _NL_IDENTIFICATION_TERRITORY,
  _NL_IDENTIFICATION_AUDIENCE,
  _NL_IDENTIFICATION_APPLICATION,
  _NL_IDENTIFICATION_ABBREVIATION,
  _NL_IDENTIFICATION_REVISION,
  _NL_IDENTIFICATION_DATE,
  _NL_IDENTIFICATION_CATEGORY,
  _NL_IDENTIFICATION_CODESET,
  _NL_NUM_LC_IDENTIFICATION,


  _NL_NUM
};
# 575 "/usr/include/langinfo.h" 3 4
extern char *nl_langinfo (nl_item __item) ;
# 586 "/usr/include/langinfo.h" 3 4
extern char *nl_langinfo_l (nl_item __item, __locale_t l);



# 43 "/usr/include/c++/3.3/i486-linux/bits/c++locale.h" 2 3
# 1 "/usr/include/iconv.h" 1 3 4
# 24 "/usr/include/iconv.h" 3 4
# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 1 3 4
# 25 "/usr/include/iconv.h" 2 3 4





typedef void *iconv_t;







extern iconv_t iconv_open (const char *__tocode, const char *__fromcode);




extern size_t iconv (iconv_t __cd, char ** __inbuf,
                     size_t * __inbytesleft,
                     char ** __outbuf,
                     size_t * __outbytesleft);





extern int iconv_close (iconv_t __cd);


# 44 "/usr/include/c++/3.3/i486-linux/bits/c++locale.h" 2 3
# 1 "/usr/include/libintl.h" 1 3 4
# 35 "/usr/include/libintl.h" 3 4





extern char *gettext (const char *__msgid) ;



extern char *dgettext (const char *__domainname, const char *__msgid)
     ;
extern char *__dgettext (const char *__domainname, const char *__msgid)
     ;



extern char *dcgettext (const char *__domainname,
                        const char *__msgid, int __category) ;
extern char *__dcgettext (const char *__domainname,
                          const char *__msgid, int __category)
     ;




extern char *ngettext (const char *__msgid1, const char *__msgid2,
                       unsigned long int __n)
     ;



extern char *dngettext (const char *__domainname, const char *__msgid1,
                        const char *__msgid2, unsigned long int __n)
     ;



extern char *dcngettext (const char *__domainname, const char *__msgid1,
                         const char *__msgid2, unsigned long int __n,
                         int __category)
     ;





extern char *textdomain (const char *__domainname) ;



extern char *bindtextdomain (const char *__domainname,
                             const char *__dirname) ;



extern char *bind_textdomain_codeset (const char *__domainname,
                                      const char *__codeset) ;
# 120 "/usr/include/libintl.h" 3 4

# 45 "/usr/include/c++/3.3/i486-linux/bits/c++locale.h" 2 3






namespace __gnu_cxx
{
  extern "C" __typeof(uselocale) __uselocale;
}


namespace std
{
  typedef __locale_t __c_locale;





  template<typename _Tv>
    int
    __convert_from_v(char* __out, const int __size, const char* __fmt,

                     _Tv __v, const __c_locale& __cloc, int __prec = -1)
    {
      __c_locale __old = __gnu_cxx::__uselocale(__cloc);
# 82 "/usr/include/c++/3.3/i486-linux/bits/c++locale.h" 3
      int __ret;

      if (__prec >= 0)
        __ret = snprintf(__out, __size, __fmt, __prec, __v);
      else
        __ret = snprintf(__out, __size, __fmt, __v);
# 96 "/usr/include/c++/3.3/i486-linux/bits/c++locale.h" 3
      __gnu_cxx::__uselocale(__old);




      return __ret;
    }
}
# 47 "/usr/include/c++/3.3/iosfwd" 2 3
# 1 "/usr/include/c++/3.3/cctype" 1 3
# 46 "/usr/include/c++/3.3/cctype" 3
       
# 47 "/usr/include/c++/3.3/cctype" 3


# 1 "/usr/include/ctype.h" 1 3 4
# 30 "/usr/include/ctype.h" 3 4

# 48 "/usr/include/ctype.h" 3 4
enum
{
  _ISupper = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),
  _ISlower = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),
  _ISalpha = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),
  _ISdigit = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),
  _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),
  _ISspace = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),
  _ISprint = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),
  _ISgraph = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),
  _ISblank = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),
  _IScntrl = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),
  _ISpunct = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)),
  _ISalnum = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))
};
# 81 "/usr/include/ctype.h" 3 4
extern const unsigned short int **__ctype_b_loc (void)
     ;
extern const __int32_t **__ctype_tolower_loc (void)
     ;
extern const __int32_t **__ctype_toupper_loc (void)
     ;
# 96 "/usr/include/ctype.h" 3 4






extern int isalnum (int) ;
extern int isalpha (int) ;
extern int iscntrl (int) ;
extern int isdigit (int) ;
extern int islower (int) ;
extern int isgraph (int) ;
extern int isprint (int) ;
extern int ispunct (int) ;
extern int isspace (int) ;
extern int isupper (int) ;
extern int isxdigit (int) ;



extern int tolower (int __c) ;


extern int toupper (int __c) ;








extern int isblank (int) ;






extern int isctype (int __c, int __mask) ;






extern int isascii (int __c) ;



extern int toascii (int __c) ;



extern int _toupper (int) ;
extern int _tolower (int) ;
# 247 "/usr/include/ctype.h" 3 4
extern int isalnum_l (int, __locale_t) ;
extern int isalpha_l (int, __locale_t) ;
extern int iscntrl_l (int, __locale_t) ;
extern int isdigit_l (int, __locale_t) ;
extern int islower_l (int, __locale_t) ;
extern int isgraph_l (int, __locale_t) ;
extern int isprint_l (int, __locale_t) ;
extern int ispunct_l (int, __locale_t) ;
extern int isspace_l (int, __locale_t) ;
extern int isupper_l (int, __locale_t) ;
extern int isxdigit_l (int, __locale_t) ;

extern int isblank_l (int, __locale_t) ;



extern int __tolower_l (int __c, __locale_t __l) ;
extern int tolower_l (int __c, __locale_t __l) ;


extern int __toupper_l (int __c, __locale_t __l) ;
extern int toupper_l (int __c, __locale_t __l) ;
# 323 "/usr/include/ctype.h" 3 4

# 50 "/usr/include/c++/3.3/cctype" 2 3
# 66 "/usr/include/c++/3.3/cctype" 3
namespace std
{
  using ::isalnum;
  using ::isalpha;
  using ::iscntrl;
  using ::isdigit;
  using ::isgraph;
  using ::islower;
  using ::isprint;
  using ::ispunct;
  using ::isspace;
  using ::isupper;
  using ::isxdigit;
  using ::tolower;
  using ::toupper;
}
# 48 "/usr/include/c++/3.3/iosfwd" 2 3
# 1 "/usr/include/c++/3.3/bits/stringfwd.h" 1 3
# 42 "/usr/include/c++/3.3/bits/stringfwd.h" 3
       
# 43 "/usr/include/c++/3.3/bits/stringfwd.h" 3



namespace std
{
  template<typename _Alloc>
    class allocator;

  template<class _CharT>
    struct char_traits;

  template<typename _CharT, typename _Traits = char_traits<_CharT>,
           typename _Alloc = allocator<_CharT> >
    class basic_string;

  template<> struct char_traits<char>;

  typedef basic_string<char> string;


  template<> struct char_traits<wchar_t>;

  typedef basic_string<wchar_t> wstring;

}
# 49 "/usr/include/c++/3.3/iosfwd" 2 3
# 1 "/usr/include/c++/3.3/bits/fpos.h" 1 3
# 42 "/usr/include/c++/3.3/bits/fpos.h" 3
       
# 43 "/usr/include/c++/3.3/bits/fpos.h" 3

# 1 "/usr/include/c++/3.3/i486-linux/bits/c++io.h" 1 3
# 35 "/usr/include/c++/3.3/i486-linux/bits/c++io.h" 3
# 1 "/usr/include/c++/3.3/cstdio" 1 3
# 47 "/usr/include/c++/3.3/cstdio" 3
       
# 48 "/usr/include/c++/3.3/cstdio" 3




# 1 "/usr/include/stdio.h" 1 3 4
# 30 "/usr/include/stdio.h" 3 4




# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 1 3 4
# 35 "/usr/include/stdio.h" 2 3 4
# 44 "/usr/include/stdio.h" 3 4


typedef struct _IO_FILE FILE;





# 62 "/usr/include/stdio.h" 3 4
typedef struct _IO_FILE __FILE;
# 72 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/libio.h" 1 3 4
# 32 "/usr/include/libio.h" 3 4
# 1 "/usr/include/_G_config.h" 1 3 4
# 14 "/usr/include/_G_config.h" 3 4
# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 1 3 4
# 354 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 3 4
typedef unsigned int wint_t;
# 15 "/usr/include/_G_config.h" 2 3 4
# 24 "/usr/include/_G_config.h" 3 4
# 1 "/usr/include/wchar.h" 1 3 4
# 48 "/usr/include/wchar.h" 3 4
# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 1 3 4
# 49 "/usr/include/wchar.h" 2 3 4

# 1 "/usr/include/bits/wchar.h" 1 3 4
# 51 "/usr/include/wchar.h" 2 3 4
# 76 "/usr/include/wchar.h" 3 4
typedef struct
{
  int __count;
  union
  {
    wint_t __wch;
    char __wchb[4];
  } __value;
} __mbstate_t;
# 25 "/usr/include/_G_config.h" 2 3 4

typedef struct
{
  __off_t __pos;
  __mbstate_t __state;
} _G_fpos_t;
typedef struct
{
  __off64_t __pos;
  __mbstate_t __state;
} _G_fpos64_t;
# 44 "/usr/include/_G_config.h" 3 4
# 1 "/usr/include/gconv.h" 1 3 4
# 28 "/usr/include/gconv.h" 3 4
# 1 "/usr/include/wchar.h" 1 3 4
# 48 "/usr/include/wchar.h" 3 4
# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 1 3 4
# 49 "/usr/include/wchar.h" 2 3 4
# 29 "/usr/include/gconv.h" 2 3 4


# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 1 3 4
# 32 "/usr/include/gconv.h" 2 3 4





enum
{
  __GCONV_OK = 0,
  __GCONV_NOCONV,
  __GCONV_NODB,
  __GCONV_NOMEM,

  __GCONV_EMPTY_INPUT,
  __GCONV_FULL_OUTPUT,
  __GCONV_ILLEGAL_INPUT,
  __GCONV_INCOMPLETE_INPUT,

  __GCONV_ILLEGAL_DESCRIPTOR,
  __GCONV_INTERNAL_ERROR
};



enum
{
  __GCONV_IS_LAST = 0x0001,
  __GCONV_IGNORE_ERRORS = 0x0002
};



struct __gconv_step;
struct __gconv_step_data;
struct __gconv_loaded_object;
struct __gconv_trans_data;



typedef int (*__gconv_fct) (struct __gconv_step *, struct __gconv_step_data *,
                            const unsigned char **, const unsigned char *,
                            unsigned char **, size_t *, int, int);


typedef wint_t (*__gconv_btowc_fct) (struct __gconv_step *, unsigned char);


typedef int (*__gconv_init_fct) (struct __gconv_step *);
typedef void (*__gconv_end_fct) (struct __gconv_step *);



typedef int (*__gconv_trans_fct) (struct __gconv_step *,
                                  struct __gconv_step_data *, void *,
                                  const unsigned char *,
                                  const unsigned char **,
                                  const unsigned char *, unsigned char **,
                                  size_t *);


typedef int (*__gconv_trans_context_fct) (void *, const unsigned char *,
                                          const unsigned char *,
                                          unsigned char *, unsigned char *);


typedef int (*__gconv_trans_query_fct) (const char *, const char ***,
                                        size_t *);


typedef int (*__gconv_trans_init_fct) (void **, const char *);
typedef void (*__gconv_trans_end_fct) (void *);

struct __gconv_trans_data
{

  __gconv_trans_fct __trans_fct;
  __gconv_trans_context_fct __trans_context_fct;
  __gconv_trans_end_fct __trans_end_fct;
  void *__data;
  struct __gconv_trans_data *__next;
};



struct __gconv_step
{
  struct __gconv_loaded_object *__shlib_handle;
  const char *__modname;

  int __counter;

  char *__from_name;
  char *__to_name;

  __gconv_fct __fct;
  __gconv_btowc_fct __btowc_fct;
  __gconv_init_fct __init_fct;
  __gconv_end_fct __end_fct;



  int __min_needed_from;
  int __max_needed_from;
  int __min_needed_to;
  int __max_needed_to;


  int __stateful;

  void *__data;
};



struct __gconv_step_data
{
  unsigned char *__outbuf;
  unsigned char *__outbufend;



  int __flags;



  int __invocation_counter;



  int __internal_use;

  __mbstate_t *__statep;
  __mbstate_t __state;



  struct __gconv_trans_data *__trans;
};



typedef struct __gconv_info
{
  size_t __nsteps;
  struct __gconv_step *__steps;
  struct __gconv_step_data __data [1];
} *__gconv_t;
# 45 "/usr/include/_G_config.h" 2 3 4
typedef union
{
  struct __gconv_info __cd;
  struct
  {
    struct __gconv_info __cd;
    struct __gconv_step_data __data;
  } __combined;
} _G_iconv_t;

typedef int _G_int16_t ;
typedef int _G_int32_t ;
typedef unsigned int _G_uint16_t ;
typedef unsigned int _G_uint32_t ;
# 33 "/usr/include/libio.h" 2 3 4
# 53 "/usr/include/libio.h" 3 4
# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stdarg.h" 1 3 4
# 43 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 54 "/usr/include/libio.h" 2 3 4
# 162 "/usr/include/libio.h" 3 4
struct _IO_jump_t; struct _IO_FILE;
# 172 "/usr/include/libio.h" 3 4
typedef void _IO_lock_t;





struct _IO_marker {
  struct _IO_marker *_next;
  struct _IO_FILE *_sbuf;



  int _pos;
# 195 "/usr/include/libio.h" 3 4
};


enum __codecvt_result
{
  __codecvt_ok,
  __codecvt_partial,
  __codecvt_error,
  __codecvt_noconv
};




struct _IO_codecvt
{
  void (*__codecvt_destr) (struct _IO_codecvt *);
  enum __codecvt_result (*__codecvt_do_out) (struct _IO_codecvt *,
                                             __mbstate_t *,
                                             const wchar_t *,
                                             const wchar_t *,
                                             const wchar_t **, char *,
                                             char *, char **);
  enum __codecvt_result (*__codecvt_do_unshift) (struct _IO_codecvt *,
                                                 __mbstate_t *, char *,
                                                 char *, char **);
  enum __codecvt_result (*__codecvt_do_in) (struct _IO_codecvt *,
                                            __mbstate_t *,
                                            const char *, const char *,
                                            const char **, wchar_t *,
                                            wchar_t *, wchar_t **);
  int (*__codecvt_do_encoding) (struct _IO_codecvt *);
  int (*__codecvt_do_always_noconv) (struct _IO_codecvt *);
  int (*__codecvt_do_length) (struct _IO_codecvt *, __mbstate_t *,
                              const char *, const char *, size_t);
  int (*__codecvt_do_max_length) (struct _IO_codecvt *);

  _G_iconv_t __cd_in;
  _G_iconv_t __cd_out;
};


struct _IO_wide_data
{
  wchar_t *_IO_read_ptr;
  wchar_t *_IO_read_end;
  wchar_t *_IO_read_base;
  wchar_t *_IO_write_base;
  wchar_t *_IO_write_ptr;
  wchar_t *_IO_write_end;
  wchar_t *_IO_buf_base;
  wchar_t *_IO_buf_end;

  wchar_t *_IO_save_base;
  wchar_t *_IO_backup_base;

  wchar_t *_IO_save_end;

  __mbstate_t _IO_state;
  __mbstate_t _IO_last_state;
  struct _IO_codecvt _codecvt;

  wchar_t _shortbuf[1];

  struct _IO_jump_t *_wide_vtable;
};


struct _IO_FILE {
  int _flags;




  char* _IO_read_ptr;
  char* _IO_read_end;
  char* _IO_read_base;
  char* _IO_write_base;
  char* _IO_write_ptr;
  char* _IO_write_end;
  char* _IO_buf_base;
  char* _IO_buf_end;

  char *_IO_save_base;
  char *_IO_backup_base;
  char *_IO_save_end;

  struct _IO_marker *_markers;

  struct _IO_FILE *_chain;

  int _fileno;



  int _flags2;

  __off_t _old_offset;



  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];



  _IO_lock_t *_lock;
# 311 "/usr/include/libio.h" 3 4
  __off64_t _offset;


  struct _IO_codecvt *_codecvt;
  struct _IO_wide_data *_wide_data;




  int _mode;

  char _unused2[15 * sizeof (int) - 2 * sizeof (void *)];

};


typedef struct _IO_FILE _IO_FILE;


struct _IO_FILE_plus;

extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;
# 350 "/usr/include/libio.h" 3 4
typedef __ssize_t __io_read_fn (void *__cookie, char *__buf, size_t __nbytes);







typedef __ssize_t __io_write_fn (void *__cookie, const char *__buf,
                                 size_t __n);







typedef int __io_seek_fn (void *__cookie, __off64_t *__pos, int __w);


typedef int __io_close_fn (void *__cookie);




typedef __io_read_fn cookie_read_function_t;
typedef __io_write_fn cookie_write_function_t;
typedef __io_seek_fn cookie_seek_function_t;
typedef __io_close_fn cookie_close_function_t;


typedef struct
{
  __io_read_fn *read;
  __io_write_fn *write;
  __io_seek_fn *seek;
  __io_close_fn *close;
} _IO_cookie_io_functions_t;
typedef _IO_cookie_io_functions_t cookie_io_functions_t;

struct _IO_cookie_file;


extern void _IO_cookie_init (struct _IO_cookie_file *__cfile, int __read_write,
                             void *__cookie, _IO_cookie_io_functions_t __fns);







extern int __underflow (_IO_FILE *) ;
extern int __uflow (_IO_FILE *) ;
extern int __overflow (_IO_FILE *, int) ;
extern wint_t __wunderflow (_IO_FILE *) ;
extern wint_t __wuflow (_IO_FILE *) ;
extern wint_t __woverflow (_IO_FILE *, wint_t) ;
# 432 "/usr/include/libio.h" 3 4
extern int _IO_getc (_IO_FILE *__fp) ;
extern int _IO_putc (int __c, _IO_FILE *__fp) ;
extern int _IO_feof (_IO_FILE *__fp) ;
extern int _IO_ferror (_IO_FILE *__fp) ;

extern int _IO_peekc_locked (_IO_FILE *__fp) ;





extern void _IO_flockfile (_IO_FILE *) ;
extern void _IO_funlockfile (_IO_FILE *) ;
extern int _IO_ftrylockfile (_IO_FILE *) ;
# 462 "/usr/include/libio.h" 3 4
extern int _IO_vfscanf (_IO_FILE * , const char * ,
                        __gnuc_va_list, int *) ;
extern int _IO_vfprintf (_IO_FILE *, const char *,
                         __gnuc_va_list) ;
extern __ssize_t _IO_padn (_IO_FILE *, int, __ssize_t) ;
extern size_t _IO_sgetn (_IO_FILE *, void *, size_t) ;

extern __off64_t _IO_seekoff (_IO_FILE *, __off64_t, int, int) ;
extern __off64_t _IO_seekpos (_IO_FILE *, __off64_t, int) ;

extern void _IO_free_backup_area (_IO_FILE *) ;


extern wint_t _IO_getwc (_IO_FILE *__fp) ;
extern wint_t _IO_putwc (wchar_t __wc, _IO_FILE *__fp) ;
extern int _IO_fwide (_IO_FILE *__fp, int __mode) ;
# 511 "/usr/include/libio.h" 3 4
extern int _IO_vfwscanf (_IO_FILE * , const wchar_t * ,
                         __gnuc_va_list, int *) ;
extern int _IO_vfwprintf (_IO_FILE *, const wchar_t *,
                          __gnuc_va_list) ;
extern __ssize_t _IO_wpadn (_IO_FILE *, wint_t, __ssize_t) ;
extern void _IO_free_wbackup_area (_IO_FILE *) ;
# 73 "/usr/include/stdio.h" 2 3 4
# 81 "/usr/include/stdio.h" 3 4
# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stdarg.h" 1 3 4
# 105 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stdarg.h" 3 4
typedef __gnuc_va_list va_list;
# 82 "/usr/include/stdio.h" 2 3 4






typedef _G_fpos_t fpos_t;





typedef _G_fpos64_t fpos64_t;
# 138 "/usr/include/stdio.h" 3 4
# 1 "/usr/include/bits/stdio_lim.h" 1 3 4
# 139 "/usr/include/stdio.h" 2 3 4



extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;







extern int remove (const char *__filename) ;

extern int rename (const char *__old, const char *__new) ;









extern FILE *tmpfile (void);
# 174 "/usr/include/stdio.h" 3 4
extern FILE *tmpfile64 (void);



extern char *tmpnam (char *__s) ;





extern char *tmpnam_r (char *__s) ;
# 196 "/usr/include/stdio.h" 3 4
extern char *tempnam (const char *__dir, const char *__pfx)
     ;








extern int fclose (FILE *__stream);




extern int fflush (FILE *__stream);

# 221 "/usr/include/stdio.h" 3 4
extern int fflush_unlocked (FILE *__stream);
# 231 "/usr/include/stdio.h" 3 4
extern int fcloseall (void);









extern FILE *fopen (const char * __filename,
                    const char * __modes);




extern FILE *freopen (const char * __filename,
                      const char * __modes,
                      FILE * __stream);
# 262 "/usr/include/stdio.h" 3 4


extern FILE *fopen64 (const char * __filename,
                      const char * __modes);
extern FILE *freopen64 (const char * __filename,
                        const char * __modes,
                        FILE * __stream);




extern FILE *fdopen (int __fd, const char *__modes) ;





extern FILE *fopencookie (void * __magic_cookie,
                          const char * __modes,
                          _IO_cookie_io_functions_t __io_funcs) ;


extern FILE *fmemopen (void *__s, size_t __len, const char *__modes) ;




extern FILE *open_memstream (char ** __bufloc,
                             size_t * __sizeloc) ;






extern void setbuf (FILE * __stream, char * __buf) ;



extern int setvbuf (FILE * __stream, char * __buf,
                    int __modes, size_t __n) ;





extern void setbuffer (FILE * __stream, char * __buf,
                       size_t __size) ;


extern void setlinebuf (FILE *__stream) ;








extern int fprintf (FILE * __stream,
                    const char * __format, ...);




extern int printf (const char * __format, ...);

extern int sprintf (char * __s,
                    const char * __format, ...) ;





extern int vfprintf (FILE * __s, const char * __format,
                     __gnuc_va_list __arg);




extern int vprintf (const char * __format, __gnuc_va_list __arg);

extern int vsprintf (char * __s, const char * __format,
                     __gnuc_va_list __arg) ;





extern int snprintf (char * __s, size_t __maxlen,
                     const char * __format, ...)
     ;

extern int vsnprintf (char * __s, size_t __maxlen,
                      const char * __format, __gnuc_va_list __arg)
     ;






extern int vasprintf (char ** __ptr, const char * __f,
                      __gnuc_va_list __arg)
     ;
extern int __asprintf (char ** __ptr,
                       const char * __fmt, ...)
     ;
extern int asprintf (char ** __ptr,
                     const char * __fmt, ...)
     ;







extern int vdprintf (int __fd, const char * __fmt,
                     __gnuc_va_list __arg)
     ;
extern int dprintf (int __fd, const char * __fmt, ...)
     ;








extern int fscanf (FILE * __stream,
                   const char * __format, ...);




extern int scanf (const char * __format, ...);

extern int sscanf (const char * __s,
                   const char * __format, ...) ;








extern int vfscanf (FILE * __s, const char * __format,
                    __gnuc_va_list __arg)
     ;





extern int vscanf (const char * __format, __gnuc_va_list __arg)
     ;


extern int vsscanf (const char * __s,
                    const char * __format, __gnuc_va_list __arg)
     ;









extern int fgetc (FILE *__stream);
extern int getc (FILE *__stream);





extern int getchar (void);

# 454 "/usr/include/stdio.h" 3 4
extern int getc_unlocked (FILE *__stream);
extern int getchar_unlocked (void);
# 465 "/usr/include/stdio.h" 3 4
extern int fgetc_unlocked (FILE *__stream);








extern int fputc (int __c, FILE *__stream) ;
extern int putc (int __c, FILE *__stream) ;





extern int putchar (int __c);

# 495 "/usr/include/stdio.h" 3 4
extern int fputc_unlocked (int __c, FILE *__stream);







extern int putc_unlocked (int __c, FILE *__stream);
extern int putchar_unlocked (int __c);






extern int getw (FILE *__stream) ;


extern int putw (int __w, FILE *__stream) ;








extern char *fgets (char * __s, int __n, FILE * __stream);






extern char *gets (char *__s);

# 540 "/usr/include/stdio.h" 3 4
extern char *fgets_unlocked (char * __s, int __n,
                             FILE * __stream);
# 556 "/usr/include/stdio.h" 3 4
extern __ssize_t __getdelim (char ** __lineptr,
                               size_t * __n, int __delimiter,
                               FILE * __stream);
extern __ssize_t getdelim (char ** __lineptr,
                             size_t * __n, int __delimiter,
                             FILE * __stream);







extern __ssize_t getline (char ** __lineptr,
                            size_t * __n,
                            FILE * __stream);








extern int fputs (const char * __s, FILE * __stream);





extern int puts (const char *__s);






extern int ungetc (int __c, FILE *__stream);






extern size_t fread (void * __ptr, size_t __size,
                     size_t __n, FILE * __stream);




extern size_t fwrite (const void * __ptr, size_t __size,
                      size_t __n, FILE * __s);

# 617 "/usr/include/stdio.h" 3 4
extern int fputs_unlocked (const char * __s,
                           FILE * __stream);
# 628 "/usr/include/stdio.h" 3 4
extern size_t fread_unlocked (void * __ptr, size_t __size,
                              size_t __n, FILE * __stream) ;
extern size_t fwrite_unlocked (const void * __ptr, size_t __size,
                               size_t __n, FILE * __stream) ;








extern int fseek (FILE *__stream, long int __off, int __whence);




extern long int ftell (FILE *__stream);




extern void rewind (FILE *__stream);

# 664 "/usr/include/stdio.h" 3 4
extern int fseeko (FILE *__stream, __off_t __off, int __whence);




extern __off_t ftello (FILE *__stream);
# 683 "/usr/include/stdio.h" 3 4






extern int fgetpos (FILE * __stream, fpos_t * __pos);




extern int fsetpos (FILE *__stream, const fpos_t *__pos);
# 706 "/usr/include/stdio.h" 3 4



extern int fseeko64 (FILE *__stream, __off64_t __off, int __whence);
extern __off64_t ftello64 (FILE *__stream);
extern int fgetpos64 (FILE * __stream, fpos64_t * __pos);
extern int fsetpos64 (FILE *__stream, const fpos64_t *__pos);




extern void clearerr (FILE *__stream) ;

extern int feof (FILE *__stream) ;

extern int ferror (FILE *__stream) ;




extern void clearerr_unlocked (FILE *__stream) ;
extern int feof_unlocked (FILE *__stream) ;
extern int ferror_unlocked (FILE *__stream) ;








extern void perror (const char *__s);






# 1 "/usr/include/bits/sys_errlist.h" 1 3 4
# 27 "/usr/include/bits/sys_errlist.h" 3 4
extern int sys_nerr;
extern const char *const sys_errlist[];


extern int _sys_nerr;
extern const char *const _sys_errlist[];
# 745 "/usr/include/stdio.h" 2 3 4




extern int fileno (FILE *__stream) ;




extern int fileno_unlocked (FILE *__stream) ;






extern FILE *popen (const char *__command, const char *__modes) ;


extern int pclose (FILE *__stream) ;





extern char *ctermid (char *__s) ;





extern char *cuserid (char *__s) ;




struct obstack;


extern int obstack_printf (struct obstack * __obstack,
                           const char * __format, ...)
     ;
extern int obstack_vprintf (struct obstack * __obstack,
                            const char * __format,
                            __gnuc_va_list __args)
     ;







extern void flockfile (FILE *__stream) ;



extern int ftrylockfile (FILE *__stream) ;


extern void funlockfile (FILE *__stream) ;
# 822 "/usr/include/stdio.h" 3 4

# 53 "/usr/include/c++/3.3/cstdio" 2 3
# 97 "/usr/include/c++/3.3/cstdio" 3
namespace std
{
  using ::FILE;
  using ::fpos_t;

  using ::clearerr;
  using ::fclose;
  using ::feof;
  using ::ferror;
  using ::fflush;
  using ::fgetc;
  using ::fgetpos;
  using ::fgets;
  using ::fopen;
  using ::fprintf;
  using ::fputc;
  using ::fputs;
  using ::fread;
  using ::freopen;
  using ::fscanf;
  using ::fseek;
  using ::fsetpos;
  using ::ftell;
  using ::fwrite;
  using ::getc;
  using ::getchar;
  using ::gets;
  using ::perror;
  using ::printf;
  using ::putc;
  using ::putchar;
  using ::puts;
  using ::remove;
  using ::rename;
  using ::rewind;
  using ::scanf;
  using ::setbuf;
  using ::setvbuf;
  using ::sprintf;
  using ::sscanf;
  using ::tmpfile;
  using ::tmpnam;
  using ::ungetc;
  using ::vfprintf;
  using ::vprintf;
  using ::vsprintf;
}
# 153 "/usr/include/c++/3.3/cstdio" 3
namespace __gnu_cxx
{
# 167 "/usr/include/c++/3.3/cstdio" 3
  using ::snprintf;
  using ::vfscanf;
  using ::vscanf;
  using ::vsnprintf;
  using ::vsscanf;

}

namespace std
{
  using __gnu_cxx::snprintf;
  using __gnu_cxx::vfscanf;
  using __gnu_cxx::vscanf;
  using __gnu_cxx::vsnprintf;
  using __gnu_cxx::vsscanf;
}
# 36 "/usr/include/c++/3.3/i486-linux/bits/c++io.h" 2 3

# 1 "/usr/include/c++/3.3/i486-linux/bits/gthr.h" 1 3
# 98 "/usr/include/c++/3.3/i486-linux/bits/gthr.h" 3
# 1 "/usr/include/c++/3.3/i486-linux/bits/gthr-default.h" 1 3
# 37 "/usr/include/c++/3.3/i486-linux/bits/gthr-default.h" 3
# 1 "/usr/include/pthread.h" 1 3 4
# 20 "/usr/include/pthread.h" 3 4
# 1 "/usr/include/sched.h" 1 3 4
# 29 "/usr/include/sched.h" 3 4
# 1 "/usr/include/time.h" 1 3 4
# 30 "/usr/include/sched.h" 2 3 4


# 1 "/usr/include/bits/sched.h" 1 3 4
# 61 "/usr/include/bits/sched.h" 3 4
struct sched_param
  {
    int __sched_priority;
  };





extern int clone (int (*__fn) (void *__arg), void *__child_stack,
                  int __flags, void *__arg) ;



# 97 "/usr/include/bits/sched.h" 3 4
typedef unsigned long int __cpu_mask;






typedef struct
{
  __cpu_mask __bits[1024 / (8 * sizeof (__cpu_mask))];
} cpu_set_t;
# 33 "/usr/include/sched.h" 2 3 4







extern int sched_setparam (__pid_t __pid, const struct sched_param *__param)
     ;


extern int sched_getparam (__pid_t __pid, struct sched_param *__param) ;


extern int sched_setscheduler (__pid_t __pid, int __policy,
                               const struct sched_param *__param) ;


extern int sched_getscheduler (__pid_t __pid) ;


extern int sched_yield (void) ;


extern int sched_get_priority_max (int __algorithm) ;


extern int sched_get_priority_min (int __algorithm) ;


extern int sched_rr_get_interval (__pid_t __pid, struct timespec *__t) ;
# 76 "/usr/include/sched.h" 3 4
extern int sched_setaffinity (__pid_t __pid, const cpu_set_t *__mask)
     ;


extern int sched_getaffinity (__pid_t __pid, cpu_set_t *__mask) ;



# 21 "/usr/include/pthread.h" 2 3 4
# 1 "/usr/include/time.h" 1 3 4
# 30 "/usr/include/time.h" 3 4








# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 1 3 4
# 39 "/usr/include/time.h" 2 3 4



# 1 "/usr/include/bits/time.h" 1 3 4
# 43 "/usr/include/time.h" 2 3 4
# 129 "/usr/include/time.h" 3 4


struct tm
{
  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;


  long int tm_gmtoff;
  const char *tm_zone;




};








struct itimerspec
  {
    struct timespec it_interval;
    struct timespec it_value;
  };


struct sigevent;
# 178 "/usr/include/time.h" 3 4



extern clock_t clock (void) ;


extern time_t time (time_t *__timer) ;


extern double difftime (time_t __time1, time_t __time0)
     ;


extern time_t mktime (struct tm *__tp) ;





extern size_t strftime (char * __s, size_t __maxsize,
                        const char * __format,
                        const struct tm * __tp) ;





extern char *strptime (const char * __s,
                       const char * __fmt, struct tm *__tp)
     ;







extern size_t strftime_l (char * __s, size_t __maxsize,
                          const char * __format,
                          const struct tm * __tp,
                          __locale_t __loc) ;

extern char *strptime_l (const char * __s,
                         const char * __fmt, struct tm *__tp,
                         __locale_t __loc) ;






extern struct tm *gmtime (const time_t *__timer) ;



extern struct tm *localtime (const time_t *__timer) ;





extern struct tm *gmtime_r (const time_t * __timer,
                            struct tm * __tp) ;



extern struct tm *localtime_r (const time_t * __timer,
                               struct tm * __tp) ;





extern char *asctime (const struct tm *__tp) ;


extern char *ctime (const time_t *__timer) ;







extern char *asctime_r (const struct tm * __tp,
                        char * __buf) ;


extern char *ctime_r (const time_t * __timer,
                      char * __buf) ;




extern char *__tzname[2];
extern int __daylight;
extern long int __timezone;




extern char *tzname[2];



extern void tzset (void) ;



extern int daylight;
extern long int timezone;





extern int stime (const time_t *__when) ;
# 309 "/usr/include/time.h" 3 4
extern time_t timegm (struct tm *__tp) ;


extern time_t timelocal (struct tm *__tp) ;


extern int dysize (int __year) ;
# 324 "/usr/include/time.h" 3 4
extern int nanosleep (const struct timespec *__requested_time,
                      struct timespec *__remaining);



extern int clock_getres (clockid_t __clock_id, struct timespec *__res) ;


extern int clock_gettime (clockid_t __clock_id, struct timespec *__tp) ;


extern int clock_settime (clockid_t __clock_id, const struct timespec *__tp)
     ;






extern int clock_nanosleep (clockid_t __clock_id, int __flags,
                            const struct timespec *__req,
                            struct timespec *__rem);


extern int clock_getcpuclockid (pid_t __pid, clockid_t *__clock_id) ;




extern int timer_create (clockid_t __clock_id,
                         struct sigevent * __evp,
                         timer_t * __timerid) ;


extern int timer_delete (timer_t __timerid) ;


extern int timer_settime (timer_t __timerid, int __flags,
                          const struct itimerspec * __value,
                          struct itimerspec * __ovalue) ;


extern int timer_gettime (timer_t __timerid, struct itimerspec *__value)
     ;


extern int timer_getoverrun (timer_t __timerid) ;
# 386 "/usr/include/time.h" 3 4
extern int getdate_err;
# 395 "/usr/include/time.h" 3 4
extern struct tm *getdate (const char *__string);
# 409 "/usr/include/time.h" 3 4
extern int getdate_r (const char * __string,
                      struct tm * __resbufp);



# 22 "/usr/include/pthread.h" 2 3 4


# 1 "/usr/include/signal.h" 1 3 4
# 31 "/usr/include/signal.h" 3 4


# 1 "/usr/include/bits/sigset.h" 1 3 4
# 34 "/usr/include/signal.h" 2 3 4
# 392 "/usr/include/signal.h" 3 4

# 25 "/usr/include/pthread.h" 2 3 4
# 1 "/usr/include/bits/pthreadtypes.h" 1 3 4
# 26 "/usr/include/pthread.h" 2 3 4
# 1 "/usr/include/bits/initspin.h" 1 3 4
# 27 "/usr/include/pthread.h" 2 3 4



# 59 "/usr/include/pthread.h" 3 4
enum
{
  PTHREAD_CREATE_JOINABLE,

  PTHREAD_CREATE_DETACHED

};

enum
{
  PTHREAD_INHERIT_SCHED,

  PTHREAD_EXPLICIT_SCHED

};

enum
{
  PTHREAD_SCOPE_SYSTEM,

  PTHREAD_SCOPE_PROCESS

};

enum
{
  PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_ADAPTIVE_NP

  ,
  PTHREAD_MUTEX_NORMAL = PTHREAD_MUTEX_TIMED_NP,
  PTHREAD_MUTEX_RECURSIVE = PTHREAD_MUTEX_RECURSIVE_NP,
  PTHREAD_MUTEX_ERRORCHECK = PTHREAD_MUTEX_ERRORCHECK_NP,
  PTHREAD_MUTEX_DEFAULT = PTHREAD_MUTEX_NORMAL



  , PTHREAD_MUTEX_FAST_NP = PTHREAD_MUTEX_ADAPTIVE_NP

};

enum
{
  PTHREAD_PROCESS_PRIVATE,

  PTHREAD_PROCESS_SHARED

};


enum
{
  PTHREAD_RWLOCK_PREFER_READER_NP,
  PTHREAD_RWLOCK_PREFER_WRITER_NP,
  PTHREAD_RWLOCK_PREFER_WRITER_NONRECURSIVE_NP,
  PTHREAD_RWLOCK_DEFAULT_NP = PTHREAD_RWLOCK_PREFER_WRITER_NP
};
# 131 "/usr/include/pthread.h" 3 4
struct _pthread_cleanup_buffer
{
  void (*__routine) (void *);
  void *__arg;
  int __canceltype;
  struct _pthread_cleanup_buffer *__prev;
};



enum
{
  PTHREAD_CANCEL_ENABLE,

  PTHREAD_CANCEL_DISABLE

};
enum
{
  PTHREAD_CANCEL_DEFERRED,

  PTHREAD_CANCEL_ASYNCHRONOUS

};
# 163 "/usr/include/pthread.h" 3 4
extern int pthread_create (pthread_t * __threadp,
                           const pthread_attr_t * __attr,
                           void *(*__start_routine) (void *),
                           void * __arg) ;


extern pthread_t pthread_self (void) ;


extern int pthread_equal (pthread_t __thread1, pthread_t __thread2) ;


extern void pthread_exit (void *__retval)
     ;




extern int pthread_join (pthread_t __th, void **__thread_return) ;





extern int pthread_detach (pthread_t __th) ;







extern int pthread_attr_init (pthread_attr_t *__attr) ;


extern int pthread_attr_destroy (pthread_attr_t *__attr) ;


extern int pthread_attr_setdetachstate (pthread_attr_t *__attr,
                                        int __detachstate) ;


extern int pthread_attr_getdetachstate (const pthread_attr_t *__attr,
                                        int *__detachstate) ;


extern int pthread_attr_setschedparam (pthread_attr_t * __attr,
                                       const struct sched_param *
                                       __param) ;


extern int pthread_attr_getschedparam (const pthread_attr_t *
                                       __attr,
                                       struct sched_param * __param)
     ;


extern int pthread_attr_setschedpolicy (pthread_attr_t *__attr, int __policy)
     ;


extern int pthread_attr_getschedpolicy (const pthread_attr_t *
                                        __attr, int * __policy)
     ;


extern int pthread_attr_setinheritsched (pthread_attr_t *__attr,
                                         int __inherit) ;


extern int pthread_attr_getinheritsched (const pthread_attr_t *
                                         __attr, int * __inherit)
     ;


extern int pthread_attr_setscope (pthread_attr_t *__attr, int __scope)
     ;


extern int pthread_attr_getscope (const pthread_attr_t * __attr,
                                  int * __scope) ;



extern int pthread_attr_setguardsize (pthread_attr_t *__attr,
                                      size_t __guardsize) ;


extern int pthread_attr_getguardsize (const pthread_attr_t *
                                      __attr, size_t * __guardsize)
     ;






extern int pthread_attr_setstackaddr (pthread_attr_t *__attr,
                                      void *__stackaddr) ;


extern int pthread_attr_getstackaddr (const pthread_attr_t *
                                      __attr, void ** __stackaddr)
     ;





extern int pthread_attr_setstack (pthread_attr_t *__attr, void *__stackaddr,
                                  size_t __stacksize) ;


extern int pthread_attr_getstack (const pthread_attr_t * __attr,
                                  void ** __stackaddr,
                                  size_t * __stacksize) ;





extern int pthread_attr_setstacksize (pthread_attr_t *__attr,
                                      size_t __stacksize) ;


extern int pthread_attr_getstacksize (const pthread_attr_t *
                                      __attr, size_t * __stacksize)
     ;



extern int pthread_getattr_np (pthread_t __th, pthread_attr_t *__attr) ;






extern int pthread_setschedparam (pthread_t __target_thread, int __policy,
                                  const struct sched_param *__param)
     ;


extern int pthread_getschedparam (pthread_t __target_thread,
                                  int * __policy,
                                  struct sched_param * __param)
     ;



extern int pthread_getconcurrency (void) ;


extern int pthread_setconcurrency (int __level) ;







extern int pthread_yield (void) ;






extern int pthread_mutex_init (pthread_mutex_t * __mutex,
                               const pthread_mutexattr_t *
                               __mutex_attr) ;


extern int pthread_mutex_destroy (pthread_mutex_t *__mutex) ;


extern int pthread_mutex_trylock (pthread_mutex_t *__mutex) ;


extern int pthread_mutex_lock (pthread_mutex_t *__mutex) ;



extern int pthread_mutex_timedlock (pthread_mutex_t * __mutex,
                                    const struct timespec *
                                    __abstime) ;



extern int pthread_mutex_unlock (pthread_mutex_t *__mutex) ;






extern int pthread_mutexattr_init (pthread_mutexattr_t *__attr) ;


extern int pthread_mutexattr_destroy (pthread_mutexattr_t *__attr) ;


extern int pthread_mutexattr_getpshared (const pthread_mutexattr_t *
                                         __attr,
                                         int * __pshared) ;


extern int pthread_mutexattr_setpshared (pthread_mutexattr_t *__attr,
                                         int __pshared) ;





extern int pthread_mutexattr_settype (pthread_mutexattr_t *__attr, int __kind)
     ;


extern int pthread_mutexattr_gettype (const pthread_mutexattr_t *
                                      __attr, int * __kind) ;







extern int pthread_cond_init (pthread_cond_t * __cond,
                              const pthread_condattr_t *
                              __cond_attr) ;


extern int pthread_cond_destroy (pthread_cond_t *__cond) ;


extern int pthread_cond_signal (pthread_cond_t *__cond) ;


extern int pthread_cond_broadcast (pthread_cond_t *__cond) ;



extern int pthread_cond_wait (pthread_cond_t * __cond,
                              pthread_mutex_t * __mutex) ;





extern int pthread_cond_timedwait (pthread_cond_t * __cond,
                                   pthread_mutex_t * __mutex,
                                   const struct timespec *
                                   __abstime) ;




extern int pthread_condattr_init (pthread_condattr_t *__attr) ;


extern int pthread_condattr_destroy (pthread_condattr_t *__attr) ;


extern int pthread_condattr_getpshared (const pthread_condattr_t *
                                        __attr,
                                        int * __pshared) ;


extern int pthread_condattr_setpshared (pthread_condattr_t *__attr,
                                        int __pshared) ;







extern int pthread_rwlock_init (pthread_rwlock_t * __rwlock,
                                const pthread_rwlockattr_t *
                                __attr) ;


extern int pthread_rwlock_destroy (pthread_rwlock_t *__rwlock) ;


extern int pthread_rwlock_rdlock (pthread_rwlock_t *__rwlock) ;


extern int pthread_rwlock_tryrdlock (pthread_rwlock_t *__rwlock) ;



extern int pthread_rwlock_timedrdlock (pthread_rwlock_t * __rwlock,
                                       const struct timespec *
                                       __abstime) ;



extern int pthread_rwlock_wrlock (pthread_rwlock_t *__rwlock) ;


extern int pthread_rwlock_trywrlock (pthread_rwlock_t *__rwlock) ;



extern int pthread_rwlock_timedwrlock (pthread_rwlock_t * __rwlock,
                                       const struct timespec *
                                       __abstime) ;



extern int pthread_rwlock_unlock (pthread_rwlock_t *__rwlock) ;





extern int pthread_rwlockattr_init (pthread_rwlockattr_t *__attr) ;


extern int pthread_rwlockattr_destroy (pthread_rwlockattr_t *__attr) ;


extern int pthread_rwlockattr_getpshared (const pthread_rwlockattr_t *
                                          __attr,
                                          int * __pshared) ;


extern int pthread_rwlockattr_setpshared (pthread_rwlockattr_t *__attr,
                                          int __pshared) ;


extern int pthread_rwlockattr_getkind_np (const pthread_rwlockattr_t *__attr,
                                          int *__pref) ;


extern int pthread_rwlockattr_setkind_np (pthread_rwlockattr_t *__attr,
                                          int __pref) ;
# 509 "/usr/include/pthread.h" 3 4
extern int pthread_spin_init (pthread_spinlock_t *__lock, int __pshared)
     ;


extern int pthread_spin_destroy (pthread_spinlock_t *__lock) ;


extern int pthread_spin_lock (pthread_spinlock_t *__lock) ;


extern int pthread_spin_trylock (pthread_spinlock_t *__lock) ;


extern int pthread_spin_unlock (pthread_spinlock_t *__lock) ;




extern int pthread_barrier_init (pthread_barrier_t * __barrier,
                                 const pthread_barrierattr_t *
                                 __attr, unsigned int __count) ;

extern int pthread_barrier_destroy (pthread_barrier_t *__barrier) ;

extern int pthread_barrierattr_init (pthread_barrierattr_t *__attr) ;

extern int pthread_barrierattr_destroy (pthread_barrierattr_t *__attr) ;

extern int pthread_barrierattr_getpshared (const pthread_barrierattr_t *
                                           __attr,
                                           int * __pshared) ;

extern int pthread_barrierattr_setpshared (pthread_barrierattr_t *__attr,
                                           int __pshared) ;

extern int pthread_barrier_wait (pthread_barrier_t *__barrier) ;
# 556 "/usr/include/pthread.h" 3 4
extern int pthread_key_create (pthread_key_t *__key,
                               void (*__destr_function) (void *)) ;


extern int pthread_key_delete (pthread_key_t __key) ;


extern int pthread_setspecific (pthread_key_t __key,
                                const void *__pointer) ;


extern void *pthread_getspecific (pthread_key_t __key) ;
# 576 "/usr/include/pthread.h" 3 4
extern int pthread_once (pthread_once_t *__once_control,
                         void (*__init_routine) (void)) ;






extern int pthread_setcancelstate (int __state, int *__oldstate) ;



extern int pthread_setcanceltype (int __type, int *__oldtype) ;


extern int pthread_cancel (pthread_t __cancelthread) ;




extern void pthread_testcancel (void) ;
# 610 "/usr/include/pthread.h" 3 4
extern void _pthread_cleanup_push (struct _pthread_cleanup_buffer *__buffer,
                                   void (*__routine) (void *),
                                   void *__arg) ;







extern void _pthread_cleanup_pop (struct _pthread_cleanup_buffer *__buffer,
                                  int __execute) ;
# 631 "/usr/include/pthread.h" 3 4
extern void _pthread_cleanup_push_defer (struct _pthread_cleanup_buffer *__buffer,
                                         void (*__routine) (void *),
                                         void *__arg) ;
# 642 "/usr/include/pthread.h" 3 4
extern void _pthread_cleanup_pop_restore (struct _pthread_cleanup_buffer *__buffer,
                                          int __execute) ;





extern int pthread_getcpuclockid (pthread_t __thread_id,
                                  clockid_t *__clock_id) ;




# 1 "/usr/include/bits/sigthread.h" 1 3 4
# 31 "/usr/include/bits/sigthread.h" 3 4
extern int pthread_sigmask (int __how,
                            const __sigset_t * __newmask,
                            __sigset_t * __oldmask);


extern int pthread_kill (pthread_t __threadid, int __signo) ;
# 656 "/usr/include/pthread.h" 2 3 4
# 671 "/usr/include/pthread.h" 3 4
extern int pthread_atfork (void (*__prepare) (void),
                           void (*__parent) (void),
                           void (*__child) (void)) ;




extern void pthread_kill_other_threads_np (void) ;


# 38 "/usr/include/c++/3.3/i486-linux/bits/gthr-default.h" 2 3
# 1 "/usr/include/unistd.h" 1 3 4
# 28 "/usr/include/unistd.h" 3 4

# 171 "/usr/include/unistd.h" 3 4
# 1 "/usr/include/bits/posix_opt.h" 1 3 4
# 172 "/usr/include/unistd.h" 2 3 4



# 1 "/usr/include/bits/environments.h" 1 3 4
# 23 "/usr/include/bits/environments.h" 3 4
# 1 "/usr/include/bits/wordsize.h" 1 3 4
# 24 "/usr/include/bits/environments.h" 2 3 4
# 176 "/usr/include/unistd.h" 2 3 4
# 195 "/usr/include/unistd.h" 3 4
# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 1 3 4
# 196 "/usr/include/unistd.h" 2 3 4
# 236 "/usr/include/unistd.h" 3 4
typedef __intptr_t intptr_t;






typedef __socklen_t socklen_t;
# 256 "/usr/include/unistd.h" 3 4
extern int access (const char *__name, int __type) ;




extern int euidaccess (const char *__name, int __type) ;
# 286 "/usr/include/unistd.h" 3 4
extern __off_t lseek (int __fd, __off_t __offset, int __whence) ;
# 298 "/usr/include/unistd.h" 3 4
extern __off64_t lseek64 (int __fd, __off64_t __offset, int __whence) ;






extern int close (int __fd);






extern ssize_t read (int __fd, void *__buf, size_t __nbytes);





extern ssize_t write (int __fd, const void *__buf, size_t __n);
# 328 "/usr/include/unistd.h" 3 4
extern ssize_t pread (int __fd, void *__buf, size_t __nbytes,
                      __off_t __offset);






extern ssize_t pwrite (int __fd, const void *__buf, size_t __n,
                       __off_t __offset);
# 356 "/usr/include/unistd.h" 3 4
extern ssize_t pread64 (int __fd, void *__buf, size_t __nbytes,
                        __off64_t __offset);


extern ssize_t pwrite64 (int __fd, const void *__buf, size_t __n,
                         __off64_t __offset);







extern int pipe (int __pipedes[2]) ;
# 378 "/usr/include/unistd.h" 3 4
extern unsigned int alarm (unsigned int __seconds) ;
# 390 "/usr/include/unistd.h" 3 4
extern unsigned int sleep (unsigned int __seconds);






extern __useconds_t ualarm (__useconds_t __value, __useconds_t __interval)
     ;






extern int usleep (__useconds_t __useconds);
# 414 "/usr/include/unistd.h" 3 4
extern int pause (void);



extern int chown (const char *__file, __uid_t __owner, __gid_t __group)
     ;



extern int fchown (int __fd, __uid_t __owner, __gid_t __group) ;




extern int lchown (const char *__file, __uid_t __owner, __gid_t __group)
     ;




extern int chdir (const char *__path) ;



extern int fchdir (int __fd) ;
# 448 "/usr/include/unistd.h" 3 4
extern char *getcwd (char *__buf, size_t __size) ;





extern char *get_current_dir_name (void) ;






extern char *getwd (char *__buf) ;




extern int dup (int __fd) ;


extern int dup2 (int __fd, int __fd2) ;


extern char **__environ;

extern char **environ;





extern int execve (const char *__path, char *const __argv[],
                   char *const __envp[]) ;




extern int fexecve (int __fd, char *const __argv[], char *const __envp[])
     ;




extern int execv (const char *__path, char *const __argv[]) ;



extern int execle (const char *__path, const char *__arg, ...) ;



extern int execl (const char *__path, const char *__arg, ...) ;



extern int execvp (const char *__file, char *const __argv[]) ;




extern int execlp (const char *__file, const char *__arg, ...) ;




extern int nice (int __inc) ;




extern void _exit (int __status) ;





# 1 "/usr/include/bits/confname.h" 1 3 4
# 25 "/usr/include/bits/confname.h" 3 4
enum
  {
    _PC_LINK_MAX,

    _PC_MAX_CANON,

    _PC_MAX_INPUT,

    _PC_NAME_MAX,

    _PC_PATH_MAX,

    _PC_PIPE_BUF,

    _PC_CHOWN_RESTRICTED,

    _PC_NO_TRUNC,

    _PC_VDISABLE,

    _PC_SYNC_IO,

    _PC_ASYNC_IO,

    _PC_PRIO_IO,

    _PC_SOCK_MAXBUF,

    _PC_FILESIZEBITS,

    _PC_REC_INCR_XFER_SIZE,

    _PC_REC_MAX_XFER_SIZE,

    _PC_REC_MIN_XFER_SIZE,

    _PC_REC_XFER_ALIGN,

    _PC_ALLOC_SIZE_MIN,

    _PC_SYMLINK_MAX,

    _PC_2_SYMLINKS

  };


enum
  {
    _SC_ARG_MAX,

    _SC_CHILD_MAX,

    _SC_CLK_TCK,

    _SC_NGROUPS_MAX,

    _SC_OPEN_MAX,

    _SC_STREAM_MAX,

    _SC_TZNAME_MAX,

    _SC_JOB_CONTROL,

    _SC_SAVED_IDS,

    _SC_REALTIME_SIGNALS,

    _SC_PRIORITY_SCHEDULING,

    _SC_TIMERS,

    _SC_ASYNCHRONOUS_IO,

    _SC_PRIORITIZED_IO,

    _SC_SYNCHRONIZED_IO,

    _SC_FSYNC,

    _SC_MAPPED_FILES,

    _SC_MEMLOCK,

    _SC_MEMLOCK_RANGE,

    _SC_MEMORY_PROTECTION,

    _SC_MESSAGE_PASSING,

    _SC_SEMAPHORES,

    _SC_SHARED_MEMORY_OBJECTS,

    _SC_AIO_LISTIO_MAX,

    _SC_AIO_MAX,

    _SC_AIO_PRIO_DELTA_MAX,

    _SC_DELAYTIMER_MAX,

    _SC_MQ_OPEN_MAX,

    _SC_MQ_PRIO_MAX,

    _SC_VERSION,

    _SC_PAGESIZE,


    _SC_RTSIG_MAX,

    _SC_SEM_NSEMS_MAX,

    _SC_SEM_VALUE_MAX,

    _SC_SIGQUEUE_MAX,

    _SC_TIMER_MAX,




    _SC_BC_BASE_MAX,

    _SC_BC_DIM_MAX,

    _SC_BC_SCALE_MAX,

    _SC_BC_STRING_MAX,

    _SC_COLL_WEIGHTS_MAX,

    _SC_EQUIV_CLASS_MAX,

    _SC_EXPR_NEST_MAX,

    _SC_LINE_MAX,

    _SC_RE_DUP_MAX,

    _SC_CHARCLASS_NAME_MAX,


    _SC_2_VERSION,

    _SC_2_C_BIND,

    _SC_2_C_DEV,

    _SC_2_FORT_DEV,

    _SC_2_FORT_RUN,

    _SC_2_SW_DEV,

    _SC_2_LOCALEDEF,


    _SC_PII,

    _SC_PII_XTI,

    _SC_PII_SOCKET,

    _SC_PII_INTERNET,

    _SC_PII_OSI,

    _SC_POLL,

    _SC_SELECT,

    _SC_UIO_MAXIOV,

    _SC_IOV_MAX = _SC_UIO_MAXIOV,

    _SC_PII_INTERNET_STREAM,

    _SC_PII_INTERNET_DGRAM,

    _SC_PII_OSI_COTS,

    _SC_PII_OSI_CLTS,

    _SC_PII_OSI_M,

    _SC_T_IOV_MAX,



    _SC_THREADS,

    _SC_THREAD_SAFE_FUNCTIONS,

    _SC_GETGR_R_SIZE_MAX,

    _SC_GETPW_R_SIZE_MAX,

    _SC_LOGIN_NAME_MAX,

    _SC_TTY_NAME_MAX,

    _SC_THREAD_DESTRUCTOR_ITERATIONS,

    _SC_THREAD_KEYS_MAX,

    _SC_THREAD_STACK_MIN,

    _SC_THREAD_THREADS_MAX,

    _SC_THREAD_ATTR_STACKADDR,

    _SC_THREAD_ATTR_STACKSIZE,

    _SC_THREAD_PRIORITY_SCHEDULING,

    _SC_THREAD_PRIO_INHERIT,

    _SC_THREAD_PRIO_PROTECT,

    _SC_THREAD_PROCESS_SHARED,


    _SC_NPROCESSORS_CONF,

    _SC_NPROCESSORS_ONLN,

    _SC_PHYS_PAGES,

    _SC_AVPHYS_PAGES,

    _SC_ATEXIT_MAX,

    _SC_PASS_MAX,


    _SC_XOPEN_VERSION,

    _SC_XOPEN_XCU_VERSION,

    _SC_XOPEN_UNIX,

    _SC_XOPEN_CRYPT,

    _SC_XOPEN_ENH_I18N,

    _SC_XOPEN_SHM,


    _SC_2_CHAR_TERM,

    _SC_2_C_VERSION,

    _SC_2_UPE,


    _SC_XOPEN_XPG2,

    _SC_XOPEN_XPG3,

    _SC_XOPEN_XPG4,


    _SC_CHAR_BIT,

    _SC_CHAR_MAX,

    _SC_CHAR_MIN,

    _SC_INT_MAX,

    _SC_INT_MIN,

    _SC_LONG_BIT,

    _SC_WORD_BIT,

    _SC_MB_LEN_MAX,

    _SC_NZERO,

    _SC_SSIZE_MAX,

    _SC_SCHAR_MAX,

    _SC_SCHAR_MIN,

    _SC_SHRT_MAX,

    _SC_SHRT_MIN,

    _SC_UCHAR_MAX,

    _SC_UINT_MAX,

    _SC_ULONG_MAX,

    _SC_USHRT_MAX,


    _SC_NL_ARGMAX,

    _SC_NL_LANGMAX,

    _SC_NL_MSGMAX,

    _SC_NL_NMAX,

    _SC_NL_SETMAX,

    _SC_NL_TEXTMAX,


    _SC_XBS5_ILP32_OFF32,

    _SC_XBS5_ILP32_OFFBIG,

    _SC_XBS5_LP64_OFF64,

    _SC_XBS5_LPBIG_OFFBIG,


    _SC_XOPEN_LEGACY,

    _SC_XOPEN_REALTIME,

    _SC_XOPEN_REALTIME_THREADS,


    _SC_ADVISORY_INFO,

    _SC_BARRIERS,

    _SC_BASE,

    _SC_C_LANG_SUPPORT,

    _SC_C_LANG_SUPPORT_R,

    _SC_CLOCK_SELECTION,

    _SC_CPUTIME,

    _SC_THREAD_CPUTIME,

    _SC_DEVICE_IO,

    _SC_DEVICE_SPECIFIC,

    _SC_DEVICE_SPECIFIC_R,

    _SC_FD_MGMT,

    _SC_FIFO,

    _SC_PIPE,

    _SC_FILE_ATTRIBUTES,

    _SC_FILE_LOCKING,

    _SC_FILE_SYSTEM,

    _SC_MONOTONIC_CLOCK,

    _SC_MULTI_PROCESS,

    _SC_SINGLE_PROCESS,

    _SC_NETWORKING,

    _SC_READER_WRITER_LOCKS,

    _SC_SPIN_LOCKS,

    _SC_REGEXP,

    _SC_REGEX_VERSION,

    _SC_SHELL,

    _SC_SIGNALS,

    _SC_SPAWN,

    _SC_SPORADIC_SERVER,

    _SC_THREAD_SPORADIC_SERVER,

    _SC_SYSTEM_DATABASE,

    _SC_SYSTEM_DATABASE_R,

    _SC_TIMEOUTS,

    _SC_TYPED_MEMORY_OBJECTS,

    _SC_USER_GROUPS,

    _SC_USER_GROUPS_R,

    _SC_2_PBS,

    _SC_2_PBS_ACCOUNTING,

    _SC_2_PBS_LOCATE,

    _SC_2_PBS_MESSAGE,

    _SC_2_PBS_TRACK,

    _SC_SYMLOOP_MAX,

    _SC_STREAMS,

    _SC_2_PBS_CHECKPOINT,


    _SC_V6_ILP32_OFF32,

    _SC_V6_ILP32_OFFBIG,

    _SC_V6_LP64_OFF64,

    _SC_V6_LPBIG_OFFBIG,


    _SC_HOST_NAME_MAX,

    _SC_TRACE,

    _SC_TRACE_EVENT_FILTER,

    _SC_TRACE_INHERIT,

    _SC_TRACE_LOG

  };


enum
  {
    _CS_PATH,


    _CS_V6_WIDTH_RESTRICTED_ENVS,


    _CS_GNU_LIBC_VERSION,

    _CS_GNU_LIBPTHREAD_VERSION,


    _CS_LFS_CFLAGS = 1000,

    _CS_LFS_LDFLAGS,

    _CS_LFS_LIBS,

    _CS_LFS_LINTFLAGS,

    _CS_LFS64_CFLAGS,

    _CS_LFS64_LDFLAGS,

    _CS_LFS64_LIBS,

    _CS_LFS64_LINTFLAGS,


    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,

    _CS_XBS5_ILP32_OFF32_LDFLAGS,

    _CS_XBS5_ILP32_OFF32_LIBS,

    _CS_XBS5_ILP32_OFF32_LINTFLAGS,

    _CS_XBS5_ILP32_OFFBIG_CFLAGS,

    _CS_XBS5_ILP32_OFFBIG_LDFLAGS,

    _CS_XBS5_ILP32_OFFBIG_LIBS,

    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS,

    _CS_XBS5_LP64_OFF64_CFLAGS,

    _CS_XBS5_LP64_OFF64_LDFLAGS,

    _CS_XBS5_LP64_OFF64_LIBS,

    _CS_XBS5_LP64_OFF64_LINTFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_CFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS,

    _CS_XBS5_LPBIG_OFFBIG_LIBS,

    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS,


    _CS_POSIX_V6_ILP32_OFF32_CFLAGS,

    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS,

    _CS_POSIX_V6_ILP32_OFF32_LIBS,

    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS,

    _CS_POSIX_V6_ILP32_OFFBIG_LIBS,

    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS,

    _CS_POSIX_V6_LP64_OFF64_CFLAGS,

    _CS_POSIX_V6_LP64_OFF64_LDFLAGS,

    _CS_POSIX_V6_LP64_OFF64_LIBS,

    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS,

    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS

  };
# 526 "/usr/include/unistd.h" 2 3 4


extern long int pathconf (const char *__path, int __name) ;


extern long int fpathconf (int __fd, int __name) ;


extern long int sysconf (int __name) ;



extern size_t confstr (int __name, char *__buf, size_t __len) ;




extern __pid_t getpid (void) ;


extern __pid_t getppid (void) ;




extern __pid_t getpgrp (void) ;
# 561 "/usr/include/unistd.h" 3 4
extern __pid_t __getpgid (__pid_t __pid) ;

extern __pid_t getpgid (__pid_t __pid) ;






extern int setpgid (__pid_t __pid, __pid_t __pgid) ;
# 587 "/usr/include/unistd.h" 3 4
extern int setpgrp (void) ;
# 605 "/usr/include/unistd.h" 3 4
extern __pid_t setsid (void) ;



extern __pid_t getsid (__pid_t __pid) ;



extern __uid_t getuid (void) ;


extern __uid_t geteuid (void) ;


extern __gid_t getgid (void) ;


extern __gid_t getegid (void) ;




extern int getgroups (int __size, __gid_t __list[]) ;



extern int group_member (__gid_t __gid) ;






extern int setuid (__uid_t __uid) ;




extern int setreuid (__uid_t __ruid, __uid_t __euid) ;




extern int seteuid (__uid_t __uid) ;






extern int setgid (__gid_t __gid) ;




extern int setregid (__gid_t __rgid, __gid_t __egid) ;




extern int setegid (__gid_t __gid) ;





extern int getresuid (__uid_t *__euid, __uid_t *__ruid, __uid_t *__suid);



extern int getresgid (__gid_t *__egid, __gid_t *__rgid, __gid_t *__sgid);



extern int setresuid (__uid_t __euid, __uid_t __ruid, __uid_t __suid);



extern int setresgid (__gid_t __egid, __gid_t __rgid, __gid_t __sgid);






extern __pid_t fork (void) ;






extern __pid_t vfork (void) ;





extern char *ttyname (int __fd) ;



extern int ttyname_r (int __fd, char *__buf, size_t __buflen) ;



extern int isatty (int __fd) ;





extern int ttyslot (void) ;




extern int link (const char *__from, const char *__to) ;



extern int symlink (const char *__from, const char *__to) ;




extern int readlink (const char * __path, char * __buf,
                     size_t __len) ;



extern int unlink (const char *__name) ;


extern int rmdir (const char *__path) ;



extern __pid_t tcgetpgrp (int __fd) ;


extern int tcsetpgrp (int __fd, __pid_t __pgrp_id) ;






extern char *getlogin (void);







extern int getlogin_r (char *__name, size_t __name_len);




extern int setlogin (const char *__name) ;
# 775 "/usr/include/unistd.h" 3 4
# 1 "/usr/include/getopt.h" 1 3 4
# 47 "/usr/include/getopt.h" 3 4
extern char *optarg;
# 61 "/usr/include/getopt.h" 3 4
extern int optind;




extern int opterr;



extern int optopt;
# 145 "/usr/include/getopt.h" 3 4
extern int getopt (int ___argc, char *const *___argv, const char *__shortopts);
# 776 "/usr/include/unistd.h" 2 3 4







extern int gethostname (char *__name, size_t __len) ;






extern int sethostname (const char *__name, size_t __len) ;



extern int sethostid (long int __id) ;





extern int getdomainname (char *__name, size_t __len) ;
extern int setdomainname (const char *__name, size_t __len) ;





extern int vhangup (void) ;


extern int revoke (const char *__file) ;







extern int profil (unsigned short int *__sample_buffer, size_t __size,
                   size_t __offset, unsigned int __scale) ;





extern int acct (const char *__name) ;



extern char *getusershell (void) ;
extern void endusershell (void) ;
extern void setusershell (void) ;





extern int daemon (int __nochdir, int __noclose) ;






extern int chroot (const char *__path) ;



extern char *getpass (const char *__prompt) ;
# 857 "/usr/include/unistd.h" 3 4
extern int fsync (int __fd);






extern long int gethostid (void) ;


extern void sync (void) ;




extern int getpagesize (void) ;




extern int truncate (const char *__file, __off_t __length) ;
# 888 "/usr/include/unistd.h" 3 4
extern int truncate64 (const char *__file, __off64_t __length) ;




extern int ftruncate (int __fd, __off_t __length) ;
# 903 "/usr/include/unistd.h" 3 4
extern int ftruncate64 (int __fd, __off64_t __length) ;





extern int getdtablesize (void) ;
# 918 "/usr/include/unistd.h" 3 4
extern int brk (void *__addr) ;





extern void *sbrk (intptr_t __delta) ;
# 939 "/usr/include/unistd.h" 3 4
extern long int syscall (long int __sysno, ...) ;
# 962 "/usr/include/unistd.h" 3 4
extern int lockf (int __fd, int __cmd, __off_t __len);
# 972 "/usr/include/unistd.h" 3 4
extern int lockf64 (int __fd, int __cmd, __off64_t __len);
# 993 "/usr/include/unistd.h" 3 4
extern int fdatasync (int __fildes) ;







extern char *crypt (const char *__key, const char *__salt) ;



extern void encrypt (char *__block, int __edflag) ;






extern void swab (const void * __from, void * __to,
                  ssize_t __n) ;







extern char *ctermid (char *__s) ;



# 39 "/usr/include/c++/3.3/i486-linux/bits/gthr-default.h" 2 3

typedef pthread_key_t __gthread_key_t;
typedef pthread_once_t __gthread_once_t;
typedef pthread_mutex_t __gthread_mutex_t;
# 96 "/usr/include/c++/3.3/i486-linux/bits/gthr-default.h" 3
static inline int
__gthread_active_p (void)
{
  return 1;
}
# 449 "/usr/include/c++/3.3/i486-linux/bits/gthr-default.h" 3
static inline int
__gthread_once (__gthread_once_t *once, void (*func) (void))
{
  if (__gthread_active_p ())
    return pthread_once (once, func);
  else
    return -1;
}

static inline int
__gthread_key_create (__gthread_key_t *key, void (*dtor) (void *))
{
  return pthread_key_create (key, dtor);
}

static inline int
__gthread_key_dtor (__gthread_key_t key, void *ptr)
{

  if (ptr)
    return pthread_setspecific (key, 0);
  else
    return 0;
}

static inline int
__gthread_key_delete (__gthread_key_t key)
{
  return pthread_key_delete (key);
}

static inline void *
__gthread_getspecific (__gthread_key_t key)
{
  return pthread_getspecific (key);
}

static inline int
__gthread_setspecific (__gthread_key_t key, const void *ptr)
{
  return pthread_setspecific (key, ptr);
}

static inline int
__gthread_mutex_lock (__gthread_mutex_t *mutex)
{
  if (__gthread_active_p ())
    return pthread_mutex_lock (mutex);
  else
    return 0;
}

static inline int
__gthread_mutex_trylock (__gthread_mutex_t *mutex)
{
  if (__gthread_active_p ())
    return pthread_mutex_trylock (mutex);
  else
    return 0;
}

static inline int
__gthread_mutex_unlock (__gthread_mutex_t *mutex)
{
  if (__gthread_active_p ())
    return pthread_mutex_unlock (mutex);
  else
    return 0;
}
# 99 "/usr/include/c++/3.3/i486-linux/bits/gthr.h" 2 3
# 38 "/usr/include/c++/3.3/i486-linux/bits/c++io.h" 2 3

namespace std
{

  typedef long streamoff;
  typedef ptrdiff_t streamsize;

  typedef ptrdiff_t wstreamsize;

  typedef fpos_t __c_streampos;

  typedef __gthread_mutex_t __c_lock;


  typedef FILE __c_file;


  struct __ios_flags
  {
    typedef short __int_type;

    static const __int_type _S_boolalpha = 0x0001;
    static const __int_type _S_dec = 0x0002;
    static const __int_type _S_fixed = 0x0004;
    static const __int_type _S_hex = 0x0008;
    static const __int_type _S_internal = 0x0010;
    static const __int_type _S_left = 0x0020;
    static const __int_type _S_oct = 0x0040;
    static const __int_type _S_right = 0x0080;
    static const __int_type _S_scientific = 0x0100;
    static const __int_type _S_showbase = 0x0200;
    static const __int_type _S_showpoint = 0x0400;
    static const __int_type _S_showpos = 0x0800;
    static const __int_type _S_skipws = 0x1000;
    static const __int_type _S_unitbuf = 0x2000;
    static const __int_type _S_uppercase = 0x4000;
    static const __int_type _S_adjustfield = 0x0020 | 0x0080 | 0x0010;
    static const __int_type _S_basefield = 0x0002 | 0x0040 | 0x0008;
    static const __int_type _S_floatfield = 0x0100 | 0x0004;


    static const __int_type _S_badbit = 0x01;
    static const __int_type _S_eofbit = 0x02;
    static const __int_type _S_failbit = 0x04;


    static const __int_type _S_app = 0x01;
    static const __int_type _S_ate = 0x02;
    static const __int_type _S_bin = 0x04;
    static const __int_type _S_in = 0x08;
    static const __int_type _S_out = 0x10;
    static const __int_type _S_trunc = 0x20;
  };
}
# 45 "/usr/include/c++/3.3/bits/fpos.h" 2 3
# 1 "/usr/include/c++/3.3/cwchar" 1 3
# 47 "/usr/include/c++/3.3/cwchar" 3
       
# 48 "/usr/include/c++/3.3/cwchar" 3



# 1 "/usr/include/c++/3.3/ctime" 1 3
# 47 "/usr/include/c++/3.3/ctime" 3
       
# 48 "/usr/include/c++/3.3/ctime" 3
# 64 "/usr/include/c++/3.3/ctime" 3
namespace std
{
  using ::clock_t;
  using ::time_t;
  using ::tm;

  using ::clock;
  using ::difftime;
  using ::mktime;
  using ::time;
  using ::asctime;
  using ::ctime;
  using ::gmtime;
  using ::localtime;
  using ::strftime;
}
# 52 "/usr/include/c++/3.3/cwchar" 2 3


# 1 "/usr/include/wchar.h" 1 3 4
# 48 "/usr/include/wchar.h" 3 4
# 1 "/usr/lib/gcc-lib/i486-linux/3.3.2/include/stddef.h" 1 3 4
# 49 "/usr/include/wchar.h" 2 3 4
# 93 "/usr/include/wchar.h" 3 4


typedef __mbstate_t mbstate_t;



# 118 "/usr/include/wchar.h" 3 4





struct tm;









extern wchar_t *wcscpy (wchar_t * __dest,
                        const wchar_t * __src) ;

extern wchar_t *wcsncpy (wchar_t * __dest,
                         const wchar_t * __src, size_t __n)
     ;


extern wchar_t *wcscat (wchar_t * __dest,
                        const wchar_t * __src) ;

extern wchar_t *wcsncat (wchar_t * __dest,
                         const wchar_t * __src, size_t __n)
     ;


extern int wcscmp (const wchar_t *__s1, const wchar_t *__s2)
     ;

extern int wcsncmp (const wchar_t *__s1, const wchar_t *__s2, size_t __n)
     ;




extern int wcscasecmp (const wchar_t *__s1, const wchar_t *__s2) ;


extern int wcsncasecmp (const wchar_t *__s1, const wchar_t *__s2,
                        size_t __n) ;





extern int wcscasecmp_l (const wchar_t *__s1, const wchar_t *__s2,
                         __locale_t __loc) ;

extern int wcsncasecmp_l (const wchar_t *__s1, const wchar_t *__s2,
                          size_t __n, __locale_t __loc) ;





extern int wcscoll (const wchar_t *__s1, const wchar_t *__s2) ;



extern size_t wcsxfrm (wchar_t * __s1,
                       const wchar_t * __s2, size_t __n) ;








extern int wcscoll_l (const wchar_t *__s1, const wchar_t *__s2,
                      __locale_t __loc) ;




extern size_t wcsxfrm_l (wchar_t *__s1, const wchar_t *__s2,
                         size_t __n, __locale_t __loc) ;


extern wchar_t *wcsdup (const wchar_t *__s) ;




extern wchar_t *wcschr (const wchar_t *__wcs, wchar_t __wc)
     ;

extern wchar_t *wcsrchr (const wchar_t *__wcs, wchar_t __wc)
     ;





extern wchar_t *wcschrnul (const wchar_t *__s, wchar_t __wc)
     ;





extern size_t wcscspn (const wchar_t *__wcs, const wchar_t *__reject)
     ;


extern size_t wcsspn (const wchar_t *__wcs, const wchar_t *__accept)
     ;

extern wchar_t *wcspbrk (const wchar_t *__wcs, const wchar_t *__accept)
     ;

extern wchar_t *wcsstr (const wchar_t *__haystack, const wchar_t *__needle)
     ;


extern wchar_t *wcstok (wchar_t * __s,
                        const wchar_t * __delim,
                        wchar_t ** __ptr) ;


extern size_t wcslen (const wchar_t *__s) ;




extern wchar_t *wcswcs (const wchar_t *__haystack, const wchar_t *__needle)
     ;




extern size_t wcsnlen (const wchar_t *__s, size_t __maxlen)
     ;





extern wchar_t *wmemchr (const wchar_t *__s, wchar_t __c, size_t __n)
     ;


extern int wmemcmp (const wchar_t * __s1,
                    const wchar_t * __s2, size_t __n)
     ;


extern wchar_t *wmemcpy (wchar_t * __s1,
                         const wchar_t * __s2, size_t __n) ;



extern wchar_t *wmemmove (wchar_t *__s1, const wchar_t *__s2, size_t __n)
     ;


extern wchar_t *wmemset (wchar_t *__s, wchar_t __c, size_t __n) ;





extern wchar_t *wmempcpy (wchar_t * __s1,
                          const wchar_t * __s2, size_t __n)
     ;






extern wint_t btowc (int __c) ;



extern int wctob (wint_t __c) ;



extern int mbsinit (const mbstate_t *__ps) ;



extern size_t mbrtowc (wchar_t * __pwc,
                       const char * __s, size_t __n,
                       mbstate_t *__p) ;


extern size_t wcrtomb (char * __s, wchar_t __wc,
                       mbstate_t * __ps) ;


extern size_t __mbrlen (const char * __s, size_t __n,
                        mbstate_t * __ps) ;
extern size_t mbrlen (const char * __s, size_t __n,
                      mbstate_t * __ps) ;

# 329 "/usr/include/wchar.h" 3 4



extern size_t mbsrtowcs (wchar_t * __dst,
                         const char ** __src, size_t __len,
                         mbstate_t * __ps) ;



extern size_t wcsrtombs (char * __dst,
                         const wchar_t ** __src, size_t __len,
                         mbstate_t * __ps) ;






extern size_t mbsnrtowcs (wchar_t * __dst,
                          const char ** __src, size_t __nmc,
                          size_t __len, mbstate_t * __ps) ;



extern size_t wcsnrtombs (char * __dst,
                          const wchar_t ** __src,
                          size_t __nwc, size_t __len,
                          mbstate_t * __ps) ;






extern int wcwidth (wchar_t __c) ;



extern int wcswidth (const wchar_t *__s, size_t __n) ;






extern double wcstod (const wchar_t * __nptr,
                      wchar_t ** __endptr) ;



extern float wcstof (const wchar_t * __nptr,
                     wchar_t ** __endptr) ;
extern long double wcstold (const wchar_t * __nptr,
                            wchar_t ** __endptr) ;





extern long int wcstol (const wchar_t * __nptr,
                        wchar_t ** __endptr, int __base) ;



extern unsigned long int wcstoul (const wchar_t * __nptr,
                                  wchar_t ** __endptr, int __base)
     ;





extern long long int wcstoll (const wchar_t * __nptr,
                              wchar_t ** __endptr, int __base)
     ;




extern unsigned long long int wcstoull (const wchar_t * __nptr,
                                        wchar_t ** __endptr,
                                        int __base) ;


# 448 "/usr/include/wchar.h" 3 4
extern long int wcstol_l (const wchar_t * __nptr,
                          wchar_t ** __endptr, int __base,
                          __locale_t __loc) ;

extern unsigned long int wcstoul_l (const wchar_t * __nptr,
                                    wchar_t ** __endptr,
                                    int __base, __locale_t __loc) ;


extern long long int wcstoll_l (const wchar_t * __nptr,
                                wchar_t ** __endptr,
                                int __base, __locale_t __loc) ;


extern unsigned long long int wcstoull_l (const wchar_t * __nptr,
                                          wchar_t ** __endptr,
                                          int __base, __locale_t __loc)
     ;

extern double wcstod_l (const wchar_t * __nptr,
                        wchar_t ** __endptr, __locale_t __loc)
     ;

extern float wcstof_l (const wchar_t * __nptr,
                       wchar_t ** __endptr, __locale_t __loc)
     ;

extern long double wcstold_l (const wchar_t * __nptr,
                              wchar_t ** __endptr,
                              __locale_t __loc) ;





extern double __wcstod_internal (const wchar_t * __nptr,
                                 wchar_t ** __endptr, int __group)
     ;
extern float __wcstof_internal (const wchar_t * __nptr,
                                wchar_t ** __endptr, int __group)
     ;
extern long double __wcstold_internal (const wchar_t * __nptr,
                                       wchar_t ** __endptr,
                                       int __group) ;


extern long int __wcstol_internal (const wchar_t * __nptr,
                                   wchar_t ** __endptr,
                                   int __base, int __group) ;



extern unsigned long int __wcstoul_internal (const wchar_t * __npt,
                                             wchar_t ** __endptr,
                                             int __base, int __group) ;




extern long long int __wcstoll_internal (const wchar_t * __nptr,
                                         wchar_t ** __endptr,
                                         int __base, int __group) ;




extern unsigned long long int __wcstoull_internal (const wchar_t *
                                                   __nptr,
                                                   wchar_t **
                                                   __endptr,
                                                   int __base,
                                                   int __group) ;
# 568 "/usr/include/wchar.h" 3 4
extern wchar_t *wcpcpy (wchar_t *__dest, const wchar_t *__src) ;



extern wchar_t *wcpncpy (wchar_t *__dest, const wchar_t *__src, size_t __n)
     ;








extern int fwide (__FILE *__fp, int __mode) ;






extern int fwprintf (__FILE * __stream,
                     const wchar_t * __format, ...)
                                                           ;




extern int wprintf (const wchar_t * __format, ...)
                                                           ;

extern int swprintf (wchar_t * __s, size_t __n,
                     const wchar_t * __format, ...)
     ;





extern int vfwprintf (__FILE * __s,
                      const wchar_t * __format,
                      __gnuc_va_list __arg)
                                                           ;




extern int vwprintf (const wchar_t * __format,
                     __gnuc_va_list __arg)
                                                           ;


extern int vswprintf (wchar_t * __s, size_t __n,
                      const wchar_t * __format,
                      __gnuc_va_list __arg)
     ;






extern int fwscanf (__FILE * __stream,
                    const wchar_t * __format, ...)
                                                          ;




extern int wscanf (const wchar_t * __format, ...)
                                                          ;

extern int swscanf (const wchar_t * __s,
                    const wchar_t * __format, ...)
     ;











extern int vfwscanf (__FILE * __s,
                     const wchar_t * __format,
                     __gnuc_va_list __arg)
                                                          ;




extern int vwscanf (const wchar_t * __format,
                    __gnuc_va_list __arg)
                                                          ;

extern int vswscanf (const wchar_t * __s,
                     const wchar_t * __format,
                     __gnuc_va_list __arg)
     ;










extern wint_t fgetwc (__FILE *__stream);
extern wint_t getwc (__FILE *__stream);





extern wint_t getwchar (void);






extern wint_t fputwc (wchar_t __wc, __FILE *__stream);
extern wint_t putwc (wchar_t __wc, __FILE *__stream);





extern wint_t putwchar (wchar_t __wc);







extern wchar_t *fgetws (wchar_t * __ws, int __n,
                        __FILE * __stream);





extern int fputws (const wchar_t * __ws,
                   __FILE * __stream);






extern wint_t ungetwc (wint_t __wc, __FILE *__stream);

# 736 "/usr/include/wchar.h" 3 4
extern wint_t getwc_unlocked (__FILE *__stream);
extern wint_t getwchar_unlocked (void);







extern wint_t fgetwc_unlocked (__FILE *__stream);







extern wint_t fputwc_unlocked (wchar_t __wc, __FILE *__stream);
# 762 "/usr/include/wchar.h" 3 4
extern wint_t putwc_unlocked (wchar_t __wc, __FILE *__stream);
extern wint_t putwchar_unlocked (wchar_t __wc);
# 772 "/usr/include/wchar.h" 3 4
extern wchar_t *fgetws_unlocked (wchar_t * __ws, int __n,
                                 __FILE * __stream);







extern int fputws_unlocked (const wchar_t * __ws,
                            __FILE * __stream);







extern size_t wcsftime (wchar_t * __s, size_t __maxsize,
                        const wchar_t * __format,
                        const struct tm * __tp) ;







extern size_t wcsftime_l (wchar_t * __s, size_t __maxsize,
                          const wchar_t * __format,
                          const struct tm * __tp,
                          __locale_t __loc) ;
# 817 "/usr/include/wchar.h" 3 4

# 55 "/usr/include/c++/3.3/cwchar" 2 3
# 69 "/usr/include/c++/3.3/cwchar" 3
namespace std
{
  using ::mbstate_t;
}
# 133 "/usr/include/c++/3.3/cwchar" 3
namespace std
{
  using ::wint_t;

  using ::btowc;
  using ::fgetwc;
  using ::fgetws;
  using ::fputwc;
  using ::fputws;
  using ::fwide;
  using ::fwprintf;
  using ::fwscanf;
  using ::getwc;
  using ::getwchar;
  using ::mbrlen;
  using ::mbrtowc;
  using ::mbsinit;
  using ::mbsrtowcs;
  using ::putwc;
  using ::putwchar;
  using ::swprintf;
  using ::swscanf;
  using ::ungetwc;
  using ::vfwprintf;
  using ::vfwscanf;
  using ::vswprintf;
  using ::vswscanf;
  using ::vwprintf;
  using ::vwscanf;
  using ::wcrtomb;
  using ::wcscat;
  using ::wcscmp;
  using ::wcscoll;
  using ::wcscpy;
  using ::wcscspn;
  using ::wcsftime;
  using ::wcslen;
  using ::wcsncat;
  using ::wcsncmp;
  using ::wcsncpy;
  using ::wcsrtombs;
  using ::wcsspn;
  using ::wcstod;
  using ::wcstof;
  using ::wcstok;
  using ::wcstol;
  using ::wcstoul;
  using ::wcsxfrm;
  using ::wctob;
  using ::wmemcmp;
  using ::wmemcpy;
  using ::wmemmove;
  using ::wmemset;
  using ::wprintf;
  using ::wscanf;

  using ::wcschr;

  inline wchar_t*
  wcschr(wchar_t* __p, wchar_t __c)
  { return wcschr(const_cast<const wchar_t*>(__p), __c); }

  using ::wcspbrk;

  inline wchar_t*
  wcspbrk(wchar_t* __s1, wchar_t* __s2)
  { return wcspbrk(const_cast<const wchar_t*>(__s1), __s2); }

  using ::wcsrchr;

  inline wchar_t*
  wcsrchr(wchar_t* __p, wchar_t __c)
  { return wcsrchr(const_cast<const wchar_t*>(__p), __c); }

  using ::wcsstr;

  inline wchar_t*
  wcsstr(wchar_t* __s1, wchar_t* __s2)
  { return wcsstr(const_cast<const wchar_t*>(__s1), __s2); }

  using ::wmemchr;

  inline wchar_t*
  wmemchr(wchar_t* __p, wchar_t __c, size_t __n)
  { return wmemchr(const_cast<const wchar_t*>(__p), __c, __n); }
}







namespace __gnu_cxx
{





  using ::wcstold;
# 242 "/usr/include/c++/3.3/cwchar" 3
  using ::wcstoll;
  using ::wcstoull;

}

namespace std
{
  using __gnu_cxx::wcstold;
  using __gnu_cxx::wcstoll;
  using __gnu_cxx::wcstoull;
}
# 46 "/usr/include/c++/3.3/bits/fpos.h" 2 3

namespace std
{






  template<typename _StateT>
    class fpos
    {
    public:

      typedef _StateT __state_type;

    private:
      streamoff _M_off;
      __state_type _M_st;

    public:
      __state_type
      state() const { return _M_st; }

      void
      state(__state_type __st) { _M_st = __st; }



      fpos(): _M_off(streamoff()), _M_st(__state_type()) { }

      fpos(streamoff __off, __state_type __st = __state_type())
      : _M_off(__off), _M_st(__st) { }

      operator streamoff() const { return _M_off; }

      fpos&
      operator+=(streamoff __off) { _M_off += __off; return *this; }

      fpos&
      operator-=(streamoff __off) { _M_off -= __off; return *this; }

      fpos
      operator+(streamoff __off)
      {
        fpos __t(*this);
        __t += __off;
        return __t;
      }

      fpos
      operator-(streamoff __off)
      {
        fpos __t(*this);
        __t -= __off;
        return __t;
      }

      bool
      operator==(const fpos& __pos) const
      { return _M_off == __pos._M_off; }

      bool
      operator!=(const fpos& __pos) const
      { return _M_off != __pos._M_off; }

      streamoff
      _M_position() const { return _M_off; }

      void
      _M_position(streamoff __off) { _M_off = __off; }
    };


  typedef fpos<mbstate_t> streampos;


  typedef fpos<mbstate_t> wstreampos;

}
# 50 "/usr/include/c++/3.3/iosfwd" 2 3
# 1 "/usr/include/c++/3.3/bits/functexcept.h" 1 3
# 34 "/usr/include/c++/3.3/bits/functexcept.h" 3
# 1 "/usr/include/c++/3.3/exception_defines.h" 1 3
# 35 "/usr/include/c++/3.3/bits/functexcept.h" 2 3

namespace std
{

  void
  __throw_bad_exception(void);


  void
  __throw_bad_alloc(void);


  void
  __throw_bad_cast(void);

  void
  __throw_bad_typeid(void);


  void
  __throw_logic_error(const char* __s);

  void
  __throw_domain_error(const char* __s);

  void
  __throw_invalid_argument(const char* __s);

  void
  __throw_length_error(const char* __s);

  void
  __throw_out_of_range(const char* __s);

  void
  __throw_runtime_error(const char* __s);

  void
  __throw_range_error(const char* __s);

  void
  __throw_overflow_error(const char* __s);

  void
  __throw_underflow_error(const char* __s);


  void
  __throw_ios_failure(const char* __s);
}
# 51 "/usr/include/c++/3.3/iosfwd" 2 3

namespace std
{
  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_ios;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_streambuf;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_istream;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_ostream;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_iostream;

  template<typename _CharT, typename _Traits = char_traits<_CharT>,
            typename _Alloc = allocator<_CharT> >
    class basic_stringbuf;

  template<typename _CharT, typename _Traits = char_traits<_CharT>,
           typename _Alloc = allocator<_CharT> >
    class basic_istringstream;

  template<typename _CharT, typename _Traits = char_traits<_CharT>,
           typename _Alloc = allocator<_CharT> >
    class basic_ostringstream;

  template<typename _CharT, typename _Traits = char_traits<_CharT>,
           typename _Alloc = allocator<_CharT> >
    class basic_stringstream;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_filebuf;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_ifstream;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_ofstream;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_fstream;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class istreambuf_iterator;

  template<typename _CharT, typename _Traits = char_traits<_CharT> >
    class ostreambuf_iterator;



  class ios_base;
# 136 "/usr/include/c++/3.3/iosfwd" 3
  typedef basic_ios<char> ios;
  typedef basic_streambuf<char> streambuf;
  typedef basic_istream<char> istream;
  typedef basic_ostream<char> ostream;
  typedef basic_iostream<char> iostream;
  typedef basic_stringbuf<char> stringbuf;
  typedef basic_istringstream<char> istringstream;
  typedef basic_ostringstream<char> ostringstream;
  typedef basic_stringstream<char> stringstream;
  typedef basic_filebuf<char> filebuf;
  typedef basic_ifstream<char> ifstream;
  typedef basic_ofstream<char> ofstream;
  typedef basic_fstream<char> fstream;


  typedef basic_ios<wchar_t> wios;
  typedef basic_streambuf<wchar_t> wstreambuf;
  typedef basic_istream<wchar_t> wistream;
  typedef basic_ostream<wchar_t> wostream;
  typedef basic_iostream<wchar_t> wiostream;
  typedef basic_stringbuf<wchar_t> wstringbuf;
  typedef basic_istringstream<wchar_t> wistringstream;
  typedef basic_ostringstream<wchar_t> wostringstream;
  typedef basic_stringstream<wchar_t> wstringstream;
  typedef basic_filebuf<wchar_t> wfilebuf;
  typedef basic_ifstream<wchar_t> wifstream;
  typedef basic_ofstream<wchar_t> wofstream;
  typedef basic_fstream<wchar_t> wfstream;


}
# 71 "/usr/include/c++/3.3/bits/stl_algobase.h" 2 3
# 1 "/usr/include/c++/3.3/bits/stl_pair.h" 1 3
# 64 "/usr/include/c++/3.3/bits/stl_pair.h" 3
namespace std
{


template <class _T1, class _T2>
struct pair {
  typedef _T1 first_type;
  typedef _T2 second_type;

  _T1 first;
  _T2 second;




  pair() : first(), second() {}




  pair(const _T1& __a, const _T2& __b) : first(__a), second(__b) {}


  template <class _U1, class _U2>
  pair(const pair<_U1, _U2>& __p) : first(__p.first), second(__p.second) {}
};


template <class _T1, class _T2>
inline bool operator==(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
{
  return __x.first == __y.first && __x.second == __y.second;
}


template <class _T1, class _T2>
inline bool operator<(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y)
{
  return __x.first < __y.first ||
         (!(__y.first < __x.first) && __x.second < __y.second);
}


template <class _T1, class _T2>
inline bool operator!=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
  return !(__x == __y);
}


template <class _T1, class _T2>
inline bool operator>(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
  return __y < __x;
}


template <class _T1, class _T2>
inline bool operator<=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
  return !(__y < __x);
}


template <class _T1, class _T2>
inline bool operator>=(const pair<_T1, _T2>& __x, const pair<_T1, _T2>& __y) {
  return !(__x < __y);
}
# 140 "/usr/include/c++/3.3/bits/stl_pair.h" 3
template <class _T1, class _T2>


inline pair<_T1, _T2> make_pair(_T1 __x, _T2 __y)



{
  return pair<_T1, _T2>(__x, __y);
}

}
# 72 "/usr/include/c++/3.3/bits/stl_algobase.h" 2 3
# 1 "/usr/include/c++/3.3/bits/type_traits.h" 1 3
# 52 "/usr/include/c++/3.3/bits/type_traits.h" 3
       
# 53 "/usr/include/c++/3.3/bits/type_traits.h" 3
# 90 "/usr/include/c++/3.3/bits/type_traits.h" 3
struct __true_type {};
struct __false_type {};

template <class _Tp>
struct __type_traits {
   typedef __true_type this_dummy_member_must_be_first;
# 113 "/usr/include/c++/3.3/bits/type_traits.h" 3
   typedef __false_type has_trivial_default_constructor;
   typedef __false_type has_trivial_copy_constructor;
   typedef __false_type has_trivial_assignment_operator;
   typedef __false_type has_trivial_destructor;
   typedef __false_type is_POD_type;
};




template<> struct __type_traits<bool> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<char> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<signed char> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<unsigned char> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<wchar_t> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<short> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<unsigned short> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<int> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<unsigned int> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<long> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<unsigned long> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<long long> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<unsigned long long> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<float> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<double> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template<> struct __type_traits<long double> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};

template <class _Tp>
struct __type_traits<_Tp*> {
   typedef __true_type has_trivial_default_constructor;
   typedef __true_type has_trivial_copy_constructor;
   typedef __true_type has_trivial_assignment_operator;
   typedef __true_type has_trivial_destructor;
   typedef __true_type is_POD_type;
};





template <class _Tp> struct _Is_integer {
  typedef __false_type _Integral;
};

template<> struct _Is_integer<bool> {
  typedef __true_type _Integral;
};

template<> struct _Is_integer<char> {
  typedef __true_type _Integral;
};

template<> struct _Is_integer<signed char> {
  typedef __true_type _Integral;
};

template<> struct _Is_integer<unsigned char> {
  typedef __true_type _Integral;
};

template<> struct _Is_integer<wchar_t> {
  typedef __true_type _Integral;
};

template<> struct _Is_integer<short> {
  typedef __true_type _Integral;
};

template<> struct _Is_integer<unsigned short> {
  typedef __true_type _Integral;
};

template<> struct _Is_integer<int> {
  typedef __true_type _Integral;
};

template<> struct _Is_integer<unsigned int> {
  typedef __true_type _Integral;
};

template<> struct _Is_integer<long> {
  typedef __true_type _Integral;
};

template<> struct _Is_integer<unsigned long> {
  typedef __true_type _Integral;
};

template<> struct _Is_integer<long long> {
  typedef __true_type _Integral;
};

template<> struct _Is_integer<unsigned long long> {
  typedef __true_type _Integral;
};

template<typename _Tp> struct _Is_normal_iterator {
   typedef __false_type _Normal;
};


namespace __gnu_cxx
{
  template<typename _Iterator, typename _Container> class __normal_iterator;
}

template<typename _Iterator, typename _Container>
struct _Is_normal_iterator< __gnu_cxx::__normal_iterator<_Iterator, _Container> > {
   typedef __true_type _Normal;
};
# 73 "/usr/include/c++/3.3/bits/stl_algobase.h" 2 3
# 1 "/usr/include/c++/3.3/bits/stl_iterator_base_types.h" 1 3
# 67 "/usr/include/c++/3.3/bits/stl_iterator_base_types.h" 3
       
# 68 "/usr/include/c++/3.3/bits/stl_iterator_base_types.h" 3

namespace std
{
# 80 "/usr/include/c++/3.3/bits/stl_iterator_base_types.h" 3
  struct input_iterator_tag {};

  struct output_iterator_tag {};

  struct forward_iterator_tag : public input_iterator_tag {};

  struct bidirectional_iterator_tag : public forward_iterator_tag {};

  struct random_access_iterator_tag : public bidirectional_iterator_tag {};
# 102 "/usr/include/c++/3.3/bits/stl_iterator_base_types.h" 3
  template<typename _Category, typename _Tp, typename _Distance = ptrdiff_t,
           typename _Pointer = _Tp*, typename _Reference = _Tp&>
    struct iterator
    {

      typedef _Category iterator_category;

      typedef _Tp value_type;

      typedef _Distance difference_type;

      typedef _Pointer pointer;

      typedef _Reference reference;
    };







  template<typename _Iterator>
    struct iterator_traits {
      typedef typename _Iterator::iterator_category iterator_category;
      typedef typename _Iterator::value_type value_type;
      typedef typename _Iterator::difference_type difference_type;
      typedef typename _Iterator::pointer pointer;
      typedef typename _Iterator::reference reference;
    };

  template<typename _Tp>
    struct iterator_traits<_Tp*> {
      typedef random_access_iterator_tag iterator_category;
      typedef _Tp value_type;
      typedef ptrdiff_t difference_type;
      typedef _Tp* pointer;
      typedef _Tp& reference;
    };

  template<typename _Tp>
    struct iterator_traits<const _Tp*> {
      typedef random_access_iterator_tag iterator_category;
      typedef _Tp value_type;
      typedef ptrdiff_t difference_type;
      typedef const _Tp* pointer;
      typedef const _Tp& reference;
    };







  template<typename _Iter>
    inline typename iterator_traits<_Iter>::iterator_category
    __iterator_category(const _Iter&)
    { return typename iterator_traits<_Iter>::iterator_category(); }

}
# 74 "/usr/include/c++/3.3/bits/stl_algobase.h" 2 3
# 1 "/usr/include/c++/3.3/bits/stl_iterator_base_funcs.h" 1 3
# 67 "/usr/include/c++/3.3/bits/stl_iterator_base_funcs.h" 3
       
# 68 "/usr/include/c++/3.3/bits/stl_iterator_base_funcs.h" 3
# 1 "/usr/include/c++/3.3/bits/concept_check.h" 1 3
# 38 "/usr/include/c++/3.3/bits/concept_check.h" 3
       
# 39 "/usr/include/c++/3.3/bits/concept_check.h" 3
# 69 "/usr/include/c++/3.3/bits/stl_iterator_base_funcs.h" 2 3

namespace std
{
  template<typename _InputIterator>
    inline typename iterator_traits<_InputIterator>::difference_type
    __distance(_InputIterator __first, _InputIterator __last,
               input_iterator_tag)
    {

     

      typename iterator_traits<_InputIterator>::difference_type __n = 0;
      while (__first != __last) {
        ++__first; ++__n;
      }
      return __n;
    }

  template<typename _RandomAccessIterator>
    inline typename iterator_traits<_RandomAccessIterator>::difference_type
    __distance(_RandomAccessIterator __first, _RandomAccessIterator __last,
               random_access_iterator_tag)
    {

     
      return __last - __first;
    }
# 109 "/usr/include/c++/3.3/bits/stl_iterator_base_funcs.h" 3
  template<typename _InputIterator>
    inline typename iterator_traits<_InputIterator>::difference_type
    distance(_InputIterator __first, _InputIterator __last)
    {

      return __distance(__first, __last, __iterator_category(__first));
    }

  template<typename _InputIter, typename _Distance>
    inline void
    __advance(_InputIter& __i, _Distance __n, input_iterator_tag)
    {

     
      while (__n--) ++__i;
    }

  template<typename _BidirectionalIterator, typename _Distance>
    inline void
    __advance(_BidirectionalIterator& __i, _Distance __n,
              bidirectional_iterator_tag)
    {

     

      if (__n > 0)
        while (__n--) ++__i;
      else
        while (__n++) --__i;
    }

  template<typename _RandomAccessIterator, typename _Distance>
    inline void
    __advance(_RandomAccessIterator& __i, _Distance __n,
              random_access_iterator_tag)
    {

     
      __i += __n;
    }
# 162 "/usr/include/c++/3.3/bits/stl_iterator_base_funcs.h" 3
  template<typename _InputIterator, typename _Distance>
    inline void
    advance(_InputIterator& __i, _Distance __n)
    {

      __advance(__i, __n, __iterator_category(__i));
    }
}
# 75 "/usr/include/c++/3.3/bits/stl_algobase.h" 2 3
# 1 "/usr/include/c++/3.3/bits/stl_iterator.h" 1 3
# 68 "/usr/include/c++/3.3/bits/stl_iterator.h" 3
namespace std
{
# 89 "/usr/include/c++/3.3/bits/stl_iterator.h" 3
  template<typename _Iterator>
    class reverse_iterator
    : public iterator<typename iterator_traits<_Iterator>::iterator_category,
                      typename iterator_traits<_Iterator>::value_type,
                      typename iterator_traits<_Iterator>::difference_type,
                      typename iterator_traits<_Iterator>::pointer,
                      typename iterator_traits<_Iterator>::reference>
    {
    protected:
      _Iterator current;

    public:
      typedef _Iterator iterator_type;
      typedef typename iterator_traits<_Iterator>::difference_type
                                                               difference_type;
      typedef typename iterator_traits<_Iterator>::reference reference;
      typedef typename iterator_traits<_Iterator>::pointer pointer;

    public:






      reverse_iterator() : current() { }




      explicit
      reverse_iterator(iterator_type __x) : current(__x) { }




      reverse_iterator(const reverse_iterator& __x)
      : current(__x.current) { }





      template<typename _Iter>
        reverse_iterator(const reverse_iterator<_Iter>& __x)
        : current(__x.base()) { }




      iterator_type
      base() const { return current; }






      reference
      operator*() const
      {
        _Iterator __tmp = current;
        return *--__tmp;
      }






      pointer
      operator->() const { return &(operator*()); }






      reverse_iterator&
      operator++()
      {
        --current;
        return *this;
      }






      reverse_iterator
      operator++(int)
      {
        reverse_iterator __tmp = *this;
        --current;
        return __tmp;
      }






      reverse_iterator&
      operator--()
      {
        ++current;
        return *this;
      }






      reverse_iterator operator--(int)
      {
        reverse_iterator __tmp = *this;
        ++current;
        return __tmp;
      }






      reverse_iterator
      operator+(difference_type __n) const
      { return reverse_iterator(current - __n); }






      reverse_iterator&
      operator+=(difference_type __n)
      {
        current -= __n;
        return *this;
      }






      reverse_iterator
      operator-(difference_type __n) const
      { return reverse_iterator(current + __n); }






      reverse_iterator&
      operator-=(difference_type __n)
      {
        current += __n;
        return *this;
      }






      reference
      operator[](difference_type __n) const { return *(*this + __n); }
    };
# 272 "/usr/include/c++/3.3/bits/stl_iterator.h" 3
  template<typename _Iterator>
    inline bool
    operator==(const reverse_iterator<_Iterator>& __x,
               const reverse_iterator<_Iterator>& __y)
    { return __x.base() == __y.base(); }

  template<typename _Iterator>
    inline bool
    operator<(const reverse_iterator<_Iterator>& __x,
              const reverse_iterator<_Iterator>& __y)
    { return __y.base() < __x.base(); }

  template<typename _Iterator>
    inline bool
    operator!=(const reverse_iterator<_Iterator>& __x,
               const reverse_iterator<_Iterator>& __y)
    { return !(__x == __y); }

  template<typename _Iterator>
    inline bool
    operator>(const reverse_iterator<_Iterator>& __x,
              const reverse_iterator<_Iterator>& __y)
    { return __y < __x; }

  template<typename _Iterator>
    inline bool
    operator<=(const reverse_iterator<_Iterator>& __x,
                const reverse_iterator<_Iterator>& __y)
    { return !(__y < __x); }

  template<typename _Iterator>
    inline bool
    operator>=(const reverse_iterator<_Iterator>& __x,
               const reverse_iterator<_Iterator>& __y)
    { return !(__x < __y); }

  template<typename _Iterator>
    inline typename reverse_iterator<_Iterator>::difference_type
    operator-(const reverse_iterator<_Iterator>& __x,
              const reverse_iterator<_Iterator>& __y)
    { return __y.base() - __x.base(); }

  template<typename _Iterator>
    inline reverse_iterator<_Iterator>
    operator+(typename reverse_iterator<_Iterator>::difference_type __n,
              const reverse_iterator<_Iterator>& __x)
    { return reverse_iterator<_Iterator>(__x.base() - __n); }
# 332 "/usr/include/c++/3.3/bits/stl_iterator.h" 3
  template<typename _Container>
    class back_insert_iterator
    : public iterator<output_iterator_tag, void, void, void, void>
    {
    protected:
      _Container* container;

    public:

      typedef _Container container_type;


      explicit
      back_insert_iterator(_Container& __x) : container(&__x) { }
# 358 "/usr/include/c++/3.3/bits/stl_iterator.h" 3
      back_insert_iterator&
      operator=(typename _Container::const_reference __value)
      {
        container->push_back(__value);
        return *this;
      }


      back_insert_iterator&
      operator*() { return *this; }


      back_insert_iterator&
      operator++() { return *this; }


      back_insert_iterator
      operator++(int) { return *this; }
    };
# 389 "/usr/include/c++/3.3/bits/stl_iterator.h" 3
  template<typename _Container>
    inline back_insert_iterator<_Container>
    back_inserter(_Container& __x)
    { return back_insert_iterator<_Container>(__x); }
# 404 "/usr/include/c++/3.3/bits/stl_iterator.h" 3
  template<typename _Container>
    class front_insert_iterator
    : public iterator<output_iterator_tag, void, void, void, void>
    {
    protected:
      _Container* container;

    public:

      typedef _Container container_type;


      explicit front_insert_iterator(_Container& __x) : container(&__x) { }
# 429 "/usr/include/c++/3.3/bits/stl_iterator.h" 3
      front_insert_iterator&
      operator=(typename _Container::const_reference __value)
      {
        container->push_front(__value);
        return *this;
      }


      front_insert_iterator&
      operator*() { return *this; }


      front_insert_iterator&
      operator++() { return *this; }


      front_insert_iterator
      operator++(int) { return *this; }
    };
# 460 "/usr/include/c++/3.3/bits/stl_iterator.h" 3
  template<typename _Container>
    inline front_insert_iterator<_Container>
    front_inserter(_Container& __x)
    { return front_insert_iterator<_Container>(__x); }
# 479 "/usr/include/c++/3.3/bits/stl_iterator.h" 3
  template<typename _Container>
    class insert_iterator
    : public iterator<output_iterator_tag, void, void, void, void>
    {
    protected:
      _Container* container;
      typename _Container::iterator iter;

    public:

      typedef _Container container_type;





      insert_iterator(_Container& __x, typename _Container::iterator __i)
      : container(&__x), iter(__i) {}
# 521 "/usr/include/c++/3.3/bits/stl_iterator.h" 3
      insert_iterator&
      operator=(const typename _Container::const_reference __value)
      {
        iter = container->insert(iter, __value);
        ++iter;
        return *this;
      }


      insert_iterator&
      operator*() { return *this; }


      insert_iterator&
      operator++() { return *this; }


      insert_iterator&
      operator++(int) { return *this; }
    };
# 553 "/usr/include/c++/3.3/bits/stl_iterator.h" 3
  template<typename _Container, typename _Iterator>
    inline insert_iterator<_Container>
    inserter(_Container& __x, _Iterator __i)
    {
      return insert_iterator<_Container>(__x,
                                         typename _Container::iterator(__i));
    }
}

namespace __gnu_cxx
{







  using std::iterator_traits;
  using std::iterator;
  template<typename _Iterator, typename _Container>
    class __normal_iterator
      : public iterator<typename iterator_traits<_Iterator>::iterator_category,
                        typename iterator_traits<_Iterator>::value_type,
                        typename iterator_traits<_Iterator>::difference_type,
                        typename iterator_traits<_Iterator>::pointer,
                        typename iterator_traits<_Iterator>::reference>
    {
    protected:
      _Iterator _M_current;

    public:
      typedef typename iterator_traits<_Iterator>::difference_type
                                                               difference_type;
      typedef typename iterator_traits<_Iterator>::reference reference;
      typedef typename iterator_traits<_Iterator>::pointer pointer;

      __normal_iterator() : _M_current(_Iterator()) { }

      explicit
      __normal_iterator(const _Iterator& __i) : _M_current(__i) { }


      template<typename _Iter>
      inline __normal_iterator(const __normal_iterator<_Iter, _Container>& __i)
        : _M_current(__i.base()) { }


      reference
      operator*() const { return *_M_current; }

      pointer
      operator->() const { return _M_current; }

      __normal_iterator&
      operator++() { ++_M_current; return *this; }

      __normal_iterator
      operator++(int) { return __normal_iterator(_M_current++); }


      __normal_iterator&
      operator--() { --_M_current; return *this; }

      __normal_iterator
      operator--(int) { return __normal_iterator(_M_current--); }


      reference
      operator[](const difference_type& __n) const
      { return _M_current[__n]; }

      __normal_iterator&
      operator+=(const difference_type& __n)
      { _M_current += __n; return *this; }

      __normal_iterator
      operator+(const difference_type& __n) const
      { return __normal_iterator(_M_current + __n); }

      __normal_iterator&
      operator-=(const difference_type& __n)
      { _M_current -= __n; return *this; }

      __normal_iterator
      operator-(const difference_type& __n) const
      { return __normal_iterator(_M_current - __n); }

      const _Iterator&
      base() const { return _M_current; }
    };
# 654 "/usr/include/c++/3.3/bits/stl_iterator.h" 3
  template<typename _IteratorL, typename _IteratorR, typename _Container>
  inline bool
  operator==(const __normal_iterator<_IteratorL, _Container>& __lhs,
             const __normal_iterator<_IteratorR, _Container>& __rhs)
  { return __lhs.base() == __rhs.base(); }

  template<typename _Iterator, typename _Container>
  inline bool
  operator==(const __normal_iterator<_Iterator, _Container>& __lhs,
             const __normal_iterator<_Iterator, _Container>& __rhs)
  { return __lhs.base() == __rhs.base(); }

  template<typename _IteratorL, typename _IteratorR, typename _Container>
  inline bool
  operator!=(const __normal_iterator<_IteratorL, _Container>& __lhs,
             const __normal_iterator<_IteratorR, _Container>& __rhs)
  { return __lhs.base() != __rhs.base(); }

  template<typename _Iterator, typename _Container>
  inline bool
  operator!=(const __normal_iterator<_Iterator, _Container>& __lhs,
             const __normal_iterator<_Iterator, _Container>& __rhs)
  { return __lhs.base() != __rhs.base(); }


  template<typename _IteratorL, typename _IteratorR, typename _Container>
  inline bool
  operator<(const __normal_iterator<_IteratorL, _Container>& __lhs,
            const __normal_iterator<_IteratorR, _Container>& __rhs)
  { return __lhs.base() < __rhs.base(); }

  template<typename _Iterator, typename _Container>
  inline bool
  operator<(const __normal_iterator<_Iterator, _Container>& __lhs,
             const __normal_iterator<_Iterator, _Container>& __rhs)
  { return __lhs.base() < __rhs.base(); }

  template<typename _IteratorL, typename _IteratorR, typename _Container>
  inline bool
  operator>(const __normal_iterator<_IteratorL, _Container>& __lhs,
            const __normal_iterator<_IteratorR, _Container>& __rhs)
  { return __lhs.base() > __rhs.base(); }

  template<typename _Iterator, typename _Container>
  inline bool
  operator>(const __normal_iterator<_Iterator, _Container>& __lhs,
            const __normal_iterator<_Iterator, _Container>& __rhs)
  { return __lhs.base() > __rhs.base(); }

  template<typename _IteratorL, typename _IteratorR, typename _Container>
  inline bool
  operator<=(const __normal_iterator<_IteratorL, _Container>& __lhs,
             const __normal_iterator<_IteratorR, _Container>& __rhs)
  { return __lhs.base() <= __rhs.base(); }

  template<typename _Iterator, typename _Container>
  inline bool
  operator<=(const __normal_iterator<_Iterator, _Container>& __lhs,
             const __normal_iterator<_Iterator, _Container>& __rhs)
  { return __lhs.base() <= __rhs.base(); }

  template<typename _IteratorL, typename _IteratorR, typename _Container>
  inline bool
  operator>=(const __normal_iterator<_IteratorL, _Container>& __lhs,
             const __normal_iterator<_IteratorR, _Container>& __rhs)
  { return __lhs.base() >= __rhs.base(); }

  template<typename _Iterator, typename _Container>
  inline bool
  operator>=(const __normal_iterator<_Iterator, _Container>& __lhs,
             const __normal_iterator<_Iterator, _Container>& __rhs)
  { return __lhs.base() >= __rhs.base(); }





  template<typename _IteratorL, typename _IteratorR, typename _Container>
  inline typename __normal_iterator<_IteratorL, _Container>::difference_type
  operator-(const __normal_iterator<_IteratorL, _Container>& __lhs,
             const __normal_iterator<_IteratorR, _Container>& __rhs)
  { return __lhs.base() - __rhs.base(); }

  template<typename _Iterator, typename _Container>
  inline __normal_iterator<_Iterator, _Container>
  operator+(typename __normal_iterator<_Iterator, _Container>::difference_type __n,
            const __normal_iterator<_Iterator, _Container>& __i)
  { return __normal_iterator<_Iterator, _Container>(__i.base() + __n); }
}
# 76 "/usr/include/c++/3.3/bits/stl_algobase.h" 2 3


namespace std
{
# 91 "/usr/include/c++/3.3/bits/stl_algobase.h" 3
  template<typename _ForwardIter1, typename _ForwardIter2>
    inline void
    iter_swap(_ForwardIter1 __a, _ForwardIter2 __b)
    {
      typedef typename iterator_traits<_ForwardIter1>::value_type _ValueType1;
      typedef typename iterator_traits<_ForwardIter2>::value_type _ValueType2;


     
     
     
     

      _ValueType1 __tmp = *__a;
      *__a = *__b;
      *__b = __tmp;
    }
# 118 "/usr/include/c++/3.3/bits/stl_algobase.h" 3
  template<typename _Tp>
    inline void
    swap(_Tp& __a, _Tp& __b)
    {

     

      _Tp __tmp = __a;
      __a = __b;
      __b = __tmp;
    }
# 146 "/usr/include/c++/3.3/bits/stl_algobase.h" 3
  template<typename _Tp>
    inline const _Tp&
    min(const _Tp& __a, const _Tp& __b)
    {

     

      if (__b < __a) return __b; return __a;
    }
# 166 "/usr/include/c++/3.3/bits/stl_algobase.h" 3
  template<typename _Tp>
    inline const _Tp&
    max(const _Tp& __a, const _Tp& __b)
    {

     

      if (__a < __b) return __b; return __a;
    }
# 186 "/usr/include/c++/3.3/bits/stl_algobase.h" 3
  template<typename _Tp, typename _Compare>
    inline const _Tp&
    min(const _Tp& __a, const _Tp& __b, _Compare __comp)
    {

      if (__comp(__b, __a)) return __b; return __a;
    }
# 204 "/usr/include/c++/3.3/bits/stl_algobase.h" 3
  template<typename _Tp, typename _Compare>
    inline const _Tp&
    max(const _Tp& __a, const _Tp& __b, _Compare __comp)
    {

      if (__comp(__a, __b)) return __b; return __a;
    }
# 221 "/usr/include/c++/3.3/bits/stl_algobase.h" 3
  template<typename _InputIter, typename _OutputIter>
    inline _OutputIter
    __copy(_InputIter __first, _InputIter __last,
           _OutputIter __result,
           input_iterator_tag)
    {
      for ( ; __first != __last; ++__result, ++__first)
        *__result = *__first;
      return __result;
    }

  template<typename _RandomAccessIter, typename _OutputIter>
    inline _OutputIter
    __copy(_RandomAccessIter __first, _RandomAccessIter __last,
           _OutputIter __result,
           random_access_iterator_tag)
    {
      typedef typename iterator_traits<_RandomAccessIter>::difference_type
          _Distance;
      for (_Distance __n = __last - __first; __n > 0; --__n) {
        *__result = *__first;
        ++__first;
        ++__result;
      }
      return __result;
    }

  template<typename _Tp>
    inline _Tp*
    __copy_trivial(const _Tp* __first, const _Tp* __last, _Tp* __result)
    {
      memmove(__result, __first, sizeof(_Tp) * (__last - __first));
      return __result + (__last - __first);
    }

  template<typename _InputIter, typename _OutputIter>
    inline _OutputIter
    __copy_aux2(_InputIter __first, _InputIter __last,
                _OutputIter __result, __false_type)
    { return __copy(__first, __last, __result, __iterator_category(__first)); }

  template<typename _InputIter, typename _OutputIter>
    inline _OutputIter
    __copy_aux2(_InputIter __first, _InputIter __last,
                _OutputIter __result, __true_type)
    { return __copy(__first, __last, __result, __iterator_category(__first)); }

  template<typename _Tp>
    inline _Tp*
    __copy_aux2(_Tp* __first, _Tp* __last,
                _Tp* __result, __true_type)
    { return __copy_trivial(__first, __last, __result); }

  template<typename _Tp>
    inline _Tp*
    __copy_aux2(const _Tp* __first, const _Tp* __last,
                _Tp* __result, __true_type)
    { return __copy_trivial(__first, __last, __result); }

  template<typename _InputIter, typename _OutputIter>
    inline _OutputIter
    __copy_ni2(_InputIter __first, _InputIter __last,
               _OutputIter __result, __true_type)
    {
      typedef typename iterator_traits<_InputIter>::value_type
          _ValueType;
      typedef typename __type_traits<_ValueType>::has_trivial_assignment_operator
          _Trivial;
      return _OutputIter(__copy_aux2(__first, __last,
                                     __result.base(),
                                     _Trivial()));
    }

  template<typename _InputIter, typename _OutputIter>
    inline _OutputIter
    __copy_ni2(_InputIter __first, _InputIter __last,
               _OutputIter __result, __false_type)
    {
      typedef typename iterator_traits<_InputIter>::value_type
          _ValueType;
      typedef typename __type_traits<_ValueType>::has_trivial_assignment_operator
          _Trivial;
      return __copy_aux2(__first, __last,
                         __result,
                         _Trivial());
    }

  template<typename _InputIter, typename _OutputIter>
    inline _OutputIter
    __copy_ni1(_InputIter __first, _InputIter __last,
               _OutputIter __result, __true_type)
    {
      typedef typename _Is_normal_iterator<_OutputIter>::_Normal __Normal;
      return __copy_ni2(__first.base(), __last.base(), __result, __Normal());
    }

  template<typename _InputIter, typename _OutputIter>
    inline _OutputIter
    __copy_ni1(_InputIter __first, _InputIter __last,
               _OutputIter __result, __false_type)
    {
      typedef typename _Is_normal_iterator<_OutputIter>::_Normal __Normal;
      return __copy_ni2(__first, __last, __result, __Normal());
    }
# 339 "/usr/include/c++/3.3/bits/stl_algobase.h" 3
  template<typename _InputIter, typename _OutputIter>
    inline _OutputIter
    copy(_InputIter __first, _InputIter __last, _OutputIter __result)
    {

     
     


       typedef typename _Is_normal_iterator<_InputIter>::_Normal __Normal;
       return __copy_ni1(__first, __last, __result, __Normal());
    }




  template<typename _BidirectionalIter1, typename _BidirectionalIter2>
    inline _BidirectionalIter2
    __copy_backward(_BidirectionalIter1 __first, _BidirectionalIter1 __last,
                    _BidirectionalIter2 __result,
                    bidirectional_iterator_tag)
    {
      while (__first != __last)
        *--__result = *--__last;
      return __result;
    }

  template<typename _RandomAccessIter, typename _BidirectionalIter>
    inline _BidirectionalIter
    __copy_backward(_RandomAccessIter __first, _RandomAccessIter __last,
                    _BidirectionalIter __result,
                    random_access_iterator_tag)
    {
      typename iterator_traits<_RandomAccessIter>::difference_type __n;
      for (__n = __last - __first; __n > 0; --__n)
        *--__result = *--__last;
      return __result;
    }







  template<typename _BidirectionalIter1, typename _BidirectionalIter2,
           typename _BoolType>
    struct __copy_backward_dispatch
    {
      static _BidirectionalIter2
      copy(_BidirectionalIter1 __first, _BidirectionalIter1 __last,
           _BidirectionalIter2 __result)
      {
        return __copy_backward(__first, __last,
                               __result,
                               __iterator_category(__first));
      }
    };

  template<typename _Tp>
    struct __copy_backward_dispatch<_Tp*, _Tp*, __true_type>
    {
      static _Tp*
      copy(const _Tp* __first, const _Tp* __last, _Tp* __result)
      {
        const ptrdiff_t _Num = __last - __first;
        memmove(__result - _Num, __first, sizeof(_Tp) * _Num);
        return __result - _Num;
      }
    };

  template<typename _Tp>
    struct __copy_backward_dispatch<const _Tp*, _Tp*, __true_type>
    {
      static _Tp*
      copy(const _Tp* __first, const _Tp* __last, _Tp* __result)
      {
        return __copy_backward_dispatch<_Tp*, _Tp*, __true_type>
          ::copy(__first, __last, __result);
      }
    };

  template<typename _BI1, typename _BI2>
    inline _BI2
    __copy_backward_aux(_BI1 __first, _BI1 __last, _BI2 __result)
    {
      typedef typename __type_traits<typename iterator_traits<_BI2>::value_type>
                            ::has_trivial_assignment_operator _Trivial;
      return __copy_backward_dispatch<_BI1, _BI2, _Trivial>
                  ::copy(__first, __last, __result);
    }

  template <typename _BI1, typename _BI2>
    inline _BI2
    __copy_backward_output_normal_iterator(_BI1 __first, _BI1 __last,
                                           _BI2 __result, __true_type)
    { return _BI2(__copy_backward_aux(__first, __last, __result.base())); }

  template <typename _BI1, typename _BI2>
    inline _BI2
    __copy_backward_output_normal_iterator(_BI1 __first, _BI1 __last,
                                           _BI2 __result, __false_type)
    { return __copy_backward_aux(__first, __last, __result); }

  template <typename _BI1, typename _BI2>
    inline _BI2
    __copy_backward_input_normal_iterator(_BI1 __first, _BI1 __last,
                                          _BI2 __result, __true_type)
    {
      typedef typename _Is_normal_iterator<_BI2>::_Normal __Normal;
      return __copy_backward_output_normal_iterator(__first.base(), __last.base(),
                                                    __result, __Normal());
    }

  template <typename _BI1, typename _BI2>
    inline _BI2
    __copy_backward_input_normal_iterator(_BI1 __first, _BI1 __last,
                                          _BI2 __result, __false_type)
    {
      typedef typename _Is_normal_iterator<_BI2>::_Normal __Normal;
      return __copy_backward_output_normal_iterator(__first, __last, __result,
                                                    __Normal());
    }
# 477 "/usr/include/c++/3.3/bits/stl_algobase.h" 3
  template <typename _BI1, typename _BI2>
    inline _BI2
    copy_backward(_BI1 __first, _BI1 __last, _BI2 __result)
    {

     
     
     



      typedef typename _Is_normal_iterator<_BI1>::_Normal __Normal;
      return __copy_backward_input_normal_iterator(__first, __last, __result,
                                                   __Normal());
    }
# 509 "/usr/include/c++/3.3/bits/stl_algobase.h" 3
  template<typename _ForwardIter, typename _Tp>
    void
    fill(_ForwardIter __first, _ForwardIter __last, const _Tp& __value)
    {

     

      for ( ; __first != __last; ++__first)
        *__first = __value;
    }
# 531 "/usr/include/c++/3.3/bits/stl_algobase.h" 3
  template<typename _OutputIter, typename _Size, typename _Tp>
    _OutputIter
    fill_n(_OutputIter __first, _Size __n, const _Tp& __value)
    {

     

      for ( ; __n > 0; --__n, ++__first)
        *__first = __value;
      return __first;
    }



  inline void
  fill(unsigned char* __first, unsigned char* __last, const unsigned char& __c)
  {
    unsigned char __tmp = __c;
    memset(__first, __tmp, __last - __first);
  }

  inline void
  fill(signed char* __first, signed char* __last, const signed char& __c)
  {
    signed char __tmp = __c;
    memset(__first, static_cast<unsigned char>(__tmp), __last - __first);
  }

  inline void
  fill(char* __first, char* __last, const char& __c)
  {
    char __tmp = __c;
    memset(__first, static_cast<unsigned char>(__tmp), __last - __first);
  }

  template<typename _Size>
    inline unsigned char*
    fill_n(unsigned char* __first, _Size __n, const unsigned char& __c)
    {
      fill(__first, __first + __n, __c);
      return __first + __n;
    }

  template<typename _Size>
    inline signed char*
    fill_n(char* __first, _Size __n, const signed char& __c)
    {
      fill(__first, __first + __n, __c);
      return __first + __n;
    }

  template<typename _Size>
    inline char*
    fill_n(char* __first, _Size __n, const char& __c)
    {
      fill(__first, __first + __n, __c);
      return __first + __n;
    }
# 606 "/usr/include/c++/3.3/bits/stl_algobase.h" 3
  template<typename _InputIter1, typename _InputIter2>
    pair<_InputIter1, _InputIter2>
    mismatch(_InputIter1 __first1, _InputIter1 __last1,
             _InputIter2 __first2)
    {

     
     
     

     


      while (__first1 != __last1 && *__first1 == *__first2) {
        ++__first1;
        ++__first2;
      }
      return pair<_InputIter1, _InputIter2>(__first1, __first2);
    }
# 640 "/usr/include/c++/3.3/bits/stl_algobase.h" 3
  template<typename _InputIter1, typename _InputIter2, typename _BinaryPredicate>
    pair<_InputIter1, _InputIter2>
    mismatch(_InputIter1 __first1, _InputIter1 __last1,
             _InputIter2 __first2,
             _BinaryPredicate __binary_pred)
    {

     
     

      while (__first1 != __last1 && __binary_pred(*__first1, *__first2)) {
        ++__first1;
        ++__first2;
      }
      return pair<_InputIter1, _InputIter2>(__first1, __first2);
    }
# 668 "/usr/include/c++/3.3/bits/stl_algobase.h" 3
  template<typename _InputIter1, typename _InputIter2>
    inline bool
    equal(_InputIter1 __first1, _InputIter1 __last1,
          _InputIter2 __first2)
    {

     
     
     



      for ( ; __first1 != __last1; ++__first1, ++__first2)
        if (!(*__first1 == *__first2))
          return false;
      return true;
    }
# 699 "/usr/include/c++/3.3/bits/stl_algobase.h" 3
  template<typename _InputIter1, typename _InputIter2, typename _BinaryPredicate>
    inline bool
    equal(_InputIter1 __first1, _InputIter1 __last1,
          _InputIter2 __first2,
          _BinaryPredicate __binary_pred)
    {

     
     

      for ( ; __first1 != __last1; ++__first1, ++__first2)
        if (!__binary_pred(*__first1, *__first2))
          return false;
      return true;
    }
# 732 "/usr/include/c++/3.3/bits/stl_algobase.h" 3
  template<typename _InputIter1, typename _InputIter2>
    bool
    lexicographical_compare(_InputIter1 __first1, _InputIter1 __last1,
                            _InputIter2 __first2, _InputIter2 __last2)
    {

     
     
     

     


      for ( ; __first1 != __last1 && __first2 != __last2
            ; ++__first1, ++__first2) {
        if (*__first1 < *__first2)
          return true;
        if (*__first2 < *__first1)
          return false;
      }
      return __first1 == __last1 && __first2 != __last2;
    }
# 767 "/usr/include/c++/3.3/bits/stl_algobase.h" 3
  template<typename _InputIter1, typename _InputIter2, typename _Compare>
    bool
    lexicographical_compare(_InputIter1 __first1, _InputIter1 __last1,
                            _InputIter2 __first2, _InputIter2 __last2,
                            _Compare __comp)
    {

     
     

      for ( ; __first1 != __last1 && __first2 != __last2
            ; ++__first1, ++__first2) {
        if (__comp(*__first1, *__first2))
          return true;
        if (__comp(*__first2, *__first1))
          return false;
      }
      return __first1 == __last1 && __first2 != __last2;
    }

  inline bool
  lexicographical_compare(const unsigned char* __first1, const unsigned char* __last1,
                          const unsigned char* __first2, const unsigned char* __last2)
  {
    const size_t __len1 = __last1 - __first1;
    const size_t __len2 = __last2 - __first2;
    const int __result = memcmp(__first1, __first2, min(__len1, __len2));
    return __result != 0 ? __result < 0 : __len1 < __len2;
  }

  inline bool
  lexicographical_compare(const char* __first1, const char* __last1,
                          const char* __first2, const char* __last2)
  {

    return lexicographical_compare((const signed char*) __first1,
                                   (const signed char*) __last1,
                                   (const signed char*) __first2,
                                   (const signed char*) __last2);






  }

}
# 68 "/usr/include/c++/3.3/vector" 2 3
# 1 "/usr/include/c++/3.3/bits/stl_alloc.h" 1 3
# 88 "/usr/include/c++/3.3/bits/stl_alloc.h" 3
# 1 "/usr/include/c++/3.3/bits/functexcept.h" 1 3
# 34 "/usr/include/c++/3.3/bits/functexcept.h" 3
# 1 "/usr/include/c++/3.3/exception_defines.h" 1 3
# 35 "/usr/include/c++/3.3/bits/functexcept.h" 2 3

namespace std
{

  void
  __throw_bad_exception(void);


  void
  __throw_bad_alloc(void);


  void
  __throw_bad_cast(void);

  void
  __throw_bad_typeid(void);


  void
  __throw_logic_error(const char* __s);

  void
  __throw_domain_error(const char* __s);

  void
  __throw_invalid_argument(const char* __s);

  void
  __throw_length_error(const char* __s);

  void
  __throw_out_of_range(const char* __s);

  void
  __throw_runtime_error(const char* __s);

  void
  __throw_range_error(const char* __s);

  void
  __throw_overflow_error(const char* __s);

  void
  __throw_underflow_error(const char* __s);


  void
  __throw_ios_failure(const char* __s);
}
# 89 "/usr/include/c++/3.3/bits/stl_alloc.h" 2 3
# 1 "/usr/include/c++/3.3/bits/stl_threads.h" 1 3
# 54 "/usr/include/c++/3.3/bits/stl_threads.h" 3
namespace std
{




  struct _Refcount_Base
  {

    typedef size_t _RC_t;


    volatile _RC_t _M_ref_count;


    __gthread_mutex_t _M_ref_count_lock;

    _Refcount_Base(_RC_t __n) : _M_ref_count(__n)
    {

      __gthread_mutex_t __tmp = {0, 0, 0, PTHREAD_MUTEX_TIMED_NP, { 0, 0 }};
      _M_ref_count_lock = __tmp;





    }

    void
    _M_incr()
    {
      __gthread_mutex_lock(&_M_ref_count_lock);
      ++_M_ref_count;
      __gthread_mutex_unlock(&_M_ref_count_lock);
    }

    _RC_t
    _M_decr()
    {
      __gthread_mutex_lock(&_M_ref_count_lock);
      volatile _RC_t __tmp = --_M_ref_count;
      __gthread_mutex_unlock(&_M_ref_count_lock);
      return __tmp;
    }
  };
# 109 "/usr/include/c++/3.3/bits/stl_threads.h" 3
  template<int __dummy>
    struct _Swap_lock_struct
    { static __gthread_mutex_t _S_swap_lock; };

  template<int __dummy>
    __gthread_mutex_t
    _Swap_lock_struct<__dummy>::_S_swap_lock = {0, 0, 0, PTHREAD_MUTEX_TIMED_NP, { 0, 0 }};



  inline unsigned long
  _Atomic_swap(unsigned long * __p, unsigned long __q)
  {
    __gthread_mutex_lock(&_Swap_lock_struct<0>::_S_swap_lock);
    unsigned long __result = *__p;
    *__p = __q;
    __gthread_mutex_unlock(&_Swap_lock_struct<0>::_S_swap_lock);
    return __result;
  }

}
# 155 "/usr/include/c++/3.3/bits/stl_threads.h" 3
namespace std
{
  struct _STL_mutex_lock
  {





    __gthread_mutex_t _M_lock;

    void
    _M_initialize()
    {
# 192 "/usr/include/c++/3.3/bits/stl_threads.h" 3
    }

    void
    _M_acquire_lock()
    {



      __gthread_mutex_lock(&_M_lock);
    }

    void
    _M_release_lock()
    {



      __gthread_mutex_unlock(&_M_lock);
    }
  };
# 228 "/usr/include/c++/3.3/bits/stl_threads.h" 3
  struct _STL_auto_lock
  {
    _STL_mutex_lock& _M_lock;

    _STL_auto_lock(_STL_mutex_lock& __lock) : _M_lock(__lock)
    { _M_lock._M_acquire_lock(); }

    ~_STL_auto_lock() { _M_lock._M_release_lock(); }

  private:
    void operator=(const _STL_auto_lock&);
    _STL_auto_lock(const _STL_auto_lock&);
  };

}
# 90 "/usr/include/c++/3.3/bits/stl_alloc.h" 2 3

# 1 "/usr/include/c++/3.3/i486-linux/bits/atomicity.h" 1 3
# 33 "/usr/include/c++/3.3/i486-linux/bits/atomicity.h" 3
typedef int _Atomic_word;

static inline _Atomic_word

__exchange_and_add (volatile _Atomic_word *__mem, int __val)
{
  register _Atomic_word __result;
  __asm__ __volatile__ ("lock; xadd{l} {%0,%1|%1,%0}"
                        : "=r" (__result), "+m" (*__mem)
                        : "0" (__val)
                        : "memory");
  return __result;
}

static inline void

__atomic_add (volatile _Atomic_word* __mem, int __val)
{
  __asm__ __volatile__ ("lock; add{l} {%1,%0|%0,%1}"
                        : "+m" (*__mem) : "ir" (__val) : "memory");
}
# 92 "/usr/include/c++/3.3/bits/stl_alloc.h" 2 3

namespace std
{
# 103 "/usr/include/c++/3.3/bits/stl_alloc.h" 3
  class __new_alloc
  {
  public:
    static void*
    allocate(size_t __n)
    { return ::operator new(__n); }

    static void
    deallocate(void* __p, size_t)
    { ::operator delete(__p); }
  };
# 126 "/usr/include/c++/3.3/bits/stl_alloc.h" 3
  template<int __inst>
    class __malloc_alloc_template
    {
    private:
      static void* _S_oom_malloc(size_t);
      static void* _S_oom_realloc(void*, size_t);
      static void (* __malloc_alloc_oom_handler)();

    public:
      static void*
      allocate(size_t __n)
      {
        void* __result = malloc(__n);
        if (__builtin_expect(__result == 0, 0))
          __result = _S_oom_malloc(__n);
        return __result;
      }

      static void
      deallocate(void* __p, size_t )
      { free(__p); }

      static void*
      reallocate(void* __p, size_t , size_t __new_sz)
      {
        void* __result = realloc(__p, __new_sz);
        if (__builtin_expect(__result == 0, 0))
          __result = _S_oom_realloc(__p, __new_sz);
        return __result;
      }

      static void (* __set_malloc_handler(void (*__f)()))()
      {
        void (* __old)() = __malloc_alloc_oom_handler;
        __malloc_alloc_oom_handler = __f;
        return __old;
      }
    };


  template<int __inst>
    void (* __malloc_alloc_template<__inst>::__malloc_alloc_oom_handler)() = 0;

  template<int __inst>
    void*
    __malloc_alloc_template<__inst>::
    _S_oom_malloc(size_t __n)
    {
      void (* __my_malloc_handler)();
      void* __result;

      for (;;)
        {
          __my_malloc_handler = __malloc_alloc_oom_handler;
          if (__builtin_expect(__my_malloc_handler == 0, 0))
            __throw_bad_alloc();
          (*__my_malloc_handler)();
          __result = malloc(__n);
          if (__result)
            return __result;
        }
    }

  template<int __inst>
    void*
    __malloc_alloc_template<__inst>::
    _S_oom_realloc(void* __p, size_t __n)
    {
      void (* __my_malloc_handler)();
      void* __result;

      for (;;)
        {
          __my_malloc_handler = __malloc_alloc_oom_handler;
          if (__builtin_expect(__my_malloc_handler == 0, 0))
            __throw_bad_alloc();
          (*__my_malloc_handler)();
          __result = realloc(__p, __n);
          if (__result)
            return __result;
        }
    }


  typedef __new_alloc __mem_interface;
# 223 "/usr/include/c++/3.3/bits/stl_alloc.h" 3
  template<typename _Tp, typename _Alloc>
    class __simple_alloc
    {
    public:
      static _Tp*
      allocate(size_t __n)
      {
        _Tp* __ret = 0;
        if (__n)
          __ret = static_cast<_Tp*>(_Alloc::allocate(__n * sizeof(_Tp)));
        return __ret;
      }

      static _Tp*
      allocate()
      { return (_Tp*) _Alloc::allocate(sizeof (_Tp)); }

      static void
      deallocate(_Tp* __p, size_t __n)
      { if (0 != __n) _Alloc::deallocate(__p, __n * sizeof (_Tp)); }

      static void
      deallocate(_Tp* __p)
      { _Alloc::deallocate(__p, sizeof (_Tp)); }
    };
# 261 "/usr/include/c++/3.3/bits/stl_alloc.h" 3
  template<typename _Alloc>
    class __debug_alloc
    {
    private:


      enum {_S_extra = 8};

    public:
      static void*
      allocate(size_t __n)
      {
        char* __result = (char*)_Alloc::allocate(__n + (int) _S_extra);
        *(size_t*)__result = __n;
        return __result + (int) _S_extra;
      }

      static void
      deallocate(void* __p, size_t __n)
      {
        char* __real_p = (char*)__p - (int) _S_extra;
        if (*(size_t*)__real_p != __n)
          abort();
        _Alloc::deallocate(__real_p, __n + (int) _S_extra);
      }

      static void*
      reallocate(void* __p, size_t __old_sz, size_t __new_sz)
      {
        char* __real_p = (char*)__p - (int) _S_extra;
        if (*(size_t*)__real_p != __old_sz)
          abort();
        char* __result = (char*) _Alloc::reallocate(__real_p,
                                                    __old_sz + (int) _S_extra,
                                                    __new_sz + (int) _S_extra);
        *(size_t*)__result = __new_sz;
        return __result + (int) _S_extra;
      }
    };
# 332 "/usr/include/c++/3.3/bits/stl_alloc.h" 3
  template<bool __threads, int __inst>
    class __default_alloc_template
    {
    private:
      enum {_ALIGN = 8};
      enum {_MAX_BYTES = 128};
      enum {_NFREELISTS = _MAX_BYTES / _ALIGN};

      union _Obj
      {
        union _Obj* _M_free_list_link;
        char _M_client_data[1];
      };

      static _Obj* volatile _S_free_list[_NFREELISTS];


      static char* _S_start_free;
      static char* _S_end_free;
      static size_t _S_heap_size;

      static _STL_mutex_lock _S_node_allocator_lock;

      static size_t
      _S_round_up(size_t __bytes)
      { return (((__bytes) + (size_t) _ALIGN-1) & ~((size_t) _ALIGN - 1)); }

      static size_t
      _S_freelist_index(size_t __bytes)
      { return (((__bytes) + (size_t)_ALIGN - 1)/(size_t)_ALIGN - 1); }



      static void*
      _S_refill(size_t __n);



      static char*
      _S_chunk_alloc(size_t __size, int& __nobjs);



      struct _Lock
      {
        _Lock() { if (__threads) _S_node_allocator_lock._M_acquire_lock(); }
        ~_Lock() { if (__threads) _S_node_allocator_lock._M_release_lock(); }
      } ;
      friend struct _Lock;

      static _Atomic_word _S_force_new;

    public:

      static void*
      allocate(size_t __n)
      {
        void* __ret = 0;




        if (_S_force_new == 0)
          {
            if (getenv("GLIBCPP_FORCE_NEW"))
              __atomic_add(&_S_force_new, 1);
            else
              __atomic_add(&_S_force_new, -1);
          }

        if ((__n > (size_t) _MAX_BYTES) || (_S_force_new > 0))
          __ret = __new_alloc::allocate(__n);
        else
          {
            _Obj* volatile* __my_free_list = _S_free_list
              + _S_freelist_index(__n);



            _Lock __lock_instance;
            _Obj* __restrict__ __result = *__my_free_list;
            if (__builtin_expect(__result == 0, 0))
              __ret = _S_refill(_S_round_up(__n));
            else
              {
                *__my_free_list = __result -> _M_free_list_link;
                __ret = __result;
              }
            if (__builtin_expect(__ret == 0, 0))
              __throw_bad_alloc();
          }
        return __ret;
      }


      static void
      deallocate(void* __p, size_t __n)
      {
        if ((__n > (size_t) _MAX_BYTES) || (_S_force_new > 0))
          __new_alloc::deallocate(__p, __n);
        else
          {
            _Obj* volatile* __my_free_list = _S_free_list
              + _S_freelist_index(__n);
            _Obj* __q = (_Obj*)__p;




            _Lock __lock_instance;
            __q -> _M_free_list_link = *__my_free_list;
            *__my_free_list = __q;
          }
      }

      static void*
      reallocate(void* __p, size_t __old_sz, size_t __new_sz);
    };

  template<bool __threads, int __inst> _Atomic_word
  __default_alloc_template<__threads, __inst>::_S_force_new = 0;

  template<bool __threads, int __inst>
    inline bool
    operator==(const __default_alloc_template<__threads,__inst>&,
               const __default_alloc_template<__threads,__inst>&)
    { return true; }

  template<bool __threads, int __inst>
    inline bool
    operator!=(const __default_alloc_template<__threads,__inst>&,
               const __default_alloc_template<__threads,__inst>&)
    { return false; }





  template<bool __threads, int __inst>
    char*
    __default_alloc_template<__threads, __inst>::
    _S_chunk_alloc(size_t __size, int& __nobjs)
    {
      char* __result;
      size_t __total_bytes = __size * __nobjs;
      size_t __bytes_left = _S_end_free - _S_start_free;

      if (__bytes_left >= __total_bytes)
        {
          __result = _S_start_free;
          _S_start_free += __total_bytes;
          return __result ;
        }
      else if (__bytes_left >= __size)
        {
          __nobjs = (int)(__bytes_left/__size);
          __total_bytes = __size * __nobjs;
          __result = _S_start_free;
          _S_start_free += __total_bytes;
          return __result;
        }
      else
        {
          size_t __bytes_to_get =
            2 * __total_bytes + _S_round_up(_S_heap_size >> 4);

          if (__bytes_left > 0)
            {
              _Obj* volatile* __my_free_list =
                _S_free_list + _S_freelist_index(__bytes_left);

              ((_Obj*)(void*)_S_start_free) -> _M_free_list_link = *__my_free_list;
              *__my_free_list = (_Obj*)(void*)_S_start_free;
            }
          _S_start_free = (char*) __new_alloc::allocate(__bytes_to_get);
          if (_S_start_free == 0)
            {
              size_t __i;
              _Obj* volatile* __my_free_list;
              _Obj* __p;



              __i = __size;
              for (; __i <= (size_t) _MAX_BYTES; __i += (size_t) _ALIGN)
                {
                  __my_free_list = _S_free_list + _S_freelist_index(__i);
                  __p = *__my_free_list;
                  if (__p != 0)
                    {
                      *__my_free_list = __p -> _M_free_list_link;
                      _S_start_free = (char*)__p;
                      _S_end_free = _S_start_free + __i;
                      return _S_chunk_alloc(__size, __nobjs);


                    }
                }
              _S_end_free = 0;
              _S_start_free = (char*)__new_alloc::allocate(__bytes_to_get);


            }
          _S_heap_size += __bytes_to_get;
          _S_end_free = _S_start_free + __bytes_to_get;
          return _S_chunk_alloc(__size, __nobjs);
        }
    }





  template<bool __threads, int __inst>
    void*
    __default_alloc_template<__threads, __inst>::_S_refill(size_t __n)
    {
      int __nobjs = 20;
      char* __chunk = _S_chunk_alloc(__n, __nobjs);
      _Obj* volatile* __my_free_list;
      _Obj* __result;
      _Obj* __current_obj;
      _Obj* __next_obj;
      int __i;

      if (1 == __nobjs)
        return __chunk;
      __my_free_list = _S_free_list + _S_freelist_index(__n);


      __result = (_Obj*)(void*)__chunk;
      *__my_free_list = __next_obj = (_Obj*)(void*)(__chunk + __n);
      for (__i = 1; ; __i++)
        {
          __current_obj = __next_obj;
          __next_obj = (_Obj*)(void*)((char*)__next_obj + __n);
          if (__nobjs - 1 == __i)
            {
              __current_obj -> _M_free_list_link = 0;
              break;
            }
          else
            __current_obj -> _M_free_list_link = __next_obj;
        }
      return __result;
    }


  template<bool threads, int inst>
    void*
    __default_alloc_template<threads, inst>::
    reallocate(void* __p, size_t __old_sz, size_t __new_sz)
    {
      void* __result;
      size_t __copy_sz;

      if (__old_sz > (size_t) _MAX_BYTES && __new_sz > (size_t) _MAX_BYTES)
        return(realloc(__p, __new_sz));
      if (_S_round_up(__old_sz) == _S_round_up(__new_sz))
        return(__p);
      __result = allocate(__new_sz);
      __copy_sz = __new_sz > __old_sz? __old_sz : __new_sz;
      memcpy(__result, __p, __copy_sz);
      deallocate(__p, __old_sz);
      return __result;
    }

  template<bool __threads, int __inst>
    _STL_mutex_lock
    __default_alloc_template<__threads,__inst>::_S_node_allocator_lock
    = { {0, 0, 0, PTHREAD_MUTEX_TIMED_NP, { 0, 0 }} };

  template<bool __threads, int __inst>
    char* __default_alloc_template<__threads,__inst>::_S_start_free = 0;

  template<bool __threads, int __inst>
    char* __default_alloc_template<__threads,__inst>::_S_end_free = 0;

  template<bool __threads, int __inst>
    size_t __default_alloc_template<__threads,__inst>::_S_heap_size = 0;

  template<bool __threads, int __inst>
    typename __default_alloc_template<__threads,__inst>::_Obj* volatile
    __default_alloc_template<__threads,__inst>::_S_free_list[_NFREELISTS];

  typedef __default_alloc_template<true,0> __alloc;
  typedef __default_alloc_template<false,0> __single_client_alloc;
# 635 "/usr/include/c++/3.3/bits/stl_alloc.h" 3
  template<typename _Tp>
    class allocator
    {
      typedef __alloc _Alloc;
    public:
      typedef size_t size_type;
      typedef ptrdiff_t difference_type;
      typedef _Tp* pointer;
      typedef const _Tp* const_pointer;
      typedef _Tp& reference;
      typedef const _Tp& const_reference;
      typedef _Tp value_type;

      template<typename _Tp1>
        struct rebind
        { typedef allocator<_Tp1> other; };

      allocator() throw() {}
      allocator(const allocator&) throw() {}
      template<typename _Tp1>
        allocator(const allocator<_Tp1>&) throw() {}
      ~allocator() throw() {}

      pointer
      address(reference __x) const { return &__x; }

      const_pointer
      address(const_reference __x) const { return &__x; }



      _Tp*
      allocate(size_type __n, const void* = 0)
      {
        _Tp* __ret = 0;
        if (__n)
          {
            if (__n <= this->max_size())
              __ret = static_cast<_Tp*>(_Alloc::allocate(__n * sizeof(_Tp)));
            else
              __throw_bad_alloc();
          }
        return __ret;
      }


      void
      deallocate(pointer __p, size_type __n)
      { _Alloc::deallocate(__p, __n * sizeof(_Tp)); }

      size_type
      max_size() const throw() { return size_t(-1) / sizeof(_Tp); }

      void construct(pointer __p, const _Tp& __val) { new(__p) _Tp(__val); }
      void destroy(pointer __p) { __p->~_Tp(); }
    };

  template<>
    class allocator<void>
    {
    public:
      typedef size_t size_type;
      typedef ptrdiff_t difference_type;
      typedef void* pointer;
      typedef const void* const_pointer;
      typedef void value_type;

      template<typename _Tp1>
        struct rebind
        { typedef allocator<_Tp1> other; };
    };


  template<typename _T1, typename _T2>
    inline bool
    operator==(const allocator<_T1>&, const allocator<_T2>&)
    { return true; }

  template<typename _T1, typename _T2>
    inline bool
    operator!=(const allocator<_T1>&, const allocator<_T2>&)
    { return false; }
# 731 "/usr/include/c++/3.3/bits/stl_alloc.h" 3
  template<typename _Tp, typename _Alloc>
    struct __allocator
    {
      _Alloc __underlying_alloc;

      typedef size_t size_type;
      typedef ptrdiff_t difference_type;
      typedef _Tp* pointer;
      typedef const _Tp* const_pointer;
      typedef _Tp& reference;
      typedef const _Tp& const_reference;
      typedef _Tp value_type;

      template<typename _Tp1>
        struct rebind
        { typedef __allocator<_Tp1, _Alloc> other; };

      __allocator() throw() {}
      __allocator(const __allocator& __a) throw()
      : __underlying_alloc(__a.__underlying_alloc) {}

      template<typename _Tp1>
        __allocator(const __allocator<_Tp1, _Alloc>& __a) throw()
        : __underlying_alloc(__a.__underlying_alloc) {}

      ~__allocator() throw() {}

      pointer
      address(reference __x) const { return &__x; }

      const_pointer
      address(const_reference __x) const { return &__x; }



      _Tp*
      allocate(size_type __n, const void* = 0)
      {
        _Tp* __ret = 0;
        if (__n)
          __ret = static_cast<_Tp*>(_Alloc::allocate(__n * sizeof(_Tp)));
        return __ret;
      }


      void
      deallocate(pointer __p, size_type __n)
      { __underlying_alloc.deallocate(__p, __n * sizeof(_Tp)); }

      size_type
      max_size() const throw() { return size_t(-1) / sizeof(_Tp); }

      void
      construct(pointer __p, const _Tp& __val) { new(__p) _Tp(__val); }

      void
      destroy(pointer __p) { __p->~_Tp(); }
    };

  template<typename _Alloc>
    struct __allocator<void, _Alloc>
    {
      typedef size_t size_type;
      typedef ptrdiff_t difference_type;
      typedef void* pointer;
      typedef const void* const_pointer;
      typedef void value_type;

      template<typename _Tp1>
        struct rebind
        { typedef __allocator<_Tp1, _Alloc> other; };
    };

  template<typename _Tp, typename _Alloc>
    inline bool
    operator==(const __allocator<_Tp,_Alloc>& __a1,
               const __allocator<_Tp,_Alloc>& __a2)
    { return __a1.__underlying_alloc == __a2.__underlying_alloc; }

  template<typename _Tp, typename _Alloc>
    inline bool
    operator!=(const __allocator<_Tp, _Alloc>& __a1,
               const __allocator<_Tp, _Alloc>& __a2)
    { return __a1.__underlying_alloc != __a2.__underlying_alloc; }







  template<int inst>
    inline bool
    operator==(const __malloc_alloc_template<inst>&,
               const __malloc_alloc_template<inst>&)
    { return true; }

  template<int __inst>
    inline bool
    operator!=(const __malloc_alloc_template<__inst>&,
               const __malloc_alloc_template<__inst>&)
    { return false; }

  template<typename _Alloc>
    inline bool
    operator==(const __debug_alloc<_Alloc>&, const __debug_alloc<_Alloc>&)
    { return true; }

  template<typename _Alloc>
    inline bool
    operator!=(const __debug_alloc<_Alloc>&, const __debug_alloc<_Alloc>&)
    { return false; }
# 884 "/usr/include/c++/3.3/bits/stl_alloc.h" 3
  template<typename _Tp, typename _Allocator>
    struct _Alloc_traits
    {
      static const bool _S_instanceless = false;
      typedef typename _Allocator::template rebind<_Tp>::other allocator_type;
    };

  template<typename _Tp, typename _Allocator>
    const bool _Alloc_traits<_Tp, _Allocator>::_S_instanceless;


  template<typename _Tp, typename _Tp1>
    struct _Alloc_traits<_Tp, allocator<_Tp1> >
    {
      static const bool _S_instanceless = true;
      typedef __simple_alloc<_Tp, __alloc> _Alloc_type;
      typedef allocator<_Tp> allocator_type;
    };




  template<typename _Tp, int __inst>
    struct _Alloc_traits<_Tp, __malloc_alloc_template<__inst> >
    {
      static const bool _S_instanceless = true;
      typedef __simple_alloc<_Tp, __malloc_alloc_template<__inst> > _Alloc_type;
      typedef __allocator<_Tp, __malloc_alloc_template<__inst> > allocator_type;
    };

  template<typename _Tp, bool __threads, int __inst>
    struct _Alloc_traits<_Tp, __default_alloc_template<__threads, __inst> >
    {
      static const bool _S_instanceless = true;
      typedef __simple_alloc<_Tp, __default_alloc_template<__threads, __inst> >
      _Alloc_type;
      typedef __allocator<_Tp, __default_alloc_template<__threads, __inst> >
      allocator_type;
    };

  template<typename _Tp, typename _Alloc>
    struct _Alloc_traits<_Tp, __debug_alloc<_Alloc> >
    {
      static const bool _S_instanceless = true;
      typedef __simple_alloc<_Tp, __debug_alloc<_Alloc> > _Alloc_type;
      typedef __allocator<_Tp, __debug_alloc<_Alloc> > allocator_type;
    };





  template<typename _Tp, typename _Tp1, int __inst>
    struct _Alloc_traits<_Tp,
                         __allocator<_Tp1, __malloc_alloc_template<__inst> > >
    {
      static const bool _S_instanceless = true;
      typedef __simple_alloc<_Tp, __malloc_alloc_template<__inst> > _Alloc_type;
      typedef __allocator<_Tp, __malloc_alloc_template<__inst> > allocator_type;
    };

  template<typename _Tp, typename _Tp1, bool __thr, int __inst>
    struct _Alloc_traits<_Tp, __allocator<_Tp1, __default_alloc_template<__thr, __inst> > >
    {
      static const bool _S_instanceless = true;
      typedef __simple_alloc<_Tp, __default_alloc_template<__thr,__inst> >
      _Alloc_type;
      typedef __allocator<_Tp, __default_alloc_template<__thr,__inst> >
      allocator_type;
    };

  template<typename _Tp, typename _Tp1, typename _Alloc>
    struct _Alloc_traits<_Tp, __allocator<_Tp1, __debug_alloc<_Alloc> > >
    {
      static const bool _S_instanceless = true;
      typedef __simple_alloc<_Tp, __debug_alloc<_Alloc> > _Alloc_type;
      typedef __allocator<_Tp, __debug_alloc<_Alloc> > allocator_type;
    };






  extern template class allocator<char>;
  extern template class allocator<wchar_t>;
  extern template class __default_alloc_template<true,0>;

}
# 69 "/usr/include/c++/3.3/vector" 2 3
# 1 "/usr/include/c++/3.3/bits/stl_construct.h" 1 3
# 67 "/usr/include/c++/3.3/bits/stl_construct.h" 3
namespace std
{






  template <class _T1, class _T2>
    inline void
    _Construct(_T1* __p, const _T2& __value)
    { new (static_cast<void*>(__p)) _T1(__value); }







  template <class _T1>
    inline void
    _Construct(_T1* __p)
    { new (static_cast<void*>(__p)) _T1(); }
# 98 "/usr/include/c++/3.3/bits/stl_construct.h" 3
  template <class _ForwardIterator>
    inline void
    __destroy_aux(_ForwardIterator __first, _ForwardIterator __last, __false_type)
    { for ( ; __first != __last; ++__first) _Destroy(&*__first); }
# 112 "/usr/include/c++/3.3/bits/stl_construct.h" 3
  template <class _ForwardIterator>
    inline void
    __destroy_aux(_ForwardIterator, _ForwardIterator, __true_type)
    { }






  template <class _Tp>
    inline void
    _Destroy(_Tp* __pointer)
    { __pointer->~_Tp(); }
# 134 "/usr/include/c++/3.3/bits/stl_construct.h" 3
  template <class _ForwardIterator>
    inline void
    _Destroy(_ForwardIterator __first, _ForwardIterator __last)
    {
      typedef typename iterator_traits<_ForwardIterator>::value_type
                       _Value_type;
      typedef typename __type_traits<_Value_type>::has_trivial_destructor
                       _Has_trivial_destructor;

      __destroy_aux(__first, __last, _Has_trivial_destructor());
    }
}
# 70 "/usr/include/c++/3.3/vector" 2 3
# 1 "/usr/include/c++/3.3/bits/stl_uninitialized.h" 1 3
# 66 "/usr/include/c++/3.3/bits/stl_uninitialized.h" 3
namespace std
{



  template<typename _InputIter, typename _ForwardIter>
    inline _ForwardIter
    __uninitialized_copy_aux(_InputIter __first, _InputIter __last,
                             _ForwardIter __result,
                             __true_type)
    { return copy(__first, __last, __result); }

  template<typename _InputIter, typename _ForwardIter>
    _ForwardIter
    __uninitialized_copy_aux(_InputIter __first, _InputIter __last,
                             _ForwardIter __result,
                             __false_type)
    {
      _ForwardIter __cur = __result;
      if (true) {
        for ( ; __first != __last; ++__first, ++__cur)
          _Construct(&*__cur, *__first);
        return __cur;
      }
      if (false)
        {
          _Destroy(__result, __cur);
          ;
        }
    }
# 106 "/usr/include/c++/3.3/bits/stl_uninitialized.h" 3
  template<typename _InputIter, typename _ForwardIter>
    inline _ForwardIter
    uninitialized_copy(_InputIter __first, _InputIter __last, _ForwardIter __result)
    {
      typedef typename iterator_traits<_ForwardIter>::value_type _ValueType;
      typedef typename __type_traits<_ValueType>::is_POD_type _Is_POD;
      return __uninitialized_copy_aux(__first, __last, __result, _Is_POD());
    }

  inline char*
  uninitialized_copy(const char* __first, const char* __last, char* __result)
  {
    memmove(__result, __first, __last - __first);
    return __result + (__last - __first);
  }

  inline wchar_t*
  uninitialized_copy(const wchar_t* __first, const wchar_t* __last,
                     wchar_t* __result)
  {
    memmove(__result, __first, sizeof(wchar_t) * (__last - __first));
    return __result + (__last - __first);
  }



  template<typename _ForwardIter, typename _Tp>
    inline void
    __uninitialized_fill_aux(_ForwardIter __first, _ForwardIter __last,
                             const _Tp& __x, __true_type)
    { fill(__first, __last, __x); }

  template<typename _ForwardIter, typename _Tp>
    void
    __uninitialized_fill_aux(_ForwardIter __first, _ForwardIter __last,
                             const _Tp& __x, __false_type)
    {
      _ForwardIter __cur = __first;
      if (true) {
        for ( ; __cur != __last; ++__cur)
          _Construct(&*__cur, __x);
      }
      if (false)
        {
          _Destroy(__first, __cur);
          ;
        }
    }
# 164 "/usr/include/c++/3.3/bits/stl_uninitialized.h" 3
  template<typename _ForwardIter, typename _Tp>
    inline void
    uninitialized_fill(_ForwardIter __first, _ForwardIter __last, const _Tp& __x)
    {
      typedef typename iterator_traits<_ForwardIter>::value_type _ValueType;
      typedef typename __type_traits<_ValueType>::is_POD_type _Is_POD;
      __uninitialized_fill_aux(__first, __last, __x, _Is_POD());
    }



  template<typename _ForwardIter, typename _Size, typename _Tp>
    inline _ForwardIter
    __uninitialized_fill_n_aux(_ForwardIter __first, _Size __n,
                               const _Tp& __x, __true_type)
    {
      return fill_n(__first, __n, __x);
    }

  template<typename _ForwardIter, typename _Size, typename _Tp>
    _ForwardIter
    __uninitialized_fill_n_aux(_ForwardIter __first, _Size __n,
                               const _Tp& __x, __false_type)
    {
      _ForwardIter __cur = __first;
      if (true) {
        for ( ; __n > 0; --__n, ++__cur)
          _Construct(&*__cur, __x);
        return __cur;
      }
      if (false)
        {
          _Destroy(__first, __cur);
          ;
        }
    }
# 210 "/usr/include/c++/3.3/bits/stl_uninitialized.h" 3
  template<typename _ForwardIter, typename _Size, typename _Tp>
    inline _ForwardIter
    uninitialized_fill_n(_ForwardIter __first, _Size __n, const _Tp& __x)
    {
      typedef typename iterator_traits<_ForwardIter>::value_type _ValueType;
      typedef typename __type_traits<_ValueType>::is_POD_type _Is_POD;
      return __uninitialized_fill_n_aux(__first, __n, __x, _Is_POD());
    }
# 227 "/usr/include/c++/3.3/bits/stl_uninitialized.h" 3
  template<typename _InputIter1, typename _InputIter2, typename _ForwardIter>
    inline _ForwardIter
    __uninitialized_copy_copy(_InputIter1 __first1, _InputIter1 __last1,
                              _InputIter2 __first2, _InputIter2 __last2,
                              _ForwardIter __result)
    {
      _ForwardIter __mid = uninitialized_copy(__first1, __last1, __result);
      if (true) {
        return uninitialized_copy(__first2, __last2, __mid);
      }
      if (false)
        {
          _Destroy(__result, __mid);
          ;
        }
    }




  template<typename _ForwardIter, typename _Tp, typename _InputIter>
    inline _ForwardIter
    __uninitialized_fill_copy(_ForwardIter __result, _ForwardIter __mid,
                              const _Tp& __x,
                              _InputIter __first, _InputIter __last)
    {
      uninitialized_fill(__result, __mid, __x);
      if (true) {
        return uninitialized_copy(__first, __last, __mid);
      }
      if (false)
        {
          _Destroy(__result, __mid);
          ;
        }
    }




  template<typename _InputIter, typename _ForwardIter, typename _Tp>
    inline void
    __uninitialized_copy_fill(_InputIter __first1, _InputIter __last1,
                              _ForwardIter __first2, _ForwardIter __last2,
                              const _Tp& __x)
    {
      _ForwardIter __mid2 = uninitialized_copy(__first1, __last1, __first2);
      if (true) {
        uninitialized_fill(__mid2, __last2, __x);
      }
      if (false)
        {
          _Destroy(__first2, __mid2);
          ;
        }
    }

}
# 71 "/usr/include/c++/3.3/vector" 2 3
# 1 "/usr/include/c++/3.3/bits/stl_vector.h" 1 3
# 65 "/usr/include/c++/3.3/bits/stl_vector.h" 3
# 1 "/usr/include/c++/3.3/bits/functexcept.h" 1 3
# 34 "/usr/include/c++/3.3/bits/functexcept.h" 3
# 1 "/usr/include/c++/3.3/exception_defines.h" 1 3
# 35 "/usr/include/c++/3.3/bits/functexcept.h" 2 3

namespace std
{

  void
  __throw_bad_exception(void);


  void
  __throw_bad_alloc(void);


  void
  __throw_bad_cast(void);

  void
  __throw_bad_typeid(void);


  void
  __throw_logic_error(const char* __s);

  void
  __throw_domain_error(const char* __s);

  void
  __throw_invalid_argument(const char* __s);

  void
  __throw_length_error(const char* __s);

  void
  __throw_out_of_range(const char* __s);

  void
  __throw_runtime_error(const char* __s);

  void
  __throw_range_error(const char* __s);

  void
  __throw_overflow_error(const char* __s);

  void
  __throw_underflow_error(const char* __s);


  void
  __throw_ios_failure(const char* __s);
}
# 66 "/usr/include/c++/3.3/bits/stl_vector.h" 2 3


namespace std
{






  template<typename _Tp, typename _Allocator, bool _IsStatic>
    class _Vector_alloc_base
    {
    public:
      typedef typename _Alloc_traits<_Tp, _Allocator>::allocator_type
      allocator_type;

      allocator_type
      get_allocator() const { return _M_data_allocator; }

      _Vector_alloc_base(const allocator_type& __a)
      : _M_data_allocator(__a), _M_start(0), _M_finish(0), _M_end_of_storage(0)
      { }

    protected:
      allocator_type _M_data_allocator;
      _Tp* _M_start;
      _Tp* _M_finish;
      _Tp* _M_end_of_storage;

      _Tp*
      _M_allocate(size_t __n) { return _M_data_allocator.allocate(__n); }

      void
      _M_deallocate(_Tp* __p, size_t __n)
      { if (__p) _M_data_allocator.deallocate(__p, __n); }
    };


  template<typename _Tp, typename _Allocator>
    class _Vector_alloc_base<_Tp, _Allocator, true>
    {
    public:
      typedef typename _Alloc_traits<_Tp, _Allocator>::allocator_type
             allocator_type;

      allocator_type
      get_allocator() const { return allocator_type(); }

      _Vector_alloc_base(const allocator_type&)
      : _M_start(0), _M_finish(0), _M_end_of_storage(0)
      { }

    protected:
      _Tp* _M_start;
      _Tp* _M_finish;
      _Tp* _M_end_of_storage;

      typedef typename _Alloc_traits<_Tp, _Allocator>::_Alloc_type _Alloc_type;

      _Tp*
      _M_allocate(size_t __n) { return _Alloc_type::allocate(__n); }

      void
      _M_deallocate(_Tp* __p, size_t __n) { _Alloc_type::deallocate(__p, __n);}
    };







  template<typename _Tp, typename _Alloc>
    struct _Vector_base
    : public _Vector_alloc_base<_Tp, _Alloc,
                                _Alloc_traits<_Tp, _Alloc>::_S_instanceless>
    {
    public:
      typedef _Vector_alloc_base<_Tp, _Alloc,
                                 _Alloc_traits<_Tp, _Alloc>::_S_instanceless>
         _Base;
      typedef typename _Base::allocator_type allocator_type;

      _Vector_base(const allocator_type& __a)
      : _Base(__a) { }

      _Vector_base(size_t __n, const allocator_type& __a)
      : _Base(__a)
      {
        _M_start = _M_allocate(__n);
        _M_finish = _M_start;
        _M_end_of_storage = _M_start + __n;
      }

      ~_Vector_base()
      { _M_deallocate(_M_start, _M_end_of_storage - _M_start); }
    };
# 184 "/usr/include/c++/3.3/bits/stl_vector.h" 3
  template<typename _Tp, typename _Alloc = allocator<_Tp> >
    class vector : protected _Vector_base<_Tp, _Alloc>
    {

     

      typedef _Vector_base<_Tp, _Alloc> _Base;
      typedef vector<_Tp, _Alloc> vector_type;

    public:
      typedef _Tp value_type;
      typedef value_type* pointer;
      typedef const value_type* const_pointer;
      typedef __gnu_cxx::__normal_iterator<pointer, vector_type> iterator;
      typedef __gnu_cxx::__normal_iterator<const_pointer, vector_type>
      const_iterator;
      typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
      typedef std::reverse_iterator<iterator> reverse_iterator;
      typedef value_type& reference;
      typedef const value_type& const_reference;
      typedef size_t size_type;
      typedef ptrdiff_t difference_type;
      typedef typename _Base::allocator_type allocator_type;

    protected:






      using _Base::_M_allocate;
      using _Base::_M_deallocate;
      using _Base::_M_start;
      using _Base::_M_finish;
      using _Base::_M_end_of_storage;

    public:





      explicit
      vector(const allocator_type& __a = allocator_type())
      : _Base(__a) { }
# 238 "/usr/include/c++/3.3/bits/stl_vector.h" 3
      vector(size_type __n, const value_type& __value,
             const allocator_type& __a = allocator_type())
      : _Base(__n, __a)
      { _M_finish = uninitialized_fill_n(_M_start, __n, __value); }
# 250 "/usr/include/c++/3.3/bits/stl_vector.h" 3
      explicit
      vector(size_type __n)
      : _Base(__n, allocator_type())
      { _M_finish = uninitialized_fill_n(_M_start, __n, value_type()); }
# 264 "/usr/include/c++/3.3/bits/stl_vector.h" 3
      vector(const vector& __x)
      : _Base(__x.size(), __x.get_allocator())
      { _M_finish = uninitialized_copy(__x.begin(), __x.end(), _M_start); }
# 282 "/usr/include/c++/3.3/bits/stl_vector.h" 3
      template<typename _InputIterator>
        vector(_InputIterator __first, _InputIterator __last,
               const allocator_type& __a = allocator_type())
        : _Base(__a)
        {

          typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
          _M_initialize_dispatch(__first, __last, _Integral());
        }






      ~vector() { _Destroy(_M_start, _M_finish); }
# 307 "/usr/include/c++/3.3/bits/stl_vector.h" 3
      vector&
      operator=(const vector& __x);
# 320 "/usr/include/c++/3.3/bits/stl_vector.h" 3
      void
      assign(size_type __n, const value_type& __val)
      { _M_fill_assign(__n, __val); }
# 336 "/usr/include/c++/3.3/bits/stl_vector.h" 3
      template<typename _InputIterator>
        void
        assign(_InputIterator __first, _InputIterator __last)
        {

          typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
          _M_assign_dispatch(__first, __last, _Integral());
        }


      allocator_type
      get_allocator() const { return _Base::get_allocator(); }






      iterator
      begin() { return iterator (_M_start); }






      const_iterator
      begin() const { return const_iterator (_M_start); }






      iterator
      end() { return iterator (_M_finish); }





      const_iterator
      end() const { return const_iterator (_M_finish); }






      reverse_iterator
      rbegin() { return reverse_iterator(end()); }






      const_reverse_iterator
      rbegin() const { return const_reverse_iterator(end()); }






      reverse_iterator
      rend() { return reverse_iterator(begin()); }






      const_reverse_iterator
      rend() const { return const_reverse_iterator(begin()); }



      size_type
      size() const { return size_type(end() - begin()); }


      size_type
      max_size() const { return size_type(-1) / sizeof(value_type); }
# 432 "/usr/include/c++/3.3/bits/stl_vector.h" 3
      void
      resize(size_type __new_size, const value_type& __x)
      {
        if (__new_size < size())
          erase(begin() + __new_size, end());
        else
          insert(end(), __new_size - size(), __x);
      }
# 451 "/usr/include/c++/3.3/bits/stl_vector.h" 3
      void
      resize(size_type __new_size) { resize(__new_size, value_type()); }





      size_type
      capacity() const
      { return size_type(const_iterator(_M_end_of_storage) - begin()); }





      bool
      empty() const { return begin() == end(); }
# 486 "/usr/include/c++/3.3/bits/stl_vector.h" 3
      void
      reserve(size_type __n);
# 500 "/usr/include/c++/3.3/bits/stl_vector.h" 3
      reference
      operator[](size_type __n) { return *(begin() + __n); }
# 514 "/usr/include/c++/3.3/bits/stl_vector.h" 3
      const_reference
      operator[](size_type __n) const { return *(begin() + __n); }

    protected:

      void
      _M_range_check(size_type __n) const
      {
        if (__n >= this->size())
          __throw_out_of_range("vector [] access out of range");
      }

    public:
# 538 "/usr/include/c++/3.3/bits/stl_vector.h" 3
      reference
      at(size_type __n) { _M_range_check(__n); return (*this)[__n]; }
# 552 "/usr/include/c++/3.3/bits/stl_vector.h" 3
      const_reference
      at(size_type __n) const { _M_range_check(__n); return (*this)[__n]; }





      reference
      front() { return *begin(); }





      const_reference
      front() const { return *begin(); }





      reference
      back() { return *(end() - 1); }





      const_reference
      back() const { return *(end() - 1); }
# 594 "/usr/include/c++/3.3/bits/stl_vector.h" 3
      void
      push_back(const value_type& __x)
      {
        if (_M_finish != _M_end_of_storage)
          {
            _Construct(_M_finish, __x);
            ++_M_finish;
          }
        else
          _M_insert_aux(end(), __x);
      }
# 614 "/usr/include/c++/3.3/bits/stl_vector.h" 3
      void
      pop_back()
      {
        --_M_finish;
        _Destroy(_M_finish);
      }
# 632 "/usr/include/c++/3.3/bits/stl_vector.h" 3
      iterator
      insert(iterator __position, const value_type& __x);
# 669 "/usr/include/c++/3.3/bits/stl_vector.h" 3
      void
      insert(iterator __pos, size_type __n, const value_type& __x)
      { _M_fill_insert(__pos, __n, __x); }
# 687 "/usr/include/c++/3.3/bits/stl_vector.h" 3
      template<typename _InputIterator>
        void
        insert(iterator __pos, _InputIterator __first, _InputIterator __last)
        {

          typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
          _M_insert_dispatch(__pos, __first, __last, _Integral());
        }
# 711 "/usr/include/c++/3.3/bits/stl_vector.h" 3
      iterator
      erase(iterator __position);
# 732 "/usr/include/c++/3.3/bits/stl_vector.h" 3
      iterator
      erase(iterator __first, iterator __last);
# 744 "/usr/include/c++/3.3/bits/stl_vector.h" 3
      void
      swap(vector& __x)
      {
        std::swap(_M_start, __x._M_start);
        std::swap(_M_finish, __x._M_finish);
        std::swap(_M_end_of_storage, __x._M_end_of_storage);
      }







      void
      clear() { erase(begin(), end()); }

    protected:






      template<typename _ForwardIterator>
        pointer
        _M_allocate_and_copy(size_type __n,
                             _ForwardIterator __first, _ForwardIterator __last)
        {
          pointer __result = _M_allocate(__n);
          if (true)
            {
              uninitialized_copy(__first, __last, __result);
              return __result;
            }
          if (false)
            {
              _M_deallocate(__result, __n);
              ;
            }
        }





      template<typename _Integer>
        void
        _M_initialize_dispatch(_Integer __n, _Integer __value, __true_type)
        {
          _M_start = _M_allocate(__n);
          _M_end_of_storage = _M_start + __n;
          _M_finish = uninitialized_fill_n(_M_start, __n, __value);
        }


      template<typename _InputIter>
        void
        _M_initialize_dispatch(_InputIter __first, _InputIter __last,
                               __false_type)
        {
          typedef typename iterator_traits<_InputIter>::iterator_category
            _IterCategory;
          _M_range_initialize(__first, __last, _IterCategory());
        }


      template<typename _InputIterator>
        void
        _M_range_initialize(_InputIterator __first,
                            _InputIterator __last, input_iterator_tag)
        {
          for ( ; __first != __last; ++__first)
            push_back(*__first);
        }


      template<typename _ForwardIterator>
        void
        _M_range_initialize(_ForwardIterator __first,
                            _ForwardIterator __last, forward_iterator_tag)
        {
          size_type __n = distance(__first, __last);
          _M_start = _M_allocate(__n);
          _M_end_of_storage = _M_start + __n;
          _M_finish = uninitialized_copy(__first, __last, _M_start);
        }






      template<typename _Integer>
        void
        _M_assign_dispatch(_Integer __n, _Integer __val, __true_type)
        {
          _M_fill_assign(static_cast<size_type>(__n),
                         static_cast<value_type>(__val));
        }


      template<typename _InputIter>
        void
        _M_assign_dispatch(_InputIter __first, _InputIter __last, __false_type)
        {
          typedef typename iterator_traits<_InputIter>::iterator_category
            _IterCategory;
          _M_assign_aux(__first, __last, _IterCategory());
        }


      template<typename _InputIterator>
        void
        _M_assign_aux(_InputIterator __first, _InputIterator __last,
                      input_iterator_tag);


      template<typename _ForwardIterator>
        void
        _M_assign_aux(_ForwardIterator __first, _ForwardIterator __last,
                      forward_iterator_tag);



      void
      _M_fill_assign(size_type __n, const value_type& __val);





      template<typename _Integer>
        void
        _M_insert_dispatch(iterator __pos, _Integer __n, _Integer __val,
                           __true_type)
        {
          _M_fill_insert(__pos, static_cast<size_type>(__n),
                         static_cast<value_type>(__val));
        }


      template<typename _InputIterator>
        void
        _M_insert_dispatch(iterator __pos, _InputIterator __first,
                           _InputIterator __last, __false_type)
        {
          typedef typename iterator_traits<_InputIterator>::iterator_category
            _IterCategory;
          _M_range_insert(__pos, __first, __last, _IterCategory());
        }


      template<typename _InputIterator>
        void
        _M_range_insert(iterator __pos, _InputIterator __first,
                        _InputIterator __last, input_iterator_tag);


      template<typename _ForwardIterator>
        void
        _M_range_insert(iterator __pos, _ForwardIterator __first,
                        _ForwardIterator __last, forward_iterator_tag);



      void
      _M_fill_insert(iterator __pos, size_type __n, const value_type& __x);


      void
      _M_insert_aux(iterator __position, const value_type& __x);





    };
# 934 "/usr/include/c++/3.3/bits/stl_vector.h" 3
  template<typename _Tp, typename _Alloc>
    inline bool
    operator==(const vector<_Tp,_Alloc>& __x, const vector<_Tp,_Alloc>& __y)
    {
      return __x.size() == __y.size() &&
             equal(__x.begin(), __x.end(), __y.begin());
    }
# 953 "/usr/include/c++/3.3/bits/stl_vector.h" 3
  template<typename _Tp, typename _Alloc>
    inline bool
    operator<(const vector<_Tp,_Alloc>& __x, const vector<_Tp,_Alloc>& __y)
    {
      return lexicographical_compare(__x.begin(), __x.end(),
                                     __y.begin(), __y.end());
    }


  template<typename _Tp, typename _Alloc>
    inline bool
    operator!=(const vector<_Tp,_Alloc>& __x, const vector<_Tp,_Alloc>& __y)
    { return !(__x == __y); }


  template<typename _Tp, typename _Alloc>
    inline bool
    operator>(const vector<_Tp,_Alloc>& __x, const vector<_Tp,_Alloc>& __y)
    { return __y < __x; }


  template<typename _Tp, typename _Alloc>
    inline bool
    operator<=(const vector<_Tp,_Alloc>& __x, const vector<_Tp,_Alloc>& __y)
    { return !(__y < __x); }


  template<typename _Tp, typename _Alloc>
    inline bool
    operator>=(const vector<_Tp,_Alloc>& __x, const vector<_Tp,_Alloc>& __y)
    { return !(__x < __y); }


  template<typename _Tp, typename _Alloc>
    inline void
    swap(vector<_Tp,_Alloc>& __x, vector<_Tp,_Alloc>& __y)
    { __x.swap(__y); }
}
# 72 "/usr/include/c++/3.3/vector" 2 3
# 1 "/usr/include/c++/3.3/bits/stl_bvector.h" 1 3
# 64 "/usr/include/c++/3.3/bits/stl_bvector.h" 3
namespace std
{
  typedef unsigned long _Bit_type;
  enum { _M_word_bit = int(8 * sizeof(_Bit_type)) };

struct _Bit_reference {

  _Bit_type * _M_p;
  _Bit_type _M_mask;
  _Bit_reference(_Bit_type * __x, _Bit_type __y)
    : _M_p(__x), _M_mask(__y) {}

public:
  _Bit_reference() : _M_p(0), _M_mask(0) {}
  operator bool() const { return !!(*_M_p & _M_mask); }
  _Bit_reference& operator=(bool __x)
  {
    if (__x) *_M_p |= _M_mask;
    else *_M_p &= ~_M_mask;
    return *this;
  }
  _Bit_reference& operator=(const _Bit_reference& __x)
    { return *this = bool(__x); }
  bool operator==(const _Bit_reference& __x) const
    { return bool(*this) == bool(__x); }
  bool operator<(const _Bit_reference& __x) const
    { return !bool(*this) && bool(__x); }
  void flip() { *_M_p ^= _M_mask; }
};

struct _Bit_iterator_base : public iterator<random_access_iterator_tag, bool>
{
  _Bit_type * _M_p;
  unsigned int _M_offset;

  _Bit_iterator_base(_Bit_type * __x, unsigned int __y)
    : _M_p(__x), _M_offset(__y) {}

  void _M_bump_up() {
    if (_M_offset++ == _M_word_bit - 1) {
      _M_offset = 0;
      ++_M_p;
    }
  }
  void _M_bump_down() {
    if (_M_offset-- == 0) {
      _M_offset = _M_word_bit - 1;
      --_M_p;
    }
  }

  void _M_incr(ptrdiff_t __i) {
    difference_type __n = __i + _M_offset;
    _M_p += __n / _M_word_bit;
    __n = __n % _M_word_bit;
    if (__n < 0) {
      _M_offset = (unsigned int) __n + _M_word_bit;
      --_M_p;
    } else
      _M_offset = (unsigned int) __n;
  }

  bool operator==(const _Bit_iterator_base& __i) const {
    return _M_p == __i._M_p && _M_offset == __i._M_offset;
  }
  bool operator<(const _Bit_iterator_base& __i) const {
    return _M_p < __i._M_p || (_M_p == __i._M_p && _M_offset < __i._M_offset);
  }
  bool operator!=(const _Bit_iterator_base& __i) const {
    return !(*this == __i);
  }
  bool operator>(const _Bit_iterator_base& __i) const {
    return __i < *this;
  }
  bool operator<=(const _Bit_iterator_base& __i) const {
    return !(__i < *this);
  }
  bool operator>=(const _Bit_iterator_base& __i) const {
    return !(*this < __i);
  }
};

inline ptrdiff_t
operator-(const _Bit_iterator_base& __x, const _Bit_iterator_base& __y) {
  return _M_word_bit * (__x._M_p - __y._M_p) + __x._M_offset - __y._M_offset;
}


struct _Bit_iterator : public _Bit_iterator_base
{
  typedef _Bit_reference reference;
  typedef _Bit_reference* pointer;
  typedef _Bit_iterator iterator;

  _Bit_iterator() : _Bit_iterator_base(0, 0) {}
  _Bit_iterator(_Bit_type * __x, unsigned int __y)
    : _Bit_iterator_base(__x, __y) {}

  reference operator*() const { return reference(_M_p, 1UL << _M_offset); }
  iterator& operator++() {
    _M_bump_up();
    return *this;
  }
  iterator operator++(int) {
    iterator __tmp = *this;
    _M_bump_up();
    return __tmp;
  }
  iterator& operator--() {
    _M_bump_down();
    return *this;
  }
  iterator operator--(int) {
    iterator __tmp = *this;
    _M_bump_down();
    return __tmp;
  }
  iterator& operator+=(difference_type __i) {
    _M_incr(__i);
    return *this;
  }
  iterator& operator-=(difference_type __i) {
    *this += -__i;
    return *this;
  }
  iterator operator+(difference_type __i) const {
    iterator __tmp = *this;
    return __tmp += __i;
  }
  iterator operator-(difference_type __i) const {
    iterator __tmp = *this;
    return __tmp -= __i;
  }

  reference operator[](difference_type __i) { return *(*this + __i); }
};

inline _Bit_iterator
operator+(ptrdiff_t __n, const _Bit_iterator& __x) { return __x + __n; }


struct _Bit_const_iterator : public _Bit_iterator_base
{
  typedef bool reference;
  typedef bool const_reference;
  typedef const bool* pointer;
  typedef _Bit_const_iterator const_iterator;

  _Bit_const_iterator() : _Bit_iterator_base(0, 0) {}
  _Bit_const_iterator(_Bit_type * __x, unsigned int __y)
    : _Bit_iterator_base(__x, __y) {}
  _Bit_const_iterator(const _Bit_iterator& __x)
    : _Bit_iterator_base(__x._M_p, __x._M_offset) {}

  const_reference operator*() const {
    return _Bit_reference(_M_p, 1UL << _M_offset);
  }
  const_iterator& operator++() {
    _M_bump_up();
    return *this;
  }
  const_iterator operator++(int) {
    const_iterator __tmp = *this;
    _M_bump_up();
    return __tmp;
  }
  const_iterator& operator--() {
    _M_bump_down();
    return *this;
  }
  const_iterator operator--(int) {
    const_iterator __tmp = *this;
    _M_bump_down();
    return __tmp;
  }
  const_iterator& operator+=(difference_type __i) {
    _M_incr(__i);
    return *this;
  }
  const_iterator& operator-=(difference_type __i) {
    *this += -__i;
    return *this;
  }
  const_iterator operator+(difference_type __i) const {
    const_iterator __tmp = *this;
    return __tmp += __i;
  }
  const_iterator operator-(difference_type __i) const {
    const_iterator __tmp = *this;
    return __tmp -= __i;
  }
  const_reference operator[](difference_type __i) {
    return *(*this + __i);
  }
};

inline _Bit_const_iterator
operator+(ptrdiff_t __n, const _Bit_const_iterator& __x) { return __x + __n; }






template <class _Allocator, bool __is_static>
class _Bvector_alloc_base {
public:
  typedef typename _Alloc_traits<bool, _Allocator>::allocator_type
          allocator_type;
  allocator_type get_allocator() const { return _M_data_allocator; }

  _Bvector_alloc_base(const allocator_type& __a)
    : _M_data_allocator(__a), _M_start(), _M_finish(), _M_end_of_storage(0) {}

protected:
  _Bit_type * _M_bit_alloc(size_t __n)
    { return _M_data_allocator.allocate((__n + _M_word_bit - 1)/_M_word_bit); }
  void _M_deallocate() {
    if (_M_start._M_p)
      _M_data_allocator.deallocate(_M_start._M_p,
                                   _M_end_of_storage - _M_start._M_p);
  }

  typename _Alloc_traits<_Bit_type, _Allocator>::allocator_type
          _M_data_allocator;
  _Bit_iterator _M_start;
  _Bit_iterator _M_finish;
  _Bit_type * _M_end_of_storage;
};


template <class _Allocator>
class _Bvector_alloc_base<_Allocator, true> {
public:
  typedef typename _Alloc_traits<bool, _Allocator>::allocator_type
          allocator_type;
  allocator_type get_allocator() const { return allocator_type(); }

  _Bvector_alloc_base(const allocator_type&)
    : _M_start(), _M_finish(), _M_end_of_storage(0) {}

protected:
  typedef typename _Alloc_traits<_Bit_type, _Allocator>::_Alloc_type
          _Alloc_type;

  _Bit_type * _M_bit_alloc(size_t __n)
    { return _Alloc_type::allocate((__n + _M_word_bit - 1)/_M_word_bit); }
  void _M_deallocate() {
    if (_M_start._M_p)
      _Alloc_type::deallocate(_M_start._M_p,
                              _M_end_of_storage - _M_start._M_p);
  }

  _Bit_iterator _M_start;
  _Bit_iterator _M_finish;
  _Bit_type * _M_end_of_storage;
};

template <class _Alloc>
class _Bvector_base
  : public _Bvector_alloc_base<_Alloc,
                               _Alloc_traits<bool, _Alloc>::_S_instanceless>
{
  typedef _Bvector_alloc_base<_Alloc,
                              _Alloc_traits<bool, _Alloc>::_S_instanceless>
          _Base;
public:
  typedef typename _Base::allocator_type allocator_type;

  _Bvector_base(const allocator_type& __a) : _Base(__a) {}
  ~_Bvector_base() { _Base::_M_deallocate(); }
};

}



namespace std
{

template <typename _Alloc>
  class vector<bool, _Alloc> : public _Bvector_base<_Alloc>
  {
  public:
    typedef bool value_type;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef _Bit_reference reference;
    typedef bool const_reference;
    typedef _Bit_reference* pointer;
    typedef const bool* const_pointer;

    typedef _Bit_iterator iterator;
    typedef _Bit_const_iterator const_iterator;

    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;

    typedef typename _Bvector_base<_Alloc>::allocator_type allocator_type;
    allocator_type get_allocator() const {
      return _Bvector_base<_Alloc>::get_allocator();
    }

  protected:
    using _Bvector_base<_Alloc>::_M_bit_alloc;
    using _Bvector_base<_Alloc>::_M_deallocate;
    using _Bvector_base<_Alloc>::_M_start;
    using _Bvector_base<_Alloc>::_M_finish;
    using _Bvector_base<_Alloc>::_M_end_of_storage;

  protected:
    void _M_initialize(size_type __n) {
      _Bit_type * __q = _M_bit_alloc(__n);
      _M_end_of_storage = __q + (__n + _M_word_bit - 1)/_M_word_bit;
      _M_start = iterator(__q, 0);
      _M_finish = _M_start + difference_type(__n);
    }
    void _M_insert_aux(iterator __position, bool __x) {
      if (_M_finish._M_p != _M_end_of_storage) {
        copy_backward(__position, _M_finish, _M_finish + 1);
        *__position = __x;
        ++_M_finish;
      }
      else {
        size_type __len = size()
                          ? 2 * size() : static_cast<size_type>(_M_word_bit);
        _Bit_type * __q = _M_bit_alloc(__len);
        iterator __i = copy(begin(), __position, iterator(__q, 0));
        *__i++ = __x;
        _M_finish = copy(__position, end(), __i);
        _M_deallocate();
        _M_end_of_storage = __q + (__len + _M_word_bit - 1)/_M_word_bit;
        _M_start = iterator(__q, 0);
      }
    }

    template <class _InputIterator>
    void _M_initialize_range(_InputIterator __first, _InputIterator __last,
                             input_iterator_tag) {
      _M_start = iterator();
      _M_finish = iterator();
      _M_end_of_storage = 0;
      for ( ; __first != __last; ++__first)
        push_back(*__first);
    }

    template <class _ForwardIterator>
    void _M_initialize_range(_ForwardIterator __first, _ForwardIterator __last,
                             forward_iterator_tag) {
      size_type __n = distance(__first, __last);
      _M_initialize(__n);
      copy(__first, __last, _M_start);
    }

    template <class _InputIterator>
    void _M_insert_range(iterator __pos,
                         _InputIterator __first, _InputIterator __last,
                         input_iterator_tag) {
      for ( ; __first != __last; ++__first) {
        __pos = insert(__pos, *__first);
        ++__pos;
      }
    }

    template <class _ForwardIterator>
    void _M_insert_range(iterator __position,
                         _ForwardIterator __first, _ForwardIterator __last,
                         forward_iterator_tag) {
      if (__first != __last) {
        size_type __n = distance(__first, __last);
        if (capacity() - size() >= __n) {
          copy_backward(__position, end(), _M_finish + difference_type(__n));
          copy(__first, __last, __position);
          _M_finish += difference_type(__n);
        }
        else {
          size_type __len = size() + max(size(), __n);
          _Bit_type * __q = _M_bit_alloc(__len);
          iterator __i = copy(begin(), __position, iterator(__q, 0));
          __i = copy(__first, __last, __i);
          _M_finish = copy(__position, end(), __i);
          _M_deallocate();
          _M_end_of_storage = __q + (__len + _M_word_bit - 1)/_M_word_bit;
          _M_start = iterator(__q, 0);
        }
      }
    }

  public:
    iterator begin() { return _M_start; }
    const_iterator begin() const { return _M_start; }
    iterator end() { return _M_finish; }
    const_iterator end() const { return _M_finish; }

    reverse_iterator rbegin() { return reverse_iterator(end()); }
    const_reverse_iterator rbegin() const {
      return const_reverse_iterator(end());
    }
    reverse_iterator rend() { return reverse_iterator(begin()); }
    const_reverse_iterator rend() const {
      return const_reverse_iterator(begin());
    }

    size_type size() const { return size_type(end() - begin()); }
    size_type max_size() const { return size_type(-1); }
    size_type capacity() const {
      return size_type(const_iterator(_M_end_of_storage, 0) - begin());
    }
    bool empty() const { return begin() == end(); }

    reference operator[](size_type __n)
      { return *(begin() + difference_type(__n)); }
    const_reference operator[](size_type __n) const
      { return *(begin() + difference_type(__n)); }

    void _M_range_check(size_type __n) const {
      if (__n >= this->size())
        __throw_out_of_range("vector<bool>");
    }

    reference at(size_type __n)
      { _M_range_check(__n); return (*this)[__n]; }
    const_reference at(size_type __n) const
      { _M_range_check(__n); return (*this)[__n]; }

    explicit vector(const allocator_type& __a = allocator_type())
      : _Bvector_base<_Alloc>(__a) {}

    vector(size_type __n, bool __value,
              const allocator_type& __a = allocator_type())
      : _Bvector_base<_Alloc>(__a)
    {
      _M_initialize(__n);
      fill(_M_start._M_p, _M_end_of_storage, __value ? ~0 : 0);
    }

    explicit vector(size_type __n)
      : _Bvector_base<_Alloc>(allocator_type())
    {
      _M_initialize(__n);
      fill(_M_start._M_p, _M_end_of_storage, 0);
    }

    vector(const vector& __x) : _Bvector_base<_Alloc>(__x.get_allocator()) {
      _M_initialize(__x.size());
      copy(__x.begin(), __x.end(), _M_start);
    }



    template <class _Integer>
    void _M_initialize_dispatch(_Integer __n, _Integer __x, __true_type) {
      _M_initialize(__n);
      fill(_M_start._M_p, _M_end_of_storage, __x ? ~0 : 0);
    }

    template <class _InputIterator>
    void _M_initialize_dispatch(_InputIterator __first, _InputIterator __last,
                                __false_type) {
      _M_initialize_range(__first, __last, __iterator_category(__first));
    }

    template <class _InputIterator>
    vector(_InputIterator __first, _InputIterator __last,
             const allocator_type& __a = allocator_type())
      : _Bvector_base<_Alloc>(__a)
    {
      typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
      _M_initialize_dispatch(__first, __last, _Integral());
    }

    ~vector() { }

    vector& operator=(const vector& __x) {
      if (&__x == this) return *this;
      if (__x.size() > capacity()) {
        _M_deallocate();
        _M_initialize(__x.size());
      }
      copy(__x.begin(), __x.end(), begin());
      _M_finish = begin() + difference_type(__x.size());
      return *this;
    }






    void _M_fill_assign(size_t __n, bool __x) {
      if (__n > size()) {
        fill(_M_start._M_p, _M_end_of_storage, __x ? ~0 : 0);
        insert(end(), __n - size(), __x);
      }
      else {
        erase(begin() + __n, end());
        fill(_M_start._M_p, _M_end_of_storage, __x ? ~0 : 0);
      }
    }

    void assign(size_t __n, bool __x) { _M_fill_assign(__n, __x); }

    template <class _InputIterator>
    void assign(_InputIterator __first, _InputIterator __last) {
      typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
      _M_assign_dispatch(__first, __last, _Integral());
    }

    template <class _Integer>
    void _M_assign_dispatch(_Integer __n, _Integer __val, __true_type)
      { _M_fill_assign((size_t) __n, (bool) __val); }

    template <class _InputIter>
    void _M_assign_dispatch(_InputIter __first, _InputIter __last, __false_type)
      { _M_assign_aux(__first, __last, __iterator_category(__first)); }

    template <class _InputIterator>
    void _M_assign_aux(_InputIterator __first, _InputIterator __last,
                       input_iterator_tag) {
      iterator __cur = begin();
      for ( ; __first != __last && __cur != end(); ++__cur, ++__first)
        *__cur = *__first;
      if (__first == __last)
        erase(__cur, end());
      else
        insert(end(), __first, __last);
    }

    template <class _ForwardIterator>
    void _M_assign_aux(_ForwardIterator __first, _ForwardIterator __last,
                       forward_iterator_tag) {
      size_type __len = distance(__first, __last);
      if (__len < size())
        erase(copy(__first, __last, begin()), end());
      else {
        _ForwardIterator __mid = __first;
        advance(__mid, size());
        copy(__first, __mid, begin());
        insert(end(), __mid, __last);
      }
    }

    void reserve(size_type __n) {
      if (__n > this->max_size())
        __throw_length_error("vector::reserve");
      if (this->capacity() < __n) {
        _Bit_type * __q = _M_bit_alloc(__n);
        _M_finish = copy(begin(), end(), iterator(__q, 0));
        _M_deallocate();
        _M_start = iterator(__q, 0);
        _M_end_of_storage = __q + (__n + _M_word_bit - 1)/_M_word_bit;
      }
    }

    reference front() { return *begin(); }
    const_reference front() const { return *begin(); }
    reference back() { return *(end() - 1); }
    const_reference back() const { return *(end() - 1); }
    void push_back(bool __x) {
      if (_M_finish._M_p != _M_end_of_storage)
        *_M_finish++ = __x;
      else
        _M_insert_aux(end(), __x);
    }
    void swap(vector<bool, _Alloc>& __x) {
      std::swap(_M_start, __x._M_start);
      std::swap(_M_finish, __x._M_finish);
      std::swap(_M_end_of_storage, __x._M_end_of_storage);
    }


    static void swap(reference __x, reference __y) {
      bool __tmp = __x;
      __x = __y;
      __y = __tmp;
    }

    iterator insert(iterator __position, bool __x = bool()) {
      difference_type __n = __position - begin();
      if (_M_finish._M_p != _M_end_of_storage && __position == end())
        *_M_finish++ = __x;
      else
        _M_insert_aux(__position, __x);
      return begin() + __n;
    }



    template <class _Integer>
    void _M_insert_dispatch(iterator __pos, _Integer __n, _Integer __x,
                            __true_type) {
      _M_fill_insert(__pos, __n, __x);
    }

    template <class _InputIterator>
    void _M_insert_dispatch(iterator __pos,
                            _InputIterator __first, _InputIterator __last,
                            __false_type) {
      _M_insert_range(__pos, __first, __last, __iterator_category(__first));
    }

    template <class _InputIterator>
    void insert(iterator __position,
                _InputIterator __first, _InputIterator __last) {
      typedef typename _Is_integer<_InputIterator>::_Integral _Integral;
      _M_insert_dispatch(__position, __first, __last, _Integral());
    }

    void _M_fill_insert(iterator __position, size_type __n, bool __x) {
      if (__n == 0) return;
      if (capacity() - size() >= __n) {
        copy_backward(__position, end(), _M_finish + difference_type(__n));
        fill(__position, __position + difference_type(__n), __x);
        _M_finish += difference_type(__n);
      }
      else {
        size_type __len = size() + max(size(), __n);
        _Bit_type * __q = _M_bit_alloc(__len);
        iterator __i = copy(begin(), __position, iterator(__q, 0));
        fill_n(__i, __n, __x);
        _M_finish = copy(__position, end(), __i + difference_type(__n));
        _M_deallocate();
        _M_end_of_storage = __q + (__len + _M_word_bit - 1)/_M_word_bit;
        _M_start = iterator(__q, 0);
      }
    }

    void insert(iterator __position, size_type __n, bool __x) {
      _M_fill_insert(__position, __n, __x);
    }

    void pop_back() { --_M_finish; }
    iterator erase(iterator __position) {
      if (__position + 1 != end())
        copy(__position + 1, end(), __position);
        --_M_finish;
      return __position;
    }
    iterator erase(iterator __first, iterator __last) {
      _M_finish = copy(__last, end(), __first);
      return __first;
    }
    void resize(size_type __new_size, bool __x = bool()) {
      if (__new_size < size())
        erase(begin() + difference_type(__new_size), end());
      else
        insert(end(), __new_size - size(), __x);
    }
    void flip() {
      for (_Bit_type * __p = _M_start._M_p; __p != _M_end_of_storage; ++__p)
        *__p = ~*__p;
    }

    void clear() { erase(begin(), end()); }
  };


typedef vector<bool, __alloc> bit_vector;

}
# 73 "/usr/include/c++/3.3/vector" 2 3


# 1 "/usr/include/c++/3.3/bits/vector.tcc" 1 3
# 64 "/usr/include/c++/3.3/bits/vector.tcc" 3
namespace std
{
  template<typename _Tp, typename _Alloc>
    void
    vector<_Tp,_Alloc>::
    reserve(size_type __n)
    {
      if (__n > this->max_size())
        __throw_length_error("vector::reserve");
      if (this->capacity() < __n)
        {
          const size_type __old_size = size();
          pointer __tmp = _M_allocate_and_copy(__n, _M_start, _M_finish);
          _Destroy(_M_start, _M_finish);
          _M_deallocate(_M_start, _M_end_of_storage - _M_start);
          _M_start = __tmp;
          _M_finish = __tmp + __old_size;
          _M_end_of_storage = _M_start + __n;
        }
    }

  template<typename _Tp, typename _Alloc>
    typename vector<_Tp,_Alloc>::iterator
    vector<_Tp,_Alloc>::
    insert(iterator __position, const value_type& __x)
    {
      size_type __n = __position - begin();
      if (_M_finish != _M_end_of_storage && __position == end())
      {
        _Construct(_M_finish, __x);
        ++_M_finish;
      }
      else
        _M_insert_aux(__position, __x);
      return begin() + __n;
    }

  template<typename _Tp, typename _Alloc>
    typename vector<_Tp,_Alloc>::iterator
    vector<_Tp,_Alloc>::
    erase(iterator __position)
    {
      if (__position + 1 != end())
        copy(__position + 1, end(), __position);
      --_M_finish;
      _Destroy(_M_finish);
      return __position;
    }

  template<typename _Tp, typename _Alloc>
    typename vector<_Tp,_Alloc>::iterator
    vector<_Tp,_Alloc>::
    erase(iterator __first, iterator __last)
    {
      iterator __i(copy(__last, end(), __first));
      _Destroy(__i, end());
      _M_finish = _M_finish - (__last - __first);
      return __first;
    }

  template<typename _Tp, typename _Alloc>
    vector<_Tp,_Alloc>&
    vector<_Tp,_Alloc>::
    operator=(const vector<_Tp,_Alloc>& __x)
    {
      if (&__x != this)
      {
        const size_type __xlen = __x.size();
        if (__xlen > capacity())
        {
          pointer __tmp = _M_allocate_and_copy(__xlen, __x.begin(), __x.end());
          _Destroy(_M_start, _M_finish);
          _M_deallocate(_M_start, _M_end_of_storage - _M_start);
          _M_start = __tmp;
          _M_end_of_storage = _M_start + __xlen;
        }
        else if (size() >= __xlen)
        {
          iterator __i(copy(__x.begin(), __x.end(), begin()));
          _Destroy(__i, end());
        }
        else
        {
          copy(__x.begin(), __x.begin() + size(), _M_start);
          uninitialized_copy(__x.begin() + size(), __x.end(), _M_finish);
        }
        _M_finish = _M_start + __xlen;
      }
      return *this;
    }

  template<typename _Tp, typename _Alloc>
    void
    vector<_Tp,_Alloc>::
    _M_fill_assign(size_t __n, const value_type& __val)
    {
      if (__n > capacity())
      {
        vector __tmp(__n, __val, get_allocator());
        __tmp.swap(*this);
      }
      else if (__n > size())
      {
        fill(begin(), end(), __val);
        _M_finish = uninitialized_fill_n(_M_finish, __n - size(), __val);
      }
      else
        erase(fill_n(begin(), __n, __val), end());
    }

  template<typename _Tp, typename _Alloc> template<typename _InputIter>
    void
    vector<_Tp,_Alloc>::
    _M_assign_aux(_InputIter __first, _InputIter __last, input_iterator_tag)
    {
      iterator __cur(begin());
      for ( ; __first != __last && __cur != end(); ++__cur, ++__first)
        *__cur = *__first;
      if (__first == __last)
        erase(__cur, end());
      else
        insert(end(), __first, __last);
    }

  template<typename _Tp, typename _Alloc> template<typename _ForwardIter>
    void
    vector<_Tp,_Alloc>::
    _M_assign_aux(_ForwardIter __first, _ForwardIter __last,
                  forward_iterator_tag)
    {
      size_type __len = distance(__first, __last);

      if (__len > capacity())
      {
        pointer __tmp(_M_allocate_and_copy(__len, __first, __last));
        _Destroy(_M_start, _M_finish);
        _M_deallocate(_M_start, _M_end_of_storage - _M_start);
        _M_start = __tmp;
        _M_end_of_storage = _M_finish = _M_start + __len;
      }
      else if (size() >= __len)
      {
        iterator __new_finish(copy(__first, __last, _M_start));
        _Destroy(__new_finish, end());
        _M_finish = __new_finish.base();
      }
      else
      {
        _ForwardIter __mid = __first;
        advance(__mid, size());
        copy(__first, __mid, _M_start);
        _M_finish = uninitialized_copy(__mid, __last, _M_finish);
      }
    }

  template<typename _Tp, typename _Alloc>
    void
    vector<_Tp,_Alloc>::
    _M_insert_aux(iterator __position, const _Tp& __x)
    {
      if (_M_finish != _M_end_of_storage)
      {
        _Construct(_M_finish, *(_M_finish - 1));
        ++_M_finish;
        _Tp __x_copy = __x;
        copy_backward(__position, iterator(_M_finish-2), iterator(_M_finish-1));
        *__position = __x_copy;
      }
      else
      {
        const size_type __old_size = size();
        const size_type __len = __old_size != 0 ? 2 * __old_size : 1;
        iterator __new_start(_M_allocate(__len));
        iterator __new_finish(__new_start);
        if (true)
          {
            __new_finish = uninitialized_copy(iterator(_M_start), __position,
                                              __new_start);
            _Construct(__new_finish.base(), __x);
            ++__new_finish;
            __new_finish = uninitialized_copy(__position, iterator(_M_finish),
                                              __new_finish);
          }
        if (false)
          {
            _Destroy(__new_start,__new_finish);
            _M_deallocate(__new_start.base(),__len);
            ;
          }
        _Destroy(begin(), end());
        _M_deallocate(_M_start, _M_end_of_storage - _M_start);
        _M_start = __new_start.base();
        _M_finish = __new_finish.base();
        _M_end_of_storage = __new_start.base() + __len;
      }
    }
# 305 "/usr/include/c++/3.3/bits/vector.tcc" 3
  template<typename _Tp, typename _Alloc>
    void
    vector<_Tp,_Alloc>::
    _M_fill_insert(iterator __position, size_type __n, const value_type& __x)
    {
      if (__n != 0)
      {
        if (size_type(_M_end_of_storage - _M_finish) >= __n)
          {
           value_type __x_copy = __x;
           const size_type __elems_after = end() - __position;
           iterator __old_finish(_M_finish);
           if (__elems_after > __n)
             {
               uninitialized_copy(_M_finish - __n, _M_finish, _M_finish);
               _M_finish += __n;
               copy_backward(__position, __old_finish - __n, __old_finish);
               fill(__position, __position + __n, __x_copy);
             }
           else
             {
               uninitialized_fill_n(_M_finish, __n - __elems_after, __x_copy);
               _M_finish += __n - __elems_after;
               uninitialized_copy(__position, __old_finish, _M_finish);
               _M_finish += __elems_after;
               fill(__position, __old_finish, __x_copy);
             }
          }
        else
          {
            const size_type __old_size = size();
            const size_type __len = __old_size + max(__old_size, __n);
            iterator __new_start(_M_allocate(__len));
            iterator __new_finish(__new_start);
            if (true)
              {
                __new_finish = uninitialized_copy(begin(), __position,
                                                  __new_start);
                __new_finish = uninitialized_fill_n(__new_finish, __n, __x);
                __new_finish = uninitialized_copy(__position, end(),
                                                  __new_finish);
              }
            if (false)
              {
                _Destroy(__new_start,__new_finish);
                _M_deallocate(__new_start.base(),__len);
                ;
              }
            _Destroy(_M_start, _M_finish);
            _M_deallocate(_M_start, _M_end_of_storage - _M_start);
            _M_start = __new_start.base();
            _M_finish = __new_finish.base();
            _M_end_of_storage = __new_start.base() + __len;
          }
      }
    }

  template<typename _Tp, typename _Alloc> template<typename _InputIterator>
    void
    vector<_Tp,_Alloc>::
    _M_range_insert(iterator __pos,
                    _InputIterator __first, _InputIterator __last,
                    input_iterator_tag)
    {
      for ( ; __first != __last; ++__first)
      {
        __pos = insert(__pos, *__first);
        ++__pos;
      }
    }

  template<typename _Tp, typename _Alloc> template<typename _ForwardIterator>
    void
    vector<_Tp,_Alloc>::
    _M_range_insert(iterator __position,_ForwardIterator __first,
                    _ForwardIterator __last, forward_iterator_tag)
    {
      if (__first != __last)
      {
        size_type __n = distance(__first, __last);
        if (size_type(_M_end_of_storage - _M_finish) >= __n)
        {
          const size_type __elems_after = end() - __position;
          iterator __old_finish(_M_finish);
          if (__elems_after > __n)
          {
            uninitialized_copy(_M_finish - __n, _M_finish, _M_finish);
            _M_finish += __n;
            copy_backward(__position, __old_finish - __n, __old_finish);
            copy(__first, __last, __position);
          }
          else
          {
            _ForwardIterator __mid = __first;
            advance(__mid, __elems_after);
            uninitialized_copy(__mid, __last, _M_finish);
            _M_finish += __n - __elems_after;
            uninitialized_copy(__position, __old_finish, _M_finish);
            _M_finish += __elems_after;
            copy(__first, __mid, __position);
          }
        }
        else
        {
          const size_type __old_size = size();
          const size_type __len = __old_size + max(__old_size, __n);
          iterator __new_start(_M_allocate(__len));
          iterator __new_finish(__new_start);
          if (true)
            {
              __new_finish = uninitialized_copy(iterator(_M_start),
                                                __position, __new_start);
              __new_finish = uninitialized_copy(__first, __last, __new_finish);
              __new_finish = uninitialized_copy(__position, iterator(_M_finish),
                                                __new_finish);
            }
          if (false)
            {
              _Destroy(__new_start,__new_finish);
              _M_deallocate(__new_start.base(), __len);
              ;
            }
          _Destroy(_M_start, _M_finish);
          _M_deallocate(_M_start, _M_end_of_storage - _M_start);
          _M_start = __new_start.base();
          _M_finish = __new_finish.base();
          _M_end_of_storage = __new_start.base() + __len;
        }
      }
    }
}
# 76 "/usr/include/c++/3.3/vector" 2 3
# 2 "<stdin>" 2
int printf(const char *format, ...);
class xx {
        float fl;
        double dbl;
};
class a : public xx {
        a(int x);
        ~a();
        int b, c, d(char x, short y);
};
int a::d(char x, short y) {
	std::vector<int>::
