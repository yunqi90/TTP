#include "errno.h"

char *get_error_string(errno_t err) {
  switch (err) {
  case OK:
    return "calm down everything is OK";
  case EPERM:
    return "operation not permitted";
  case EINVAL:
    return "invalid function argument";
  case EBUSY:
    return "a system resource that can't be shared is already in use";
  case EAGAIN:
    return "resource temporarily unavailable";
  case ENORES:
    return "resource exhausted";
  case EIO:
    return "I/O error";
  case ERANGE:
    return "numerical result out of range";
  case ETIMEDOUT:
    return "timed out";
  case ECONFIG:
    return "bad config";
  default:
    return "unknown error";
  }
}