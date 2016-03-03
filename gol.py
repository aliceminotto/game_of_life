#!usr/bin/python

def count_neigh(matrice,posizione):
    counter=0
    row=posizione[0]
    col=posizione[1]
    if row-1>=0:
        if col-1>=0 and matrice[row-1][col-1]==1:
            counter+=1
        if matrice[row-1][col]==1:
            counter+=1
        if col+1<WIDTH and matrice[row-1][col+1]==1:
            counter+=1
    if col-1>=0 and matrice[row][col-1]==1:
        counter+=1
    if col+1<WIDTH and matrice[row][col+1]==1:
        counter+=1
    if row+1<HEIGHT:
        if col-1>=0 and matrice[row+1][col-1]==1:
            counter+=1
        if matrice[row+1][col]==1:
            counter+=1
        if col+1<WIDTH and matrice[row+1][col+1]==1:
            counter+=1
    return counter


def check_int():
    i=raw_input()
    while not i.isdigit():
        print "bad value"
        i=raw_input()
    return i

def check_range(value,bottom,top):
    while value<bottom or value>top:
        print "value must be between ",bottom,"and",top
        value=check_range(int(check_int()),bottom,top)
    return value

def print_canvas(canvas):
    for x in range(len(canvas)):
        riga=""
        for y in range(len(canvas[x])):
            if canvas[x][y]==0:
                riga+="- "
            else:
                riga+="* "
        print riga
    print "================="

print "enter underpopulation {default would be 2}"
UNDER=int(check_int())
UNDER=check_range(UNDER,0,9)
print "enter overpopulation {default would be 3}"
OVER=int(check_int())
OVER=check_range(OVER,UNDER,9)
print "enter reproduction case {default would be 3}"
REPR=int(check_int())
REPR=check_range(REPR,UNDER,OVER)
WIDTH=20
HEIGHT=20

canvas=[[0]*WIDTH for i in range(HEIGHT)]
#print_canvas(canvas)
print "enter position of cell as N N, press q when finished"
while True:
    pos=raw_input().split()
    if len(pos)==1:
        if pos[0]=="q" or pos[0]=="Q":
            break
        else:
            print "bad value"
            continue
    else:
        if len(pos)==2:
            if (not pos[0].isdigit() or not pos[1].isdigit() or int(pos[0])<1
                        or int(pos[1])<1 or int(pos[0])>HEIGHT or int(pos[1])>WIDTH):
                print "bad value"
                continue
            pos=[int(x) for x in pos]
            canvas[pos[0]-1][pos[1]-1]=1
            #print_canvas(canvas)
        else:
            print "bad value"
            continue
print_canvas(canvas)

for i in xrange(10):
    new_canvas=[[0]*WIDTH for i in range(HEIGHT)]
    for row in range(HEIGHT):
        for col in range(WIDTH):
            situation=count_neigh(canvas,[row,col])
            #print [row,col],situation
            if situation<UNDER or situation>OVER:
                new_canvas[row][col]=0
            elif situation==REPR:
                new_canvas[row][col]=1
            else:
                new_canvas[row][col]=canvas[row][col]
    canvas=new_canvas
    print_canvas(canvas)
