data = [1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15]
def Find(data,rows,columns,number):
    found = False
    if rows > 0 and  columns > 0:
        row = 0
        column = columns - 1
        while row < rows and column >0:
            if data[row * columns + column] == number:
                found = True
                break
            elif data[row * columns + column] > number:
                column -= 1
            else:
                row +=1

    return found

if __name__ == '__main__':
    print(Find(data,4,4,5))