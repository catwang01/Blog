[toc]


## perf list

列出支持的事件。

```
[par2020_1901210043@mu01 codes]$ perf list

List of pre-defined events (to be used in -e):

  branch-instructions OR branches                    [Hardware event]
  branch-misses                                      [Hardware event]
  bus-cycles                                         [Hardware event]
  cache-misses                                       [Hardware event]
  cache-references                                   [Hardware event]
  cpu-cycles OR cycles                               [Hardware event]
  instructions                                       [Hardware event]
  ref-cycles                                         [Hardware event]

  alignment-faults                                   [Software event]
  context-switches OR cs                             [Software event]
  cpu-clock                                          [Software event]
  cpu-migrations OR migrations                       [Software event]
  dummy                                              [Software event]
  emulation-faults                                   [Software event]
  major-faults                                       [Software event]
  minor-faults                                       [Software event]
  page-faults OR faults                              [Software event]
  task-clock                                         [Software event]

  L1-dcache-load-misses                              [Hardware cache event]
  L1-dcache-loads                                    [Hardware cache event]
  L1-dcache-stores                                   [Hardware cache event]
  L1-icache-load-misses                              [Hardware cache event]
  LLC-load-misses                                    [Hardware cache event]
  LLC-loads                                          [Hardware cache event]
  LLC-store-misses                                   [Hardware cache event]
  LLC-stores                                         [Hardware cache event]
  branch-load-misses                                 [Hardware cache event]
  branch-loads                                       [Hardware cache event]
  dTLB-load-misses                                   [Hardware cache event]
  dTLB-loads                                         [Hardware cache event]
  dTLB-store-misses                                  [Hardware cache event]
  dTLB-stores                                        [Hardware cache event]
  iTLB-load-misses                                   [Hardware cache event]
  iTLB-loads                                         [Hardware cache event]
  node-load-misses                                   [Hardware cache event]
  node-loads                                         [Hardware cache event]
  node-store-misses                                  [Hardware cache event]
  node-stores                                        [Hardware cache event]

  branch-instructions OR cpu/branch-instructions/    [Kernel PMU event]
  branch-misses OR cpu/branch-misses/                [Kernel PMU event]
  bus-cycles OR cpu/bus-cycles/                      [Kernel PMU event]
  cache-misses OR cpu/cache-misses/                  [Kernel PMU event]
  cache-references OR cpu/cache-references/          [Kernel PMU event]
  cpu-cycles OR cpu/cpu-cycles/                      [Kernel PMU event]
```

可以添加参数来查找只与 cache 相关的事件

```
[par2020_1901210043@mu01 codes]$ perf list cache

List of pre-defined events (to be used in -e):

  L1-dcache-load-misses                              [Hardware cache event]
  L1-dcache-loads                                    [Hardware cache event]
  L1-dcache-stores                                   [Hardware cache event]
  L1-icache-load-misses                              [Hardware cache event]
  LLC-load-misses                                    [Hardware cache event]
  LLC-loads                                          [Hardware cache event]
  LLC-store-misses                                   [Hardware cache event]
  LLC-stores                                         [Hardware cache event]
  branch-load-misses                                 [Hardware cache event]
  branch-loads                                       [Hardware cache event]
  dTLB-load-misses                                   [Hardware cache event]
  dTLB-loads                                         [Hardware cache event]
  dTLB-store-misses                                  [Hardware cache event]
  dTLB-stores                                        [Hardware cache event]
  iTLB-load-misses                                   [Hardware cache event]
  iTLB-loads                                         [Hardware cache event]
  node-load-misses                                   [Hardware cache event]
  node-loads                                         [Hardware cache event]
  node-store-misses                                  [Hardware cache event]
  node-stores                                        [Hardware cache event]
```

这下数量就少了很多。

## perf stat


