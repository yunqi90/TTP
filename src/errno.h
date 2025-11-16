#ifndef _ERRNO_H_
#define _ERRNO_H_

typedef enum
{
    OK        = 0,
    EPERM     = -1, /* operation not permitted */
    EINVAL    = -2, /* invalid function argument */
    EBUSY     = -3, /* a system resource that can't be shared is already in use */
    EAGAIN    = -4, /* resource temporarily unavailable */
    ENORES    = -5, /* resource exhausted */
    EIO       = -6, /* I/O error */
    ERANGE    = -7, /* numerical result out of range */
    ETIMEDOUT = -8, /* timed out  */
    ECONFIG   = -9, /* bad config */
    EDATA     = -10,/* bad data */
    ERETRY    = -11 /* fail retry */
} errno_t;
// #define RUN_AND_CHECK(x, ret)                                                                                          \
//     if ((x) != OK)                                                                                                     \
//     {                                                                                                                  \
//        printf("%s:%d\r\n", __FILE__, __LINE__);                                                                        \
//        return ret;                                                                                                     \
//     }

#define RUN_AND_CHECK(x, ret)                                                                                          \
    if ((x) != OK)                                                                                                     \
    {                                                                                                                  \
        return ret;                                                                                                    \
    }

char *get_error_string(errno_t err);

#endif /* _ERRNO_H_ */