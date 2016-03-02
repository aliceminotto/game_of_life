#!usr/bin/python

def count_neigh(matrice,posizione):
    pass

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

print "enter underpopulation {default would be 2}"
UNDER=int(check_int())
UNDER=check_range(UNDER,0,9)
print "enter overpopulation {default would be 3}"
OVER=int(check_int())
OVER=check_range(OVER,UNDER,9)
print "enter reproduction case {default would be 3}"
REPR=int(check_int())
REPR=check_range(REPR,UNDER,OVER)

print UNDER,OVER,REPR
