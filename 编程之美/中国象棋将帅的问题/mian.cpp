#define MAXNUM  255
#define HALFBIT 4
#define ROW 3
#define LMASK MAXNUM<<HALFBIT
#define RMASK MAXNUM>>HALFBIT
#define Rset(b,n) b = (b&LMASK) | n
#define Lset(b,n) b = ((b&RMASK)>>HALFBIT) | n
#define LGet(b) b = (LMASK & b) >> HALFBIT
#define RGet(b) b = RMASK & b

for(Lset(b,1);LGet(b)<3*3;Lset(b,(LGet(b)+1))):
    for(Rset(b,1);RGet(b)<3*3;Rset(b,(RGet(b)+1))):
        if(LGet(b)%3!=RGet(b)%3):
            print("A =%d B = %d",LGet(b),LGet(a))
