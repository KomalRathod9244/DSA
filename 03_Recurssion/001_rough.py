count =0

def fun():
    count=count +1
    print(f"count inside fun: ",  count)

print(f"count outside fun: ",  count)


count = 10
def increment():
    global count
    count = count + 1

increment()
print(count)

