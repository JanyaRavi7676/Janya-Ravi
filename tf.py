import time
def do_s(x):
    sum=0
    for v in x:
        sum+=v
    return sum
sz=10000000
testdata=range(sz)
t0=time.perf_counter()
my_result=do_s(testdata)
t1=time.perf_counter()
print("the value is{0}(timetaken={1:.4f}seconds)".format(my_result,t1-t0))
