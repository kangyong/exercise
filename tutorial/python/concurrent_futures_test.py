#!/usr/bin/env python3
# new in version 3.2
import concurrent.futures

n = [i for i in range(12)]
print(n)
with concurrent.futures.ThreadPoolExecutor(max_workers=4) as executor:
    future_dic = { i : executor.submit(pow,12,i) for i in n}
    print(future_dic)
# For python 3.x ,iteritems() has been replace with simply items()
rt = [ value for key,value in future_dic.items() ]
rt = [ value.result() for key,value in future_dic.items() ]
print(rt)
