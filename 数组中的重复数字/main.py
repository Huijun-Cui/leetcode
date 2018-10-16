# ??????O(n) ?????? O(1)
data = [2,3,1,0,2,5,3]
def duplicate(data):
    if len(data) <= 0:
        return False
    for item in data:
        if item < 0 or item > len(data)-1:
            return False
    for ix,item in enumerate(data):
        while data[ix] != ix:
            if data[ix] == data[data[ix]]:
                return True
            else:
                tmp = data[ix]
                data[ix] = data[tmp]
                data[tmp] = tmp
    return False

if __name__ == '__main__':
    print(duplicate(data))