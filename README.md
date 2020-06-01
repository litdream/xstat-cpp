# ProcPS clone for vmstat
( ubuntu package 'procps' provides vmstat )
( ubuntu package 'sysstat' provides iostat/mpstat )

The goal is providing monitor for the Decent Linux.
I am not going to support 2.x or early 4.x kernel.
Minimum Linux kernel is >4.9.x, which is sane normal linux.


- Mirror:
  - https://github.com/mmalecki/procps
  - Mainly working with getstat() function
    - https://github.com/mmalecki/procps/blob/fe4c4a7314f32907b9f558ad0d8b8d0ff1cc76be/proc/sysinfo.c#L374-L445

- If necessary, think about commandline parser:
  - getopt_long()
    - https://www.cplusplus.com/articles/DEN36Up4/
  - Lightwegit parser:
    - https://github.com/jarro2783/cxxopts
	

## 5 proc files to process:

"/proc/stat"
"/proc/uptime"
"/proc/loadavg"
"/proc/meminfo"
"/proc/vmstat"

### /proc/stat
- Sample output

```
ubuntu@ip-172-31-28-185:~$ cat /proc/stat
cpu  273788 122284 74997 1734763271 68823 0 497 18837 0 0
cpu0 273788 122284 74997 1734763271 68823 0 497 18837 0 0
intr 52305483 36 9 0 0 4341 0 0 0 2 0 0 0 3 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 42059342 0 0 0 0 0 236 2375303 7810457 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
ctxt 91871373
btime 1573481090
processes 417617
procs_running 1
procs_blocked 0
softirq 23125439 0 9386820 4957776 3031138 0 0 33642 0 0 5716063
```

### /proc/uptime

291998.49 1166557.46

```
/proc/uptime
     This file contains two numbers: the uptime of the system (seconds), and the amount of  time  spent
	 in  idle  process (seconds).

```

### /proc/loadavg

0.06 0.01 0.00 1/101 9631

```
/proc/loadavg
       The first three fields in this file are load average figures giving the number of jobs in
       the run queue (state R) or waiting for disk I/O (state D) averaged over 1, 5, and 15 min‐
       utes.  They are the same as the load average numbers given by uptime(1)  and  other  pro‐
       grams.   The fourth field consists of two numbers separated by a slash (/).  The first of
       these is  the  number  of  currently  runnable  kernel  scheduling  entities  (processes,
       threads).   The  value  after  the slash is the number of kernel scheduling entities that
       currently exist on the system.  The fifth field is the PID of the process that  was  most
       recently created on the system.

```


### /proc/meminfo

```
MemTotal:        6484116 kB
MemFree:         5037940 kB
MemAvailable:    6123308 kB
Buffers:           68368 kB
Cached:          1185372 kB
SwapCached:            0 kB
Active:           455228 kB
Inactive:         844508 kB
Active(anon):      46052 kB
Inactive(anon):        8 kB
Active(file):     409176 kB
Inactive(file):   844500 kB
Unevictable:           0 kB
Mlocked:               0 kB
SwapTotal:       2097152 kB
SwapFree:        2097152 kB
Dirty:                32 kB
Writeback:             0 kB
AnonPages:         45944 kB
Mapped:            37840 kB
Shmem:                72 kB
Slab:              97012 kB
SReclaimable:      83564 kB
SUnreclaim:        13448 kB
KernelStack:        1688 kB
PageTables:         2432 kB
NFS_Unstable:          0 kB
Bounce:                0 kB
WritebackTmp:          0 kB
CommitLimit:     5339208 kB
Committed_AS:     148228 kB
VmallocTotal:   34359738367 kB
VmallocUsed:           0 kB
VmallocChunk:          0 kB
Percpu:              944 kB
AnonHugePages:     22528 kB
ShmemHugePages:        0 kB
ShmemPmdMapped:        0 kB
HugePages_Total:       0
HugePages_Free:        0
HugePages_Rsvd:        0
HugePages_Surp:        0
Hugepagesize:       2048 kB
Hugetlb:               0 kB
DirectMap4k:       52224 kB
DirectMap2M:     6641664 kB
```

### /proc/vmstat

```
nr_free_pages 1259537
nr_zone_inactive_anon 2
nr_zone_active_anon 11488
nr_zone_inactive_file 211125
nr_zone_active_file 102296
nr_zone_unevictable 0
nr_zone_write_pending 0
nr_mlock 0
nr_page_table_pages 608
nr_kernel_stack 1688
nr_bounce 0
nr_free_cma 0
nr_inactive_anon 2
nr_active_anon 11488
nr_inactive_file 211125
nr_active_file 102296
nr_unevictable 0
nr_slab_reclaimable 20891
nr_slab_unreclaimable 3362
nr_isolated_anon 0
nr_isolated_file 0
workingset_refault 0
workingset_activate 0
workingset_nodereclaim 0
nr_anon_pages 11505
nr_mapped 9460
nr_file_pages 313437
nr_dirty 0
nr_writeback 0
nr_writeback_temp 0
nr_shmem 18
nr_shmem_hugepages 0
nr_shmem_pmdmapped 0
nr_anon_transparent_hugepages 11
nr_unstable 0
nr_vmscan_write 0
nr_vmscan_immediate_reclaim 0
nr_dirtied 338234
nr_written 315454
nr_dirty_threshold 308225
nr_dirty_background_threshold 153924
pgpgin 482510
pgpgout 5660140
pswpin 0
pswpout 0
pgalloc_dma 0
pgalloc_dma32 0
pgalloc_normal 12229030
pgalloc_movable 0
allocstall_dma 0
allocstall_dma32 0
allocstall_normal 0
allocstall_movable 0
pgskip_dma 0
pgskip_dma32 0
pgskip_normal 0
pgskip_movable 0
pgfree 13733859
pgactivate 168577
pgdeactivate 0
pglazyfree 0
pgfault 5853492
pgmajfault 1834
pglazyfreed 0
pgrefill 0
pgsteal_kswapd 0
pgsteal_direct 0
pgscan_kswapd 0
pgscan_direct 0
pgscan_direct_throttle 0
pginodesteal 0
slabs_scanned 0
kswapd_inodesteal 0
kswapd_low_wmark_hit_quickly 0
kswapd_high_wmark_hit_quickly 0
pageoutrun 0
pgrotated 0
drop_pagecache 0
drop_slab 0
oom_kill 0
pgmigrate_success 233835
pgmigrate_fail 6525
compact_migrate_scanned 334168700
compact_free_scanned 234593452
compact_isolated 486356
compact_stall 0
compact_fail 0
compact_success 0
compact_daemon_wake 0
compact_daemon_migrate_scanned 0
compact_daemon_free_scanned 0
htlb_buddy_alloc_success 0
htlb_buddy_alloc_fail 0
unevictable_pgs_culled 528
unevictable_pgs_scanned 0
unevictable_pgs_rescued 528
unevictable_pgs_mlocked 528
unevictable_pgs_munlocked 528
unevictable_pgs_cleared 0
unevictable_pgs_stranded 0
thp_fault_alloc 1715
thp_fault_fallback 0
thp_collapse_alloc 11701
thp_collapse_alloc_failed 0
thp_file_alloc 0
thp_file_mapped 0
thp_split_page 0
thp_split_page_failed 0
thp_deferred_split_page 2053
thp_split_pmd 25
thp_split_pud 0
thp_zero_page_alloc 1
thp_zero_page_alloc_failed 0
thp_swpout 0
thp_swpout_fallback 0
balloon_inflate 0
balloon_deflate 0
swap_ra 0
swap_ra_hit 0
```

