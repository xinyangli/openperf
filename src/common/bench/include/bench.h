#ifndef __BENCH_COMMON
#define __BENCH_COMMON

#include <stddef.h>
#include <stdint.h>

uint64_t uptime();
char *format_time(uint64_t us);
uint32_t checksum(void *start, void *end);

typedef struct {
  void *sub_config;
  size_t mlim;
  uint64_t ref_time;
  uint32_t checksum;
  size_t repeat_time;
} Setting;

#endif
