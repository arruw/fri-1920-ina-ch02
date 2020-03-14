# 
```
n = 39000000
T = 60 sec
S = 29894944
```

```
To construct a random graph I have used G(n, p) model.
To find the biggest component size I have implemented almost the same algorithm that was introduced at labs (BFS) in C++. I was careful to compute just the size of the components (and not store all of the vertices) and to pass as reference when possible. 
```

```
n, m, Tg, Ts, T, S
1000, 375, 0, 0, 0, 14
10000, 5000, 0, 0, 0, 227
100000, 62500, 0, 0, 0, 37229
1000000, 750000, 0, 1, 1, 583000
5000000, 4186856, 4, 2, 6, 3397117
10000000, 8750000, 8, 5, 13, 7124691
15000000, 13455171, 14, 8, 22, 10951584
20000000, 18252574, 20, 11, 31, 14829759
25000000, 23118562, 25, 14, 39, 18761086
30000000, 28039204, 27, 17, 44, 22710581
35000000, 33005297, 33, 21, 54, 26695617
37000000, 35002932, 35, 22, 57, 28293178
39000000, 37006439, 37, 23, 60, 29894944
40000000, 38010299, 38, 25, 63, 30693179
```

```
Intel(R) Core(TM) i5-5200U CPU @ 2.20GHz
8 GB + 4 GB
```