```
[par2020_1901210043@mu01 codes]$ perf stat ./a.out -e cpu-clock

Calculations took 0.487435ms.

 Performance counter stats for './a.out -e cpu-clock':

        919.096234      task-clock (msec)         #    1.873 CPUs utilized
                46      context-switches          #    0.050 K/sec
                25      cpu-migrations            #    0.027 K/sec
               462      page-faults               #    0.503 K/sec
     1,682,778,924      cycles                    #    1.831 GHz
     2,233,464,376      instructions              #    1.33  insn per cycle
       395,443,929      branches                  #  430.253 M/sec
            65,037      branch-misses             #    0.02% of all branches

       0.490623837 seconds time elapsed
```


1. task-clock 是指程序运行期间占用了xx的任务时钟周期，该值高，说明程序的多数时间花费在 CPU 计算上而非 IO
2. context-switches 是指程序运行期间发生了xx次上下文切换，记录了程序运行过程中发生了多少次进程切换，频繁的进程切换是应该避免的。（有进程进程间频繁切换，或者内核态与用户态频繁切换）
3. cpu-migrations 是指程序运行期间发生了xx次CPU迁移，即用户程序原本在一个CPU上运行，后来迁移到另一个CPU


上面的内容可能没有我们希望查看的事件，没关系，可以使用 `-e` 来添加，如 `perf stat -e L1-dcache-load-misses ./a.out` .

如果需要添加多个事件，可以使用逗号分隔(*注意一定要用逗号分隔，逗号之间不应该有空格* ！)，如下面的示例

```
$ perf stat -e task-clock,context-switches,cpu-migrations,page-faults,cycles,instructions,branches,branch-misses,L1-dcache-loads,L1-dcache-load-misses,LLC-loads,LLC-load-misses,dTLB-loads,dTLB-load-misses ./a.out

Calculations took 0.411473ms.

 Performance counter stats for './a.out':

        825.547114      task-clock (msec)         #    1.987 CPUs utilized
                57      context-switches          #    0.069 K/sec
                22      cpu-migrations            #    0.027 K/sec
               459      page-faults               #    0.556 K/sec
     1,466,252,860      cycles                    #    1.776 GHz                      (81.35%)
   <not supported>      stalled-cycles-frontend
   <not supported>      stalled-cycles-backend
     2,208,170,312      instructions              #    1.51  insn per cycle           (90.55%)
       393,149,252      branches                  #  476.229 M/sec                    (89.37%)
            68,215      branch-misses             #    0.02% of all branches          (89.01%)
       770,371,487      L1-dcache-loads           #  933.165 M/sec                    (88.99%)
         5,431,727      L1-dcache-load-misses     #    0.71% of all L1-dcache hits    (89.23%)
         1,069,129      LLC-loads                 #    1.295 M/sec                    (90.02%)
             8,760      LLC-load-misses           #    0.82% of all LL-cache hits     (90.42%)
       624,428,017      dTLB-loads                #  756.381 M/sec                    (90.92%)
            11,465      dTLB-load-misses          #    0.00% of all dTLB cache hits   (90.85%)

       0.415483585 seconds time elapsed
```

## perf record

perf record 可以将输出的结果保存成固定格式，从而进一步分析。

```
-a  录取所有CPU的事件，这个一般需要管理员权限
-p  录取指定pid进程的事件
-g 
-o  指定录取保存数据的文件名
-C  录取指定CPU的事件
```

```
[par2020_1901210043@mu01 test_data_merge]$ perf record -g -o a.data ./a
first element of a: 0 last element of b: 393608215
[ perf record: Woken up 2 times to write data ]
[ perf record: Captured and wrote 0.293 MB a.data (7119 samples) ]
```

## perf report 

```
[par2020_1901210043@mu01 test_data_merge]$ perf report -g -i a.data
```

## 关心哪个指标？

关于缓存的指标有一堆。这个了貌似还挺复杂的。目前来看，关心 `caches-misses` 的值可能会比较好。

1. [caching - How does Linux perf calculate the cache-references and cache-misses events - Stack Overflow](https://stackoverflow.com/questions/55035313/how-does-linux-perf-calculate-the-cache-references-and-cache-misses-events)
