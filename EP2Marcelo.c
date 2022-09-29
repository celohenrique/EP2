#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MBR_SIZE 512
#define NUM_PARTITIONS 4

/* offsets within the MBR */
#define SEC_PARTITION_START	0x1BE
#define SEC_MAGICBYTES_START	0x1FE

/* offsets within a partition record */
#define OFF_START_CHS	0x1
#define OFF_PART_DESC	0x4
#define OFF_END_CHS	0x5
#define OFF_START_SEC	0x8
#define OFF_PART_SZ	0xC

//criando variveris globais, nao sei manipular struct em c direito :(


static uint8_t mbr[512];

static void	check_boot_indicator(uint32_t);
static void	check_chs_values(char *, uint32_t);
static uint32_t check_partition_size(uint32_t);
static void	check_starting_sector(uint32_t);
static void	check_partition_fs(uint32_t);
static char *	sector_to_size_str(uint32_t);

https://gist.github.com/glen-mac/8ba1ee9b96767fed74db24defabc1d7e