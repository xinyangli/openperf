#ifndef CONFIG_TCCDIR
#define CONFIG_TCCDIR "/usr/local/lib/tcc"
#endif
#ifndef CONFIG_TCC_PREDEFS
#define CONFIG_TCC_PREDEFS 1
#endif
#define TCC_VERSION "0.9.27"
#define GCC_MAJOR 13
#define GCC_MINOR 2
#define CC_NAME CC_gcc

#define TCC_TARGET_RISCV32
#define TCC_TARGET_RISCV32_ilp32
#define TCC_RISCV_ilp32
#define ONE_SOURCE 1
// #define SDE_RISCV32_DEV 1
// #define __SIZEOF_POINTER__ 4
//
typedef struct {
  int file_count;
} bench_tcc_config;
