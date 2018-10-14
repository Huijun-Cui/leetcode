data = [2,3,5,4,3,2,6,7]
def getDuplication(data,length):
    if length <=0:
        return -1
    start = 1
    end = length-1
    while(end >= start):
        middle = (end-start)//2 + start
        count = countRange(data,length,start,middle)
        if end == start:
            if count > 1:
                return start
            else:
                break
        if count > middle - start + 1:
            end = middle
        else:
            start = middle + 1
    return -1



def countRange(data,length,start,end):
    count = 0
    for i in range(length):
        if data[i] >=start and data[i] <= end:
            count +=1
    return count

if __name__ == '__main__':
    print(getDuplication(data,len(data)))