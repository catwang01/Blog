[toc]

## icache 和 dcache

icache 指令 cache i=instruction
dcache 数据 cache d=data

## 查看系统缓存

```
$ getconf -a | grep CACHE
LEVEL1_ICACHE_SIZE                 32768    # 单位是 byte
LEVEL1_ICACHE_ASSOC                8        # 8路归并
LEVEL1_ICACHE_LINESIZE             64       # 单位是 byte
LEVEL1_DCACHE_SIZE                 32768
LEVEL1_DCACHE_ASSOC                8
LEVEL1_DCACHE_LINESIZE             64
LEVEL2_CACHE_SIZE                  262144
LEVEL2_CACHE_ASSOC                 8
LEVEL2_CACHE_LINESIZE              64
LEVEL3_CACHE_SIZE                  20971520
LEVEL3_CACHE_ASSOC                 20
LEVEL3_CACHE_LINESIZE              64
LEVEL4_CACHE_SIZE                  0
LEVEL4_CACHE_ASSOC                 0
LEVEL4_CACHE_LINESIZE              0
```


# References
1. [linux 上查询cache 大小的方法_操作系统_liu-yonggang的专栏-CSDN博客](https://blog.csdn.net/yt_42370304/article/details/83904121)
